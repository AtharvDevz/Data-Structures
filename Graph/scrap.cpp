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
    
    map <T, set<pair<T, int>>> adj;
    void addEdgeAdjList(T u, T v, int w){
        adj[u].insert(v, w);
        adj[v].insert(u, w);
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<< " -> ";
            for(auto j: i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }

    void bfs(map<T, set<pair<T, int>>> &adj, map<T, bool> &visited, T node, vector<T> &ans){
        queue<T> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()){
            T frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            for(auto j:adj[frontNode]){
                if(!visited[j]){
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
    }
    vector<T> BFS(){
        map<T, bool> visited;
        vector<T> ans;
        // default Value of a bool Variable is false
        // for(auto i: adj){
        //     visited[i] = 0;
        // }
        for(auto i : adj){
            if(!visited[i.first]){
                bfs(adj, visited, i.first, ans);
            }
        }
        return ans;
    }

// With Stack
    void dfs(T node,map<T, set<T>> &adj, map<T, bool> &visited, vector<T> &component){
        stack<T> st;
        visited[node] = 1;
        st.push(node);
        while(!st.empty()){
            T topNode = st.top();
            st.pop();
            component.push_back(topNode);
            for(auto i: adj[topNode]){
                if(!visited[i]){
                    visited[i] = 1 ;
                    st.push(i);
                }
            }
        }
    }

// With Recursion
    // void dfs(T node,map<T, set<T>> &adj, map<T, bool> &visited, vector<T> &component){
    //     component.push_back(node);
    //     visited[node] = 1;
    //     for(auto i: adj[node]){
    //             if(!visited[i]){
    //                 dfs(i, adj, visited, component);
    //             }
    //     }
    // }

    vector<vector<T>> DFS(){
        map<T, bool> visited;
        vector<vector<T>> ans;

        for(auto j: adj){   
            if(!visited[j.first]){
                vector<T> component;
                dfs(j.first, adj, visited, component);
                ans.push_back(component);
            }
        }
        return ans;
    }


};


template <typename T>
class directed_graph{
    public:
    
    map <T, list<T>> adj;
    void addEdge(T u, T v, bool direct){
        // direct 
        // 0 -> indegree
        // 1-> outdegree
        if(direct == 1){
            adj[u].push_back(v);
        }else{
            adj[v].push_back(u);
        }
    }
    
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<< " -> ";
            for(auto j: i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
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

    vector<int> bfs;
    bfs= g1.BFS();
    cout<<"BFS : "<<endl;
    for(int i: bfs){
        cout<<i<<"  ";
    }
    cout<<endl;


    vector<vector<int>> dfs;
    dfs = g1.DFS();
    cout<<"DFS : "<<endl;
    for(int i:dfs[0]){
        cout<<i<<"  ";
    }   
    cout<<endl;

    // directed_graph<string> g2;
    // int node, edge;
    // cout<<"Enter Number of Node : ";
    // cin>>node;
    // cout<<"Enter Number of Edge : ";
    // cin>>edge;
    // cout<<"\n\n";
    // for(int i=0;i<edge;i++){
    //     string u, v;
    //     bool direct;
    //     cin>>u;
    //     cin>>v;
    //     cin>>direct;
    //     g2.addEdge(u, v, direct);
    // }
    // cout<<"ADJ List : \n";
    // g2.printAdjList();

}