//=== ARM Neon32 implementation ==========================================
#include <arm_neon.h>


float32x4_t vsetq_f32(float v0, float v1, float v2, float v3) {

    float32x4_t result;

    result = vsetq_lane_f32(v0, result, 0);
    result = vsetq_lane_f32(v1, result, 1);
    result = vsetq_lane_f32(v2, result, 2);
    result = vsetq_lane_f32(v3, result, 3);

    return result;
}


// assertion: each 32-bit element of vector contains either 0 or 0xffffffff
int vq_is_zero(const uint32x4_t vec) {

    // combine lower and higher 32-bit helves
    const uint32x2_t t0 = vorr_u32(vget_low_u32(vec), vget_high_u32(vec));

    // shift whole 64-bit register right
    const uint64x1_t t1 = vreinterpret_u64_u32(t0);
    const uint64x1_t t2 = vshr_n_u64(t1, 32);

    // get the lower half the register
    uint32_t tmp = vget_lane_u32(vreinterpret_u32_u64(t2), 0);

    return tmp;
}


void Neon_mandelbrot(
	float Re_min, float Re_max,
	float Im_min, float Im_max,
	float thr,
	int maxiters,
	int width, int height,
	uint8_t *data)

{
	float dRe, dIm;
	int x, y, i;

	uint8_t* ptr = data;

	// step on Re and Im axis
	dRe = (Re_max - Re_min)/width;
	dIm = (Im_max - Im_min)/height;

    float32x4_t threshold = vdupq_n_f32(thr);
    float32x4_t Cim       = vdupq_n_f32(Im_min);
    const float32x4_t vec_dRe = vdupq_n_f32(4*dRe);
    const float32x4_t vec_dIm = vdupq_n_f32(dIm);

    uint32_t tmp[4];

	for (y=0; y < height; y++) {
		float32x4_t Cre = vsetq_f32(Re_min, Re_min + dRe, Re_min + 2*dRe, Re_min + 3*dRe);

		for (x=0; x < width; x += 4) {

            float32x4_t Xre = vdupq_n_f32(0.0f);
            float32x4_t Xim = Xre;
            float32x4_t Tre;
            float32x4_t Tim;

            uint32x4_t itercount = vdupq_n_u32(0);

			for (i=0; i < maxiters; i++) {
				// Tre = Xre*Xre - Xim*Xim + Cre;

                const float32x4_t Xre2 = vmulq_f32(Xre, Xre);
                const float32x4_t Xim2 = vmulq_f32(Xim, Xim);

                Tre = vsubq_f32(Xre2, Xim2);
                Tre = vaddq_f32(Tre, Cre);

				// Tim = 2*Xre*Xim + Cim;
                const float32x4_t XreXim = vmulq_f32(Xre, Xim);
                Tim = vaddq_f32(XreXim, XreXim);
                Tim = vaddq_f32(Tim, Cim);

                // dist = Tre*Tre + Tim*Tim
                const float32x4_t Tre2 = vmulq_f32(Tre, Tre);
                const float32x4_t Tim2 = vmulq_f32(Tim, Tim);
                const float32x4_t dist = vaddq_f32(Tre2, Tim2);

                // dist < threshold
                const uint32x4_t lt = vcltq_f32(dist, threshold);
				if (vq_is_zero(lt) == 0) {
					break;
                }

                itercount = vsubq_u32(itercount, lt);

				Xre = Tre;
				Xim = Tim;
			}

            vst1q_u32(tmp, itercount);
            *ptr++ = tmp[0];
            *ptr++ = tmp[1];
            *ptr++ = tmp[2];
            *ptr++ = tmp[3];

            Cre = vaddq_f32(Cre, vec_dRe);
		}

        Cim = vaddq_f32(Cim, vec_dIm);
	}
}


void NeonFMA_mandelbrot(
	float Re_min, float Re_max,
	float Im_min, float Im_max,
	float thr,
	int maxiters,
	int width, int height,
	uint8_t *data)

{
	float dRe, dIm;
	int x, y, i;

	uint8_t* ptr = data;

	// step on Re and Im axis
	dRe = (Re_max - Re_min)/width;
	dIm = (Im_max - Im_min)/height;

    float32x4_t threshold = vdupq_n_f32(thr);
    float32x4_t Cim       = vdupq_n_f32(Im_min);
    const float32x4_t vec_dRe = vdupq_n_f32(4*dRe);
    const float32x4_t vec_dIm = vdupq_n_f32(dIm);

    uint32_t tmp[4];

	for (y=0; y < height; y++) {
		float32x4_t Cre = vsetq_f32(Re_min, Re_min + dRe, Re_min + 2*dRe, Re_min + 3*dRe);

		for (x=0; x < width; x += 4) {

            float32x4_t Xre = vdupq_n_f32(0.0f);
            float32x4_t Xim = Xre;
            float32x4_t Tre;
            float32x4_t Tim;

            uint32x4_t itercount = vdupq_n_u32(0);

			for (i=0; i < maxiters; i++) {
				// Tre = Xre*Xre - Xim*Xim + Cre;
                Tre = vfmaq_f32(Cre, Xre, Xre); // Tre  = Cre + Xre^2
                Tre = vfmsq_f32(Tre, Xim, Xim); // Tre -= Yre^2

				// Tim = 2*Xre*Xim + Cim;
                Tim = vaddq_f32(Xre, Xre);      // Tim  = 2*Xre
                Tim = vfmaq_f32(Cim, Tim, Xim); // Tim  = Cim + Tim*Xim

                // dist = Tre*Tre + Tim*Tim
                float32x4_t dist = vmulq_f32(Tre, Tre);
                dist = vfmaq_f32(dist, Tim, Tim);

                // dist < threshold
                const uint32x4_t lt = vcltq_f32(dist, threshold);
				if (vq_is_zero(lt) == 0) {
					break;
                }

                itercount = vsubq_u32(itercount, lt);

				Xre = Tre;
				Xim = Tim;
			}

            vst1q_u32(tmp, itercount);
            *ptr++ = tmp[0];
            *ptr++ = tmp[1];
            *ptr++ = tmp[2];
            *ptr++ = tmp[3];

            Cre = vaddq_f32(Cre, vec_dRe);
		}

        Cim = vaddq_f32(Cim, vec_dIm);
	}
}
