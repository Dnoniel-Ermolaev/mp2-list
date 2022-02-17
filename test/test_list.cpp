#include "list.h"
#include "monom.h"
#include "polinom.h"
#include <gtest.h>
#include <iostream>


//Тест на создание списка
TEST(Polinoms,test_create_polinoms) {
	Monom a(-10, 2, 2, 2);
	Monom b(1, 3, 3, 3);
	Monom c(1, 4, 4, 4);
	

	Polinoms A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.showList2();
	auto it1 = A.begin();
	
    ASSERT_NO_THROW();
}
//Добавление в начало

