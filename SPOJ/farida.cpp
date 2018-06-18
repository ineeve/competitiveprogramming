// FARIDA - Princess Farida

//this includes all needed libraries
#include <bits/stdc++.h>
using namespace std;

unsigned long long dynamic_farida(unsigned long long *coins_array, int size){
    if (size == 0) return 0;
    if (size>1){
        coins_array[1]= max(coins_array[0],coins_array[1]);
    }
    for (int i = 2; i < size; i++){
        unsigned long long y = coins_array[i-2] + coins_array[i];
        if (coins_array[i-1] > y){
            coins_array[i]=coins_array[i-1];
        } else{
            coins_array[i] = y;
        }
        
    }
    if (size > 1){
        return max(coins_array[size-1],coins_array[size-2]);
    }
    return coins_array[size-1];
}


int main() {
    ios::sync_with_stdio(0); //input and output become more efficient.
    cin.tie();
    int num_tests,i=1;
    cin >> num_tests;
    while(i <= num_tests){
        int num_monsters, j = 0;
        cin >> num_monsters;
        unsigned long long *coins_array = new unsigned long long[num_monsters];
        while(j < num_monsters){
            cin >> coins_array[j++];
        }
        cout << "Case " << i++ << ": " << dynamic_farida(coins_array, num_monsters);
        cout << "\n";
    }
}