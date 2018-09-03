#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/* 
    InsertionSort  O(N^2)
 */
void InsertionSort(ElementType A[], int N){
    int j,P;

    ElementType Tmp;
    for(P=1; P<N; P++){
        Tmp = A[P];
        for(j=P; j>0 && A[j-1] > Tmp; j--){
            A[j] = A[j-1];
        }
        A[j] = Tmp;
    }
}

/*  
    缩小增量排序
    ShellSort 亚二次时间界，最坏情况 Theta(N^(4/3))
    最好的序列 {1, 5, 19, 41, 109, ...}
*/
void ShellSort(ElementType A[], int N){
    int i, j, Increment;
    ElementType Tmp;

    for(Increment = N/2; Increment > 0; Increment /= 2)
        for(i = Increment; i<N; i++){
            Tmp = A[i];
            for(j=i; j >= Increment; j-= Increment){
                if(Tmp < A[j - Increment])
                    A[j] = A[j - Increment];
                else   
                    break;
            }
            A[j] = A[i];
        }
    
}

/* 
    堆排序
    PercDown    O(Nlog(N))
 */
#define LeftChild(i) (2 * (i) + 1)
// 下滤，将大元素移到父节点
void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType Tmp;

    for(Tmp = A[i]; LeftChild(i)< N; i = Child)
    {
        Child = LeftChild(i);
        if(Child != N-1 && A[Child + 1] > A[Child])
            Child++;
        if(Tmp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Tmp;
}

void Swap(ElementType *a, ElementType *b)
{
    ElementType tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void HeapSort(ElementType A[], int N)
{
    int i;

    for(i=N/2; i >= 0; i--)  /* BuildHeap */
        PercDown(A, i, N);
    for(i = N-1; i>0; i--)
    {
        Swap(&A[0], &A[i]); /*  DeleteMax */
        PercDown(A, 0, i);
    }
}

/* 
    归并排序    MergeSort   O(Nlog(N))
 */
/* Lpos = start of left half, Rpos = start of right half */
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
    int i, LeftEnd, NumElements, TmpPos;

    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    /* main loop */
    while (Lpos <= LeftEnd && Rpos <= RightEnd)
        if (A[Lpos] <= A[Rpos])
            TmpArray[TmpPos++] = A[Lpos++];
        else
            TmpArray[TmpPos++] = A[Rpos++];

    while (Lpos <= LeftEnd) /* Copy rest of first half */
        TmpArray[TmpPos++] = A[Lpos++];
    while (Rpos <= RightEnd) /* Copy rest of second half */
        TmpArray[TmpPos++] = A[Rpos++];

    /* Copy TmpArray back */
    for (i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TmpArray[RightEnd];
}
void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
    int Center;

    if(Left < Right)
    {
        Center = (Left + Right)/2;
        MSort(A, TmpArray, Left, Center);
        MSort(A, TmpArray, Center+1, Right);
        Merge(A, TmpArray, Left, Center+1, Right);
    }
}

void Mergesort(ElementType A[], int N)
{
    ElementType *TmpArray;
    TmpArray = malloc(N*sizeof(ElementType));
    if(TmpArray != NULL)
    {
        MSort(A, TmpArray, 0, N-1);
        free(TmpArray);
    }
    else 
        printf("No space for tmp array");
}

/* 
    快速排序
    Quicksort   O(Nlog(N))
 */
/* Return median of Left, Center, and Right */
/* Order these and hide the pivot */
ElementType Median3(ElementType A[], int Left, int Right)
{
    int Center = (Left + Right)/2;

    if(A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    /* Invariant: A[Left] <= A[Center] <= A[Right] */
    Swap(&A[Center], &A[Right - 1]);
    return A[Right - 1];
}
#define Cutoff (3)
void Qsort(ElementType A[], int Left, int Right)
{
    int i, j;
    ElementType Pivot;

    if(Left + Cutoff <= Right)
    {
        Pivot = Median3(A, Left, Right);
        i = Left; j = Right - 1;
        for(;;)
        {
            while(A[++i] < Pivot){}
            while(A[--j] > Pivot){}
            if(i<j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        Swap(&A[i], &A[Right-1]); /* Restore pivot */
        Qsort(A, Left, i-1);
        Qsort(A, i + 1, Right);
    }
    else    /* Do an insertion sort on the subarray */
        InsertionSort(A + Left, Right - Left + 1);
}
void Quicksort(ElementType A[], int N)
{
    Qsort(A, 0, N-1);
}

/* 
    快速选择，替代快速排序中的 Qsort 的实现
    Quick select    O(Nlog(N))  最坏：O(N^2)    平均:O(N)
 */

void Qselect(ElementType A[], int k, int Left, int Right)
{
    int i, j;
    ElementType Pivot;

    if(Left + Cutoff <= Right)
    {
        Pivot = Median3(A, Left, Right);
        i = Left; j = Right - 1;
        for(;;)
        {
            while(A[++i] < Pivot){}
            while(A[--j] > Pivot){}
            if(i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        Swap(&A[i], &A[Right-1]);

        if( k <= i)
            Qselect(A, k, Left, i-1);
        else if(k > i+1)
            Qselect(A, k, i+1, Right);
    }
    else
        InsertionSort(A+Left, Right-Left+1);
}

/* 
    桶式排序
    bucket sort     O(M+N)
 */
#define MAX (65535)
void Bucketsort(ElementType A[], int N)
{
    int bucket[MAX];
    int i,j;
    /* 初始化桶 */
    for(i=0;i<MAX;i++)
        bucket[i] = 0;
    
    /* 记录元素个数 */
    for(i=0;i<N;i++)
        bucket[A[i]]++;
    /* 将桶中有序元素返回给原数组 */
    for(i=0,j=0;i<MAX;i++)
    {
        if(bucket[i]!=0)
            A[j++] = i;
    }
}