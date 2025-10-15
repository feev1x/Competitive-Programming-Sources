/**
 *    author:  feev1x
 *    created: 09.09.2025 10:43:02
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }
    
    return res;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;

    if (a < 0)
        a += MOD;
}

struct Sptable {
    std::vector<std::vector<int>> sp;
    std::vector<int> lg;
    int n;

    Sptable(std::vector<int> a) : n(a.size() - 1) {
        lg.resize(n + 1);

        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;

        sp.resize(lg[n] + 1, std::vector<int>(n + 1));

        sp[0] = a;

        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j + (1 << i) - 1 <= n; ++j)
                sp[i][j] = std::max(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
    }

    inline int get(int l, int r) {
        int i = lg[r - l + 1];

        return std::max(sp[i][l], sp[i][r - (1 << i) + 1]);
    }
};

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        r = n - r + 1;
        for (; r <= n; r += r & -r)
            p[r] = std::max(p[r], x);
    }

    inline int get(int r) {
        r = n - r + 1;

        int res = 0;

        for (; r >= 1; r -= r & -r)
            res = std::max(res, p[r]);

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> p(n + 1), lb(n + 1), pos(n + 1), llb(n + 1), fac(n + 1), inv(n + 1);
    std::stack<int> stk;
    Bit bit(n);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        fac[i] = mul(i, fac[i - 1]);

        pos[p[i]] = i;

        while (stk.size() && p[stk.top()] < p[i])
            stk.pop();

        if (stk.size())
            lb[i] = stk.top();

        stk.emplace(i);
    }

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i >= 1; --i)
        inv[i] = mul(inv[i + 1], fac[i + 1]);

    auto C = [&](int N, int K) {
        return mul(fac[N], mul(inv[K], inv[N - K]));
    };

    for (int i = 1; i <= n; ++i) {
        llb[i] = bit.get(p[i]);

        bit.update(p[i], lb[i]);
    }

    Sptable sp(llb);

    int q; std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;

        int mxs = -1, mx = -1;

        bool bad = false;
        for (int i = l; i <= r; ++i) {
            mx = std::max(mx, p[i]);

            if (l <= lb[i])
                mxs = std::max(mxs, p[i]);

            if (llb[i] >= l)
                bad = true;
        }

        if (bad) {
            std::cout << "0\n";
            continue;
        }

        if (r - l + 1 == n) {
            std::cout << "1\n";
            continue;
        }

        int mn = n + 1;
        for (int i = 1; i <= n; ++i)
            if (pos[i] < l || r < pos[i]) {
                mn = i;
                break;
            }

        if (mn < mxs) {
            std::cout << "0\n";
            continue;
        }

        int cntl = 0, cntr = 0;
        for (int i = 1; i < mx; ++i)
            if (pos[i] < l || r < pos[i])
                cntl++;

        for (int i = mx + 1; i <= n; ++i)
            if (pos[i] < l || r < pos[i])
                cntr++;

        int res = 1;
        for (int i = 1; i <= cntr; ++i)
            add_self(res, mul(cntl + i - 1, cntr - i + 1));

        std::cout << res << '\n';
    }
    return 0;
}
