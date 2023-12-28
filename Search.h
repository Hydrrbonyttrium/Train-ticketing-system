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
// ���¶���֮ǰ��ͼ�ṹ���������
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

// ����Dijkstra�㷨�ĺ���
std::vector<Vertex> dijkstraShortestPath(const Graph& g, const Vertex& start, const Vertex& goal);
Status Timetable(LinkedList<Ticket>& TicketList, const std::string& fromStation, const std::string& toStation);
Ticket FindTicketByTrainNumber(LinkedList<Ticket>& TicketList, const std::string& trainNumber);
#endif // SEARCH_H
