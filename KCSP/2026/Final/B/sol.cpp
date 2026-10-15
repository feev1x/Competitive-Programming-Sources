#include <bits/stdc++.h>

constexpr int N = 1e4 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<std::vector<std::pair<int, int>>> seg(N);
    std::vector<std::vector<int>> pt(N);
    int n; std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i], pt[x[i]].emplace_back(y[i]);
    int m; std::cin >> m;
    std::vector<int> xb(m), yb(m), r(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> xb[i] >> yb[i] >> r[i];
        for (int j = std::max(0, xb[i] - r[i]); j <= std::min(N - 1, xb[i] + r[i]); ++j) {
            int val = sqrt((int64_t)r[i] * r[i] - (int64_t)(j - xb[i]) * (j - xb[i]));
            if (val >= 0) seg[j].emplace_back(yb[i] - val, yb[i] + val);
        }
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        std::sort(pt[i].begin(), pt[i].end());
        std::sort(seg[i].begin(), seg[i].end());
        int mxr = -1, pi = 0;
        for (int si = 0; si < seg[i].size() && pi < pt[i].size(); ++si) {
            mxr = std::max(mxr, seg[i][si].second);
            while (pi < pt[i].size() && pt[i][pi] < seg[i][si].first) pi++, res++;
            while (pi < pt[i].size() && pt[i][pi] <= mxr) pi++;
        }
        while (pi < pt[i].size()) res++, pi++;
    }
    std::cout << res << '\n';
    return 0;
}
