#include <bits/stdc++.h>

#define int int64_t

class segtree {
    std::vector<int> tree, psh;
	int n;
	void update(int v, int tl, int tr, int l, int r, int x) {                   
		if (tr < l || r < tl) return;
		if (l <= tl && tr <= r) {
		 	tree[v] = x * (tr - tl + 1);    
			psh[v] = x;
			return;
		}
		int tm = tl + tr >> 1;
		if (psh[v] != -1) {
		 	if (tl == tr) {
			 	tree[v] = psh[v];
			} else {
				psh[v << 1] = psh[v << 1 | 1] = psh[v];
				tree[v << 1] = psh[v] * (tm - tl + 1);
				tree[v << 1 | 1] = psh[v] * (tr - (tm + 1) + 1);
			}
			psh[v] = -1;
		}
		update(v << 1, tl, tm, l, r, x);
		update(v << 1 | 1, tm + 1, tr, l, r, x);
		tree[v] = tree[v << 1] + tree[v << 1 | 1];
	}
	int sum(int v, int tl, int tr, int l, int r) {
		if (tr < l || r < tl) return 0;
		if (psh[v] != -1) return psh[v] * (std::min(tr, r) - std::max(tl, l) + 1);
		if (l <= tl && tr <= r) return tree[v];
		int tm = tl + tr >> 1;
		return sum(v << 1, tl, tm, l, r) + sum(v << 1 | 1, tm + 1, tr, l, r);             
	}
public:
	segtree(int n) {
		this->n = n;
		int sz = n + 1;
		sz <<= 2;
		tree.assign(sz, 0LL);
		psh.assign(sz, -1LL);
	}
	void modify(int l, int r, int x) {
	 	update(1, 1, n, l + 1, r + 1, x);
	}
	int calc(int l, int r) {
	 	return sum(1, 1, n, l + 1, r + 1);
	}
};

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n), c(n), p(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (auto &u: c) {
        std::cin >> u;
    }

    for (auto &u: p) {
        std::cin >> u, u--;
    }

    int64_t res = 0;
    
    segtree t(n + 1);
    {
        std::vector<int> next(n, n), prev(n, -1);

        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            prev[i] = i - 1;
        }

        for (int i = 0; i + 1 < n; ++i) {
            next[i] = i + 1;
        }

        std::vector<int> idx(n);
        std::vector<bool> used(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int i, int j) {
            return c[i] < c[j];
        });

        for (int i = 0; i < n; ++i) {
            int j = idx[i];

            if (used[j]) {
                continue;
            }

            used[j] = true;
            while (prev[j] != -1 && a[prev[j]] <= a[j]) {
                t.modify(prev[j], prev[j], c[j]);
//                assert(!used[prev[j]]);
                used[prev[j]] = true;
                cnt++;
                res += c[j];
                prev[j] = prev[prev[j]];
            }

            while (next[j] != n && a[next[j]] <= a[j]) {
                t.modify(next[j], next[j], c[j]);
//                assert(!used[next[j]]);
                used[next[j]] = true;
                cnt++;
                res += c[j];

                next[j] = next[next[j]];
            }

            t.modify(j, j, c[j]);
            res += c[j];
            cnt++;

            if (cnt == n) {
                res -= c[j];
                t.modify(j, j, 0);
            }

            if (prev[j] != -1) {
                next[prev[j]] = next[j];
            }

            if (next[j] != n) {
                prev[next[j]] = prev[j];
            }
        }
    }

    std::vector<int> prev(n, -1), next(n, n);
    
    {
        std::stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (stk.size() && a[stk.top()] <= a[i]) {
                stk.pop();
            }

            if (stk.size()) {
                prev[i] = stk.top();
            }

            stk.emplace(i);
        }
    }

    {
        std::stack<int> stk;
        for (int i = n; i >= 0; --i) {
            while (stk.size() && a[stk.top()] <= a[i]) {
                stk.pop();
            }

            if (stk.size()) {
                next[i] = stk.top();
            }

            stk.emplace(i);
        }
    }

    std::cout << res << ' ';
    for (int i = 0; i < n; ++i) {
        res -= t.calc(prev[p[i]] + 1, next[p[i]] - 1);

        t.modify(prev[p[i]] + 1, next[p[i]] - 1, 0);

        std::cout << res << " \n"[i == n - 1];
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
