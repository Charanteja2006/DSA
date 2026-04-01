class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& heal, string dir) {
        map<int,int> mp;
        int n = pos.size();

        for(int i=0;i<n;i++) mp[pos[i]] = i;
        sort(pos.begin(),pos.end());

        stack<int> st;
        int i = 0;
        while(i<n){
            if(st.empty()) st.push(pos[i]);
            else{
                if(dir[mp[st.top()]]==dir[mp[pos[i]]]){
                    st.push(pos[i]);
                }
                else{
                    if(dir[mp[st.top()]]=='L') st.push(pos[i]);
                    else{
                        while(i<n && !st.empty() && dir[mp[st.top()]]!='L' ){
                            if(dir[mp[st.top()]]==dir[mp[pos[i]]]) break;
                            if(heal[mp[st.top()]]==heal[mp[pos[i]]]){
                                st.pop();
                                i++;
                            }
                            else if(heal[mp[st.top()]]>heal[mp[pos[i]]]){
                                heal[mp[st.top()]] -= 1;
                                i++;
                            }
                            else{
                                st.pop();
                                heal[mp[pos[i]]] -= 1;
                            }
                        }
                        if(i<n) st.push(pos[i]);
                    }
                }
            }
            i++;
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(mp[st.top()]);
            st.pop();
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++) res[i] = heal[res[i]];
        return res;
    }
};