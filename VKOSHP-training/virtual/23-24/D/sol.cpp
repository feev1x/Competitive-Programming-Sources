#include <bits/stdc++.h>
 
struct Bit {
    std::vector<int> p;
    int n;
 
    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }
 
    inline void update(int r, int x) {
        for (; r <= n; r += r & -r) {
            p[r] += x;
        }
    }
 
    inline int get(int r) {
        int res = 0;
 
        for (; r > 0; r -= r & -r) {
            res += p[r];
        }
 
        return res;
    }
 
    inline int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n; std::cin >> n;
 
    std::string s; std::cin >> s;
 
    Bit bit(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'b') {
            bit.update(i + 1, 1);
        }
    }
 
    std::set<int> st, st1;
    int q; std::cin >> q;
    while (q--) {
        int type; std::cin >> type;
 
        if (type == 1) {
            int i; std::cin >> i; --i;
 
            if (s[i] == 'a') {
                if (!i || s[i - 1] == 'b') {
                    st1.emplace(i - 1);
                }
 
                if (i + 1 == n || s[i + 1] == 'b') {
                    st1.emplace(i);
                }
 
                if ((!i || s[i - 1] == 'b') && (i + 1 == n || s[i + 1] == 'b')) {
                    st.emplace(i - 1);
                }
 
                if (i + 1 < n && s[i + 1] == 'b' && (i + 2 == n || s[i + 2] == 'b')) {
                    st.emplace(i);
                }
 
                s[i] = 'b';
                bit.update(i + 1, 1);
            } else {
                if (!i || s[i - 1] == 'b') {
                    st1.erase(i - 1);
                }
 
                if (i + 1 == n || s[i + 1] == 'b') {
                    st1.erase(i);
                }
 
                if ((!i || s[i - 1] == 'b') && (i + 1 == n || s[i + 1] == 'b')) {
                    st.erase(i - 1);
                }
 
                if (i + 1 < n && s[i + 1] == 'b' && (i + 2 == n || s[i + 2] == 'b')) {
                    st.erase(i);
                }
 
                s[i] = 'a';
                bit.update(i + 1, -1);
            }
        } else {
            int l, r; std::cin >> l >> r;
 
            auto it = st.lower_bound(r - 1);
            auto it1 = st1.lower_bound(l - 1);

            if (s[l - 1] == 'b' && st1.size() && it1 != st1.end() && *it1 <= r - 1) {
                if (bit.get(l, *it1 + 1) * 2 - 1 == *it1 - l + 2) {
                    std::cout << "NO\n";
                    continue;
                }
            }

            it1 = st1.upper_bound(r - 1);

            if (s[r - 1] == 'b' && st1.size() && it1 != st1.begin() && *(--it1) >= l - 1) {
                if (bit.get(*it1 + 2, r) * 2 == r - 1 - *it1) {
                    std::cout << "NO\n";
                    continue;
                }
            }
 
            int sz = r - l + 1;
            std::cout << (bit.get(l, r) * 2 <= sz && (st.empty() || it == st.begin() || *(--it) + 1 < l - 1) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
