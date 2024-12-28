/**
 *    smots gaming: smots gaming 
 *    smots gaming: smots gaming
**/

#include <bits/stdc++.h>

#define smots_gaming5 long long
#define smots_gaming6 int
#define smots_gaming7 main
#define smots_gaming8 std
#define smots_gaming9 ios_base
#define smots_gaming10 sync_with_stdio
#define smots_gaming11 vector
#define smots_gaming12 map

smots_gaming6 smots_gaming7() {
  smots_gaming8::smots_gaming9::smots_gaming10(false);
  smots_gaming8::cin.tie(nullptr);

  smots_gaming6 smots_gaming_n;
  smots_gaming5 smots_gaming_s;
  smots_gaming8::cin >> smots_gaming_n >> smots_gaming_s;

  smots_gaming8::smots_gaming11<smots_gaming5> smots_gaming_a(smots_gaming_n + 1);
  smots_gaming8::smots_gaming11<smots_gaming5> smots_gaming_pref(smots_gaming_n + 1);
  smots_gaming8::smots_gaming11<smots_gaming5> smots_gaming_suf(smots_gaming_n + 2);
  smots_gaming8::smots_gaming12<smots_gaming5, bool> smots_gaming_mp;

  smots_gaming5 smots_gaming_sum = 0;
  smots_gaming_mp[0] = true;

  for (smots_gaming6 smots_gaming_i = 1; smots_gaming_i <= smots_gaming_n; ++smots_gaming_i) {
    smots_gaming8::cin >> smots_gaming_a[smots_gaming_i];
    smots_gaming_sum += smots_gaming_a[smots_gaming_i];
    smots_gaming_pref[smots_gaming_i] = smots_gaming_pref[smots_gaming_i - 1] + smots_gaming_a[smots_gaming_i];
    smots_gaming_mp[smots_gaming_pref[smots_gaming_i]] = true;
  }

  for (smots_gaming6 smots_gaming_i = smots_gaming_n; smots_gaming_i >= 1; --smots_gaming_i) {
    smots_gaming_suf[smots_gaming_i] = smots_gaming_suf[smots_gaming_i + 1] + smots_gaming_a[smots_gaming_i];
    smots_gaming5 smots_gaming_ost = (smots_gaming_s - smots_gaming_suf[smots_gaming_i]) % smots_gaming_sum;
    if (smots_gaming_mp[smots_gaming_ost]) {
      smots_gaming8::cout << "Yes\n";
      return 0;
    }
  }

  smots_gaming8::cout << "No\n";
  return 0;
}
