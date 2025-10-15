/**
 *    author:  feev1x
 *    created: 12.09.2025 14:29:58
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int n = std::count(s.begin(), s.end(), 'm') + std::count(s.begin(), s.end(), '?');

    std::vector<bool> min(n + 1);

    int par = -1;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> p(n + 1, -1);

    int nw = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'm') {
            min[nw] = s[i + 1] == 'i';
            
            p[nw] = par;
            if (par != -1)
                g[par].emplace_back(nw);

            par = nw++;
        } else if (s[i] == ')') {
            par = p[par];
        } else if (s[i] == '?') {
            p[nw] = par;

            if (par != -1)
                g[par].emplace_back(nw);

            nw++;
        }
    }

    std::vector<std::array<std::pair<int, int>, 3>> dp(n + 1);
    for (auto &u: dp)
        for (auto &v: u)
            v = {0, n - 1};

    auto Dfs = [&](auto &&self, int v) -> void {
        if (g[v].empty()) {
            dp[v][0] = {1, 1};
            dp[v][1] = {0, 0};
            dp[v][2] = {0, 0};
            return;
        }

        assert(g[v].size() == 2);

        for (auto to: g[v])
            self(self, to);

        int l = g[v][0], r = g[v][1];
        dp[v][0] = {(min[v] ? std::max({dp[l][0].first + dp[r][0].first, dp[l][1].first + dp[r][0].first, dp[l][0].first +
                    dp[r][1].first}) : dp[l][0].first + dp[r][0].first), 
                    (min[v] ? std::min({dp[l][0].second + dp[r][0].second, dp[l][1].second + dp[r][0].second, dp[l][0].second +
                    dp[r][1].second}) : dp[l][0].second + dp[r][0].second)};
        dp[v][1] = {(!min[v] ? std::max({dp[l][1].first + dp[r][1].first, dp[l][1].first + dp[r][0].first, dp[l][0].first +
                    dp[r][1].first}) : dp[l][1].first + dp[r][1].first), 
                    (!min[v] ? std::min({dp[l][1].second + dp[r][1].second, dp[l][1].second + dp[r][0].second, dp[l][0].second +
                    dp[r][1].second}) : dp[l][1].second + dp[r][1].second)};
        dp[v][2] = {(!min[v] ? std::max(dp[l][2].first + dp[r][0].first, dp[l][0].first + dp[r][2].first) : std::max(dp[l][2].first + dp[r][1].first, dp[l][1].first + dp[r][2].first)), 
        (!min[v] ? std::min(dp[l][2].second + dp[r][0].second, dp[l][0].second + dp[r][2].second) : std::min(dp[l][2].second + dp[r][1].second, dp[l][1].second + dp[r][2].second)) };
    };

    Dfs(Dfs, 1);

//    for (auto i: {1, 2, 5}) {
//        std::cout << " 0:{" << dp[i][0].first << ' ' << dp[i][0].second << "} 1:{" <<
//            dp[i][1].first << ' ' << dp[i][1].second << "} 2:{" << 
//            dp[i][2].first << ' ' << dp[i][2].second << "}\n";
//    }

    std::cout << dp[1][2].first - dp[1][2].second + 1 << '\n';
    return 0;
}
