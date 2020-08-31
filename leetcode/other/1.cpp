#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>data(m,vector<int>(n));
    for(int i =0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>data[i][j];
        }
    }

    int target;
    cin>>target;
    int i = 0;
    while(data[i][i]<=target){
        if(data[i][i] == target){
            cout<<i<<' '<<i<<endl;
            system("pause");
            return 0;
        }
        i++;
    }
    int j = i-1;
    if(data[j][j]<target && data[j+1][j]>target){
        int x = m - j -1,y = n-j-1;
        if(data[x][y]>target){
            if(data[j][y]>=target){
                for(int k = j;k<=y;k++){
                    if(data[j][k] == target){
                        cout<<j<<' '<<k<<endl;
                        system("pause");
                        return 0;
                    }
                    else{
                        for(int k = j+1;k<=x;k++){
                            if(data[k][j] == target){
                                cout<<k<<' '<<j<<endl;
                                system("pause");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        else{
            if(data[x][j]>=target){
                for(int k = j;k<=y;k++){
                    if(data[x][k] == target){
                        cout<<x<<' '<<k<<endl;
                        system("pause");
                        return 0;
                    }
                }
            }
            else{
                for(int k = j;k<=x;k++){
                    if(data[k][j] ==target ){
                        cout<<k<<' '<<j<<endl;
                        system("pause");
                        return 0;
                    }
                }
            }

        }
    }
    system("pause");
    return 0;
}