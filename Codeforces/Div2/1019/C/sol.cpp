/**
 *    author:  feev1x
 *    created: 21.04.2025 20:50:37
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        int pref = 0, sz = 0, l = -1, r = -1;
        std::vector<int> a(n);
        std::set<int> st;
        bool flag = false;
        for (auto &u: a) {
            std::cin >> u;

            if (u > k) {
                u = 1;
            } else {
                u = 0;
            }

            pref += u;
            sz++;

            if (sz < n && st.size() && *st.rbegin() > -1 + 2 * pref - sz) {
                flag = true;
            }


            if (pref <= sz / 2) {
                st.emplace(2 * pref - sz);

                if (l == -1) {
                    l = sz;
                }
            }
        }

        st.clear();
        pref = 0, sz = 0;
        for (int i = n - 1; i >= 0; --i) {
            pref += a[i];
            sz++;

            if (i && st.size() && *st.rbegin() > -1 + 2 * pref - sz) {
                flag = true;
            }

            if (pref <= sz / 2) {
                st.emplace(2 * pref - sz);
                
                if (r == -1) {
                    r = n - sz + 1;
                }
            }
        }

        if (r - l > 1 && l != -1) {
            flag = true;
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
