class Solution {
public:
    bool check(const string& s1,const string& s2){
        int n = s1.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]) count++;
        }

        if(count == 1) return true;
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(beginWord == endWord) return 0;
        if(s.count(endWord)==0) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        
        s.erase(beginWord);

        while(!q.empty()){
            string cur = q.front().first;
            int st = q.front().second;
            q.pop();
            if(cur == endWord) return st+1;
            for(auto it:wordList){
                if(s.count(it) && check(cur,it)){
                    s.erase(it);
                    q.push({it,st + 1});
                }
            }  
        }
        
        return 0;
    }
};