#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define N (8)

int main(){
    int A[N] = { 54, 12, 15, 48, 20, 58, 8, 32};
    Bucketsort(A, N);    
    for(int i=0; i<N; i++){
        printf("%d \n", A[i]);
    }
    exit(0);
}