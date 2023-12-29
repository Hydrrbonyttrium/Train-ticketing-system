#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
#include "LinkList.h"

using namespace std;

//����ʵ�嶨��
SqList<User> UserList;
SqList<Train> TrainList;
SqList<TrainNumber> TrainNumberList;

Graph CityGraph;
WeightMap weightmap;
std::unordered_map<std::string, Vertex> stationMap;

User currentUser;
LinkedList<Ticket> TicketList;

// ��������
void loginMenu();
void userMenu();
void adminMenu();
void loginUser();
void registerUser();
void loginAdmin();
void queryTimetable();
void queryTicketPrice();
void purchaseTicket();
void viewOrders();
void refundOrChangeTicket();
void manageUserDetails();
void manageTrainDetails();
void enterModifyCityInfo();
void optimalStationQuery();
void queryInterCityPath();
void SetConsoleSize(int cols, int lines);
void viewUserList(SqList<User>& UserList);
void modifyUser(SqList<User>& UserList);
void viewTrainNumberList(SqList<TrainNumber>& TrainNumberList);
void modifyTrainNumberList(SqList<TrainNumber>& TrainNumberList);
std::string getCityName(const Vertex& v);
int getEdgeWeight(const Vertex& v1, const Vertex& v2, WeightMap& weightmap);
// ������
int main()
{
    SetConsoleSize(80, 20);
    // ȫ�����ݶ�ȡ
    UserList.InitList();
    TrainList.InitList();
    TrainNumberList.InitList();
    ReadUser(UserList);
    ReadTicket(TicketList);
    weightmap = get(boost::edge_weight, CityGraph);
    ReadCity(CityGraph, weightmap, stationMap);
    loginMenu();
    // ReadTrain(TrainList);
    // ReadTrainNumber(TrainNumberList);

    // �˳�����
    // ע������Ҫɾ��һ������һ��
    // ע������Ҫɾ��һ������һ��
    int user_delete_index;
    User user_delete_temp;
    user_delete_index = UserList.LocateElem(currentUser, UserCompare);
    UserList.ListDelete(user_delete_index, user_delete_temp);
    UserList.ListInsert(user_delete_index, currentUser);

    WriteUser(UserList);
    WriteTicket(TicketList);
    return 0;
}

// ��¼�˵�
void loginMenu() {
    
    SetConsoleSize(80, 20); // ���ƴ��ڴ�С
    int choice;
    while (true) {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t|=============================================|\n");
        printf("\t\t|===            ��·Ʊ�����ϵͳ           ===|\n");
        printf("\t\t|=============================================|\n");
        printf("\t\t|\t1.��ͨ�û���¼                        |\n");
        printf("\t\t|\t2.����Ա��¼                          |\n");
        printf("\t\t|\t3.�û�ע��                            |\n");
        printf("\t\t|\t4.�˳�����                            |\n");
        printf("\t\t|=============================================|\n");
        printf("\t\t������Ҫ���еĲ���(1 - 4)");
        std::cin >> choice;

        switch (choice) {
            case 1:
                loginUser();
                break;
            case 2:
                loginAdmin();
                break;
            case 3:
                registerUser();
                break;
            case 4:
                std::cout << "�˳�ϵͳ.\n";
                return; // ���� ��ʼ�˳�����
            default:
                std::cout << "��Чѡ�������ԡ�\n";
                break;
        }
    }
}

//***********��ͨ�û�����***********//

// ��ͨ�û���¼�˵�
void loginUser() {
    SetConsoleSize(80, 20);
    system("cls");
    std::string username, password;

    std::cout << "\n\n";
    std::cout << "\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
    std::cout << "\t\t�U      ��ӭʹ����·Ʊ�����ϵͳ        �U\n";
    std::cout << "\t\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n";
    std::cout << "\t\t�U            �û���¼�˵�              �U\n";
    std::cout << "\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";

    std::cout << "�����û���: ";
    std::cin >> username;
    std::cout << "��������: ";
    std::cin >> password;

    // ��֤��¼�߼�
    if (Login(UserList, username, password, currentUser)) {
        userMenu();
    } else {
        std::cout << "�û������������\n";
    }
}


