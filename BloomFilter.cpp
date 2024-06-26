
// Write a program in C++ to implement the following probabilistic data structures Bloom's Filter.

#include<bits/stdc++.h>
#define MAXN 11
#define ver 2

int hashtable[ver][MAXN];
int pos[ver];

class bloom {
public:
    void initTable() {
        for (int j=0; j<MAXN; j++)
            for (int i=0; i<ver; i++)
                hashtable[i][j] = INT_MIN;
    }

    int hash(int function, int key) {
        switch (function) {
            case 1: return key%MAXN;
            case 2: return (key/MAXN)%MAXN;
        }
    }

    void place(int key, int tableID, int cnt, int n) {
        if (cnt==n) {
            printf("%d unpositioned\n", key);
            printf("Cycle present. REHASH.\n");
            return;
        }

        for (int i=0; i<ver; i++) {
            pos[i] = hash(i+1, key);
            if (hashtable[i][pos[i]] == key)
                return;
        }

        if (hashtable[tableID][pos[tableID]] != INT_MIN) {
            int dis = hashtable[tableID][pos[tableID]];
            hashtable[tableID][pos[tableID]] = key;
            place(dis, (tableID+1)%ver, cnt+1, n);
        } else {
            hashtable[tableID][pos[tableID]] = key;
        }
    }

    void printTable() {
        printf("Final hash tables:\n");
        for (int i=0; i<ver; i++, printf("\n"))
            for (int j=0; j<MAXN; j++)
                (hashtable[i][j] == INT_MIN) ? printf("- ") : printf("%d ", hashtable[i][j]);
        printf("\n");
    }

    void bloom_filter(int keys[], int n) {
        initTable();
        for (int i=0, cnt=0; i<n; i++, cnt=0)
            place(keys[i], 0, cnt, n);
        printTable();
    }
};

int main() {
    bloom b;
    int keys_1[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
    int n = sizeof(keys_1) / sizeof(int);
    b.bloom_filter(keys_1, n);

    int keys_2[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6};
    int m = sizeof(keys_2) / sizeof(int);
    b.bloom_filter(keys_2, m);

    return 0;
}
/*
Output:
Final hash tables:
- 100 - 36 - - 50 - - 75 -
3 20 - 39 53 - 67 - - 105 -

105 unpositioned
Cycle present. REHASH.
Final hash tables:
- 67 - 3 - - 39 - - 53 -
6 20 - 36 50 - 75 - - 100 -
*/




