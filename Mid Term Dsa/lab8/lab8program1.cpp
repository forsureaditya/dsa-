#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;

    cout << "Enter a postfix expression: ";
    cin >> str;

    stack<int> st;

    for (int i = 0; i < str.size(); i++) {

        if (isdigit(str[i])) {

            int x = 0;

            while (i < str.size() && isdigit(str[i])) {

                x = x * 10 + (str[i] - '0');
                i++;
            }

            i--;

            st.push(x);
        }

        else {

            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (str[i] == '+') {
                st.push(b + a);
            }

            else if (str[i] == '-') {
                st.push(b - a);
            }

            else if (str[i] == '*') {
                st.push(b * a);
            }

            else if (str[i] == '/') {
                st.push(b / a);
            }
        }
    }

    cout << "Answer = " << st.top() << endl;

    return 0;
}