// �û����˵�����
void userMenu() {
    SetConsoleSize(80, 20);
    system("cls");
    int choice;
    while (true) {
        std::cout << "\n\n";
        std::cout << "\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
        std::cout << "\t\t�U      ��ӭʹ����·Ʊ�����ϵͳ        �U\n";
        std::cout << "\t\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n";
        std::cout << "\t\t�U               �û��˵�               �U\n";
        std::cout << "\t\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n";
        std::cout << "\t\t�U 1. ��ѯʱ�̱�                        �U\n";
        std::cout << "\t\t�U 2. ��ѯƱ�ۺ���Ʊ                    �U\n";
        std::cout << "\t\t�U 3. ��ѯ�Ǽ�·��                      �U\n";
        std::cout << "\t\t�U 4. ����Ʊ                          �U\n";
        std::cout << "\t\t�U 5. ��ѯ���˶���                      �U\n";
        std::cout << "\t\t�U 6. ��Ʊ/��ǩ                         �U\n";
        std::cout << "\t\t�U 7. �˳�ϵͳ                          �U\n";
        std::cout << "\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";
        std::cout << "ѡ����� (1-7): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                queryTimetable();
                break;
            case 2:
                queryTicketPrice();
                break;
            case 3:
                queryInterCityPath();
                break;
            case 4:
                purchaseTicket();
                break;
            case 5:
                viewOrders();
                break;
            case 6:
                refundOrChangeTicket();
                break;
            case 7:
                std::cout << "�˳��û��˵�.\n";
                return; // ���ص���¼����
            default:
                std::cout << "��Чѡ�������ԡ�\n";
                break;
        }
    }
}


// ��ͨ�û�ע��˵�
void registerUser() {
    SetConsoleSize(80, 20);
    system("cls");
    int outcome;
    std::string username, password, name, confirmPassword, sex, id;

    do {
        system("cls");
        std::cout << "\n\n";
        std::cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
        std::cout << "�U      ��ӭʹ����·Ʊ�����ϵͳ        �U\n";
        std::cout << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n";
        std::cout << "�U            �û�ע��˵�             �U\n";
        std::cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";

        std::cout << "�����û���: ";
        std::cin >> username;
        std::cout << "��������: ";
        std::cin >> password;
        std::cout << "ȷ������: ";
        std::cin >> confirmPassword;
        std::cout << "��������: ";
        std::cin >> name;
        std::cout << "�������Ա�: ";
        std::cin >> sex;
        std::cout << "�������֤: ";
        std::cin >> id;

        outcome = (password == confirmPassword) ? 0 : 1;

        if (outcome) {
            std::cout << "�������벻ͬ�����������롣\n";
            system("pause");
        }
    } while (outcome);

    User tempUser;
    tempUser = {username, password, name, sex, id, "0", 0};
    if(Register(UserList, tempUser))
        std::cout << "ע��ɹ���\n";
    system("pause");
    loginUser();
}


// ��ѯʱ�̱�
void queryTimetable() {
    SetConsoleSize(100, 60);
    system("cls");
    std::string start_stop;
    std::string end_stop;

    std::cout << "�������վ��: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ����֮ǰ������
    std::getline(std::cin, start_stop); // ʹ�� getline ��ȡ�����ո���ַ���

    std::cout << "���뵽��վ��: ";
    std::getline(std::cin, end_stop); // ͬ��ʹ�� getline

    if (Timetable(TicketList, start_stop, end_stop)) {
        std::cout << "��ѯ����" << std::endl;
    } else {
        std::cout << "��ѯʧ��: δ�ҵ�ƥ��ĳ���" << std::endl;
    }
    while (TRUE) {
        char result;
        std::cout << "��q������ѯ��";
        std::cin >> result;
        if (result == 'q'){
            SetConsoleSize(80, 20);
            system("cls");
            break;
        }
    }
}

// ��ѯƱ�ۺ���Ʊ
void queryTicketPrice() {
    SetConsoleSize(80, 20);
    system("cls");
    std::string trainNumber;
    std::cout << "���복�κ�: ";
    std::cin >> trainNumber;

    Ticket foundTicket = FindTicketByTrainNumber(TicketList, trainNumber);
    if (!foundTicket.train_number.empty()) { // ����Ƿ��ҵ���Ʊ
        std::cout << "����: " << foundTicket.train_number
                  << ", Ʊ��: " << foundTicket.price
                  << ", ʣ��Ʊ��: " << foundTicket.remains << std::endl;
    } else {
        std::cout << "δ�ҵ�����Ϊ " << trainNumber << " ��Ʊ��Ϣ" << std::endl;
    }
}

