/**
 *    author:  feev1x
 *    created: 21.04.2025 10:51:35
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int k, x, y; std::cin >> k >> x >> y;

    int dis = std::abs(x) + std::abs(y), nw = dis % k, fx = 0, fy = 0;

    std::vector<std::pair<int, int>> res;
    if (k & 1) {
        if (nw % 2 == 0) {
            if (nw > 2) {
                fx = -((2 * k - nw) / 2), fy = k + fx;
            }
        } else {
            fy = ((k + nw) / 2), fx = -k + fy;
        }
    } else {
        if (nw & 1) {
            std::cout << "-1\n";

            exit(0);
        }

        fy = ((k + nw) / 2), fx = -k + fy;
    }


    if (x < 0) {
        fx = -fx;
    }

    if (std::abs(x) < fy && std::abs(y) < fy) {
        if (y < 0) {
            res.emplace_back(0, k);
            fy = k - fy;
        } else {
            res.emplace_back(0, -k);
            fy = -k + fy;
        }
    } else {
        if (y < 0) {
            fy = -fy;
        }

        if (std::abs(y) < std::abs(fy)) {
            std::swap(fy, fx);

            fx = std::abs(fx);
            fy = std::abs(fy);

            if (x > 0) {
                fx = -fx;
            }

            if (y < 0) {
                fy = -fy;
            }
        }
    }

    if (fx || fy) {
        res.emplace_back(fx, fy);
    }

    assert((std::abs(x - fx) + std::abs(y - fy)) % k == 0);
    while (std::abs(x - fx) > k) {
        if (fx > x) {
            fx -= k;
        } else {
            fx += k;
        }

        res.emplace_back(fx, fy);
    }

    while (std::abs(y - fy) > k) {
        if (fy > y) {
            fy -= k;
        } else {
            fy += k;
        }

        res.emplace_back(fx, fy);
    }
    
    if (fx != x || fy != y) {
        res.emplace_back(x, y);
    }

    std::cout << res.size() << '\n';
    for (auto [u, v]: res) {
        std::cout << u << ' ' << v << '\n';
    }

    return 0;
}
