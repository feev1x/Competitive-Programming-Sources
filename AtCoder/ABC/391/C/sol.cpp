/**
 *    author:  feev1x
 *    created: 01.02.2025 18:17:48
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> cnt(n + 1, 1), pos(n + 1);
    std::set<int> st;

    iota(pos.begin(), pos.end(), 0);

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int p, h; std::cin >> p >> h;

            if (cnt[pos[p]] == 2) {
                st.erase(pos[p]);
            }

            cnt[pos[p]]--;

            pos[p] = h;

            if (cnt[h] == 1) {
                st.emplace(h);
            }

            cnt[h]++;
        } else {
            std::cout << st.size() << '\n';
        }
    }
    return 0;
}
