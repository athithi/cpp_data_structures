//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include <iostream>
#include <string>
#define TABLE_SIZE 10
using namespace std;

class Footprint {
private:
	struct Node {
		string name;
		string brand;
		string place;
		int waterconsumption;
		string watersource;
		Node* next;
	}* table[TABLE_SIZE];
public:
	Footprint() {
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL; 
	}
	Node* createNode(string nn, string b, string pl, int c, string ws);
	int hash(int key);
	void insert(int key, string nn, string b, string pl, int c, string ws);
	void display();
	void Delete(int key);
	Node* find(int key);
};
Footprint::Node* Footprint:: createNode(string nn, string b, string pl, int c, string ws) {
	Node* newNode = new Node;
	newNode->name=nn;
	newNode->brand=b;
	newNode->place=pl;
	newNode->waterconsumption=c;
	newNode->watersource=ws;
	newNode->next = NULL;
	return newNode;
}
int Footprint::hash(int key) {
	return key % TABLE_SIZE;
}

void Footprint::insert(int key,string nn, string b, string pl, int c, string ws) {
	int index = hash(key);
	Node* newNode = createNode(nn,b,pl,c,ws); 
	newNode->next = table[index]; 
	table[index] = newNode;
}

void Footprint::display() {
	cout << "\nIndex\tName\tBrand\tPlace\tWater Consumption\tWater Source";
	for (int i = 0; i < TABLE_SIZE; i++) {
		cout << "\n" << i << "\t";
		Node* temp = table[i];
		if (temp == NULL)
			cout << "X"; 
		else {
			while (temp != NULL) {
				cout<<temp->name<<"\t"<<temp->brand<<"\t"<<temp->place<<"\t"<<temp->waterconsumption<< "%\t\t\t"<<temp->watersource<<"\n"<<"\t";
				temp = temp->next;
			}
			cout << "X"; 
		}
	}
	cout << "\n";
}
Footprint::Node* Footprint::find(int key) {
	int index = hash(key);
	Node* temp = table[index];
	while (temp != NULL && temp->waterconsumption != key)
		temp = temp->next;
	return temp; 
}
void Footprint::Delete(int key) {
	int index = hash(key);
	Node* temp = table[index];
	Node* prev = NULL;
	while (temp != NULL && temp->waterconsumption != key) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		cout << "\nElement not found in the hash table.";
		return;
	}
	if (prev == NULL) 
		table[index] = temp->next;
	else
		prev->next = temp->next;
	delete temp; 
}

int main() {
	Footprint ht;
	int choice, key, waterConsumption;
	string name, brand, place, waterSource;

	do {
		cout << "\nMenu:";
		cout << "\n1. Insert Entry";
		cout << "\n2. Display Hash Table";
		cout << "\n3. Delete Entry";
		cout << "\n4. Find Entry";
		cout << "\n5. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter key (water consumption): ";
			cin >> waterConsumption;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter brand: ";
			cin >> brand;
			cout << "Enter place: ";
			cin >> place;
			cout << "Enter water source: ";
			cin >> waterSource;
			ht.insert(waterConsumption, name, brand, place, waterConsumption, waterSource);
			break;

		case 2:
			cout << "\nHash Table Contents:";
			ht.display();
			break;

		case 3:
			cout << "Enter key (water consumption) to delete: ";
			cin >> key;
			ht.Delete(key);
			break;

		case 4:
			cout << "Enter key (water consumption) to find: ";
			cin >> key;
			cout << "The data with key " << key << " is found at index: " << ht.find(key);
			break;

		case 5:
			cout << "Exiting the program.";
			break;

		default:
			cout << "Invalid choice. Please try again.";
			break;
		}
	} while (choice != 5);

	return 0;
}
