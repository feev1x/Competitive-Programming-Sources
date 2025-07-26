/**
 *    author:  feev1x
 *    created: 22.07.2025 12:11:31
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n), b(n), idx(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];

        idx[i] = i;
    }

    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] + b[i] < a[j] + b[j];
    });

    std::multiset<int> st;

    int64_t sum = 0;
    for (auto i: idx) {
        if (sum <= b[i]) {
            st.emplace(a[i]);

            sum += a[i];
        } else if (st.empty() || *st.rbegin() > a[i]) {
            sum -= *st.rbegin();
            st.erase(--st.end());

            sum += a[i];
            st.emplace(a[i]);
        }
    }

    std::cout << st.size() << '\n';
    return 0;
}
