/**
 *    author:  feev1x
 *    created: 06.07.2025 09:27:38
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::map<std::tuple<int, int, int>, std::vector<std::pair<int, int>>> mp;
    auto Ask = [&](int x, int y, int z) {
        if (x > z)
            std::swap(x, z);
        if (y > z)
            std::swap(y, z);
        if (x > y)
            std::swap(x, y);

        if (mp.count({x, y, z}))
            return mp[{x, y, z}];

        std::cout << "? " << x << ' ' << y << ' ' << z << std::endl;
        
        int r; std::cin >> r;

        std::vector<std::pair<int, int>> pr(r);
        for (auto &[a, b]: pr) {
            std::cin >> a >> b;

            if (a > b)
                std::swap(a, b);
        }

        return mp[{x, y, z}] = pr;
    };

    int tt, k; std::cin >> tt >> k;
    while (tt--) {
        mp.clear();


        int n; std::cin >> n;
        if (n != 400 || k != 4500) {
            exit(0);
        }

        std::vector<bool> used(n);
        std::vector<int> x(n);
        for (int i = 200; i < n; ++i) {
            x[i] = i;
        }

        for (int i = 0; i < 200; ++i) {
            auto got = Ask(i, 200, n - 1);

            if (got.size() == 2) {
                x[100] = i;
            } else {
                if (got.back() == std::pair{i, 200}) {
                    int l = 201, r = n - 1, ans = -1;
                    while (true) {
                        int m = l + r >> 1;

                        got = Ask(m, i, 200);
                        if (got.size() == 2) {
                            ans = m;

                            break;
                        }

                        if (got.back() == std::pair{i, 200}) {
                            r = m - 1;
                        } else {
                            l = m + 1;
                        }
                    }

                    x[400 - ans] = i;
                } else {
                    int l = 200, r = n - 2, ans = -1;
                    while (true) {
                        int m = l + r >> 1;

                        got = Ask(m, i, n - 1);
                        if (got.size() == 2) {
                            ans = m;

                            break;
                        }

                        if (got.back() == std::pair{i, n - 1}) {
                            l = m + 1;
                        } else {
                            r = m - 1;
                        }
                    }

                    x[(n - 1) - ans - 1] = i;
                }
            }
        }

        std::cout << "! ";
        for (auto u: x) {
            std::cout << u << ' ';
        }

        std::cout << std::endl;
    }
    return 0;
}
