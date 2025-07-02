/**
 *    author:  feev1x
 *    created: 13.06.2025 13:44:28
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int64_t> p(n), d(n);

        for (auto &u: p) {
            std::cin >> u;
        }

        for (auto &u: d) {
            std::cin >> u;
        }

        int q; std::cin >> q;
        while (q--) {
            int64_t pos; std::cin >> pos; pos--;

            int64_t nw = -1;
            bool fl = true, inf = false;
            std::vector<std::array<bool, 2>> used(n, std::array<bool, 2>{false, false});
            for (int i = 0; !inf && i < 2 * n; ++i) {
                bool flag = false;

//////////////////                std::cout << nw << ' ' << fl << ' ' << pos << '\n';

                if (fl) {
                    for (int i = 0; i < n; ++i) {
                        if (pos >= p[i]) {
                            continue;
                        }

                        if ((nw + std::abs(p[i] - pos) - d[i]) % k == 0) {
                            nw += std::abs(p[i] - pos);
                            pos = p[i];
                            fl = !fl;
                            flag = true;

                            if (used[i][fl]) {
                                inf = true;
                            }

                            used[i][fl] = true;

                            break;
                        }
                    }
                } else {
                    for (int i = n - 1; i >= 0; --i) {
                        if (pos <= p[i]) {
                            continue;
                        }

                        if ((nw + std::abs(p[i] - pos) - d[i]) % k == 0) {
                            nw += std::abs(p[i] - pos);
                            pos = p[i];
                            fl = !fl;
                            flag = true;

                            if (used[i][fl]) {
                                inf = true;
                            }

                            used[i][fl] = true;

                            break;
                        }
                    }

                }

                if (!flag) {
                    break;
                }
            }

            std::cout << (inf ? "NO\n" : "YES\n");
        }
    }
    return 0;
}
