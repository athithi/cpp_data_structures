//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include <iostream>
#include<malloc.h>
#define max 100
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
	}*head,*p,*temp,f[max];
public:
	Footprint() {
		head=NULL;
		p=NULL;
		temp=NULL;
	}
	void insert(string,string,string,int,string);
	void display();
	void search(string);
	void deletevalue(string);
	void modify(string,string);
};
int main() {
	Footprint a;
	int choice;
	do {
		cout<<"\nMenu:\n";
		cout<<"1. Insert\n";
		cout<<"2. Display\n";
		cout<<"3. Search\n";
		cout<<"4. Modify\n";
		cout<<"5. Delete\n";
		cout<<"6. Exit\n";
		cout<<"\nEnter your choice: \n";
		cin>>choice;
		cout<<"\n";
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
			a.display();
			break;
		}
		case 3: {
			string names;
			cout<<"Enter product name to search: ";
			cin>>names;
			a.search(names);
			break;
		}
		case 4: {
			string oldvalue,newvalue;
			cout<<"Enter name to modify: ";
			cin>>oldvalue;
			cout<<"Enter new name: ";
			cin>>newvalue;
			a.modify(oldvalue,newvalue);
			break;
		}
		case 5: {
			string j;
			cout<<"enter name to be deleted:";
			cin>>j;
			a.deletevalue(j);
			break;
		}
		case 6: {
			cout<<"Exit...\n";
			break;
		}
		default:
			cout<<"Invalid choice. Please try again.\n";
		}
	} while(choice!=6);
	return 0;
}
void Footprint::insert(string n,string b,string pl,int c,string s) {
	temp=new struct node;
	temp->name=n;
	temp->brand=b;
	temp->place=pl;
	temp->waterconsumption=c;
	temp->watersource=s;
	temp->next=NULL;
	if(head==NULL) {
		head=temp;
		return;
	}
	Footprint::node*p;
	p=head;

	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}
void Footprint::display() {
	if(head==NULL) {
		cout<<"\nSorry List is empty; can't print";
		return;
	}
	p=head;
	cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
	while(p!=NULL) {
		cout<<p->name<<"\t"<<p->brand<<"\t"<<p->place<<"\t"<<p->waterconsumption<< "%\t\t\t"<<p->watersource<<"\n";
		p=p->next;
	}
}
void Footprint::deletevalue(string j) {
	if (head==NULL) {
		cout<<"sorry list is empty";
		return;
	}
	p=head;
	cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
	while(p->name==j) {
		p=p->next;
		cout<<p->name<<"\t"<<p->brand<<"\t"<<p->place<<"\t"<<p->waterconsumption<< "%\t\t\t"<<p->watersource<<"\n";
		delete(p);
	}
	temp->next=p->next;
}

void Footprint::modify(string oldvalue,string newvalue) {
	if (head==NULL) {
		cout<<"sorry list is empty";
		return;
	}
	p=head;
	cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
	while(p!=NULL) {
		if(p->name==oldvalue) {
			p->name=newvalue;
			cout<<p->name<<"\t"<<p->brand<<"\t"<<p->place<<"\t"<<p->waterconsumption<< "%\t"<<p->watersource<<"\t\n";
		}
		p=p->next;

	}
}
void Footprint::search(string names) {
	if(head==NULL) {
		cout<<"\nSorry List is empty; can't print";
		return;
	}
	p=head;
	cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
	while(p->name==names) {
		cout<<p->name<<"\t"<<p->brand<<"\t"<<p->place<<"\t"<<p->waterconsumption<< "%\t\t\t"<<p->watersource<<"\t";
		p=p->next;
	}
}
