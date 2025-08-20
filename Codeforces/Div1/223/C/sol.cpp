/**
 *    author:  feev1x
 *    created: 20.08.2025 17:21:36
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

struct Node {
    int mx = 0, l = 0, r = 0;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    inline Node comb(Node &a, Node &b) {
        Node res;

        int mn = std::min(a.l, b.r);
        res.mx = a.mx + b.mx + mn * 2;
        res.l = a.l + b.l - mn;
        res.r = a.r + b.r - mn;

        return res;
    }

    Segtree(std::string s) : n(s.size()) {
        t.resize(2 * n);

        for (int i = 0; i < n; ++i)
            t[i + n] = {0, s[i] == '(', s[i] == ')'};

        for (int i = n - 1; i > 0; --i)
            t[i] = comb(t[i << 1], t[i << 1 | 1]);
    }

    inline int get(int l, int r) {
        l--;

        Node resl, resr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                resl = comb(resl, t[l++]);

            if (r & 1)
                resr = comb(t[--r], resr);
        }

        return comb(resl, resr).mx;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;
    int m; std::cin >> m;

    Segtree t(s);

    while (m--) {
        int l, r; std::cin >> l >> r;

        std::cout << t.get(l, r) << '\n';
    }
    return 0;
}
