/**
 *    author:  feev1x
 *    created: 05.07.2025 16:41:17
**/
#include <bits/stdc++.h>

struct Sptable {
    std::vector<std::vector<int>> sp;
    std::vector<int> lg;
    int n;

    Sptable(std::vector<int> a) : n(a.size() - 1) {
        lg.resize(n + 1);
        
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;

        sp.resize(lg[n] + 1, std::vector<int>(n + 1));

        sp[0] = a;

        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j + (1 << i) - 1 <= n; ++j)
                sp[i][j] = std::max(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
    }

    inline int get(int l, int r) {
        int i = lg[r - l + 1];

        return std::max(sp[i][l], sp[i][r - (1 << i) + 1]);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> h(n + 1), lmx(n + 1), rmx(n + 1, n + 1), idx(n + 1), ans(n + 1, -1), lans(n + 1), rans(n + 1);
    std::vector<std::array<int, 20>> lj(n + 1), rj(n + 1), la(n + 1), ra(n + 1);
    std::stack<int> stk;
    for (int i = 1; i <= n; ++i)
        std::cin >> h[i];

    auto _ = h;

    std::sort(_.begin(), _.end());

    for (int i = 1; i <= n; ++i)
        h[i] = std::lower_bound(_.begin(), _.end(), h[i]) - _.begin(),
        idx[h[i]] = i;

    for (int i = 1; i <= n; ++i) {
        while (stk.size() && h[stk.top()] < h[i])
            stk.pop();

        if (stk.size())
            lmx[i] = stk.top();

        stk.emplace(i);
    }

    while (stk.size())
        stk.pop();

    for (int i = n; i >= 1; --i) {
        while (stk.size() && h[stk.top()] < h[i])
            stk.pop();

        if (stk.size())
            rmx[i] = stk.top();
        
        stk.emplace(i);
    }

    Sptable sp(h);
    for (int val = 1; val <= n; ++val) {
        int i = idx[val];

        ans[i] = 0;

        if (lmx[i] + 1 != i) {
            int mx = idx[sp.get(lmx[i] + 1, i - 1)];

            ans[i] = std::max(ans[i], ans[mx] + 1);
            lans[i] = std::max(lans[i], ans[mx] + 1);

            lj[i][0] = mx;
            la[i][0] = rans[mx] + 1;
            for (int j = 1; j < 20; ++j) {
                lj[i][j] = lj[lj[i][j - 1]][j - 1];
                la[i][j] = std::max(la[i][j - 1], la[lj[i][j - 1]][j - 1] + (1 << j - 1));

                if (lj[i][j] == 0) {
                    break;
                }
            }
        }

        if (rmx[i] - 1 != i) {
            int mx = idx[sp.get(i + 1, rmx[i] - 1)];

            ans[i] = std::max(ans[i], ans[mx] + 1);
            rans[i] = std::max(rans[i], ans[mx] + 1);

            rj[i][0] = mx;
            ra[i][0] = lans[mx] + 1;
            for (int j = 1; j < 20; ++j) {
                rj[i][j] = rj[rj[i][j - 1]][j - 1];
                ra[i][j] = std::max(ra[i][j - 1], ra[rj[i][j - 1]][j - 1] + (1 << j - 1));

                if (rj[i][j] == 0) {
                    break;
                }
            }
        }
    }

    while (q--) {
        int l, r; std::cin >> l >> r;

        int mx = idx[sp.get(l, r)];

        int res = 0, add = 0;
        for (int u = mx; u != r && u + 1 < rmx[u];) {
            u = idx[sp.get(u + 1, std::min(rmx[u] - 1, r))];

            add++;

            res = std::max({res, lans[u] + add, add});
        }

        add = 0;
        for (int u = mx; u != l && u - 1 > lmx[u];) {
            u = idx[sp.get(std::max(lmx[u] + 1, l), u - 1)];

            add++;

            res = std::max({res, rans[u] + add, add});
        }


        std::cout << res << '\n';
    }
    return 0;
}
