#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
int n, m;
int p[MAXN+1];
vector<int> g[MAXN+1];

// BFS distance between u and v
int dist(int u, int v) {
  vector<int> dist(n+1, -1);
  queue<int> q;
  dist[u] = 0;
  q.push(u);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    if (cur == v) return dist[cur];
    for (int to : g[cur]) {
      if (dist[to] == -1) {
        dist[to] = dist[cur] + 1;
        q.push(to);
      }
    }
  }
  return -1; // should never happen in tree
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(time(nullptr));

  if (argc > 1) n = atoi(argv[1]); else n = rand() % 9 + 2; // 2..10
  if (argc > 2) m = atoi(argv[2]); else m = rand() % 10 + 1; // 1..10

  // generate random tree
  for (int i = 2; i <= n; i++) {
    p[i] = rand() % (i - 1) + 1;
    g[i].push_back(p[i]);
    g[p[i]].push_back(i);
  }

  cout << n << "\n";
  for (int i = 2; i <= n; i++) {
    cout << p[i] << (i == n ? '\n' : ' ');
  }

  // print [l_i, r_i] in [1..10]
  for (int i = 1; i <= n; i++) {
    int L = rand() % 10 + 1;
    int R = rand() % (11 - L) + L; 
    cout << L << " " << R << "\n";
  }

  cout << m << "\n";

  // generate queries with equal dist paths
  for (int i = 0; i < m; i++) {
    int a, b, c, d;

    // pick a,b distinct random nodes
    do {
      a = rand() % n + 1;
      b = rand() % n + 1;
    } while (a == b);

    int length = dist(a,b);

    // collect all pairs with same length
    vector<pair<int,int>> candidates;
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        if (x != y && dist(x,y) == length) {
          candidates.emplace_back(x,y);
        }
      }
    }

    // pick random (c,d)
    auto pr = candidates[rand() % candidates.size()];
    c = pr.first;
    d = pr.second;

    cout << a << " " << b << " " << c << " " << d << "\n";
  }

  return 0;
}
