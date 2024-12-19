/**
 *    author:  feev1x
 *    created: 09.12.2024 11:20:27
**/
#include <bits/stdc++.h>

using i64 = long long;
using u129 = unsigned __int128;

constexpr int N = 505;
#define sz 501

int popcount(u128 x) {
  uint64_t low = static_cast<uint64_t>(x);
  uint64_t high = static_cast<uint64_t>(x >> 64);
  return __builtin_popcountll(low) + __builtin_popcountll(high);
}

struct Bs {
  u128 a[5];
  int cnt[5];
  u128 on = 1;
  Bs() : a{0, 0, 0, 0, 0}, cnt{0, 0, 0, 0, 0} {}
  inline void full() {
    for (int i = 0; i < 5; ++i) {
      a[i] = (on << 127) - 1;
      a[i] |= (on << 127);
      cnt[i] += 128;
    }
    cnt[0]--;
    a[0] ^= 1;
  }
  inline void operator&=(const Bs &b) {
    for (int i = 0; i < 5; ++i) {
      cnt[i] = 0;
      a[i] &= b.a[i];
      cnt[i] = popcount(a[i]);
    }
  }
  inline void operator|=(const Bs &b) {
    for (int i = 0; i < 5; ++i) {
      cnt[i] = 0;
      a[i] |= b.a[i];
      cnt[i] = popcount(a[i]);
    }
  }
  inline void operator^=(const Bs &b) {
    for (int i = 0; i < 5; ++i) {
      cnt[i] = 0;
      a[i] ^= b.a[i];
      cnt[i] = popcount(a[i]);
    }
  }
  inline void operator|=(int v) {
    int i = v / 128;
    v %= 128;
    cnt[i] = 0;
    a[i] |= on << v;
    cnt[i] = popcount(a[i]);
  }
  inline int ppcnt() {
    int res = 0;
    for (int i = 0; i < 5; ++i) {
      res += cnt[i];
    }
    return res;
  }
};

struct Lca {
  std::vector < int > adj[sz];   
  std::vector < int > euler;    
  std::vector < int > depthArr;
  int FAI[sz];     
  int level[sz];  
  int ptr;       
  int dp[sz][18];
  int logn[sz]; 
  int p2[20];  
  void buildSparseTable(int n) {
      memset(dp,-1,sizeof(dp));
      for (int i=1; i<n; i++)
          dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i;
      for (int l=1; l<15; l++)
        for (int i=0; i<n; i++)
          if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1)
            dp[i][l] =
              (depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])?
               dp[i+p2[l-1]][l-1] : dp[i][l-1];
          else
               break;
  }
  int query(int l,int r) {
      int d = r-l;
      int dx = logn[d];
      if (l==r) return l;
      if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]])
          return dp[r-p2[dx]][dx];
      else
          return dp[l][dx];
  }
   
  void preprocess() {
      p2[0] = 1;
      for (int i=1; i<18; i++)
          p2[i] = p2[i-1]*2;
      int val = 1,ptr=0;
      for (int i=1; i<sz; i++)
      {
          logn[i] = ptr-1;
          if (val==i)
          {
              val*=2;
              logn[i] = ptr;
              ptr++;
          }
      }
  }
   
  void dfs(int cur,int prev,int dep) {
      if (FAI[cur]==-1)
          FAI[cur] = ptr;
   
      level[cur] = dep;
   
      euler.push_back(cur);
   
      ptr++;
   
      for (auto x:adj[cur])
      {
          if (x != prev)
          {
              dfs(x,cur,dep+1);
   
              euler.push_back(cur);
              ptr++;
          }
      }
  }
   
  void makeArr()
  {
      for (auto x : euler)
          depthArr.push_back(level[x]);
  }
   
  int LCA(int u,int v) {
      if (u==v)
         return u;
   
      if (FAI[u] > FAI[v])
         std::swap(u,v);
   
      return euler[query(FAI[u], FAI[v])];
  }
   
  void addEdge(int u,int v)
  {
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
};


int main() {
  int n, k; scanf("%d%d", &n, &k);
  std::vector<Bs> st(n + 1);
  for (int i = 1; i <= n; ++i) {
    st[i].full();
  }
  std::vector<std::vector<int>> a(n + 2, std::vector<int>(n + 1));
  std::vector<std::vector<Bs>> lca(n + 1, std::vector<Bs>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      lca[i][j].full();
    }
  }
  while (k--) {
    Lca l;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      l.addEdge(u, v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    auto Dfs = [&](auto Dfs, int v, int p) -> void {
      st[v] &= st[p];
      st[v] |= v;
      for (auto to: g[v]) {
        if (to == p) {
          continue;
        }
        Dfs(Dfs, to, v);
      }
    };
    Dfs(Dfs, 1, 0);
    l.preprocess();
    l.ptr = 0;
    memset(l.FAI,-1,sizeof(l.FAI));
    l.dfs(1,0,0);
    l.makeArr();
    l.buildSparseTable(l.depthArr.size());
    for (int i = 1; i < n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        lca[i][j] &= st[l.LCA(i, j)];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      Bs ans, bi, bj;
      bi |= st[i];
      bj |= st[j];
      bi ^= lca[i][j];
      bj ^= lca[i][j];
      ans |= bi;
      ans |= bj;
      ans |= i;
      ans |= j;
      a[j][i] = a[i][j] = ans.ppcnt();
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) {
        a[i][j] = 1;
      }
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
