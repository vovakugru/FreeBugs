#include <iostream>
#include <algorithm>


int main() {
	//char number1[] = { 9, 2, 3, 4, 3, 2, 1 };
	char number1[] = { 0, 7, 3, 4, 3, 2, 1 };
	const int M = 7;
	//char number2[] = { 9, 8, 2, 3, 4, 3, 2, 1 };
	char number2[] = { 3, 7, 7, 3, 4, 3, 2, 1 };
	const int N = 8;

	constexpr int l = std::max(N, M);
	int k = std::min(N, M);

	//constexpr int A = std::max(N, M) + 1;
	char result[l]{ 0 };

	char degree = 10;

	char* a = number1; // a -большее число, b - меньшее число
	char* b = number2;

	char is_swap = 0;

	__asm {
		mov ecx, k;
		mov ebx, l;

		xor eax, eax;
		xor esi, esi;

		mov eax, M;
		cmp eax, N;
		jb _swap;
		jg _substraction;
		// в случае равенства проверяем старшую цифру
		mov esi, M;
		dec esi;
		mov ecx, esi;
	_compare_digits:
		mov al, number1[esi];
		cmp al, number2[esi];
		jb _swap;
		jg _substraction;
		// цифры равны
		dec esi;
		loop _compare_digits;

		jmp _continue;

	_swap:
		lea esi, number2;
		mov a, esi;
		lea esi, number1;
		mov b, esi;
		mov al, 1;
		mov is_swap, al;

	_substraction:
		xor esi, esi;
		mov ecx, k;
		// находим разность
	_cycle:
		mov al, a[esi];
		sub al, b[esi];
		mov result[esi], al;
		inc esi;
		loop _cycle;

		mov ecx, l; // максимальный рвзмер
		sub ecx, k; // - минималный
	_transfer:
		mov al, a[esi];
		mov result[esi], al;
		inc esi;
		loop _transfer;

		xor esi, esi;
		mov al, 0;
		mov ecx, l; // размер результата
	_norm:
		cmp result[esi], al;
		jge _next_digit;
		mov bl, degree;
		add bl, result[esi];
		mov result[esi], bl;
		inc esi;
		mov bl, result[esi];
		dec bl;
		mov result[esi], bl;
		jmp _next_step;

	_next_digit:
		inc esi;
	_next_step:
		loop _norm;
	}
	
	
	return 0;
}