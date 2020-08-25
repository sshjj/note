vector<int> boundaryOfBinaryTree(vector<int>data) {
    	if(!data.size()) return {};
    	ans.push_back(data[0]);
        for(int i =0;i<data.size()/2;i++){
    	    dfs(data, -1,2i+1);
    	    dfs(data, 1,2i+2);
        }
    	return ans;
    }
    void dfs(vector<int>data, int dir)
    {
    	if(!data[i]) return;
    	if(dir == -1)//左边界
    	{
    		ans.push_back(data[i]);//前序遍历
    		if(data[2i+1])
    		{	
    			dfs(root->left,-1);//有左节点，进入左节点找
    			dfs(root->right, 0);//舍弃右节点
    		}
    		else
    			dfs(root->right,-1);//没有左节点，当成左边界
    	}
    	else if(dir == 1)//右边界
    	{
    		// ans.push_back(root->val);//写这里错了
    		if(root->right)
    		{
    			dfs(root->left,0);
    			dfs(root->right, 1);
    		}
    		else
    			dfs(root->left, 1);
    		ans.push_back(root->val);//应该是后序遍历
    	}
    	else//dir==0，非左右边界，找叶子节点
    	{
    		if(!root->left && !root->right)
    			ans.push_back(root->val);
    		dfs(root->left, 0);
    		dfs(root->right, 0);
    	}
    }
};