#include <iostream>
#include <vector>
#include <algorithm>





int main() {
	char number1[] = { 9, 2, 3, 4, 3, 2, 1 };
	const int M = 7;
	char number2[] = { 9, 8, 2, 3, 4, 3, 2, 1 };
	const int N = 8;

	int l = std::max(N, M);
	int k = std::min(N, M);

	constexpr int A = std::max(N, M) + 1;
	char result[A]{ 0 };

	char ten = 10;
	__asm {
		mov ecx, k;
		mov ebx, l;

		xor eax, eax;
		xor esi, esi;
	_cycle:
		mov al, byte ptr number1[esi];
		add al, byte ptr number2[esi];
		mov result[esi], al;
		inc esi;
		loop _cycle;

		mov eax, M;
		cmp eax, N;  // M - N

		jng _mass2;
	_mass1:
		mov ecx, M;
		sub ecx, k;
		jecxz _norm;
	_cycle2:
		mov al, byte ptr number1[esi];
		mov result[esi], al;
		inc esi;
		loop _cycle2;
		jmp _norm;

	_mass2:
		mov ecx, N;
		sub ecx, k;
		jecxz _norm;
	_cycle3:
		mov al, byte ptr number2[esi];
		mov result[esi], al;
		inc esi;
		loop _cycle3;

	_norm:
		mov ecx, l;
		xor esi, esi;
		_cycle4:
		mov al, result[esi];
		cbw;     
		div ten;

		mov result[esi], ah;
		inc esi;

		add al, result[esi];
		mov result[esi], al;
		loop _cycle4;
		cmp al, 1;
		je _plus;
		jmp _done;
	_plus:
		inc l;
	_done:

	}

	for (int i = 0; i < l; ++i) {
		std::cout << (int)result[i] << '\n';
	}
	// сортировка выбором

	return 0;
}