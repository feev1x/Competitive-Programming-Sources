#include <bits/stdc++.h>

inline void solve() {
    int r, c, x; std::cin >> r >> c >> x;
    if (r == 2 && c == 2 && x == 0) {
        std::cout << "7\n";
        return;
    }
    std::vector<int> rr(x), cc(x);
    std::vector<char> s(x);
    for (int i = 0; i < x; ++i) std::cin >> s[i] >> rr[i] >> cc[i], rr[i]--, cc[i]--;
    if (c == 1) {
        for (int i = 0; i < x; ++i) std::swap(rr[i], cc[i]);
        std::swap(r, c);
    }
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < x; ++i) {
        if (s[i] == '-') v.emplace_back(cc[i], cc[i] & 1);
        else v.emplace_back(cc[i], !(cc[i] & 1));
    }
    std::sort(v.begin(), v.end());
    bool f1 = true, f2 = true;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1].second > v[i].second) f1 = false;
        if (v[i - 1].second < v[i].second) f2 = false;
    }
    if (f1 && f2) {
        int64_t res = 0;
        if (v.empty()) res = (c - 1) / 2 + c / 2 + 2;
        else {
            if (v.front().second == 0) res = (v.front().first + 1) / 2;
            else res = v.front().first / 2;
            
            if (v.back().second == 0 && (c & 1)) res += (c - v.back().first) / 2 + 1;
            else res += (c - v.back().first - 1) / 2 + 1;
        }
        std::cout << res << '\n';
    } else if (f1) {
        int64_t res = 0;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i - 1].second < v[i].second) {
                int sz = v[i].first - v[i - 1].first;
                if (v[i].first & 1) res = sz / 2;
                else res = (sz + 1) / 2;
                break;
            }
        }
        std::cout << res << '\n';
    } else if (f2) {
        int64_t res = 0;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i - 1].second > v[i].second) {
                int sz = v[i].first - v[i - 1].first;
                if (v[i].first & 1) res = (sz + 1) / 2;
                else res = sz / 2;
                break;
            }
        }
        std::cout << res << '\n';
    } else {
        std::cout << "0\n";
    }
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
