#include <bits/stdc++.h>

struct Node {
    Node *a[2] = {nullptr, nullptr};
    int dep = 0;
    Node(int dep) : dep(dep) {}
};

struct Trie {
    Node *root;
    Trie() : root(new Node(30)) {}
    inline void add(int64_t x, Node *nw) {
        if (nw->dep == 0) return;
        int bit = x >> (nw->dep - 1) & 1;
        if (nw->a[bit] == nullptr) nw->a[bit] = new Node(nw->dep - 1);
        add(x, nw->a[bit]);
    }
    inline int64_t get(int64_t cnt, Node *nw) {
        if (nw == nullptr || nw->dep == 0) return 0ll;
        if (nw->a[0] == nullptr || nw->a[1] == nullptr) return cnt * (1ll << 2 * (nw->dep - 1)) + get(cnt * 2, nw->a[nw->a[0] == nullptr]);
        return get(cnt, nw->a[0]) + get(cnt, nw->a[1]);
    }
    inline int64_t gets(int64_t x, Node *nw) {
        if (nw == nullptr || nw->dep == 0) return 0ll;
        int bit = x >> (nw->dep - 1) & 1;
        int64_t c = x & ((1ll << nw->dep - 1) - 1);
        if (nw->a[0] == nullptr) {
            if (bit) return gets(x, nw->a[1]) + get(1, nw->a[1]) + (1ll << 2 * (nw->dep - 1));
            return gets(x, nw->a[1]) + (1ll << nw->dep - 1) * (c + 1);
        }
        if (nw->a[1] == nullptr) {
            if (bit) return gets(x, nw->a[0]) + get(1, nw->a[0]) + (1ll << nw->dep - 1) * (c + 1);
            return gets(x, nw->a[0]);
        }
        if (bit) return gets(x, nw->a[1]) + get(1, nw->a[0]);
        return gets(x, nw->a[0]);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n, m; std::cin >> n >> m;
    std::vector<int64_t> a(n);
    Trie t = Trie();
    for (auto &u: a) std::cin >> u, t.add(u, t.root);
    std::cout << t.gets(m - 1, t.root) << '\n';
    return 0;
}
