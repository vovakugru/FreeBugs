#pragma once
#include "basic+lib.h"
using namespace std;

void StartFunc() {
    int degree = 1;
    int result;
    bool isOk  1;
    int rem = 0;
    int n;
    fout("Enter number: ");
    cin >> n;
    __asm{
        mov eax, n
        mov ecx, 10
        mov ebx, result
        start:
        cmp eax, 0
            je _finish // if equal
            jl _error // if lower
                cdq
                div dword ptr 10 // ?
                mov temp, eax
                mov eax, edx
                cdq
                imul ecx
                add ebx, eax
                mov eax, ecx
                cdq
                imul 10
                cmp edx, 1
                    je ch // if equal
                    jmp start
                    ch:
                        imul eax, dx
                        add ebx, eax
                        div dx
                        imul eax, 10
                        jmp start
                _error:

    }
}