//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products 
#include <iostream>
#include <string>
using namespace std;
#define max 100

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
    void insert(string, string, string, int, string);
    void display();
    void search(string);
    void modify(string, string);
    void delete_data(string);
    void delete_all();
    Footprint() {
        top = -1;
    }
};

void Footprint::insert(string nn, string b, string pl, int c, string s) {
    if (top == max - 1) {
        cout << "\nSorry List is full; can't insert";
        return;
    }
    ++top;
    x[top].name = nn;
    x[top].brand = b;
    x[top].place = pl;
    x[top].waterconsumption = c;
    x[top].watersource = s;
}

void Footprint::display() {
    if (top == -1) {
        cout << "\nSorry List is empty; can't print";
        return;
    }
    cout<<"Name\tBrand\tPlace\twaterconsumption\twatersource\n";
    for (int i = 0; i <= top; i++) {
        cout << x[i].name << "\t";
        cout << x[i].brand << "\t";
        cout << x[i].place << "\t";
        cout << x[i].waterconsumption << "\t\t";
        cout << x[i].watersource << "\t\n";
    }
}

void Footprint::delete_data(string d) {
    if (top == -1) {
        cout << "\n Sorry the list is empty";
        return;
    }
    for (int i = 0; i <= top; i++) {
        if (x[i].name == d) {
            while (i < top) {
                x[i] = x[i + 1];
                ++i;
            }
        }
    }
    --top;
}

void Footprint::modify(string oldvalue, string newvalue) {
    int n;
    if (top == -1) {
        cout << "\nList is empty";
        return;
    }
    cout<<"Name\tBrand\tPlace\twaterconsumption\twatersource\n";
    for (int i = 0; i <= top; i++) {
        if (x[i].name == oldvalue) {
            x[i].name = newvalue;
            cout << x[i].name << "\t";
            cout << x[i].brand << "\t";
            cout << x[i].place << "\t\t";
            cout << x[i].watersource << "\t\n";
            return;
        }
    }
    cout << "\nValue not found";
}

void Footprint::search(string names) {
    if (top == -1) {
        cout << "\nList is empty";
        return;
    }
    cout<<"Name\tBrand\tPlace\twaterconsumption\twatersource\n";
    for (int i = 0; i <= top; i++) {
        if (x[i].name == names) {
            cout << x[i].name << "\t";
            cout << x[i].brand << "\t";
            cout << x[i].place << "\t";
            cout << x[i].waterconsumption << "\t\t";
            cout << x[i].watersource << "\t\n";
            return;
        }
    }
}


void Footprint::delete_all() {
    if (top == -1) {
        cout << "List is already empty\n";
        return;
    }
    top = -1;
    cout << "\nThe list has been clear";
}

int main() {
    Footprint a;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Modify\n";
        cout << "5. Delete\n";
        cout << "6. Delete All\n";
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
            a.insert(name, brand, place, waterconsumption, watersource);
            break;
        }
        case 2: {
            a.display();
            break;
        }
        case 3: {
            string names;
            cout << "Enter product name to search: ";
            cin >> names;
            a.search(names);
            break;
        }
        case 4: {
            string oldvalue, newvalue;
            cout << "Enter name to modify: ";
            cin >> oldvalue;
            cout << "Enter new name: ";
            cin >> newvalue;
            a.modify(oldvalue, newvalue);
            break;
        }
        case 5: {
            string j;
            cout << "Enter name to be deleted: ";
            cin >> j;
            a.delete_data(j);
            break;
        }
       
        case 6: {
            a.delete_all();
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
