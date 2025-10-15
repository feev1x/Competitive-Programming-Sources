/**
 *    author:  feev1x
 *    created: 10.09.2025 00:17:33
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
    
    std::string s, t; std::cin >> s >> t;    

    for (auto &u: s)
        u = (u == 'A' ? '0' : '1');

    for (auto &u: t)
        u = (u == 'A' ? '0' : '1');

    s = ' ' + s;
    t = ' ' + t;
    std::vector<int> left(s.size()), lef(t.size()), pref(s.size()), pfx(t.size());
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] != '0')
            left[i] = i;
        else
            left[i] = left[i - 1];

        if (s[i] == '1')
            left[i] = i + 1;

        pref[i] = pref[i - 1] + s[i] - '0';
    }

    for (int i = 1; i < t.size(); ++i) {
        if (t[i - 1] != '0')
            lef[i] = i;
        else
            lef[i] = lef[i - 1];

        if (t[i] == '1')
            lef[i] = i + 1;

        pfx[i] = pfx[i - 1] + t[i] - '0';
    }

    int q; std::cin >> q;
    while (q--) {
        int l, r, a, b; std::cin >> l >> r >> a >> b;

        int lzs = r - std::max(left[r], l) + 1, lzt = b - std::max(lef[b], a) + 1, cnt1s = pref[r] - pref[l - 1], cnt1t = pfx[b] - pfx[a - 1];

        if (lzt > lzs || cnt1s > cnt1t || ((cnt1t - cnt1s) & 1) || cnt1s == cnt1t && (lzs - lzt) % 3 != 0 
                || cnt1t > 0 && cnt1s == 0 && lzs == lzt)
            std::cout << 0;
        else
            std::cout << 1;
    }

    std::cout << '\n';
    return 0;
}
