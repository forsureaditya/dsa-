#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n;

    vector<int> arr1(n);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;

    vector<int> arr2(m);

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    map<int, int> mpp;

    // Store elements of first array
    for (int i = 0; i < n; i++) {
        mpp[arr1[i]]++;
    }

    // Store elements of second array
    for (int i = 0; i < m; i++) {
        mpp[arr2[i]]++;
    }

    // Union
    cout << "Printing the union:" << endl;

    for (auto it : mpp) {
        cout << it.first << " ";
    }

    cout << endl;

    // Intersection
    cout << "Printing the intersection:" << endl;

    for (auto it : mpp) {
        if (it.second >= 2) {
            cout << it.first << " ";
        }
    }

    cout << endl;

    return 0;
}