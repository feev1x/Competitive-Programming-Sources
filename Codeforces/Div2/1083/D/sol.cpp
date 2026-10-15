#include <bits/stdc++.h>

struct Bit {
    std::vector<int> p;
    int n; bool rev;

    Bit(int n, bool rev) : n(n), rev(rev) {
        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        if (rev) {
            r = n - r + 1;
        }

        for (; r <= n; r += r & -r) {
            p[r] = std::max(p[r], x);
        }
    }

    inline int get(int r) {
        if (rev) {
            r = n - r + 1;
        }

        int res = 0;
        for (; r > 0; r -= r & -r) {
            res = std::max(res, p[r]);
        }

        return res;
    }
};

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }
    
    std::vector<int> dpl(n, -1), dpr(n, -1);

    {
        std::vector<int> ll;

        int op = 0;
        for (int i = 0; i < n; ++i) {
            if (ll.empty()) {
                ll.emplace_back(a[i]);
                dpl[i] = 0;
                continue;
            }

            if (ll.back() > a[i]) {
                ll.emplace_back(a[i]);
                dpl[i] = op;
                continue;
            }

            int nw = i + 1;

            while (nw < n && a[nw] > a[nw - 1]) {
                nw++;
                op++;
            }


            if (nw >= n) {
                break;
            }

            while (ll.size() && ll.back() < a[nw - 1]) {
                ll.pop_back();
                op++;
            }

            dpl[nw - 1] = op;

            ll.emplace_back(a[nw - 1]);
            i = nw - 1;
        }
    }

    {
        std::vector<int> ll;

        int op = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (ll.empty()) {
                ll.emplace_back(a[i]);
                dpr[i] = 0;
                continue;
            }

            if (ll.back() > a[i]) {
                ll.emplace_back(a[i]);
                dpr[i] = op;
                continue;
            }

            int nw = i - 1;

            while (nw >= 0 && a[nw] > a[nw + 1]) {
                nw--;
                op++;
            }

            if (nw < 0) {
                break;
            }

            while (ll.size() && ll.back() < a[nw + 1]) {
                ll.pop_back();
                op++;
            }

//            dpr[nw + 1] = op;

            ll.emplace_back(a[nw + 1]);
            i = nw + 1;
        }
    }

    int res = n + 5;
    for (int i = n - 1; i >= 0; --i) {
        if (dpl[i] == -1 || dpr[i] == -1) {
            continue;
        }

//        std::cout << i << ' ' << dpr[i] << ' ' << dpl[i] << '\n';
        res = std::min(res, dpr[i] + dpl[i]);
    }

    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
