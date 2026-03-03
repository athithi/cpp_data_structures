//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Footprint {
private:
	struct node {
		string name;
		string brand;
		string place;
		int waterconsumption;
		string watersource;
		struct node* parent;
		int rank;
	};
	struct node* s[MAX];

public:
	Footprint();
	void MakeSet(struct node*, string, string, string, int, string);
	void Makeset(int, string, string, string, int, string);
	struct node* Find(struct node*);
	void Union(struct node*, struct node*);
	void Link(struct node*, struct node*);
	struct node* getnode(int);
};

Footprint::Footprint() {
	for (int i = 0; i < MAX; i++)
		s[i] = nullptr;
}

void Footprint::MakeSet(struct node* x, string nn, string b, string pl, int c, string ws) {
	x->name = nn;
	x->brand = b;
	x->place = pl;
	x->waterconsumption = c;
	x->watersource = ws;
	x->rank = 0;
	x->parent = x;
}

void Footprint::Makeset(int i, string nn, string b, string pl, int c, string ws) {
	s[i] = new node;
	MakeSet(s[i], nn, b, pl, c, ws);
}

Footprint::node* Footprint::Find(struct node* x) {
	if (x != x->parent)
		x->parent = Find(x->parent);
	return x->parent;
}

void Footprint::Union(struct node* x, struct node* y) {
	Link(Find(x), Find(y));
}

void Footprint::Link(struct node* x, struct node* y) {
	if (x->rank > y->rank)
		y->parent = x;
	else {
		x->parent = y;
		if (x->rank == y->rank)
			y->rank++;
	}
}

Footprint::node* Footprint::getnode(int index) {
	return s[index];
}

int main() {
	Footprint ds;
	int choice, index1, index2;
	string name, brand, place, source;
	int waterConsumption;

	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Create a set\n";
		cout << "2. Union two sets\n";
		cout << "3. Find a set\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter index (0-9): ";
			cin >> index1;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter brand: ";
			cin >> brand;
			cout << "Enter place: ";
			cin >> place;
			cout << "Enter water consumption: ";
			cin >> waterConsumption;
			cout << "Enter water source: ";
			cin >> source;
			ds.Makeset(index1, name, brand, place, waterConsumption, source);
			cout << "Set created at index " << index1 << ".\n";
			break;

		case 2:
			cout << "Enter index of first set: ";
			cin >> index1;
			cout << "Enter index of second set: ";
			cin >> index2;
			ds.Union(ds.getnode(index1), ds.getnode(index2));
			cout << "Union performed on sets at indices " << index1 << " and " << index2 << ".\n";
			break;

		case 3:
			cout << "Enter index of set to find: ";
			cin >> index1;
			cout << "The name of the set at index " << index1 << " is: ";
			cout<< ds.Find(ds.getnode(index1))->name << "\n";
			break;

		case 4:
			cout << "Exiting program.\n";
			return 0;

		default:
			cout << "Invalid choice. Please try again.\n";
		}
	}

	return 0;
}
