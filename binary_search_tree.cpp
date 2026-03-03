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
		struct node* left;
		struct node* right;
	} *root,*temp;
	node* createnode(string nn, string b, string pl, int c, string s);
	node* insert(node*,string,string,string,int,string);
	void preorder(node *);
	void postorder(node *);
	void inorder(node *);
	node* maximum(node *);
	node* Delete(node*, int);
	node* minimum(node *);
	node* Search(node*,int);
public:
	Footprint() {
		root=NULL;
		temp=NULL;
	}
	void insert(string,string,string,int,string);
	void preorder();
	void postorder();
	void inorder();
	int maximum();
	void Delete(int);
	int minimum();
	void Search(int);
};

Footprint::node* Footprint::createnode(string nn, string b, string pl, int c, string s) {
	temp=new node;
	temp->name = nn;
	temp->brand = b;
	temp->place = pl;
	temp->waterconsumption = c;
	temp->watersource = s;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Footprint::node* Footprint::insert(node *T, string nn, string b, string pl, int c, string s) {
	if(T==NULL)
		T=createnode(nn,b,pl,c,s);
	else if(c>T->waterconsumption)
		T->right=insert(T->right,nn,b,pl,c,s);
	else if(c<T->waterconsumption)
		T->left=insert(T->left,nn,b,pl,c,s);
	return T;
}

void Footprint::insert(string nn, string b, string pl, int c, string s) {
	root=insert(root,nn,b,pl,c,s);
}
Footprint::node* Footprint::Delete(struct node* T, int d) {
	if (T == NULL)
		return T;

	if (d > T->waterconsumption) {
		T->right = Delete(T->right, d);
	} else if (d < T->waterconsumption) {
		T->left = Delete(T->left, d);
	} else {
		if (T->left == NULL && T->right == NULL) {
			delete T;
			return NULL;
		}

		else if (T->left == NULL) {
			temp = T;
			T = T->right;
			delete temp;
		}

		else if (T->right == NULL) {
			temp = T;
			T = T->left;
			delete temp;
		}

		else {
			temp = minimum(T->right);
			T->waterconsumption = temp->waterconsumption;
			T->right = Delete(T->right, temp->waterconsumption);
		}
	}
	return T;
}
void Footprint::Delete(int d) {
	root = Delete(root,d);
}
void Footprint::preorder(node *T) {
	if(T!=NULL) {
		cout<<T->name<<"\t"<<T->brand<<"\t"<<T->place<<"\t"<<T->waterconsumption<<"\t\t"<<T->watersource<<" \n";
		preorder(T->left);
		preorder(T->right);
	}
}

void Footprint::postorder(node *T) {
	if(T!=NULL) {
		postorder(T->left);
		postorder(T->right);
		cout<<T->name<<"\t"<<T->brand<<"\t"<<T->place<<"\t"<<T->waterconsumption<<"\t\t"<<T->watersource<<" \n";
	}
}

void Footprint::inorder(node *T) {
	if(T!=NULL) {
		inorder(T->left);
		cout<<T->name<<"\t"<<T->brand<<"\t"<<T->place<<"\t"<<T->waterconsumption<<"\t\t"<<T->watersource<<" \n";
		inorder(T->right);
	}
}

void Footprint::preorder() {
	preorder(root);
}

void Footprint::postorder() {
	postorder(root);
}

void Footprint::inorder() {
	inorder(root);
}

Footprint::node* Footprint::maximum(node* T) {
	while(T->right!=NULL)
		T=T->right;
	cout<<T->name<<"\t"<<T->brand<<"\t"<<T->place<<"\t"<<T->waterconsumption<<"\t\t"<<T->watersource<<" \n";
	preorder(T->left);
	return T;
}
Footprint::node* Footprint::Search(node *T,int e) {
	struct node* result= Search(root,e);
	if(result) {
		cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
		cout<<T->name<<"\t"<<T->brand<<"\t"<<T->place<<"\t"<<T->waterconsumption<<"\t\t"<<T->watersource<<" \n";
	}
	else {
		cout<<"Not found"<<endl;
	}
	return T;
}
Footprint::node* Footprint::minimum(node* T) {
	while(T->left!=NULL)
		T=T->left;
	cout<<T->name<<"\t"<<T->brand<<"\t"<<T->place<<"\t"<<T->waterconsumption<<"\t\t"<<T->watersource<<" \n";
	preorder(T->left);
	return T;
}

int Footprint::maximum() {
	return(maximum(root)->waterconsumption);
}

int Footprint::minimum() {
	return(minimum(root)->waterconsumption);
}
int main() {
	Footprint a;
	int choice;
	do {
		cout << "\nMenu:\n";
		cout << "1. insert\n";
		cout << "2. preorder\n";
		cout << "3. postorder\n";
		cout << "4. inorder\n";
		cout << "5. maximum\n";
		cout << "6. minimum\n";
		cout << "7. delete\n";
		cout << "8.Search\n";
		cout << "9.Exit\n";
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
			a.insert(name, brand, place, waterconsumption, watersource);
			break;
		}
		case 2: {
			cout<<"preorder:\n";
			cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
			a. preorder();
			break;
		}

		case 3: {
			cout<<"postorder:\n";
			cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
			a.postorder();
			break;
		}
		case 4: {
			cout<<"inorder:\n";
			cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
			a.inorder();
			break;
		}
		case 5: {
			cout<<"the maximum value is\n";
			cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
			a.maximum();
			break;
		}
		case 6: {
			cout<<"the minimun value is\n";
			cout<<"name"<<"\t"<<"brand"<<"\t"<<"place"<<"\t"<<"waterconsumption"<<"\t"<<"watersource"<<"\t\n";
			a.minimum();
			break;
		}
		case 7: {
			int d;
			cout<<"enter value to be deleted";
			cin>>d;
			a.Delete(d);
		}
		case 8: {
			int e;
			cout<<"enter value to search:";
			cin>>e;
			a.Search(e);
		}
		case 9: {
			cout << "Exit...\n";
			break;
		}
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 9);
	return 0;
}
