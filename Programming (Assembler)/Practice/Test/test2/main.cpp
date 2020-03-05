#include <iostream>

using namespace std;

int main() {
    char number1[] = { 1,1,0,1,1,1,1,1,0,1 };
    char number2[] = { 1,1,0,1,1,1,1,1,0,0 };

    const int M = 10; // amount of elements in number1
    const int N = 10; // amount of elements in number2
    char result[]{ 0 };

    int l = std::max(N, M);
    int k = std::min(N, M);

    int A= std::max(N, M)+1;

    int n; //= std::max(number1.size(), number2.size()) + 1;
    char elem = 0;

    __asm {
        mov ecx, k
        mov ebx, l
        //mov eax, n
        xor eax, eax
        xor esi, esi
        lea esi, 0
        //jecxz done

    cycle:
        mov al, byte ptr number1[esi]
        add al, byte ptr number2[esi]
        mov result[esi], al
        inc esi
        loop cycle
        jmp _norm

        mov eax, M
        cpm eax, N//M-N

        jng _mass2

    _mass1:
        mov ecx, M
        sub ecx, k
        jecxz _norm
    _cycle2:
        mov al, byte btr number1[esi]
        mov result[esi], al

        inc esi
        loop _cycle2

        jmp _norm

    _mass2:
        mov ecx, N

        sub ecx, k
        jecxz _norm

    _cycle3:
        mov al, byte btr number2[esi]
        mov result[esi], al
        inc esi
        loop _cycle3

    _norm :

    done:

    }
    return 0;
}
