class Solution {
public:
    int get_sum(pair<int,int>p){
        int s = 0;
        while(p.first){
            s+=p.first%10;
            p.first/=10;
        }
        while(p.second){
            s+=p.second%10;
            p.second/=10;
        }
        return s;
    }
    int movingCount(int m, int n, int k) {
        if(!m || !n)return 0;
        queue<pair<int,int>>q;
        vector<vector<bool>> st(m,vector<bool>(n,false));
        int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
        int res= 0;
        q.push({0,0});
        while(q.size()){
            auto t = q.front();
            q.pop();
            if(st[t.first][t.second] || get_sum(t)>k)continue;
            res++;
            st[t.first][t.second] = true;
            for(int i = 0;i<4;i++){
                int x = t.first+dx[i],y = t.second+dy[i];
                if(x>=0&&x<m&&y>=0&&y<n)q.push({x,y});
            }
        }
        return res;
    }
};