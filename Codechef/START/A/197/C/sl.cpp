#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<double> A(N + 1), B(N + 1), dp(N + 2, 1e18);

    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) cin >> B[i];

    dp[N + 1] = 0;
    for (int iter = 0; iter < 50; ++iter) {
      double total = accumulate(dp.begin() + 1, dp.begin() + N + 2, 0.0);
      for (int x = N; x >= 1; --x) {
        double walk = A[x] + dp[x + 1];
        double teleport = B[x] + total / (N + 1);
        dp[x] = min(walk, teleport);
      }
    }

    cout << fixed << setprecision(10) << dp[1] << '\n';
  }
}
