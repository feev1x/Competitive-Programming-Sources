#include <bits/stdc++.h>


struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        for (; r <= n; r += r & -r) {
            p[r] += x;
        }
    }

    inline int get(int r) {
        int res = 0;

        for (; r > 0; r -= r & -r) {
            res += p[r];
        }

        return res;
    }

    inline int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::string s; std::cin >> s;

    std::vector<int64_t> sum(2 * n + 5);
    sum[1] = 1;
    for (int i = 3; i <= 2 * n + 4; i += 2) {
        sum[i] = sum[i - 2] + i;
    }

    Bit bit(n);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+') {
            bit.update(i + 1, 1);
        }
    }

    int q; std::cin >> q;
    while (q--) {
        int type; std::cin >> type;

        if (type == 2) {
            int l, r; std::cin >> l >> r;

            int64_t i = bit.get(l, r);

            int64_t cu = r - l + 1 - i;

            // (2 * (i - 1) + 1) = cnt of sec
            // (2 * (i - 1) + 3) = cnt of fir
            std::cout << i * (2 * (i - 1) + 1 + cu * 2) + (cu * 2 + 1) * (2 * (i - 1) + 3 + cu * 2) + sum[(2 * (i - 1) + 1) + cu * 2] - sum[1 + cu * 2] + 1 + cu * 2 << '\n';
        } else {
            int i; std::cin >> i; i--;

            if (s[i] == '+') {
                s[i] = '*';
                bit.update(i + 1, -1);
            } else {
                s[i] = '+';
                bit.update(i + 1, 1);
            }
        }
    }
}
