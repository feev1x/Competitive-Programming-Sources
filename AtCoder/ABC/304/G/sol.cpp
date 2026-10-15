#include <bits/stdc++.h>

struct Node {
    Node *a[2] = {nullptr, nullptr};
    int cnt = 0, dep = 0;
    Node(int dep, int cnt) : cnt(cnt), dep(dep) {}
};

struct Trie {
    Node *root;
    Trie() { root = new Node(30, 0); }
    inline void add(Node *nw, int num) {
        nw->cnt++;
        if (nw->dep == 0) return;
        int bit = num >> (nw->dep - 1) & 1;
        if (nw->a[bit] == nullptr) nw->a[bit] = new Node(nw->dep - 1, 0);
        add(nw->a[bit], num);
    }
    inline int get(Node *nw, Node *nw2, int num) {
        if (nw == nullptr || nw2 == nullptr) return 0;
        if (nw->dep == 0) return std::min(nw->cnt, nw2->cnt) * 2;
        int bit = num >> (nw->dep - 1) & 1, cl = 0, cr = 0, cl2 = 0, cr2 = 0;
        if (nw->a[0] != nullptr) cl = nw->a[0]->cnt;
        if (nw->a[1] != nullptr) cr = nw->a[1]->cnt;
        if (nw2->a[0] != nullptr) cl2 = nw2->a[0]->cnt;
        if (nw2->a[1] != nullptr) cr2 = nw2->a[1]->cnt;
        if (bit) return std::min(std::min(cl, cr2) * 2, get(nw->a[0], nw2->a[1], num))
                      + std::min(std::min(cl2, cr) * 2, get(nw2->a[0], nw->a[1], num));
        int res = std::min(cl, cr2) * 2 + std::min(cl2, cr) * 2;
        if (cr > cl2 == cr2 > cl) res += get(nw->a[cr > cl2], nw2->a[cr2 > cl], num);
        return res;
    }
    inline int get(Node *nw, int num) {
        if (nw == nullptr) return 0;
        if (nw->dep == 0) return nw->cnt;
        int bit = num >> (nw->dep - 1) & 1, cl = 0, cr = 0;
        if (nw->a[0] != nullptr) cl = nw->a[0]->cnt;
        if (nw->a[1] != nullptr) cr = nw->a[1]->cnt;
        if (bit) return std::min(std::min(cl, cr) * 2, get(nw->a[0], nw->a[1], num));
        return std::min(cl, cr) * 2 + std::min(std::abs(cl - cr), get(nw->a[cr > cl], num));
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n; n += n;
    std::vector<int> a(n);
    Trie t = Trie();
    for (auto &u: a) std::cin >> u, t.add(t.root, u);
    int l = 0, r = (1 << 30) - 1, ans = 0;
    while (l <= r) {
        int m = l + r >> 1;
        if (t.get(t.root, m) >= n / 2) l = m + 1, ans = m;
        else r = m - 1;
    }
    std::cout << ans << '\n';
    return 0;
}
