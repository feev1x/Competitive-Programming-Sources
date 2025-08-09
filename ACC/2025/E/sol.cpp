#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t _n, _k; std::cin >> _n >> _k;

    __int128 n = _n, k = _k;

    std::string s; std::cin >> s;

    std::vector<__int128> p(n + 1);
    for (__int128 i = 0; i < n; ++i)
        p[i + 1] = p[i] + (s[i] == '+');

//    auto Val = [](std::string s) {
//        int64_t res = 0;
//
//        for (auto u: s)
//            res = (res * 10) + u - '0';
//
//        return res;
//    };
//
//    std::vector<int> pos, pb(1, 0);
//    std::vector<__int128> a, p(1, 0);
//    std::vector<std::string> b;
//    for (int i = 0; i < n; ++i) {
//        int j = i;
//
//        std::string t;
//        while (s[j] != '+')
//            t += s[j];
//
//        pos.emplace_back(i);
//        b.emplace_back(t);
//
//        int64_t val = Val(t);
//        if (t.size() > 17 || val > k) {
//            a.emplace_back(-1);
//            p.emplace_back(p.back());
//            pb.emplace_back(pb.back() + 1);
//        } else {
//            a.emplace_back(val);
//            p.emplace_back(p.back() + val);
//            pb.emplace_back(pb.back());
//        }
//
//        i = j;
//    }

    int64_t r = 0;
    __int128 sum = 0, ls = 0, fr = 0, ten = 1;
    int64_t res = 0;
    for (int64_t l = 0; l < n; ++l) {
        if (s[l] == '+') {
            fr = 0;
            continue;
        }

        if (r <= l)
            r = l, sum = ls = fr = s[l] - '0', ten = 1;

        if (sum > k)
            continue;

        if (fr == 0) {
            int64_t i = l;

            ten = 1;
            while (i <= r && s[i] != '+')
                fr = (fr * 10) + s[i] - '0', ten = ten * 10, i++;

            ten /= 10;
        }

        while (r + 1 < n) {
            if (s[r] == '+' && s[r + 1] == '+')
                break;

            if (s[r + 1] == '+') {
                ls = 0, r++;
                continue;
            }

            if (sum - ls + (ls * 10) + s[r + 1] - '0' > k)
                break;

            sum -= ls;

            ls = (ls * 10) + s[r + 1] - '0';
            if (p[r + 2] - p[l] == 0)
                fr = ls, ten *= 10;

            sum += ls;

            r++;
        }

        res += (r - l + 1 - p[r + 1] + p[l]);

        sum -= fr;

        fr = fr - (fr / ten) * ten; ten /= 10;
        if (p[r + 1] - p[l] == 0)
            ls = fr;

        sum += fr;


//        std::cout << (int64_t)res << ' ' << (int64_t)l << ' ' << (int64_t)r << ' ' << (int64_t)sum << ' ' << (int64_t)ten << ' ' << (int64_t)fr << ' ' << (int64_t)ls << '\n';
    }

    std::cout << (int64_t)res << '\n';
    return 0;
}
