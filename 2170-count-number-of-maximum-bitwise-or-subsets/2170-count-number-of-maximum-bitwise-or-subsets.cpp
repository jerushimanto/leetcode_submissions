class Solution {
public:

    int find(vector<int>& a,int cur, int tar, int i){
        if(i==0)return (tar==cur);
        else return (find(a,cur,tar,i-1)+find(a,cur|a[i-1],tar,i-1));
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int tar=0;
        for(int i:nums) tar|=i;
        return find(nums,0, tar,nums.size());
    }
};