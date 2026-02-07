#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")

constexpr int N = 1e5;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> get(N);
    for (int i = 0; i < N; ++i) {
        int u = i;

        for (int j = 0; j < 5; ++j) {
            get[i].emplace_back(u % 10);
            u /= 10;
        }
    }

    auto Idx = [&](std::vector<int> a) {
        int i = 0, pw = 1;

        for (int j = 0; j < 5; ++j) {
            i += a[j] * pw;
            pw *= 10;
        }

        return i;
    };

    std::vector<std::array<int, 31>> anc(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 31; ++j) {
            anc[i][j] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        auto a = get[i];

        int sum = accumulate(a.begin(), a.end(), 0ll) % 10;
        a.erase(a.begin());

        a.emplace_back(sum);

        int j = Idx(a);
        anc[i][0] = j;
    }

    std::array<bool, N> used;
    std::fill(used.begin(), used.end(), false);
    auto Do = [&](int i) {
        int u = i;

        std::vector<int> a;
        while (!used[u]) {
            used[u] = true;
            a.emplace_back(u);
            u = anc[u][0];
        }

        bool flag = false;
        for (auto v: a) {
            if (u == v) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            std::reverse(a.begin(), a.end());

            for (auto u: a) {
                for (int j = 1; j < 31; ++j) {
                    anc[u][j] = anc[anc[u][j - 1]][j - 1];
                }
            }

            return;
        }

        flag = false;
        std::vector<int> b;
        for (auto v: a) {
            if (u == v) {
                flag = true;
            }

            if (flag) {
                b.emplace_back(v);
            }
        }

        while (a.back() != u) {
            a.pop_back();
        }

        a.pop_back();
        
        for (int i = 0; i < b.size(); ++i) {
            for (int j = 0; j < 31; ++j) {
                int k = (i + (1ll << j)) % (int)b.size();

                assert(0 <= k && k < b.size());

                anc[b[i]][j] = b[k];
            }
        }

        std::reverse(a.begin(), a.end());

        for (auto u: a) {
            for (int j = 1; j < 31; ++j) {
                anc[u][j] = anc[anc[u][j - 1]][j - 1];
            }
        }
    };

    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            Do(i);
        }
    }


    std::array<std::pair<int, int>, 5> a;
    for (int i = 0; i < 5; ++i) {
        std::cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < N; ++i) {
        bool flag = true;

        for (int j = 0; j < 5; ++j) {
            if (a[j].second <= 5) {
                auto b = get[i];

                if (b[a[j].second - 1] != a[j].first) {
                    flag = false;
                    break;
                }
            } else {
                int ds = a[j].second - 5;

                int nw = i;
                for (int k = 0; k < 31; ++k) {
                    if (ds >> k & 1) {
                        nw = anc[nw][k];
                    }
                }

                auto b = get[nw];

                if (b.back() != a[j].first) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            auto b = get[i];

            for (auto u: b) {
                std::cout << u << '\n';
            }

            exit(0);
        }
    }

    return 0;
}
