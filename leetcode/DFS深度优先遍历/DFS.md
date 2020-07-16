# 概念
深度优先搜索算法（Depth First Search，简称DFS）：一种用于遍历或搜索树或图的算法。 沿着树的深度遍历树的节点，尽可能深的搜索树的分支。当节点v的所在边都己被探寻过或者在搜寻时结点不满足条件，搜索将回溯到发现节点v的那条边的起始节点。整个进程反复进行直到所有节点都被访问为止。属于盲目搜索,最糟糕的情况算法时间复杂度为O(!n)。
————————————————
# 算法思想
回溯法（探索与回溯法）是一种选优搜索法，又称为试探法，按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为“回溯点”。 

# 基本模板
(```)
    int check(参数)
    {
        if(满足条件)
            return 1;
        return 0;
    }
 
    void dfs(int step)
    {
        判断边界
        {
            相应操作
        }
        尝试每一种可能
        {
               满足check条件
               标记
               继续下一步dfs(step+1)
               恢复初始状态（回溯的时候要用到）
        }
    }   
    /**
    * DFS核心伪代码
    * 前置条件是visit数组全部设置成false
    * @param n 当前开始搜索的节点
    * @param d 当前到达的深度
    * @return 是否有解
    */
    bool DFS(Node n, int d){
        if (isEnd(n, d)){//一旦搜索深度到达一个结束状态，就返回true
            return true;
        }
 
        for (Node nextNode in n){//遍历n相邻的节点nextNode
            if (!visit[nextNode]){//
                visit[nextNode] = true;//在下一步搜索中，nextNode不能再次出现
                if (DFS(nextNode, d+1)){//如果搜索出有解
                    //做些其他事情，例如记录结果深度等
                    return true;
                }
 
                //重新设置成false，因为它有可能出现在下一次搜索的别的路径中
                visit[nextNode] = false;
            }
        }
        return false;//本次搜索无解
    }
(```)