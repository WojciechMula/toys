/*
 * Wojciech Mu³a, 22.11.2002
 */

float myround(float x)
{
 dword *bin    = (dword*)&x;
 dword signbit = d & 0x80000000;
 
 *bin ^= signbit;     // x = fabs(x);
  x    = floor(x+0.5) // x = round(x);
 *bin ^= signbit;     // restore sign
 
 return x;
}
