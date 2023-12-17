 #include<Graph.h>
 #include<public1.h>
 typedef struct City
 {
   VNode Station;
 };

 typedef struct Ticket
 {
   string train_number;
   City start;
   City end;
   int price;
   string seat;
 };
 typedef struct User
 {
    string account;
    string password;
    Ticket* tickets; 
    int authority;
 };
 typedef struct Train
 {
   string train_type;//�������ͣ�����/������
   string train_set;//����(����/��г)
   string seat_type;
 };
 typedef struct TrainNunmber
 {
   string number;
   City begin;
   City end;
   int ticket_number;
   int distance;
   int train_distance;
 };