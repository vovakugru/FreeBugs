#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Password(string pass_key) { // Create simple password for file .cpp
    string key;
    cin >> key;
    if (key == pass_key) {return 1;}
    cout << "Wrong password!";
    return 0;
}

void Space(int how_much_escapes) { // Add escapes for out
    for(; how_much_escapes > 0; --how_much_escapes) {
        cout << "\n";
    }
}

void End() { // Exit file
    exit(0);
}

//----------


//----------

template <class F1> // All Fouts are displaying text
void Fout(F1 out) {
    cout << out;
}

template <class F1, class F2>
void Fout(F1 out, F2 __) {
    cout << out << __;
}

template <class F1, class F2, class F3>
void Fout(F1 out, F2 __, F3 _) {
    cout << out << __ << _;
}

template <class F1, class F2, class F3, class F4>
void Fout(F1 out, F2 __, F3 _, F4 ___) {
    cout << out << __ << _ << ___;
}

template <class F1, class F2, class F3, class F4, class F5>
void Fout(F1 __, F2 a, F3 b, F4 c, F5 d) {
    cout << __ << a << b << c << d;
}

template <class F1, class F2, class F3, class F4, class F5, class F6>
void Fout(F1 __, F2 a, F3 b, F4 c, F5 d, F6 e) {
    cout << __ << a << b << c << d << e;
}

template <class F1, class F2, class F3, class F4, class F5, class F6, class F7>
void Fout(F1 __, F2 a, F3 b, F4 c, F5 d, F6 e, F7 f) {
    cout << __ << a << b << c << d << e << f;
}

template <class F1, class F2, class F3, class F4, class F5, class F6, class F7, class F8>
void Fout(F1 __, F2 a, F3 b, F4 c, F5 d, F6 e, F7 f, F8 g) {
    cout << __ << a << b << c << d << e << f << g;
}

template <class F1, class F2, class F3, class F4, class F5, class F6, class F7, class F8, class F9>
void Fout(F1 __, F2 a, F3 b, F4 c, F5 d, F6 e, F7 f, F8 g, F9 h) {
    cout << __ << a << b << c << d << e << f << g << h;
}

template <class F1, class F2, class F3, class F4, class F5, class F6, class F7, class F8, class F9, class F0>
void Fout(F1 __, F2 a, F3 b, F4 c, F5 d, F6 e, F7 f, F8 g, F9 h, F0 i) {
    cout << __ << a << b << c << d << e << f << g << h << i;
}

template <class F1> // Display vector data
void Vout(vector <F1> vector, string what_between) {
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << what_between;
    }
}
