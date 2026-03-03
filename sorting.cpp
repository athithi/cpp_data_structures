//PROBLEM STATEMENT:Calculate Water Footprints for different Agricultural Products
#include <iostream>
using namespace std;
#define MAX 10

class Footprint {
private:
	struct WaterFacility {
		string name;
		string brand;
		string place;
		int waterconsumption;
		string watersource;
	} arr[MAX];

	int n;

public:
	void getData();
	void bubblesortsort();
	void insertionsort();
	void quicksortsort();
	void quickSort(int low, int high);
	int partition(int low, int high);
	void mergesortsort();
	void merge(int l, int m, int r);
	void mergeSort(int l, int r);
	void display();
};

void Footprint::getData() {
	cout << "Enter the number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter details  " << i + 1 << ":\n";
		cout << "Name: ";
		cin >> arr[i].name;
		cout << "Brand: ";
		cin >> arr[i].brand;
		cout << "Place: ";
		cin >> arr[i].place;
		cout << "Water Consumption (in liters): ";
		cin >> arr[i].waterconsumption;
		cout << "Water Source: ";
		cin >> arr[i].watersource;
	}
}

void Footprint::bubblesortsort() {
	WaterFacility temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j].waterconsumption > arr[j + 1].waterconsumption) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Footprint::insertionsort() {
	for (int i = 1; i < n; i++) {
		WaterFacility key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j].waterconsumption > key.waterconsumption) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void Footprint::quicksortsort() {
	quickSort(0, n - 1);
}

void Footprint::quickSort(int low, int high) {
	if (low < high) {
		int pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

int Footprint::partition(int low, int high) {
	int pivot = arr[high].waterconsumption;
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j].waterconsumption < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void Footprint::mergesortsort() {
	mergeSort(0, n - 1);
}

void Footprint::mergeSort(int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}

void Footprint::merge(int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	WaterFacility L[n1], R[n2];

	for (int i = 0; i < n1; i++) L[i] = arr[l + i];
	for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i].waterconsumption <= R[j].waterconsumption) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void Footprint::display() {
	cout << "\nList of Water Facilities:\n";
	for (int i = 0; i < n; i++) {
		cout << "Name: " << arr[i].name << ", Brand: " << arr[i].brand
		     << ", Place: " << arr[i].place << ", Water Consumption: "
		     << arr[i].waterconsumption << " liters, Water Source: "
		     << arr[i].watersource << endl;
	}
}

int main() {
	Footprint footprint;
	int choice;

	do {

		cout << "\nMenu:\n";
		cout << "1. Add Data\n";
		cout << "2. Display Data\n";
		cout << "3. Bubble Sort\n";
		cout << "4. Insertion Sort\n";
		cout << "5. Quick Sort\n";
		cout << "6. Merge Sort\n";
		cout << "7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			footprint.getData();
			break;
		case 2:
			footprint.display();
			break;

		case 3:
			footprint.bubblesortsort();
			cout << "\nSorted list (Bubble Sort):\n";
			footprint.display();
			break;
		case 4:
			footprint.insertionsort();
			cout << "\nSorted list (Insertion Sort):\n";
			footprint.display();
			break;
		case 5:
			footprint.quicksortsort();
			cout << "\nSorted list (Quick Sort):\n";
			footprint.display();
			break;
		case 6:
			footprint.mergesortsort();
			cout << "\nSorted list (Merge Sort):\n";
			footprint.display();
			break;

		case 7:
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice! Try again.\n";
		}
	} while (choice != 7);

	return 0;
}
