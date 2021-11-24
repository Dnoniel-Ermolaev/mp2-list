#include "list.h"

typedef int Type;

LIST::LIST() {
    head = tail = NULL;
    index = 0;
}
//подсчёт элементов в списке+
void LIST::count()
{
    index = 0;
    if (head) {
        Node* buf = head;
        while (buf) {
            index++;
            buf = buf->next;
        }
    }
}

Node* LIST::search_uk(Type elem) {
    int i = 0;
    if (head) {
        Node* buf = head;
        while (buf) {
            if (buf->elem == elem)return buf;
            buf = buf->next;
            i++;
        }
        //cout << "нет такого элемента";
        throw "No this elemets";
    }

}
//поиск элемента по индексу элемента+
Type LIST::search_in(int in) {
    int i = 0;
    if (head) {
        Node* buf = head;
        while (buf) {
            if (i == in) return buf->elem;
            buf = buf->next;
            i++;
        }
    }
    //return NULL;//если не нашёл, то возвращает NULL 
    throw "No this elemets";
}

//поиск индекса элемента по элементу+
int LIST::search_el(Type elem) {
    int i = 0;
    if (head) {
        Node* buf = head;
        while (buf) {
            if (buf->elem == elem)return i;
            i++;
            buf = buf->next;
        }
    }
    //i = NULL;
    //return i;//Возвращает NULL если не нашёл, по хорошему возвращать ошибку
    throw "No this elements";
}

//Добавление узла в начало+
void LIST::addFirst(Type elem) {
    Node* buf = new Node;
    buf->elem = elem;
    if (!head) {
        buf->next = tail;
        tail = buf;
    }
    else {
        buf->next = head;
        head->prev = buf;
    }
    head = buf;
    head->prev = NULL;

}

//Добавление узла в конец+
void LIST::addLast(Type elem) {
    Node* buf = new Node;
    buf->elem = elem;
    if (!head) {
        buf->next = tail;
        head = buf;
        buf->prev = NULL;
    }
    else {
        buf->next = tail->next;
        buf->prev = tail;
        tail->next = buf;
    }
    tail = buf;
}
//Добавление нужного элемента после указанного элемента+
void LIST::addAfter(Node* bufwh1, Type elemin) {
    //Node* bufwh = new Node;
    //bufwh = bufwh1;//находит то, где лежит элемент после которого вставить

    if ((bufwh1 != tail) || (bufwh1 == head))
    {
        Node* bufin1 = new Node;
        bufin1->elem = elemin;

        bufin1->next = bufwh1->next;
        bufin1->prev = bufwh1;
        //if (bufin1->prev == bufwh1->next->prev) bufwh1->next->prev = bufin1;
        bufwh1->next = bufin1;
        bufin1->next->prev = bufin1;

    }
    else if ((bufwh1 == tail) && (bufwh1 != head)) {
        Node* bufin2 = new Node;
        bufin2->elem = elemin;
        bufin2->next = NULL;
        bufwh1->next = bufin2;
        bufin2->prev = bufwh1;
        tail = bufin2;

        //bufwh->next->prev = bufin;
    }
    /*else if ((bufwh1 != tail) && (bufwh1 == head)) {
        Node* bufin = new Node;
        bufin->elem = elemin;
        bufin->next = bufwh1->next;
        bufwh1->next = bufin;

        bufin->prev = NULL;
        //head = bufin;
        //bufwh->next->prev = bufin;
    }*/
    else cout << "Нет такого элемента";
}
//сложить один список с другим +
void LIST::mergeAfter(Node* bufwh1, const LIST& it) {
    Node* bufwh = new Node;
    bufwh = bufwh1;

    if (it.head)
    {
        Node* buf = new Node;
        buf = it.head;
        while (buf)
        {
            addAfter(bufwh, buf->elem);
            buf = buf->next;
        }
        //bufwh = bufwh->next;
    }

}

