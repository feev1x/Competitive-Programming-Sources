/**
 *    author:  feev1x
 *    created: 05.07.2025 16:04:10
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> p(n + 1), idx(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        idx[p[i]] = i;
    }

    auto Swap = [&](int i, int j) {
        std::swap(p[i], p[j]);
        std::swap(idx[p[i]], idx[p[j]]);
    };

    std::map<std::vector<int>, int> mp;

    int res = 0;
    std::queue<std::vector<int>, int> q;
    q.emplace(p);
    while (q.size()) {
        auto a = q.front();

        q.pop();

        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;

            for (int j = i + 1; j <= n; ++j) {
                if (p[i] > p[j]) {
                    cnt++;
                }
            }

            if (cnt > 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            std::cout << mp[a] << '\n';

            exit(0);
        }

        for (int i = 1; i 
    }
    return 0;
}
