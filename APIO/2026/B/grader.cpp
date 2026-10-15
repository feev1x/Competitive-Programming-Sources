#include "navigation.h"

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>

int run_testcase() {
  int N;
  assert(scanf("%d", &N) == 1);

  int B;
  assert(scanf("%d", &B) == 1);

  std::vector<int> U(N - 1), V(N - 1);
  std::vector<std::vector<int>> indices(N);
  for (int i = 0; i < N - 1; i++) {
    assert(scanf("%d%d", &U[i], &V[i]) == 2);
    assert(U[i] < V[i]);
    indices[U[i]].push_back(i);
    indices[V[i]].push_back(i);
  }

  int K;
  assert(scanf("%d", &K) == 1);

  std::vector<int> P(K);
  for (int i = 0; i < K; i++)
    assert(scanf("%d", &P[i]) == 1);

  auto T = construct_network(N, K, B, U, V, P);
  if (T.size() != U.size()) {
    fprintf(stderr, "returned array T is not size N - 1\n");
    std::exit(EXIT_FAILURE);
  }
  for (auto t : T)
    if (t < 0 || t >= 100) {
      fprintf(stderr, "returned array T has entry not in [0, 99]\n");
      std::exit(EXIT_FAILURE);
    }

  int Q;
  assert(scanf("%d", &Q) == 1);

  for (int i = 0; i < Q; i++) {
    int X;
    assert(scanf("%d", &X) == 1);

    std::vector<int> C = indices[X];
    for (auto &c : C)
      c = T[c];

    auto D = navigate(K, B, C);

    if (D.size() != C.size()) {
      fprintf(stderr, "returned array D does not have the same size as C\n");
      std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i + 1 < (int)D.size(); i++)
      printf("%d ", D[i]);
    printf("%d\n", D.back());
  }

  int S = 0;
  for (int i = 0; i < N - 1; i++)
    S = std::max(S, T[i] + 1);
  return S;
}
int main() {
  int T;
  assert(scanf("%d", &T) == 1);

  int S = 0;
  for (int i = 0; i < T; i++)
    S = std::max(S, run_testcase());

  fprintf(stderr, "S = %d\n", S);
}
