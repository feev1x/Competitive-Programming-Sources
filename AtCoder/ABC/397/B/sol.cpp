/**
 *    author:  feev1x
 *    created: 15.03.2025 18:04:04
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int cnt = 0;
    bool ls = true;
    for (int i = 0; i < s.size(); ++i) {
        if (ls != (s[i] == 'i')) {
            cnt++;

            ls = !ls;
        }

        ls = !ls;
    }

    cnt += s.back() == 'i';

    std::cout << cnt << '\n';
    return 0;
}
