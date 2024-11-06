/**
 *    author:  feev1x
 *    created: 05.11.2024 09:15:10
**/
#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    vector<pair<int, int>> a(n), srt(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a[i].first, &a[i].second);
      srt[i].first = max(a[i].first, a[i].second);
      srt[i].second = i;
    }
    sort(srt.begin(), srt.end(), [&](pair<int, int> fr, pair<int, int> sc) {
        if (fr.first == sc.second) {
          int mnf = min(a[fr.second].first, a[fr.second].second);
          int mns = min(a[sc.second].first, a[sc.second].second);
          return mnf < mns;
        }
        return fr.first < sc.first;
        });
    vector<int> A;
    for (auto [sm, i]: srt) {
      A.emplace_back(a[i].first);
      A.emplace_back(a[i].second);
    }
    for (int i = 0; i < n; ++i) {
      srt[i].first = min(a[i].first, a[i].second);
      srt[i].second = i;
    }
    sort(srt.begin(), srt.end(), [&](pair<int, int> fr, pair<int, int> sc) {
        if (fr.first == sc.second) {
          int mnf = max(a[fr.second].first, a[fr.second].second);
          int mns = max(a[sc.second].first, a[sc.second].second);
          return mnf < mns;
        }
        return fr.first < sc.first;
        });
    vector<int> B;
    for (auto [sm, i]: srt) {
      B.emplace_back(a[i].first);
      B.emplace_back(a[i].second);
    }
    auto Count = [](vector<int> a) {
      int n = a.size();
      ll cnt = 0;
      ordered_set st;
      for (int i = 0; i < n; ++i) {
        auto it = st.upper_bound(a[i]);
        if (it == st.end()) {
          st.insert(a[i]);
          continue;
        }
        cnt += st.size() - st.order_of_key(*it);
        st.insert(a[i]);
      }
      debug(cnt);
      return cnt;
    };
    if (Count(A) > Count(B)) {
      for (auto u: A) {
        printf("%d ", u);
      }
    } else {
      for (auto u: B) {
        printf("%d ", u);
      }
    }
    printf("\n");
  }
  return 0;
}
