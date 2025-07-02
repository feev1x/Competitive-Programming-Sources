/**
 *    author:  feev1x
 *    created: 05.04.2025 18:30:51
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = " " + s[i];
    }

    int a, b, c, d; std::cin >> a >> b >> c >> d;


    return 0;
}
