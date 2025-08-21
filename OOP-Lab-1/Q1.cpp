#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(int argc, char* argv[])	{
	
	char* arrNum[22];
	
	for (int i=2; i <= argc; i++)	{
		arrNum[i]= argv[i];
//		cout << argv[i] << endl;
	}
	
	
//	for (int j=2; j<22; j++)	{
//		cout << arrNum[j] << endl;
//	}

	int max = 0, secmax = 0, maxI = -1;

	for (int j=2; j<22; j++)	{
		
		if (stoi(arrNum[j]) > max)	{
			max = stoi(arrNum[j]);
			maxI = j;
		}
	}
	for (int j=2; j<22; j++)	{
		
		if (j != maxI)	{
		
			if (stoi(arrNum[j]) > secmax)	{
				secmax = stoi(arrNum[j]);
			}
		}	
	}	
	
	cout << secmax << endl;
	
	return 0;
}
