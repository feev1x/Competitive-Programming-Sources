#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    a[i] %= m;  // Directly take a[i] modulo m
  }
  
  vector<ll> prefix_count(m, 0);  // To count occurrences of each prefix mod value
  ll prefix_sum = 0, res = 0;
  prefix_count[0] = 1;  // Base case for subarrays starting from the beginning
  
  for (int i = 1; i <= n; ++i) {
    prefix_sum = (prefix_sum + a[i]) % m;
    if (prefix_sum < 0) prefix_sum += m;  // Ensure non-negative

    // Add the count of prefix sums that match `prefix_sum`
    res += prefix_count[prefix_sum];
    
    // Increment count for this prefix_sum mod value
    prefix_count[prefix_sum]++;
  }
  
  printf("%lld\n", res);
  return 0;
}
