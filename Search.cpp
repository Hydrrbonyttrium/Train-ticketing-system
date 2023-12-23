#include "search.h"
void searchtime_trainnumber(Train* s);
void searchtime_departure(Train* s);
void searchtime_departure_to_destination(Train* s, const char* startStations[], const char* endStations[], int numStations);
void search_train_by_number_and_time(Train* s);
void quickSort(Train* arr[], int left, int right);
void search_train_by_to_and_time(Train* s, char* departureStations[], char* arrivalStations[], char* departureTimes[]);
void all_show(Train* s, const char* trainNumber, const char* startStation, const char* endStation, const char* departureTime, const char* arrivalTime, float ticketPrice, int ticketCount);
void search_train_by_ticket_price(Train* s, float* ticketPrices, int numTrains);
void search_train_by_station_and_time(Train* s, float* ticketPrices, char (*arrivalTimes)[20], int numTrains);
void searchUnpaidOrders(Train* s, int userID);
void searchPaidOrders(Train* s, int userID);
void searchUserTickets(Train* s, int userID);
void Dijkstra(MGraph *G, int v0, int lengthOrTime);
void searchShortestPath(MGraph *G, char start[], char end[], int lengthOrTime);
void drawLine(int length, char border);
void displayMainMenu();



void searchtime_trainnumber(Train* s) {
    int num; // 定义列车号
    Train* p;
    p = s; // 定义列车链表头结点
    printf("请输入您需要查找的列车信息的列车号：");
    scanf("%d", &num);
    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价(元)\t票数（张）\n");
    int found = 0; // 用于跟踪是否找到列车的变量

    while (p) {
        if (p->data.trainNumber == num) {
            Info(p);
            found = 1;
            break;
        }
        p = p->next;
    }

    if (!found) {
        printf("\t\t未找到该列车号的信息！\n");
    }
}






