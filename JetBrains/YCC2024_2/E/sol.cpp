/**
 *    author:  feev1x
 *    created: 29.10.2024 09:15:23
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, heal, reg; cin >> n >> heal >> reg;
  vector<int> pw(n), dmg(n);
  for (int i = 0; i < n; ++i) {
    cin >> pw[i] >> dmg[i];
  }
  if (heal > *max_element(pw.begin(), pw.end())) {
    cout << "NO\n";
    return 0;
  }
  vector<bool> used(n);
  vector<pair<int, int>> ans;
  int hp = heal, ac = reg, ls = 0;
  while (hp > 0) {
    int ind = -1, tm = 2e9, dmgg = 0;
    for (int i = 0; i < n; ++i) {
      if (used[i]) continue;
      if (ind == -1) {
        if (ac >= 0) {
          if (hp > pw[i]) continue;
          ind = i;
          tm = ls;
          dmgg = dmg[i];
        } else if (hp > pw[i]) {
          ind = i;
          tm = ls + (hp - pw[i] + (-ac - 1)) / (-ac);
          dmgg = dmg[i];
        } else {
          tm = ls;
          dmgg = dmg[i];
          ind = i;
        }
      }
      if (ac >= 0) {
        if (hp > pw[i]) continue;
        if (tm > ls) {
          tm = ls;
          dmgg = dmg[i];
          ind = i;
        } else if (tm == ls) {
          if (dmgg < dmg[i]) {
            ind = i;
            dmgg = dmg[i];
          }
        }
      } else {
        if (hp <= pw[i]) {
          if (tm > ls) {
            tm = ls;
            dmgg = dmg[i];
            ind = i;
          } else {
            if (dmgg < dmg[i]) {
              ind = i;
              dmgg = dmg[i];
            }
          }
        }
        if (tm > ls + (hp - pw[i] + (-ac - 1)) / (-ac)) {
          tm = ls + (hp - pw[i] + (-ac - 1)) / (-ac);
          dmgg = dmg[i];
          ind = i;
        } else if (tm == ls + (hp - pw[i] + (-ac - 1)) / (-ac)) {
          if (dmgg < dmg[i]) {
            ind = i;
            dmgg = dmg[i];
          }
        }
      }
    }
    debug(ac, hp, tm, ls);
    if (ind == -1) break;
    if (ac < 0 && hp + ac * (tm - ls) <= 0) {
      break;
    }
    used[ind] = true;
    ans.emplace_back(tm, ind + 1);
    hp += ac * (tm - ls);
    hp -= dmgg;
    ls = tm + 1;
    ac -= dmgg;
    hp = min(hp, heal);
    debug(ls);
  }
  cout << "YES\n";
  cout << ls - 1 + (hp > 0 ? (hp + (-ac)) / (-ac) : 0) << ' ' << ans.size();
  cout << '\n';
  for (auto [l, r]: ans) cout << l << ' ' << r << '\n';
  return 0;
}
