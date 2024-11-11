#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, mod = MOD;

long long binpow(long long a, long long b) {
    long long result = 1;
    a = a % mod;  // Take modulo at the start to avoid overflow
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

int mod_inverse(int a) {
    return binpow(a, MOD - 2);
}

void dfs(int node, int parent, vector<vector<int>>& tree, vector<long long>& prob) {
    bool is_leaf = true;
    long long sum_prob = 0;

    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            is_leaf = false;
            dfs(neighbor, node, tree, prob);
            sum_prob += prob[neighbor];
        }
    }

    if (is_leaf) {
        prob[node] = 0;
    } else {
        prob[node] = (sum_prob + 1) * mod_inverse(2) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> tree(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<long long> prob(n + 1, 0);
        dfs(1, -1, tree, prob);

        for (int i = 1; i <= n; i++) {
            cout << prob[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

