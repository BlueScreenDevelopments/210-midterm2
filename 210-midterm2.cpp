//Brandon Julao
//COMSC-210-5481
// 10/17/2024
// Midterm #2

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
class DoublyLinkedList{
private:
	Node* head;
	Node* tail;

public:
	DoublyLinkedList() { head = nullptr; tail = nullptr; {}

	//Add a customer to the end of the line.
	void push_back(const string & name) {
		Node* newNode = new Node(name);
		if (!tail) {
			head = tail = newNode;
		}
		else {
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

	//									//
	// Old Code Below, Delete as Needed //
	//									//
	
	
	void print() {
		Node* current = head;
		if (!current) {
			cout << "List is empty." << endl;
			return;
		}
		while (current) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void print_reverse() {
		Node* current = tail;
		if (!current) {
			cout << "List is empty." << endl;
			return;
		}
		while (current) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}
};
int main() {
	cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid
	compiler warning
		return 0;
}
