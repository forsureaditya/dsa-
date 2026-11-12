#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int refSum = 0;

    // Reference sum = first row
    for (int j = 0; j < n; j++) {
        refSum += a[0][j];
    }

    int count = 0;

    // Check rows
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }

        if (sum == refSum)
            count++;
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i][j];
        }

        if (sum == refSum)
            count++;
    }

    // Main diagonal
    int sum1 = 0;

    for (int i = 0; i < n; i++) {
        sum1 += a[i][i];
    }

    if (sum1 == refSum)
        count++;

    // Secondary diagonal
    int sum2 = 0;

    for (int i = 0; i < n; i++) {
        sum2 += a[i][n - 1 - i];
    }

    if (sum2 == refSum)
        count++;

    if (count == 2 * n + 2) {
        cout << "The given square is a magic square";
    }
    else {
        cout << "The given square is not a magic square";
    }

    return 0;
}