#ifndef SEARCH_H
#define SEARCH_H

#include <boost/graph/adjacency_list.hpp>
#include <string>
#include <unordered_map>

// 重新定义之前的图结构和相关类型
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

// 声明Dijkstra算法的函数
std::vector<Vertex> SearchForCityShortestPath(const Graph& g, const Vertex& start, const Vertex& goal);

#endif // SEARCH_H
