#include <bits/stdc++.h>

inline void solve() {
    std::string s; std::cin >> s;

    int n = s.size();
    
    int l = -1, res = 0;

    std::vector<std::pair<int, int>> comp;
    for (int i = 0; i < n;) {
        if (s[i] == 'I' || i + 2 >= n || s[i + 1] != 'I') {
            i++;
            continue;
        }

        if (s[i + 2] == 'I') {
            i = i + 3;
            continue;
        }

        int m = 0, t = 0, j;
        for (j = i; j < n && s[j] != 'I' && (j == i || s[j - 1] == 'I'); j += 2) {
            if (s[j] == 'M') {
                m++;
            } else {
                t++;
            }
        }

        i = j - 1;

        res += std::min(m, t / 2);
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
