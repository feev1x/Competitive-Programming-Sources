#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::map<std::string, int64_t> mp;
    for (int i = 0; i < n; ++i) {
        std::string s; std::cin >> s;
        int64_t u; std::cin >> u;


        mp[s] = u;
    }

    int q; std::cin >> q;

    int64_t res = 0;
    while (q--) {
        std::string s; std::cin >> s;

        res += mp[s];
    }

    std::cout << res << '\n';
    return 0;
}
