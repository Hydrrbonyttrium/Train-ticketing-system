#include "Search.h"
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <vector>
#include <limits>

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
