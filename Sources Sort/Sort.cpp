#include "Sort.h"
#include <iostream>

using namespace std;

void printarray(int arr[], int n)
{
    cout << "array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_i;
    for (i = 0; i < n - 1; i++)
    {
        min_i = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_i])
                min_i = j;
        swap(arr[min_i], arr[i]);
    }
}
void selectionSort(int arr[], int n, long long& d)
{
    int i, j, min_i;
    for (i = 0; ++d && i < n - 1; i++)
    {
        min_i = i;
        for (j = i + 1; ++d && j < n; j++)
            if (++d && arr[j] < arr[min_i])
                min_i = j;
        swap(arr[min_i], arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertionSort(int arr[], int n, long long& d)
{
    int key, j;
    for (int i = 1; ++d && i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (++d && j >= 0 && ++d && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void bubbleSort(int arr[], int n, long long& d)
{
    int i, j;
    for (i = 0; ++d && i < n - 1; i++) {
        for (j = 0; ++d && j < n - i - 1; j++) {
            if (++d && arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;  j = 0; k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}
void merge(int arr[], int l, int m, int r, long long& d)
{
    int nL = m - l + 1, nR = r - m;
    int* L = new int[nL], * R = new int[nR];
    for (int i = 0; i < nL; i++)
    {
        ++d;
        L[i] = arr[l + i];
    }
    ++d;
    for (int i = 0; i < nR; i++)
    {
        ++d;
        R[i] = arr[m + i + 1];
    }
    ++d;
    int i = 0, j = 0, indexarr = l;
    while (++d && i < nL && ++d && j < nR)
    {
        if (++d && L[i] < R[j])
        {
            arr[indexarr++] = L[i++];
        }
        else
        {
            arr[indexarr++] = R[j++];
        }
    }
    while (++d && i < nL)
    {
        arr[indexarr++] = L[i++];
    }
    while (++d && j < nR)
    {
        arr[indexarr++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void mergeSort(int arr[], int l, int r, long long& d)
{
    if (++d && l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, d);
        mergeSort(arr, m + 1, r, d);
        merge(arr, l, m, r, d);
    }
}

void shakerSort(int M[], int n)
{
    int left = 0, right = n - 1, k = n - 1;
    while (left < right)
    {
        for (int i = right; i > left; i--)
            if (M[i - 1] > M[i])
            {
                swap(M[i - 1], M[i]);
                k = i;
            }
        left = k;
        for (int j = left; j < right; j++)
            if (M[j] > M[j + 1])
            {
                swap(M[j], M[j + 1]);
                k = j;
            }
        right = k;
    }
}

void shakerSort(int M[], int n, long long& d)
{
    int left = 0, right = n - 1, k = n - 1, b = 1;
    while (++d&& left < right)
    {
        for (int i = right; ++d && i > left; i--)
            if (++d && M[i - 1] > M[i])
            {
                swap(M[i - 1], M[i]);
                k = i;
            }
        left = k;
        for (int j = left; ++d && j < right; j++)
            if (++d && M[j] > M[j + 1])
            {
                swap(M[j], M[j + 1]);
                k = j;
            }
        right = k;
    }
}

void shellSort(int a[], int n)
{
    int interval, i, j, temp;
    for (interval = n / 2; interval > 0; interval /= 2) {
        for (i = interval; i < n; i++) {
            temp = a[i];
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

void shellSort(int a[], int n, long long& d)
{
    int interval, i, j, temp;
    for (interval = n / 2; ++d && interval > 0; interval /= 2) {
        for (i = interval; ++d && i < n; i++) {
            temp = a[i];
            for (j = i; ++d && j >= interval && ++d && a[j - interval] > temp; j -= interval) {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

void heapdify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapdify(arr, n, largest);
    }
}

void heapdify(int arr[], int n, int i, long long& d)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (++d && l < n && ++d && arr[l] > arr[largest])
        largest = l;

    if (++d && r < n && ++d && arr[r] > arr[largest])
        largest = r;

    if (++d && largest != i)
    {
        swap(arr[i], arr[largest]);
        heapdify(arr, n, largest, d);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapdify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapdify(arr, i, 0);
    }
}
void heapSort(int arr[], int n, long long& d)
{
    for (int i = n / 2 - 1; ++d && i >= 0; i--)
        heapdify(arr, n, i, d);
    for (int i = n - 1; ++d && i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapdify(arr, i, 0, d);
    }
}

int partition(int a[], int first, int last)
{
    int pivot = a[(first + last) / 2];
    int i = first;
    int j = last;
    int tmp;
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i;
}
int partition(int a[], int first, int last, long long& d)
{
    int pivot = a[(first + last) / 2];
    int i = first;
    int j = last;
    int tmp;
    while (++d && i <= j)
    {
        while (++d && a[i] < pivot)
            i++;
        while (++d && a[j] > pivot)
            j--;
        if (++d && i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i;
}
void quickSort(int a[], int first, int last)
{
    int index = partition(a, first, last);
    if (first < index - 1)
        quickSort(a, first, index - 1);
    if (index < last)
        quickSort(a, index, last);
}

void quickSort(int a[], int first, int last, long long& d)
{
    int index = partition(a, first, last, d);
    if (++d && first < index - 1)
        quickSort(a, first, index - 1, d);
    if (++d && index < last)
        quickSort(a, index, last, d);
}
void countingSort(int arr[], int n)
{
    int* output = new int[n];
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
    int k = max - min + 1;
    int* countarrrray = new int[k];
    fill_n(countarrrray, k, 0);

    for (int i = 0; i < n; i++)
        countarrrray[arr[i] - min]++;
    for (int i = 1; i < k; i++)
        countarrrray[i] += countarrrray[i - 1];
    for (int i = 0; i < n; i++)
    {
        output[countarrrray[arr[i] - min] - 1] = arr[i];
        countarrrray[arr[i] - min]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void countingSort(int arr[], int n, long long& d)
{
    int* output = new int[n];
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; ++d && i < n; i++)
    {
        if (++d && arr[i] > max)
            max = arr[i];
        else if (++d && arr[i] < min)
            min = arr[i];
    }
    int k = max - min + 1;
    int* countarrrray = new int[k];
    fill_n(countarrrray, k, 0);
    for (int i = 0; ++d && i < n; i++)
        countarrrray[arr[i] - min]++;
    for (int i = 1; ++d && i < k; i++)
        countarrrray[i] += countarrrray[i - 1];
    for (int i = 0; i < n; i++)
    {
        ++d;
        output[countarrrray[arr[i] - min] - 1] = arr[i];
        countarrrray[arr[i] - min]--;
    }
    ++d;
    for (int i = 0; ++d && i < n; i++)
    {
        arr[i] = output[i];
    }
}


int getMax(int arr[], int n)
{
    int _max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > _max)
            _max = arr[i];
    return _max;
}

int getMax(int arr[], int n, long long& d)
{
    int _max = arr[0];
    for (int i = 1; ++d && i < n; i++)
        if (++d && arr[i] > _max)
            _max = arr[i];
    return _max;
}

int digit(int a, int k) {

    while (a > 0 && k > 0) {
        a /= 10;
        k--;
    }
    return a % 10;
}
int digit(int a, int k, long long& d) {

    while (++d && a > 0 && ++d && k > 0) {
        a /= 10;
        k--;
    }
    return a % 10;
}

void countSort(int a[], int n, int k) {

    int f[10] = { 0 };

    for (int i = 0; i < n; i++)
        f[digit(a[i], k)]++;

    for (int i = 1; i < 10; i++)
        f[i] += f[i - 1];

    int* b = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        int j = digit(a[i], k);
        b[f[j] - 1] = a[i];
        f[j]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[]b;
}
void countSort(int a[], int n, int k, long long& d)
{

    int f[10] = { 0 };

    for (int i = 0; ++d && i < n; i++)
        f[digit(a[i], k, d)]++;

    for (int i = 1; ++d && i < 10; i++)
        f[i] += f[i - 1];

    int* b = new int[n];

    for (int i = n - 1; ++d && i >= 0; i--) {
        int j = digit(a[i], k, d);
        b[f[j] - 1] = a[i];
        f[j]--;
    }

    for (int i = 0; ++d && i < n; i++)
        a[i] = b[i];

    delete[]b;
}

void radixSort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    for (int i = 0; max > 0; i++) {
        max /= 10;
        countSort(a, n, i);
    }
}
void radixSort(int a[], int n, long long& d) {
    int max = a[0];
    for (int i = 1; ++d && i < n; i++)
        if (++d && a[i] > max)
            max = a[i];
    for (int i = 0; ++d && max > 0; i++) {
        max /= 10;
        countSort(a, n, i, d);
    }
}


void flashSort(int arr[], int n)
{
    int m = (int)(0.45 * n);
    int* L = new int[m];
    fill_n(L, m, 0);
    int _max = getMax(arr, n), _min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < _min)
            _min = arr[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k = (int)(((double)m - 1) / ((double)_max - _min)) * (arr[i] - _min);
        L[k] += 1;
    }

    for (int i = 1; i < m; i++)
    {
        L[i] += L[i - 1];
    }

    int count = 0;
    int i = 0;
    k = m - 1;

    while (count < n) {
        while (i >= L[k]) {
            i++;
            k = (int)(((double)m - 1) / ((double)_max - _min)) * (arr[i] - _min);
        }
        int x = arr[i];
        while (i < L[k]) {
            k = (int)(((double)m - 1) / ((double)_max - _min)) * (x - _min);
            int y = arr[L[k] - 1];
            arr[L[k] - 1] = x;
            x = y;
            L[k]--;
            count++;
        }
    }

    for (int k = 1; k < m; k++)
    {
        for (int i = L[k] - 2; i >= L[k - 1]; i--)
            if (arr[i] > arr[i + 1])
            {
                int t = arr[i];
                int j = i;
                while (t > arr[j + 1])
                {
                    arr[j] = arr[j + 1];
                    j++;
                }
                arr[j] = t;
            }
    }

}

void flashSort(int arr[], int n, long long& d)
{
    int m = (int)(0.45 * n);
    int* L = new int[m];
    fill_n(L, m, 0);
    int _max = getMax(arr, n, d), _min = arr[0];
    for (int i = 0; ++d && i < n; i++)
    {
        if (++d && arr[i] < _min)
            _min = arr[i];
    }
    int k = 0;
    for (int i = 0; ++d && i < n; i++)
    {
        k = (int)(((double)m - 1) / ((double)_max - _min)) * (arr[i] - _min);
        L[k] += 1;
    }

    for (int i = 1; ++d && i < m; i++)
    {
        L[i] += L[i - 1];
    }

    int count = 0;
    int i = 0;
    k = m - 1;

    while (++d && count < n) {
        while (++d && i >= L[k]) {
            i++;
            k = (int)(((double)m - 1) / ((double)_max - _min)) * (arr[i] - _min);
        }
        int x = arr[i];
        while (++d && i < L[k]) {
            k = (int)(((double)m - 1) / ((double)_max - _min)) * (x - _min);
            int y = arr[L[k] - 1];
            arr[L[k] - 1] = x;
            x = y;
            L[k]--;
            count++;
        }
    }
    for (int k = 1; ++d && k < m; k++)
    {
        for (int i = L[k] - 2; ++d && i >= L[k - 1]; i--)
            if (++d && arr[i] > arr[i + 1])
            {
                int t = arr[i];
                int j = i;
                while (++d && t > arr[j + 1])
                {
                    arr[j] = arr[j + 1];
                    j++;
                }
                arr[j] = t;
            }
    }
}