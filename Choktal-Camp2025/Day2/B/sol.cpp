/**
 *    author:  feev1x
 *    created: 02.07.2025 10:26:39
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::multiset<int> st;
    std::vector<int> a(n + 1), b(n + 1), idx(n), pos(n + 1);
    std::vector<std::pair<int, int>> sr;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i] >> b[i];

        st.emplace(a[i]);

        sr.emplace_back(a[i], i);
        idx[i - 1] = i;
    }

    std::sort(sr.begin(), sr.end());

    for (int i = 0; i < n; ++i) {
        pos[sr[i].second] = i;
    }

    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
            return b[i] > b[j] || b[i] == b[j] && a[i] < a[j];
            });

    int mx = 0, res = 1e9;
    for (auto i: idx) {
        int l, r, ans, ps = pos[i];

        l = 0, r = ps - 1, ans = -1;
        while (l <= r) {
            int m = l + r >> 1;

            if (sr[m].first >= std::max(mx, b[i])) {
                r = m - 1, ans = m;
            } else {
                l = m + 1;
            }
        }

        if (ans != -1) {
            res = std::min(res, sr[ans].first - b[i]);
        }

        l = ps + 1, r = n - 1, ans = -1;
        while (l <= r) {
            int m = l + r >> 1;

            if (sr[m].first >= std::max(mx, b[i])) {
                r = m - 1, ans = m;
            } else {
                l = m + 1;
            }
        }

        if (ans != -1) {
            res = std::min(res, sr[ans].first - b[i]);
        }

        l = 0, r = ps - 1, ans = -1;
        while (l <= r) {
            int m = l + r >> 1;

            if (sr[m].first < b[i]) {
                l = m + 1;

                if (sr[m].first >= mx) {
                    ans = m;
                }
            } else {
                r = m - 1;
            }
        }

        if (ans != -1) {
            res = std::min(res, b[i] - sr[ans].first);
        }

        l = ps + 1, r = n - 1, ans = -1;
        while (l <= r) {
            int m = l + r >> 1;

            if (sr[m].first < b[i]) {
                l = m + 1;

                if (sr[m].first >= mx) {
                    ans = m;
                }
            } else {
                r = m - 1;
            }
        }

        if (ans != -1) {
            res = std::min(res, b[i] - sr[ans].first);
        }

        mx = std::max(mx, a[i]);
    }

    std::cout << res << '\n';
    return 0;
}

