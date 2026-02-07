/**
 *    author:  feev1x
 *    created: 24.11.2025 13:13:18
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    if (n == 4) {
        std::cout << "3\n1 1\n2 1\n3 1\n";
        exit(0);
    }

    std::vector<int> prev(n + 1, -1), next(n + 1, -1);

    int m = cbrt(n) + 1;

    for (int i = 2; i <= n; ++i)
        prev[i] = i - 1;

    for (int i = 1; i < n; ++i)
        next[i] = i + 1;

    int ly = n + 5;
    auto Del = [&](int i) {
        std::cout << i << ' ' << next[i] - i << '\n';

        if (next[i] != -1)
            prev[next[i]] = prev[i];

        if (prev[i] != -1)
            next[prev[i]] = next[i];

        i = ly;
    };

    std::cout << n - 1 << '\n';
    while (prev[n] != -1) {
        if (prev[prev[n]] == -1) {
            Del(prev[n]);
            break;
        }

        for (int j = m; j >= 2; --j) {
            int nw = n;

            while (nw != -1) {
                int _ = j;

                while (_-- && nw != -1)
                    nw = prev[nw];

                if (nw != -1)
                    Del(nw);
            }
        }
    }

    return 0;
}
