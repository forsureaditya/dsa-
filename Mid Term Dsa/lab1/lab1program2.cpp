#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int a, b;
    cin >> a >> b;

    // Matrix multiplication condition
    if (n != a) {
        cout << "Matrix multiplication not possible" << endl;
    }
    else {
        vector<vector<int>> mat1(m, vector<int>(n));
        vector<vector<int>> mat2(a, vector<int>(b));
        vector<vector<int>> ans(m, vector<int>(b));

        // Input first matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat1[i][j];
            }
        }

        // Input second matrix
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cin >> mat2[i][j];
            }
        }

        // Matrix multiplication
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < b; j++) {

                int sum = 0;

                for (int k = 0; k < n; k++) {
                    sum += mat1[i][k] * mat2[k][j];
                }

                ans[i][j] = sum;
            }
        }

        // Print result
        cout << "Resultant Matrix:" << endl;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < b; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}