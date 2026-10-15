#include "migrations.h"
#include <bits/stdc++.h>

constexpr int MN = 10000, SM = 14;

std::vector<std::array<int, SM>> anc(MN);
std::vector<int> d(MN);
int A, B, pw, ph;

inline int lca(int u, int v) {
  if (d[u] > d[v]) std::swap(u, v);
  for (int i = 0; i < SM; ++i) if ((d[v] - d[u]) >> i & 1) v = anc[v][i];
  if (u == v) return u;
  for (int i = SM - 1; i >= 0; --i) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}

inline int dis(int u, int v) {
  int l = lca(u, v);
  return d[u] + d[v] - 2 * d[l];
}

inline int update(int u) {
  int dab = dis(A, B), dau = dis(A, u), dub = dis(u, B);
  if (dab >= dau && dab >= dub) return 0;
  if (dub >= dau && dub >= dab) return A = u, 1;
  assert(dau >= dab && dau >= dub);
  return B = u, 2;
}

int send_message(int N, int i, int Pi) {
  assert(N == MN);
  anc[i][0] = Pi;
  d[i] = d[Pi] + 1;
  for (int j = 1; j < SM; ++j) anc[0][j - 1] = 0, anc[i][j] = anc[anc[i][j - 1]][j - 1];
  int got = update(i);
  if (i >= MN - 21) {
    if (pw == 14 && ph == 1 || pw == 7 && ph == 0) ph++, pw = 0;
    if (got == 0) {
      if (ph == 0) {
        return (A / (int)std::pow(4, pw++) % 4);
      } else if (ph == 1) {
        return (B >> (pw++) & 1);
      } else {
        return 0;
      }
    } else if (got == 1) {
      if (ph == 0) {
        ph++;
        pw = 0;
        return 4;
      } else if (ph == 1) {
        return (B >> (pw++) & 1) + 2;
      } else {
        return 1;
      }
    } else {
      if (ph == 0) {
        return (A / (int)std::pow(4, pw++) % 4);
      } else if (ph == 1) {
        ph++;
        pw = 0;
        return 4;
      } else {
        return 2;
      }
    }
  }
  return 0;
}

std::pair<int, int> longest_path(std::vector<int> S) {
  int ph = 0;
  int A = 0, B = 0, pw = 0;
  for (int i = MN - 21; i < MN; ++i) {
    assert(S[i] <= 4);
    if (S[i] == 4) {
      if (ph == 0) {
        A = i;
      } else {
        B = i;
      }
      assert(ph != 2);
      ph++;
      pw = 0;
      continue;
    }
    if (ph == 2) {
      if (S[i] == 1) {
        A = i;
      } else if (S[i] == 2) {
        B = i;
      }
      continue;
    }
    if (S[i] == 2 || S[i] == 3) {
      if (ph == 1) A = i, S[i] -= 2;
    }
    if (ph == 0) A += (int)std::pow(4, pw) * S[i];
    else B += (1 << pw) * S[i];
    pw++;
    if (pw == 14 && ph == 1 || pw == 7 && ph == 0) pw = 0, ph++;
  }
  if (A > B) std::swap(A, B);
  return {A, B};
}

