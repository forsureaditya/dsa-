#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Row Major Order
    cout << "Row Major Order:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
    }

    cout << endl << endl;

    // Column Major Order
    cout << "Column Major Order:" << endl;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            cout << a[i][j] << " ";
        }
    }

    cout << endl << endl;

    // Upper Triangular - Row Major
    cout << "Upper Triangular Matrix - Row Major:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i <= j) {
                cout << a[i][j] << " ";
            }
        }
    }

    cout << endl << endl;

    // Upper Triangular - Column Major
    cout << "Upper Triangular Matrix - Column Major:" << endl;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {

            if (i <= j) {
                cout << a[i][j] << " ";
            }
        }
    }

    cout << endl;

    return 0;
}