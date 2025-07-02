/**
 *    author:  feev1x
 *    created: 01.05.2025 21:44:06
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        auto Ask = [](int x) {
            std::cout << "? " << x << std::endl;

            int got; std::cin >> got;

            return got;
        };

        auto Report = [](int a, int b) {
            std::cout << "! " << a << ' ' << b << std::endl;
        };

        std::vector<int> a(1);
        for (int i = 1; i <= k; ++i) {
            a.emplace_back(Ask(i)); 
        }

        int pos = -1, vl = -1;
        for (int i = 1; i <= k; ++i) {
            int x = (n - i) / k;

            int got = Ask(i + x * k);

            if (a[i] != got) {
                if (pos == -1) {
                    int l = 1, r = x, ans = x;

                    while (l <= r) {
                        int m = l + r >> 1;

                        if (Ask(i + m * k) != a[i]) {
                            ans = m;
                            r = m - 1;
                        } else {
                            l = m + 1;
                        }
                    }

                    pos = i + k * ans;
                    vl = i;
                } else {
                    int ps1 = (pos - vl) / k - 1;

                    if (a[i] != Ask(i + ps1 * k)) {
                        pos = i + ps1 * k;

                        break;
                    }
                }
            }
        }

        if (pos == -1) {
            if (n == 2 * k) {
                Report(k, k);

                continue;
            }

            std::cout << "! -1" << std::endl;

            continue;
        }

        if (pos > n - k + 1) {
            pos = n - k + 1;

            std::vector<int> b;
            for (int i = 0; i < n; ++i) {
                b.emplace_back(Ask(n - i));
            }

            std::sort(b.begin(), b.end());
            b.erase(std::unique(b.begin(), b.end()), b.end());
        }

        int val = Ask(pos - 1);

        bool flag = pos > k + 1 ? true : false;
        for (int i = 0; pos > k + 1 && i < k - 1; ++i) {
            if (val == Ask(pos + i)) {
                flag = false; 

                break;
            }
        }

        if (!flag) {
            Report(pos - 1, n - (pos - 1));
        } else {
            std::cout << "! -1" << std::endl;
        }
    }
    return 0;
}
