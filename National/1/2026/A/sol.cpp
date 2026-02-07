#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s; std::getline(std::cin, s);

    std::array<int, 10> cnt;
    for (auto &u: cnt) {
        u = 0;
    }

    for (auto u: s) {
        if (std::isdigit(u)) {
            cnt[u - '0']++;
        }
    }

    int val = -1, c = 0, mx = 0, nw = 0, co = 0;
    for (auto u: cnt) {
        if (u & 1) {
            c++;
            val = nw;
        } else if (u) {
            mx = nw;
            co++;
        }

        nw++;
    }

    if (c < 2 && (mx || !co)) {
        std::deque<int> dq;
        
        if (val != -1) {
            dq.emplace_back(val);
        }

        for (int i = 0; i < 10; ++i) {
            c = cnt[i];

            c /= 2;

            while (c--) {
                dq.emplace_back(i);
                dq.emplace_front(i);
            }
        }

        if (dq.size() && dq.back() == 0) {
            std::cout << "NO\n";
            return 0;
        }

        std::cout << "YES\n";
        for (auto u: dq) {
            std::cout << u;
        }

        std::cout << '\n';
    } else {
        std::cout << "NO\n";
    }
    return 0;
}
