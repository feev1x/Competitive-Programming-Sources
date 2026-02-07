#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<std::string> s(n);
    std::map<std::pair<int, int>, int> mp;
    for (auto &u: s) {
        std::cin >> u;

        int pos = -1;
        for (int i = 0; i < u.size(); ++i) {
            if ('A' <= u[i] && u[i] <= 'Z') {
                pos = i;
                break;
            }
        }

        mp[{pos + 1, u.size()}]++;
    }

    std::string t;
    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::string ss; std::cin >> ss;

        t += ss;
    }

    std::vector<int> pos;
    for (int i = 0; i < t.size(); ++i) {
        if ('A' <= t[i] && t[i] <= 'Z') {
            pos.emplace_back(i + 1);
        }
    }

    n = t.size();
    std::vector<int> dp(n + 1);

    std::vector<std::vector<std::pair<int, int>>> vec(n + 1);
    for (auto [key, val]: mp) {
        auto [x, y] = key;

        if (y > n) {
            continue;
        }

        vec[x].emplace_back(y, val);
    }


    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int ps = std::upper_bound(pos.begin(), pos.end(), i) - pos.begin();

        if (ps == pos.size()) {
            break;
        }
        
        int nx = (ps + 1 == pos.size() ? n + 1 : pos[ps + 1]) - i, nw = pos[ps] - i;

        for (int j = 0; j < vec[nw].size() && vec[nw][j].first < nx; ++j) {
            add_self(dp[i + vec[nw][j].first], mul(dp[i], vec[nw][j].second));
        }
    }

    std::cout << dp[n] << '\n';
    return 0;
}
