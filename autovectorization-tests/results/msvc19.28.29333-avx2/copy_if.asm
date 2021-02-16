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
void copy_if_epi8(std::vector<signed char,std::allocator<signed char> > const &,std::vector<signed char,std::allocator<signed char> > &) PROC ; copy_if_epi8, COMDAT
        push    ebx
        push    esi
        mov     esi, DWORD PTR _v$[esp+4]
        mov     ebx, DWORD PTR [esi+4]
        mov     esi, DWORD PTR [esi]
        cmp     esi, ebx
        je      SHORT $LN17@copy_if_ep
        push    edi
        mov     edi, DWORD PTR _out$[esp+8]
$LL18@copy_if_ep:
        mov     cl, BYTE PTR [esi]
        test    cl, cl
        jle     SHORT $LN16@copy_if_ep
        mov     eax, DWORD PTR [edi+4]
        cmp     eax, DWORD PTR [edi+8]
        je      SHORT $LN28@copy_if_ep
        mov     BYTE PTR [eax], cl
        inc     DWORD PTR [edi+4]
        jmp     SHORT $LN16@copy_if_ep
$LN28@copy_if_ep:
        push    esi
        push    eax
        mov     ecx, edi
        call    signed char * std::vector<signed char,std::allocator<signed char> >::_Emplace_reallocate<signed char const &>(signed char * const,signed char const &) ; std::vector<signed char,std::allocator<signed char> >::_Emplace_reallocate<signed char const &>
$LN16@copy_if_ep:
        inc     esi
        cmp     esi, ebx
        jne     SHORT $LL18@copy_if_ep
        pop     edi
$LN17@copy_if_ep:
        pop     esi
        pop     ebx
        ret     0
void copy_if_epi8(std::vector<signed char,std::allocator<signed char> > const &,std::vector<signed char,std::allocator<signed char> > &) ENDP ; copy_if_epi8

_x$ = 8                                       ; size = 1
bool <lambda_dcb711e7327c1e486fdcdacb9b3a0fbc>::operator()(signed char)const  PROC ; <lambda_dcb711e7327c1e486fdcdacb9b3a0fbc>::operator(), COMDAT
        cmp     BYTE PTR _x$[esp-4], 0
        setg    al
        ret     4
bool <lambda_dcb711e7327c1e486fdcdacb9b3a0fbc>::operator()(signed char)const  ENDP ; <lambda_dcb711e7327c1e486fdcdacb9b3a0fbc>::operator()

_v$ = 8                                       ; size = 4
_out$ = 12                                          ; size = 4
void copy_if_epi32(std::vector<int,std::allocator<int> > const &,std::vector<int,std::allocator<int> > &) PROC ; copy_if_epi32, COMDAT
        push    ebx
        push    esi
        mov     esi, DWORD PTR _v$[esp+4]
        mov     ebx, DWORD PTR [esi+4]
        mov     esi, DWORD PTR [esi]
        cmp     esi, ebx
        je      SHORT $LN17@copy_if_ep
        push    edi
        mov     edi, DWORD PTR _out$[esp+8]
$LL18@copy_if_ep:
        mov     ecx, DWORD PTR [esi]
        test    ecx, ecx
        jle     SHORT $LN16@copy_if_ep
        mov     eax, DWORD PTR [edi+4]
        cmp     eax, DWORD PTR [edi+8]
        je      SHORT $LN28@copy_if_ep
        mov     DWORD PTR [eax], ecx
        add     DWORD PTR [edi+4], 4
        jmp     SHORT $LN16@copy_if_ep
$LN28@copy_if_ep:
        push    esi
        push    eax
        mov     ecx, edi
        call    int * std::vector<int,std::allocator<int> >::_Emplace_reallocate<int const &>(int * const,int const &) ; std::vector<int,std::allocator<int> >::_Emplace_reallocate<int const &>
$LN16@copy_if_ep:
        add     esi, 4
        cmp     esi, ebx
        jne     SHORT $LL18@copy_if_ep
        pop     edi
$LN17@copy_if_ep:
        pop     esi
        pop     ebx
        ret     0
void copy_if_epi32(std::vector<int,std::allocator<int> > const &,std::vector<int,std::allocator<int> > &) ENDP ; copy_if_epi32

_x$ = 8                                       ; size = 4
bool <lambda_a0485afc6d049ea42b27214b482175de>::operator()(int)const  PROC ; <lambda_a0485afc6d049ea42b27214b482175de>::operator(), COMDAT
        cmp     DWORD PTR _x$[esp-4], 0
        setg    al
        ret     4
bool <lambda_a0485afc6d049ea42b27214b482175de>::operator()(int)const  ENDP ; <lambda_a0485afc6d049ea42b27214b482175de>::operator()
