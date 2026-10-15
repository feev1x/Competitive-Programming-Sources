#include <bits/stdc++.h>

inline void swap(int x) { std::cout << "swap " << x << std::endl; }
inline int check(int x) { std::cout << "throw " << x << std::endl; int got; std::cin >> got; return got; }

inline void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n + 1), cnt(n + 3), vl(n + 1);
    cnt[n] = 1;
    if (check(n - 1) == 1) cnt[n - 1] = 1, a[n - 1] = 2;
    else cnt[n - 1] = 2, a[n - 1] = 1;
    swap(n - 1);
    if (check(n - 1) == 1) cnt[n - 1] = 1, a[n] = 2;
    else cnt[n - 1] = 2, a[n] = 1;
    vl[n] = a[n - 1];
    vl[n - 1] = a[n];
    for (int i = n - 2; i >= 1; --i) {
        if (cnt[i + 1] == cnt[i + 2]) {
            if (i == 1) {
                swap(i);
                std::swap(cnt[i], cnt[i + 1]);
                std::swap(vl[i], vl[i + 1]);
                if (check(i + 1) == cnt[i + 2] + 1) vl[i + 1] = 1, a[i] = 1, cnt[i + 1] = cnt[i + 2] + 1;
                else vl[i + 1] = 2, a[i] = 2, cnt[i + 1] = cnt[i + 3] + 1;
                cnt[i] = cnt[i + vl[i]] + 1;
            } else {
                if (check(i - 1) == cnt[i + 1] + 1) vl[i - 1] = 2, a[i - 1] = 2, cnt[i - 1] = cnt[i + 1] + 1;
                else vl[i - 1] = 1, a[i - 1] = 1, cnt[i - 1] = cnt[i + 1] + 2;
                swap(i - 1);
                std::swap(cnt[i - 1], cnt[i]);
                std::swap(vl[i - 1], vl[i]);
                cnt[i] = cnt[i + 1] + 1;
                if (check(i - 1) == cnt[i + 1] + 1) vl[i - 1] = 2, a[i] = 2, cnt[i - 1] = cnt[i + 1] + 1;
                else vl[i - 1] = 1, a[i] = 1, cnt[i - 1] = cnt[i + 1] + 2;
                i--;
            }
        } else {
            if (check(i) == cnt[i + 1] + 1) vl[i] = 1, a[i] = 1, cnt[i] = cnt[i + 1] + 1;
            else vl[i] = 2, a[i] = 2, cnt[i] = cnt[i + 2] + 1;
        }
    }
    std::cout << "!";
    for (int i = 1; i <= n; ++i) std::cout << " " << a[i];
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
