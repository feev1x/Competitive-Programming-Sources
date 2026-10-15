#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n, k, a, b; std::cin >> n >> k >> a >> b;
    int64_t res = 0;
    while (n > 1) {
        res += (n % k) * a;
        n -= (n % k);
        if (b > a * (n - n / k)) break;
        n /= k;
        res += b;
    }
    std::cout << res + (n - 1) * a << '\n';
    return 0;
}
