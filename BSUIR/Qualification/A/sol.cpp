/**
 *    author:  feev1x
 *    created: 19.03.2025 12:14:13
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 1;

int inv[N];

inline int mul(int a, int b, int mod) {
    return (int64_t)a * b % mod;
}

inline int divide(int a, int b, int mod) {
    return mul(a, inv[b], mod);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    inv[1] = 1;
    for (int i = 2; i < n; ++i) {
        inv[i] = n - (int64_t)(n / i) * inv[n % i] % n;
    }

    std::vector<int> a(n);
    std::vector<bool> used(n);
    for (int sec = sqrt(n); sec >= 2; --sec) {
        bool flag = true;
        a[1] = 1, a[2] = sec;

        used[1] = true, used[sec] = true;

        for (int i = 3; i < n; ++i) {
            a[i] = divide(mul(a[i - 1], a[i - 1], n), a[i - 2], n);

            if (used[a[i]]) {
                flag = false;

                break;
            }

            used[a[i]] = true;
        }

        for (int i = 1; flag && i < n; ++i) {
            int l = i - 1, r = i + 1;

            if (i == 1) {
                l = n - 1;
            }

            if (i == n - 1) {
                r = 1;
            }

            if (mul(a[i], a[i], n) != mul(a[l], a[r], n)) {
                flag = false;

                break;
            }
        }

        if (flag) {
            std::cout << "Yes\n";
            for (int i = 1; i < n; ++i) {
                std::cout << a[i] << " \n"[i == n - 1];
            }

            exit(0);
        }

        std::fill(used.begin(), used.end(), false);
    }

    std::cout << "No\n";
    return 0;
}
