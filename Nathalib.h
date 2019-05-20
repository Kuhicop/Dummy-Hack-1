#ifndef NATHALIB
#define NATHALIB
#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <TlHelp32.h>
#include <stdio.h>
using namespace std;

int FindProcessByName(char name[]);
bool ReadProcessInteger(HANDLE pid, LPCVOID address, int &result);
bool WriteProcessInteger(HANDLE pid, LPCVOID address, int &result);
string ReadProcessString(HANDLE pid, LPCVOID address, int characters_to_read);

#endif
