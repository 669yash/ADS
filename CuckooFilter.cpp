

// Write a program in C++ to implement the following probabilistic data structures Cuckoo Filter.

#include <iostream>
using namespace std;

class CuckooFilter {
public:
    string hashtable[50][2];
    int table_size;
    int buckets;

    CuckooFilter(int s, int b) {
        table_size = s;
        buckets = b;
        for (int i = 0; i < table_size; i++) {
            for (int j = 0; j < buckets; j++) {
                hashtable[i][j] = "";
            }
        }
    }

    int hash_function1(string s) {
        int hashvalue = 0;
        for (unsigned int i = 0; i < s.length(); i++) {
            hashvalue = hashvalue + (int)s[i];
        }
        hashvalue = hashvalue % table_size;
        return hashvalue;
    }

    int hash_function2(string s) {
        int hashvalue = 0;
        for (unsigned int i = 0; i < s.length(); i++) {
            hashvalue = hashvalue + ((int)s[i] * 7);
        }
        hashvalue = hashvalue % table_size;
        return hashvalue;
    }

    void store_data_in_filter(string s) {
        int hv1 = hash_function1(s);
        int hv2 = hash_function2(s);

        if (hashtable[hv1][0] == s || hashtable[hv2][0] == s) {
            cout << "\nThe data is already present in the hash table at location " << (hashtable[hv1][0] == s ? hv1 : hv2) << endl;
            return;
        }

        if (hashtable[hv1][0] == "") {
            hashtable[hv1][0] = s;
            cout << "\nInserted the key : " << s << " in hash table at location " << hv1 << endl;
        } else if (hashtable[hv2][0] == "") {
            hashtable[hv2][0] = s;
            cout << "\nInserted the key : " << s << " in hash table at location " << hv2 << endl;
        } else {
            cout << "\nUnable to insert " << s << ". Hash table is full." << endl;
            return;
        }

        display_table();
    }

    void display_table() {
        cout << "\nIndex   Table1   Table2" << endl;
        for (int i = 0; i < table_size; i++) {
            cout << " " << i << "       ";
            for (int j = 0; j < buckets; j++) {
                cout << hashtable[i][j] << "       ";
            }
            cout << endl;
        }
    }
};

int main() {
    CuckooFilter cf(10, 2);
    int ch;
    string s;
    do {
        cout << "\n Enter the data to be stored : ";
        cin >> s;
        cf.store_data_in_filter(s);
        cout << "\nDo you want to enter other data? (1 for Yes, 0 for No): ";
        cin >> ch;
    } while (ch != 0);
    return 0;
}

/* Output:
 Enter the data to be stored : 12

Inserted the key : 12 in hash table at location 9

Index   Table1   Table2
 0
 1
 2
 3
 4
 5
 6
 7
 8
 9       12

Do you want to enter other data? (1 for Yes, 0 for No): 1

 Enter the data to be stored : 34

Inserted the key : 34 in hash table at location 3

Index   Table1   Table2
 0
 1
 2
 3       34
 4
 5
 6
 7
 8
 9       12

Do you want to enter other data? (1 for Yes, 0 for No): 1

 Enter the data to be stored : 67

Unable to insert 67. Hash table is full.

Do you want to enter other data? (1 for Yes, 0 for No): 1

 Enter the data to be stored : 45

Inserted the key : 45 in hash table at location 5

Index   Table1   Table2
 0
 1
 2
 3       34
 4
 5       45
 6
 7
 8
 9       12

Do you want to enter other data? (1 for Yes, 0 for No): 1

 Enter the data to be stored : 89

Inserted the key : 89 in hash table at location 1

Index   Table1   Table2
 0
 1       89
 2
 3       34
 4
 5       45
 6
 7
 8
 9       12

Do you want to enter other data? (1 for Yes, 0 for No): 1

 Enter the data to be stored : 78

Inserted the key : 78 in hash table at location 7

Index   Table1   Table2
 0
 1       89
 2
 3       34
 4
 5       45
 6
 7       78
 8
 9       12

Do you want to enter other data? (1 for Yes, 0 for No): 1

 Enter the data to be stored : 06

Inserted the key : 06 in hash table at location 2

Index   Table1   Table2
 0
 1       89
 2       06
 3       34
 4
 5       45
 6
 7       78
 8
 9       12

Do you want to enter other data? (1 for Yes, 0 for No): 1

 Enter the data to be stored : 9

Unable to insert 9. Hash table is full.

*/
