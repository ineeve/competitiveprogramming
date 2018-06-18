//this includes all needed libraries
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); //input and output become more efficient.
    cin.tie();
    int num_tests;
    cin >> num_tests;
    int num1, num2;
    int i = 0;
    while(i++ < num_tests){
        cin >> num1;
        cin >> num2;
        if (num1 < 2){num1 = 2;}
        while(num1 <= num2){
            double maxDiv = sqrt(num1);
            int isPrime = 1;
            for (int j = 2; j <= maxDiv; j++){
                if (j==num1) continue;
                if (num1 % j == 0){isPrime = 0; break;}
            }
            if (isPrime){
                cout << num1 << "\n";
            }
            num1++;
        }
        cout << "\n";
    }
}