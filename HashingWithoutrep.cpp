#include <iostream>
using namespace std;

void insert_withoutreplacement(int n) {
    int arr1[n];
    int arr2[n];
    int flag[n];

    for (int i = 0; i < n; i++) {
        flag[i] = 0;
    }

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++) {
        arr2[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int a = arr1[i] % n;

        if (arr2[a] == -1) {
            arr2[a] = arr1[i];
            flag[a] = 1;
        } else {
            int c = a + 1;
            int flag1 = 0;
            while (c != a && flag1 == 0) {
                if (flag[c] == 0 && c < n) {
                    arr2[c] = arr1[i];
                    flag[c] = 1;
                    flag1 = 1;
                    break;
                } else {
                    if (c == n) {
                        c = 0;
                    } else {
                        c++;
                    }
                }
            }
        }
    }

    cout << "Hashing table is: ";
    cout << endl;
    for (int j = 0; j < n; j++) {
        cout << arr2[j] << " ";
    }
    cout << endl;
}

int main() {
    int choice = 1, ch;
    do {
        cout << "Hashing" << endl;
        cout << "1. Linear probing without replacement" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int n1;
                cout << "Enter the max length of hashing table: ";
                cin >> n1;
                insert_withoutreplacement(n1);
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
