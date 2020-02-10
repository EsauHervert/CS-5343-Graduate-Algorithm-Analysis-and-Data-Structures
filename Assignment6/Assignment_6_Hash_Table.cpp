#include "Hash_Functions.h"

using namespace std;

int main() {
	// Initialise the Hash Table and make it to be size 19.
	Hash Words;
	Words.Change_Size(19);

	// Add the following words.
	Words.add("It");
	Words.add("Would");
	Words.add("Be");
	Words.add("Nice");
	Words.add("If");
	Words.add("You");
	Words.add("Give");
	Words.add("Me");
	Words.add("An");
	Words.add("A");

	// Print the current table.
	Words.Print();

	// Find the following words.
	Words.find("Nice");
	Words.find("Me");
	Words.find("Triangle");

	// Now let us add more words but here we pass the load threshold.
	Words.add("In");
	Words.add("This");
	Words.add("Class");

	// Print the final table.
	Words.Print();

	// Find these following words in the final table.
	Words.find("In");
	Words.find("Nice");
	Words.find("Me");
	Words.find("Banana");
}