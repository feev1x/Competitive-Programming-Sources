#include "arithmetic_progression.h"
#include <iostream>
#include <vector>

std::istream& operator>> (std::istream& inp, __int128& n)
{
    std::string num;
    inp >> num;
    n=0;
    bool negative=false;
    for (auto c : num) {
        n*=10;
        if (c=='-') negative=true;
        else n+=(c-'0');
    }
    if (negative==true) n*=(-1);
    return inp;
}

std::ostream& operator<< (std::ostream& out, const __int128& n)
{
    std::string digs="";
    bool negative=false;
    __int128 tmp=n;
    if (tmp<0) {
        negative=true;
        tmp*=(-1);
    }
    for (;;) {
        digs+=(tmp%10+'0');
        tmp/=10;
        if (tmp==0) break;
    }
    reverse(digs.begin(),digs.end());
    if (negative==true) out << "-";
    out << digs ;
    return out;
}

int main(int argc, char **args)
{
    std::ios_base :: sync_with_stdio(0);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, k;
    long long s;
    int d;
    std::vector <long long> A;
    std::cin >> n >> k >> s >> d;
    A.resize(n);

    for (int i = 0 ; i < n ; ++i)
    {
        std::cin >> A[i];
    }

    std::cout << solve(A, k, s, d) << '\n';
    return 0;
}
