#include <vector>

std::vector<std::pair<long long, long long>> solve(std::vector<long long> a) {
    std::vector<std::pair<long long, long long>> ret;
    for (int i = 0; i < (int) a.size(); i += 2) {
    	ret.push_back({a[i], a[i + 1]});
    }
    return ret;
}
