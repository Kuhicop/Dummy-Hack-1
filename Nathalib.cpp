#include "Nathalib.h"

DWORD ProcessID;

int FindProcessByName(char name[]){
	int pid = 0;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		do
		{
			if (_stricmp(entry.szExeFile, name) == 0)
			{
				pid = entry.th32ProcessID;
				break;
			}
		} while (Process32Next(snapshot, &entry) == TRUE);
	}

	CloseHandle(snapshot);

	return pid;
}

bool ReadProcessInteger(HANDLE pid, LPCVOID address, int &result) { return ReadProcessMemory(pid, address, &result, sizeof(int), NULL); }

bool WriteProcessInteger(HANDLE pid, LPCVOID address, int &result) { return WriteProcessMemory(pid, (LPVOID)address, &result, sizeof(int), NULL); }

string ReadProcessString(HANDLE pid, LPCVOID address, int characters_to_read) { 
	char bufferchr[100];
	if (ReadProcessMemory(pid, address, &bufferchr, characters_to_read, NULL)) {
		string bufferstring = bufferchr;
		return (bufferstring.substr(0, characters_to_read));
	}
	else {
		return "failed";
	}
}