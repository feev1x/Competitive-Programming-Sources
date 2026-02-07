#include <bits/stdc++.h>

inline void solve() {
    std::string s, t; std::cin >> s >> t;

    std::vector<int> cs(26), ct(26);
    for (int i = 0; i < s.size(); ++i) {
        cs[s[i] - 'a']++;
    }

    for (int i = 0; i < t.size(); ++i) {
        ct[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (cs[i] > ct[i]) {
            std::cout << "Impossible\n";
            return;
        }
    }

    std::string res;
    for (int i = 0, j = 0; i < 26; ++i) {
        int c = ct[i] - cs[i];

bck:;
        if (j == s.size() || i + 'a' < s[j]) {
            while (c--) {
                res += char(i + 'a');
            }
        } else {
            res += s[j++];
            goto bck;
        }
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
