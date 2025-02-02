/**
 *    author:  feev1x
 *    created: 29.01.2025 19:35:45
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::deque<std::pair<int64_t, int64_t>> dq;

    int64_t head = 0, rm = 0;
    
    int q; std::cin >> q;
    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int l; std::cin >> l;
            
            dq.emplace_back(head, l);

            head += l;
        } else if (type == 2) {
            rm += dq.front().second;

            dq.pop_front();
        } else {
            int k; std::cin >> k;

            std::cout << dq[k - 1].first - rm << '\n';
        }
    }
    return 0;
}
