#include <iostream>

using namespace std;

const int ARRAY_SIZE = 20;

// Updated Node referring to code from lab 22
struct Node {
	string customerName;
	string order;
	Node* prev;
	Node* next;
	Node(string c, string o, Node* p = nullptr, Node* n = nullptr) {
		customerName = c;
		order = o;
		prev = p;
		next = n;
	}
};

// Updated arrays that have more items, generated using ChatGPT:
const string names[ARRAY_SIZE] = {
	"Alex", "Jordan", "Taylor", "Morgan", "Riley", "Casey", "Avery", "Quinn", "Parker", "Reese",
	"Dakota", "Skyler", "Emerson", "Rowan", "Hayden", "Blake", "Sawyer", "Finley", "Harper", "Logan"
};

const string coffeeOrders[ARRAY_SIZE] = {
	"Latte", "Cappuccino", "Americano", "Mocha", "Espresso", "Flat White", "Cold Brew", "Macchiato",
	"Iced Latte", "Caramel Frappuccino", "Vanilla Latte", "Hazelnut Mocha", "Cortado", "Affogato", "Irish Coffee",
	"Pumpkin Spice Latte", "Matcha Latte", "Iced Americano", "Double Espresso", "Honey Almond Cold Brew"
};

// getRandomIndex() generates a random number within the range 0 to ARRAY_SIZE
// arguments: none
// returns: an int value representing an index
int getRandomIndex();

int main() {
	/* MILESTONE 1 (Coffee Booth pt 1)
	 * Create a node struct for a linked list with string name and string drink order as the data in each node
	 * Use LLM for creating data set of data arrays w/ names and drink orders
	 */
	// Temporarily using 3 while testing
	srand(3);
	// The head node of the linked list representing the coffee booth queue
	Node *coffeeBoothQueueHead = nullptr;
	coffeeBoothQueueHead = new Node;

	// Add first customer


	/* MILESTONE 2 (Coffee Booth pt 2)
	 * Run simulation for 10 rounds and initialize queue w/ 3 customers
	 * In any round:
	 * 50% chance someone joins queue
	 * Customer at the head of the queue is ALWAYS served in each round
	 * If the queue is empty:
	 * no customer is served, but 50% chance someone joins still remains
	 */

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

	return 0;
}

int getRandomIndex() {
	return rand() % ARRAY_SIZE;
}