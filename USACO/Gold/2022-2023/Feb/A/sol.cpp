/**
 *    author:  feev1x
 *    created: 20.11.2025 11:33:41
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n);
    for (auto &u: a)
        std::cin >> u;

    std::multiset<int64_t> st;
    for (int l = 0; l < n; ++l) {
        int64_t sum = 0;

        for (int r = l; r < n; ++r) {
            sum += a[r];

            st.emplace(sum);
        }
    }

    for (int i = 0; i < n; ++i) {
        int64_t res = std::abs(a[i] - a[i + (i ? -1 : 1)]);
        
        for (int l = 0; l <= i; ++l) {
            int64_t sum = 0;

            for (int r = l; r < n; ++r) {
                sum += a[r];

                if (r >= i) {
                    assert(st.find(sum) != st.end());
                    st.erase(st.find(sum));
                }
            }
        }

        for (int l = 0; l <= i; ++l) {
            int64_t sum = 0;

            for (int r = l; r < n; ++r) {
                sum += a[r];

                if (r >= i) {
                    auto it = st.lower_bound(sum);

                    if (it != st.end())
                        res = std::min(res, std::abs(sum - *it));

                    if (it != st.begin()) {
                        --it;

                        res = std::min(res, std::abs(sum - *it));
                    }
                }
            }
        }

        for (int l = 0; l <= i; ++l) {
            int64_t sum = 0;

            for (int r = l; r < n; ++r) {
                sum += a[r];

                if (r >= i)
                    st.emplace(sum);
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
