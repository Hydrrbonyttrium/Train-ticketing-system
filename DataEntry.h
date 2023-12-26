#ifndef DATAENTRY_H_INCLUDED
#define DATAENTRY_H_INCLUDED


#include "Sqlist.h"
#include "LinkList.h"
#include "LinkQueue.h"
#include <fstream>
#include <sstream>
#include <boost/graph/adjacency_list.hpp>
#include <string>
#include <unordered_map>

// 使用Boost Graph Library定义图
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, boost::no_property, boost::property<boost::edge_weight_t, int>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;
typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;


void ReadUser(SqList<User>& userList);
void ReadTrain(SqList<Train>& TrainList);
void ReadTrainNunmber(SqList<TrainNumber>& TrainNumberList);
void WriteUser(SqList<User>& UserList);
void ReadTicket(LinkedList<Ticket>& TicketList);
void ReadCity(Graph& g, WeightMap& weightmap, std::unordered_map<std::string, Vertex>& stationMap);
void WriteCity(const Graph& g, const WeightMap& weightmap, const std::unordered_map<std::string, Vertex>& stationMap);

#endif // DATAENTRY_H_INCLUDED

