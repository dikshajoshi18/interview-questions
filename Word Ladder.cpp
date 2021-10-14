 int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
       auto itr  = find(wordList.begin(), wordList.end(), endWord);
        
        if(itr == wordList.end())
            return 0;
        
        
        queue<string> q;
                
        q.push(beginWord);
        
        unordered_set <string> words (wordList.begin(), wordList.end());
        
        int ans = 0;
        while(!q.empty()){
            ans++;
            int ls = q.size();
            
            while(ls --){
                
                string temp = q.front();
                q.pop();
            
                for(int i = 0 ; i<temp.size(); i++){
                    char c = temp[i];

                    for(char j = 'a' ; j<= 'z' ; j++)
                    {
                        temp[i] = j;

                        if(temp == endWord)
                            return ++ans;
                        if(!words.count(temp))
                            continue;


                        words.erase(temp);
                        q.push(temp);

                        words.erase(endWord);
                    }

                    temp[i] = c;
                }
                }

         }
        
        
        return 0;
        
    }
