#include <iostream>
#include <string>
using namespace std;
int n, m;
string maze[110];
bool vis[110][110];

bool in(int x,int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool dfs(int x,int y){
    
    /*找到终点后退出*/
    if(maze[x][y] == 'T'){
        return true;
    }
    vis[x][y]=1;
    maze[x][y]='m';
    
	/*尝试上下左右方向*/
    int tx = x-1,ty=y;
    if(in(tx,ty)&&maze[tx][ty]!='*'&&!vis[tx][ty]){
        if(dfs(tx,ty)){
            return true;
        }
    }

	tx = x,ty=y-1;
    if(in(tx,ty)&&maze[tx][ty]!='*'&&!vis[tx][ty]){
        if(dfs(tx,ty)){
            return true;
        }
    }

    tx = x+1,ty=y;
    if(in(tx,ty)&&maze[tx][ty]!='*'&&!vis[tx][ty]){
        if(dfs(tx,ty)){
            return true;
        }
    }
    
    tx = x,ty=y+1;
    if(in(tx,ty)&&maze[tx][ty]!='*'&&!vis[tx][ty]){
        if(dfs(tx,ty)){
            return true;
        }
    }
    
	/*回溯*/
    vis[x][y] = 0;
    maze[x][y] = '.';
    return false;
    
}

int main() {
    // 输入迷宫地图
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    int x,y;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == 'S'){
                x = i,y = j;
            }
        }
    }
    
    if(dfs(x,y)){
        for(int i=0;i<n;i++){
            cout<< maze[i]<<endl;
        }
    }else{
        cout<<"NO!"<<endl;
    }
    
    return 0;
}
