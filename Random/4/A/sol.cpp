#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;


    int64_t res = 0;
    while (n--) {
        int u; std::cin >> u;

        if (u & 1) {
            continue;
        }

        res += u;
    }

    std::cout << res << '\n';

    return 0;
}
