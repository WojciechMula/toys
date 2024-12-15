/* Fri Nov 22 13:53:11 2002 */
typedef unsigned int dword;

#define VALUE    0 /* finite normalized number */
#define ZERO     1 /* zero */
#define DENORMAL 2 /* finite denormalized number */
#define INF      3 /* infinity */
#define QNaN     4 /* QNaN (quiet NaN) */
#define SNaN     5 /* SNaN */

int qualify_float(float f)
{
 dword d        = *(dword*)&f;
 dword exp      = (d >> 23) & 0xff;
 dword mantissa = (d & 0x007fffff);
 
 if (exp==0x00 && mantissa==0) // zero
 	return ZERO;
 if (exp==0x00 && mantissa!=0) // denormalized
 	return DENORMAL;
 if (exp==0xff && mantissa==0) // infinity
 	return INF;
 if (exp==0xff && mantissa!=0) // NaN
 	{
	 if (mantissa & 0x00800000)
	 	return QNaN;
	 else
	 	return SNaN;
	}
 return VALUE;
}
