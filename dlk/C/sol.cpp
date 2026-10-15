#include <bits/stdc++.h>

#define int int64_t

constexpr int N = 1e4 + 5;

inline bool prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int p, type; std::cin >> p >> type;
  if (!prime(p)) assert(false);
  if (type != 1 && p > 5) {
    std::map<std::vector<int>, int> code;
    std::vector<std::vector<int>> ps(p + 1);
    std::vector<std::set<int>> mp(p + 1);
    std::vector<int> vl(p + 1), cd(p + 1);
    int nw = 0;
    for (int i = 0, x = 1; i < p; ++i, x = (x * 10) % p) {
      std::vector<int> v;
      vl[p - i] = x;
      for (int y = 0, c = 0; c < 10; ++c, y = (y + x) % p) {
        v.emplace_back(y);
      }
      std::sort(v.begin(), v.end());
      if (code.count(v)) {
      } else {
        code[v] = nw++;
      }
      cd[p - i] = code[v];
      ps[p - i] = v;
      mp[cd[p - i]].emplace(p - i);
    }
    int sum = 0, pos = -1;
    for (int i = 0; i <= p; ++i) if (mp[i].size()) {
      auto key = ps[*mp[i].begin()];
      auto &val = mp[i];
      std::vector<int> v;
      for (auto u: key) {
        v.emplace_back((p - u) % p);
      }
      std::sort(v.begin(), v.end());
      int mpv = 0, cc = code[v];
      mpv = mp[cc].size();
      if (mpv < (int)val.size()) pos = *val.begin();
      sum += std::abs(mpv - (int)val.size());
    }
    std::cout << "0 " << pos << std::endl;
    mp[cd[pos]].erase(pos);
    for (int nw = 2; nw <= p; nw += 2) {
      int d, pos; std::cin >> d >> pos;
      mp[cd[pos]].erase(pos);
      std::vector<int> v;
      for (auto u: ps[pos]) {
        v.emplace_back((p - u) % p);
      }
      std::sort(v.begin(), v.end());
      int cc = code[v];
      int contr = *mp[cc].begin(), contrv = 0;
      mp[cc].erase(mp[cc].begin());
      for (int i = 0; i < 10; ++i) {
        if (((i * vl[contr]) % p + (d * vl[pos]) % p) % p == 0) {
          contrv = i;
          break;
        }
      }
      std::cout << contrv << ' ' << contr << std::endl;
    }
  } else if (p <= 5) {
    if (p != 3) {
      std::cout << "0 " << p << std::endl;
      std::set<int> ps;
      for (int i = 1; i < p; ++i) ps.emplace(i);
      for (int nw = 2; nw <= p; nw += 2) {
        int d, pos; std::cin >> d >> pos;
        ps.erase(pos);
        
        if (p > 2) {
          std::cout << "0 " << *ps.begin() << std::endl;
          ps.erase(ps.begin());
        }
      }
    } else {
      std::cout << "0 " << p << std::endl;
      int d, pos; std::cin >> d >> pos;
      d %= 3;
      d = (3 - d) % 3;
      std::cout << d << ' ' << (pos == 1 ? 2 : 1) << std::endl;
    }
  } else {
    int sum = 0, ls = 0;
    std::vector<int> vl;
    for (int i = 0, x = 1; i < p; ++i, x = (x * 10) % p) {
      vl.emplace_back(x);
    }
    std::reverse(vl.begin(), vl.end());
    for (int i = 1; i <= p; ++i) {
      sum = (sum + vl[i - 1]) % p;
      if (sum == 0) ls = i;
    }
    if (ls == p) {
      std::cout << "1 " << p << std::endl;
    } else {
      std::cout << "0 " << p << std::endl;
    }
    int rn = p - 1;
    for (int nw = 2; nw <= p; nw += 2) {
      int d, pos; std::cin >> d >> pos;
      if (rn <= ls) std::cout << 1;
      else std::cout << 0;
      std::cout << ' ' << rn-- << std::endl;
    }
  }
  return 0;
}
