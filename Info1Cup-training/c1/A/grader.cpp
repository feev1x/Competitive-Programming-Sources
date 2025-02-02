#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "game.h"
#include "sol.cpp"

namespace {  
int phase = 1;
std::vector<std::pair<int, int>> chosen;
void propagate() {
    fprintf(stdout, "%d\n", (int)chosen.size());
    fflush(stdout);

    for (int i = 0; i < chosen.size(); i++) {
        fprintf(stdout, "%d %d\n", chosen[i].first, chosen[i].second);
        fflush(stdout);
    }
    chosen.clear();
}
}  // namespace

void chooseInterval(int left, int right) {
    if (chosen.size() < 200000 + 10) {
        chosen.push_back({left, right});
    }
}

int main(int argc, char **argv) {
    int n, m, q;
    if(fscanf(stdin, "%d %d %d", &n, &m, &q) != 3){
      exit(0);
    }
    init(n, m);
    propagate();
    for (int i = 1; i <= q; i++) {
        int x, y;
        if(fscanf(stdin, "%d %d", &x, &y) != 2) {
          exit(0);
        }
        query(x, y);
        propagate();
    }
    return 0;
}
