class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        set<int> s;
        int count = 0;
        for(int i=0;i<n;i++){
            if(A[i]==B[i]){
                count++;
                ans[i] = count;
            }
            else{
                if(s.count(A[i])){
                    count++;
                }
                else s.insert(A[i]);
                if(s.count(B[i])) count++;
                else s.insert(B[i]);

                ans[i] = count;
            }
        }

        return ans;
    }
};