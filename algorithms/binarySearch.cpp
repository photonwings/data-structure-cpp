/*
  Binary Search:
  Time complexity - O(log(n))
*/
#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int k)
{
    int start, mid, end;
    start = 0;
    end = n - 1;

    // Stop the loop when start becomes greater than end
    while (start <= end) {
        mid = (start + end) / 2;
        // Check if the mid element is the key element
        if (a[mid] == k) {
            return mid + 1;
        } else if (k > a[mid]) {
            // Move start if key element is present in second half
            start = mid + 1;
            // Move end if key element is present in first half
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursion(int a[], int k, int start, int end)
{
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (a[mid] == k) {
        return mid + 1;
    } else if (k > a[mid]) {
        return binarySearchRecursion(a, k, mid + 1, end);
    } else {
        return binarySearchRecursion(a, k, start, mid - 1);
    }
}

int main()
{
    int n, k;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements to array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter key element to search: ";
    cin >> k;
    // cout << binarySearch(a, n, k) << endl;
    cout << binarySearchRecursion(a, k, 0, n - 1) << endl;
    return 0;
}