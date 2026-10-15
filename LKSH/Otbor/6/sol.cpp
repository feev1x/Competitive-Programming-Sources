#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s; std::cin >> s;
    int n = s.size();
    s = " " + s;
    std::vector<std::vector<int>> p(n + 1, std::vector<int>(26)), pos(26);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1];
        p[i][s[i] - 'a']++;
        pos[s[i] - 'a'].emplace_back(i);
    }
    auto Get = [&](auto &&self, int l, int r) -> void {
        for (int i = 0; i < 26; ++i) if (p[r][i] - p[l - 1][i]) {
            int ps = *--std::upper_bound(pos[i].begin(), pos[i].end(), r);
            std::cout << char(i + 'a');
            self(self, l, ps - 1);
            self(self, ps + 1, r);
            return;
        }
    }; Get(Get, 1, n);
    return 0;
}
