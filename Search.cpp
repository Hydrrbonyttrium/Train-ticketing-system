#include "Search.h"
#include "Reality.h"
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <vector>
#include <limits>
#include <iostream>

struct TrainNumber timetable[MAX_TIMETABLE_SIZE];

std::vector<Vertex> dijkstraShortestPath(const Graph& g, const Vertex& start, const Vertex& goal) {
    std::vector<Vertex> predecessors(num_vertices(g)); // 用于存储路径
    std::vector<int> distances(num_vertices(g)); // 用于存储距离

    // Dijkstra算法
    boost::dijkstra_shortest_paths(g, start, boost::predecessor_map(&predecessors[0]).distance_map(&distances[0]));

    // 从goal回溯到start以获得路径
    std::vector<Vertex> path;
    for (Vertex v = goal; v != start; v = predecessors[v]) {
        path.push_back(v);
        if (predecessors[v] == v) {
            path.clear();
            break; // 无法到达
        }
    }
    if (!path.empty()) {
        path.push_back(start);
    }
    std::reverse(path.begin(), path.end());

    return path;
}
// 查询时刻表
static void queryTimetable(const std::vector<TrainNumber>& entries, const std::string& trainNumberOrStation) {
        for (const TrainNumber& entry : entries) {
            if (entry.number == trainNumberOrStation || entry.begin == trainNumberOrStation || entry.end == trainNumberOrStation) {
                std::cout << "车次: " << entry.number << std::endl;
                std::cout << "始发站: " << entry.begin << std::endl;
                std::cout << "终点站: " << entry.end << std::endl;
                std::cout << "发车时间: " << entry.timetable << std::endl;
                std::cout << "可售票数量: " << entry.ticket_number << std::endl;
                std::cout << "距离: " << entry.distance << " 公里" << std::endl;
                std::cout << "车程时间: " << entry.train_distance << " 小时" << std::endl;
                std::cout << "车厢类型: " << entry.carriage << std::endl;
                return;
            }
        }

        std::cout << "未找到与 " << trainNumberOrStation << " 相关的时刻表信息。" << std::endl;
    }

// 查询票价和余票
void queryTicketPrice(const std::vector<Ticket>& tickets, const std::vector<TrainNumber>& timetable) {
    std::string trainNumber;
    std::cout << "\n输入车次: ";
    std::cin >> trainNumber;

    // 查找对应车次的票价和余票信息
    for (const Ticket& ticket : tickets) {
        if (ticket.train_number == trainNumber) {
            // 找到匹配的车次，输出相关信息
            std::cout << "车次: " << ticket.train_number << std::endl;
            std::cout << "起始站: " << ticket.start << std::endl;
            std::cout << "终点站: " << ticket.end << std::endl;
            std::cout << "座位类型: " << ticket.seat << std::endl;
            std::cout << "票价: " << ticket.price << " 元" << std::endl;
            std::cout << "余票数量: " << ticket.remains << std::endl;

            // 查找对应车次的时刻表信息
            for (const TrainNumber& entry : timetable) {
                if (entry.number == trainNumber) {
                    std::cout << "发车时间: " << entry.timetable << std::endl;
                    std::cout << "距离: " << entry.distance << " 公里" << std::endl;
                    std::cout << "车程时间: " << entry.train_distance << " 小时" << std::endl;
                    std::cout << "车厢类型: " << entry.carriage << std::endl;
                    break;  // 找到匹配项后结束循环
                }
            }

            return;  // 找到匹配项后结束函数
        }
    }

    // 如果循环结束仍未找到匹配项，输出未找到的信息
    std::cout << "未找到车次为 " << trainNumber << " 的票价和余票信息。" << std::endl;
}

// 查看个人订单
void viewOrders(const std::vector<Ticket>& userTickets) {
    // 检查用户是否有车票
    if (userTickets.empty()) {
        std::cout << "您还没有购买任何车票。" << std::endl;
        return;
    }

    // 遍历用户车票并输出相关信息
    std::cout << "您的车票信息如下：" << std::endl;
    for (const Ticket& ticket : userTickets) {
        std::cout << "车次: " << ticket.train_number << std::endl;
        std::cout << "起始站: " << ticket.start << std::endl;
        std::cout << "终点站: " << ticket.end << std::endl;
        std::cout << "座位类型: " << ticket.seat << std::endl;
        std::cout << "票价: " << ticket.price << " 元" << std::endl;
        std::cout << "余票数量: " << ticket.remains << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
//最优站点查询
void optimalStationQuery(const Graph& stationGraph, const Vertex& start, const Vertex& goal) {
    // 使用 Dijkstra 算法查找最优站点
    std::vector<Vertex> optimalPath = dijkstraShortestPath(stationGraph, start, goal);

    // 输出最优站点
    std::cout << "最优站点路径: ";
    for (const auto& station : optimalPath) {
        std::cout << station << " -> ";
    }
    std::cout << "End" << std::endl;
}