void searchtime_departure(Train* s, const char* startStations[], int numStartStations) {
    Train* p;
    char pstart[STR_LEN]; // 定义始发站
    p = s->next;
    int flag = 0;

    printf("请输入您需要查找的列车信息的始发站：");
    scanf("%s", pstart);
    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价(元)\t票数（张）\n");

    while (p) {
        // 遍历始发站数组，查找是否有匹配的站点
        for (int i = 0; i < numStartStations; i++) {
            if (strcmp(p->data.from, startStations[i]) == 0) {
                Info(p);
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            // 如果找到匹配的站点，跳出循环
            break;
        }

        p = p->next;
    }

    if (p == NULL || flag == 0)
    {
        printf("\t\t\t.......未找到该列车信息!\n");
    }



void searchtime_departure_to_destination(Train* s, const char* startStations[], const char* endStations[], int numStations)
{
    Train* p;
    char pstart[STR_LEN]; // 定义始发站
    char pend[STR_LEN];   // 定义终点站
    p = s->next;
    int flag = 0;

    printf("请输入您需要查找的列车信息的始发站：");
    scanf("%s", pstart);
    printf("请输入您需要查找的列车信息的终点站：");
    scanf("%s", pend);
    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价(元)\t票数（张）\n");

    while (p) {
        // 遍历站点数组，查找是否有匹配的站点对
        for (int i = 0; i < numStations; i++) {
            if (strcmp(p->data.from, startStations[i]) == 0 && strcmp(p->data.to, endStations[i]) == 0) {
                Info(p);
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            // 如果找到匹配的站点对，跳出循环
            break;
        }

        p = p->next;
    }

    if (flag == 0) {
        printf("\t\t\t.......未找到符合条件的列车信息!\n");
    }
}





void search_train_by_number_and_time(Train* s) {
    Train *p;
    char trainNumber[20]; // 定义列车号
    char departureTime[20];   // 定义出发时间
    p = s->next;
    int flag = 0;

    printf("请输入您需要查询的列车信息的列车号: ");
    scanf("%s", trainNumber);
    printf("请输入您需要查询的列车信息的出发时间: ");
    scanf("%s", departureTime);
    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t出发站\t到达站\t出发时间\t到达时间\t票价（CNY）\t票数\n");

    while (p) {
        // 遍历判断是否有匹配的列车号和出发时间
        if (strcmp(p->train_number, trainNumber) == 0 && strcmp(p->departure_time, departureTime) == 0) {
            printf("%s\t%s\t%s\t%s\t%s\t%.2f\t%d\n", p->train_number, p->departure_station, p->arrival_station, p->departure_time, p->arrival_time, p->ticket_price, p->ticket_count);
            // 在此添加代码以显示停靠站点、停留时间等详细信息
            flag = 1;
            break; // 找到匹配项后跳出循环
        }

        p = p->next;
    }

    if (flag == 0) {
        printf("\t\t\t.......未找到符合条件的列车信息!\n");
    }
}





void quickSort(Train* arr[], int left, int right) {
    if (left < right) {
        int i = left, j = right;
        Train* pivot = arr[left];
        while (i < j) {
            while (strcmp(arr[j]->departure_time, pivot->departure_time) >= 0 && i < j) {
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j];
            }
            while (strcmp(arr[i]->departure_time, pivot->departure_time) <= 0 && i < j) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = pivot;
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}




void search_train_by_to_and_time(Train* s, char* departureStations[], char* arrivalStations[], char* departureTimes[]) {
    Train *p;
    p = s->next;
    int flag = 0;

    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t出发站\t到达站\t出发时间\t到达时间\t票价（CNY）\t票数\n");

    // 创建一个临时数组来存储匹配的列车信息
    Train* matchingTrains[100];
    int matchingCount = 0;

    while (p) {
        int isMatching = 0; // 判断是否有匹配的信息

        // 判断是否有匹配的出发地
        if (departureStations[0] != NULL && strcmp(p->departure_station, departureStations[0]) == 0) {
            isMatching = 1;
        }

        // 判断是否有匹配的到达地
        if (arrivalStations[0] != NULL && strcmp(p->arrival_station, arrivalStations[0]) == 0) {
            isMatching = 1;
        }

        // 判断是否有匹配的出发时间
        if (departureTimes[0] != NULL && strcmp(p->departure_time, departureTimes[0]) == 0) {
            isMatching = 1;
        }

        // 如果有匹配的信息，加入数组
        if (isMatching) {
            matchingTrains[matchingCount] = p;
            matchingCount++;
        }

        p = p->next;
    }

    // 对匹配的列车信息按时间排序
    quickSort(matchingTrains, 0, matchingCount - 1);

    // 输出排序后的列车信息
    for (int i = 0; i < matchingCount; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%.2f\t%d\n", matchingTrains[i]->train_number, matchingTrains[i]->departure_station, matchingTrains[i]->arrival_station, matchingTrains[i]->departure_time, matchingTrains[i]->arrival_time, matchingTrains[i]->ticket_price, matchingTrains[i]->ticket_count);
        // Add code here to display the schedule of stops, dwell time, etc.
        flag = 1;
    }

    if (flag == 0) {
        printf("\t\t\t.......未找到符合条件的列车信息!\n");
    }
}




void all_show(Train* s, const char* trainNumber, const char* startStation, const char* endStation, const char* departureTime, const char* arrivalTime, float ticketPrice, int ticketCount) {
    Train* p;
    p = s->next;
    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价(元)\t票数（张）\n");
    if (p == NULL) {
        printf("\t\t\t.......未查询到任何列车信息！");
    }
    while (p != NULL) {
        // 使用传递进来的参数进行处理
        printf("%s\t%s\t%s\t%s\t%s\t%.2f\t%d\n", trainNumber, startStation, endStation, departureTime, arrivalTime, ticketPrice, ticketCount);
        p = p->next;
    }
}



void search_train_by_ticket_price(Train* s, float* ticketPrices, int numTrains)
{
    Train* p;
    p = s->next;
    int flag = 0;
    printf("请输入您需要查询的列车信息的票价: ");

    float ticketPrice;
    scanf("%f", &ticketPrice);

    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t出发站\t到达站\t出发时间\t到达时间\t票价（CNY）\t票数\n");

    // 遍历链表，查找符合条件的列车信息
    for (int i = 0; i < numTrains; i++) {
        if (ticketPrices[i] == ticketPrice && p->ticket_count > 0) {
            printf("%s\t%s\t%s\t%s\t%s\t%.2f\t%d\n", p->train_number, p->departure_station, p->arrival_station, p->departure_time, p->arrival_time, ticketPrices[i], p->ticket_count);
            // Add code here to display the schedule of stops, dwell time, etc.
            flag = 1;
        }
        p = p->next;
    }

    if (flag == 0) {
        printf("\t\t\t.......未找到符合条件的列车信息!\n");
    }
}


void search_train_by_station_and_time(Train* s, float* ticketPrices, char (*arrivalTimes)[20], int numTrains) {
    Train* p;
    p = s->next;
    int flag = 0;
    char stationName[50]; // 定义车站名称
    char time[20];   // 定义时间

    printf("请输入您需要查询的列车信息的车站名称: ");
    scanf("%s", stationName);
    printf("请输入您需要查询的列车信息的时间: ");
    scanf("%s", time);

    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t出发站\t到达站\t出发时间\t到达时间\t票价（CNY）\t票数\n");

    // 创建一个临时数组来存储匹配的列车信息
    Train* matchingTrains[100];
    int matchingCount = 0;

    while (p) {
        // 判断车站名称和时间是否匹配
        if (strcmp(p->departure_station, stationName) == 0 && strcmp(p->departure_time, time) <= 0) {
            matchingTrains[matchingCount] = p;
            matchingCount++;
        }
        p = p->next;
    }

    // 使用选择排序对匹配的列车信息按到站时间排序
    for (int i = 0; i < matchingCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < matchingCount; j++) {
            if (strcmp(matchingTrains[j]->arrival_time, matchingTrains[minIndex]->arrival_time) < 0) {
                minIndex = j;
            }
        }
        // 交换位置
        Train* temp = matchingTrains[i];
        matchingTrains[i] = matchingTrains[minIndex];
        matchingTrains[minIndex] = temp;
    }

    // 输出排序后的列车信息
    for (int i = 0; i < matchingCount; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%.2f\t%d\n", matchingTrains[i]->train_number, matchingTrains[i]->departure_station, matchingTrains[i]->arrival_station, matchingTrains[i]->departure_time, matchingTrains[i]->arrival_time, ticketPrices[i], matchingTrains[i]->ticket_count);
        // Add code here to display the schedule of stops, dwell time, etc.
        flag = 1;
    }

    if (flag == 0) {
        printf("\t\t\t.......未找到符合条件的列车信息!\n");
    }
}
// 按待支付订单查询
void searchUnpaidOrders(Train* s, int userID) {
    Train *p;
    p = s->next;
    int flag = 0;
    printf("\n\t\t\t\t******-----待支付订单查询结果-----******\n");
    printf("\t订单编号\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价(元)\t票数（张）\n");
    while (p) {
        if (p->data.userID == userID && p->data.orderStatus == UNPAID) {
            Info(p);
            flag = 1;
        }
        p = p->next;
    }
    if (flag == 0) {
        printf("\t\t\t.......未找到待支付订单信息!\n");
    }
}

// 按已支付订单查询
void searchPaidOrders(Train* s, int userID) {
    Train *p;
    p = s->next;
    int flag = 0;
    printf("\n\t\t\t\t******-----已支付订单查询结果-----******\n");
    printf("\t订单编号\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价(元)\t票数（张）\n");
    while (p) {
        if (p->data.userID == userID && p->data.orderStatus == PAID) {
            Info(p);
            flag = 1;
        }
        p = p->next;
    }
    if (flag == 0) {
        printf("\t\t\t.......未找到已支付订单信息!\n");
    }
}

// 本人车票查询
void searchUserTickets(Train* s, int userID) {
    Train *p;
    p = s->next;
    int flag = 0;
    printf("\n\t\t\t\t******-----本人车票查询结果-----******\n");
    printf("\t订单编号\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价(元)\t票数（张）\n");
    while (p) {
        if (p->data.userID == userID) {
            Info(p);
            flag = 1;
        }
        p = p->next;
    }
    if (flag == 0) {
        printf("\t\t\t.......未找到本人车票信息!\n");
    }
}
// Dijkstra 算法实现
void Dijkstra(MGraph *G, int v0, int lengthOrTime) {
    int v, w, k, min;
    int final[MAX_STATIONS]; // 用于记录是否已经找到最短路径

    // 初始化
    for (v = 0; v < G->numVertexes; v++) {
        final[v] = 0;
        dist[v] = G->arc[v0][v];
        path[v] = -1;
    }
    final[v0] = 1;
    dist[v0] = 0;

    for (v = 1; v < G->numVertexes; v++) {
        min = INT_MAX;
        for (w = 0; w < G->numVertexes; w++) {
            if (!final[w] && dist[w] < min) {
                k = w;
                min = dist[w];
            }
        }
        final[k] = 1;
        for (w = 0; w < G->numVertexes; w++) {
            if (!final[w] && (min + G->arc[k][w] < dist[w])) {
                dist[w] = min + G->arc[k][w];
                path[w] = k;
            }
        }
    }
}

// 按最短路径查询
void searchShortestPath(MGraph *G, char start[], char end[], int lengthOrTime) {
    int v0, vn;
    for (int i = 0; i < G->numVertexes; i++) {
        if (strcmp(G->vexs[i].name, start) == 0) {
            v0 = i;
        }
        if (strcmp(G->vexs[i].name, end) == 0) {
            vn = i;
        }
    }
    Dijkstra(G, v0, lengthOrTime);

    // 输出最短路径
    printf("\n\t\t\t\t******-----查询结果-----******\n");
    printf("\t列车号\t发车站\t到达站\t发车时间\t到达时间\t票价(元)\t票数（张）\n");
    // 输出最短路径的车次信息等
}

void drawLine(int length, char border) {
    for (int i = 0; i < length; i++) {
        printf("%c", border);
    }
    printf("\n");
}

void displayMainMenu() {
    printf("\n\t\t\t\t******-----列车信息查询系统-----******\n");

    drawLine(45, '*');
    printf("| %-2s | %-30s |\n", "1", "按列车号查询");
    printf("| %-2s | %-30s |\n", "2", "按发车站查询");
    printf("| %-2s | %-30s |\n", "3", "按始发站到终点站查询");
    printf("| %-2s | %-30s |\n", "4", "按列车号和发车时间查询");
    printf("| %-2s | %-30s |\n", "5", "按出发地、到达地和发车时间查询");
    printf("| %-2s | %-30s |\n", "6", "查询全部列车");
    printf("| %-2s | %-30s |\n", "7", "按票价查询");
    printf("| %-2s | %-30s |\n", "8", "按车站和时间查询");
    printf("| %-2s | %-30s |\n", "9", "待支付订单查询");
    printf("| %-2s | %-30s |\n", "10", "已支付订单查询");
    printf("| %-2s | %-30s |\n", "11", "本人车票查询");
    printf("| %-2s | %-30s |\n", "12", "最短路径查询");
    drawLine(45, '*');

    printf("| %-2s | %-30s |\n", "0", "退出系统");

    drawLine(45, '*');
    printf("请选择功能: ");
}
