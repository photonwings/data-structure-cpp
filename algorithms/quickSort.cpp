#include <iostream>
#include <utility>
using namespace std;

int partition(int a[], int low, int high)
{
    int i, j, pivot;
    i = low;
    j = high;
    pivot = a[low];

    // Stop looping when i becomes less than j
    while (i < j) {
        // Stop incrementing i when an element which is greater than piovt is found
        while (a[i] <= pivot && i <= high - 1) {
            i++;
        }
        // Stop decrementign j when an element which is less than pivot is found
        while (a[j] > pivot && j >= low) {
            j--;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    // Swap pivot with the jth element
    swap(a[j], a[low]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        // Partition the array
        int pivot = partition(arr, low, high);
        // Call quickSort on left side
        quickSort(arr, low, pivot - 1);
        // Call quickSort on right side
        quickSort(arr, pivot + 1, high);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements to array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Entered elements are: ";
    printArray(a, n);
    cout << endl;

    quickSort(a, 0, n - 1);

    cout << "Array after quick sorting: ";
    printArray(a, n);
    cout << endl;
    return 0;
}