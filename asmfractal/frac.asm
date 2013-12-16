; Fraktal Mandelbrota (148 bajtów)

; kompilacja: nasm frac.asm -o frac.com

; Wojciech Mu³a
; 31.08.2001
;  1.09.2001
; 14.04.2004 -- polskie komentarze

         org 100h          ; format COM

iterations equ 64          ; liczba iteracji		

%define set_palette

start:
        ;; ustawienie trybu graficznego 320x200x256
        mov al, 13h
        int 10h

%ifdef set_palette
        ;; ustawienie palety kolorów
        mov dx, 3c8h      ;
        mov al, 0         ; zaczynamy od indeksu 0
        out dx, al        ;
        inc dx            ;
 set_pal:                 ;
        out dx, al        ;
        out dx, al        ;
        out dx, al        ;
        inc al            ;
        cmp al, 64        ; i ustawiamy pierwsze 64 kolorów
        jne set_pal       ; na poziomy szaro¶ci
%endif

        push word 0a000h  ;
        pop  es           ; [es:di] -> A000:0000
        xor  di, di       ;

        finit               ; inicjalizacja koprocesora
        fld dword [Cim_min] ; Cim = Cim_min

        mov dl, 200
  loopy:

        mov cx, 320
        fld dword [Cre_min] ; Cre = Cre_min
  loopx:
            fldz
            fldz            ; Xre = Xim = 0.0
            mov dh, iterations
      iters:                    ; st0         st1   st2 st3 st4 st5 st6
                fld st0         ; Xre         Xre   Xim Cre Cim
                fld st2         ; Xim         Xre   Xre Xim Cre Cim

                ;; Re(X^2+C) = Xre^2 + Xim^2 + Cre
                fmul   st3      ; Xim^2       Xre   Xre Xim Cre Cim
                fxch            ; Xre         Xim^2 Xre Xim Cre Cim
                fmul   st2      ; Xre^2 Xim^2 Xre   Xim Cre Cim
                fsubrp st1      ; Xre^2-Xim^2 Xre   Xim Cre Cim
                fadd   st3      ; Tre         Xre   Xim Cre Cim

                ;; Im(X^2+C) = 2*Xre*Xim + Cim
                fxch  st2       ; Xim         Xre   Tre Cre Cim
                fmulp st1       ; Xim*Xre     Tre   Cre Cim
                fadd  st0, st0  ; Tim         Tre   Cre Cim
                fadd  st3

                ;; obliczenie kwadratu modu³u z liczby X^2+C
                fld   st0       ; Tim         Tim   Tre   Cre   Cim
                fmul  st1       ; Tim^2       Tim   Tre   Cre   Cim
                fld   st2       ; Tre         Tim^2 Tim   Tre   Cre   Cim
                fmul  st3       ; Tre^2       Tim^2 Tim   Tre   Cre   Cim
                faddp st1       ; Tre^2+Tim^2 Tim   Tre   Cre   Cim

		; if (Tre^2+Tim^2 > thersold) break
                fcomp dword [thershold] ; Tim   Tre   Cre   Cim
		
                fstsw ax                ; zapisz wynik porównania
                and ah,41h       	; do rejestru FLAGS
                jz  break        

                fxch                    ; Tre   Tim   Cre   Cim
					; jeste¶my gotowi do nastêpnej iteracji

                dec dh                  ;
                jnz  iters              ; nastêpna iteracja

      break:
            fcompp                  ; usuniêcie ze stosu Tre oraz Tim

            mov [es:di], dh         ; narysowanie piksela
            inc di                  ; 

            fadd dword [Cadd]       ; Cre += Cadd

        loop loopx              ; pêtla X

        fcomp st1               ; usuniêcie Cre ze stosu, zostanie ponownie
	                        ; za³adowany
        fadd dword [Cadd]       ; Cim += Cadd

        dec dl                  ; pêtla X
        jnz  loopy              ;

        fcompp                  ; usuñ Cre i Cim ze stosu

        mov ah, 07h             ; czekaj na klawisz
        int 21h
        mov ax, 0003h           ; koniec
        int 10h

        ret

Cim_min dd -1.0        ; pocz±tkowa warto¶ci C
Cre_min dd -2.0        ;

Cadd      dd 0.009375  ; 3/320
thershold dd 20.0      ; mo¿na sprobówaæ te¿ z 1.0, 0.1 itp.

;; równowa¿ny kod w C++

;Cim = Cim_min
;for (int y=0; y<200; y++, Cre=Cre_min, Cim+=Cadd)
;  for (int x=0; x<320; x++, Cre+=Cadd)
;    {
;     Xre = Xim = 0.0;
;     int i;
;     for (i=0; i<63; i++)
;       {
;        Tre = Xre*Xre - Xim*Xim + Cre
;        Tim = 2*Xre*Xim + Cim
;
;        if (Tre*Tre+Tim*Tim > thershold) break;
;        Xre = Tre;
;        Xim = Tim;
;       }
;     put_pixel(x,y, i);
;    }

;; eof
