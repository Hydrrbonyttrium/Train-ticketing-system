#include "DataEntry.h"

void ReadUser(SqList<User>& UserList) {
    std::ifstream file("data\\User.csv");
    if (!file.is_open()) {
        std::cerr << "�޷����ļ�" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        User tempUser;

        // ��ȡ���ָ�ÿ�е��ֶ�
        getline(iss, tempUser.account, '\t');
        getline(iss, tempUser.password, '\t');
        getline(iss, tempUser.name, '\t');
        getline(iss, tempUser.sex, '\t');
        getline(iss, tempUser.id, '\t');
        getline(iss, tempUser.tickets, '\t');
        iss >> tempUser.authority;

        // ����ȡ���û���ӵ��б���
        UserList.ListInsert(UserList.GetLength() + 1, tempUser);
    }

    file.close();
}

void ReadTrain(SqList<Train>& TrainList) {
    std::ifstream file("data\\Train.csv");
    if (!file.is_open()) {
        std::cerr << "�޷����ļ�" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        Train tempTrain;

        // ��ȡ���ָ�ÿ�е��ֶ�
        getline(iss, tempTrain.train_type, '\t');
        getline(iss, tempTrain.train_set, '\t');
        iss >> tempTrain.seat_type;

        // ����ȡ���û���ӵ��б���
        TrainList.ListInsert(TrainList.GetLength() + 1, tempTrain);
    }

    file.close();
}

void ReadTrainNumber(SqList<TrainNumber>& TrainNumberList) {
    FILE* file= fopen("data\\TrainNumber.csv","r");

    while (file) {
        TrainNumber tempTrainNumber;

        // ��ȡ���ָ�ÿ�е��ֶ�
            fscanf(file,"%s\t%s\t%s\t%d\t%d\t%d\t%s\n",tempTrainNumber.number,tempTrainNumber.begin,tempTrainNumber.end,tempTrainNumber.ticket_number,tempTrainNumber.distance,tempTrainNumber.train_distance,tempTrainNumber.carriage.data);
    

        // ����ȡ���û���ӵ��б���
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

