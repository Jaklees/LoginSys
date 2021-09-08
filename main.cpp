#include <iostream>
#include <fstream>
#include <string>
#include <map>

// I want to create a login system... there will be a file that is read and editted where a line saves the username and password
// 1) First, option comes up asking if user wants to login or register
// 2) If user chooses login, then it will prompt for username and then for password and will check this by searching for the username and checking to see if that password matches provided
// 3) say "Invalid Information given, attempt 1 of 3" then give options a,b,c: a) retry? b) register? c) forgot password?
// 4) OR user chooses to register which will then prompt them to enter a username and then a password as well as confirming there password
// if confirmed pass and pass arent same, give error and then a) try again? b) quit

int main() {
	std::string user, password, u1, p1, p2,temp; // user = username on file, password = pass on file
	// u1 = inputted username, p1 = inputted password, p2 = confirmed password
	std::fstream fs;
	fs.open("login.txt", std::ios::out | std::ios::in | std::ios::app);

	std::cout << "Hello, welcome to LogX" << std::endl;
	std::cout << "Would you like to a) Login or b) Register?" << std::endl;
	std::cout << "Please enter a or b for option selection" << std::endl;
	std::getline(std::cin, temp);

	if (temp == "a") {
		std::cout << "You selected login" << std::endl;
		std::cout << "Please enter your username" << std::endl;
		std::getline(std::cin, u1);

		std::cout << "Please enter your password" << std::endl;
		std::getline(std::cin, p1);

		std::string hold;
		std::map<std::string, std::string> userpass;
		std::map<std::string, std::string>::iterator it;
		while (std::getline(fs, hold)) {
			userpass.insert(std::make_pair(hold.substr(0, hold.find(';')), hold.substr(hold.find(';') + 1)));
			hold.clear();
		}
		if (userpass.find(u1) != userpass.end()) {

		}
	}

	return 0;
}