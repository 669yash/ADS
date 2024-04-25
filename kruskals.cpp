#include<iostream>
using namespace std;

class disjointSet{
	public:
    int djSet[20];
    disjointSet(int v){
        for(int i = 0; i < v; i++){
        djSet[i] = i;
    }
    }

    int findRoot(int v){
        while(v != djSet[v]){
            v = djSet[v];
        }
        return v;
    }

    void unionTwo(int v1, int v2){
        int r1 = findRoot(v1);
        int r2 = findRoot(v2);

        if(v1 == r1 && v2 == r2){
            djSet[v1] = v2;
        }
        else if(v1 != r1 && v2 == r2){
        djSet[v2] = v1;
        }
		else if(v1 == r1 && v2 != r2){
        djSet[v1] = v2;
        }
		else{
        djSet[r1] = r2;
        }
    }
};

class edge{
    public:
    int v1;
    int v2;
    int wt;
};

class graph{
    public:
    int v;
    int e;
    edge ed[20];

    graph(int vertices, int edges){
        v = vertices;
        e = edges;
    }

    void acceptGraph();
    void displayGraph();
    void sortEdges();
    void kruskal_mst();
};

void graph :: acceptGraph(){
    for(int i = 0; i < e; i++){
    cout << "\nEnter vertex v1: ";
    cin >> ed[i].v1;
    cout <<"\nEnter vertex v2: ";
    cin >> ed[i].v2;
    cout << "\nEnter weight of the edge: ";
    cin >> ed[i].wt;
    }
}

void graph :: displayGraph(){
    for(int i = 0; i < e; i++){
    cout << "\n " << ed[i].v1 << " " << ed[i].v2 << " " << ed[i].wt;
    }
}

void graph :: sortEdges(){
    edge temp;
    for(int i = 0; i < e; i++){
        for(int j = 0; j < e-i; j++){
            if(ed[j].wt > ed[j + 1].wt){
            temp.v1 = ed[j].v1;
            temp.v2 = ed[j].v2;
            temp.wt = ed[j].wt;
            ed[j].v1 = ed[j + 1].v1;
            ed[j].v2 = ed[j + 1].v2;
            ed[j].wt = ed[j + 1].wt;
            ed[j + 1].v1 = temp.v1;
            ed[j + 1].v2 = temp.v2;
            ed[j + 1].wt = temp.wt;
            }
        }
    }
}

void graph :: kruskal_mst(){
    edge mst[20];
    int mst_ctr = 0;
    int mst_cost = 0;
    disjointSet dj(v);
    sortEdges();
    cout << "\nEdge after Sorting ";
    displayGraph();
    cout << "\n ";
    for(int i = 0; i < e; i++){
        int r1 = dj.findRoot(ed[i].v1);
        int r2 = dj.findRoot(ed[i].v2);
        if(r1 != r2){
            mst[mst_ctr].v1 = ed[i].v1;
            mst[mst_ctr].v2 = ed[i].v2;
            mst[mst_ctr].wt = ed[i].wt;

            mst_ctr++;
            mst_cost = mst_cost + ed[i].wt;

            dj.unionTwo(ed[i].v1, ed[i].v2);
        }
    }

    cout << "\nMST of given graph: ";
    for(int i = 0; i < mst_ctr; i++){
        cout << " \n " << mst[i].v1 << " " << mst[i].v2 << " " << mst[i].wt;
    }
    cout << "Total cost of path: " << mst_cost;
}  


int main(){
	int v, e;
    cout << "\nEnter total no. of vertices: ";
    cin >> v;
    cout << "\nEnter total no. of edges: ";
    cin >> e;
    graph g(v, e);
    g.acceptGraph();
    g.displayGraph();
    g.kruskal_mst();
    
	return 0;
}
