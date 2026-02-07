#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::string s; std::cin >> s;

    std::vector<int> prev(n, -1), next(n, n);
    std::vector<std::array<int, 26>> p(n + 1);
    for (int i = 1; i < n; ++i) {
        prev[i] = (s[i] == s[i - 1] ? prev[i - 1] : i - 1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            p[i + 1][j] = p[i][j];
        }

        p[i + 1][s[i] - 'a']++;
    }

    for (int i = n - 2; i >= 0; --i) {
        next[i] = (s[i] == s[i + 1] ? next[i + 1] : i + 1);
    }

    
    auto Get = [&](auto &&self, int l, int r) -> int {
        if (l > r) {
            return 0;
        }

        int cnt = 0;

        std::vector<bool> odd(26);
        for (int j = 0; j < 26; ++j) {
            odd[j] = (p[r + 1][j] - p[l][j]) & 1;

            cnt += odd[j];
        }

        if (cnt > 1) {
            return r - l + 1;
        }

        if (cnt == 1) {
            if (!odd[s[l] - 'a'] || !odd[s[r] - 'a']) {
                return r - l;
            }

            assert(s[l] == s[r]);

            return std::max(self(self, l, prev[r]), self(self, next[l], r));
        }

        if (s[l] != s[r]) {
            return r - l - 1;
        }

        return std::max(self(self, l, r - 1), self(self, l + 1, r));
    };

    int q; std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;

        std::cout << Get(Get, l - 1, r - 1) << std::endl;
    }
    return 0;
}
