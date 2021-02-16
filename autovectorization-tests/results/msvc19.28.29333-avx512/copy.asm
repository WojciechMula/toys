std::bad_array_new_length::`RTTI Base Class Descriptor at (0,-1,0,64)' DD FLAT:std::bad_array_new_length `RTTI Type Descriptor' ; std::bad_array_new_length::`RTTI Base Class Descriptor at (0,-1,0,64)'
        DD      02H
        DD      00H
        DD      0ffffffffH
        DD      00H
        DD      040H
        DD      FLAT:std::bad_array_new_length::`RTTI Class Hierarchy Descriptor'
std::bad_array_new_length::`RTTI Base Class Array' DD FLAT:std::bad_array_new_length::`RTTI Base Class Descriptor at (0,-1,0,64)' ; std::bad_array_new_length::`RTTI Base Class Array'
        DD      FLAT:std::bad_alloc::`RTTI Base Class Descriptor at (0,-1,0,64)'
        DD      FLAT:std::exception::`RTTI Base Class Descriptor at (0,-1,0,64)'
std::bad_array_new_length::`RTTI Class Hierarchy Descriptor' DD 00H       ; std::bad_array_new_length::`RTTI Class Hierarchy Descriptor'
        DD      00H
        DD      03H
        DD      FLAT:std::bad_array_new_length::`RTTI Base Class Array'
const std::bad_array_new_length::`RTTI Complete Object Locator' DD 00H             ; std::bad_array_new_length::`RTTI Complete Object Locator'
        DD      00H
        DD      00H
        DD      FLAT:std::bad_array_new_length `RTTI Type Descriptor'
        DD      FLAT:std::bad_array_new_length::`RTTI Class Hierarchy Descriptor'
std::bad_alloc::`RTTI Base Class Descriptor at (0,-1,0,64)' DD FLAT:std::bad_alloc `RTTI Type Descriptor' ; std::bad_alloc::`RTTI Base Class Descriptor at (0,-1,0,64)'
        DD      01H
        DD      00H
        DD      0ffffffffH
        DD      00H
        DD      040H
        DD      FLAT:std::bad_alloc::`RTTI Class Hierarchy Descriptor'
std::bad_alloc::`RTTI Base Class Array' DD FLAT:std::bad_alloc::`RTTI Base Class Descriptor at (0,-1,0,64)' ; std::bad_alloc::`RTTI Base Class Array'
        DD      FLAT:std::exception::`RTTI Base Class Descriptor at (0,-1,0,64)'
std::bad_alloc::`RTTI Class Hierarchy Descriptor' DD 00H                            ; std::bad_alloc::`RTTI Class Hierarchy Descriptor'
        DD      00H
        DD      02H
        DD      FLAT:std::bad_alloc::`RTTI Base Class Array'
const std::bad_alloc::`RTTI Complete Object Locator' DD 00H                      ; std::bad_alloc::`RTTI Complete Object Locator'
        DD      00H
        DD      00H
        DD      FLAT:std::bad_alloc `RTTI Type Descriptor'
        DD      FLAT:std::bad_alloc::`RTTI Class Hierarchy Descriptor'
std::exception::`RTTI Base Class Descriptor at (0,-1,0,64)' DD FLAT:std::exception `RTTI Type Descriptor' ; std::exception::`RTTI Base Class Descriptor at (0,-1,0,64)'
        DD      00H
        DD      00H
        DD      0ffffffffH
        DD      00H
        DD      040H
        DD      FLAT:std::exception::`RTTI Class Hierarchy Descriptor'
std::exception::`RTTI Base Class Array' DD FLAT:std::exception::`RTTI Base Class Descriptor at (0,-1,0,64)' ; std::exception::`RTTI Base Class Array'
std::exception::`RTTI Class Hierarchy Descriptor' DD 00H                            ; std::exception::`RTTI Class Hierarchy Descriptor'
        DD      00H
        DD      01H
        DD      FLAT:std::exception::`RTTI Base Class Array'
const std::exception::`RTTI Complete Object Locator' DD 00H                      ; std::exception::`RTTI Complete Object Locator'
        DD      00H
        DD      00H
        DD      FLAT:std::exception `RTTI Type Descriptor'
        DD      FLAT:std::exception::`RTTI Class Hierarchy Descriptor'
`string' DB 'vector too long', 00H ; `string'
__CT??_R0?AVexception@std@@@8??0exception@std@@QAE@ABV01@@Z12 DD 00H
        DD      FLAT:std::exception `RTTI Type Descriptor'
        DD      00H
        DD      0ffffffffH
        ORG $+4
        DD      0cH
        DD      FLAT:std::exception::exception(std::exception const &)
__CT??_R0?AVbad_alloc@std@@@8??0bad_alloc@std@@QAE@ABV01@@Z12 DD 010H
        DD      FLAT:std::bad_alloc `RTTI Type Descriptor'
        DD      00H
        DD      0ffffffffH
        ORG $+4
        DD      0cH
        DD      FLAT:std::bad_alloc::bad_alloc(std::bad_alloc const &)
