#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

// 1) First, option comes up asking if user wants to login or register
// 2) If user chooses login, then it will prompt for username and then for password and will check this by searching for the username and checking to see if that password matches provided
// 3) say "Invalid Information given, attempt 1 of 3" then give options a,b,c: a) retry? b) register? c) forgot password?
// 4) OR user chooses to register which will then prompt them to enter a username and then a password as well as confirming there password
// if confirmed pass and pass arent same, give error and then a) try again? b) quit

int main() {
	std::string user, password, u1, p1, p2,temp;
	std::string hold = " ";

	// user = username on file, password = pass on file
	// u1 = inputted username, p1 = inputted password, p2 = confirmed password
	std::fstream fs;
	fs.open("loginSys.txt", std::ios::app);

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

		while (std::getline(fs, hold)) {
			std::stringstream ss(hold);
			ss >> user >> password;

			if (u1 == user && p1 == password) {
				std::cout << "Login Successful" << std::endl;
				exit(0);
			}
		}
		std::cout << "Invalid Username or Password... Exiting" << std::endl;
	}
	else {
		std::cout << "You selected to create an account" << std::endl;
		std::cout << "Please enter desired username" << std::endl;
		std::cin >> u1;
		
		while (std::getline(fs, hold)) {
			std::stringstream ss(hold);
			ss >> user >> password;
			if (u1 == user) {
				std::cout << "Username is already in user... Exiting" << std::endl;
				exit(0);
			}
			else {
				std::cout << "Username accepted" << std::endl;
				break;
			}
		}
		std::cout << "Please enter desired password" << std::endl;
		std::cin >> p1;
		fs << u1 << p1 << std::endl;
		std::cout << "Account created" << std::endl;
	}
	fs.close();
	return 0;
}
