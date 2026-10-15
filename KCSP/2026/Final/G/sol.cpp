#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s; std::cin >> s;
    int n = s.size(), res = 0;
    std::vector<int> cnt(26);
    for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
    for (int i = 2; i < n; ++i) if (s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
        char b1 = 'A', b2 = 'A';
        int cn = n + 5, nd = -1;
        if (i) b1 = s[i - 1];
        if (i + 1 < n) b2 = s[i + 1];
        for (int j = 0; j < 26; ++j) {
            if (j == b1 - 'a' || j == b2 - 'a' || j == s[i] - 'a') continue;
            if (cnt[j] < cn) {
                cn = cnt[j];
                nd = j;
            }
        }
        cnt[s[i] - 'a']--;
        s[i] = char('a' + nd);
        cnt[nd]++;
    }
    int val = -1, sm = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > n / 2) val = i, sm = cnt[i] - n / 2;
    }
    for (int i = 0; sm && i < n; ++i) if (val == s[i] - 'a') {
        sm--;
        char b1 = 'A', b2 = 'A';
        int cn = n + 5, nd = -1;
        if (i) b1 = s[i - 1];
        if (i + 1 < n) b2 = s[i + 1];
        for (int j = 0; j < 26; ++j) {
            if (j == b1 - 'a' || j == b2 - 'a' || j == s[i] - 'a') continue;
            if (cnt[j] < cn) {
                cn = cnt[j];
                nd = j;
            }
        }
        cnt[s[i] - 'a']--;
        s[i] = char('a' + nd);
        cnt[nd]++;
    }
    std::cout << s << '\n';
    return 0;
}
