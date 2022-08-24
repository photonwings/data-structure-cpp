/*
  Linear Search:
  Time complexity - O(n)
*/
#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int k)
{
    for (int i = 0; i < n; i++) {
        // Checking if the current element is the key element
        if (a[i] == k) {
            return i + 1;
        }
    }
    return -1;
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
    cout << linearSearch(a, n, k) << endl;
    return 0;
}