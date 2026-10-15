#include <bits/stdc++.h>

inline int ask(int i, int j) { std::cout << "? " << i << ' ' << j << std::endl; int got; std::cin >> got; return got; }

inline void solve() {
    int n; std::cin >> n;
    int l = n + 1, r = -1, ls = n + 1;
    std::vector<int> val(n);
    for (int i = 1; i < n; ++i) {
        val[i] = ask(i, i + 1);
        if (val[i] == 1) ls = i;
        else r = i, l = ls;
    }
    if (l > r) {
        std::cout << "! -1" << std::endl;
        return;
    }
    std::vector<int> p(n + 1), vl;
    std::iota(p.begin(), p.end(), 0);
    vl = p;
    int nw = l + 1, pos = n;
    for (int i = r + 1; i <= n; ++i) {
        if (ask(l, i) == 1) {
            if (ask(nw, i) == 0) nw = i;
            break;
        }
    }
    for (int i = r; i > l + 1; --i) {
        if (ask(l, i) == 1) {
            if (ask(nw, i) == 0) nw = i;
            break;
        }
    }
    p[l] = nw;
    vl[nw] = l;
    vl[l] = nw;
    int i = l + 1, j = n, idx = n;
    while (i < r + 1 && j >= r + 1) {
        if (ask(vl[i], vl[j]) == 1) p[idx] = vl[j--];
        else p[idx] = vl[i++];
        idx--;
    }
    while (i < r + 1) p[idx--] = vl[i++];
    while (j >= r + 1) p[idx--] = vl[j--];
    std::cout << '!';
    for (int i = 1; i <= n; ++i) std::cout << ' ' << p[i];
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
