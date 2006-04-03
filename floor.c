/*
 * Wojciech Mu³a, 20.11.2002
 */

typedef unsigned int dword;

float myfloor(float x)
{
#define float2bin(f) *(dword*)&(f)
#define bin2float(b) *(float*)&(b)

 dword bin   = float2bin(x);
 dword fract = 0;
 dword mask  = 0xffffffff;
 int   exp   = ((bin & 0x7f800000) >> 23);

 if (exp >= (23+127)) // |x| >= 2^23 -> floor(x)==0
	return x;
 else
 if (exp <= (-1+127)) // |x| <= 1
	{
         if ((bin & 0x80000000) != 0) // x < 0
            return -1.0;
         else                         // x > 0
            return  0.0;
        }
 else          // 1 < |x| < 2^23
	{
	 mask <<= (23-exp+127);
	 fract  = bin & ~mask;
	 bin   &= mask;
         if ((bin & 0x80000000) == 0x80000000 && fract != 0)
	      return bin2float(bin)-1.0;
         else
	      return bin2float(bin);
	}

#undef float2bin
#undef bin2float
}
