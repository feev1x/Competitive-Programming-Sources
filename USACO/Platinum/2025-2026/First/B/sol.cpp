#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q; std::cin >> q;
    while (q--) {
        int l1, r1, l2, r2; int64_t t; std::cin >> l1 >> r1 >> l2 >> r2 >> t;
        if (t > 100) {
            std::cout << "1000000000000000001\n";
            continue;
        }
        std::vector<int> ar;
        for (int tm = 0; tm <= t; ++tm) {
            std::vector<int> new_ar;
            for (int i = 1; i <= tm / 2; ++i) new_ar.emplace_back(ar[i]);
            if (ar.size()) new_ar.emplace_back(ar[0]);
            for (int i = tm / 2 + 1; i < ar.size(); ++i) new_ar.emplace_back(ar[i]);
            new_ar.emplace_back(tm);
            std::swap(new_ar, ar);
        }
        int res = 0;
        for (int i = l2; i <= r2; ++i) res += l1 <= ar[i] && ar[i] <= r1;
        std::cout << res << '\n';
    }
    return 0;
}
