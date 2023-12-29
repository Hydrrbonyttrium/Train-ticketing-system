#include "DataEntry.h"

void ReadUser(SqList<User>& UserList) {
    std::ifstream file("data\\User.csv");
    if (!file.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        User tempUser;

        // 读取并分割每行的字段
        getline(iss, tempUser.account, ',');
        getline(iss, tempUser.password, ',');
        getline(iss, tempUser.name, ',');
        getline(iss, tempUser.sex, ',');
        getline(iss, tempUser.id, ',');
        getline(iss, tempUser.tickets, ',');
        iss >> tempUser.authority;

        // 将读取的用户添加到列表中
        UserList.ListInsert(UserList.GetLength() + 1, tempUser);
    }

    file.close();
}

void ReadTrain(SqList<Train>& TrainList) {
    std::ifstream file("data\\Train.csv");
    if (!file.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        Train tempTrain;

        // 读取并分割每行的字段
        getline(iss, tempTrain.train_type, ',');
        getline(iss, tempTrain.train_set, ',');
        iss >> tempTrain.seat_type;

        // 将读取的用户添加到列表中
        TrainList.ListInsert(TrainList.GetLength() + 1, tempTrain);
    }

    file.close();
}

void ReadTrainNumber(SqList<TrainNumber>& TrainNumberList) {
    std::ifstream file("data\\TrainNumber.csv");
    if (!file.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        TrainNumber tempTrainNumber;

        // 读取并分割每行的字段
        getline(iss, tempTrainNumber.number, ',');
        getline(iss, tempTrainNumber.begin, ',');
        getline(iss, tempTrainNumber.end, ',');
        getline(iss, tempTrainNumber.price, ',');
        getline(iss, tempTrainNumber.remains, ',');
        getline(iss, tempTrainNumber.distance, ',');
        getline(iss, tempTrainNumber.train_distance, ',');
        iss >> tempTrainNumber.carriage;


        // 将读取的用户添加到列表中
        TrainNumberList.ListInsert(TrainNumberList.GetLength() + 1, tempTrainNumber);
    }

    file.close();
}

void ReadTicket(LinkedList<Ticket>& TicketList) {
    std::ifstream file("data\\Ticket.csv");
    if (!file.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        Ticket tempTicket;

        // 读取并分割每行的字段
        getline(iss, tempTicket.train_number, ',');
        getline(iss, tempTicket.start, ',');
        getline(iss, tempTicket.end, ',');
        getline(iss, tempTicket.seat, ',');

        std::string price, remains;
        getline(iss, price, ',');
        tempTicket.price = std::stoi(price);

        getline(iss, remains, ',');
        tempTicket.remains = std::stoi(remains);

        getline(iss, tempTicket.departure_time, ',');
        getline(iss, tempTicket.arrival_time);

        // 将读取的票务信息添加到列表中
        TicketList.ListInsert(1, tempTicket);
    }

    file.close();
}

void WriteUser(SqList<User>& UserList) {
    FILE* file = fopen("data\\User.csv", "w");
    if (!file) {
        std::cerr << "无法打开文件进行写入" << std::endl;
        return;
    }

    for (int i = 1; i <= UserList.GetLength(); i++) {
        User tempUser;
        if (UserList.GetElem(i, tempUser) == OK) { // 确保能够获取元素
            fprintf(file, "%s,%s,%s,%s,%s,%s,%d\n",
                    tempUser.account.c_str(),
                    tempUser.password.c_str(),
                    tempUser.name.c_str(),
                    tempUser.sex.c_str(),
                    tempUser.id.c_str(),
                    tempUser.tickets.c_str(),
                    tempUser.authority);
        }
    }
    fclose(file);
}

void WriteTrain(SqList<Train>& TrainList) {
    FILE* file = fopen("data\\Train.csv", "w");
    if (!file) {
        std::cerr << "无法打开文件进行写入" << std::endl;
        return;
    }

    for (int i = 1; i <= TrainList.GetLength(); i++) {
        Train tempTrain;
        if (TrainList.GetElem(i, tempTrain) == OK) { // 确保能够获取元素
            fprintf(file, "%s,%s,%s\n",
                    tempTrain.train_type.c_str(),
                    tempTrain.train_set.c_str(),
                    tempTrain.seat_type.c_str());
        }
    }
    fclose(file);
}

void WriteTrainNumber(SqList<TrainNumber>& TrainNumberList) {
    FILE* file = fopen("data\\TrainNumber.csv", "w");
    if (!file) {
        std::cerr << "无法打开文件进行写入" << std::endl;
        return;
    }

    for (int i = 1; i <= TrainNumberList.GetLength(); i++) {
        TrainNumber tempTrainNumber;
        if (TrainNumberList.GetElem(i, tempTrainNumber) == OK) { // 确保能够获取元素
            fprintf(file, "%s,%s,%s,%d,%d,%d,%d,%s\n",
                    tempTrainNumber.number.c_str(),
                    tempTrainNumber.begin.c_str(),
                    tempTrainNumber.end.c_str(),
                    &tempTrainNumber.price,
                    &tempTrainNumber.remains,
                    &tempTrainNumber.distance,
                    &tempTrainNumber.train_distance
                    );
        }
    }
    fclose(file);
}

void WriteTicket(LinkedList<Ticket>& TicketList) {
    FILE* file = fopen("data\\Ticket.csv", "w");
    if (!file) {
        std::cerr << "无法打开文件进行写入" << std::endl;
        return;
    }

    int i = 0;
    while (TicketList.GetElemPtr(i)) {
        Ticket tempTicket = TicketList.GetElem(i);
        fprintf(file, "%s,%s,%s,%s,%d,%d,%s,%s\n",
                tempTicket.train_number.c_str(),
                tempTicket.start.c_str(),
                tempTicket.end.c_str(),
                tempTicket.seat.c_str(),
                tempTicket.price,
                tempTicket.remains,
                tempTicket.departure_time.c_str(),
                tempTicket.arrival_time.c_str());
        i++;
    }

    fclose(file);
}

void ReadCity(Graph& g, WeightMap& weightmap, std::unordered_map<std::string, Vertex>& stationMap) {
    std::ifstream file("data\\City.csv");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string station1, station2;
        int distance;

        std::getline(iss, station1, ',');
        std::getline(iss, station2, ',');
        iss >> distance;

        Vertex u, v;
        if (stationMap.find(station1) == stationMap.end()) {
            u = add_vertex(g);
            stationMap[station1] = u;
        } else {
            u = stationMap[station1];
        }

        if (stationMap.find(station2) == stationMap.end()) {
            v = add_vertex(g);
            stationMap[station2] = v;
        } else {
            v = stationMap[station2];
        }

        Edge e;
        bool inserted;
        tie(e, inserted) = add_edge(u, v, g);
        weightmap[e] = distance;
    }
}

void WriteCity(const Graph& g, const WeightMap& weightmap, const std::unordered_map<std::string, Vertex>& stationMap) {
    std::ofstream file("data\\City.csv");

    for (auto& pair : stationMap) {
        auto edges = out_edges(pair.second, g);
        for (auto edge : make_iterator_range(edges)) {
            Vertex target = boost::target(edge, g);
            for (const auto& targetPair : stationMap) {
                if (targetPair.second == target) {
                    file << pair.first << "," << targetPair.first << "," << weightmap[edge] << std::endl;
                }
            }
        }
    }
}
