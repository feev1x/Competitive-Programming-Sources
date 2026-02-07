#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int64_t> a(2 * n), p(2 * n + 1), b, p2(2 * n + 1);

    int64_t sum = 0;
    for (auto &u: a) {
        std::cin >> u;

        sum += u;
    }

    b = a;

    std::reverse(b.begin(), b.end());

    int64_t sm = 0;
    for (int i = 0; i < 2 * n; ++i) {
        p[i + 1] = p[i] + a[i];
        p2[i + 1] = p2[i] + b[i];
    }

    for (int i = 1; i <= n; ++i) {
        int64_t fs = sum, cnt = 0;

        int ost = n - (n + i - 1) / i + 1, scnt = (n + i - 1) / i - 1;

        if (ost > i) {
            ost -= i;
        } else {
            ost = 0;
        }

        for (int j = i + 1, num = 0; j <= 2 * n; j += i + 1, num++) {
            if (cnt + i < n) {
                fs -= 2 * (p[j - 1] - p[j - i - 1]);
                cnt += i;
            } else {
                fs -= 2 * (p[j - i - 1 + n - cnt] - p[j - i - 1]);
                break;
            }

            if (scnt - num <= ost) {
                j++;
            }
        }

        int64_t ss = -sum;
        cnt = 0;

        for (int j = i + 1, num = 0; j <= 2 * n; j += i + 1, num++) {
            if (cnt + i < n) {
                ss += 2 * (p2[j - 1] - p2[j - i - 1]);
                cnt += i;
            } else {
                ss += 2 * (p2[j - i - 1 + n - cnt] - p2[j - i - 1]);
                break;
            }

            if (scnt - num <= ost) {
                j++;
            }
        }

        std::cout << std::max(fs, ss) << " \n"[i == n];
    }
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
