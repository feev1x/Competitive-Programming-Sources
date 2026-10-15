#include <algorithm>
#include <iostream>
#include <vector>

std::istream& operator>>(std::istream&, __int128&);
std::ostream& operator<<(std::ostream&, const __int128&);

__int128 solve(std::vector<long long> A, int K, long long S, int D);
