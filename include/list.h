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
    void addFirst(Type elem);
    void addLast(Type elem);
    void addAfter(Node* bufwh1, Type elemin);
    void mergeAfter(Node* bufwh1, const LIST& it);
    void delTail();
    void delHead();
    void delElem(Type elemwh);
    void sortingList();
    void count();
    void unique();
    int search_el(Type elem);
    Type search_in(int in);
    Node* search_uk(Type elem);
    void swap(int& a, int& b);
    void showList() const;
    void inverse();
    bool equal(LIST& it1);
};

#endif