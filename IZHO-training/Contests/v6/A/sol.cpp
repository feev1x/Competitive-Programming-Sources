/**
 *    author:  feev1x
 *    created: 10.01.2025 11:04:16
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::map<char, std::pair<int, int>> mp;
    std::vector<int> x(n), y(n);
    std::string d(n);

    mp['N'] = {0, -1};
    mp['S'] = {0, 1};
    mp['E'] = {1, 0};
    mp['W'] = {-1, 0};

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i] >> d[i];
    }


    return 0;
}
