/**
 *    author:  feev1x
 *    created: 19.09.2025 16:03:40
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::array<int, 4>> seg(n);
    for (auto &[x1, y1, x2, y2]: seg) {
        std::cin >> x1 >> y1 >> x2 >> y2;

        if (y1 < y2)
            std::swap(y1, y2);
    }

    std::sort(seg.begin(), seg.end(), [&](std::array<int, 4> a, std::array<int, 4> b) {
        if (a[0] == b[0])
            return std::max(a[1], a[3]) > std::max(b[1], b[3]);

        return a[0] < b[0];
    });

    std::vector<bool> used(n);
    {
        std::stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (stk.size() && seg[stk.top()][1] <= seg[i][1])
                stk.pop();

            if (stk.size()) {
                used[i] = true;

                if (seg[i][0] != seg[stk.top()][0])
                    std::cout << seg[i][0] << ' ' << seg[i][1] << ' ' << seg[stk.top()][0] << ' ' << seg[stk.top()][1] << '\n';
                else
                    std::cout << seg[i][0] << ' ' << seg[i][1] << ' ' << seg[stk.top()][0] << ' ' << seg[stk.top()][3] << '\n';
            }
                
            stk.emplace(i);
        }
    }

    std::sort(seg.begin(), seg.end(), [&](std::array<int, 4> a, std::array<int, 4> b) {
        if (a[0] == b[0])
            return std::max(a[1], a[3]) < std::max(b[1], b[3]);

        return a[0] < b[0];
    });


    {
        std::stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            while (stk.size() && seg[stk.top()][1] <= seg[i][1])
                stk.pop();

            if (stk.size() && !used[i]) {
                used[i] = true;

                if (seg[i][0] != seg[stk.top()][0])
                    std::cout << seg[i][0] << ' ' << seg[i][1] << ' ' << seg[stk.top()][0] << ' ' << seg[stk.top()][1] << '\n';
                else
                    std::cout << seg[i][0] << ' ' << seg[i][1] << ' ' << seg[stk.top()][0] << ' ' << seg[stk.top()][3] << '\n';
            }
                
            stk.emplace(i);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += !used[i];

    assert(cnt == 1);
    return 0;
}
