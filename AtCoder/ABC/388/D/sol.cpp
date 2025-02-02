/**
 *    author:  feev1x
 *    created: 11.01.2025 18:10:50
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n), val(n), cnt(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    int cn = 0;
    for (int i = 0; i < n; ++i) {
        a[i] += cn++;

        if (i + a[i] >= n) {
            a[i] = i + a[i] - n + 1;
        } else {
            cnt[i + a[i]]++;
            a[i] = 0;
        }

        cn -= cnt[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}
