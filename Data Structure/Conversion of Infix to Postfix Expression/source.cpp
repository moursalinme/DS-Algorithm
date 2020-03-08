#include <bits/stdc++.h> 
using namespace std;

void print(stack<char> &s, string &ans) {
    while(s.top() != '(') {
	ans += s.top();
	s.pop();
    }
}

int main() {
    stack <char> ms;
    string ans, s;
    cin >> s;
    int i = 0, sz = s.size();
    ms.push('(');
    while(i < sz) {
	if(s[i] == ')' || s[i] == '(') {
	    if(s[i] == '(') 
		ms.push(s[i]);
	    else {
		print(ms, ans);
		ms.pop();
	    }
	}
	else if(s[i] == '+' || s[i] == '-') {
	    if(ms.top() == '*' || ms.top() == '^' || ms.top() == '/') 
	        print(ms, ans);
	    ms.push(s[i]);
	}
	else if(s[i] == '/' || s[i] == '*') {
	    if(ms.top() == '^') 
		print(ms, ans);
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
    cout << ans << endl;
    return 0;
}
