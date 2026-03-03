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
    } x[max];
    int top;
public:
    Footprint() {
        top=-1;
    }
    void push(string,string,string,int,string);
    void display();
    void POP();
    void peek();
    bool isEmpty();
    bool isFull();
};

void Footprint::push(string nn, string b, string pl, int c, string s) {
    if (top == max - 1) {
        cout << "\nSorry List is full; can't push";
        return;
    }
    ++top;
    x[top].name = nn;
    x[top].brand = b;
    x[top].place = pl;
    x[top].waterconsumption = c;
    x[top].watersource = s;
}

void Footprint::display(){
    if(top==-1){
        cout<<"\nSorry List is empty; can't print";
        return;
    }
    for(int i=top;i>=0;i--){
      cout<<x[i].name            <<"\t";
      cout<<x[i].brand           <<"\t";
      cout<<x[i].place           <<"\t";
      cout<<x[i].waterconsumption<<"\t\t\t";
      cout<<x[i].watersource     <<"\t\n";
    }
}

void Footprint::POP(){
    if(top==-1){
        cout<<"\nSorry Stack Underflow; can't pop";
        return;
    }
    cout << "Popped: " << x[top].name << ", " << x[top].brand << ", " 
         << x[top].place << ", " << x[top].waterconsumption << ", " 
         << x[top].watersource << endl;
    --top;  
}

int main() {
    Footprint a;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Display\n";
        cout << "3. POP\n";
        cout << "4. peek\n";
        cout << "5. isEmpty\n";
        cout << "6. isFull\n";
        cout << "7. Exit\n";
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
            a.push(name, brand, place, waterconsumption, watersource);
            break;
        }
        case 2: {
            cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
            a.display();
            break;
        }

        case 3: {
            a.POP();
            break;
        }
        case 4:{
            a.peek();
            break;
        }
        case 5:{
            a.isEmpty();
            break;
        }
        case 6:{
            a.isFull();
            break;
        }
        case 7: {
            cout << "Exit...\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}
void Footprint::peek(){
    if(top==-1){
        cout<<"stack empty";
        return ;
    }
    cout << "Top element: " << x[top].name << ", " << x[top].brand << ", " 
         << x[top].place << ", " << x[top].waterconsumption << ", " 
         << x[top].watersource << endl;
}

bool Footprint::isEmpty(){
    if(top==-1){
    	cout<< "yes,the list is empty";
	}
	else{
		cout<< "no,the list is not empty";
	}
}
bool Footprint::isFull(){
     if(top == max - 1){
    	cout<< "yes, the list is full";
	}
	else{
		cout<< "no, the list is not full";
	}
    
 
    
}
