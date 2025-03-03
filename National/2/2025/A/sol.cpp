/**
 *    author:  feev1x
 *    created: 22.02.2025 14:02:08
**/
#include <bits/stdc++.h>

#define int64_t __int128

inline __int128 read() {
    char ch = getchar();
    __int128 x = 0;

    while (ch < '0' || ch > '9') {
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';

        ch = getchar();
    }

    return x;
}

inline void print(__int128 x) {
    if (x < 10) {
        putchar(x + '0');

        return;
    }
    
    print(x / 10);

    putchar(x % 10 + '0');
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n = read(); 

    std::vector<int64_t> a(n);
    for (auto &u: a) {
        u = read();
    }

    int64_t res = -1;
    for (int64_t md = 0; md < n; ++md) {
        int64_t _l = 0, _r = 1e16, _ans = -1;

        while (_l <= _r) {
            int64_t _m = _l + _r >> 1;
            int64_t op = _m * n + md;
            bool flag = true;
            int64_t cnt = 0;

            for (int i = 0; i < n; ++i) {
                int64_t l = 0, r = op, ans = -1;

                while (l <= r) {
                    int64_t m = l + r >> 1;

                    if (a[i] - m * n + op - m >= n) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                        
                        ans = m;
                    }
                }

                cnt += ans;

                if (ans == -1 || cnt > op) {
                    flag = false;

                    break;
                }
            }

            if (flag) {
                _r = _m - 1;

                _ans = op;
            } else {
                _l = _m + 1;
            }
        }

        if (_ans == -1) {
            continue;
        }

        if (res == -1 || _ans < res) {
            res = _ans;
        }
    }

    print(res);

    putchar('\n');
    return 0;
}
