// ---------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #5 - Sorting Analysis
// Date due: 10/08/2025
// Description: Sort identical arrays of random numbers using bubble, selection,
// and insertion sort, and print out how many comparisons occurred.
// ---------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <utility>

using namespace std;

int bubbleSort(int arr[], int size);
int selectionSort(int arr[], int size);
int insertionSort(int arr[], int size);
int mergeSort(int arr[], int left, int right);
int merge(int arr[], int left, int middle, int right);

int main()
{
    const int SIZE = 5000;

    int list1[SIZE]; // bubble sort
    int list2[SIZE]; // selection sort
    int list3[SIZE]; // insertion sort
    int list4[SIZE]; // merge sort

    // number of comparisons for each sorting algorithm
    int bubbleComps = 0;
    int selectionComps = 0;
    int insertionComps = 0;
    int mergeComps = 0;

    // random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 50000);

    // assign values to first array, then copy the same value to other arrays
    for (int i = 0; i < SIZE; i++)
    {
        list1[i] = distrib(gen);
        list2[i] = list1[i];
        list3[i] = list1[i];
        list4[i] = list1[i];
    }

    // run search algorithms, get num of comparisons for each
    bubbleComps = bubbleSort(list1, SIZE);
    selectionComps = selectionSort(list2, SIZE);
    insertionComps = insertionSort(list3, SIZE);
    mergeComps = mergeSort(list4, 0, SIZE);

    // print each algorithm's number of comparisons
    cout << "Bubble sort comparisons:\t" << bubbleComps << endl;
    cout << "Selection sort comparisons:\t" << selectionComps << endl;
    cout << "Insertion sort comparisons:\t" << insertionComps << endl;
    cout << "Merge sort comparisons:\t\t" << mergeComps << endl;


    return 0;
}

//---------------------------------------------------------------------------
/* bubbleSort() sorts the values stored in an array using a bubble sort
* algorithm, repeatedly swapping adjacent elements if in the wrong order.
* INCOMING DATA: 2 ints, an array of random numbers, and the size of the array
* OUTGOING DATA: 1 int for the total number of comparisons done while sorting
* the array, and the sorted array itself.
*/
int bubbleSort(int arr[], int size)
{
    int comparisons = 0;
    bool flag;

    for (int i = 0; i < size - 1; i++)
    {
        flag = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }

        if (!flag) // array is in order early, short-circuit outer loop
        {
            break;
        }
    }

    return comparisons;
}

//---------------------------------------------------------------------------
/* selectionSort() sorts an array using the selection sort algorithm, which
* repeatedly finds the minimum element and putting it at the beginning of the
* array.
* INCOMING DATA: 2 ints, an array of random numbers, and the size of the array
* OUTGOING DATA: 1 int for the total number of comparisons done while sorting
* the array, and the sorted array itself.
*/
int selectionSort(int arr[], int size)
{
    int comparisons = 0;
    int min_idx = 0;

    for (int i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
            swap(arr[min_idx], arr[i]);
        }
    }

    return comparisons;
}

//---------------------------------------------------------------------------
/* insertionSort() uses the insertion sort algorithm to sort an array by
* inserting each element of an unsorted array into its correct position in a
* sorted portion of the array.
* INCOMING DATA: 2 ints, an array of random numbers, and the size of the array
* OUTGOING DATA: An int for the total number of comparisons done while sorting
* the array, and the sorted array itself.
*/
int insertionSort(int arr[], int size)
{
    int comparisons = 0;
    int key;
    int j;

    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0)
        {
            comparisons++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }

    return comparisons;
}

//---------------------------------------------------------------------------
/* mergeSort() recursively divides the array into halves, sorts each half, then
* merges the array back together.
* INCOMING DATA: 3 ints, the array of random numbers to be sorted, the first
* index of the array, and the last index of the array.
* OUTGOING DATA: 1 int for the total number of comparisons done while sorting
* the array, and the sorted array itself.
*/
int mergeSort(int arr[], int left, int right)
{
    int comparisons = 0;
    int middle;

    if (left < right)
    {
        middle = left + (right - left) / 2;
        comparisons += mergeSort(arr, left, middle);
        comparisons += mergeSort(arr, middle + 1, right);
        comparisons += merge(arr, left, middle, right);
    }

    return comparisons;
}

//---------------------------------------------------------------------------
/* merge() merges the sub-arrays back together in order.
* INCOMING DATA: 4 ints - the array to be merged and 3 indexes for merging the
* array together.
* OUTGOING DATA: 1 int - the number of comparisons done while merging the
* array together, and the merged array itself.
*/
int merge(int arr[], int left, int middle, int right)
{
    int comparisons = 0;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // temp arrays
    int tempL[n1], tempR[n2];

    int k = 0;
    int l = 0;
    int m = left;

    for (int i = 0; i < n1; i++)
    {
        tempL[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        tempR[j] = arr[middle + 1 + j];
    }

    while (k < n1 && l < n2)
    {
        comparisons++;
        if (tempL[k] <= tempR[l])
        {
            arr[m] = tempL[k];
            k++;
        }
        else
        {
            arr[m] = tempR[l];
            l++;
        }
        m++;
    }

    while (k < n1)
    {
        arr[m] = tempL[k];
        k++;
        m++;
    }

    while (l < n2)
    {
        arr[m] = tempR[l];
        l++;
        m++;
    }

    return comparisons;
}
