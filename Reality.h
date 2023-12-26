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
   int ticket_number;
   int distance;
   int train_distance;
   std::string carriage;
 }TrainNumber;//Sqlist

#endif // REALITY_H_INCLUDED
