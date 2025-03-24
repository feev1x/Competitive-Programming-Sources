/**
 *    author:  feev1x
 *    created: 10.03.2025 15:33:54
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline void sub_self(int &a, int b) {
     a -= b;

     if (a < 0) {
         a += MOD;
     }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::string k; std::cin >> k;

    std::string s; std::cin >> s;

    if (s[0] == '0') {
        std::cout << 0 << '\n';
        
        exit(0);
    }

    int m = n;

    n += k.size();

    std::string ss = k + s;
    std::vector<int> z(n);
    int l = 0, r = 0;

    z[0] = n;
    for (int i = 1; i < n; ++i) {
        if (r > i) {
            z[i] = std::min(r - i, z[i - l]);
        }

        while (i + z[i] < n && ss[z[i]] == ss[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }

    n = m;

    int kz = k.size();
    std::vector<std::vector<int>> del(n + 1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            continue;
        }

        if (z[i + kz] >= kz || i + kz - 1 >= n || s[i + z[i + kz]] > k[z[i + kz]]) {
            del[std::min(n, i + kz - 1)].emplace_back(i);
        } else {
            del[i + kz].emplace_back(i);
        }
    }

    std::vector<int> dp(n + 1);
    dp[0] = 1;
    int sum = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != '0') {
            dp[i] = sum;

            add_self(sum, dp[i]);
        }

        for (auto j: del[i]) {
            sub_self(sum, dp[j]);
        }
    }

    std::cout << sum << '\n';
    return 0;
}
