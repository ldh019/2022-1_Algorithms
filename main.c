#include <stdio.h>
#include <time.h>

void setting(int arr[], int n) {
    for(int i = 1; i <= n; i++)
        arr[i] = n - i + 1;
}

void bubble(int arr[], int n) {
    int i, j;
    int tmp;

    for(i = n; i > 1; i++) {
        for(j = 1; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void insertion(int arr[], int n) {
    int i, j;
    int tmp;

    for(i = 2; i <= n; i++) {
        tmp = arr[i];
        for(j = i - 1; j > 0; j--) {
            if(arr[j] > tmp) {
                arr[j + 1] = arr[j];
            }
            else break;
        }
        arr[j + 1] = tmp;
    }
}

void combine(int arr[], int l, int mid, int r) {
    int i1 = l, i2 = mid + 1;
    int l1 = mid, l2 = r;
    int tmp[10001], cnt = 1;

    while(i1 <= mid && i2 <= r) {
        if(arr[i1] <= arr[i2])
            tmp[cnt++] = arr[i1++];
        else
            tmp[cnt++] = arr[i2++];
    }
    for(; i1 <= l1; i1++)
        tmp[cnt++] = arr[i1];

    for(; i2 <= l2; i2++)
        tmp[cnt++] = arr[i2];

    for(int i = l; i <= r; i++)
        arr[i] = tmp[i];
}

void merge(int arr[], int l, int r) {
    int mid;

    if(l < r) {
        mid = (l + r) / 2;

        merge(arr, l, mid);
        merge(arr, mid + 1, r);
        combine(arr, l, mid, r);
    }
}

int partition(int arr[], int l, int r) {
    int pivot = l;
    int low, high, tmp;
    l++;
    low = l; high = r;

    while(low < high) {
        for(;arr[low] <= arr[pivot] && low <= r; low++);
        for(;arr[high] > arr[pivot] && high >= l; high--);

        if(low < high) {
            tmp = arr[low];
            arr[low] = arr[high];
            arr[high] = tmp;
        }
    }

    tmp = arr[pivot];
    arr[pivot] = arr[high];
    arr[high] = tmp;

    return high;
}

void quick(int arr[], int l, int r) {
    if(l < r) {
        int p = partition(arr, l, r);

        quick(arr, l, p - 1);
        quick(arr, p + 1, r);
    }
}

void radix(int arr[], int n) {

}

void bucket(int arr[], int n) {
    int bucketArr[10][n];
    int cnt[10] = {0, };
    int bucketNum;

}

int main() {
    clock_t start, end;
    int arr[10001];

    setting(arr, 1000);

    start = clock();



    end = clock();

    printf("Execution Time : %f", end - start);

    return 0;
}
