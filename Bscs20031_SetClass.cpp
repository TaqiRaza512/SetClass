#include"Set.h"
#include<iostream>
#include<fstream>
using namespace std;
void LoadSets(Set*& S, int& Nofs)
{
	ifstream Rdr("Set.txt");
	Rdr >> Nofs;
	S = new Set[Nofs];
	for (int ri=0;ri< Nofs;ri++)
	{
		S[ri].LoadSet(Rdr);
	}
}
void Print(Set*& S, int& Nofs)
{
	for (int ri=0;ri<Nofs;ri++)
	{
		cout << S[ri]<<endl;
	}
}

int main()
{	
	int NofS;
	Set* S;
	int num = 12;
	LoadSets(S, NofS);	
	Print(S,NofS);
	cout << endl;
	S[0] != S[0];
	cout << endl << S[0];
	

}