#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
    int n, q; std::cin >> n >> q;

    std::string s; std::cin >> s;

    int l = -1;

    int64_t sum = 0;
    int qc = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'X') {
            sum += 10;
        } else if (s[i] == 'V') {
            sum += 5;
        } else if (s[i] == 'I') {
            if (i + 1 == n || s[i + 1] == 'I') {
                sum += 1;
            } else {
                sum -= 1;
            }
        } else {
            qc++;
        }
    }

    std::vector<int> c2, c1, c0;
    for (int i = 0; i < n; ++i) {
        bool old = i ? s[i - 1] == '?' : false;

        if (s[i] == '?' && !old) {
            l = i;
        } else if (s[i] != '?' && old) {
            if (s[i] == 'I' && l && s[l - 1] == 'I') {
                c2.emplace_back(i - l);
            } else if (s[i] == 'I' || l && s[l - 1] == 'I') {
                c1.emplace_back(i - l);
            } else {
                c0.emplace_back(i - l);
            }
        }
    }

    if (s.back() == '?') {
        if (l && s[l - 1] == 'I') {
            c2.emplace_back(n - l);
        } else {
            c1.emplace_back(n - l);
        }
    }

    int cg = 0, cm = 0;
    for (int i = 0; i < c0.size(); ++i) {
        cg += (c0[i] + 1) / 2;

        if (c0[i] % 2 == 0) {
            cm++;
        }
    }

    for (int i = 0; i < c1.size(); ++i) {
        cg += c1[i] / 2;

        if ((c1[i] - 1) % 2 == 0) {
            cm++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < c2.size(); ++i) {
        cg += (c2[i] - 1) / 2;

        if ((c2[i] - 2) % 2 == 0) {
            cm++;
        } else {
            if (c2[i] > 3)
                cnt++;
        }
    }

    while (q--) {
        int cx, cv, ci; std::cin >> cx >> cv >> ci;

        if (ci >= qc) {
            cx = cv = 0;
            ci = qc;
        } else if (ci + cv >= qc) {
            cx = 0;
            cv = std::min(cv, std::max((int64_t)0, qc - ci));
        } else {
            cx = std::min(cx, std::max((int64_t)0, qc - ci - cv));
        }

        int64_t res = 0;

        if (cg >= ci) {
            res -= ci;
            ci = 0;
        } else {
            res -= cg;
            ci -= cg;
        }

        if (cm >= ci) {
            res += ci;
            ci = 0;
        } else {
            res += cm;
            ci -= cm;
        }

        res += ci * 3;

        std::cout << sum + cx * 10 + cv * 5 + res << '\n';
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
