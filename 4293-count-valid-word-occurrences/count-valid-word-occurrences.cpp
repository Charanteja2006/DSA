class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        
        for(auto it:chunks) s += it;

        map<string,int> mp;
        string temp = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(!temp.empty()) mp[temp]++;
                temp = "";
            }
            else if(s[i]=='-'){
                if(temp.size()!=0 && i+1<n && isalpha(s[i+1])) temp+='-';
                else{
                    if(temp.size()!=0){
                        mp[temp]++;
                        temp="";
                    }
                }
            }
            else temp += s[i];
        }

        if(!temp.empty()) mp[temp]++;

        int m = queries.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int freq = mp[queries[i]];
            ans[i] = freq;
        }

        return ans;
    }
};