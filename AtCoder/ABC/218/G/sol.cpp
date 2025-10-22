/**
 *    author:  feev1x
 *    created: 21.10.2025 10:52:43
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, std::less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

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

constexpr int MX = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1);
  
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

	std::vector<std::pair<int, int>> dp(n + 1, {2, MX});

    {
        ordered_set st;

        auto Median = [&]() {
            int sz = st.size();

            if (sz & 1) return *st.find_by_order(sz / 2);

            auto it = st.find_by_order(sz / 2);
            
            return (*it + *--it) / 2;
        };

        auto Dfs = [&](auto &&self, int v, int p) -> void {
            st.insert(a[v]);

            if (g[v].size() == 1 && p != v) {
                int md = Median();
                
                dp[v] = {md, md};
            }

            for (auto to: g[v]) {
                if (to != p) {
                    self(self, to, v);
				}
			}
			
            st.erase(st.upper_bound(a[v]));
        };

        Dfs(Dfs, 1, 1);
    }	
    
    {
		auto Dfs = [&](auto &&self, int v, int p) -> void {
			for (auto to: g[v])
				if (to != p) {
					self(self, to, v);

					dp[v].first = std::max(dp[v].first, dp[to].second);
					dp[v].second = std::min(dp[v].second, dp[to].first);
				}
		};

		Dfs(Dfs, 1, 1);
	}
	
    std::cout << dp[1].first << '\n';
    return 0;
}
