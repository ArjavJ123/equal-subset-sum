class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        for(int i =0; i<n; i++) {
            s += nums[i];
        }
        if(s%2 == 1) {
            return false;
        }
        s = s/2;
        vector<vector<bool>> t(n+1, vector<bool>(s+1));
        for(int i=0 ;i<=n; i++) {
            for(int j=0; j<=s; j++) {
                if(j == 0) {
                    t[i][j] = true;
                }
                else if(i ==0) {
                    t[i][j] = false;
                }
                else {
                    if(nums[i-1] <= j) {
                        t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]]; 
                    }
                    else {
                        t[i][j] = t[i-1][j];
                    }
                }
            }
        }
        return t[n][s];
    }
};
