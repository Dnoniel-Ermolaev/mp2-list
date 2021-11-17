#include "list.h"
#include <gtest.h>
#include <iostream>


TEST(LIST, test) {//просто main, не несущий важности проверки
        setlocale(LC_ALL, "RUS");


        LIST mylist;
        int a_i;
        cout << "Enter elements" << endl;
        int j = 1;
        while (j < 10) {
                mylist.addFirst(j);
                j++;
        }
        mylist.count();
        mylist.addFirst(1000);
        cout << "1000 This is:";
        cout << mylist.search_el(1000) << endl;
        //mylist.sortingList();
        
        cout << mylist.index << endl;
        cout << "Элемент 5 находится по индексу:";
        cout << mylist.search_el(5) << endl;
        cout << "Элемент по номеру 3 это:";
        cout << mylist.search_in(3) << endl;
        cout << "Найти элемент 5 и вернуть указатель:";
        cout << mylist.search_uk(5)->elem << endl;

        mylist.addAfter(mylist.search_uk(1), 55);
        mylist.showList();
        mylist.addAfter(mylist.search_uk(55), 57);
        mylist.showList();
        mylist.addAfter(mylist.search_uk(55), 58);
        mylist.showList();
        mylist.addAfter(mylist.search_uk(58), 59);
        mylist.showList();
        mylist.addAfter(mylist.search_uk(59), 60);
        mylist.showList();


        mylist.delTail();
        mylist.showList();

        mylist.delTail();
        mylist.showList();

        mylist.delTail();
        mylist.showList();

        mylist.delTail();
        mylist.showList();

        //mylist.delHead();
        mylist.addAfter(mylist.search_uk(9), 55);
        mylist.addAfter(mylist.search_uk(9), 55);


        LIST mylist2;
        int i = 100;
        while (i < 500) {
            mylist2.addFirst(i);
            i = i + 100;
        }

        mylist.mergeAfter(mylist.search_uk(9), mylist2);
        cout << "list после суммы с другим list : " << endl;
        mylist.delElem(4);
        mylist.delElem(6);
        mylist.delElem(7);

        mylist.showList();
        mylist.count();

        mylist.showList();
        //_______________________





        cout << "Hello World!" << endl;
        
    }
TEST(LIST,test_crate_list) {
    LIST a;
    ASSERT_NO_THROW();
}
TEST(LIST,test_add_first) {
    LIST a;
    a.addFirst(1);
    ASSERT_NO_THROW();
}
TEST(LIST,test_add_first_equal_head) {
    LIST a;
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    ASSERT_EQ(3,a.search_uk(3)->elem);
}
TEST(LIST, test_add_last) {
    LIST a;
    a.addLast(1);
    a.addLast(2);
    a.addLast(3);
    ASSERT_NO_THROW();
}
TEST(LIST, test_add_last_equal_tail) {
    LIST a;
    a.addLast(1);
    a.addLast(2);
    a.addLast(3);
    ASSERT_EQ(1, a.search_uk(1)->elem);
}
TEST(LIST, test_add_after) {//Здесь приходится проводить два теста для того, чтоб точно удостовериться в верном расположении узла и его значении
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    a.addAfter(a.search_uk(3),1000);
    ASSERT_EQ(1000,a.search_uk(1000)->elem);
    ASSERT_EQ(3, a.search_el(1000));
}
TEST(LIST, test_del_Head) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    a.delHead();
    ASSERT_EQ(4, a.search_uk(4)->elem );
}
TEST(LIST, test_del_Tail) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    a.delTail();
    ASSERT_EQ(2, a.search_uk(2)->elem);
}
TEST(LIST, test_all_del) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    a.delTail();
    a.delHead();
    ASSERT_EQ(2, a.search_uk(2)->elem);
    ASSERT_EQ(4, a.search_uk(4)->elem);

}
TEST(LIST, test_two_del_head) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    a.delHead();
    a.delHead();
    ASSERT_EQ(3, a.search_uk(3)->elem);
}
TEST(LIST, test_two_del_tail) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    a.delTail();
    a.delTail();
    ASSERT_EQ(3, a.search_uk(3)->elem);
}
TEST(LIST, test_del_elem) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    a.delElem(4);
    a.delElem(3);
    ASSERT_EQ(2, (a.search_uk(5)->next->elem));
}
TEST(LIST, test_search_in) {
    LIST a;
   
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_EQ(2, a.search_in(3));
}
TEST(LIST, test_search_in_throw) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_ANY_THROW(a.search_in(100));
}
TEST(LIST, test_search_el) {
    LIST a;
   
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_EQ(3, a.search_el(2));
}
TEST(LIST, test_search_el_throw) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_ANY_THROW(a.search_el(100));
}
TEST(LIST, test_search_uk) {
    LIST a;
   
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_EQ(4, a.search_uk(4)->elem);
}
TEST(LIST, test_search_uk_throw) {
    LIST a;
  
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_ANY_THROW(a.search_uk(100));
}
TEST(LIST,test_count) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    a.count();
    ASSERT_EQ(5, a.index);
}
TEST(LIST, test_count_without_elements) {
    LIST a;

    a.count();
    ASSERT_EQ(0, a.index);
}
TEST(LIST, test_Merge) {
    LIST a;
    LIST b;
    int i = 100;
    while (i < 500) {
        a.addFirst(i);
        i = i + 100;
    }
    
    int j = 0;
    while (j < 10) {
        b.addFirst(j);
        j = j + 1;
    }
    a.mergeAfter(a.search_uk(100), b);
    a.count();
   ASSERT_EQ(100, a.search_in(3));
   ASSERT_EQ(0, a.search_in(4));
   ASSERT_EQ(1, a.search_in(5));


}
