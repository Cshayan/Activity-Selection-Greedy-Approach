#include <stdio.h>
#include <stdlib.h>

struct Activity
{
    int start;
    int finish;
};

struct Activity arr[6] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                                       {5, 7}, {8, 9}};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b =temp;
}

int partition(struct Activity arr[], int low, int high)
{
    int pivot = arr[high].finish;
    int pIndex = low;
    int i;
    for(i = low; i < high; i++)
    {
        if(arr[i].finish < pivot)
        {
            swap(&arr[i].finish, &arr[pIndex].finish);
            swap(&arr[i].start, &arr[pIndex].start);
            pIndex++;
        }
    }
            swap(&arr[high].finish, &arr[pIndex].finish);
            swap(&arr[high].start, &arr[pIndex].start);
    return pIndex;
}

void qSort(struct Activity arr[], int low, int high)
{
    if(low < high)
    {
        int pIndex = partition(arr, low, high);
        qSort(arr, low, pIndex-1);
        qSort(arr, pIndex+1, high);
    }
}

int selectActivity(struct Activity arr[], int n)
{
    qSort(arr, 0, n-1);

    int i;
    int countProcess = 1, j = 0;
    printf("\nProcesses selected are:- \n");
    printf("\n( %d, %d )\n", arr[0].start, arr[0].finish);
    for(i = 1; i < n; i++)
    {
        if(arr[j].finish <= arr[i].start)
        {
            printf("\n( %d, %d )\n", arr[i].start, arr[i].finish);
            countProcess++;
            j = i;
        }
    }
    return countProcess;
}

int main()
{
    printf("\nNumber of processes selected is %d\n", selectActivity(arr, 6));
    return 0;
}
