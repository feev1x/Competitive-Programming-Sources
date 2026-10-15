#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> sum(n);
    for (auto &u: sum) std::cin >> u;
    int64_t a = 0;
    for (int64_t pw = 1; sum[0] > 0; pw *= 10) {
        int64_t val = -1, cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (sum[i - 1] > sum[i]) {
                val = 10 - (i + pw - 1) / pw;
                break;
            }
        }
        for (int i = 1; i < n; ++i) if (sum[i - 1] < sum[i]) cnt++;
        if (val == -1) {
            val = std::min({(int64_t)sum[0], (int64_t)9, 9 - cnt});
        }
        a += pw * val;
        for (int i = 0; i < n; ++i) sum[i] -= val, val = (i + 1 < n && sum[i] + val != sum[i + 1] ? (val + 1) % 10 : val);
    }
    std::cout << a << '\n';
    return 0;
}
