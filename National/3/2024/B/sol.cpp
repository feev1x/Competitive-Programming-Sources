/**
 *    author:  feev1x
 *    created: 10.03.2025 14:04:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    std::vector<int64_t> cnt(10);

    int64_t res = 0;
    for (int i = 0; i < s.size(); ++i) {
        int dig = s[i] - '0';

        for (int j = 0; j < dig; ++j) {
            res += cnt[j] * (dig - j);
        }

        cnt[s[i] - '0']++;
    }

    std::cout << res << '\n';
    return 0;
}
