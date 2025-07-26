/**
 *    author:  feev1x
 *    created: 08.07.2025 11:24:37
**/
#include <bits/stdc++.h>
#include "message.h"

void send_message(std::vector<bool> M, std::vector<bool> c) {
    std::vector<bool> pck(31), ok(31);
    for (int j = 0; j < 31; ++j) {
        for (int i = 0; i < 31; ++i) {
            if (c[i]) {
                pck[i] = rand() % 2;
            } else {
                pck[i] = c[j];
            }
        }

        auto pk = send_packet(pck);
    }

    for (int i = 0; i < M.size();) {
        for (int j = 0; i < M.size() && j < 31; ++j) {
            if (c[j]) {
                pck[j] = rand() % 2;
            } else {
                pck[j] = M[i++];
            }
        }

        send_packet(pck);
    }

    int sz = M.size();
    for (int j = 0, i = 0; j < 31; ++j) {
        if (c[j]) {
            pck[j] = rand() % 2;
        } else {
            pck[j] = sz >> i & 1;
            i++;
        }
    }

    send_packet(pck);
}

std::vector<bool> receive_message(std::vector<std::vector<bool>> R) {
    std::vector<bool> c(31);
    int cnt = 0;

    for (int j = 0; j < 31; ++j) {
        int cnt0 = 0, cnt1 = 0;

        for (int i = 0; i < 31; ++i) {
            if (R[j][i]) {
                cnt1++;
            } else {
                cnt0++;
            }
        }

        if (cnt0 > cnt1) {
            c[j] = 0;
        } else {
            c[j] = 1;
        }
    }

    std::vector<bool> ans;
    for (int idx = 31 ;idx + 1 < R.size(); ++idx) {
        auto pck = R[idx];

        for (int i = 0; i < 31; ++i) {
            if (c[i]) {
                continue;
            }

            ans.emplace_back(pck[i]);
        }
    }

    int sz = 0;
    for (int i = 0, j = 0; i < 31; ++i) {
        if (c[i]) {
            continue;
        }

        if (R.back()[i]) {
            sz |= 1 << j;
        }

        j++;
    }

    ans.resize(sz);

    return ans;
}
