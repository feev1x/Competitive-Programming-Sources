/**
 *    author:  feev1x
 *    created: 13.08.2025 15:51:49
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

struct Trie {
    std::vector<std::array<int, 26>> g;
    std::vector<bool> end;

    Trie() {
        g.assign(1, {});
        end.assign(1, false);
    }
    
    inline void add(std::string s) {
        int nw = 0;

        for (int i = 0; i < s.size(); ++i) {
            int u = s[i] - 'a';

            if (!g[nw][u]) {
                g[nw][u] = g.size();

                g.emplace_back(std::array<int, 26>{});
                end.emplace_back(false);
            }

            nw = g[nw][u];
        }

        end[nw] = true;
    }

    inline std::vector<int> get(std::string s) {
        int nw = 0;

        std::vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            int u = s[i] - 'a';

            if (!g[nw][u])
                break;

            nw = g[nw][u];

            if (end[nw])
                ans.emplace_back(i + 1);
        }

        return ans;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::string s; std::cin >> s;

        s = " " + s;

        Trie trie;
        for (int i = 0; i < m; ++i) {
            std::string t; std::cin >> t;

            trie.add(t);
        }

        std::vector<int> dp(n + 2);
        for (int i = 1; i <= n; ++i) {
            std::string str;

            for (int j = 0; j < 20 && i + j <= n; ++j)
                str += s[i + j];

            auto got = trie.get(str);

            for (auto j: got)
                dp[i + j] = std::max(dp[i + j], dp[i] + 1);

            dp[i + 1] = std::max(dp[i + 1], dp[i]);
        }

        std::cout << dp[n + 1] << '\n';
    }

    return 0;
}
