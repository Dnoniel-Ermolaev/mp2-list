// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов

#pragma once
#include "monom.h"
#include <vector>
#include <string>


class Polinoms{
	//Monom* head;

	std::vector<std::string> Lexs;
	void parser(const std::string& input);
	bool check_vars() const;
	bool check_points() const;
	bool isCorrect() const;
	void converter();

public:
	Monom* head;
	void str_to_poly(const std::string& _input);
	~Polinoms();
	Polinoms();
	Polinoms(const Polinoms& poly);
	void addFirst(const Monom& monom); //Добавление в список перед NULL
	void addLast(const Monom& monom);// Добавление в список перед Head
	void addNow(const Monom& monom, Monom& ptr); //Добавление в список после конкретного элемента. Правильное взаимодействие через Итератор.
	void showList() const;
	void showList2() const;
	void delFirst();
	void delLast();
	void delElem(Monom& ptr);
	
	class Iterator //Надо ставить после того как создал список и заполнил его чем либо. Ибо список имеет вид [Head]->[]->[]->NULL
	{
	public:
		Monom* ptr;
		Iterator(){}
		Iterator(Monom* _ptr = nullptr);
		
		Iterator operator++(int);
		Iterator& operator++();
		Monom& operator*();
	};
	Iterator begin();
	Iterator end();
	Polinoms& operator=(const Polinoms& poly);
	Polinoms& operator+=(const Monom& monom);
	Polinoms& operator-=(const Monom& monom);
	Polinoms  operator+(const Monom& monom) const;
	Polinoms  operator-(const Monom& monom) const;
	Polinoms  operator*(const Monom& monom) const;
	Polinoms& operator*=(const Monom& monom);
	Polinoms& operator+=(double scalar);
	Polinoms& operator-=(double scalar);
	Polinoms operator+(double scalar) const;
	Polinoms operator-(double scalar) const;
	Polinoms operator*(double scalar) const;
	Polinoms& operator*=(double scalar);
	Polinoms& operator+=(const Polinoms& poly);
	Polinoms& operator-=(const Polinoms& poly);
	Polinoms operator+(const Polinoms& poly) const;
	Polinoms operator-(const Polinoms& poly) const;
	Polinoms operator*(const Polinoms& poly) const;
	bool operator==(const Polinoms& poly) const;
	
};
