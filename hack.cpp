#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "Nathalib.h"
using namespace std;

char process_name[] = "Calculator.exe";

int main()
{
  while(true)
  {    
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
		
    getchar();
    cout << "-----------------------------------" << endl << endl;
  }
  return 0;
}
