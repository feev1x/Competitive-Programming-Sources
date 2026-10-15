#include <bits/stdc++.h>

inline void solve() {
    std::string s; std::cin >> s;

    int sum = 0, fr = s[0] - '0';
    for (int i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
    }

    int cnt = 0;
    std::sort(s.begin(), s.end(), std::greater<>());
    for (int i = 0; sum > 9 && i < s.size(); ++i) {
        int x = s[i] - '0';

        if (x == fr && (i + 1 == s.size() || s[i + 1] - '0' != x)) {
            sum -= x - 1;
        } else {
            sum -= x;
        }

        cnt++;
    }

    std::cout << cnt << '\n';
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
