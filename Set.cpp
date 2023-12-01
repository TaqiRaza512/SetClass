#include "Set.h"
#include<iostream>
#include<fstream>
using namespace std;

Set::Set()
{
	size = 0;
	Vs = nullptr;
}
Set::Set(int& S)
{
	size = S;
	Vs = new int[size] {};
}	
Set::Set(ifstream& Rdr)
{
	LoadData(Rdr);	
}
void Set::LoadData(ifstream& Rdr)
{
	Rdr >> size;
	int dummy;
	Vs = new int[size] {};
	for (int ri = 0; ri < size; ri++)
	{
		Rdr >> dummy;

		if (dummy != -1)
		{
			Vs[ri] = dummy;
		}
	}
}
void Set::LoadSet(ifstream &Rdr)
{
	this->LoadData(Rdr);
}
void Set::Insert(int val)
{
	int* Hp = new int[this->size + 1];
	int ri;
	for (ri = 0; ri < this->size; ri++)
	{
		Hp[ri] = this->Vs[ri];
	}
	Hp[ri] = val;
	delete[]this->Vs;
	this->Vs = Hp;
	this->size++;
}
void Set::Remove(int val)
{
	
	if (this->belongto(val))
	{
		int* Hp = new int[this->size - 1];
		for (int ri = 0, j = 0; ri < this->size; j++)
		{
			if (!(val == this->Vs[j]))
			{
				Hp[ri] = this->Vs[j];
				ri++;
			}
			else
			{
				this->size--;

			}
		}
		delete[]this->Vs;
		this->Vs = Hp;
	}
}
ostream& operator<<(ostream&,Set& S)
{
	cout << S.size<<"\t";
	for (int ri=0;ri<S.size;ri++)
	{
		cout << S.Vs[ri]<<" ";
	}
	return cout;
}
istream& operator>>(istream& ,Set& S)
{
	cin >> S.size;
	for (int ri = 0; ri < S.size; ri++)
	{
		cin >> S.Vs[ri];
	}
	return cin;
}
ifstream& operator>>(ifstream& Rdr, Set& S)
{
	S.LoadData(Rdr);	
	return Rdr;
}
ofstream& operator<<(ofstream& Rdr, Set& S)
{
	Rdr << S.size << "\t";
	for (int ri = 0; ri < S.size; ri++)
	{
		Rdr << S.Vs[ri] << " ";
	}
	return Rdr;
}
void Set::DeAllocateSet()
{
	if (this->Vs!=nullptr)
	{		
		delete[]this->Vs;
	}
}
void Set::AllocateSet(const Set& S)
{
	this->size = S.size;
	this->Vs = new int[S.size];
	for (int ri = 0; ri < S.size; ri++)
	{
		this->Vs[ri] = S.Vs[ri];
	}
}
const Set& Set::operator=(const Set& S)
{
	this->DeAllocateSet();
	this->AllocateSet(S);
	return *this;
}
bool Set::belongto(int& num)
{
	for (int ri=0;ri<this->size;ri++)
	{
		if (this->Vs[ri]==num)
		{
			return true;
		}
	}
	return false;
}
const Set Set::operator+(const Set& S)const
{
	Set Res;
	Res.AllocateSet(*this);
	for (int ri=0;ri<S.size;ri++)
	{
		if (!Res.belongto(S.Vs[ri]))
		{
			Res.Insert(S.Vs[ri]);
		}
	}
	return Res;
}
const Set Set::operator^(Set& S)const
{

	Set Res;
	for (int ri=0;ri<this->size;ri++)
	{
		if (S.belongto(this->Vs[ri]))
		{
			Res.Insert(this->Vs[ri]);
		}
	}
	return Res;	
}
bool Set::CheckDis(Set &S)const
{
	for (int ri = 0; ri < this->size;ri++)
	{
		if (S.belongto(this->Vs[ri]))
		{
			return false;
		}
	}
}
bool Set::operator|(Set& S)
{
	if (this->CheckDis(S) && S.CheckDis(*this))
	{
		return true;
	}
}
const Set Set::operator-(Set &S)const
{
	Set Res;
	for (int ri=0;ri<this->size;ri++)
	{
		if (!S.belongto(this->Vs[ri]))
		{
			Res.Insert(this->Vs[ri]);
		}
	}
	return Res;
}
const Set& Set::operator+=(int num)
{	
	if (!this->belongto(num))
	{
		this->Insert(num);
	}
	return *this;
}
const Set& Set::operator-=(int num)
{
	if (this->belongto(num))
	{
		this->Remove(num);
	}
	return *this;
}
const Set& Set::operator+=(const Set& S)
{
	*this = *this + S;
	return *this;
}
const Set& Set::operator-=(Set& S)
{
	*this = *this - S;
	return *this;
}
bool Set::operator==(const Set& S)
{
	int count = 0;
	if (this->size==S.size)
	{
		for (int ri=0;ri<S.size;ri++)
		{
			if (this->belongto(S.Vs[ri]))
			{
				count++;
			}
		}
		if (count == this->size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
const Set Set::operator!=(Set& S)
{
	ifstream Rdr("U.txt");
	Set U(Rdr);
	*this = U - S;
	return *this;
}
