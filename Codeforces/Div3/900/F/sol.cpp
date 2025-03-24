/**
 *    author:  feev1x
 *    created: 05.03.2025 17:27:01
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<std::map<int, int>> pr(N);
    for (int i = 2; i < N; ++i) {
        int div = i;

        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                div = j; 

                break;
            }
        }

        pr[i] = pr[i / div];
        pr[i][div]++;
    }

    int tt; std::cin >> tt;
    while (tt--) {
        int n, q; std::cin >> n >> q;

        auto mp = pr[n];
        while (q--) {
            int type; std::cin >> type;

            if (type == 1) {
                int x; std::cin >> x;

                std::map<int, int> mp1;
                for (auto [key, val]: pr[x]) {
                    mp[key] += val;
                }

                for (auto [key, val]: mp) {
                    int vl = val + 1;

                    for (auto [key1, val1]: pr[vl]) {
                        mp1[key1] += val1;
                    }
                }

                bool flag = true;
                for (auto [key, val]: mp1) {
                    if (val > mp[key]) {
                        flag = false;

                        break;
                    }
                }

                std::cout << (flag ? "YES\n" : "NO\n");
            } else {
                mp = pr[n];
            }
        }

        std::cout << '\n';
    }
    return 0;
}
