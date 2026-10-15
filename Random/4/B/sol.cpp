#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d; std::cin >> a >> b >> c >> d;

    if (c <= b) {
        if (a > d) {
            std::cout << a << ' ' << d << '\n';
        } else if (a > c) {
            std::cout << a << ' ' << a << '\n';
        } else {
            std::cout << c << ' ' << c << '\n';
        }
    } else {
        std::cout << b << ' ' << c << '\n';
    }

    return 0;
}
