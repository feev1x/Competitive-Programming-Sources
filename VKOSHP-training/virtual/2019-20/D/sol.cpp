/**
 *    author:  feev1x
 *    created: 11.08.2025 15:39:16
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

    int CNT = 0;
    std::map<std::string, std::vector<std::pair<int, int>>> mp;
    auto Ask = [&](std::string s) {
        if (mp.count(s))
            return mp[s];

        CNT++;
        assert(CNT <= 10);
        std::cout << "? " << s << std::endl;

        int t; std::cin >> t;
        std::vector<std::pair<int, int>> v(t);
        for (auto &[x, y]: v)
            std::cin >> x >> y;

        return mp[s] = v;
    };
    
    int n, m; std::cin >> n >> m;

    std::vector<int> l(n + 1, 1), r(n + 1, m), mid(n + 1);
    std::vector<bool> fix(n + 1);

    l[1] = r[1] = mid[1] = 1;
    while (true) {
        bool flag = false;

        std::string s;
        for (int i = 1; i <= n; ++i) {
            if (r[i] != l[i]) {
                if (i != 1)
                    l[i] = std::max(l[i], l[i - 1]);

                if (i != n)
                    r[i] = std::min(r[i], r[i + 1]);
            }
        }

        for (int i = n; i >= 1; --i) {
            if (r[i] != l[i]) {
                if (i != 1)
                    l[i] = std::max(l[i], l[i - 1]);

                if (i != n)
                    r[i] = std::min(r[i], r[i + 1]);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (r[i] != l[i])
                flag = true;

            mid[i] = l[i] + r[i] >> 1;
        }

        if (!flag)
            break;

        int j = 1;
        for (int i = 2; i <= n; ++i) {
            while (j < mid[i])
                s += "R", j++;

            s += "D";
        }

        while (j < m)
            s += "R", j++;

        auto cor = Ask(s);
        
        std::vector<int> left(n + 1), right(n + 1);
        for (auto [i, j]: cor) {
            if (!left[i])
                left[i] = j;

            right[i] = j;
        }

        bool ls = false;
        for (int i = 2; i <= n; ++i) {
            if (l[i] == r[i])
                continue;

            if (right[i - 1] < mid[i] && right[i - 1]) {
                l[i] = r[i] = mid[i] = right[i - 1];
                ls = false;
                continue;
            }

            if (right[i - 1] == mid[i] && left[i] == mid[i]) {
                l[i] = r[i] = mid[i];
                continue;
            }

            if (left[i]) {
                if (left[i] == mid[i])
                    r[i] = mid[i];
                else
                    l[i] = r[i] = mid[i] = left[i];
            } else {
                if (right[i - 1] == mid[i]) {
                    l[i] = mid[i + 1] + 1;
                    ls = true;
                } else {
                    if (ls)
                        l[i] = mid[i + 1] + 1;
                    else
                        r[i] = mid[i];
                }
            }

            while (l[i] > r[i]);
        }
    }

    int j = 1;
    std::string s;
    for (int i = 2; i <= n; ++i) {
        while (j < mid[i])
            s += "R", j++;

        s += "D";
    }

    while (j < m)
        s += "R", j++;

    std::cout << "! " << s << std::endl;
    return 0;
}
