#include "graph.hpp"

namespace algorithms { 
namespace graph {


/*********** eventual_safe_nodes *************/
namespace {
bool dfs(int node, ::std::vector<int> &color, const ::std::vector<::std::vector<int>> &graph) {
  if (color[node] > 0)
    return color[node] == 2;

  color[node] = 1;
  for (int nei : graph[node]) {
    if (color[node] == 2)
      continue;
    if (color[nei] == 1 || !dfs(nei, color, graph))
      return false;
  }

  color[node] = 2;
  return true;        
}
} // anonymous


::std::vector<int> eventual_safe_nodes(const ::std::vector<::std::vector<int>>& graph) {
  int n = graph.size();
  ::std::vector<int> color(n);
  ::std::vector<int> ans;

  for (int i = 0; i < n; ++i)
    if (dfs(i, color, graph))
      ans.emplace_back(i);
  return ans;
}


} // graph
} // algorithms
