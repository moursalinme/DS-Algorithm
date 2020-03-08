#include <bits/stdc++.h>
using namespace std;

void add(stack<char> &s, string &ans) {
    while(s.top() != '(') {
        ans += s.top();
        s.pop();
    }
}

int main() {
    stack <char> ms;
    string ans, s;
    cout << "Enter infix expression without space in between characters : " << endl;
    cin >> s;
    int sz = s.size(), i = 0;
    ms.push('(');
    while(i < sz) {
        if(s[i] == ')' || s[i] == '(') {
            if(s[i] == '(') 
                ms.push(s[i]);
            else {
                add(ms, ans);
                ms.pop();
            }
        }
        else if(s[i] == '+' || s[i] == '-') {
            if(ms.top() == '*' || ms.top() == '^' || ms.top() == '/') 
                add(ms, ans);
            ms.push(s[i]);
        }
        else if(s[i] == '/' || s[i] == '*') {
            if(ms.top() == '^') 
                add(ms, ans);
            ms.push(s[i]);
        } 
        else if(s[i] == '^') 
            ms.push(s[i]);
        else 
            ans += s[i];
        ++i;
    }
    while(!ms.empty()) {
        if(ms.top() == '(') {
            ms.pop(); continue;
        } else {
            ans += ms.top(); ms.pop();
        }

    }
    cout << "Postfix expression is : " << ans << endl;
    return 0;
}
