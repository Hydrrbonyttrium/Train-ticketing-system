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
    // ��ʼ���û���
    SqList<User> user_list;
    user_list.InitList();
    ReadUser(user_list);

    User current_user;
    /*****************************
     * ����ʵ�ֵ�¼
     * ����½��ɵ�User��ֵ��current_user
     * ������ʹ��
    *****************************/
    // ����ʹ��һ��ʾ��
    // ע�����û�
//    User newUser = {"zhangsan", "password123", "New User"};
//    if (Register(user_list, newUser)) {
//        std::cout << "ע��ɹ���" << std::endl;
//    }

    // �û���¼
    std::string account, password;
    std::cout << "�������˺�: ";
    std::cin >> account;
    std::cout << "����������: ";
    std::cin >> password;

    if (Login(user_list, account, password, current_user)) {
        std::cout << "��¼�ɹ�����ӭ " << current_user.name << std::endl;
    } else {
        std::cout << "��¼ʧ�ܣ�" << std::endl;
    }

    //��ʼ��Ʊ������
    LinkedList<Ticket> ticket_list;
    ReadTicket(ticket_list);

    Ticket ticket_to_purchase;
    /*****************************
     * ����ʵ��Ʊ������
     * ��������ѡ�е�Ʊ��ֵ��ticket_to_purchase
    *****************************/
    // ����ʹ��һ��ʾ��
//    ticket_to_purchase = ticket_list.GetElem(1);

    // ����һ�¹�Ʊ
//    if (PurchaseTicket(current_user, ticket_to_purchase)) {
//        cout << "��Ʊ�ɹ�" << endl;
//    } else {
//        cout << "�Ѽ���Ⱥ��б���" << endl;
//    }

    // ������ɽ����д��
    // ע������Ҫɾ��һ������һ��
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

    // ��ȡͼ����
    ReadCity(g, weightmap, stationMap);

    // ��ʾ��ȡ�����ݣ���Ϊ����
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

    // ������Զ�ͼ����һЩ�޸ģ�������ӻ�ɾ����
    // ʾ�������һ���µı�
//    std::string newStation1 = "NewStation1";
//    std::string newStation2 = "NewStation2";
//    Vertex newU = add_vertex(g);
//    Vertex newV = add_vertex(g);
//    stationMap[newStation1] = newU;
//    stationMap[newStation2] = newV;
//    Edge newE;
//    bool inserted;
//    tie(newE, inserted) = add_edge(newU, newV, g);
//    weightmap[newE] = 100; // �������Ϊ100
//
//    // ���޸ĺ��ͼ����д���ļ�
//    WriteCity(g, weightmap, stationMap);

//    std::cout << "Graph modification and writing complete." << std::endl;

    // ����Dijkstra�㷨
    // ѡ�������յ�
    std::string startStation = "Kunshannan Railway Station";
    std::string endStation = "Nanjingnan Railway Station"; // ʾ���յ�

    // ȷ�������յ㶼��stationMap��
    if (stationMap.find(startStation) != stationMap.end() && stationMap.find(endStation) != stationMap.end()) {
        // ��ȡ�����յ�Ķ���
        Vertex startVertex = stationMap[startStation];
        Vertex endVertex = stationMap[endStation];

        // �������·��
        std::vector<Vertex> path = dijkstraShortestPath(g, startVertex, endVertex);

        // ������·��
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
     * ׼���˳�����
     * 1.����������д�������ļ�
     * 2.����������ݽṹ�����ڴ�й©
     * (SqList��LinkedListʹ���ˡ���Դ��ȡ����ʼ������RAII������Ҫ����)
    ***************************/

    return 0;
}
