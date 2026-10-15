#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline void solve() {
    int n; std::cin >> n;

    std::string s; std::cin >> s;

    int sum = 0;
    std::vector<int> pos, ps;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            sum++;
            ps.emplace_back(i);
        } else {
            sum--;
        }

        if (sum < 2) {
            pos.emplace_back(i);
        }
    }

    int nps = 0, npos = 0, nw = (int)ps.size() - 1, valsum = 0;
    int res = 0;
    for (int l = n - 1; l >= 0; --l) {
        if (s[l] == ')') {
            add_self(res, binpow(2, n - l - 1));
            continue;
        }

        int i = std::lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        int j = std::upper_bound(ps.begin(), ps.end(), l) - ps.begin();
        int k = std::upper_bound(ps.begin(), ps.end(), (i == pos.size() ? n + 5 : pos[i])) - ps.begin();

        int osum = valsum;
        {
            int c = binpow(2, k - j), cn = k - j;

            add_self(c, MOD - 1);

            add_self(res, mul(c, binpow(2, n - l - 1 - cn)));
            add_self(valsum, mul(c, binpow(2, n - l - 1 - cn)));
        }

        add_self(res, binpow(2, (i == pos.size() ? n - 1 : pos[i]) - l));
        add_self(valsum, binpow(2, (i == pos.size() ? n - 1 : pos[i]) - l));
        
        if (k < ps.size()) {
            add_self(res, mul(osum, binpow(2, pos[i] - l)));
            add_self(valsum, mul(osum, binpow(2, pos[i] - l)));
        }

        std::cout << "RES "<< res << '\n';
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
