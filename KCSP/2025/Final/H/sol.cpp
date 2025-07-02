/**
 *    author:  feev1x
 *    created: 15.06.2025 14:00:20
**/
#include <bits/stdc++.h>

constexpr int N = 1e5 + 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q, T; std::cin >> n >> q >> T;

    std::vector<int> p(q + 1), s(q + 1), e(q + 1);
    std::vector<std::set<int>> st(n + 1), en(n + 1);
    for (int i = 1; i <= q; ++i) {
        std::cin >> p[i] >> s[i] >> e[i];

        st[p[i]].emplace(s[i]);
        en[p[i]].emplace(e[i]);
    }

    std::vector<std::set<std::pair<int, int>>> ost(n + 1), oen(n + 1);
    for (int i = 1; i <= n; ++i) {
        int r = -1, l = -1;
        if(st[i].size())
        for (auto it = --st[i].end(); ; --it) {
            if (r == -1) {
                r = *it;
                l = *it - 1;
            } else {
                if (l - *it <= 1) {
                    l = *it - 1;
                } else {
                    ost[i].emplace(r, l);
                    r = *it;
                    l = *it - 1;
                }
            }

            if (it == st[i].begin()) {
                break;
            }
        }

        if (l != -1) {
            ost[i].emplace(r, l);
        }

        r = -1, l = -1;
        if(en[i].size())
        for (auto it = --en[i].end(); ; --it) {
            if (r == -1) {
                r = *it;
                l = *it - 1;
            } else {
                if (l - *it <= 1) {
                    l = *it - 1;
                } else {
                    oen[i].emplace(r, l);
                    r = *it;
                    l = *it - 1;
                }
            }

            if (it == en[i].begin()) {
                break;
            }
        }

        if (l != -1) {
            oen[i].emplace(r, l);
        }
    }

    int l = 1, r = T, ans = -1;
    while (l <= r) {
        int m = l + r >> 1;

        bool flag = false;
        for (int i = 1; i <= q; ++i) {
            int tm = m;

            for (int j = 1; j < p[i]; ++j) {
                auto it = ost[j].lower_bound({tm, -1});

                if (ost[j].empty() || it == ost[j].end() || it->second > tm) {
                    continue;
                }

                tm = it->first + 1;
            }


            if (tm > s[i]) {
                continue;
            }

            tm = e[i];

            for (int j = p[i] + 1; j <= n; ++j) {
                auto it = oen[j].lower_bound({tm, -1});

                if (oen[j].empty() || oen[j].end() == it || it->second > tm) {
                    continue;
                }

                tm = it->first + 1;
            }

            if (tm <= T) {
                flag = true;

                break;
            }
        }

        if (flag) {
            l = m + 1, ans = m;
        } else {
            r = m - 1;
        }
    }

    std::cout << ans << '\n';

    if (ans == -1) {
        exit(0);
    }

    std::vector<int> res;

    for (int i = 1; i <= q; ++i) {
        int tm = ans;

        for (int j = 1; j < p[i]; ++j) {
            auto it = ost[j].lower_bound({tm, -1});

            if (ost[j].empty() || it == ost[j].end() || it->second > tm) {
                continue;
            }

            tm = it->first + 1;
        }


        if (tm > s[i]) {
            continue;
        }

        tm = e[i];

        for (int j = p[i] + 1; j <= n; ++j) {
            auto it = oen[j].lower_bound({tm, -1});

            if (oen[j].empty() || oen[j].end() == it || it->second > tm) {
                continue;
            }

            tm = it->first + 1;
        }

        if (tm <= T) {
            res.emplace_back(i);
        }
    }

    std::cout << res.size() << '\n';

    for (auto u: res) {
        std::cout << u << ' ';
    }

    std::cout << '\n';
    return 0;
}
