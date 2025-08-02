/**
 *    author:  feev1x
 *    created: 28.07.2025 22:02:25
**/
#include "bits/stdc++.h"

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

const int64_t N = 1e6 + 12, inf = 1e18 + 7, mod = 1e9 + 7;

bool a[N], b[N], sp[N];
std::string sm;

bool check(std::string s, std::string l) {
    int n = s.size(), m = l.size();

    if (n >= m)
        for (int i = n - m; i < n; i++) {
            if (s[i] != l[i - (n - m)]) 
                break;

            if (i == n - 1) 
                return 1;
        }

    return 0;
}

std::string rec(int ind, std::string s, std::string l) {
    if (check(s, l))
        return "";

    if (ind == sm.size() - 1) 
        return s;

    if (b[ind + 1]) {
        for (char i = '0'; i <= '9'; i++) {
            if (a[ind + 1] && i == '0') 
                continue;

            std::string ret = rec(ind + 1, s + i, l);
            if (ret.size()) 
                return ret;
        }

        return "";
    } else
        return rec(ind + 1, s + sm[ind + 1], l);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, l;
    std::cin >> s;
    std::getline(std::cin, l);
    std::getline(std::cin, l);

    std::vector<std::string> smt{""};
    for (auto j: l)
        if (j == ' ')
            smt.push_back("");
        else
            smt.back() += j;

    l = "";
    for (int i = 0; i < smt.size(); i++) {
        if (smt[i].size() > 1)
            a[l.size()] = 1;

        if (i)
            sp[l.size()] = 1;

        l += smt[i];
    }

    std::string smth = "";
    for (int i = 0; i < l.size(); i++) {
        smth += l[i];
        if (check(smth, s))
            for (int j = i - s.size() + 1; j <= i; j++)
                b[j] = 1;
    }

    sm = l;
    std::string res = rec(-1, "", s), ans;
    for (int i = 0; i < res.size(); i++) {
        if (sp[i]) 
            ans += ' ';

        ans += res[i];
    }

    std::cout << ans << '\n';
    return 0;
}
