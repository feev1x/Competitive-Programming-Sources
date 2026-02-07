/**
 *    author:  feev1x
 *    created: 15.11.2025 18:05:59
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; int64_t x, y; std::cin >> n >> x >> y;

    std::vector<int64_t> a(n);

    int64_t mx = -1, mn = -1, cnt = 0;

    bool flag = true;
    int nw = 0;
    for (auto &u: a) {
        std::cin >> u;

        if (mx == -1)
            mn = u * x, mx = u * y, cnt += u;
        else {
            int64_t val = u * x;

            if (val > mn) {
                if ((val - mn) % (y - x) != 0)
                    flag = false;
                else
                    mn = val;
            } else {
                if ((mn - val) % (y - x) != 0)
                    flag = false;
            }

            if (mx > u * y) {
                cnt -= ((mx - u * y) / (y - x)) * nw;
                cnt += u;
                mx = u * y;
            } else
                cnt += (mx - val) / (y - x);
        }


        nw++;
    }

    if (mx < mn || !flag) {
        std::cout << "-1\n";
        exit(0);
    }

    std::cout << cnt << '\n';
    return 0;
}
