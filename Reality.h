#ifndef REALITY_H_INCLUDED
#define REALITY_H_INCLUDED

#include "Graph.h"

 typedef struct City
 {
   VNode Station;
 };//Graph


 typedef struct Ticket
 {
   string train_number;
   City start;
   City end;
   int price;
   string seat;
 };//Linklist


 typedef struct User
 {
    string account;
    string password;
    string name;
    string sex;
    string id;
    Ticket* tickets;
    int authority;
 };//Sqlist


 typedef struct Train
 {
   string train_type;//�������ͣ�����/������
   string train_set;//����(����/��г)
   string seat_type;
 };//Sqlist


 typedef struct TrainNunmber
 {
   string number;
   City begin;
   City end;
   int ticket_number;
   int distance;
   int train_distance;
   Tree carriage;
 };//Sqlist
#endif // header guard

#endif // REALITY_H_INCLUDED
