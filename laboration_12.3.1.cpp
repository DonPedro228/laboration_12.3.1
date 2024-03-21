#include <iostream>
using namespace std;


typedef int Info;
struct Elem
{
	Elem* next,
		* prev;
	Info info;
};


void enqueue(Elem*& first, Elem*& last, Info value);
void print(Elem* first);
void reverse(Elem*& first);

int main() {
	Elem* first_1 = NULL,
		* last_1 = NULL;
	Info input;

	cout << "Input -1 for break: " << endl;
	while (true) {
		cin >> input;
		if (input == -1)
			break;
		enqueue(first_1, last_1, input);
	}

	print(first_1);
	reverse(first_1);
	print(first_1);


	return 0;
}

void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; 
	tmp->info = value; 
	tmp->next = NULL; 
	if (last != NULL)
		last->next = tmp; 
	tmp->prev = last; 
	last = tmp; 
	if (first == NULL)
		first = tmp; 
}

void print(Elem* first) {
	Elem* current = first;
	while (current != nullptr) {
		cout << current->info << " ";
		current = current->next;
	}
	cout << endl;
}

void reverse(Elem*& first) {
	Elem* prev = nullptr;
	Elem* current = first;
	Elem* next = nullptr;

	while (current != nullptr) {
		next = current->next;  
		current->next = prev; 
		prev = current;       
		current = next;        
	}

	first = prev; 
}