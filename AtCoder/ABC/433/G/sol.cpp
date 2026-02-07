#include <bits/stdc++.h>

struct Node {
    std::array<int, 26> next;
    int l, r, p, s;
    bool dp;

    Node(int l = 0, int r = 0, int p = -1) : l(l), r(r), p(p), s(0), dp(false) {
        std::fill(next.begin(), next.end(), -1);
    }

    inline int size() {
        return r - l + 1;
    }
};

struct Sufftree {
    std::vector<Node> t;
    std::string a;
    int sz, v, nw, pos, n;

    inline void add(int c) {
suff:;
        if (t[v].r < pos) {
            if (t[v].next[c] == -1) {
                t[v].next[c] = sz++;
                t.emplace_back(Node(nw, n - 1, v));

                v = t[v].s, pos = t[v].r + 1;
                goto suff;
            }

            v = t[v].next[c], pos = t[v].l;
        }

        if (pos == -1 || c == a[pos] - 'a') {
            pos++;
        } else {
            t.emplace_back(Node(t[v].l, pos - 1, t[v].p));

            t[v].l = pos, t[v].p = sz;
            t[sz].next[a[pos] - 'a'] = v, t[sz].next[c] = sz + 1;
            t.emplace_back(Node(nw, n - 1, sz));

            t[t[sz].p].next[a[t[sz].l] - 'a'] = sz, sz += 2;
            v = t[t[sz - 2].p].s, pos = t[sz - 2].l;

            while (pos <= t[sz - 2].r) {
                v = t[v].next[a[pos] - 'a'], pos += t[v].size();
            }

            if (pos == t[sz - 2].r + 1) {
                t[sz - 2].s = v;
            } else {
                t[sz - 2].s = sz;
            }

            pos = t[v].r - (pos - t[sz - 2].r) + 2;
            goto suff;
        }
    }

    inline void Dfs(int v) {
        for (int i = 0; i < 26; ++i) {
            int to = t[v].next[i];

            if (to != -1) {
                Dfs(to);

                if (!t[to].dp == t[to].size() % 2) {
                    t[v].dp = true;
                }
            }
        }
    }

    Sufftree(std::string a) : a(a) {
        n = a.size();

        t.emplace_back(Node(-1, -1));
        t.emplace_back(Node(-1, -1));

        t[0].s = 1;
        sz = 2, v = 0, pos = 0;
        std::fill(t[1].next.begin(), t[1].next.end(), 0);

        for (nw = 0; nw < n; ++nw) {
            add(a[nw] - 'a');
        }

        Dfs(0);
    }
};

inline void solve() {
    std::string s; std::cin >> s;

    Sufftree t(s);

    std::cout << (t.t[0].dp ? "Alice" : "Bob") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
