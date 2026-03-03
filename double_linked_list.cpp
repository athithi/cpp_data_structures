//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include<iostream>
using namespace std;
class DoubleList {
private:
	struct node {
		string name;
		string brand;
		string place;
		int waterconsumption;
		string watersource;
		struct node *next;
		struct node *prev;
	}*head,*p,*temp,*tail;
public:
	DoubleList() {
		head=NULL;
		tail=NULL;
		p=NULL;
		temp=NULL;
	}
	void insert(string,string,string,int,string);
	void displayforward();
	void displayreverse();
	void deletedata(string);
};
int main() {
	DoubleList a;
	int choice;
	do {
		cout<<"\nMenu:\n";
		cout<<"\n 1.insert";
		cout<<"\n 2.Forward display";
		cout<<"\n 3.Reverse display";
		cout<<"\n 4.delete";
		cout<<"\n 5.Exit";
		cout<<"\nEnter your choice: \n";
		cin>>choice;

		switch(choice) {
		case 1: {
			string name,brand,place,watersource;
			int waterconsumption;
			cout<<"Enter product name: ";
			cin>>name;
			cout<<"Enter brand: ";
			cin>>brand;
			cout<<"Enter place: ";
			cin>>place;
			cout<<"Enter total waterconsumption: ";
			cin>>waterconsumption;
			cout<<"Enter water source: ";
			cin>>watersource;
			a.insert(name,brand,place,waterconsumption,watersource);
			break;
		}
		case 2: {
			a.displayforward();
			break;
		}
		case 3: {
			a.displayreverse();
			break;
		}
		case 4: {
			string names;
			cout<<"enter name to be deleted:";
			cin>>names;
			a.deletedata(names);
			break;
		}
		case 5: {
			cout<<"Exit...\n";
			break;
		}
		default:
			cout<<"Invalid choice. Please try again.\n";
		}
	} while(choice!=4);
	return 0;
}
void DoubleList::insert(string n,string b,string p,int w,string s) {
	temp = new struct node;
	temp->name=n;
	temp->brand=b;
	temp->place=p;
	temp->waterconsumption=w;
	temp->watersource=s;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL) {
		head = temp;
		tail=temp;
	}
	else {
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}
void DoubleList::displayforward() {
	if(head==NULL) {
		cout<<"\nSorry the list is empty";
		return;
	}
	p=head;
	cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
	while(p!=NULL) {
		cout<<p->name<<"\t"<<p->brand<<"\t"<<p->place<<"\t"<<p->waterconsumption<< "%\t\t\t"<<p->watersource<<"\n";;
		p=p->next;
	}
}
void DoubleList::displayreverse() {
	if(head==NULL) {
		cout<<"\nSorry the list is empty";
		return;
	}
	p=tail;
	cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
	while(p!=NULL) {
		cout<<p->name<<"\t"<<p->brand<<"\t"<<p->place<<"\t"<<p->waterconsumption<< "%\t\t\t"<<p->watersource<<"\n";;
		p=p->prev;
	}
}
void DoubleList::deletedata(string names) {
	if(head==NULL) {
		cout<<"\nSorry the list is empty";
		return;
	}
	p=head;
	while(p->name!=names) {
		temp=p;
		p=p->next;
	}
	temp->next=p->next;
	p->next->prev=temp;
	delete p;
	p=head;
	cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
	while(p!=NULL) {
		cout<<p->name<<"\t"<<p->brand<<"\t"<<p->place<<"\t"<<p->waterconsumption<< "%\t\t\t"<<p->watersource<<"\n";;
		p=p->next;
	}
}
