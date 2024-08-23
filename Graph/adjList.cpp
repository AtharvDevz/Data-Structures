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
        adj[u].insert(make_pair(v, w));
        adj[v].insert(make_pair(u, w));
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

    void bfs(map<T, set<pair<T, int>>> &adj, map<T, bool> &visited, T node, vector<T> &ans){
        queue<T> q;
        q.push(node.first);
        visited[node.first] = 1;

        while(!q.empty()){
            T frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            for(auto j:adj[frontNode]){
                if(!visited[j.first]){
                    q.push(j.first);
                    visited[j.first] = 1;
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
    void dfs(T node,map<T, set<pair<T, int>>> &adj, map<T, bool> &visited, vector<T> &component){
        stack<T> st;
        visited[node.first] = 1;
        st.push(node.first);
        while(!st.empty()){
            T topNode = st.top();
            st.pop();
            component.push_back(topNode);
            for(auto i: adj[topNode]){
                if(!visited[i.first]){
                    visited[i.first] = 1 ;
                    st.push(i.first);
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

    vector<pair<pair<int, int>, int>> primsMST(){
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
                if(MST[v] == false && key[v] < mini){
                    u = v;
                    mini = key[v];
                }
            }
            MST[u] = true;
            for(auto j:adj[u]){
                if(MST[j.first]==false &&  j.second < key[j.first]){
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

    // vector<int> bfs;
    // bfs= g1.BFS();
    // cout<<"BFS : "<<endl;
    // for(int i: bfs){
    //     cout<<i<<"  ";
    // }
    // cout<<endl;


    // vector<vector<int>> dfs;
    // dfs = g1.DFS();
    // cout<<"DFS : "<<endl;
    // for(int i:dfs[0]){
    //     cout<<i<<"  ";
    // }   
    // cout<<endl;

    vector<pair<pair<int, int>, int>> answer;
    answer = g1.primsMST();

    cout<<"Weight  Node  Parent"<<endl;
    for(auto i: answer){
        cout<<i.second<<"  "<<i.first.second<<" "<<i.first.first<<endl;
    }
}