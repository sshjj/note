class DisjoinSet{
public:
    DisjoinSet(int n){
        for(int i = 0;i<n;i++){
            _id.push_back(i);
        }
    }
    int find(int p){
        return _id[p];
    }
    void union_(int p,int q){
        int pid = find(p);
        int qid = find(q);
        if(pid == qid){
            return ;
        }
        for(int i =0;i<_id.size();i++){
            if(_id[i] == pid){
                _id[i] = qid;
            }
        }
    }
private:
    vector<int>_id;
}