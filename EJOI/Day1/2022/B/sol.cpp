/**
 *    author:  feev1x
 *    created: 03.05.2025 14:01:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto Ask = [](std::vector<int> a) {
        std::cout << "? " << a.size();

        for (auto u: a) {
            std::cout << ' ' << u;
        }


        std::cout << std::endl;

        std::string got; std::cin >> got;

        return got == "YES";
    };

    auto Report = [](int v) {
        std::cout << "! " << v << std::endl;
    };
    
    int n; std::cin >> n;

    std::vector<int> d(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        d[u]++, d[v]++;
    }

    std::vector<int> a, c;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 1) {
            a.emplace_back(i);
        } else {
            c.emplace_back(i);
        }
    }

    if (Ask(a)) {

//        int l = 0, r = a.size() - 2, ans = a.size() - 1;
//
//        while (l <= r) {
//            int m = l + r >> 1;
//
//            std::vector<int> b;
//            for (int i = 0; i <= m; ++i) {
//                b.emplace_back(a[i]);
//            }
//
//            if (l == 0 && r == 0) {
//                b.emplace_back(a.back());
//            }
//            
//            if (Ask(b)) {
//                r = m - 1;
//                ans = m;
//            } else {
//                l = m + 1;
//            }
//        }
//
//        Report(a[ans]);
    } else {
        int l = 0, r = c.size() - 2, ans = c.size() - 1;
        
        while (l <= r) {
            int m = l + r >> 1;

            auto b = a;
            for (int i = 0; i <= m; ++i) {
                b.emplace_back(c[i]);
            }

            std::sort(b.begin(), b.end());

            b.erase(std::unique(b.begin(), b.end()), b.end());

            if (Ask(b)) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }

        Report(c[ans]);
    }

    return 0;
}
