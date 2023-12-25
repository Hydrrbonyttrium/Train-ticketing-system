#ifndef SEARCH_H
#define SEARCH_H

#include <boost/graph/adjacency_list.hpp>
#include <string>
#include <unordered_map>

// ���¶���֮ǰ��ͼ�ṹ���������
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

// ����Dijkstra�㷨�ĺ���
std::vector<Vertex> SearchForCityShortestPath(const Graph& g, const Vertex& start, const Vertex& goal);

#endif // SEARCH_H
