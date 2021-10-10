#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <set>

int main() {

	// Welcome text
	std::cout << "Welcome to our game of guess the number correct! " << std::endl;
	std::cout << "I picked number between 1-100. Now its your turn" << std::endl;


	// random number generation
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist100(1,100);

	int rnd_number = dist100(rng);
	int count = 0;


	// loop to get the input from user to find the number
	while (true) {
		count++;
		int guessed_number;

		std::cout << "Guess the number!: ";
		std::cin >> guessed_number;

		if (guessed_number>rnd_number) {
			std::cout << "You are too much! Decrase" << std::endl;
		}
		else {
			if (guessed_number<rnd_number) {
				std::cout << "You are short! Increase" << std::endl;

			}
			else {
				std::cout << "You hit the bullseye brother congrats" << std::endl;
				break;
			}

		}

	}

	// Info text
	std::cout << "It took you " <<  count << " times trying for you!" << std::endl;

	// Lets add the last score to the database
	std::ofstream myfile_write("scores-database.txt", std::ios_base::app);
	if (myfile_write.is_open()) {
		myfile_write << count << "\n";
		myfile_write.close();
	}
	else {
		std::cout << "Unable to reach the database file" << std::endl;
	}

	// Read the dabase file
	std::set<std::string> scores;
	std::string line;
	std::ifstream myfile_read("scores-database.txt");
	if (myfile_read.is_open()) {
		while (std::getline (myfile_read,line)) 
			scores.insert(line);
	}
	else {
		std::cout <<  "Unable to reach the database file" << std::endl;
	}

	// Print the scores
	std::cout << "Your previous scores: " << std::endl;

	for (auto elem : scores) {
		std::cout << elem << std::endl;
	}

	std::cout << "Thanks for playing the game!" << std::endl;

}