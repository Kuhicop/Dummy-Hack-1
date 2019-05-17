#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "Nathalib.h"
using namespace std;

// Process
char process_name[] = "Dummy Target 1.exe";

// Variables
int addr_varInt = 0x0091F970, addr_varString = 0x0091F980, addr_varChar = 0x0091F9C8;

// Pointers


int main()
{	  
	while(true)
	{   
		int buffer = 0;

		// Get PID
		cout << process_name << " PID: ";
		int pid = FindProcessByName(process_name);
		if (pid != 0) {
			cout << pid << endl;
		}
		else {
			cout << "Unable to find PID!" << endl;
			getchar();
			return 0;
		}
		
		// Open Process
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		if (hProcess == NULL) { // Failed to get a handle
			cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
			system("pause");
			return EXIT_FAILURE;
		}
		else
		{
			cout << "Process " << pid << " is open." << endl << endl;
		}

		// Read Process Memory
		if (ReadProcessInteger(hProcess, (LPCVOID)addr_varInt, buffer)) {
			cout << "addr_varInt = " << buffer << endl;
		}
		else
		{
			cout << "Unable to read " << addr_varInt << endl;
		}

		cout << "Press any key to repeat." << endl;
		getchar();		
	}
	return 0;
}
