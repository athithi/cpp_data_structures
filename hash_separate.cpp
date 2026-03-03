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
	} table[TABLE_SIZE];

public:
	Footprint();
	int hash(int);
	void insert(int, string, string, string, int, string);
	void display();
	void Delete(int);
	int find(int);
};


Footprint::Footprint() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i].waterconsumption = -1;
	}
}


int Footprint::hash(int key) {
	return key % TABLE_SIZE;
}


void Footprint::insert(int key, string nn, string b, string pl, int c, string ws) {
	int index = hash(key);
	int i = 0;
	while (table[(index + i) % TABLE_SIZE].waterconsumption != -1) {
		i++;
	}
	table[(index + i) % TABLE_SIZE].name = nn;
	table[(index + i) % TABLE_SIZE].brand = b;
	table[(index + i) % TABLE_SIZE].place = pl;
	table[(index + i) % TABLE_SIZE].waterconsumption = c;
	table[(index + i) % TABLE_SIZE].watersource = ws;
}


void Footprint::display() {
	cout << "\nIndex\tName\tBrand\tPlace\tWater Consumption\tWater Source";
	for (int i = 0; i < TABLE_SIZE; i++) {
		cout << "\n" << i << "\t";
		if (table[i].waterconsumption != -1) {
			cout << table[i].name << "\t" << table[i].brand << "\t" << table[i].place << "\t"
			     << table[i].waterconsumption << "\t" << table[i].watersource;
		} else {
			cout << "-";
		}
	}
	cout << "\n";
}


void Footprint::Delete(int key) {
	int index = find(key);
	if (index == -1) {
		cout << "\nElement not found in the hash table.";
		return;
	}
	table[index].waterconsumption = -1;
}


int Footprint::find(int key) {
	int index = hash(key);
	int i = 0;
	while (table[(index + i) % TABLE_SIZE].waterconsumption != -1) {
		if (table[(index + i) % TABLE_SIZE].waterconsumption == key)
			return (index + i) % TABLE_SIZE;
		i++;
	}
	return -1;
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
			if (ht.find(key) != -1) {
				cout << "The data with key " << key << " is found at index: " << ht.find(key);
			} else {
				cout << "The data with key " << key << " is not found.";
			}
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
