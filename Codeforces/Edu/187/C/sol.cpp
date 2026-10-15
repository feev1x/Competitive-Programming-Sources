#include <bits/stdc++.h>

inline void solve() {
    int64_t s, m; std::cin >> s >> m;

    for (int i = 0, j = 0; i < 61 && j < 61; ++i, ++j) {
        if (s >> i & 1) {
            if (m >> i & 1) {
                break;
            } else {
                std::cout << "-1\n";
                return;
            }
        } else if (m >> i & 1) {
            break;
        }
    }

    __int128 cnt = 0;
    std::vector<std::pair<__int128, int>> v;
    for (int64_t i = 60, j = 60; i >= 0 && j >= 0;) {
        if (j > i) {
            if (m >> j & 1) {
                v.emplace_back(cnt, j);
            }

            j--;
            cnt = 0;
        } else if (!(s >> i & 1)) {
            --i;
        } else if (!(m >> j & 1)) {
            if (m >> j & 1) {
                v.emplace_back(cnt, j);
            }

            --j;
            cnt = 0;
        } else {
            int df = i - j;
            cnt += (1ll << df);

            --i;
        }
    }

    for (int64_t j = (v.size() ? v.back().second - 1 : 60); j >= 0; --j) {
        if (m >> j & 1) {
            v.emplace_back((__int128)cnt, j);
            cnt = 0;
        }
    }

    __int128 l = 0, r = 1e18, ans = -1;
    while (l <= r) {
        __int128 mid = l + r >> 1;
        
        auto vec = v;

        for (int i = 1; i < vec.size(); ++i) {
            __int128 mul = 1ll << (vec[i - 1].second - vec[i].second);

            if (vec[i - 1].first > mid) {
                vec[i].first += (vec[i - 1].first - mid) * mul;
            }

            if (vec[i].first - mid > mid) {
                vec.back().first = mid + 1;
                break;
            }
        }

        if (vec.back().first > mid) {
            l = mid + 1;
        } else {
            r = mid - 1, ans = mid;
        }
    }

    std::cout << (int64_t)ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
