
#include <iostream>
using namespace std;

void insert_withreplacement(int n) {
    int arr1[n];
    int arr2[n];
    bool flag[n]; // To keep track of occupied positions
    int orig_index[n]; // To store the original index of elements in the hash table

    for (int i = 0; i < n; i++) {
        flag[i] = false;
        arr2[i] = -1;
        orig_index[i] = -1;
    }

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++) {
        int key = arr1[i];
        int index = key % n;

        if (arr2[index] == -1) {
            arr2[index] = key;
            flag[index] = true;
            orig_index[index] = index;
        } else if (orig_index[index] == index) { // If the current element is at its original position
            int j = (index + 1) % n;
            while (j != index && arr2[j] != -1) {
                j = (j + 1) % n;
            }
            if (j == index) {
                cout << "Hash table is full" << endl;
                return;
            }
            arr2[j] = key;
            flag[j] = true;
            orig_index[j] = index;
        } else { // Replace and move the old element
            int temp = arr2[index];
            int temp_orig = orig_index[index];
            arr2[index] = key;
            orig_index[index] = index;

            int j = (index + 1) % n;
            while (j != index && arr2[j] != -1) {
                j = (j + 1) % n;
            }
            if (j == index) {
                cout << "Hash table is full" << endl;
                return;
            }
            arr2[j] = temp;
            flag[j] = true;
            orig_index[j] = temp_orig;
        }
    }

    cout << "Hashing table is: " << endl;
    for (int j = 0; j < n; j++) {
        cout << arr2[j] << " ";
    }
    cout << endl;
}

int main() {
    int choice = 1, ch;
    do {
        cout << "Hashing" << endl;
        cout << "1. Linear probing with replacement" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int n1;
                cout << "Enter the max length of hashing table: ";
                cin >> n1;
                insert_withreplacement(n1);
                break;
            }
            default:
                cout << "Invalid choice" << endl;
        }
        cout << "Press 1 to continue: ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}


/*
Output:
Hashing
1. Linear probing with replacement
Enter your choice: 1
Enter the max length of hashing table: 6
Enter the elements:
34
67
36
12
97
45
Hashing table is:
36 67 12 45 34 97
Press 1 to continue:
*/


