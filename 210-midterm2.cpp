//Brandon Julao
//COMSC-210-5481
//10/17/2024
//Midterm #2

//Including the necessary libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//Node Structure for the DoublyLinkedList
struct Node {
	string name;
	Node* prev;
	Node* next;
	Node(string val) : name(val), prev(nullptr), next(nullptr) {}
};

//DoublyLinkedList class to manage the line of customers
class DoublyLinkedList {
private:
	Node* head;
	Node* tail;

public:
	DoublyLinkedList() {
		head = nullptr; tail = nullptr;
	}

		//Add a customer to the end of the line.
		void push_back(const string & name) {
			Node* newNode = new Node(name);
			if (!tail) {
				head = tail = newNode;
			} else {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			cout << name << " joined the line." << endl;
		}

		//Serve the customer at the front of the line
		void serve_customer() {
			if (!head) return;
			cout << head->name << " is served." << endl;
			Node* temp = head;
			head = head->next;
			if (head) head->prev = nullptr;
			else tail = nullptr; // Line is now empty
			delete temp;
		}

		// Remove the last customer (frustrated)
		void remove_last() {
			if (!tail) return;
			cout << tail->name << " (at the rear) left the line." << endl;
			Node* temp = tail;
			tail = tail->prev;
			if (tail) tail->next = nullptr;
			else head = nullptr; // Line is now empty
			delete temp;
		}

		//Line Check (Empty?)
		bool is_empty() {
			return head == nullptr;
		}

		//Print to the user the current line
		void print_line() {
			Node* current = head;
			cout << "Resulting line: ";
			while (current) {
				cout << current->name << " ";
				current = current->next;
			}
			cout << endl;
		}

		~DoublyLinkedList() {
			while (head) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
	};

	//Read names from a file into a vector
	vector<string> read_names(const string& filename) {
		vector<string> names;
		ifstream file(filename);
		string name;
		while (getline(file, name)) {
			names.push_back(name);
		}
		return names;
	}

	// Main simulation function
	//Random Number Generator
	void simulate_coffee_shop(const vector<string>& names) {
		DoublyLinkedList line;
		srand(static_cast<unsigned int>(time(0)));

	//Initial customers when the store opens
		for (int i = 0; i < 5; ++i) {
			line.push_back(names[rand() % names.size()]);
		}
		line.print_line();

	//Run the simulation for 20 time periods
		for (int time_step = 1; time_step <= 20; ++time_step) {
			cout << "Time step #" << time_step << ":" << endl;

	// Probability checks
	//Random number in between 1 & 100
			int prob = rand() % 100 + 1;

	//Check if a customer is served (40% chance)
			if (!line.is_empty() && prob <= 40) {
				line.serve_customer();
			}

	//Check if a new customer joins (60% chance)
			if (prob <= 60) {
				line.push_back(names[rand() % names.size()]);
			}

	//Check if the last customer leaves (20% chance)
			if (!line.is_empty() && (rand() % 100 + 1) <= 20) {
				line.remove_last();
			}

	//Check if any particular customer leaves (10% chance)
			if (!line.is_empty() && (rand() % 100 + 1) <= 10) {
				line.remove_last();
			}

	//Check if a VIP customer joins (10% chance)
			if (prob <= 10) {
				string vip_name = names[rand() % names.size()] + " (VIP)";
				cout << vip_name << " joins the front of the line." << endl;
				line.push_back(vip_name);
			}

			// Print the current line
			line.print_line();
		}
	}



	int main() {
		vector<string> names = read_names("names.txt");
		simulate_coffee_shop(names);
		return 0;
	};