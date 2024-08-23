#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<set> // set stores values in sorted manner
using namespace std;

template <typename T>
class undirected_graph{
    public:
    
    map <T, list<pair<T, int>>> adj;
    void addEdgeAdjList(T u, T v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<< " -> ";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<")"<<" ";
            }
            cout<<endl;
        }
    }

    vector<pair<pair<int, int>, int>> MST(){
        vector<int> key(adj.size()+1);
        vector<bool> MST(adj.size()+1);
        vector<T> parent(adj.size()+1);
        for(int i=0;i<key.size();i++){
            key[i] = INT_MAX;
            parent[i] = -1 ;
        }
        key[0]=0;
        parent[0] = -1;
        for(int i=0;i<adj.size();i++){
            int mini = INT_MAX;
            int u;
            for(int v=0;v<adj.size();v++){
                if(MST[i] == false && key[i] < mini){
                    mini = key[i];
                    u = v;
                }
            }
            MST[u] = true;
            for(auto j:adj[u]){
                if(MST[u]==false &&  j.second < key[j.first]){
                    parent[j.first] = u ;
                    key[j.first] = j.second;
                }
            }
        }
        vector<pair<pair<int, int>, int>> result;
        for(int i=0;i<key.size();i++){
            result.push_back(make_pair(make_pair(parent[i], i), key[i]));
        }
        return result;
    }
};

int main(){

    undirected_graph<int> g1;
    int node, edge;
    cout<<"Enter Number of Node : ";
    cin>>node;
    cout<<"Enter Number of Edge : ";
    cin>>edge;
    cout<<"\n\n";
    for(int i=0;i<edge;i++){
        int u, v, w;
        cin>>u;
        cin>>v;
        cin>>w;
        g1.addEdgeAdjList(u, v, w);
    }
    cout<<"ADJ List : \n";
    g1.printAdjList();

    vector<pair<pair<int, int>, int>> answer;
    answer = g1.MST();

    for(auto i: answer){
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<" "<<endl;
    }
}