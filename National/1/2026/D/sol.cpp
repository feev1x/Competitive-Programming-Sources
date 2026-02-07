#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<std::string> s(n + 1);
    for (auto &u: s) {
        std::cin >> u;
    }

    std::vector<int> bi, bj;
    for (int i = 0; i <= n; ++i) {
        bool nw = false;

        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '1') {
                nw = !nw;
            }
        }

        if (nw != s[i][n] - '0') {
            bi.emplace_back(i);
        }
    }

    for (int j = 0; j < n; ++j) {
        bool nw = false;

        for (int i = 0; i < n; ++i) {
            if (s[i][j] == '1') {
                nw = !nw;
            }
        }

        if (nw != s[n][j] - '0') {
            bj.emplace_back(j);
        }
    }

    std::map<char, char> mp;

    mp['1'] = '0';
    mp['0'] = '1';
    int res = 0;
    while (bi.size() && bj.size()) {
        int i = bi.back(), j = bj.back();

        bi.pop_back();
        bj.pop_back();

        res++;
        s[i][j] = mp[s[i][j]];
    }

    while (bi.size()) {
        int i = bi.back(), j = n;

        bi.pop_back();

        res++;
        s[i][j] = mp[s[i][j]];
    }

    while (bj.size()) {
        int i = n, j = bj.back();

        bj.pop_back();

        res++;
        s[i][j] = mp[s[i][j]];
    }

    bool nw = false;
    for (int i = 0; i < n; ++i) {
        if (s[i][n] == '1') {
            nw = !nw;
        }
    }

    if (nw != s[n][n] - '0') {
        res++;
        s[n][n] = mp[s[n][n]];
    }

    std::cout << res << '\n';
    return 0;
}
