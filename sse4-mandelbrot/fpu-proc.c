//=== C reference implementation =========================================
void FPU_mandelbrot(
	float Re_min, float Re_max,
	float Im_min, float Im_max,
	float threshold,
	int maxiters,
	int width, int height,
	uint8_t *data)

{
	float dRe, dIm;
	float Cre, Cim, Xre, Xim, Tre, Tim;
	int x, y, i;

	uint8_t* ptr = data;

	// step on Re and Im axis
	dRe = (Re_max - Re_min)/width;
	dIm = (Im_max - Im_min)/height;


	Cim = Im_min;

	for (y=0; y < height; y++) {
		Cre = Re_min;
		for (x=0; x < width; x++) {
			Xre = 0.0;
			Xim = 0.0;
			for (i=0; i < maxiters; i++) {
				Tre = Xre*Xre - Xim*Xim + Cre;
				Tim = 2*Xre*Xim + Cim;

				if (Tre*Tre + Tim*Tim > threshold)
					break;

				Xre = Tre;
				Xim = Tim;
			}

			*ptr++ = i;
			Cre += dRe;
		}

		Cim += dIm;
	}
}

