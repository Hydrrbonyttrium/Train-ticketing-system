#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
#include "LinkList.h"

using namespace std;

int main() {
    // 初始化用户表
    SqList<User> user_list;
    user_list.InitList();
    ReadUser(user_list);

    User current_user;
    /*****************************
     * 这里实现登录
     * 将登陆完成的User赋值给current_user
     * 给后续使用
    *****************************/
    // 这里使用一个示例
    // 注册新用户
//    User newUser = {"zhangsan", "password123", "New User"};
//    if (Register(user_list, newUser)) {
//        std::cout << "注册成功！" << std::endl;
//    }

    // 用户登录
    std::string account, password;
    std::cout << "请输入账号: ";
    std::cin >> account;
    std::cout << "请输入密码: ";
    std::cin >> password;

    if (Login(user_list, account, password, current_user)) {
        std::cout << "登录成功！欢迎 " << current_user.name << std::endl;
    } else {
        std::cout << "登录失败！" << std::endl;
    }

    //初始化票的链表
    LinkedList<Ticket> ticket_list;
    ReadTicket(ticket_list);

    Ticket ticket_to_purchase;
    /*****************************
     * 这里实现票的搜索
     * 将搜索且选中的票赋值给ticket_to_purchase
    *****************************/
    // 这里使用一个示例
//    ticket_to_purchase = ticket_list.GetElem(1);

    // 测试一下购票
//    if (PurchaseTicket(current_user, ticket_to_purchase)) {
//        cout << "购票成功" << endl;
//    } else {
//        cout << "已加入等候列表中" << endl;
//    }

    // 测试完成将结果写入
    // 注意这里要删除一个插入一个
//    int user_delete_index;
//    User user_delete_temp;
//    user_delete_index = user_list.LocateElem(current_user, UserCompare);
//    user_list.ListDelete(user_delete_index, user_delete_temp);
//    user_list.ListInsert(user_delete_index, current_user);
//
//    WriteUser(user_list);

    Graph g;
    WeightMap weightmap = get(boost::edge_weight, g);
    std::unordered_map<std::string, Vertex> stationMap;

    // 读取图数据
    ReadCity(g, weightmap, stationMap);

    // 显示读取的数据，作为测试
//    std::cout << "Initial Graph:" << std::endl;
//    for (auto& pair : stationMap) {
//        auto edges = out_edges(pair.second, g);
//        for (auto edge : make_iterator_range(edges)) {
//            Vertex target = boost::target(edge, g);
//            for (const auto& targetPair : stationMap) {
//                if (targetPair.second == target) {
//                    std::cout << pair.first << " - " << targetPair.first << " : " << weightmap[edge] << std::endl;
//                }
//            }
//        }
//    }

    // 这里可以对图进行一些修改，比如添加或删除边
    // 示例：添加一个新的边
//    std::string newStation1 = "NewStation1";
//    std::string newStation2 = "NewStation2";
//    Vertex newU = add_vertex(g);
//    Vertex newV = add_vertex(g);
//    stationMap[newStation1] = newU;
//    stationMap[newStation2] = newV;
//    Edge newE;
//    bool inserted;
//    tie(newE, inserted) = add_edge(newU, newV, g);
//    weightmap[newE] = 100; // 假设距离为100
//
//    // 将修改后的图数据写回文件
//    WriteCity(g, weightmap, stationMap);

//    std::cout << "Graph modification and writing complete." << std::endl;

    // 测试Dijkstra算法
    // 选择起点和终点
    std::string startStation = "Kunshannan Railway Station";
    std::string endStation = "Nanjingnan Railway Station"; // 示例终点

    // 确保起点和终点都在stationMap中
    if (stationMap.find(startStation) != stationMap.end() && stationMap.find(endStation) != stationMap.end()) {
        // 获取起点和终点的顶点
        Vertex startVertex = stationMap[startStation];
        Vertex endVertex = stationMap[endStation];

        // 计算最短路径
        std::vector<Vertex> path = dijkstraShortestPath(g, startVertex, endVertex);

        // 输出最短路径
        std::cout << "Shortest path from " << startStation << " to " << endStation << ":" << std::endl;
        for (Vertex v : path) {
            for (auto& pair : stationMap) {
                if (pair.second == v) {
                    std::cout << pair.first << " -> ";
                    break;
                }
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "One or both stations not found in the graph." << std::endl;
    }

    /***************************
     * 准备退出程序
     * 1.将所有内容写入数据文件
     * 2.清除所有数据结构避免内存泄漏
     * (SqList与LinkedList使用了“资源获取即初始化”（RAII）不需要清理)
    ***************************/

    return 0;
}
