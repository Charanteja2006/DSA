class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        map<char,int> mp;
        int n = s.size();
        int l = 0;
        for(int i=0;i<n;i++){
            
            mp[s[i]]++;

            if(mp.size()==3){
                while(mp.size()==3){
                    count += n-i;
                    mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                    l++;
                }
            }
            
        }

        return count;
    }
};