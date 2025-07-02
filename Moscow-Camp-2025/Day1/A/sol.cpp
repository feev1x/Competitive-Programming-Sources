#include "grader.h"
#include <bits/stdc++.h>

std::vector<int> Solve(int n, int digger, int q, std::vector<std::pair<int, int>> e, std::vector<std::pair<int, int>> qq) {
    std::vector<std::vector<int>> le(n), re(n);
    for (auto [u, v]: e) {
        if (u > v) {
            std::swap(u, v);
        }

        le[u].emplace_back(v);
        re[v].emplace_back(u);
    }

    std::sort(e.begin(), e.end());

    std::vector<int> ans(q);
    std::vector<std::vector<int>> la(n), ra(n);
    auto Dnc = [&](auto &&self, std::vector<int> idx, int _l, int _r) -> void {
        if (_l == _r) {
            return;
        }

        int m = _l + _r >> 1;

        for (auto i: idx) {
            if (qq[i].first <= m && m <= qq[i].second) {
                la[qq[i].first].emplace_back(i);
                ra[qq[i].second].emplace_back(i);
            }
        }

        {
            std::vector<int> stk;
            std::vector<std::pair<int, int>> opt;

            for (int i = m; i <= _r; ++i) {
                for (auto u: re[i]) {
                    if (u < m) {
                        while (opt.size() && opt.back().first <= u) {
                            opt.pop_back();
                        }

                        opt.emplace_back(u, i);
                    } else {
                        while (stk.size() && stk.back() >= u) {
                            stk.pop_back();
                        }
                    }
                }

                for (auto j: ra[i]) {
                    int l = 0, r = opt.size() - 1, it = -1;
                    while (l <= r) {
                        int _m = l + r >> 1;

                        if (opt[_m].first < qq[j].first) {
                            r = _m - 1;
                        } else {
                            l = _m + 1, it = _m;
                        }
                    }

                    if (it == -1) {
//                        std::cout << j << ' ' << stk.size() << '\n';
                        ans[j] += stk.size();
                        continue;
                    }

//                    std::cout << ans[j] << ' ';
                    ans[j] += stk.end() - std::lower_bound(stk.begin(), stk.end(), opt[it].second);
//                    std::cout << ans[j] << ' ' << j << '\n';
                }

                stk.emplace_back(i);
            }
        }

        {
            std::vector<int> stk;
            std::vector<std::pair<int, int>> opt;

            for (int i = m; i >= _l; --i) {
                for (auto u: le[i]) {
                    if (u > m) {
                        while (opt.size() && opt.back().first >= u) {
                            opt.pop_back();
                        }

                        opt.emplace_back(u, i);
                    } else {
                        while (stk.size() && stk.back() < u) {
                            stk.pop_back();
                        }
                    }
                }

                for (auto j: la[i]) {
                    auto it = std::lower_bound(opt.begin(), opt.end(), std::pair{qq[j].second + 1, -1});

                    if (it == opt.begin()) {
//                        std::cout << j << ' ' << stk.size() << '\n';
                        ans[j] += stk.size();

                        continue;
                    }

                    --it;

                    int l = 0, r = stk.size() - 1, _ans = -1;
                    while (l <= r) {
                        int _m = l + r >> 1;

                        if (stk[_m] < it->second) {
                            r = _m - 1, _ans = _m;
                        } else {
                            l = _m + 1;
                        }
                    }

                    if (_ans == -1) {
                        continue;
                    }

                    ans[j] += stk.size() - _ans;
                }

                stk.emplace_back(i - 1);
            }
        }

        std::vector<int> l, r;
        for (auto i: idx) {
            if (qq[i].first <= m && m <= qq[i].second) {
                la[qq[i].first].pop_back();
                ra[qq[i].second].pop_back();
            } else if (qq[i].second <= m) {
                l.emplace_back(i);     
            } else {
                r.emplace_back(i);
            }
        }

        self(self, l, _l, m);
        self(self, r, m + 1, _r);
    };

    std::vector<int> idx(q);

    std::iota(idx.begin(), idx.end(), 0);
    Dnc(Dnc, idx, 0, n - 1);

    return ans;
}
