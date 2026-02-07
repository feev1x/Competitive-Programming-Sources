#include <bits/stdc++.h>

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int n) : n(n) {
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
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    auto ab = a;

    std::sort(ab.begin(), ab.end());
    ab.erase(unique(ab.begin(), ab.end()), ab.end());

    for (int i = 1; i <= n; ++i) {
        a[i] = std::lower_bound(ab.begin(), ab.end(), a[i]) - ab.begin();
    }

    int sq = std::sqrt(n) + 1;
    for (int i = 1; i <= n; ++i) {
        b[i] = i / sq;
    }

    std::vector<int> bl(b[n] + 1, -1), br(b[n] + 1);
    for (int i = 1; i <= n; ++i) {
        if (bl[b[i]] == -1) {
            bl[b[i]] = i;
            br[b[i]] = i;
        } else {
            br[b[i]] = i;
        }
    }

    std::vector<std::vector<int>> qq(n + 1), B(b[n] + 1, std::vector<int>(n + 1)), SQ(b[n] + 1, std::vector<int>(b[n] + 1));
    std::vector<int> ans(q + 1), qr(q + 1), qk(q + 1);
    for (int i = 1; i <= q; ++i) {
        int l, r, k; std::cin >> l >> r >> k;

        qr[i] = r;
        qk[i] = k;
        qq[l].emplace_back(i);
    }

    auto Update = [&](int i, int l, int r, int x) {
        if (b[l] == b[r]) {
            for (int j = l; j <= r; ++j) {
                B[i][j] += x;
            }

            return;
        }

        for (int bn = b[l] + 1; bn < b[r]; ++bn) {
            SQ[i][bn] += x;
        }

        for (int j = l; b[j] == b[l]; ++j) {
            B[i][j] += x;
        }

        for (int j = r; b[j] == b[r]; --j) {
            B[i][j] += x;
        }
    };

    std::vector<int> next(n + 1, n + 1), pos(n + 1, -1);
    for (int i = n; i >= 1; --i) {
        if (pos[a[i]] != -1) {
            next[i] = pos[a[i]];
        }

        pos[a[i]] = i;
    }

    std::vector<int> nl(n + 1, n + 1), nr(n + 1, n + 1);
    for (int i = 1; i <= n; ++i) {
        if (pos[i] == -1) {
            continue;
        }

        int l = pos[i], r = next[pos[i]] - 1;

        nl[i] = l, nr[i] = r + 1;
        
        Update(b[i], l, r, 1);
    }

    for (int l = 1; l <= n; ++l) {
        for (auto i: qq[l]) {
            int nd = -1;

            int sum = 0;
            for (int bn = 0; bn <= b[n]; ++bn) {
                sum += B[bn][qr[i]] + SQ[bn][b[qr[i]]];

                if (sum >= qk[i]) {
                    nd = bn;
                    break;
                }
            }

            if (nd == -1) {
                ans[i] = -1;
                continue;
            }

            sum -= B[nd][qr[i]] + SQ[nd][b[qr[i]]];
            for (int j = bl[nd]; j <= br[nd]; ++j) {
                if (nl[j] <= qr[i] && qr[i] < nr[j]) {
                    sum++;

                    if (sum == qk[i]) {
                        ans[i] = ab[j];
                        break;
                    }
                }
            }
        }

        Update(b[a[l]], nl[a[l]], nr[a[l]] - 1, -1);
        if (next[l] == n + 1) {
            nl[a[l]] = next[nl[a[l]]];
            continue;
        }

        nl[a[l]] = next[nl[a[l]]];
        nr[a[l]] = next[nr[a[l]]];

        Update(b[a[l]], nl[a[l]], nr[a[l]] - 1, 1);
    }

    for (int i = 1; i <= q; ++i) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}
