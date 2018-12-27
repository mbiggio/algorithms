#ifndef _GRAPH_
#define _GRAPH_
#include <vector>

namespace algorithms { 
namespace graph {

/**
 * In a directed graph, we start at some node and at every turn, 
 * walk along a directed edge of the graph.  
 * If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.
 * Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  
 * More specifically, there exists a natural number K so that for any choice of where to walk, 
 * we must have stopped at a terminal node in less than K steps.
 * Which nodes are eventually safe?  Return them as an array in sorted order.
 * The directed graph has N nodes with labels 0, 1, ..., N-1, 
 * where N is the length of graph.  
 * The graph is given in the following form: 
 * graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.
 */

::std::vector<int> eventual_safe_nodes(const ::std::vector<::std::vector<int>>& graph);

} // graph
} // algorithms

#endif
