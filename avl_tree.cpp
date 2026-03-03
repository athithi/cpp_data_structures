//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include<iostream>
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
		struct node* left;
		struct node* right;
		int height;
	} *root,*temp;
	node* createnode(string nn, string b, string pl, int c, string s);
	node* insert(node*,string,string,string,int,string);
	void preorder(node *);
	void postorder(node *);
	void inorder(node *);
	node* maximum(node *);
	node* minimum(node *);
	node* Deleted(node*,string,string,string,int,string);
	struct node* SRR(struct node *);
	struct node* SRL(struct node *);
	int height (struct node *);
	int maxi(int, int);
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
	int minimum();
	void Deleted(string,string,string,int,string);
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
	int balance;
	if(T==NULL)
		T=createnode(nn,b,pl,c,s);
	else if(c>T->waterconsumption)
		T->right=insert(T->right,nn,b,pl,c,s);
	else if(c<T->waterconsumption)
		T->left=insert(T->left,nn,b,pl,c,s);
	T->height=1+maxi (height(T->left),height(T->right));
	balance = height(T->left)-height(T->right);
	if(balance > 1 && c < T->left->waterconsumption)
		return SRR(T);
	else if (balance < -1 && c >T->right->waterconsumption)
		return SRL(T);
	else if(balance > 1 && c > T->left->waterconsumption) {
		T->left = SRL(T->left);
		return SRR(T);
	}
	else if(balance < -1 && c < T->right->waterconsumption) {
		T->right = SRR(T->right);
		return SRL(T);
	}
	return T;
}

void Footprint::insert(string nn, string b, string pl, int c, string s) {
	root=insert(root,nn,b,pl,c,s);
}

void Footprint::preorder(node *T) {
	if(T!=NULL) {
		cout<<T->name<<"\t\t"<<T->brand<<"\t\t"<<T->place<<"\t\t"<<T->waterconsumption<<"\t\t\t\t"<<T->watersource<<" \n";
		preorder(T->left);
		preorder(T->right);
	}
}

void Footprint::postorder(node *T) {
	if(T!=NULL) {
		postorder(T->left);
		postorder(T->right);
		cout<<T->name<<"\t\t"<<T->brand<<"\t\t"<<T->place<<"\t\t"<<T->waterconsumption<<"\t\t\t\t"<<T->watersource<<" \n";
	}
}

void Footprint::inorder(node *T) {
	if(T!=NULL) {
		inorder(T->left);
		cout<<T->name<<"\t\t"<<T->brand<<"\t\t"<<T->place<<"\t\t"<<T->waterconsumption<<"\t\t\t\t"<<T->watersource<<" \n";
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

int Footprint::height (struct node *T) {
	if (T==NULL)
		return 0;
	return (T->height);
}
int Footprint::maxi(int a, int b) {
	return (a>b)?a:b;
}
Footprint::node* Footprint::SRR(struct node *y) {
	struct node * x = y ->left;
	struct node *T2 = x->right;
	x->right=y;
	y->left=T2;
	x->height = 1+maxi(height(x->right),height(x->left));
	y->height = 1+maxi(height(y->right),height(y->left));
	return x;
}
Footprint::node* Footprint::SRL(struct node *x) {
	struct node * y = x -> right;
	struct node *T2 = y->left;
	y->left=x;
	x->right=T2;
	x->height = 1+maxi(height(x->right),height(x->left));
	y->height = 1+maxi(height(y->right),height(y->left));
	return y;
}
Footprint::node* Footprint::maximum(node* T) {
	while(T->right!=NULL)
		T=T->right;
	cout<<T->name<<"\t\t"<<T->brand<<"\t\t"<<T->place<<"\t\t"<<T->waterconsumption<<"\t\t\t\t"<<T->watersource<<" \n";
	preorder(T->left);
	return T;
}

Footprint::node* Footprint::minimum(node* T) {
	while(T->left!=NULL)
		T=T->left;
	cout<<T->name<<"\t\t"<<T->brand<<"\t\t"<<T->place<<"\t\t\t"<<T->waterconsumption<<"\t\t\t\t"<<T->watersource<<" \n";
	preorder(T->left);
	return T;
}

int Footprint::maximum() {
	return(maximum(root)->waterconsumption);
}

int Footprint::minimum() {
	return(minimum(root)->waterconsumption);
}
void Footprint::Deleted(string nn, string b, string pl, int c, string s) {
	root=Deleted(root,nn,b,pl,c,s);

}
Footprint::node* Footprint::Deleted(node *T, string nn, string b, string pl, int c, string s) {
	if (T==NULL)
		return T;
	else if(c>T->waterconsumption)
		T->right=Deleted(T->right,nn,b,pl,c,s);
	else if(c<T->waterconsumption)
		T->left=Deleted(T->left,nn,b,pl,c,s);
	else {
		if(T->left ==NULL && T->right ==NULL) {
			T=NULL;
			delete T;
		}

		else if(T->left==NULL ) {
			temp=T;
			T=T->right;
			delete temp;
		}

		else if(T->right==NULL ) {
			temp=T;
			T=T->left;
			delete temp;
		}
		else {
			temp=minimum(T->right);
			T->waterconsumption=temp->waterconsumption;
			T->right=Deleted(T->right,nn,b,pl,c,s);
		}
	}
	if (T == NULL)
		return T;
	T->height = 1 + maxi(height(T->left), height(T->right));
	int balance = height(T->left) - height(T->right);
	if (balance > 1 && height(T->left->left) >= height(T->left->right))
		return SRR(T);
	if (balance > 1 && height(T->left->left) < height(T->left->right)) {
		T->left = SRL(T->left);
		return SRR(T);
	}
	if (balance < -1 && height(T->right->right) >= height(T->right->left))
		return SRL(T);
	if (balance < -1 && height(T->right->right) < height(T->right->left)) {
		T->right = SRR(T->right);
		return SRL(T);
	}
	return T;
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
		cout << "7.delete\n";
		cout << "8. Exit\n";
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
			a.Deleted(name, brand, place, waterconsumption, watersource);
		}
		case 8: {
			cout << "Exit...\n";
			break;
		}
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 8);
	return 0;
}
