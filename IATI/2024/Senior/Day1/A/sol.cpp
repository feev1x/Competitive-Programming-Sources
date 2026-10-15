#include <bits/stdc++.h>
#include "ones.h"

inline std::vector<int> get(int l, int r, int nd) {
    if (l == r) return std::vector<int>{l};
    int m = l + r >> 1;
    std::vector<int> res;
    if (std::rand() % 2 == 0) {
        if (hasOnes(l, m)) {
            auto got = get(l, m, nd);
            for (auto u: got) res.emplace_back(u);
        }
        if (res.empty() || res.size() < nd && hasOnes(m + 1, r)) {
            auto got = get(m + 1, r, nd - res.size());
            for (auto u: got) res.emplace_back(u);
        }
        return res;
    } else {
        if (hasOnes(m + 1, r)) {
            auto got = get(m + 1, r, nd);
            for (auto u: got) res.emplace_back(u);
        }
        if (res.empty() || res.size() < nd && hasOnes(l, m)) {
            auto got = get(l, m, nd - res.size());
            for (auto u: got) res.emplace_back(u);
        }
        std::sort(res.begin(), res.end());
        return res;
    }
}

std::vector<int> Get(int l, int r) {
    std::vector<int> res;
    int n = r;
    while (l <= r && hasOnes(l, r)) {
        if (l == r) {
            res.emplace_back(l);
            break;
        }
        while (l < r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            m1 = l + r >> 1;
            if (hasOnes(l, m1)) r = m1;
            else l = m1 + 1;
        }
        res.emplace_back(l);
        l++, r = n;
    }
    return res;
}

std::vector<int> Get2(int l, int r) {
    std::vector<int> res;
    int n = r;
    while (l <= r && hasOnes(l, r)) {
        if (l == r) {
            res.emplace_back(l);
            break;
        }
        while (l < r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (hasOnes(l, m1)) r = m1;
            else l = m1 + 1;
        }
        res.emplace_back(l);
        l++, r = n;
    }
    return res;
}

std::vector<int> guessOnes(int n, int k) {
    std::srand(std::time(nullptr));
    if (k < 2000) {
        int val = n / k;
        std::vector<int> res;
        for (int i = 1; i <= n; i += val) {
            assert(i + val - 1 <= n);
            auto got = Get(i, i + val - 1);
            for (auto u: got) res.emplace_back(u);
        }
        return res;
    }
    int val = n / k;
    std::vector<int> res;
    for (int i = 1; i <= n; i += val) {
        assert(i + val - 1 <= n);
        auto got = Get2(i, i + val - 1);
        for (auto u: got) res.emplace_back(u);
    }
    return res;
}
