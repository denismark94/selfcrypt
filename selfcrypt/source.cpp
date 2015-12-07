#include <fstream>
#include<string>
#include <iostream>
#include <Windows.h>


using namespace std;

void exec(char * text, int (*f) (const char *,...))
{
	_asm
	{
		nop;
		nop;
		nop;
	}
	char * format = new char[4];
	format[0] = '%';
	format[1] = 's';
	format[2] = '\n';
	format[3] = '\0';
	f(format,text);
	_asm
	{
		nop;
		nop;
		nop;
	}
}

void stub(){}

int main (int argc, char** argv) 
{
	cout<<"q: exit\nd 0xXX: decrypt\ns: start function"<<endl;
	string respond = "";
	char *p;
	int xorValue;
	void(*f)(char*, int(*)(const char *, ...)) = exec;
	while(respond.compare("q") != 0) {
		getline(cin,respond);
		switch(respond[0])
		{
		case 's':
			f("Succeed",printf);
			break;
		case 'd':
			xorValue = strtol(respond.substr(2,4).c_str(), & p, 16);
			DWORD *fA = NULL, *fB = NULL;
			fA = (DWORD*)&exec;
			fB = (DWORD*)&stub;
			DWORD dwRead = 34;
			char * lpBuffer = new char [dwRead];
			DWORD *offset = (DWORD*)&exec;
			if (!ReadProcessMemory(GetCurrentProcess(),fA,lpBuffer,dwRead,&dwRead))
				cout<<GetLastError()<<endl;
			for (int i = 0; i < dwRead; i++)
				lpBuffer[i] = lpBuffer[i]^xorValue;
			if (!WriteProcessMemory(GetCurrentProcess(),offset,lpBuffer,dwRead,&dwRead))
				cout<<GetLastError()<<endl;	
			break;
		}
	}
	return 0;
}