// �鿴���˶���
void viewOrders() {
    SetConsoleSize(80, 20);
    system("cls");
    User tempUser = currentUser;
    string tempCurrentUserTicket = tempUser.tickets;
    cout << "���û�ӵ��Ʊ��" << endl;
    // �����û�ӵ�е�Ʊ����������'/'�ַ�ʱ���д�ӡ
    for (char ch : tempUser.tickets) {
        if (ch == '/') {
            std::cout << std::endl;
        } else {
            std::cout << ch;
        }
    }
    std::cout << std::endl;
}

// ����Ʊ
void purchaseTicket() {
    SetConsoleSize(80, 20);
    system("cls");
    std::string trainNumber;
    std::string seatType;

    cout << "�����복�Σ�";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ����֮ǰ������
    std::getline(std::cin, trainNumber); // ʹ�� getline ��ȡ�����ո���ַ���
    cout << "��������λ���ͣ�First Class/Second Class����";
    std::getline(std::cin, seatType); // ͬ��ʹ�� getline
    Ticket tempfoundTicket = FindTicketByTrainNumberAndSeat(TicketList, trainNumber, seatType);
    if (!tempfoundTicket.train_number.empty()) { // ����Ƿ��ҵ���Ʊ
        std::cout << "�ҵ���Ʊ ���ڹ���" << std::endl;
        PurchaseTicket(currentUser, tempfoundTicket);
    } else {
        std::cout << "δ�ҵ�����Ϊ " << trainNumber << " ��Ʊ��Ϣ" << std::endl;
    }
}

void queryInterCityPath() {
    SetConsoleSize(100, 60);
    system("cls");
    std::cout << "\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
    std::cout << "\t\t�U      ��ӭʹ����·Ʊ�����ϵͳ        �U\n";
    std::cout << "\t\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n";
    std::cout << "\t\t�U            �Ǽʲ�ѯ�˵�              �U\n";
    std::cout << "\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";

    std::cout << "�������������: ";
    std::string sourceCity;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, sourceCity);

    std::cout << "������Ŀ�ĳ���: ";
    std::string destinationCity;
    std::getline(std::cin, destinationCity);

    if (stationMap.find(sourceCity) != stationMap.end() && stationMap.find(destinationCity) != stationMap.end()) {
        Vertex startVertex = stationMap[sourceCity];
        Vertex endVertex = stationMap[destinationCity];
        std::vector<Vertex> path = dijkstraShortestPath(CityGraph, startVertex, endVertex);

        // ��ȡȨ��ӳ��
        WeightMap weightmap = get(boost::edge_weight, CityGraph);

        // �����ͷ
        std::cout << std::left << std::setw(40) << "��ʼ����" << "|" << std::setw(40) << "Ŀ�ĳ���" << "|" << std::setw(10) << "����" << std::endl;
        std::cout << std::string(52, '-') << std::endl; // ��ӡ�ָ���

        for (size_t i = 0; i < path.size() - 1; ++i) {
            std::string fromCity = getCityName(path[i]);
            std::string toCity = getCityName(path[i + 1]);

            // �������к������Ի�ȡ��������֮��ı�Ȩ��
            int distance = getEdgeWeight(path[i], path[i + 1], weightmap);

            std::cout << std::left << std::setw(40) << fromCity << "|" << std::setw(40) << toCity << "|" << std::setw(10) << distance << std::endl;
        }
    }

    while (TRUE) {
        char result;
        std::cout << "��q������ѯ��";
        std::cin >> result;
        if (result == 'q') {
            SetConsoleSize(80, 20);
            system("cls");
            break;
        }
    }
}

// Ԥ�۳�Ʊ
void purchaseAdvanceTicket() {
    // ʵ��Ԥ�۳�Ʊ�����߼�...
    // �Ƚ���ʱ�̱��ѯ
    queryTimetable();

}

// ��Ʊ/��ǩ
void refundOrChangeTicket() {
    // TODO: ʵ����Ʊ���ǩ���߼�
    // ��ʾ�û�������ѡ�������Ʊ���ǩ�Ķ���
}

//**********************************//





//***********����Ա�û�����**********//
//����Ա�û���¼�˵�
void loginAdmin() {
    system("cls");
    std::string adminUsername, adminPassword;
    std::cout << "�������Ա�û���: ";
    std::cin >> adminUsername;
    std::cout << "��������: ";
    std::cin >> adminPassword;
    // TODO: ��֤����Ա��¼�߼�
    if(Login(UserList,adminUsername,adminPassword,currentUser)&&currentUser.authority)
        adminMenu();
    else
        std::cout << "�ǹ���Ա�û����û������������" << endl;
}

