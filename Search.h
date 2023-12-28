#ifndef SEARCH_H
#define SEARCH_H
#include "Public1.h"
#include "LinkList.h"
#include "Reality.h"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits>
#include <iostream>
// 重新定义之前的图结构和相关类型
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

// 声明Dijkstra算法的函数
std::vector<Vertex> dijkstraShortestPath(const Graph& g, const Vertex& start, const Vertex& goal);
Status Timetable(LinkedList<Ticket>& TicketList, const std::string& fromStation, const std::string& toStation);
Ticket FindTicketByTrainNumber(LinkedList<Ticket>& TicketList, const std::string& trainNumber);
#endif // SEARCH_H
