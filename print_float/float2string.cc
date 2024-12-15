#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef unsigned long long int  qword; // 64 bity
typedef unsigned int            dword; // 32 bity
typedef unsigned short int       word; // 16 bity
typedef unsigned char            byte; //  8 bitów

/*
 * byte quotient [10*256] = {for (i=0; i<2560; i++) element[i]=i/10};
 * byte remainder[10*256] = {for (i=0; i<2560; i++) element[i]=i%10};
 */
#include "precalc.c"

/* 
 * funkcja dzieli liczbê o podstawie 256 przez 10.
 * 
 * 'start' i 'end' (zmienna 'end' mo¿e zostaæ zmieniona) 
 * okre¶laj± zakres tablicy 'number' na jakim przeprowdzane 
 * s± obliczenia
 * 
 * zwracana jest reszta z dzielenia
 */
byte div_by_10(byte number[], int& start, int& end)
{
	assert(end >= start);

	int  i   = end;
	word rem = 0;	// reszta

	// dzielenie
	while (i >= start)
		{
		 word digit = number[i];
		 word tmp   = 256*rem + digit;

		 number[i]  = quotient[tmp];  // tmp/10;
		 rem        = remainder[tmp]; // tmp%10;
		 i--;
		}
	// zawê¿enie przedzia³u obliczeñ
	while (number[end]==0 && start <= end)
		end--;

	return rem;
}

/* 
 * funkcja mno¿y liczbê o podstawie 256 przez 10.
 * 
 * 'start' i 'end' (zmienna 'start' mo¿e zostaæ zmieniona) 
 * okre¶laj± zakres tablicy 'number' na jakim przeprowdzane 
 * s± obliczenia
 * 
 * zwracane jest przeniesienie
 */
byte mul_by_10(byte number[], int& start, int& end)
{
	assert(end >= start);

	int i = start;
	dword carry = 0;	// przeniesienie

	// mno¿enie
	while (i <= end)
		{
		 word digit = number[i];
		 word tmp   = 10*digit + carry;

		 number[i]  = tmp &  0xff;
		 carry      = tmp >> 8;
		 i++;
		}
	// zawê¿enie przedzia³u obliczeñ
	while (number[start]==0 && start <= end)
		start++;

	return carry;
}

char* float2string(char* S, float x)
{
 static byte fixedpoint[40]; //  0..19 - czê¶æ u³amkowa
                             // 20..39 - czê¶æ ca³kowita 
#define bias 127
#define dot_position (20*8)  /* pozycja kropki dziesiêtnej (w bitach)  */

 // 1. wydzielenie pól bitowych
 dword bin  =  *(dword*)&x;
 dword sign = (bin >> 31);		// znak
 dword exp  = (bin >> 23) & 0xff;	// wyk³adnik+bias
 dword mantissa = (bin & 0x007fffff);	// mantysa
 
 // 2. warto¶ci specjalne 
 // 2a. zero
 if (exp==0x00 && mantissa==0)
 	{
	 if (sign) strcpy(S, "-0.0");
	      else strcpy(S, "+0.0");
	 return S;
	}
 // 2b. nieskoñczono¶æ
 if (exp==0xff && mantissa==0)
 	{
	 if (sign) strcpy(S, "-inf");
	      else strcpy(S, "+inf");
	 return S;
	}
 // 2c. NaN -- rozró¿nienie miêdzy QNaN i SNaN
 if (exp==0xff && mantissa!=0)
 	{
	 if (mantissa & 0x800000)
	 	strcpy(S, "QNaN");
	 else
	 	strcpy(S, "SNaN");
	 return S;
	}

 // 3. uzupe³nienie czê¶ci ca³kowitej
 //    (je¶li liczba nie jest zdenormalizowana)
 if (exp==0x00 && mantissa!=0) 
 	;
 else 
 	mantissa |= 0x800000;
 
 // 4. wstawienie znaku liczby
 if (sign)
 	{
	 S[0] = '-';
	 S[1] = '\0';
	}
 else
 	{
	 //S[0] = '+'; S[1]='\0'
 	 S[0] = '\0';
	}

 // 5. zamiana liczby zmiennoprzecinkowej na fixed-point 

 memset(fixedpoint, sizeof(fixedpoint), 0); // zerowanie

 // exp-23, poniewa¿ mantysa jest przesuniêta o 23 bity w prawo
 int position = (exp-23) + dot_position - bias;

 int shift    = position & 0x7;	// przesuniêcie w obrêbie bajtu
 int index    = position >> 3;  // pierwszy bajt

 // "wstawienie" mantysy do liczby sta³oprzecinkowej
 // poniewa¿ shift=0..7, wobec czego liczba bitów znacz±cych
 // wynosi zaledwie 32
 mantissa <<= shift;
 fixedpoint[index+0] = (mantissa >> 0x00) & 0xff;
 fixedpoint[index+1] = (mantissa >> 0x08) & 0xff;
 fixedpoint[index+2] = (mantissa >> 0x10) & 0xff;
 fixedpoint[index+3] = (mantissa >> 0x18) & 0xff;

 // 6. konwersja
 static char tmp[128];
 
 if (exp >= 0+bias) // liczba posiada czê¶æ ca³kowit±
 	{
 	 memset(tmp, sizeof(tmp), 0);
	 // zakres w którym zostan± przeprowadzone obliczenia
	 int start = 20;	
	 int end   = index+3;
	 //
	 int idx = sizeof(tmp)-1;
	 while (1)
	 	{
		 tmp[--idx] = div_by_10(fixedpoint, start, end) + '0';
		 if (start > end)
		 	break;
		}
	 strcat(S, &tmp[idx]);
	}
 else
 	 strcat(S, "0");
	 
 strcat(S, ".");
 
 if (exp < 23+bias) // liczba posiada czê¶æ u³amkow±
 	{
 	 memset(tmp, sizeof(tmp), 0);
	 // zakres w którym zostan± przeprowadzone obliczenia
	 int start = index;
	 int end   = 19;
	 //
	 int idx   = 0;
	 while (1)
	 	{
		 tmp[idx++] = mul_by_10(fixedpoint, start, end) + '0';
		 if (start > end)
		 	break;
		}
	 strcat(S, tmp);
	}
 else
 	 strcat(S, "0");
 
 return S;
}
