#include <bits/stdc++.h>

#define int64_t __int128_t

constexpr int N = 31;

inline void print(__int128_t x) {
    if (x >= 10) {
        print(x / 10);
    }

    std::cout << (int)(x % 10);
}

inline __int128_t gcd(__int128_t a, __int128_t b) {
    if (a > b) {
        std::swap(a, b);
    }

    while (a) {
        b %= a;

        std::swap(a, b);
    }

    return b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n; std::cin >> n;

    std::vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    int64_t res = 0, resb = (1ll << n) - 1;
    for (int64_t i = 0; i < N; ++i) {
        int64_t c = 0;

        for (int j = 1; j <= n; ++j) {
            c += (a[j] >> i & 1);
        }

        res += (!!c) * (1ll << i) * (1ll << n - 1);
    }

    int64_t gc = gcd(res, resb);

    print(res / gc);
    std::cout << '/';
    print(resb / gc);
    return 0;
}
