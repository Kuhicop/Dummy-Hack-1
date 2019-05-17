#pragma once
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include "Nathalib.h"
using namespace std;

int main()
{
  While(True)
  {    
    cout << FindProcessByName("Calculator") << endl;
    getchar();
    cout << "-----------------------------------" << endl << endl;
  }
  return 0;
}
