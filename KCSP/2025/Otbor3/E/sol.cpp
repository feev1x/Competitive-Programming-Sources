/**
 *    author:  feev1x
 *    created: 16.03.2025 11:15:20
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::string s; std::cin >> s;

    int mx = INF;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            mx = std::min(mx, a[i] - 1);
        }
    }

    int64_t diff = 0;
    std::vector<std::pair<int64_t, int64_t>> sl;
    for (int i = 1; i < n; ++i) {
        diff += std::abs(a[i] - a[i - 1]);

        if (s[i] == s[i - 1]) {
            continue;
        }

        if (s[i] == 'D') {
            if (a[i] > a[i - 1]) {
                if (a[i] - a[i - 1] == 1) {
                } else {
                    sl.emplace_back(1, -2);
                    sl.emplace_back((a[i] - a[i - 1]) / 2 + 1, 2);
                }

                sl.emplace_back((a[i] - a[i - 1] + 1) / 2 + 1, 2);
            } else {
                sl.emplace_back(1, 2);
            }
        } else {
            if (a[i - 1] > a[i]) {
                if (a[i - 1] - a[i] == 1) {
                } else {
                    sl.emplace_back(1, -2);
                    sl.emplace_back((a[i - 1] - a[i]) / 2 + 1, 2);
                }

                sl.emplace_back((a[i - 1] - a[i] + 1) / 2 + 1, 2);
            } else {
                sl.emplace_back(1, 2);
            }
        }
    }

    std::sort(sl.begin(), sl.end());

    int64_t tw = 0, mtw = 0, res = 0, mnsum = diff, sum = diff;
    for (int i = 0, j = 0; i <= mx; ++i) {
        while (j < sl.size() && sl[j].first == i) {
            if (sl[j].second == 2) {
                tw++;
            } else {
                mtw++;
            }

            j++;
        }

        sum += tw * 2 - mtw * 2;

        if (mnsum > sum) {
            mnsum = sum;
            res = i;
        }
    }

    std::cout << res << '\n';
    return 0;
}
