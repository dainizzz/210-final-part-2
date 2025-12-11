#include <iostream>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

const int ARRAY_SIZE = 20;
const int SIMULATION_ROUNDS = 10;

struct Node {
	string customerName;
	string order;
	Node *next;
};

// Updated arrays that have more items, generated using ChatGPT:
const string NAMES[ARRAY_SIZE] = {
	"Alex", "Jordan", "Taylor", "Morgan", "Riley", "Casey", "Avery", "Quinn", "Parker", "Reese",
	"Dakota", "Skyler", "Emerson", "Rowan", "Hayden", "Blake", "Sawyer", "Finley", "Harper", "Logan"
};

const string COFFEE_ORDERS[ARRAY_SIZE] = {
	"Latte", "Cappuccino", "Americano", "Mocha", "Espresso", "Flat White", "Cold Brew", "Macchiato",
	"Iced Latte", "Caramel Frappuccino", "Vanilla Latte", "Hazelnut Mocha", "Cortado", "Affogato", "Irish Coffee",
	"Pumpkin Spice Latte", "Matcha Latte", "Iced Americano", "Double Espresso", "Honey Almond Cold Brew"
};

// getRandomIndex() generates a random number within the range 0 to ARRAY_SIZE
// arguments: none
// returns: an int value representing an index
int getRandomIndex();

void printCoffeeShopQueue(Node *);

int main() {
	srand(time(0));

	// Add first customer
	Node *coffeeBoothHead = new Node;
	coffeeBoothHead->customerName = NAMES[getRandomIndex()];
	coffeeBoothHead->order = COFFEE_ORDERS[getRandomIndex()];

	// Add second customer
	coffeeBoothHead->next = new Node;
	coffeeBoothHead->next->customerName = NAMES[getRandomIndex()];
	coffeeBoothHead->next->order = COFFEE_ORDERS[getRandomIndex()];

	// Add third customer
	coffeeBoothHead->next->next = new Node;
	coffeeBoothHead->next->next->customerName = NAMES[getRandomIndex()];
	coffeeBoothHead->next->next->order = COFFEE_ORDERS[getRandomIndex()];

	// MUFFIN BOOTH
	deque<string> muffinQueue;
	// Add initial customer
	muffinQueue.push_back(NAMES[getRandomIndex()]);

	// FRIENDSHIP BRACELET BOOTH
	vector<string> braceletQueue;
	// Add initial customer
	braceletQueue.push_back(NAMES[getRandomIndex()]);

	for (int i = 0; i < SIMULATION_ROUNDS; i++) {
		cout << "ROUND " << i+1 << endl;
		int probability = rand() % 101 + 1;

		// // COFFEE BOOTH
		// if (coffeeBoothHead) {
		// 	Node *temp = coffeeBoothHead;
		// 	coffeeBoothHead = coffeeBoothHead->next;
		// 	cout << temp->customerName << "'s order of " << temp->order << " was ready." << endl;
		// 	delete temp;
		// }
		//
		// if (probability >= 50 ) {
		// 	string name = NAMES[getRandomIndex()];
		// 	string order = COFFEE_ORDERS[getRandomIndex()];
		// 	cout << name << " ordered a " << order << '.' << endl;
		// 	Node *temp = coffeeBoothHead;
		// 	while (temp) {
		// 		if (temp->next == nullptr)
		// 			break;
		// 		temp = temp->next;
		// 	}
		// 	temp = new Node;
		// 	temp->customerName = NAMES[getRandomIndex()];
		// 	temp->order = COFFEE_ORDERS[getRandomIndex()];
		// 	delete temp;
		// }

		// MUFFIN BOOTH
		if (!muffinQueue.empty()) {
			cout << "Customer " << muffinQueue.front() << " was served at the muffin booth." << endl;
			muffinQueue.pop_front();
		} else
			cout << "The muffin booth line is empty." << endl;

		if (probability >= 50) {
			muffinQueue.push_back(NAMES[getRandomIndex()]);
			cout << "Customer " << muffinQueue.back() << " joined the line at the muffin booth." << endl;
		}

		// BRACELET BOOTH
		if (!braceletQueue.empty()) {
			cout <<
		}

	}

	/* MILESTONE 4 (Friendship Bracelets)
	 * Add code simulating a friendship bracelet vendor using a vector
	 */

	/* MILESTONE 5
	 * Add another vendor showing use of a different data structure not yet used in this program selling something
	 * you choose
	 */

	/* MILESTONE 6
	 * Make sure each round shows all 4 booths' activities
	 */

	while (coffeeBoothHead) {
		Node *cur = coffeeBoothHead;
		coffeeBoothHead = cur->next;
		delete cur;
	}

	return 0;
}

int getRandomIndex() {
	return rand() % ARRAY_SIZE;
}

// Modified version of function from Lab 22
void printCoffeeShopQueue(Node *head) {
	Node *current = head;
	if (!current) return;
	while (current) {
		cout << current->customerName << ": " << current->order << endl;
		current = current->next;
	}
	cout << endl;
}
