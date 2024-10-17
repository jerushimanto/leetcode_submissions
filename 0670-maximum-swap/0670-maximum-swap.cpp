class Solution {
public:
    int maximumSwap(int num) {
        int n=0;
        string s1="",s2="";
        while(num){
            s1+=('0'+(num%10));
            s2+=('0'+(num%10));
            num/=10;
            n++;
        }
        reverse(s1.begin(),s1.end());
        sort(s2.begin(),s2.end(),greater<char>());
        //cout<<s1<<endl<<s2;

        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                for(int j=n-1;j>i;j--){
                    if(s1[j]==s2[i]){
                        //char temp=s1[i];
                        s1[j]=s1[i];
                        s1[i]=s2[i];
                        break;
                    }
                }
                break;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans*10 + (s1[i]-'0'));
        }
        return ans;

    }
};