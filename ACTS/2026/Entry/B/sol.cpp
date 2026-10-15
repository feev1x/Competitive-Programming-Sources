#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> t(n);
    for (auto &u: t) std::cin >> u;
    std::string s; std::cin >> s;
    int lmin = -1e9, rmin = 1e9, lmax = -1e9, rmax = 1e9;
    bool ls = 0;
    for (int i = 4; i < n; ++i) {
        if (s[i - 1] == '0') {
            int mx = -1e9;
            for (int j = i - 4; j <= i; ++j) mx = std::max(mx, t[j]);
            if (s[i] == '1') {
                lmin = std::max(lmin, mx + 1);
            } else {
                bool flag = true;
                for (int j = i - 4; j <= i; ++j) if (s[j] != s[i]) flag = false;
                if (flag) rmin = std::min(rmin, mx);
            }
        } else if (s[i - 1] == '1') {
            int mn = 1e9;
            for (int j = i - 4; j <= i; ++j) mn = std::min(mn, t[j]);
            if (s[i] == '0') {
                rmax = std::min(rmax, mn - 1);
            } else {
                bool flag = true;
                for (int j = i - 4; j <= i; ++j) if (s[j] != s[i]) flag = false;
                if (flag) lmax = std::max(lmax, mn);
            }
        }
    }
    int tmin = rmin, tmax = lmax;
    if (tmin > tmax) {
        if (lmin <= lmax && lmax <= rmin) {
            std::cout << lmax << ' ' << lmax << '\n';
        } else if (lmin <= rmax && rmax <= rmin) {
            std::cout << rmax << ' ' << rmax << '\n';
        } else if (lmax <= lmin && lmin <= rmax) {
            std::cout << lmin << ' ' << lmin << '\n';
        } else if (lmax <= rmin && rmin <= rmax) {
            std::cout << rmin << ' ' << rmin << '\n';
        }
    } else {
        std::cout << tmin << ' ' << tmax << '\n';
    }
    return 0;
}
