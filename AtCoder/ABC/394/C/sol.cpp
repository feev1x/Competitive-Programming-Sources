/**
 *    author:  feev1x
 *    created: 06.03.2025 16:04:26
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    std::string res;

    char ls = '-';
    for (int i = s.size() - 1; i >= 0; --i) {
        if ((ls == 'A' || ls == 'W' && res.back() == 'A') && s[i] == 'W') {
            res.pop_back();

            res += "CA";
        } else {
            res += s[i];
        }

        ls = s[i];
    }

    std::reverse(res.begin(), res.end());

    std::cout << res << '\n';
    return 0;
}
