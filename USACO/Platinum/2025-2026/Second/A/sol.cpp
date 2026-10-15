#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
constexpr int N = 1002;
int a[N], n, c;
int str;
bool stop;
inline int Dis(int i, int j) { return std::min(std::abs(a[i] - a[j]), c - std::abs(a[i] - a[j])); }
inline int Ds(int i, int j) { return (j - i + n) % n; }
inline int Get(int m, int st) {
    if (st > n) return 0;
    int cnt = 0;
    for (int i = str, j = st; i < st; ++i) {
        while (Dis(i, j) < m) {
            if (Dis(i, j) >= Dis(i, (j + 1) % n) || j == 0) break;
            if (cnt == 0) return 0;
            j = (j + 1) % n;
        }
        if (j == 0) break;
        if (Dis(i, j) >= m) {
            if (cnt == 0) str = i;
            cnt++;
            j = (j + 1) % n;
        }
    }
    if (cnt == 0) str = st;
    if (cnt == 0 && st > n / 2) stop = true;
    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> c;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> ans(n / 2 + 1);
    for (int md = 0; md < n; ++md) {
        for (int st = 0; st < md; ++st) {
            for (int en = md; en < n; ++en) {
                
            }
        }
    }
    return 0;
}
