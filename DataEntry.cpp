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
        getline(iss, tempUser.account, '\t');
        getline(iss, tempUser.password, '\t');
        getline(iss, tempUser.name, '\t');
        getline(iss, tempUser.sex, '\t');
        getline(iss, tempUser.id, '\t');
        getline(iss, tempUser.tickets, '\t');
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
        getline(iss, tempTrain.train_type, '\t');
        getline(iss, tempTrain.train_set, '\t');
        iss >> tempTrain.seat_type;

        // 将读取的用户添加到列表中
        TrainList.ListInsert(TrainList.GetLength() + 1, tempTrain);
    }

    file.close();
}

void ReadTrainNumber(SqList<TrainNumber>& TrainNumberList) {
    FILE* file= fopen("data\\TrainNumber.csv","r");

    while (file) {
        TrainNumber tempTrainNumber;

        // 读取并分割每行的字段
            fscanf(file,"%s\t%s\t%s\t%d\t%d\t%d\t%s\n",tempTrainNumber.number,tempTrainNumber.begin,tempTrainNumber.end,tempTrainNumber.ticket_number,tempTrainNumber.distance,tempTrainNumber.train_distance,tempTrainNumber.carriage.data);
    

        // 将读取的用户添加到列表中
        TrainNumberList.ListInsert(TrainNumberList.GetLength() + 1, tempTrainNumber);
    }

    fclose(file);
}

void WriteUser(SqList<User>& UserList)
{
    FILE* file = fopen("data\\User.csv","w");
    for(int i=0;i<=UserList.GetLength();i++)
    {
        User tempUser;
        UserList.GetElem(i,tempUser); 
        fprintf(file,"%s\t%s\t%s\t%s\t%s\t%s\t%d\n",tempUser.account,tempUser.password,tempUser.name, tempUser.sex,tempUser.tickets,tempUser.authority);
    }
    fclose(file);
}