//Пройти по списку и вывести все элементы+
void LIST::showList() const {
    if (head) {
        Node* buf = head;
        while (buf) {
            cout << buf->elem << " ";
            buf = buf->next;
        }
        cout << endl;
    }
    else cout << "List is empty " << endl;
}

//Удаление головы+
void LIST::delHead() {
    if (head) {
        Node* buf = head;
        head = head->next;
        head->prev = NULL;
        delete buf;
    }
    else cout << "List is empty" << endl;
}

//Удаление хвоста+
void LIST::delTail() {
    if (tail) {
        Node* buf = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete buf;
    }
    else cout << "List is empty" << endl;
}
void LIST::delElem(Type elemwh) {
    Node* bufwh = new Node;
    bufwh = search_uk(elemwh);
    if ((bufwh == head) && (bufwh != tail)) {
        Node* buf = head;
        head = head->next;
        head->prev = NULL;
        delete buf;
    }

    if ((bufwh != head) && (bufwh == tail)) {
        Node* buf = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete buf;
    }

    if ((bufwh != head) && (bufwh != tail))
    {
        Node* bufprev = bufwh->prev;
        Node* bufnext = bufwh->next;
        bufprev->next = bufnext;
        bufnext->prev = bufprev;

    }
    delete bufwh;
}
//Обмен данных списка+
void LIST::swap(int& a, int& b) {
    int buf = a;
    a = b;
    b = buf;
}

//Сортировка+
void LIST::sortingList() {
    Node* buf = head;
    for (Node* i = buf; i; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            if (i->elem < j->elem) {
                swap(i->elem, j->elem);
            }
        }
    }

}
//проверка на уникальность--находится в разработке
void LIST::unique() {
    Node* tmp = head->next;
    Node* prev = head;
    while (tmp != nullptr) {
        Node* tmp2 = head;
        bool find = false;
        prev = tmp->prev;
        while ((tmp2 != tmp) && (!find)) {
            if (tmp2->elem == tmp->elem) find = true;
            else {
                tmp2 = tmp2->next;

            }
            if (find) {

                Node* bufwh = new Node;
                bufwh = tmp2;
                if ((bufwh == head) && (bufwh != tail))
                {
                    Node* buf = head;
                    head = head->next;
                    head->prev = NULL;
                    delete buf;
                }
                else {
                    if ((bufwh != head) && (bufwh == tail)) {
                        Node* buf = tail;
                        tail = tail->prev;
                        tail->next = NULL;
                        delete buf;
                        //prev = tmp->prev;
                    }
                    else {
                        if ((bufwh != head) && (bufwh != tail))
                        {
                            Node* bufprev = bufwh->prev;
                            Node* bufnext = bufwh->next;
                            bufprev->next = bufnext;
                            bufnext->prev = bufprev;
                            delete bufwh;
                            // prev = tmp->prev;
                        }
                    }
                }
                /*if ((bufwh != head) && (bufwh != tail))
                {
                    Node* bufprev = bufwh->prev;
                    Node* bufnext = bufwh->next;
                    bufprev->next = bufnext;
                    bufnext->prev = bufprev;

                }*/
                // delete bufwh;
                 //delElem(tmp2->elem);
                // prev = tmp->prev;
                // find = false;
            }
          
        }
        tmp = tmp->next;

        prev = prev->next;
    }

}

void LIST::inverse() {
    count();
    int i = index - 1;
    int k;
    for (k = 0; k < index / 2 + 1; k++) {
        swap(search_uk(search_in(k))->elem, search_uk(search_in(i))->elem);
        i--;

    }
}

bool LIST::equal(LIST& it1) {
    it1.count();
    count();
    if (it1.index != index) return 0;
    else {
        if (head) {
            Node* buf = head;
            Node* buf2 = it1.head;
            while (buf) {
                if (buf->elem != buf2->elem)return 0;
                buf = buf->next;
                buf2 = buf2->next;
            }
        }
    }
    return 1;
}