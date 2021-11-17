#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;
using namespace std;

typedef int Type;
struct Node {
    Type elem; //данные
    Node* next; //указатель на следующий узел
    Node* prev; //указатель на предыдущий
};

class LIST {
    Node* head;
    Node* tail;
public:
    int index;
    LIST();
    void addFirst(Type elem);//+
    void addLast(Type elem);//+
    void addAfter(Node* bufwh1, Type elemin);//+
    void mergeAfter(Node* bufwh1, const LIST& it);//+
    void delTail();//+ -with throw
    void delHead();//+ -with throw
    void delElem(Type elemwh);//+ -with throw
    void sortingList();
    void count();//+ with throw
    int search_el(Type elem);//+ with throw
    Type search_in(int in);//+ with throw
    Node* search_uk(Type elem);//+ with throw
    void swap(int& a, int& b);
    void showList() const;

};

#endif