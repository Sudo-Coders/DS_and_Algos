// Graph dfs problem
// http://codeforces.com/contest/601/problem/A


#include <iostream>
#include <string.h> 
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> v[500] ; 
int graph[401][401];
// vector for maintaining adjacency list explained above.
int level[401];
int level2[401];// to determine the level of each node
bool visited[401];
bool visited2[401];
//mark the node if visited 
void bfs(int s) 
{
    queue <int> q;
    q.push(s);
    level[ s ] = 0 ;  //setting the level of sources node as 0.
    visited[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0;i < v[ p ].size() ; i++)
        {
            if(visited[ v[ p ][ i ] ] == false)
            {
        //setting the level of each node with an increment in the level of parent node
                level[ v[ p ][ i ] ] = level[ p ]+1;                 
                 q.push(v[ p ][ i ]);
                 visited[ v[ p ][ i ] ] = true;
  }
        }
    }
}
// 2nd bfs modified 

void bfs2(int s,int n) {
    queue <int> q;
    q.push(s);
    level[ s ] = 0 ; 
    visited2[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        
        for(int i = 1;i <= n;i++)
            {
            
                if(graph[p][i]==1 && visited[i]== false)
                {
                    level[i] = min(level[p]+1,level[i]);                 
                    q.push(i);
                    visited[i] = true;
                }
                 
            }
    }
}

void bfs3(int s,int n) {
    queue <int> q;
    q.push(s);
    level2[ s ] = 0 ; 
    visited2[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        
        for(int i = 1;i <= n;i++)
            {
            
                if(graph[p][i]==0 && visited2[i]== false)
                {
                    level2[i] = min(level2[p]+1,level2[i]);                 
                    q.push(i);
                    visited2[i] = true;
                }
                 
            }
    }
}
int main() {
    int n,m,x,y;
	cin >> n >> m;
	memset(graph,0,sizeof(graph));
	memset(level,10000,sizeof(level));
	memset(level2,10000,sizeof(level2));
	memset(visited,false,sizeof(visited));
	memset(visited2,false,sizeof(visited2));
	
	for (int i = 0; i < m; i++) 
	{
	    cin >> x >> y;  
	    graph[x][y] = 1;
	    graph[y][x] = 1;
	    v[x].push_back(y);
	    v[y].push_back(x);
	}
//	bfs(1);
	bfs2(1,n);
	
	bfs3(1,n);
	if(visited[n]==false || visited2[n] == false)
	{
	        cout << "-1\n";
	}
	else
	{
	    cout << max(level[n],level2[n])  << endl;  
	}
	
	return 0;
}
