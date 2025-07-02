#include "segments.h"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void wrong_answer(const string& message) {
    cout << "Wrong answer: " << message << "\n";
    exit(1);
}

constexpr int kMul = 60;
constexpr int kAdd = 1000;

namespace data {
    int n;
    vector<int> arr;
    vector<int> query_answer;
    vector<bool> asked;
    int limit;
    int query_count;
    int required_length;
    bool answered;
}

using namespace data;

void clear_data() {
    n = 0;
    arr.clear();
    query_answer.clear();
    asked.clear();
    limit = 0;
    query_count = 0;
    required_length = 0;
    answered = false;
};

void run_testcase() {
    clear_data();

    cin >> n;

    arr.resize(n);
    query_answer.resize(n);
    asked.resize(n, false);
    asked[n - 1] = true;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int last = n;
    for (int i = n - 1; i >= 0; --i) {
        query_answer[i] = last;
        required_length = max(required_length, last - i);
        if (i > 0 && arr[i] != arr[i - 1]) {
            last = i;
        }
    }

    limit = ((n + required_length - 1) / required_length) * kMul + kAdd;

    solve(n);
}

int check_position(int pos) {
    cout << "? " << pos << "\n";

    if (answered) {
        wrong_answer("test case already solved");
    }

    if (pos < 0 || pos >= n) {
        wrong_answer("incorrect position");
    }

    ++query_count;
    if (query_count > limit) {
        wrong_answer("too many queries");
    }

    int r = query_answer[pos];
    asked[r - 1] = true;
    return r;
}

void answer(int left, int right) {
    cout << "! " << left << " " << right << "\n";

    if (answered) {
        wrong_answer("test case already solved");
    }

    if (right - left + 1 != required_length) {
        wrong_answer("incorrect segment length");
    }

    if (left < 0 || left >= n || right < 0 || right >= n) {
        wrong_answer("incorrect segment bounds");
    }

    if (query_answer[left] != right + 1) {
        wrong_answer("wrong segment was found");
    }

    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (asked[i - 1]) {
            if (i - pos > required_length) {
                wrong_answer("the answer is correct, but there exists an array with longer segment");
            }
            pos = i;
        }
    }

    answered = true;

    cout << "[OK, " << query_count << " queries used]\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_count;
    cin >> test_count;

    for (int i = 0; i < test_count; ++i) {
        run_testcase();
    }

    return 0;
}