// ����Ա���˵�����
void adminMenu() {
    system("cls");
    int choice;
    while (true) {
        std::cout << "\n����Ա�˵�:\n";
        std::cout << "1. �û����Ϲ���\n";
        std::cout << "2. ������Ϣ����\n";
        std::cout << "3. ¼��/�޸ĳ�����Ϣ\n";
        std::cout << "4. ¼��/�޸ĳ��������Ϣ\n";
        std::cout << "5. վ�����Ų�ѯ����\n";
        std::cout << "6. �˳�ϵͳ\n";
        std::cout << "ѡ����� (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manageUserDetails();
                break;
            case 2:
                manageTrainDetails();
                break;
            case 3:
                optimalStationQuery();
                break;
            case 4:
                // TODO: ʵ��¼��/�޸ĳ��������Ϣ�ĺ���
                break;
            case 5:
                optimalStationQuery();
                break;
            case 6:
                std::cout << "�˳�����Ա�˵�.\n";
                return; // ���ص���¼����
            default:
                std::cout << "��Чѡ�������ԡ�\n";
                break;
        }
    }
}

//�û����Ϲ���
void manageUserDetails() {
    system("cls");
    int choice;
    while (true) {
        std::cout << "\n�����û�����:\n";
        std::cout << "1. �鿴�û��б�\n";
        std::cout << "2. ѡ���û����б༭\n";
        std::cout << "3. ������һ��\n";
        std::cout << "ѡ����� (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // TODO: ʵ�ֲ鿴�û��б���߼�
                viewUserList(UserList);
                break;
            case 2:
                // TODO: ʵ��ѡ�񲢱༭�û����߼�
                modifyUser(UserList);
                break;
            case 3:
                return; // ���ع���Ա�˵�
            default:
                std::cout << "��Чѡ�������ԡ�\n";
                break;
        }
    }
}

//�鿴�û���Ϣ
void viewUserList(SqList<User>& UserList){
    system("cls");
    int i = 0;
    std::cout << std::left
            << std::setw(14) << "�û���" << " | "
            << std::setw(14) << "����" << " | "
            << std::setw(4) << "����" << " | "
            << std::setw(2) << "�Ա�" << " | "
            << std::setw(18) << "���֤��" << " | "
            << std::setw(20) << "�����Ʊ" << " | "
            << std::setw(14) << "Ȩ��" << endl;
    for(int i = 0;i <= UserList.GetLength();i++)
    {
        User currentUser;
        UserList.GetElem(i,currentUser);
        std::cout << std::left
                << std::setw(14) << currentUser.account <<" | "
                << std::setw(14) << currentUser.password <<" | "
                << std::setw(4) << currentUser.name << " | "
                << std::setw(2) << currentUser.sex << " | "
                << std::setw(18) << currentUser.id << " | "
                << std::setw(20) << currentUser.tickets << " | "
                << std::setw(14) << currentUser.authority <<endl;
    }
    system("pause");
}

void modifyUser(SqList<User>& UserLsit){
    string account;
    system("cls");
    std::cout << "�����������ҵ��û���:";
    std::cin >> account;
    std::cout << "�����޸ĺ���û�����"<<endl;
    for(int i = 0 ;i <= UserList.GetLength(); i++ ){
        User currentUser;
        UserList.GetElem(i,currentUser);
        if(currentUser.account == account)
        {
            UserList.ListDelete(i,currentUser);
            std::cout << "�û���:";
            std::cin >> currentUser.account;
            std::cout << "����:";
            std::cin >> currentUser.password;
            std::cout << "����:";
            std::cin >> currentUser.name;
            std::cout <<"�Ա�:";
            std::cin >>currentUser.sex;
            std::cout <<"���֤:";
            std::cin >> currentUser.id;
            std::cout <<"����:";
            std::cin >> currentUser.tickets;
            std::cout <<"Ȩ��:";
            std::cin >> currentUser.authority;
            UserList.ListInsert(i,currentUser);
        }
    }
    system("pause");
}

