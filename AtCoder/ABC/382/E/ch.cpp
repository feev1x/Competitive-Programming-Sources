#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }

  // Precompute probabilities for rare cards in a single pack using binomial distribution.
  vector<double> prob(N + 1, 0.0); // prob[j] = probability of exactly j rare cards in one pack
  prob[0] = 1.0; // Base case: 0 rare cards with probability 1 initially.
  
  for (int i = 0; i < N; i++) {
    vector<double> next_prob(N + 1, 0.0);
    for (int j = 0; j <= i; j++) {
      // Either the i-th card is rare or not.
      next_prob[j + 1] += prob[j] * (P[i] / 100.0); // Add one rare card
      next_prob[j] += prob[j] * (1 - P[i] / 100.0); // No rare card
    }
    prob = next_prob;
  }

  // Dynamic programming to compute dp[k]
  vector<double> dp(X + 1, 1e18); // Large initial value
  dp[0] = 0.0; // No packs needed for 0 rare cards

  for (int k = 1; k <= X; k++) {
    for (int j = 0; j <= N; j++) {
      if (j > k) continue; // Can't remove more rare cards than needed
      dp[k] += prob[j] * (1 + dp[k - j]);
    }
  }

  cout << fixed << setprecision(16) << dp[X] << endl;

  return 0;
}

