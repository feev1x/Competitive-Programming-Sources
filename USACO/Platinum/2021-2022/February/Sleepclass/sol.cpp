#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int64_t> a(n);
    int64_t sum = 0;
    for (auto &u: a) {
        std::cin >> u;
        sum += u;
    }
    int q; std::cin >> q;
    while (q--) {
        int64_t num; std::cin >> num;
        if (sum % num) {
            std::cout << "-1\n";
            continue;
        }
        int64_t res = 0, ls = a[0];
        for (int i = 0; i < n; ++i) {
            if (ls > num) {
                res += ls / num;
                ls %= num;
                i--;
                if (!ls) {
                    ls = num;
                    res--;
                }
            } else if (ls < num) {
                ls += a[i + 1];
                res++;
            } else if (i + 1 < n) {
                ls = a[i + 1];
            }
        }
        std::cout << res << '\n';
    }
    return 0;
}

