#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
#include "LinkList.h"

using namespace std;


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
    loginMenu();
    return 0;
}

// ��¼�˵�
void loginMenu() {
    int choice;
    while (true) {
        std::cout << "\n��·Ʊ�����ϵͳ\n";
        std::cout << "1. ��ͨ�û���¼\n";
        std::cout << "2. ����Ա��¼\n";
        std::cout << "3. �û�ע��\n";
        std::cout << "4. �˳�\n";
        std::cout << "ѡ����� (1-4): ";
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
                exit(0);
            default:
                std::cout << "��Чѡ�������ԡ�\n";
                break;
        }
    }
}

//***********��ͨ�û�����***********//
//��ͨ�û���¼�˵�
 void loginUser() {
    std::string username, password;
    std::cout << "�����û���: ";
    std::cin >> username;
    std::cout << "��������: ";
    std::cin >> password;
    // TODO: ��֤��¼�߼�
    userMenu();
}

// ��ͨ�û����˵�����
void userMenu() {
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
    std::string username, password, confirmPassword, email;
    std::cout << "�����û���: ";
    std::cin >> username;
    std::cout << "��������: ";
    std::cin >> password;
    std::cout << "ȷ������: ";
    std::cin >> confirmPassword;
    std::cout << "��������ʼ�����ѡ��: ";
    std::cin >> email;
    // TODO: ע���߼�
    loginUser();
}

// ��ѯʱ�̱�
void queryTimetable() {
    std::string trainNumberOrStation;
    std::cout << "\n���복�λ�վ��: ";
    std::cin >> trainNumberOrStation;
    // TODO: ��������ĳ��λ�վ����ʾ���ʱ�̱�
}

// ��ѯƱ�ۺ���Ʊ
void queryTicketPrice() {
    std::string trainNumber;
    std::cout << "\n���복��: ";
    std::cin >> trainNumber;
    // TODO: ��������ĳ�����ʾƱ�ۺ���Ʊ��Ϣ
}

// �鿴���˶���
void viewOrders() {
    // ʵ�ֲ鿴���˶����߼�...
}

// ����Ʊ
void purchaseTicket() {
    std::string trainNumber;
    std::string seatType;
    // TODO: ʵ�ֹ���Ʊ���߼�
    // ���복�Ρ�ѡ����λ���͵�
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
    adminMenu();
}

// ����Ա���˵�����
void adminMenu() {
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
                enterModifyCityInfo();
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

//¼��/�޸Ĺ��ܣ�����Ա��
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

//**********************************//
