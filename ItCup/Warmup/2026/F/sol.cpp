#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n), odd, even;
    for (auto &u: a) std::cin >> u;
    for (auto u: a) {
        if (u & 1) odd.emplace_back(u);
        else even.emplace_back(u);
    }
    std::sort(odd.begin(), odd.end());
    std::sort(even.begin(), even.end());
    int sz = 0, i = 0, j = 0, ls = 0;
    bool od = true;
    while (true) {
        if (sz == 0) {
            if (odd.empty()) od = false;
            else if (even.empty()) od = true;
            else if (odd[i] < even[j]) od = true;
            else od = false;
        }
        if (od) {
            if (i >= odd.size()) break;
            if (odd[i++] < ls) continue;
            ls = odd[i - 1], sz++;
        } else {
            if (j >= even.size()) break;
            if (even[j++] < ls) continue;
            ls = even[j - 1], sz++;
        }
        od = !od;
    }
    std::cout << sz << '\n';
    return 0;
}
