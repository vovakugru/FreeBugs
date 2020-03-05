#pragma once
#include "basic+lib.h"
using namespace std;

void StartFunc() {
    int a, b, c, d, result = 0;
    cin >> a;
    __asm {
        mov eax, a
        imul eax, a
        mov b, eax
        imul eax, a
        mov c, eax
        imul eax, b
        mov d, eax
        mov ebx, 0
        add ebx, a
        add ebx, c
        add ebx, d
        mov result, ebx
    }
    Fout(result);
}