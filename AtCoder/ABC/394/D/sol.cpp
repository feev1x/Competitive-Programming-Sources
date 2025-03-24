/**
 *    author:  feev1x
 *    created: 06.03.2025 16:10:47
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    std::stack<char> stk;
    bool flag = true;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<') {
            stk.emplace(s[i]);
        } else {
            if (stk.empty() || !(
                stk.top() == '(' && s[i] == ')' ||
                stk.top() == '[' && s[i] == ']' ||
                stk.top() == '<' && s[i] == '>')) {
                flag = false;

                break;
            } else {
                stk.pop();
            }
        }
    }

    if (stk.size()) {
        flag = false;
    }

    std::cout << (flag ? "Yes\n" : "No\n");
    return 0;
}
