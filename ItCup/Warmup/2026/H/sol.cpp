#include <bits/stdc++.h>

#define int int64_t

constexpr int INF = 1e18;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    auto Check = [&](int x) {
        if (x % 4 == 0 && x % 100 || x % 400 == 0) return true;
        return false;
    };
    std::array<std::array<int, 13>, 2> lim;
    for (int i = 1; i < 8; ++i) lim[0][i] = lim[1][i] = 30 + (i & 1);
    for (int i = 8; i <= 12; ++i) lim[0][i] = lim[1][i] = 30 + !(i & 1);
    lim[0][2] = 28;
    lim[1][2] = 29;
    auto Dis = [&](int d, int m, int y) {
        bool val = Check(y);
        if (m > 12 || d <= 0 || m <= 0 || lim[val][m] < d || y < 1700 || y > 2299) return INF;
int d1 = (2000) * 365 + 2000 / 4 - 2000 / 100 + 2000 / 400;

int d2 = (d - 1)
       + (y - 1) * 365
       + (y - 1) / 4
       - (y - 1) / 100
       + (y - 1) / 400;
        for (int i = 1; i < m; ++i) d2 += lim[Check(y)][i];
        return d2 - d1 + 1;
    };
    std::string s; std::getline(std::cin, s);
    std::string t;
    std::vector<int> res;
    bool raz = false;
    int cnt = 0;
    for (auto u: s) { if (std::isdigit(u)) t += u; else raz = true, cnt++; }
    if (!raz) {
        std::swap(s, t);
        for (int i = 0; i + 2 < s.size(); ++i)
            for (int j = i + 1; j + 1 < s.size(); ++j) {
                std::vector<std::pair<int, int>> a;
                int num = 0, sz = 0;
                for (int idx = 0; idx < s.size(); ++idx) {
                    num = num * 10 + s[idx] - '0';
                    sz++;
                    if (idx == i || idx == j) a.emplace_back(num, sz), num = 0, sz = 0;
                }
                a.emplace_back(num, sz);
                std::sort(a.begin(), a.end());
                do {
                    if (a[0].second > 2 || a[1].second > 2 || a[2].second == 3 || a[2].second > 4) continue;
                    if (a[2].first < 100 && a[2].second < 3) {
                        for (int i = 17; i <= 22; ++i) {
                            int got = Dis(a[0].first, a[1].first, i * 100 + a[2].first);
                            if (got != INF) res.emplace_back(got);
                        }
                    } else {
                        int got = Dis(a[0].first, a[1].first, a[2].first);
                        if (got != INF) res.emplace_back(got);
                    }
                } while (std::next_permutation(a.begin(), a.end()));
            }
        std::sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        std::cout << res.size() << '\n';
        for (auto u: res) std::cout << u << '\n';
    } else {
            std::vector<std::pair<int, int>> a;
        int num = 0, sz = 0;
        bool flag = false;
        for (auto u: s) {
            if (u == ' ') continue;
            if (std::isdigit(u)) num = num * 10 + u - '0', flag = true, sz++;
            else if (flag) a.emplace_back(num, sz), flag = false, num = 0, sz = 0;
        }
        if (flag) a.emplace_back(num, sz), flag = false, num = 0;
        std::sort(a.begin(), a.end());
        do {
            if (a[0].second > 2 || a[1].second > 2 || a[2].second == 3 || a[2].second > 4) continue;
            if (a[2].first < 100 && a[2].second < 3) {
                for (int i = 17; i <= 22; ++i) {
                    int got = Dis(a[0].first, a[1].first, i * 100 + a[2].first);
                    if (got != INF) res.emplace_back(got);
                }
            } else {
                int got = Dis(a[0].first, a[1].first, a[2].first);
                if (got != INF) res.emplace_back(got);
            }
        } while (std::next_permutation(a.begin(), a.end()));
        std::sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        std::cout << res.size() << '\n';
        for (auto u: res) std::cout << u << '\n';
    }
    return 0;
}
