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
   string train_type;//车次类型（高铁/动车）
   string train_set;//车组(复兴/和谐)
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