//��������Ϣ
void manageTrainDetails() {
    int choice;
    system("cls");
    while (true) {
        std::cout << "\n��������Ϣ:\n";
        std::cout << "1. �鿴�����б�\n";
        std::cout << "2. ѡ�񳵴ν��б༭\n";
        std::cout << "3. ������һ��\n";
        std::cout << "ѡ����� (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // TODO: ʵ�ֲ鿴�����б���߼�
                viewTrainNumberList(TrainNumberList);
                break;
            case 2:
                // TODO: ʵ��ѡ�񲢱༭���ε��߼�
                modifyTrainNumberList(TrainNumberList);
                break;
            case 3:
                return; // ���ع���Ա�˵�
            default:
                std::cout << "��Чѡ�������ԡ�\n";
                break;
        }
    }
}

void viewTrainNumberList(SqList<TrainNumber>& TrainNumberList){
    system("cls");
    int i = 0;
    std::cout << std::left
            << std::setw(14) << "����" << " | "
            << std::setw(14) << "ʼ��վ" << " | "
            << std::setw(4) << "�յ�վ" << " | "
            << std::setw(2) << "Ʊ��" << " | "
            << std::setw(18) << "��Ʊ" << " | "
            << std::setw(20) << "��·��" << " | "
            << std::setw(14) << "�ܳ���" << endl;
    for(int i = 0;i <= UserList.GetLength();i++)
    {
        TrainNumber currentTrainNumber;
        TrainNumberList.GetElem(i,currentTrainNumber);
        std::cout << std::left
                << std::setw(14) << currentTrainNumber.number <<" | "
                << std::setw(14) << currentTrainNumber.begin <<" | "
                << std::setw(4) << currentTrainNumber.end << " | "
                << std::setw(2) << currentTrainNumber.price << " | "
                << std::setw(18) << currentTrainNumber.remains << " | "
                << std::setw(20) << currentTrainNumber.distance << " | "
                << std::setw(14) << currentTrainNumber.train_distance <<endl;
    }
    system("pause");
}

void modifyTrainNumberList(SqList<TrainNumber>&TrainNumberList){
    string number;
    system("cls");
    std::cout << "�����������ҵĳ���:";
    std::cin >> number;
    std::cout << "�����޸ĺ�ĳ�����Ϣ"<<endl;
    for(int i = 0 ;i <= TrainNumberList.GetLength(); i++ ){
        TrainNumber currentTrainNumber;
        TrainNumberList.GetElem(i,currentTrainNumber);
        if(currentTrainNumber.number == number)
        {
            TrainNumberList.ListDelete(i,currentTrainNumber);
            std::cout << "����:";
            std::cin >> currentTrainNumber.number;
            std::cout << "ʼ��վ:";
            std::cin >> currentTrainNumber.begin;
            std::cout << "�յ�վ:";
            std::cin >> currentTrainNumber.end;
            std::cout <<"Ʊ��:";
            std::cin >>currentTrainNumber.price;
            std::cout <<"��Ʊ:";
            std::cin >> currentTrainNumber.remains;
            std::cout <<"��·��:";
            std::cin >> currentTrainNumber.distance;
            std::cout <<"�ܳ���:";
            std::cin >> currentTrainNumber.train_distance;
            TrainNumberList.ListInsert(i,currentTrainNumber);
        }
    }
    system("pause");
}
//�޸ĳ�����Ϣ
void enterModifyCityInfo(){
    
}

//����վ���ѯ
void optimalStationQuery(){

}
//**********************************//

std::string getCityName(const Vertex& v) {
    for (const auto& pair : stationMap) {
        if (pair.second == v) {
            return pair.first; // �ҵ��� Vertex ��Ӧ�ĳ�������
        }
    }
    return ""; // ���û���ҵ���Ӧ�ĳ��У����ؿ��ַ���
}

int getEdgeWeight(const Vertex& v1, const Vertex& v2, WeightMap& weightmap) {
    boost::graph_traits<Graph>::edge_descriptor e;
    bool exists;
    boost::tie(e, exists) = edge(v1, v2, CityGraph);

    if (exists) {
        return weightmap[e]; // ���رߵ�Ȩ��
    } else {
        return -1; // ��ʾ�߲�����
    }
}

// ���ÿ���̨���ڴ�С�ĺ���
void SetConsoleSize(int cols, int lines) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // ���ÿ���̨���ڻ�������С
    COORD coord;
    coord.X = cols;
    coord.Y = lines;
    SetConsoleScreenBufferSize(hOut, coord);

    // ���ÿ���̨���ڴ�С
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = cols - 1;
    rect.Bottom = lines - 1;
    SetConsoleWindowInfo(hOut, TRUE, &rect);
}
