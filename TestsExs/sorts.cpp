#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 30000

void Wrong() //输入错误
{   
    printf("\n语法错误，请重新输入！\n");
    getchar();
}

void Disp(int a[])  //清屏
{    
    int i;
    system("cls");
    for(i = 0; i < N; i++) {
        if((i - 1) % 10 == 9)
            printf("\n");
            printf("%-7d",a[i]);
    }
}

void InsertSort(int a[], int p) //直接插入排序算法
{    
    int i, j, temp;
    for(i = 1; i < N; i++) {
        temp=a[i];
        for(j = i; j > 0 && a[j-1] > temp; j--)     // 逐步往前挪位置，给插入值腾地儿
            a[j]=a[j-1];
        a[j]=temp;
    }
}

void SelectSort(int a[], int p)   //选择排序算法
{    
    int i, j, k;
    for(i = 0; i < N-1; i++) { 
        k = i;
        for(j = i + 1; j < N; j++)
            if(a[j] < a[k])
                k = j;
        if(k != i) {
            int temp;
            temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
}

void BubbleSort(int a[], int p) //冒泡排序算法
{    
    int i, j, temp;
    for (i = 0; i < N-1; i++)
    {
        for (j = N-1; j > i; j--) //比较,找出本趟最小关键字的记录
            if (a[j] < a[j - 1]) {
                temp = a[j];    //进行交换,将最小关键字记录前移
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
    }
}

void quicksort(int a[], int n, int p)   //快速排序算法
{    
    int i, j, low, high, temp, top=-1;
    struct node {
        int low,high;
    } st[N];
    top++;
    st[top].low = 0;
    st[top].high = n-1;
    while(top > -1) {
        low = st[top].low;
        high = st[top].high;
        top--;
        i = low;
        j = high;
        if(low < high) {
            temp = a[low];
            while(i != j) {
                while(i < j && a[j] > temp)
                    j--;
                if(i < j) {
                    a[i] = a[j];
                    i++;
                }
                
                while(i < j && a[i] < temp)
                    i++;
                if(i < j) {
                    a[j] = a[i];
                    j--;
                }
            } 
            a[i] = temp;
            top++;
            st[top].low = low;
            st[top].high = i-1;
            top++;
            st[top].low = i+1;
            st[top].high = high;
        }
    }
}
