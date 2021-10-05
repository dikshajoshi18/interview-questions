
#include<bits/stdc++.h>
using namespace std;

void toposort(int node,int vis[],stack<int>&st,vector<pair<int,int>>adj[])
{
    vis[node] = 1;

    for(auto x:adj[node])
    {
        if(!vis[x.first])
        {
            toposort(x.first,vis,st,adj);
        }
    }
    st.push(node);  

}


void shortestPath(int src,int N,vector<pair<int,int>> adj[])
{
    int vis[N] = {0};

    stack<int> st;

    for(int i=0;i<N;i++)
    {
        if(!vis[i]) toposort(i,vis,st,adj);
    }

    int distance[N] = {1e9};

    distance[src] = 0;

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(distance[node]!=1e9)
        {
            for(auto x:adj[node])
            {
                if(distance[node] + x.second < distance[x.first] )
                {
                    distance[x.first] = distance[node] + x.second;
                }
            }
        }

    }

    for(int i=0;i<N;i++)
    {
        distance[i]!=1e9 ? cout<<distance[i] : cout<<"unreachable";
    }

}













int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 

	return 0; 
} 