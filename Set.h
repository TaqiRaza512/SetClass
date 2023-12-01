#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class Set
{
private:
	int size;
	int* Vs;
	static int USize;
	static int* UVs;
	bool belongto(int &num);
	bool CheckDis(Set& S)const;
public:
	Set();
	Set(int&);
	Set(ifstream& Rdr);
	void Insert(int);
	void Remove(int);
	void LoadSet(ifstream& Rdr);
	void LoadData(ifstream& Rdr);
	void DeAllocateSet();
	void AllocateSet(const Set&);


	friend ostream& operator<<(ostream&, Set& S);
	friend istream& operator>>(istream&, Set& S);
	friend ofstream& operator<<(ofstream&, Set& S);
	friend ifstream& operator>>(ifstream&, Set& S);
	const Set& operator=(const Set& S);
	const Set operator+(const Set& S)const;
	const Set operator^(Set& S)const;
	const Set operator-(Set& S)const;
	bool operator|(Set& S);
	const Set& operator+=(int);
	const Set& operator-=(int);
	const Set& operator+=(const Set& S);
	const Set& operator-=(Set& S);
	bool operator==(const Set& S);
	const Set operator!=(Set& S);



};

