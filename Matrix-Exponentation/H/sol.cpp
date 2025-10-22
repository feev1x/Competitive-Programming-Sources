/**
 *    author:  feev1x
 *    created: 16.10.2025 09:00:41
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

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

struct Matrix {
    std::array<std::array<int, 2>, 2> a;
    int n, m;

    Matrix() {}
    Matrix(int _n, int _m, int val) : n(_n), m(_m) {
//        a.resize(n, std::vector<int>(m));

        a = {};
        for (int i = 0; i < std::min(n, m); ++i)
            a[i][i] = val;
    }

    Matrix(std::array<std::array<int, 2>, 2> _a) : a(_a), n(a.size()), m(a[0].size()) {}

    inline Matrix operator*(const Matrix &b) const {
        Matrix c(n, b.m, 0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < m; ++k)
                    add_self(c.a[i][j], mul(a[i][k], b.a[k][j]));

        return c;
    }

//    inline Matrix operator=(const Matrix &b) const {
//        a = b.a;
//        n = b.n;
//        m = b.m;
//    }
};

std::string vowel = "AEIOU";

struct Segtree {
    std::vector<Matrix> t;
    int n;

    Segtree(std::vector<Matrix> a) : n(a.size()) {
        int pw = 1;

        while (pw < n)
            pw *= 2;

        n = pw;

        while (a.size() < n)
            a.emplace_back(Matrix(2, 2, 1));

        t.resize(2 * n);

        for (int i = 0; i < n; ++i)
            t[i + n] = a[i];

        for (int i = n - 1; i > 0; --i)
            t[i] = t[i << 1 | 1] * t[i << 1];
    }

    inline void update(int i, const Matrix &a) {
        for (t[i += n] = a; (i >>= 1) > 0;)
            t[i] = t[i << 1 | 1] * t[i << 1];
    }

    inline Matrix get() {
        return t[1];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;    

    std::string s; std::cin >> s;

    Matrix h(std::array<std::array<int, 2>, 2>{std::array<int, 2>{1, 1},
              std::array<int, 2>{0, 0}});

    Matrix sd(std::array<std::array<int, 2>, 2>{std::array<int, 2>{0, 0},
               std::array<int, 2>{1, 1}});

    Matrix vow(std::array<std::array<int, 2>, 2>{std::array<int, 2>{0, 1},
                std::array<int, 2>{1, 0}});

    Matrix noth(2, 2, 1);

    Matrix qq(std::array<std::array<int, 2>, 2>{std::array<int, 2>{19, 6},
              std::array<int, 2>{7, 20}});

    std::vector<Matrix> send;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'H')
            send.emplace_back(h);
        else if (s[i] == 'S' || s[i] == 'D')
            send.emplace_back(sd);
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            send.emplace_back(vow);
        else if (s[i] == '?')
            send.emplace_back(qq);
        else
            send.emplace_back(noth);

    Segtree t(send);

    std::cout << t.get().a[0][0] << '\n';
    while (q--) {
        int i; char ch; std::cin >> i >> ch; i--;

        s[i] = ch;

        if (s[i] == 'H')
            t.update(i, h);
        else if (s[i] == 'S' || s[i] == 'D')
            t.update(i, sd);
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            t.update(i, vow);
        else if (s[i] == '?')
            t.update(i, qq);
        else
            t.update(i, noth);

        std::cout << t.get().a[0][0] << '\n';
    }

    return 0;
}
