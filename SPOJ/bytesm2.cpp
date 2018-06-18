//BYTESM2
#include <bits/stdc++.h>
using namespace std;



int posToIndex(int cols, int col, int row){
    return cols*row + col;
}

int upLeft(int *matrix, int cols, int row, int col){
    if (col==0) return 0;
    return matrix[posToIndex(cols,col-1,row-1)];
}
int up(int *matrix, int cols, int row, int col){
    return matrix[posToIndex(cols,col,row-1)];
}
int upRight(int *matrix, int cols, int row, int col){
    if (col==cols-1) return 0;
    return matrix[posToIndex(cols,col+1,row-1)];
}


int bestPath(int *matrix, int rows, int cols){
    int best = 0;
    int pos;
    for (int row = 1; row < rows; row++){
        for (int col=0; col < cols; col++){
            pos = posToIndex(cols,col,row);
            matrix[pos] += max(upLeft(matrix,cols,row,col), max(up(matrix,cols,row,col),upRight(matrix,cols,row,col)));
            if (matrix[pos] > best){
                best = matrix[pos];
            }
        }
    }
    return best;
}


int main() {
    ios::sync_with_stdio(0); //input and output become more efficient.
    cin.tie();
    int tests, rows, cols;
    cin >> tests;
    while(tests--){
        cin >> rows >> cols;
        int size = rows*cols;
        int *matrix = new int[size];
        for(int i = 0; i < size; i++){
            cin >> matrix[i];
        }
        cout << bestPath(matrix, rows, cols) << "\n";
    }

}