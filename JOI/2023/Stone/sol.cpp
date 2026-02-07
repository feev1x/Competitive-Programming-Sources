#include <bits/stdc++.h>

sdfsdfssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> r;

    int nw = 0;
    for (auto &u: a) {
        std::cin >> u;

        r[u] = nw;

        nw++;
    }

    for (int i = 0; i < n; ++i) {
        int cnt = r[a[i]] - i;

        while (cnt--) {
            std::cout << a[i] << '\n';
        }

        if (r[a[i]] == i) {
            std::cout << a[i] << '\n';
            continue;
        }

        i = r[a[i]] - 1;
    }

    return 0;
}
