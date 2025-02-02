/**
 *    author:  feev1x
 *    created: 29.01.2025 09:11:39
**/
#include <bits/stdc++.h>
#include "caesar.h"

constexpr int N = 1e6;

int64_t dp[N], dp1[N], p[N];
int sz;

inline int dis(char a, char b) {
    if (a > b) {
        return a - b;
    } else {
        return 'z' - b + a - 'a' + 1;
    }
}

void init(int n, int q, char A[], char B[]) {
    std::vector<int> cnt(n + 1), cnt1(n + 1);
    cnt1[0]++;
    sz = n;

    for (int i = 1; i < n; ++i) {
        p[i] = p[i - 1];

        if (dis(A[i], A[i - 1]) != dis(B[i], B[i - 1])) {
            p[i]++;
        }

        cnt1[p[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        if (i) {
            dp[i] = dp[i - 1];
        }

        dp[i] += ++cnt[p[i]];
        dp1[i] += --cnt1[p[i]];
    }
}

long long query(int left, int right) {
    if (p[right] - p[left] == 0) {
        return (int64_t)(right - left + 2) * (right - left + 1) / 2;
    }

    int l = left, r = right, ans = 0;
    while (l <= r) {
        int m = l + r >> 1;

        if (p[m] - p[left] == 0) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }

    return dp[right] - dp[ans] + (int64_t)(ans - left + 2) * (ans - left + 1) / 2;
}
