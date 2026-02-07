/**
 *    author:  feev1x
 *    created: 16.11.2025 21:24:17
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, q; std::cin >> n >> q;

        std::vector<int> a(n);
        std::vector<int> b(n);

        std::set<std::pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];

            st.emplace(a[i], i);
        }

        while (q--) {
            int c; std::cin >> c;

            std::vector<int> bck;

            int64_t res = 0;
            while (c) {
                auto [val, pos] = *st.rbegin();

                st.erase(--st.end());

                int bt;

                for (int i = 29; i >= 0; --i)
                    if (c >> i & 1) {
                        bt = i;
                        break;
                    }

                bt = 1 << bt;

                if (bt > val)
                    res += bt - val;

                c -= bt;

                bck.emplace_back(pos);
                b[pos] = std::max(0, val - bt);
                st.emplace(std::max(0, val - bt), pos);
            }

            for (auto u: bck) {
                auto it = st.find({b[u], u});

                if (it != st.end()) {
                    st.erase(it);
                    st.emplace(a[u], u);
                }
            }

            std::cout << res << '\n';
        }
    }

    return 0;
}
