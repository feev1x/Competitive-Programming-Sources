#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::string s; std::cin >> s;
    std::vector<int> pos;

    int ca = std::count(s.begin(), s.end(), 'a'), cb = n - ca;

    if (ca == cb) {
        std::cout << "0\n";
        return;
    }

    if (ca < cb) {
        std::swap(ca, cb);

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                s[i] = 'b';
            } else {
                s[i] = 'a';
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            pos.emplace_back(i);
        }
    }

    int m = pos.size();

    std::map<int, int> mp;
    std::vector<int> p(m + 1);
    for (int i = 0; i < m; ++i) {
        p[i + 1] = p[i] + 1 - (i ? (pos[i] - pos[i - 1] - 1) : pos[i]);
    }

    int res = n;
    for (int i = m; i > 0; --i) {
        int val = (ca - cb) + p[i] - 1;

//        std::cout << "{" << val << ", " << p[i] << "}" << " \n"[i == 1];

        mp[p[i]] = i;
        if (mp.count(val)) {
            res = std::min(res, pos[mp[val] - 1] - pos[i - 1] + 1);
        }
    }

    if (res == n) {
        res = -1;
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
