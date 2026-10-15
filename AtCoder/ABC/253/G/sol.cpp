#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, xl = 0, yl, xr = 0, yr; int64_t l, r, nw = 0; std::cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        if (nw + n - i - 1 >= l && nw < l) xl = i + 1, yl = i + 1 + l - nw;
        if (nw + n - i - 1 >= r && nw < r) xr = i + 1, yr = i + 1 + r - nw;
        nw += n - i - 1;
    }
    std::deque<int> dq;
    for (int i = 1; i <= n; ++i) dq.emplace_back(i);
    for (int i = 1; i <= xr; ++i) {
        if (i < xl) std::cout << dq.front() << ' ', dq.pop_front();
        else if (i == xl && i == xr) for (int j = yl; j <= yr; ++j) std::swap(dq[0], dq[j - i]);
        else if (i == xl && yl != xl + 1) {
            for (int j = yl; j <= n; ++j) std::swap(dq[0], dq[j - i]);
            std::cout << dq.front() << ' ', dq.pop_front();
        } else if (i == xr && yr != n) for (int j = i + 1; j <= yr; ++j) std::swap(dq[0], dq[j - i]);
        else std::cout << dq.back() << ' ', dq.pop_back();
    }
    for (auto u: dq) std::cout << u << ' ';
    return 0;
}
