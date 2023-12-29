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

    int TicketListLengrh = TicketList.ListLength();
    // 遍历链表，找到所有匹配的票
    for (int i = 1; i < TicketListLengrh; ++i) {
        Ticket tempTicket = TicketList.GetElem(i);
        if (tempTicket.start == fromStation && tempTicket.end == toStation) {
            matchingTickets.push_back(tempTicket);
        }
    }

    // 使用自己的快速排序方法
    if (!matchingTickets.empty()) {
        quickSort(matchingTickets, 0, matchingTickets.size() - 1);
    }

    // 打印表头
    std::cout << std::left
              << std::setw(14) << "Train Number" << " | "
              << std::setw(19) << "Departure Time" << " | "
              << std::setw(19) << "Arrival Time" << " | "
              << std::setw(14) << "Seat" << " | "
              << std::setw(9) << "Price" << " |"
              << std::endl;

    // 输出分割线
    std::cout << std::string(88, '-') << std::endl;

    // 打印每行的结果
    for (const auto& ticket : matchingTickets) {
        std::cout << std::left
                  << std::setw(14) << ticket.train_number << " | "
                  << std::setw(19) << ticket.departure_time << " | "
                  << std::setw(19) << ticket.arrival_time << " | "
                  << std::setw(14) << ticket.seat << " | "
                  << std::setw(9) << ticket.price << " |"
                  << std::endl;
    }

    return matchingTickets.empty() ? ERROR : OK;
}

Ticket FindTicketByTrainNumber(LinkedList<Ticket>& TicketList, const std::string& trainNumber) {
    for (int i = 0; TicketList.GetElemPtr(i) != nullptr; ++i) {
        Ticket tempTicket = TicketList.GetElem(i);
        if (tempTicket.train_number == trainNumber) {
            return tempTicket; // 找到匹配的票，返回该票
        }
    }
    return Ticket(); // 如果没有找到匹配的票，返回一个空的 Ticket 对象
}

Ticket FindTicketByTrainNumberAndSeat(LinkedList<Ticket>& TicketList, const std::string& trainNumber, const std::string& SeatType) {
    for (int i = 0; TicketList.GetElemPtr(i) != nullptr; ++i) {
        Ticket tempTicket = TicketList.GetElem(i);
        if (tempTicket.train_number == trainNumber && tempTicket.seat == SeatType) {
            return tempTicket; // 找到匹配的票，返回该票
        }
    }
    return Ticket(); // 如果没有找到匹配的票，返回一个空的 Ticket 对象
}

void quickSort(std::vector<Ticket>& tickets, int low, int high) {
    if (low < high) {
        int pivot = partition(tickets, low, high);
        quickSort(tickets, low, pivot - 1);
        quickSort(tickets, pivot + 1, high);
    }
}

int partition(std::vector<Ticket>& tickets, int low, int high) {
    Ticket pivot = tickets[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (tickets[j].departure_time < pivot.departure_time) {
            i++;
            std::swap(tickets[i], tickets[j]);
        }
    }
    std::swap(tickets[i + 1], tickets[high]);
    return (i + 1);
}

