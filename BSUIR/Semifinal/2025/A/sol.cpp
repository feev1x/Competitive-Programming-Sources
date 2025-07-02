/**
 *    author:  feev1x
 *    created: 09.04.2025 19:56:29
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
    
        std::map<std::pair<int64_t, int64_t>, bool> mp;
        std::map<int64_t, int64_t> p, tin, tout;
        std::stack<int64_t> stk;

        stk.emplace(0);
        std::vector<int64_t> res;
        for (int i = 1; i <= n; ++i) {
            int64_t t, id; std::cin >> t;

            std::string s; std::cin >> s;

            if (s == "new") {
                std::cin >> id;

                p[id] = stk.top();
                mp[{stk.top(), id}] = true;
            } else if (s == "drop") {
                std::cin >> id;
            } else if (s == "enter") {
                std::cin >> id;

                if (!tin[id]) {
                    tin[id] = t;
                }

                res.emplace_back(id);

                stk.emplace(id); 
            } else if (s == "exit") {
                id = stk.top();

                stk.pop();

                tout[id] = t;

                if (mp[{p[id], id}]) {
                    tout[p[id]] = t;
                }
            }
        }

        std::cout << res.size() << '\n';
        for (auto u: res) {
            std::cout << u << ' ' << p[u] << ' ' << tin[u] << ' ' << tout[u] << '\n';
        }
    }

    return 0;
}
