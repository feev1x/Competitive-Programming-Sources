#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int res = n / 100;

    n %= 100;

    res += n / 10;

    n %= 10;

    std::cout << res + n << '\n';
    return 0;
}
