/**
 *    author:  feev1x
 *    created: 06.07.2025 20:35:54
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1);

        bool flag = false;
        int pos = -1;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            if (a[i - 1] > a[i]) {
                flag = true;
                pos = i;
            }
        }

        if (flag) {
            std::cout << "YES\n2\n" << a[pos - 1] << ' ' << a[pos] << '\n';
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
