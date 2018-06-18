// FCTRL - Factorial
#include <bits/stdc++.h>
using namespace std;

long getTrailingZeros(unsigned long x){
    unsigned long numZeros = 0;
    unsigned long power = 5;
    while(x >= power){
        numZeros += x/power;
        power = power * 5;
    }
    return numZeros;
}

int main() {
    ios::sync_with_stdio(0); //input and output become more efficient.
    cin.tie();
    unsigned long tests, x;
    cin >> tests;
    while(tests--){
        cin >> x;
        cout << getTrailingZeros(x) << "\n";
    }
}