/**
 *    author:  feev1x
 *    created: 23.07.2025 19:12:06
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, N = 7e5 + 5;

int p2[N], ans[N];

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    if (a == 2)
        return n >= 0 ? p2[n] : 0;

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

inline int divide(int a, int pw) {
    return mul(a, ans[pw]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    p2[0] = 1;
    
    int n, k; std::cin >> n >> k;

    std::string s; std::cin >> s;

    int all = 1;
    std::vector<int> cost(n + 1), idx(26);
    std::vector<std::vector<int>> pos(26);
    for (int i = 1; i <= n; ++i) {
        std::cin >> cost[i], p2[i] = mul(p2[i - 1], 2);

        pos[s[i - 1] - 'a'].emplace_back(i);
    }


    p2[n + 1] = mul(p2[n], 2);

    for (int i = 0; i <= n + 1; ++i) {
        ans[i] = binpow(binpow(2, i) - 1, MOD - 2);
    }

    for (int i = 0; i < 26; ++i) {
        if (pos[i].empty())
            continue;

        all = mul(all, binpow(2, pos[i].size()) - 1);
    }

    std::vector<int> pfx(n + 2), zer(n + 2);
    for (int l = 1; l <= n; ++l) {
        int sum = all, pw = 0;

        for (int j = 0; j < 26; ++j)
            while (idx[j] < pos[j].size() && pos[j][idx[j]] < l)
                idx[j]++;


        std::vector<int> ps(26);

        std::iota(ps.begin(), ps.end(), 0);

        std::sort(ps.begin(), ps.end(), [&](int i, int j) {
            if (idx[i] >= (int)pos[i].size())
                return false;

            if (idx[j] >= (int)pos[j].size())
                return true;


            return pos[i][idx[i]] < pos[j][idx[j]];
        });

        int POS = 29;
        if (l > 1) {
            POS = s[l - 2] - 'a';

            sum = divide(sum, pos[POS].size());

            sum = mul(sum, pos[POS].size() - 1);
        }

        int old = l, val = -1;
        for (auto r: ps) {
            if (idx[r] >= pos[r].size())
                break;

            r = pos[r][idx[r]];

            if (val != -1) {
                int sz = r - old - 1;

//                std::cout << old - l + 1 << ' ' << mul(binpow(2, pw - 1), sum) << '\n';
//                std::cout << r - l << ' ' << -mul(binpow(2, pw - sz - 1), sum) << '\n';

                if (pw - sz - 1 < 0) {
                    add_self(pfx[old - l + 1], mul(binpow(2, pw - 1), sum));

                    if (r - l - 1 >= old - l + 1 && pw - 1 >= 0)
                        add_self(zer[r - l - 1], sum);
                } else {
                    add_self(pfx[old - l + 1], mul(binpow(2, pw - 1), sum));
                    add_self(pfx[r - l], -mul(binpow(2, pw - sz - 1), sum));
                }

                pw = pw - sz - 1;

                if (pw < 0) {
                    pw = 0;
                }

                int vl = s[r - 1] - 'a';
                val = s[r - 1] - 'a';
                sum = divide(sum, pos[vl].size() - (vl == POS ? 1 : 0));
                
                if (binpow(2, pos[vl].size() - 1 - (vl == POS ? 1 : 0)) - 1 > 0) {
                    sum = mul(sum, binpow(2, pos[vl].size() - 1 - (vl == POS ? 1 : 0)) - 1);


                    if (pw - 1 < 0) {
                        add_self(pfx[r - l], mul(binpow(2, pw), sum));

                        if (pw >= 0)
                            add_self(zer[r - l], sum);
                    } else {
                        add_self(pfx[r - l], mul(binpow(2, pw), sum));
                        add_self(pfx[r - l + 1], -mul(binpow(2, pw - 1), sum));
                    }
//                    std::cout << r - l << ' ' << mul(binpow(2, pw), sum) << '\n';
//                    std::cout << r - l + 1 << ' ' << -mul(binpow(2, pw - 1), sum) << '\n';

                    sum = divide(sum, pos[vl].size() - 1 - (vl == POS ? 1 : 0));
                }

                pw += pos[val].size() - (val == POS ? 1 : 0) - 1;

                old = r;
            } else {
                old = r;
                val = s[r - 1] - 'a';

                sum = divide(sum, pos[val].size() - (val == POS ? 1 : 0));

                pw += pos[val].size() - (val == POS ? 1 : 0) - 1;
            }
        }

        if (pw - (n - old + 1) < 0) {
            add_self(pfx[old - l + 1], mul(binpow(2, pw), sum));

            if (pw >= 0)
                add_self(zer[n - l + 1], sum);
        } else {
            add_self(pfx[old - l + 1], mul(binpow(2, pw), sum));
            add_self(pfx[n - l + 2], -mul(binpow(2, pw - (n - old + 1)), sum));
        }

//        std::cout << old - l + 1 << ' ' << mul(binpow(2, pw), sum) << '\n';
//        std::cout << n - l + 2 << ' ' << -mul(binpow(2, pw - (n - old + 1)), sum) << '\n';
    }

//    std::cout << "SSS\n";
    int res = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum = mul(sum, (MOD + 1) / 2);

        add_self(sum, pfx[i]);
//        std::cout << sum << ' ' << pfx[i] << '\n';

        add_self(res, mul(cost[i], sum));

        add_self(sum, -zer[i]);
    }

    std::cout << res << '\n';
    return 0;
}