__CT??_R0?AVbad_array_new_length@std@@@8??0bad_array_new_length@std@@QAE@ABV01@@Z12 DD 00H
        DD      FLAT:std::bad_array_new_length `RTTI Type Descriptor'
        DD      00H
        DD      0ffffffffH
        ORG $+4
        DD      0cH
        DD      FLAT:std::bad_array_new_length::bad_array_new_length(std::bad_array_new_length const &)
__CTA3 ?? std::AVbad_array_new_length DD 03H
        DD      FLAT:__CT??_R0?AVbad_array_new_length@std@@@8??0bad_array_new_length@std@@QAE@ABV01@@Z12
        DD      FLAT:__CT??_R0?AVbad_alloc@std@@@8??0bad_alloc@std@@QAE@ABV01@@Z12
        DD      FLAT:__CT??_R0?AVexception@std@@@8??0exception@std@@QAE@ABV01@@Z12
__TI3 ?? std::AVbad_array_new_length DD 00H
        DD      FLAT:virtual std::bad_array_new_length::~bad_array_new_length(void)
        DD      00H
        DD      FLAT:__CTA3 ?? std::AVbad_array_new_length
`string' DB 'bad array new length', 00H ; `string'
const std::bad_array_new_length::`vftable' DD FLAT:const std::bad_array_new_length::`RTTI Complete Object Locator' ; std::bad_array_new_length::`vftable'
        DD      FLAT:virtual void * std::bad_array_new_length::`vector deleting destructor'(unsigned int)
        DD      FLAT:virtual char const * std::exception::what(void)const 
const std::bad_alloc::`vftable' DD FLAT:const std::bad_alloc::`RTTI Complete Object Locator'  ; std::bad_alloc::`vftable'
        DD      FLAT:virtual void * std::bad_alloc::`vector deleting destructor'(unsigned int)
        DD      FLAT:virtual char const * std::exception::what(void)const 
`string' DB 'Unknown exception', 00H ; `string'
const std::exception::`vftable' DD FLAT:const std::exception::`RTTI Complete Object Locator'  ; std::exception::`vftable'
        DD      FLAT:virtual void * std::exception::`vector deleting destructor'(unsigned int)
        DD      FLAT:virtual char const * std::exception::what(void)const 

_v$ = 8                                       ; size = 4
_out$ = 12                                          ; size = 4
void copy_epi8(std::vector<signed char,std::allocator<signed char> > const &,std::vector<signed char,std::allocator<signed char> > &) PROC ; copy_epi8, COMDAT
        push    ebx
        push    esi
        mov     esi, DWORD PTR _v$[esp+4]
        mov     ebx, DWORD PTR [esi+4]
        mov     esi, DWORD PTR [esi]
        cmp     esi, ebx
        je      SHORT $LN21@copy_epi8
        push    edi
        mov     edi, DWORD PTR _out$[esp+8]
$LL22@copy_epi8:
        mov     ecx, DWORD PTR [edi+4]
        cmp     ecx, DWORD PTR [edi+8]
        je      SHORT $LN29@copy_epi8
        mov     al, BYTE PTR [esi]
        mov     BYTE PTR [ecx], al
        inc     DWORD PTR [edi+4]
        jmp     SHORT $LN20@copy_epi8
$LN29@copy_epi8:
        push    esi
        push    ecx
        mov     ecx, edi
        call    signed char * std::vector<signed char,std::allocator<signed char> >::_Emplace_reallocate<signed char const &>(signed char * const,signed char const &) ; std::vector<signed char,std::allocator<signed char> >::_Emplace_reallocate<signed char const &>
$LN20@copy_epi8:
        inc     esi
        cmp     esi, ebx
        jne     SHORT $LL22@copy_epi8
        pop     edi
$LN21@copy_epi8:
        pop     esi
        pop     ebx
        ret     0
void copy_epi8(std::vector<signed char,std::allocator<signed char> > const &,std::vector<signed char,std::allocator<signed char> > &) ENDP ; copy_epi8

_v$ = 8                                       ; size = 4
_out$ = 12                                          ; size = 4
void copy_epi32(std::vector<int,std::allocator<int> > const &,std::vector<int,std::allocator<int> > &) PROC ; copy_epi32, COMDAT
        push    ebx
        push    esi
        mov     esi, DWORD PTR _v$[esp+4]
        mov     ebx, DWORD PTR [esi+4]
        mov     esi, DWORD PTR [esi]
        cmp     esi, ebx
        je      SHORT $LN21@copy_epi32
        push    edi
        mov     edi, DWORD PTR _out$[esp+8]
$LL22@copy_epi32:
        mov     ecx, DWORD PTR [edi+4]
        cmp     ecx, DWORD PTR [edi+8]
        je      SHORT $LN29@copy_epi32
        mov     eax, DWORD PTR [esi]
        mov     DWORD PTR [ecx], eax
        add     DWORD PTR [edi+4], 4
        jmp     SHORT $LN20@copy_epi32
$LN29@copy_epi32:
        push    esi
        push    ecx
        mov     ecx, edi
        call    int * std::vector<int,std::allocator<int> >::_Emplace_reallocate<int const &>(int * const,int const &) ; std::vector<int,std::allocator<int> >::_Emplace_reallocate<int const &>
$LN20@copy_epi32:
        add     esi, 4
        cmp     esi, ebx
        jne     SHORT $LL22@copy_epi32
        pop     edi
$LN21@copy_epi32:
        pop     esi
        pop     ebx
        ret     0
void copy_epi32(std::vector<int,std::allocator<int> > const &,std::vector<int,std::allocator<int> > &) ENDP ; copy_epi32
