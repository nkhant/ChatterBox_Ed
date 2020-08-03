#include "Voice.h"
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

/*
	The following function textually and audibly communcates a phrase.
	The open source eSpeak speech synthesizer is used to create the audible message.
	If the eSpeak.exe is no Locaed in the director, no audible message will be heard.
*/

void Voice::say(string phrase) {
	string command = "espeak \"" + phrase + "\""; // Concat the phrase to the command
	const char* charCommand = command.c_str(); // Conver to a const char*
	cout << phrase << endl; // Textually outpit phrase
	system(charCommand); // Send the command to cmd to execute espeak with the phrase and argument
}