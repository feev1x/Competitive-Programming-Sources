/**
 *    author:  feev1x
 *    created: 10.02.2025 17:00:56
**/
#include <bits/stdc++.h>

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void turn_on(int r) {
        for (; r <= n; r += r & -r) {
            p[r]++;
        }
    }

    inline void turn_off(int r) {
        for (; r <= n; r += r & -r) {
            p[r]--;
        }
    }

    inline int get(int r) {
        int res = 0;
        
        for (; r > 0; r -= r & -r) {
            res += p[r];
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    Bit bit(n); 
    std::vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        bit.turn_on(i);
    }

    auto Find = [&](int x) {
        int l = 1, r = n, ans = -1;

        while (l <= r) {
            int m = l + r >> 1;

            if (bit.get(m) >= x) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }

        return ans;
    };

    for (int i = n; i >= 1; --i) {
        int j = Find(p[i]);

        assert(j != -1);

        a[j] = i;

        bit.turn_off(j);
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << a[i] << " \n"[i == n];
    }
    return 0;
}
