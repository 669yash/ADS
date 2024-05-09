#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999
#define V 10

int main()
{
    int no_edge;
    int cost_path = 0;
    int G[V][V];
    int selected[V];
    no_edge = 0;
    int i, j;
    cout << "Enter value of the total number of vertices: ";
    int V1;
    cin >> V1;
    for (i = 0; i < V1; i++)
    {
        for (j = i; j < V1; j++)
        {
            if (i == j)
            {
                G[i][j] = INF;
            }
            else
            {
                cout << "\nEnter the weight from " << i << " to " << j << " - ";
                cin >> G[i][j];
                if (G[i][j] == 0)
                {
                    G[i][j] = INF;
                }
                G[j][i] = G[i][j];
            }
        }
        selected[0] = true;
    }
    for (int i = 0; i < V1; i++)
    {
        for (int j = 0; j < V1; j++)
        {
            cout << G[i][j] << "  ";
        }
        cout << endl;
    }
    int x;
    int y;
    cout << "Edge"<< " : "<< "weight";
    cout << endl;
    int min = INF;
    x = 0;
    y = 0;
    for (i = 0; i < V1; i++){
        selected[i] = false;
    }
    selected[0] = true;
    no_edge = 0;
    while (no_edge < V1 - 1)
    {
        min = 9999;
        for (i = 0; i < V1; i++)
        {
            if (selected[i] == true)
            {
                for (j = 0; j < V1; j++)
                {
                    if (selected[j] == false)
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = true;
        cout << "\n" << x << " --> " << y << " : " << G[x][y];
        cost_path = cost_path + G[x][y];
        no_edge = no_edge + 1;
    }
    cout << "\nMinimum cost of path: " << cost_path;

    return 0;
}

/*Output:
Enter value of the total number of vertices: 5

Enter the weight from 0 to 1 - 5

Enter the weight from 0 to 2 - 3

Enter the weight from 0 to 3 - 8

Enter the weight from 0 to 4 - 1

Enter the weight from 1 to 2 - 0

Enter the weight from 1 to 3 - 5

Enter the weight from 1 to 4 - 4

Enter the weight from 2 to 3 - 3

Enter the weight from 2 to 4 - 8

Enter the weight from 3 to 4 - 4
9999  5  3  8  1
5  9999  9999  5  4
3  9999  9999  3  8
8  5  3  9999  4
1  4  8  4  9999
Edge : weight

0 --> 4 : 1
0 --> 2 : 3
2 --> 3 : 3
4 --> 1 : 4
Minimum cost of path: 11
*/
