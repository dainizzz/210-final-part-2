#include <iostream>

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
	// MILESTONE 1 (Coffee Booth pt 1)
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

	//printCoffeeShopQueue(coffeeBoothHead);



	/* MILESTONE 2 (Coffee Booth pt 2)
	 * Run simulation for 10 rounds and initialize queue w/ 3 customers
	 * In any round:
	 * 50% chance someone joins queue
	 * Customer at the head of the queue is ALWAYS served in each round
	 * If the queue is empty:
	 * no customer is served, but 50% chance someone joins still remains
	 */
	for (int i = 0; i < SIMULATION_ROUNDS; i++) {
		if (coffeeBoothHead) {
			cout << coffeeBoothHead->customerName << endl;
		}

		int probability = rand() % 101 + 1;
		if (probability >= 50 ) {
			string name = NAMES[getRandomIndex()];
			string order = COFFEE_ORDERS[getRandomIndex()];
			cout << name << " ordered a " << order << endl;
		}
	}

	/* MILESTONE 3 (Muffin Booth)
	 * Add code simulating the queue of a muffin booth using a deque, and incorporate this new booth into the
	 * simulation while keeping the probabilities the same
	 */

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
