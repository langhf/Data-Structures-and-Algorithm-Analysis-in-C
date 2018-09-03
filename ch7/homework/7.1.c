#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void Insertionsort(ElementType A[], int N)
{
    int i, j, tmp;

    for(i=1; i<N; i++)
    {
        tmp = A[i];
        for(j=i; j>0 && tmp < A[j-1]; j--)/* 不满足条件时，立即停止，退出 for 循环，不会比较所有之前的元素 */
            A[j] = A[j-1];
        A[j] = tmp;
    }
}

int main()
{
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int N = 9;
    int i;

    printf("Before: ");
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");

    printf("After:  ");
    Insertionsort(A, N);
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    exit(0);
}