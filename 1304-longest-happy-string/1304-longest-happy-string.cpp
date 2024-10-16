class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int,char>> v;
        v.push_back({a,'a'});
        v.push_back({b,'b'});
        v.push_back({c,'c'});
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string ans="";
        if(v[0].first >= 2*(v[1].first+v[2].first)){
            //cout<<"hi"
            while(v[1].first || v[2].first){
                ans+=string(2,v[0].second);
                v[0].first-=2;
                if(v[1].first){ 
                    ans+=v[1].second;
                    v[1].first--;
                }
                else {
                    ans+=v[2].second;
                    v[2].first--;
                }
            }
            ans+=string(min(2,v[0].first),v[0].second);
            return ans;
        }
        else if(v[0].first >= (v[1].first+v[2].first)){
            int req=v[0].first - (v[1].first+v[2].first);
            for(int i=0;i<req;i++){
                ans+=string(2,v[0].second);
                if(v[1].first){ 
                    ans+=v[1].second;
                    v[1].first--;
                }
                else {
                    ans+=v[2].second;
                    v[2].first--;
                }
            }
            while(v[1].first || v[2].first){
                ans+=v[0].second;
                if(v[1].first){ 
                    ans+=v[1].second;
                    v[1].first--;
                }
                else {
                    ans+=v[2].second;
                    v[2].first--;
                }
            }
            return ans;
        }
        else{
            int res=v[2].first - (v[0].first-v[1].first);
            for(int i=0;i<res;i++){
                ans+=v[0].second;
                ans+=v[1].second;
                ans+=v[2].second;
                v[0].first--;
                v[1].first--;
                v[2].first--;
            }
            while(v[1].first){
                ans+=v[0].second;
                ans+=v[1].second;
                v[1].first--;
            }
            while(v[2].first){
                ans+=v[0].second;
                ans+=v[2].second;
                v[2].first--;
            }
            return ans;
        }
        return "";
    }
};