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

// ������
int main()
{
    UserList.InitList();
    TrainList.InitList();
    TrainNumberList.InitList();
    ReadUser(UserList);
    ReadTicket(TicketList);
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
    system("cls");
    int choice;
    while (true) {
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

//��ͨ�û���¼�˵�
 void loginUser() {
    system("cls");
    std::string username, password;
    std::cout << "�����û���: ";
    std::cin >> username;
    std::cout << "��������: ";
    std::cin >> password;
    // ��֤��¼�߼�
    if(Login(UserList,username,password,currentUser))
        userMenu();
    else
        std::cout << "�û������������" << endl;
}

// ��ͨ�û����˵�����
void userMenu() {
    system("cls");
    int choice;
    while (true) {
        std::cout << "\n�û��˵�:\n";
        std::cout << "1. ��ѯʱ�̱�\n";
        std::cout << "2. ��ѯƱ�ۺ���Ʊ\n";
        std::cout << "3. ����Ʊ\n";
        std::cout << "4. ��ѯ���˶���\n";
        std::cout << "5. ��Ʊ/��ǩ\n";
        std::cout << "6. �˳�ϵͳ\n";
        std::cout << "ѡ����� (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                queryTimetable();
                break;
            case 2:
                queryTicketPrice();
                break;
            case 3:
                purchaseTicket();
                break;
            case 4:
                viewOrders();
                break;
            case 5:
                refundOrChangeTicket();
                break;
            case 6:
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
    int outcome;
    std::string username, password, name, confirmPassword ,sex, id;
    do{
        system("cls");
        std::cout << "�����û���: ";
        std::cin >> username;
        std::cout << "��������: ";
        std::cin >> password;
        std::cout << "ȷ������: ";
        std::cin >> confirmPassword;
        std::cout <<"��������:";
        std::cin >> name;
        std::cout << "�������Ա�:";
        std::cin >> sex;
        std::cout << "�������֤:";
        std::cin >> id;
        outcome= password==confirmPassword?0:1;
        if(outcome)
        {
            std::cout << "�������벻ͬ,����������" <<endl;
            system("pause");
        }
    }while(outcome);
    // TODO: ע���߼�
    User tempUser;
    tempUser={username,password,name,sex,id,"0",0};
    Register(UserList,tempUser);
    std::cout << "ע��ɹ�" << endl;
    system("pause");
    loginUser();
}

// ��ѯʱ�̱�
void queryTimetable() {
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
}

// ��ѯƱ�ۺ���Ʊ
void queryTicketPrice() {
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

// Ԥ�۳�Ʊ
void purchaseAdvanceTicket() {
    // ʵ��Ԥ�۳�Ʊ�����߼�...
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
                break;
            case 2:
                // TODO: ʵ��ѡ�񲢱༭�û����߼�
                break;
            case 3:
                return; // ���ع���Ա�˵�
            default:
                std::cout << "��Чѡ�������ԡ�\n";
                break;
        }
    }
}

//��������Ϣ
void manageTrainDetails() {
    int choice;
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
                break;
            case 2:
                // TODO: ʵ��ѡ�񲢱༭���ε��߼�
                break;
            case 3:
                return; // ���ع���Ա�˵�
            default:
                std::cout << "��Чѡ�������ԡ�\n";
                break;
        }
    }
}

//�޸ĳ�����Ϣ
void enterModifyCityInfo(){

}

//����վ���ѯ
void optimalStationQuery(){

}
//**********************************//
