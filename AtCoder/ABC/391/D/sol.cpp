/**
 *    author:  feev1x
 *    created: 01.02.2025 18:27:15
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, w; std::cin >> n >> w;

    std::vector<std::vector<int>> b(w + 1);
    std::vector<int> X(n + 1), Y(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x, y; std::cin >> x >> y;

        b[x].emplace_back(y);

        X[i] = x, Y[i] = y;
    }

    for (int i = 1; i <= w; ++i) {
        std::sort(b[i].begin(), b[i].end(), std::greater<>());
    }

    auto B = b;

    for (int i = 1; i <= w; ++i) {
        std::reverse(B[i].begin(), B[i].end());
    }

    int tm = 0;
    std::vector<int> T;
    while (true) {
        int mx = 0;

        for (int i = 1; i <= w; ++i) {
            if (b[i].empty()) {
                goto end;
            }

            b[i].back() = std::max(tm == 0 ? 1 : 2, b[i].back() - tm);

            mx = std::max(mx, b[i].back() - 1);

            b[i].pop_back();
        }

        tm += mx;
        T.emplace_back(tm + 1);
    }

end:

    int q; std::cin >> q;
    while (q--) {
        int t, a; std::cin >> t >> a;

        int l = 0, r = B[X[a]].size() - 1, ans = 0;
        while (l <= r) {
            int m = l + r >> 1;

            if (B[X[a]][m] == Y[a]) {
                ans = m;

                break;
            }

            if (B[X[a]][m] > Y[a]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (T.size() <= ans || T[ans] > t) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
