#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n), o, e;
    int mno = n, mxo = 1, mne = n, mxe = 1;
    for (auto &u: a) {
        std::cin >> u;
        if (u & 1) mno = std::min(mno, u), mxo = std::max(mxo, u), o.emplace_back(u);
        else mne = std::min(mne, u), mxe = std::max(mxe, u), e.emplace_back(u);
    }
    bool flag = true;
    { // even
        int mx = -1;
        for (auto u: e) {
            if (u >= mx) { mx = u; continue; }
            if (mno < u || mxo > mx) { continue; }
            flag = false;
        }
    }
    { // odd 
        int mx = -1;
        for (auto u: o) {
            if (u >= mx) { mx = u; continue; }
            if (mne < u || mxe > mx) { continue; }
            flag = false;
        }
    }
    std::cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
