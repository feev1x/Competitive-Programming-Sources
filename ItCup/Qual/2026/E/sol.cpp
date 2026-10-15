#include <bits/stdc++.h>

std::map<char, int> mp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

struct Node {
    Node *a[4] = {nullptr, nullptr, nullptr, nullptr};
    bool end = false;
    int dep = 0;
    Node(bool end, int dep) : end(end), dep(dep) {}
};

struct Trie {
    Node *root;
    Trie() : root(new Node(false, -1)) {}
    inline void add(Node *nw, const std::string &s) {
        if (nw->dep + 1 == s.size()) return nw->end = true, void();
        int nx = mp[s[nw->dep + 1]];
        if (nw->a[nx] == nullptr) nw->a[nx] = new Node(false, nw->dep + 1);
        add(nw->a[nx], s);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s; std::cin >> s;
    int n; std::cin >> n;
    Trie tr = Trie();
    for (int i = 0; i < n; ++i) {
        std::string t; std::cin >> t;
        tr.add(tr.root, t);
    }
    n = s.size();
    std::vector<int> dp(n + 1);
    for (int i = 0; i <= n; ++i) {
        auto nw = tr.root;
        bool flag = true;
        for (int j = i + 1; j <= n; ++j) {
            int nx = mp[s[j - 1]];
            if (nw->a[nx] != nullptr) nw = nw->a[nx];
            else flag = false;
            if (flag && nw->end) dp[j] = std::max(dp[j], dp[i] + j - i);
            dp[j] = std::max(dp[j], dp[i]);
        }
    }
    std::cout << dp[n] << '\n';
    return 0;
}
