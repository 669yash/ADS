#include<iostream>

using namespace std;

class CountMinSketch
{
public:
    int d;
    int w;
    int** matrix;

    CountMinSketch(int d_, int w_) : d(d_), w(w_)
    {
        matrix = new int*[d];
        for (int i = 0; i < d; ++i)
        {
            matrix[i] = new int[w];
            for (int j = 0; j < w; ++j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    int hash(int idx, string s)
    {
        int hash_val = 0;
        for (unsigned int i = 0; i < s.length(); ++i)
        {
            char c = s[i];
            hash_val = (hash_val * 31 + c) % w;
        }
        return (hash_val + idx) % w;
    }

    void increment(string s)
    {
        for (int i = 0; i < d; ++i)
        {
            int idx = hash(i, s);
            matrix[i][idx]++;
        }
    }

    int min(int a, int b)
    {
        return (a < b) ? a : b;
    }

    int getCount(string s)
    {
        int min_count = matrix[0][hash(0, s)];
        for (int i = 1; i < d; ++i)
        {
            int idx = hash(i, s);
            min_count = min(min_count, matrix[i][idx]);
        }
        return min_count;
    }
};

int main()
{
    int d = 4;
    int w = 10;

    CountMinSketch sketch(d, w);

    string s;
    char ch;
    do
    {
        cout << "Enter the data: ";
        cin >> s;

        sketch.increment(s);

        cout << "\nsketch matrix: " << endl;
        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cout << sketch.matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nDo you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
