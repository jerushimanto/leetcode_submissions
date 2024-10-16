class Solution {
public:
    int romanToInt(string nums) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0;
        int temp=m[nums[0]];
        for(int i=1;i<nums.size();i++){
            cout<<temp<<" "<<ans<<endl;
            if(m[nums[i]]<=m[nums[i-1]]){
                temp+=m[nums[i]];
            }
            else{
                ans+=m[nums[i]]-temp;
                temp=0;
            }
        }
        ans+=temp;
        return ans;
    }
};