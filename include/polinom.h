// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������

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
	void addFirst(const Monom& monom); //���������� � ������ ����� NULL
	void addLast(const Monom& monom);// ���������� � ������ ����� Head
	void addNow(const Monom& monom, Monom& ptr); //���������� � ������ ����� ����������� ��������. ���������� �������������� ����� ��������.
	void showList() const;
	void showList2() const;
	void delFirst();
	void delLast();
	void delElem(Monom& ptr);
	
	class Iterator //���� ������� ����� ���� ��� ������ ������ � �������� ��� ��� ����. ��� ������ ����� ��� [Head]->[]->[]->NULL
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
