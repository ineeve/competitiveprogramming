//COINS - Bytelandian gold coins
#include <bits/stdc++.h>
using namespace std;

const unsigned long MAX_ARRAY_VALUE = 100000000;


unsigned long byteland_dynamic(unsigned long value, unsigned long *array, unsigned long &maxNumCalculated){
    int maxSize = min(value,MAX_ARRAY_VALUE);
    unsigned long i = maxNumCalculated;
    for (; i <= maxSize; i++){
        array[i] = max(array[i/4]+array[i/3]+array[i/2],i);
    }
    if (i > maxNumCalculated){
        maxNumCalculated = i;
    }
    return array[value];
}

unsigned long recursive(unsigned long value, unsigned long *array, unsigned long &maxNumCalculated){
    if (value < MAX_ARRAY_VALUE){
        return byteland_dynamic(value, array, maxNumCalculated);
    }
    return max(recursive(value/2,array,maxNumCalculated) + recursive(value/3,array,maxNumCalculated) + recursive(value/4,array,maxNumCalculated),value);
}

int main() {
    ios::sync_with_stdio(0); //input and output become more efficient.
    cin.tie();
    unsigned long x;
    unsigned long *array = new unsigned long[MAX_ARRAY_VALUE+1];
    array[0]= 0;
    array[1]= 1;
    array[2]= 2;
    unsigned long max = 2;
    while(cin >> x){
        cout << recursive(x,array,max) << "\n";
    }
}