#include "Public1.h"
#include "Reality.h"
#include "Search.h"
#include "Ticket.h"
#include "DataEntry.h"
#include "Login.h"
#include "Sqlist.h"
#include "LinkList.h"

using namespace std;

int main() {
    // 初始化用户表
    SqList<User> user_list;
    user_list.InitList();
    ReadUser(user_list);

    User current_user;
    /*****************************
     * 这里实现登录
     * 将登陆完成的User赋值给current_user
     * 给后续使用
    *****************************/
    // 这里使用一个示例
    user_list.GetElem(1, current_user);

    //初始化票的链表
    LinkedList<Ticket> ticket_list;
    ReadTicket(ticket_list);

    Ticket ticket_to_purchase;
    /*****************************
     * 这里实现票的搜索
     * 将搜索且选中的票赋值给ticket_to_purchase
    *****************************/
    // 这里使用一个示例
    ticket_to_purchase = ticket_list.GetElem(1);

    // 测试一下购票
    if (PurchaseTicket(current_user, ticket_to_purchase)) {
        cout << "购票成功" << endl;
    } else {
        cout << "已加入等候列表中" << endl;
    }

    // 测试完成将结果写入
    // 注意这里要删除一个插入一个
    User user_delete_temp;
    user_list.ListDelete(1, user_delete_temp);
    user_list.ListInsert(1, current_user);

    WriteUser(user_list);

    /***************************
     * 准备退出程序
     * 1.将所有内容写入数据文件
     * 2.清除所有数据结构避免内存泄漏
     * (SqList与LinkedList使用了“资源获取即初始化”（RAII）不需要清理)
    ***************************/

    return 0;
}
