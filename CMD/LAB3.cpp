#include "Sort.h"
#include "DataGenerator.h"

#include <string.h>
#include <stdint.h> // standard integer
#include <cctype> // toupper
#define MAX_SIZE 1000000

void Generate(int arr[], int n, char order[])
{
    if (!strcmp(order, "-rand")) { GenerateData(arr, n, 0); return; }
    if (!strcmp(order, "-nsorted")) { GenerateData(arr, n, 3); return; }
    if (!strcmp(order, "-sorted")) { GenerateData(arr, n, 1); return; }
    if (!strcmp(order, "-rev")) { GenerateData(arr, n, 2); return; }
}

bool exist_algorithm(char str[])
{
    char c = str[0];
    str[0] = toupper(str[0]);
    if (str[0] == c) return false;

    for (int i = 4; i < strlen(str); ++i) {
        if (str[i] == '-') {
            str[i] = ' ';
            c = str[i + 1];
            str[i + 1] = toupper(str[i + 1]);
            if (c == str[i + 1]) return false;
            break;
        }
    }

    if (!strcmp(str, "Selection Sort")) return true;
    if (!strcmp(str, "Insertion Sort")) return true;
    if (!strcmp(str, "Bubble Sort")) return true;
    if (!strcmp(str, "Shaker Sort")) return true;
    if (!strcmp(str, "Shell Sort")) return true;
    if (!strcmp(str, "Heap Sort")) return true;
    if (!strcmp(str, "Merge Sort")) return true;
    if (!strcmp(str, "Quick Sort")) return true;
    if (!strcmp(str, "Counting Sort")) return true;
    if (!strcmp(str, "Radix Sort")) return true;
    if (!strcmp(str, "Flash Sort")) return true;
    return false;
}

bool exist_input_order(char str[])
{
    if (!strcmp(str, "-rand")) return true;
    if (!strcmp(str, "-nsorted")) return true;
    if (!strcmp(str, "-sorted")) return true;
    if (!strcmp(str, "-rev")) return true;
    return false;
}

char* convert_to_normal_English(char str[])
{
    char* res = new char[15];
    if (!strcmp(str, "-rand")) {
        res[0] = 'R';
        res[1] = 'a';
        res[2] = 'n';
        res[3] = 'd';
        res[4] = 'o';
        res[5] = 'm';
        res[6] = 'i';
        res[7] = 'z';
        res[8] = 'e';
        res[9] = '\0';
        return res;
    }
    if (!strcmp(str, "-nsorted")) {
        res[0] = 'N';   res[1] = 'e';
        res[2] = 'a';   res[3] = 'r';
        res[4] = 'l';   res[5] = 'y';
        res[6] = ' ';   res[7] = 'S';
        res[8] = 'o';   res[9] = 'r';
        res[10] = 't';  res[11] = 'e';
        res[12] = 'd';  res[13] = '\0';
        return res;
    }
    if (!strcmp(str, "-sorted")) {
        res[0] = 'S';
        res[1] = 'o';
        res[2] = 'r';
        res[3] = 't';
        res[4] = 'e';
        res[5] = 'd';
        res[6] = '\0';
        return res;
    }
    if (!strcmp(str, "-rev")) {
        res[0] = 'R';
        res[1] = 'e';
        res[2] = 'v';
        res[3] = 'e';
        res[4] = 'r';
        res[5] = 's';
        res[6] = 'e';
        res[7] = 'd';
        res[8] = '\0';
    }
    return res;
}

bool exist_output_parameters(char str[])
{
    if (!strcmp(str, "-time")) return true;
    if (!strcmp(str, "-comp")) return true;
    if (!strcmp(str, "-both")) return true;
    return false;
}

bool isNum(char str[])
{
    for (int i = 0; i < strlen(str); ++i)
        if (str[i] > '9' || str[i] < '0') return false;

    return true;
}

int convert_to_int(char str[])
{
    int input_size = 0;
    for (int i = 0; i < strlen(str); ++i)
        input_size = input_size * 10 + (str[i] - '0');

    return input_size;
}

void print_parameters(char parameters[], double time, long long comp)
{
    if (!strcmp(parameters, "-time")) {
        cout << "Running time: " << time << '\n';
        return;
    }
    if (!strcmp(parameters, "-comp")) {
        cout << "Comparisons: " << comp << '\n';
        return;
    }
    else {
        cout << "Running time: " << time << '\n';
        cout << "Comparisons: " << comp << '\n';
    }
}

