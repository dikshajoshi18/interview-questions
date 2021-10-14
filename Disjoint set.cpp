int find(int source, vector<pair<int,int>> &disjoint){
        
        if(disjoint[source].first == source)
            return source;
        return disjoint[source].first = find(disjoint[source].first, disjoint); 
    }
    
    void unionOfEdge(int source, int destination, vector<pair<int,int>> &disjoint){
        
        if(disjoint[source].second > disjoint[destination].second)
            disjoint[destination].first = source;

        else if(disjoint[source].second < disjoint[destination].first)
            disjoint[source].first = destination;

        else{
            
            disjoint[source].first = destination;
            disjoint[destination].second++; 
        }
    }
    
    void merge(int from, int to, vector<pair<int,int>> &disjoint){
        int fromParent = find(from, disjoint);
        int toParent = find(to, disjoint);
        unionOfEdge(fromParent, toParent, disjoint);
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<pair<int,int> > disjoint;
                                         
        for(int i = 0; i<=n; i++){
            
            disjoint.push_back(make_pair(i, 0));
            cout<<disjoint[i].first<<" ";
        }
        
        cout<<endl;
                                            
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n ;j++){

                if(isConnected[i][j])
                
                    merge(i+1,j+1, disjoint);
                
            }  
        }
                 
        int ct =0;
                                            
        for(int i = 1; i<=n; i++){
            if(disjoint[i].first == i)
                ct++;
            
            cout<<disjoint[i].first<<" ";
        }
                                            
        return ct;
                                        
    }
