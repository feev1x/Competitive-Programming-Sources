#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int cnt = 0;
    auto Dfs = [&](auto &&self, std::vector<std::vector<int>> &p) -> void {
        if (p.size() == n) {
            if (p[0][2] != 2)
                return;

            for (auto u: p) {
                for (auto v: u)
                    std::cout << v << ' ';

                std::cout << '\n';
            }
            std::cout << '\n';

            cnt++;

            if (cnt == 5)
                exit(0);
            return;
        }

        std::vector<int> per(n);

        std::iota(per.begin(), per.end(), 1);

        do {
            if (per[p.size()] != p.size() + 1)
                continue;

            p.emplace_back(per);

            bool flag = true;
            for (int i = 0; i < n; ++i) {
                std::set<int> st;

                for (int j = 0; j < p.size(); ++j)
                    st.emplace(p[j][i]);

                if (st.size() != p.size()) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                self(self, p);

            p.pop_back();
        } while (next_permutation(per.begin(), per.end()));
    };

    std::vector<std::vector<int>> p;
    Dfs(Dfs, p);
}
