/**
 *    author:  feev1x
 *    created: 04.07.2025 11:30:42
**/
#include <bits/stdc++.h>

struct Sptable {
    std::vector<std::vector<int>> sp;
    std::vector<int> log;
    int n;

    Sptable(std::vector<int> a) : n(a.size() - 1) {
        log.resize(n + 1);

        for (int i = 2; i <= n; ++i)
            log[i] = log[i / 2] + 1;

        sp.resize(n + 1, std::vector<int>(log[n] + 1));

        for (int i = 1; i <= n; ++i)
            sp[i][0] = a[i];

        for (int j = 1; j <= log[n]; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                sp[i][j] = std::min(sp[i][j - 1], sp[i + (1 << j - 1)][j - 1]);
    }

    inline int get(int l, int r) {
        int i = log[r - l + 1];

        return std::min(sp[l][i], sp[r - (1 << i) + 1][i]);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;    

    std::stack<int> stk;
    bool fl = true;
    std::vector<int> a(n + 1), nx(n + 1), idx(n + 1), mx(n + 2);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        if (i & 1) {
            if (a[i] != (i + 1) / 2) {
                fl = false;
            }
        } else {
            if (a[i] != n - (i / 2) + 1) {
                fl = false;
            }
        }

        idx[a[i]] = i;
    }


    Sptable sp(a);

    for (int i = n; i >= 0; --i) {
        while (stk.size() && a[stk.top()] < a[i])
            stk.pop();

        if (stk.size())
            nx[i] = stk.top();
        else
            nx[i] = n;

        stk.emplace(i);

        mx[i] = std::max(mx[i + 1], a[i]);
    }

    std::vector<std::vector<int>> ans;
    std::vector<int> cls;
    while (q--) {
        int k, j; std::cin >> k >> j;

        if (fl) {
            if (k == j) {
                if (j & 1) {
                    std::cout << (j == 1 ? mx[j] : a.back()) << '\n';
                } else {
                    std::cout << a[j] << '\n';
                }
            } else {
                std::cout << a[j] << '\n';
            }

            continue;
        }

        --j;

        if (ans.size() <= k)
            ans.resize(k + 1),
            cls.resize(k + 1);

        if (ans[k].size() <= j && !cls[k]) {
            for (int i = ans[k].size(); i <= j; ++i) {
                int sm = ans[k].empty() ? 0 : idx[ans[k].back()];

                if (i == k - 1) {
                    ans[k].emplace_back(a[nx[sm]]);

                    break;
                }

                int r = std::min(n - k + i + 1, nx[sm]);

                ans[k].emplace_back(sp.get(sm + 1, r));

                if (idx[ans[k].back()] == n - k + i + 1 && i != k - 1) {
                    cls[k] = i + 1;

                    break;
                }
            }

            if (ans[k].size() == k) {
                ans[k].back() = mx[idx[ans[k].back()]];
            }
        }

        std::cout << (cls[k] - 1 <= j && cls[k] ? a[n - k + j + 1] : ans[k][j]) << '\n';
    }
    return 0;
}
