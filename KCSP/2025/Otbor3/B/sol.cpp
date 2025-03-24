/**
 *    author:  feev1x
 *    created: 16.03.2025 10:09:39
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, d; std::cin >> n >> d;    

    std::set<std::pair<int, int>> st;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        st.emplace(a[i] - 2 * d, a[i] - d);
    }

    int cnt = n;
    for (int i = 0; i < n; ++i) {
        auto it = st.lower_bound({a[i] - d, -1});

        if (it != st.end() && it->second >= a[i] && it->first <= a[i]) {
            cnt--;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
