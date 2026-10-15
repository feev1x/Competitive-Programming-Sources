#include <bits/stdc++.h>

constexpr int N = 25;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n), val(n), cnt(N);
    std::vector<std::vector<int>> pos(N);
    std::vector<int64_t> sum(N);
    int idx = 0;
    for (auto &u: a) {
        std::cin >> u;
        for (int i = 0; i < N; ++i) if (u >> i & 1) { val[idx] = i; break; }
        cnt[val[idx]]++;
        sum[val[idx]] += u;
        pos[val[idx]].emplace_back(idx);
        idx++;
    }
    int64_t res = 0;
    for (int i = 0; i < n; ++i) {
        int64_t cn = 0, sm = 0;
        for (int j = val[i] + 1; j < N; ++j) cn += cnt[j], sm += sum[j];
        res += (sm >> val[i]) + (a[i] >> val[i]) * cn;
    }
    for (int j = 0; j < N; ++j) {
        std::vector<std::map<int, int64_t>> sm(N), cn(N);
        for (auto i: pos[j]) {
            int vl = a[i] >> j, vlg = 1;
            for (int k = 0; k < N; ++k) {
                int vll = vl & ((1 << k + 1) - 1);
                sm[k][vll] += vl;
                cn[k][vll]++;
                if (k > 0) vlg |= (1 << k) * (!(vl >> k & 1)), res -= (sm[k][vlg] + cn[k][vlg] * vl) >> k;
                res += (sm[k][vlg] + cn[k][vlg] * vl) >> (k + 1);
            }
        }
    }
    std::cout << res << '\n';
    return 0;
}
