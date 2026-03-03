//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include<iostream>
#define max 10
using namespace std;
class Footprint {
private:
	struct node {
		string name;
		string brand;
		string place;
		int waterconsumption;
		string watersource;
		struct node *next;
	} *front,*rear,*p,*temp;
public:
	Footprint() {
		front=NULL;
		rear=NULL;
		p=NULL;
		temp=NULL;
	}
	void ENQUEUE(string,string,string,int,string);
	void display();
	void DEQUEUE();
	void isempty();
	void empty();
};

int main() {
	Footprint a;
	int choice;
	do {
		cout << "\nMenu:\n";
		cout << "1. ENQUEUE\n";
		cout << "2. Display\n";
		cout << "3. DEQUEUE\n";
		cout << "4. isempty\n";
		cout << "5. empty\n";
		cout << "\nEnter your choice: \n";
		cin >> choice;
		cout << "\n";
		switch (choice) {
		case 1: {
			string name, brand, place, watersource;
			int waterconsumption;
			cout << "Enter product name: ";
			cin >> name;
			cout << "Enter brand: ";
			cin >> brand;
			cout << "Enter place: ";
			cin >> place;
			cout << "Enter total waterconsumption: ";
			cin >> waterconsumption;
			cout << "Enter water source: ";
			cin >> watersource;
			a.ENQUEUE(name, brand, place, waterconsumption, watersource);
			break;
		}
		case 2: {
			a.display();
			break;
		}

		case 3: {
			a.DEQUEUE();
			break;
		}
		case 4: {
			a.isempty();
			break;
		}
		case 5: {
			a.empty();
			break;
		}
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 7);
	return 0;
}
void Footprint::ENQUEUE(string nn, string b, string pl, int c, string s) {
	temp=new struct node;
	temp->name=nn;
	temp->brand=b;
	temp->place=pl;
	temp->waterconsumption=c;
	temp->watersource=s;
	temp->next=NULL;
	if(front==NULL) {
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}
void Footprint::display() {
	if(front==NULL) {
		cout<<"\nSorry Queue is empty; can't print";
		return;
	}
	p=front;
	cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t\t\t\t"<<"watersource"<<"\t\n";
	while(p!=NULL) {
		cout << p->name << "\t";
		cout << p->brand << "\t";
		cout << p->place << "\t";
		cout << p->waterconsumption << "\t";
		cout << p->watersource << "\n";
		p=p->next;
	}
}
void Footprint::DEQUEUE() {
	if (front == NULL) {
		cout << "\nSorry Queue is empty; can't print";
		return;
	}
	cout<<"the contents deleted \t";
	temp = front;
	p=temp;
	front = front->next;
	cout << p->name << "\t";
	cout << p->brand << "\t";
	cout << p->place << "\t";
	cout << p->waterconsumption << "\t";
	cout << p->watersource << "\n";
	delete temp;
}

void Footprint::isempty() {
	if(front==-1) {
		cout<<"\nthe list is empty";
		return;
	}
	else
		cout<<"the list is not empty";
	return;
}
void Footprint::empty() {
	front=-1;
	return;
}
