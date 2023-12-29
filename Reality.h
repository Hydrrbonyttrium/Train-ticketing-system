#ifndef REALITY_H_INCLUDED
#define REALITY_H_INCLUDED


#include <string.h>
#include "Tree.h"


 typedef struct Ticket
 {
   std::string train_number; // 车次
   std::string start;        // 起始车站
   std::string end;          // 终点车站
   std::string seat;
   int price;
   int remains;
   std::string departure_time;    // 发车时间
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
   std::string train_type;//车次类型（高铁/动车）
   std::string train_set;//车组(复兴/和谐)
   std::string seat_type;
 }Train;//Sqlist


 typedef struct TrainNumber
 {
   
   std::string number;
   std::string begin;
   std::string end;
   int price;
   int remains;
   int distance;//总路程
   int train_distance;//总车程
   std::string carriage;
 }TrainNumber;//Sqlist


#endif // REALITY_H_INCLUDED
