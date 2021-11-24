#include "list.h"
#include <gtest.h>
#include <iostream>


//Тест на создание списка
TEST(LIST,test_create_list) {
    LIST a;
    ASSERT_NO_THROW();
}
//Добавление в начало
TEST(LIST,test_add_first) {
    LIST a;
    a.addFirst(1);
    ASSERT_NO_THROW();
}
//Проверка, что при добавлении в начало, элемент становится равным head
TEST(LIST,test_add_first_equal_head) {
    LIST a;
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    ASSERT_EQ(3,a.search_uk(3)->elem);
}
//Добавление в конец
TEST(LIST, test_add_last) {
    LIST a;
    a.addLast(1);
    a.addLast(2);
    a.addLast(3);
    ASSERT_NO_THROW();
}
//Проверка, что при добавлении в конец, элемент становится tail
TEST(LIST, test_add_last_equal_tail) {
    LIST a;
    a.addLast(1);
    a.addLast(2);
    a.addLast(3);
    ASSERT_EQ(1, a.search_uk(1)->elem);
}
//Добавление после какого-то элемента
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
//Удаление head
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
//Удаление tail
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
//Удаление head+tail
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
//Повторное удаление head
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
//Повторное удаление tail
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
//Удаление конкретного элемента
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
//Поиск по индексу -> вернёт значение
TEST(LIST, test_search_in) {
    LIST a;
   
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_EQ(2, a.search_in(3));
}
//Поиск по индексу с исключением
TEST(LIST, test_search_in_throw) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_ANY_THROW(a.search_in(100));
}
//Поиск по значению -> вернёт индекс
TEST(LIST, test_search_el) {
    LIST a;
   
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_EQ(3, a.search_el(2));
}
//Поиск по значению с исключение
TEST(LIST, test_search_el_throw) {
    LIST a;
    
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_ANY_THROW(a.search_el(100));
}
//Поиск по значению -> вернёт указатель
TEST(LIST, test_search_uk) {
    LIST a;
   
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_EQ(4, a.search_uk(4)->elem);
}
//Поиск по значению с исключением 
TEST(LIST, test_search_uk_throw) {
    LIST a;
  
    a.addFirst(1);
    a.addFirst(2);
    a.addFirst(3);
    a.addFirst(4);
    a.addFirst(5);
    ASSERT_ANY_THROW(a.search_uk(100));
}
//Подсчёт элеентов в списке
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
//Проверка на подсчёт элементов в пустом списке
TEST(LIST, test_count_without_elements) {
    LIST a;

    a.count();
    ASSERT_EQ(0, a.index);
}
//Проверка на возможность =+ двух списков
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
//Проверка на сравнение списков
TEST(LIST, test_equal_1) {
    LIST mylist3;

    mylist3.addFirst(1);
    mylist3.addFirst(2);
    mylist3.addFirst(3);
    mylist3.addFirst(4);
    mylist3.addFirst(5);
    
    
    LIST mylist4;
    mylist4.addFirst(1);
    mylist4.addFirst(2);
    mylist4.addFirst(3);
    mylist4.addFirst(4);
    mylist4.addFirst(5);
    ASSERT_EQ(1, mylist4.equal(mylist3));


}
TEST(LIST, test_equal_2_check_large) {
    LIST mylist3;

    mylist3.addFirst(1);
    mylist3.addFirst(2);
    mylist3.addFirst(3);
    mylist3.addFirst(4);
    mylist3.addFirst(5);


    LIST mylist4;
    mylist4.addFirst(1);
    mylist4.addFirst(2);
    mylist4.addFirst(3);
    mylist4.addFirst(4);
    ASSERT_EQ(0, mylist4.equal(mylist3));


}
TEST(LIST, test_equal_3_after_operations) {
    LIST mylist3;

    mylist3.addFirst(1);
    mylist3.addFirst(2);
    mylist3.addFirst(3);
    mylist3.addFirst(4);
    mylist3.addFirst(5);


    LIST mylist4;
    mylist4.addFirst(6);
    mylist4.addFirst(7);
    mylist4.addFirst(8);
    mylist3.mergeAfter(mylist3.search_uk(5),mylist4);
    
    LIST mylist5;

    mylist5.addFirst(1);
    mylist5.addFirst(2);
    mylist5.addFirst(3);
    mylist5.addFirst(4);
    mylist5.addFirst(8);
    mylist5.addFirst(7);
    mylist5.addFirst(6);
    mylist5.addFirst(5);

    ASSERT_EQ(1, mylist5.equal(mylist3));


}
//Проверка на правильную операцию по созданию уникального списка 
TEST(LIST, test_unique_1) {
    LIST mylist3;

    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.unique();
    LIST mylist4;
    mylist4.addFirst(4);
    ASSERT_EQ(1, mylist4.equal(mylist3));
}
TEST(LIST, test_unique_2) {
    LIST mylist3;

    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(3);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.unique();
    LIST mylist4;
    mylist4.addFirst(4);
    mylist4.addFirst(3);

    ASSERT_EQ(1, mylist4.equal(mylist3));
}
TEST(LIST, test_unique_3) {
    LIST mylist3;

    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(5);
    mylist3.unique();
    LIST mylist4;
    mylist4.addFirst(4);
    mylist4.addFirst(5);

    ASSERT_EQ(1, mylist4.equal(mylist3));
}
TEST(LIST, test_unique_4) {
    LIST mylist3;

    mylist3.addFirst(5);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(5);
    mylist3.unique();
    LIST mylist4;
    mylist4.addFirst(5);
    mylist4.addFirst(4);

    ASSERT_EQ(1, mylist4.equal(mylist3));
}
TEST(LIST, test_unique_5_after_operations) {
    LIST mylist3;

    
    mylist3.addFirst(1);
    mylist3.addFirst(2);
    mylist3.addFirst(3);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(3);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(3);

    mylist3.addFirst(5);
    mylist3.addFirst(6);

    mylist3.addAfter(mylist3.search_uk(5), 57);
    mylist3.addAfter(mylist3.search_uk(5), 57);
    mylist3.addAfter(mylist3.search_uk(5), 57);
    mylist3.unique();
    //cout << "\ninverse" << endl;
    //cout<<mylist3.search_in(0);
    mylist3.inverse();
   //mylist3.showList();

    LIST mylist4;
    mylist4.addFirst(6);
    mylist4.addFirst(5);
    mylist4.addFirst(57);
    mylist4.addFirst(4);
    mylist4.addFirst(3);
    mylist4.addFirst(2);
    mylist4.addFirst(1);
  //  mylist4.showList();

    ASSERT_EQ(1, mylist4.equal(mylist3));
}
//Проверка на правильную операцию инверсии списка
TEST(LIST, test_inverse_1) {
    LIST mylist3;


    mylist3.addFirst(1);
    mylist3.addFirst(2);
    mylist3.addFirst(3);
    mylist3.addFirst(4);

    LIST mylist4;
    mylist4.addFirst(4);
    mylist4.addFirst(2);
    mylist4.addFirst(3);
    mylist4.addFirst(1);

    mylist3.inverse();

    ASSERT_EQ(1, mylist4.equal(mylist3));
}
TEST(LIST, test_inverse_2_after_operations) {
    LIST mylist3;


    mylist3.addFirst(1);
    mylist3.addFirst(2);
    mylist3.addFirst(3);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(3);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(4);
    mylist3.addFirst(3);

    mylist3.addFirst(5);
    mylist3.addFirst(6);

    mylist3.addAfter(mylist3.search_uk(5), 57);
    mylist3.addAfter(mylist3.search_uk(5), 57);
    mylist3.addAfter(mylist3.search_uk(5), 57);
    mylist3.unique();
    //cout << "\ninverse" << endl;
    //cout<<mylist3.search_in(0);
    //mylist3.showList();

    LIST mylist4;
    mylist4.addFirst(6);
    mylist4.addFirst(5);
    mylist4.addFirst(57);
    mylist4.addFirst(4);
    mylist4.addFirst(3);
    mylist4.addFirst(2);
    mylist4.addFirst(1);
   // mylist4.showList();
    mylist4.inverse();
    ASSERT_EQ(1, mylist4.equal(mylist3));
}
