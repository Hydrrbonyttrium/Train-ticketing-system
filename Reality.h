#ifndef REALITY_H_INCLUDED
#define REALITY_H_INCLUDED


#include <string.h>
#include "Tree.h"


 typedef struct Ticket
 {
   std::string train_number; // ����
   std::string start;        // ��ʼ��վ
   std::string end;          // �յ㳵վ
   std::string seat;
   int price;
   int remains;
   std::string departure_time;    // ����ʱ��
   std::string arrival_time;
 }Ticket;//Linklist



 typedef struct User
 {
    std::string account;
    std::string password;
    std::string name;
    std::string sex;
    std::string id;
    std::string tickets;
    int authority;
 }User;//Sqlist



 typedef struct Train
 {
   std::string train_type;//�������ͣ�����/������
   std::string train_set;//����(����/��г)
   std::string seat_type;
 }Train;//Sqlist


 typedef struct TrainNumber
 {
   
   std::string number;
   std::string begin;
   std::string end;
   int price;
   int remains;
   int distance;//��·��
   int train_distance;//�ܳ���
   std::string carriage;
 }TrainNumber;//Sqlist


#endif // REALITY_H_INCLUDED
