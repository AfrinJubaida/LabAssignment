#include<iostream>
#include<cstring>
using namespace std;
class mystring
{
	char *str;
	int size;
public:
	//default
	mystring()
	{
		str = new char[2];
		str = '\0';
		size = 1;

	}
	//parameterized
	mystring(char *s)
	{
		int l;
		l = strlen(s) + 1;
		str = new char[1];
		strcpy(str, s);
	}
	//copy
	mystring(const mystring &ob)
	{
		int l;
		l = strlen(ob.str) + 1;
		str = new char[1];
		strcpy(str, ob.str);
	}
	//destructor
	~mystring()
	{
		delete[] str;
	}

	void print_str()
	{
		cout << str << endl;

	}
	mystring con_str(mystring a)
	{
		char *s;
		int l = strlen(str) + strlen(a.str) + 1;
		s = new char[l];
		int i, j;
		for (i = 0; i<strlen(str); i++)
		{
			s[i] = str[i];
		}
		for (j = 0; j<strlen(a.str); j++, i++)
		{
			s[i] = a.str[j];
		}
		s[i] = '\0';
		//cout<< s <<endl;
		mystring b(s);
		return b;
	}

};

int main()
{
	mystring a("abc"), b("def");
	mystring c = a.con_str(b);
	c.print_str();
}
