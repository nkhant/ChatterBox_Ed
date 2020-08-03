#include "learner.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	The following function will look for the passed phrase in the memory file. 
	If there is a match, the accompany reponse will be stored below the initial phrase,
	will be outputed
	If the reponse cannot be found the Learner will repeat the phrase and prompt 
	the user to enter an ideal reponse. This reponse will be stored in the memory
	file along with the initial phrase.
*/
void Learner::respond(string phrase) {
	fstream memory;
	memory.open("Memory/memory.txt", ios::in); // Open the memory file for input

	// Search through the file until the end is reached  
	// Maybe I can alter so that the files are organize
	while (!memory.eof() ) { //while not at end of file
		string identifier;
		getline(memory, identifier); // Get next phrase

		if (identifier == phrase) { // Is it the phrase we are looking for
			string response;
			getline(memory, response); // If so, get the response
			voice.say(response); // Textually annd audibly output the reponse!
			return; // Leave the function
		}
	}

	memory.close(); // Looks like we couldn't find the phrase in the memory. Close the file!
	memory.open("memory/memory.txt", ios::out | ios::app); // Now open for output and append at end of file
	memory << phrase << endl; //Record inital phrase in memory

	voice.say("I don't know what to say. What do you think I should do?"); // Repeat the phrase the user entered
	string userResponse;
	cout << "You:";
	//voice.say("Thanks. I will note that down");
	getline(cin, userResponse); // Get the Ideal Reponse
	memory << userResponse << endl; // Write the ideal response to memory
	memory.close(); // Close the file!
}

/*
	This function simply communicates a phrase textually and audibly
*/
void Learner::say(string phrase) {
	this->voice.say(phrase);
}