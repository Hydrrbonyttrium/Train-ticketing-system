#include "Search.h"

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

Status Timetable(LinkedList<Ticket>& TicketList, const std::string& fromStation, const std::string& toStation) {
    std::vector<Ticket> matchingTickets;

    // 遍历链表，找到所有匹配的票
    for (int i = 0; TicketList.GetElemPtr(i) != nullptr; ++i) {
        Ticket tempTicket = TicketList.GetElem(i);
        if (tempTicket.start == fromStation && tempTicket.end == toStation) {
            matchingTickets.push_back(tempTicket);
        }
    }

    // 按发车时间对票进行排序
    std::sort(matchingTickets.begin(), matchingTickets.end(), [](const Ticket& a, const Ticket& b) {
        return a.departure_time < b.departure_time;
    });

    // 打印或返回结果
    for (const auto& ticket : matchingTickets) {
        std::cout << "车次：" << ticket.train_number
                  << ", 离开时间： " << ticket.departure_time
                  << ", 到达时间： " << ticket.arrival_time
                  << ", 座位等级： " << ticket.seat
                  << ", 价格：" << ticket.price << std::endl;
    }
    return OK;
}
