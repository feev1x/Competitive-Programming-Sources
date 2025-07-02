#include <vector>

// ========== Contestant interface ==========
// These functions are to be implemented by contestant in the solution.

// Solve the problem
//
// Accepts:
// * number of vertices `n`;
// * number of edges `m`;
// * number of queries `q`;
// * vector of pairs of ints edges, vector length is exactly `m`, pair stores indexes of vertices that are connected by edge. Vertices are 0-indexed
// * vector of pairs of ints queries, vector length is exactly `q`, first number is left border of query, second number is the right border of query
//
// Returns:
// vector containing answers for all queries
std::vector<int> Solve(int n, int m, int q, std::vector<std::pair<int, int>> edges, std::vector<std::pair<int, int>> queries);
