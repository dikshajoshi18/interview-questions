string decodeString(string s) {
        
        
        stack<int> nums;
        
        stack<char> strr;
        
        int times = 0;
        
        for(int i = 0 ;i< s.size() ;i++){
            
            int val = s[i] - '0';
            
            if(val<=9 and val>=0 )
            {
                
                times  = times*10 + val;
            }
            
            else {
                
                if(times!=0)
                    nums.push(times);
                
                times = 0;
                
                 if(s[i] != ']')
                strr.push(s[i]);
            
            if(s[i] == ']')
            {
                string temp = "";
                while(strr.top()!= '['){
                    
                    char c = strr.top();
                    strr.pop();
                    
                    temp+=c;
                }
                
                if(strr.top() == '[')
                    strr.pop();
                
                for(int k =0; k<nums.top();k++)
                for(int j = temp.size()-1 ;j>=0; j--)
                    strr.push(temp[j]);
                    
                nums.pop();
            }
            
            
                
            }
            
           
            
        }
        
        string ans="";
        
        int i =0;
        
        while(!strr.empty()){
            
            ans += strr.top();
            strr.pop();
            
            
        }
        
        string finalAns = "";
        
        for(int i =ans.size()-1; i>=0 ; i--){
            finalAns += ans[i];
            
        }
        
        return finalAns;
        
        
        
    }
