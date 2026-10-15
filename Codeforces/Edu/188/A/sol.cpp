#include <bits/stdc++.h>

inline void solve() {
    int n, res = 1; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<bool> used(n);
    used[0] = true;
    for (int i = 0, j = 0; i < n; ++i) {
        if (s[j] == 'L') j--;
        else j++;
        res += !used[j];
        used[j] = true;
    }
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
