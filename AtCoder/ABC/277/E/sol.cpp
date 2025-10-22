/**
 *    author:  feev1x
 *    created: 16.10.2025 20:50:48
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

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r) {
        for (; r <= n; r += r & -r)
            p[r]++;
    }

    inline int get(int r) {
        int res = 0;

        for (; r > 0; r -= r & -r)
            res += p[r];

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int n = s.size();
    std::array<std::vector<int>, 3> pos{};
    std::map<char, int> mp;

    mp['K'] = 0;
    mp['E'] = 1;
    mp['Y'] = 2;
    for (int i = 0; i < s.size(); ++i)
        pos[mp[s[i]]].emplace_back(i + 1);

    int k; std::cin >> k;

    auto t = s;

    int res = 0;
    std::sort(t.begin(), t.end());

    do {
        Bit bit(n);
        std::array<std::vector<int>, 3> ps{};

        for (int i = 0; i < t.size(); ++i)
            ps[mp[t[i]]].emplace_back(i);

        std::vector<int> p(n);
        for (int k = 0; k < 3; ++k)
            for (int i = 0, j = 0; i < ps[k].size(); ++i, ++j)
                p[ps[k][i]] = pos[k][j];

        int cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            cnt += bit.get(p[i]);

            bit.update(p[i]);
        }
        
        if (cnt <= k)
            res++;

    } while (next_permutation(t.begin(), t.end()));
    
    std::cout << res << '\n';
    return 0;
}
