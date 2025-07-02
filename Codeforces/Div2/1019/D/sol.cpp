/**
 *    author:  feev1x
 *    created: 21.04.2025 21:26:58
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int x = -1, even = 0, odd = 0, mx = 0;
        std::vector<int> a(n + 1), p(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            mx = std::max(mx, a[i]);

            if (a[i] & 1) {
                odd++;
            } else {
                even++;
            }
        }

        x = even + 1;

        for (int i = 1; i <= n; ++i) {
            if (a[i] == -1) {
                p[i] = x;
            }
        }

        int l = x - 1, r = x + 1;
        for (int op = mx; op >= 1; --op) {
            std::vector<int> pos;

            for (int i = 1; i <= n; ++i) {
                if (a[i] == op) {
                    pos.emplace_back(i);
                } else if (p[i]) {
                    break;
                }
            }

            std::reverse(pos.begin(), pos.end());

            if (op & 1) {
                for (auto u: pos) {
                    p[u] = r++;
                }

                for (int i = (pos.size() ? pos.front() : 0) + 1; i <= n; ++i) {
                    if (a[i] == op) {
                        p[i] = r++;
                    }
                }
            } else {
                for (auto u: pos) {
                    p[u] = l--;
                }

                for (int i = (pos.size() ? pos.front() : 0) + 1; i <= n; ++i) {
                    if (a[i] == op) {
                        p[i] = l--;
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            std::cout << p[i] << " \n"[i == n];
        }
    }

    return 0;
}
