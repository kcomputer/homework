#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


static long long degree = 1;
static long long mod = 38083;

long long realFunction (char symbol, long long j)
{
	j = ((long long (symbol)) * degree) % mod;
	degree *= 23;
	return j;
}


long long hashFunction(string s)
{
	long long j = 0;
	string::iterator i = s.begin();
	while (i < s.end())
	{
		j += realFunction( *i, j);
		i++;
	}
	degree = 1;
	j %= mod;
	return j;
}


int rabinKarp(string s, string subString)
{
	int counter = 0;
	long long hashSubString = hashFunction(subString);
	string temp = "";
	temp = s.substr(0, subString.length());
	long long tempHash = hashFunction(temp);
	long long usefulConst = 1;
	for (int i = 0; i < subString.length(); ++i)
	{
		usefulConst*=23;
	}
	if(s.length() == subString.length())
	{
		++counter;             // wtf??
	}
	for (int i = 0; i < s.length() - subString.length(); ++i)
	{
		if (tempHash = hashSubString)
		{
			temp.clear();
			temp = s.substr(i, subString.length());
			if (temp == subString)
			{
				++counter;
			}
		}
		tempHash = (tempHash - long long(s[i])) / 23 + long long(s[i + subString.length()]) * usefulConst;
	}
	return counter;
}


int main()
{

	cout << "Enter string:\n";
	string s = "";
	getline(cin, s);
	cout << "Enter substring:\n";
	string subString = "";
	getline (cin, subString);
	cout << rabinKarp(s, subString);
	return 0;
}

