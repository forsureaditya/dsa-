#include <bits/stdc++.h>
using namespace std;

int comparisons = 0;
int swaps = 0;

int partitionArray(int arr[], int low, int high) {

    int pivot = arr[low];

    int i = low;
    int j = high;

    while (i <= j) {

        while (i <= high) {

            comparisons++;

            if (arr[i] > pivot)
                break;

            i++;
        }

        while (j >= low) {

            comparisons++;

            if (arr[j] <= pivot)
                break;

            j--;
        }

        if (i < j) {

            swap(arr[i], arr[j]);
            swaps++;

            i++;
            j--;
        }
    }

    swap(arr[low], arr[j]);
    swaps++;

    return j;
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {

        int p = partitionArray(arr, low, high);

        quickSort(arr, low, p - 1);

        quickSort(arr, p + 1, high);
    }
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Comparisons = " << comparisons << endl;

    cout << "Swaps = " << swaps << endl;

    return 0;
}