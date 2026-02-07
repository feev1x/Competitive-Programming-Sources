#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::string s, t; std::cin >> s >> t;

    std::vector<bool> cs(26), ct(26);
    for (auto u: s) {
        cs[u - 'a'] = true;
    }

    for (auto u: t) {
        ct[u - 'a'] = true;
    }

    int q; std::cin >> q;
    while (q--) {
        std::string w; std::cin >> w;

        bool nt = false, na = false;
        for (auto u: w) {
            if (!cs[u - 'a']) {
                nt = true;
            }

            if (!ct[u - 'a']) {
                na = true;
            }
        }

        assert(!(nt & na));

        if (!nt && !na) {
            std::cout << "Unknown\n";
        } else if (!nt) {
            std::cout << "Takahashi\n";
        } else {
            std::cout << "Aoki\n";
        }
    }

    return 0;
}
