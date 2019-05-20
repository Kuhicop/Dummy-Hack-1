#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "Nathalib.h"
using namespace std;

// Process
char process_name[] = "Dummy Target 1.exe";
const int INT_TO_WRITE = 5000;

// Variables
const int addr_varInt = 0x0105F9A0;
const int ptr2int = 0x0105F9A4;
const int ptr2int_array[4] = { 0x0105F9A4, 0, 0, 0 }; //[address][offset1][offset2]...
const int defaultstring[2] = { 0x0105F9B0, 13 }; //[address][characters to read]
const int varchar[2] = { 0x0105F9F8, 30 }; //[address][characters to read]

int main()
{	  
	// Get PID
	cout << dec << process_name << " PID: ";
	int pid = FindProcessByName(process_name);
	if (pid != 0) {
		cout << pid << endl;
	}
	else {
		cout << "Unable to find PID!" << endl;
		getchar();
		return EXIT_FAILURE;
	}

	// Open Process -- PROCESS_ALL_ACCESS
	HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, pid);
	if (hProcess == NULL) { // Failed to get a handle
		cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	else
	{
		cout << "Process " << pid << " is open." << endl << endl;
	}

	while(true)
	{   
		int buffer = 0;

		// Read varInt
		if (ReadProcessInteger(hProcess, (LPCVOID)addr_varInt, buffer)) {
			cout << "addr_varInt = " << buffer << endl;
		}
		else
		{
			cout << "Unable to read " << addr_varInt << endl;
		}

		// Read ptr2int
		if (ReadProcessInteger(hProcess, (LPCVOID)ptr2int, buffer)) {
			cout << "ptr2int = 0x0" << hex << uppercase << buffer;
			if (ReadProcessInteger(hProcess, (LPCVOID)buffer, buffer)) {
				cout << " --> " << dec << uppercase << buffer << endl;
			}
			else
			{
				cout << "Unable to read " << ptr2int << endl;
			}
		}
		else
		{
			cout << "Unable to read " << ptr2int << endl;
		}

		// Read ptr2int_array
		if (ReadProcessInteger(hProcess, (LPCVOID)((((ptr2int_array[0] + ptr2int_array[1]) + ptr2int_array[2]) + ptr2int_array[3])), buffer)) {
			cout << "ptr2int_array = 0x0" << hex << uppercase << buffer;
			if (ReadProcessInteger(hProcess, (LPCVOID)buffer, buffer)) {
				cout << " --> " << dec << uppercase << buffer << endl;
			}
			else
			{
				cout << "Unable to read " << ptr2int_array[0] << endl;
			}
		}
		else
		{
			cout << "Unable to read " << ptr2int_array[0] << endl;
		}
		
		// Read defaultstring
		string bufferstring = ReadProcessString(hProcess, (LPCVOID)defaultstring[0], defaultstring[1]);
		if (bufferstring != "failed") {
			cout << "defaultstring = " << dec << bufferstring << endl;
		}
		else
		{
			cout << "Unable to read " << defaultstring[0] << endl;
		}

		// Read varchar
		bufferstring = ReadProcessString(hProcess, (LPCVOID)varchar[0], varchar[1]);
		if (bufferstring != "failed") {
			cout << "varchar = " << dec << bufferstring << endl;
		}
		else
		{
			cout << "Unable to read " << varchar[0] << endl;
		}

		// Write varInt
		int value_to_write = 5000;
		WriteProcessInteger(hProcess, );


		cout << endl << "Press any key to repeat." << endl;
		getchar();		
		system("cls");
	}
	return 0;
}
