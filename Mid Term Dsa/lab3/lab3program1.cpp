#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int arr[n][m];

    // First matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int p;
    cin >> p;

    int brr[n][m];

    // Second matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> brr[i][j];
        }
    }

    // Triplet representation of first matrix
    vector<vector<int>> a;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (arr[i][j] != 0) {
                a.push_back({i, j, arr[i][j]});
                cnt++;
            }
        }
    }

    // Insert header
    a.insert(a.begin(), {n, m, cnt});


    // Triplet representation of second matrix
    vector<vector<int>> b;

    int cnt2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (brr[i][j] != 0) {
                b.push_back({i, j, brr[i][j]});
                cnt2++;
            }
        }
    }

    // Insert header
    b.insert(b.begin(), {n, m, cnt2});


    // Resultant sparse matrix
    vector<vector<int>> c;

    int i = 1;
    int j = 1;

    while (i < a.size() && j < b.size()) {

        // Same row and same column
        if (a[i][0] == b[j][0] &&
            a[i][1] == b[j][1]) {

            c.push_back({
                a[i][0],
                a[i][1],
                a[i][2] + b[j][2]
            });

            i++;
            j++;
        }

        // First matrix element comes first
        else if (a[i][0] < b[j][0] ||
                (a[i][0] == b[j][0] &&
                 a[i][1] < b[j][1])) {

            c.push_back(a[i]);

            i++;
        }

        // Second matrix element comes first
        else {

            c.push_back(b[j]);

            j++;
        }
    }

    // Remaining elements of first matrix
    while (i < a.size()) {
        c.push_back(a[i]);
        i++;
    }

    // Remaining elements of second matrix
    while (j < b.size()) {
        c.push_back(b[j]);
        j++;
    }


    // Sort resultant triplet
    sort(c.begin(), c.end());


    // Fast transpose
    for (auto &it : c) {
        swap(it[0], it[1]);
    }

    // Sort after transpose
    sort(c.begin(), c.end());


    // Display resultant triplet
    cout << "Triplet representation after fast transpose:" << endl;

    for (auto it : c) {
        cout << it[0] << " "
             << it[1] << " "
             << it[2] << endl;
    }

    return 0;
}