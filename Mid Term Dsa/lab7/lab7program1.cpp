#include <bits/stdc++.h>
using namespace std;

int p(char c) {

    if (c == '^')
        return 3;

    if (c == '*' || c == '/')
        return 2;

    if (c == '+' || c == '-')
        return 1;

    return 0;
}

int main() {

    string s, ans = "";

    stack<char> st;

    cout << "Enter infix expression: ";
    cin >> s;

    for (char c : s) {

        if (isalnum(c)) {
            ans += c;
        }

        else if (c == '(') {
            st.push(c);
        }

        else if (c == ')') {

            while (!st.empty() && st.top() != '(') {

                ans += st.top();
                st.pop();
            }

            st.pop();
        }

        else {

            while (!st.empty() &&
                   st.top() != '(' &&
                   (p(st.top()) > p(c) ||
                   (p(st.top()) == p(c) && c != '^'))) {

                ans += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while (!st.empty()) {

        ans += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << ans << endl;

    return 0;
}