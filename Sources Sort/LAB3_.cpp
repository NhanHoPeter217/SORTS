#include "Sort.h"
#include "DataGenerator.h"
#include <iostream>
#include <time.h>

#define EX1 10000
#define EX2 30000
#define EX3 50000
#define EX4 100000
#define EX5 300000
#define EX6 500000

using namespace std;

int main()
{
    long long comparison = 0;
    clock_t start, end;
    double cpu_time_used;
    int* a = new int[EX6];
    GenerateData(a, EX6, 1);
    /*
    start = clock();
    insertionSort(a, EX1);
    end = clock();
    cpu_time_used = ((double)end - (double)start) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << endl;
    */
    /*
    quickSort(a, 0, EX6 - 1, comparison);
    cout << comparison << endl;
    */
    //printarray(a, EX6);
    delete[] a;
}