void calculate_parameters(char algorithm[], int arr[], int n, char parameters[], double& time, long long& comp)
{
    time = 0;
    comp = 0;
    if (!strcmp(parameters, "-time")) {
        if (!strcmp(algorithm, "Selection Sort")) {
            clock_t start, end;
            start = clock();
            selectionSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Insertion Sort")) {
            clock_t start, end;
            start = clock();
            insertionSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Bubble Sort")) {
            clock_t start, end;
            start = clock();
            bubbleSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Shaker Sort")) {
            clock_t start, end;
            start = clock();
            shakerSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Shell Sort")) {
            clock_t start, end;
            start = clock();
            shellSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Heap Sort")) {
            clock_t start, end;
            start = clock();
            heapSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Merge Sort")) {
            clock_t start, end;
            start = clock();
            mergeSort(arr, 0, n - 1);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Quick Sort")) {
            clock_t start, end;
            start = clock();
            quickSort(arr, 0, n - 1);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Counting Sort")) {
            clock_t start, end;
            start = clock();
            countingSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Radix Sort")) {
            clock_t start, end;
            start = clock();
            radixSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
        if (!strcmp(algorithm, "Flash Sort")) {
            clock_t start, end;
            start = clock();
            flashSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;
            return;
        }
    }
    if (!strcmp(parameters, "-comp")) {
        if (!strcmp(algorithm, "Selection Sort")) {
            selectionSort(arr, n, comp);
            return;
        }
        if (!strcmp(algorithm, "Insertion Sort")) {
            insertionSort(arr, n, comp);
            return;
        }
        if (!strcmp(algorithm, "Bubble Sort")) {
            bubbleSort(arr, n, comp);
            return;
        }
        if (!strcmp(algorithm, "Shaker Sort")) {
            shakerSort(arr, n, comp);
            return;
        }
        if (!strcmp(algorithm, "Shell Sort")) {
            shellSort(arr, n, comp);
            return;
        }
        if (!strcmp(algorithm, "Heap Sort")) {
            heapSort(arr, n, comp);
            return;
        }
        if (!strcmp(algorithm, "Merge Sort")) {
            mergeSort(arr, 0, n - 1, comp);
            return;
        }
        if (!strcmp(algorithm, "Quick Sort")) {
            quickSort(arr, 0, n - 1, comp);
            return;
        }
        if (!strcmp(algorithm, "Counting Sort")) {
            countingSort(arr, n, comp);
            return;
        }
        if (!strcmp(algorithm, "Radix Sort")) {
            radixSort(arr, n, comp);
            return;
        }
        if (!strcmp(algorithm, "Flash Sort")) {
            flashSort(arr, n, comp);
            return;
        }
    }
    else {
        if (!strcmp(algorithm, "Selection Sort")) {

            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            selectionSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            selectionSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Insertion Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            insertionSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            insertionSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Bubble Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            bubbleSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            bubbleSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Shaker Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            shakerSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            shakerSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Shell Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            shellSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            shellSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Heap Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            heapSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            heapSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Merge Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            mergeSort(tmp, 0, n - 1, comp);

            clock_t start, end;
            start = clock();
            mergeSort(arr, 0, n - 1);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Quick Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            quickSort(tmp, 0, n - 1, comp);

            clock_t start, end;
            start = clock();
            quickSort(arr, 0, n - 1);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Counting Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            countingSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            countingSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Radix Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            radixSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            radixSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
        if (!strcmp(algorithm, "Flash Sort")) {
            int* tmp = new int[n + 1];
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];

            flashSort(tmp, n, comp);

            clock_t start, end;
            start = clock();
            flashSort(arr, n);
            end = clock();
            time = ((double)end - (double)start) / CLOCKS_PER_SEC;

            delete[] tmp;

            return;
        }
    }
}

int main(int argc, char** argv)
{
    if (argc != 5 && argc != 6) { cout << "Wrong Syntax!"; return 0; }

    double time;
    long long comp;

    if (!strcmp(argv[1], "-a")) {
        if (argc == 6) {

            if (!exist_algorithm(argv[2])) { cout << "Wrong syntax at [Algorithm]"; return 0; }
            if (!isNum(argv[3])) { cout << "Wrong syntax at [Input size]"; return 0; }
            int input_size = convert_to_int(argv[3]);
            if (input_size > MAX_SIZE) { cout << "[Input size] is out of range!"; return 0; }
            if (!exist_input_order(argv[4])) { cout << "Wrong syntax at [Input order]"; return 0; }
            if (!exist_output_parameters(argv[5])) { cout << "Wrong syntax at [Output parameter(s)]"; return 0; }

            int* arr = new int[input_size + 1];
            Generate(arr, input_size, argv[4]);

            cout << "ALGORITHM MODE\n";
            cout << "Algorithm: " << argv[2] << '\n';
            cout << "Input size: " << input_size << '\n';
            char* order = convert_to_normal_English(argv[4]);
            cout << "Input order: " << order << '\n';
            delete[] order; // Not sure
            cout << "-------------------------\n";
            calculate_parameters(argv[2], arr, input_size, argv[5], time, comp);
            print_parameters(argv[5], time, comp);
            cout << "\n\n";

            delete[] arr;
            return 0;
        }
        if (argc == 5) {
            if (isNum(argv[3])) { // 70000

                int input_size = convert_to_int(argv[3]);

                if (input_size > MAX_SIZE) { cout << "[Input size] is out of range!"; return 0; }
                if (!exist_algorithm(argv[2])) { cout << "Wrong syntax at [Algorithm]"; return 0; }
                if (!exist_output_parameters(argv[4])) { cout << "Wrong syntax at [Output parameter(s)]"; return 0; }

                cout << "ALGORITHM MODE\n";
                cout << "Algorithm: " << argv[2] << '\n';
                cout << "Input size: " << input_size << "\n\n";

                cout << "Input order: Randomize\n";
                cout << "-------------------------\n";

                int* arr = new int[input_size + 1];
                char order1[] = "-rand";
                Generate(arr, input_size, order1);
                calculate_parameters(argv[2], arr, input_size, argv[4], time, comp);
                print_parameters(argv[4], time, comp);

                cout << "\n";

                cout << "Input order: Nearly Sorted\n";
                cout << "-------------------------\n";

                char order2[] = "-nsorted";
                Generate(arr, input_size, order2);
                calculate_parameters(argv[2], arr, input_size, argv[4], time, comp);
                print_parameters(argv[4], time, comp);

                cout << "\n";

                cout << "Input order: Sorted\n";
                cout << "-------------------------\n";

                char order3[] = "-sorted";
                Generate(arr, input_size, order3);
                calculate_parameters(argv[2], arr, input_size, argv[4], time, comp);
                print_parameters(argv[4], time, comp);

                cout << "\n";

                cout << "Input order: Reversed\n";
                cout << "-------------------------\n";

                char order4[] = "-rev";
                Generate(arr, input_size, order4);
                calculate_parameters(argv[2], arr, input_size, argv[4], time, comp);
                print_parameters(argv[4], time, comp);

                cout << "\n";

                delete[] arr;
                return 0;
            }

            if (!exist_algorithm(argv[2])) { cout << "Wrong syntax at [Algorithm]"; return 0; }
            if (!exist_output_parameters(argv[4])) { cout << "Wrong syntax at [Output parameter(s)]"; return 0; }

            ifstream ifs(argv[3]);

            if (!ifs.is_open()) {
                cout << "Can't open the file!";
                ifs.close();
                return 0;
            }

            int n;
            ifs >> n;
            int* arr = new int[n + 1];
            for (int i = 0; i < n; ++i) ifs >> arr[i];

            ifs.close();

            cout << "ALGORITHM MODE\n";
            cout << "Algorithm: " << argv[2] << '\n';
            cout << "Input file: " << argv[3] << '\n';
            cout << "Input size: " << n << '\n';
            cout << "-------------------------\n";

            calculate_parameters(argv[2], arr, n, argv[4], time, comp);
            print_parameters(argv[4], time, comp);

            cout << "\n\n";

            delete[] arr;
            return 0;
        }

        return 0;
    }
    if (!strcmp(argv[1], "-c")) {
        if (argc == 6) {

            if (!exist_algorithm(argv[2])) { cout << "Wrong syntax at [Algorithm 1]"; return 0; }
            if (!exist_algorithm(argv[3])) { cout << "Wrong syntax at [Algorithm 2]"; return 0; }
            if (!isNum(argv[4])) { cout << "Wrong syntax at [Input size]"; return 0; }
            int input_size = convert_to_int(argv[4]);
            if (input_size > MAX_SIZE) { cout << "[Input size] is out of range!"; return 0; }
            if (!exist_input_order(argv[5])) { cout << "Wrong syntax at [Input order]"; return 0; }

            // Generate array
            int* arr = new int[input_size + 1];
            Generate(arr, input_size, argv[5]);

            cout << "COMPARE MODE\n";
            cout << "Algorithm: " << argv[2] << " | " << argv[3] << '\n';
            cout << "Input size: " << input_size << '\n';
            char* order = convert_to_normal_English(argv[5]);
            cout << "Input order: " << order << '\n';
            delete[] order; // Not sure
            cout << "-------------------------\n";

            // count time and comparisons of 2 algorithms
            int* tmp = new int[input_size + 1];
            int* tmp1 = new int[input_size + 1];
            int* tmp2 = new int[input_size + 1];
            for (int i = 0; i < input_size; ++i) {
                tmp[i] = arr[i];
                tmp1[i] = arr[i];
                tmp2[i] = arr[i];
            }

            char* time_ = new char[6];
            time_[0] = '-';
            time_[1] = 't';
            time_[2] = 'i';
            time_[3] = 'm';
            time_[4] = 'e';
            time_[5] = '\0';
            char* comp_ = new char[6];
            comp_[0] = '-';
            comp_[1] = 'c';
            comp_[2] = 'o';
            comp_[3] = 'm';
            comp_[4] = 'p';
            comp_[5] = '\0';

            calculate_parameters(argv[2], tmp, input_size, time_, time, comp);

            cout << "Running time: " << time << " | ";

            calculate_parameters(argv[3], tmp1, input_size, time_, time, comp);

            cout << time << '\n';

            calculate_parameters(argv[2], tmp, input_size, comp_, time, comp);

            cout << "Comparisons: " << comp << " | ";

            calculate_parameters(argv[3], tmp, input_size, comp_, time, comp);

            cout << comp << "\n";

            delete[] arr;
            delete[] tmp;
            delete[] tmp1;
            delete[] tmp2;
            delete[] time_;
            delete[] comp_;
            return 0;
        }
        if (argc == 5) {

            if (!exist_algorithm(argv[2])) { cout << "Wrong syntax at [Algorithm 1]"; return 0; }
            if (!exist_algorithm(argv[3])) { cout << "Wrong syntax at [Algorithm 2]"; return 0; }

            ifstream ifs(argv[4]);

            if (!ifs.is_open()) {
                cout << "Can't open " << argv[4] << " file";
                ifs.close();
                return 0;
            }

            int n;
            ifs >> n;
            int* arr = new int[n + 1];
            for (int i = 0; i < n; ++i) ifs >> arr[i];

            ifs.close();

            cout << "COMPARE MODE\n";
            cout << "Algorithm: " << argv[2] << " | " << argv[3] << '\n';
            cout << "Input file: " << argv[4] << '\n';
            cout << "Input size: " << n << '\n';
            cout << "-------------------------\n";

            // count time and comparisons of 2 algorithms
            int* tmp = new int[n + 1];
            int* tmp1 = new int[n + 1];
            int* tmp2 = new int[n + 1];
            for (int i = 0; i < n; ++i) {
                tmp[i] = arr[i];
                tmp1[i] = arr[i];
                tmp2[i] = arr[i];
            }

            char* time_ = new char[6];
            time_[0] = '-';
            time_[1] = 't';
            time_[2] = 'i';
            time_[3] = 'm';
            time_[4] = 'e';
            time_[5] = '\0';
            char* comp_ = new char[6];
            comp_[0] = '-';
            comp_[1] = 'c';
            comp_[2] = 'o';
            comp_[3] = 'm';
            comp_[4] = 'p';
            comp_[5] = '\0';

            calculate_parameters(argv[2], tmp, n, time_, time, comp);

            cout << "Running time: " << time << " | ";

            calculate_parameters(argv[3], tmp1, n, time_, time, comp);

            cout << time << '\n';

            calculate_parameters(argv[2], tmp, n, comp_, time, comp);

            cout << "Comparisons: " << comp << " | ";

            calculate_parameters(argv[3], tmp, n, comp_, time, comp);

            cout << comp << "\n";

            delete[] arr;
            delete[] tmp;
            delete[] tmp1;
            delete[] tmp2;
            delete[] time_;
            delete[] comp_;
            return 0;
        }

        return 0;
    }
    else cout << "Wrong syntax at [Mode]";

    return 0;
}