#include <iostream>
using namespace std;

void createlist(int data);
void beginning_add(int data);
void end_add(int data);
void beginning_del(int data);
void end_del(int data);
void display();

struct Node {
	int info;
	struct Node *link;
} *start; //will serve as the head

int main ()
{
	int choice, element, n, i;
	while (1) //loop for the menu until it is true
	{
		cout << "========================== \n";
		cout << "         M  E  N  U        \n";
		cout << "========================== \n\n";
		cout << "1. Create a list\n";
		cout << "2. Add node in the beginning\n";
		cout << "3. Add node in the end\n";
		cout << "4. Delete node in the beginning\n";
		cout << "5  Delete node in the end\n";
		cout << "6. Display\n";
		cout << "\nEnter your choice: ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				system ("cls");
				cout << "========================== \n";
				cout << "     CREATING A LIST       \n";
				cout << "========================== \n\n";
				cout << "How many nodes do you want to create?: ";
				cin >> n;
				for (i=0; i<n; i++) {
					cout << "Enter element " << i+1 << ": ";
					cin >> element; //user will enter his/her desired elements
					createlist(element);
				}
				break;
			case 2:
				system ("cls");
				cout << "========================== \n";
				cout << "   ADD BEGINNING NODE      \n";
				cout << "========================== \n\n";
				cout << "Add node in the beginning: ";
				cin >> element;
				beginning_add(element);
				break;
			case 3:
				system ("cls");
				cout << "========================== \n";
				cout << "      ADD ENDING NODE      \n";
				cout << "========================== \n\n";
				cout << "Add node at the end: ";
				cin >> element;
				end_add(element);
				break;
			case 4:
				system ("cls");
				cout << "========================== \n";
				cout << "      DELETE HEAD NODE     \n";
				cout << "========================== \n\n";
				beginning_del(element);
				break;
			case 5:
				system ("cls");
				cout << "========================== \n";
				cout << "     DELETE TAIL NODE      \n";
				cout << "========================== \n\n";
				end_del(element);
				break;
			case 6:
				display();
				break;
		}
	}
	return 0;
}

//function for creating a list
void createlist(int data) {
	struct Node *p, *tmp; //p will be the one we will move, tmp = temporary
	tmp = new Node; //where we set a memory allocation
	tmp->info = data; // to fetch the data
	tmp->link = NULL; //to set the link to null
	if (start == NULL)
		start = tmp;
	else {
		p = start;
		while (p->link != NULL)
			p = p->link;
		p->link = tmp;
	}
}

//function for adding node in the beginning
void beginning_add (int data) {
	struct Node *tmp;
	tmp = new Node;
	tmp-> info = data;
	if (start == NULL) {
		tmp->link = NULL;
	} else {
		tmp->link = start;
	}
	start = tmp;
}

//function for adding node at the end
void end_add (int data) {
	struct Node *p, *tmp;
	tmp = new Node;
	tmp->info = data;
	tmp->link = NULL;
	if (start == NULL)
		start = tmp;
	else {
		p = start;
		while (p->link != NULL)
			p = p->link;
		p->link = tmp;
	}
}

//function for deleting the head node
void beginning_del (int data) {
	struct Node *tmp, *p;
	tmp = new Node;
	tmp = start->link;
	delete start;
	start = tmp;
}

//function for deleting the tail node
void end_del (int data) {
	struct Node *tmp;
	tmp = start;
	if (start->link == NULL)
		delete start;
	//this will check the second last of the list
	while (tmp->link->link != NULL) {
		tmp = tmp->link;
	}
	delete tmp->link;
	tmp->link = NULL;
}

//function for displaying the list
void display() {
	struct Node *p;
	if (start == NULL) {
		cout << "It's empty!\n";
		return;
	}
	p = start;
	cout << "\nThe list: \n";
	while (p != NULL) {
		cout << p->info << endl;
		p = p->link;
	}
	cout << endl;
}



