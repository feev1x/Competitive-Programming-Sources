/**
 *    author:  feev1x
 *    created: 26.07.2025 18:03:24
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int n = s.size();
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.' && flag)
            s[i] = 'o', flag = false;
        else if (s[i] == '#')
            flag = true;
    }

    std::cout << s << '\n';
    return 0;
}
