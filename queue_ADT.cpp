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
	} a[max];
	int front;
	int rear;
public:
	Footprint() {
		front=-1;
		rear=-1;
	}
	void ENQUEUE(string, string, string, int, string);
	void display();
	void DEQUEUE();
	void isempty();
	void isfull();
	void empty();
};
int main(){
  Footprint a;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. enqueue\n";
        cout << "2. display\n";
        cout << "3. dequeue\n";
        cout << "4. isempty\n";
        cout << "5. isfull\n";
        cout << "6. empty\n";
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
        case 3:{
        	a.DEQUEUE();
					break;
				}
				case 4:{
					a.isempty();
					break;
				}
				case 5:{
					a.isfull();
					break;
				}
				case 6:{
					a.empty();
					break;
				}
				default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}

void Footprint::ENQUEUE(string nn, string pl, string br, int wc, string ws){
	if(rear==max-1) {
		cout<<"\nSorry queue overflow; can't insert";
		return;
	}
	if(front==-1)
	   ++front;
	++rear;
	a[rear].name=nn;
	a[rear].place=pl;
	a[rear].brand=br;
	a[rear].waterconsumption=wc;
	a[rear].watersource=ws;
}
void Footprint::display() {
	if(front==-1) {
		cout<<"\nSorry queue Underflow; can't print";
		return;
	}
	cout<<"Name\tBrand\tPlace\twaterconsumption\twatersource\n";
	for(int j=front; j<=rear; j++){
		 cout << a[j].name << "\t";
     cout << a[j].brand << "\t";
     cout << a[j].place << "\t";
     cout << a[j].waterconsumption << "\t\t";
     cout << a[j].watersource << "\t\n";
   }
}
void Footprint::DEQUEUE() {
       if(front==-1){
        cout<<"\nSorry queue Underflow; can't print";
        return;
    }
    int x=a[front].waterconsumption;
    ++front;
    if(front==rear+1)
        front=rear=-1;
    return;
}

void Footprint::isfull(){
	if(rear==max-1) {
		cout<<"\nthe list is full";
		return;
	}
	else
	  cout<<"the list is not full yet";
}
void Footprint::isempty(){
	if(front==-1) {
		cout<<"\nthe list is empty";
		return;
	}
	else
	  cout<<"the list is not empty";
	  return;
}
void Footprint::empty(){
	front=-1;
	return;
}
