#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
void execute() 
{
	printf("Secret function is active!\n");
}

void stub(){}

int main (int argc, char** argv) 
{	
	/*HANDLE h = OpenProcess(PROCESS_VM_OPERATION
		|PROCESS_VM_WRITE,
		true,GetCurrentProcessId());*/
	printf("%p\n",execute);
	std::ifstream ifs(argv[0],ifstream::in 
		|ifstream::binary);
	//ifs.seekg
	//WriteProcessMemory(h,);
	//execute();
	system("PAUSE");
	return 0;
}

