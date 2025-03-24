/**
 *    author:  feev1x
 *    created: 20.03.2025 10:55:49
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    int ls = 0;
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;

        if (ls >= u) {
            std::cout << "No\n";

            exit(0);
        }

        ls = u;
    }
    
    std::cout << "Yes\n";
    return 0;
}
