#include<iostream>
#include"Vector.h"
using namespace std;
int main()
{
	Vector<int>V;
	for (int i = 0; i < 3; i++)
	{
		V.insert(3 - i);
		cout << V[i] <<endl;
	}
	V.insertsort();
	for (int i = 0; i < 3; i++)
		cout << endl << V[i];
	cin >> V[2];
	cout << V[2];
}