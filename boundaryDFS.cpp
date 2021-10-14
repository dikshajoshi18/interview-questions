int numEnclaves(vector<vector<int>>& grid) {
        
        int n  = grid.size();
        int m = grid[0].size();
        
        cout<<n<<" "<<m;
        
        queue<pair<int,int>> q;
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m ;j++){
                
                if(i == 0 || j ==0 || i == n-1 || j==m-1 ){
                    
                    if(grid[i][j] == 1)
                    {
                        pair<int,int> p;
                        p.first = i;
                        p.second = j;
                        
                        q.push(p);
                        
                    }
                }
            }
        }
        
        
        while(!q.empty()){
            
            pair<int, int> temp;
            temp = q.front();
            q.pop();
            
            int i = temp.first;
            int j = temp.second;
            
            if(i<0  or i>=n or j<0 or j>=m or grid[i][j]!=1)
                continue;
            
           
            q.push(make_pair(i-1,j));
            q.push(make_pair(i+1,j));
            q.push(make_pair(i,j-1));
            q.push(make_pair(i,j+1));
            
            grid[i][j] = 0;
            
            
        }
        
        int sum = 0;
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m ; j++){
                sum+= grid[i][j];
            }
        }
        
        return sum;
        
    }
