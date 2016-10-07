#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
int test;
int N, M;
int parent[1001];
int board[1001][1001];
 
struct edge{
	int from;
	int to;
	int cost;
	bool operator < (const edge &other){
		return cost > other.cost;
	}
};
int find(int x){
	if (x == parent[x]){
		return x;
	}
	return parent[x] = find(parent[x]);
}
void Union(int x, int y){
	x = find(x);
	y = find(y);
	if (x != y){
		parent[y] = x;
	}
}
//스패닝 트리 탐색
int bfs(vector<vector<int> > graph,int root,int target){
	queue<int> q;
	q.push(root);
	int ret=123123125;
	bool visited[1001];
	memset(visited,false,sizeof(visited));
	visited[root]=true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		printf("now :%d\n",x);
		if(x == target){
			break;
		}
		int len = graph[x].size();
		for(int i=0;i<len;i++){
			int nx = graph[x][i];
			if(!visited[nx]){
				ret = min(ret,board[x][nx]);
				visited[nx]=true;
				q.push(nx);
			}
		}
	}
	return ret;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &test);
	while (test--){
		scanf("%d %d", &N, &M);
		vector<vector<int> > graph(N + 1);
		memset(board,0,sizeof(board));
		vector<edge> group;
		int m = M;
		while (M--){
			int u, v, x;
			scanf("%d %d %d", &u, &v, &x);
			edge e = { u, v, x };
			group.push_back(e);
		}
		sort(group.begin(), group.end());
		int q;
		scanf("%d", &q);
		int ans = 0;
		for (int i = 1; i <= N; i++){
				parent[i] = i;
		}
		memset(board,0,sizeof(board));
		for(int i = 0; i < m; i++){
			int f = group[i].from;
			int t = group[i].to;
			int cost = group[i].cost;
			int pf = find(f);
			int pt = find(t);
			if(pf != pt){
				//새 무방향 그래프 만듬
				graph[f].push_back(t);
				graph[t].push_back(f);
				board[f][t]=cost;
				board[t][f]=cost;
				Union(pf,pt);
			}
		}
		while (q--){
			int from, to;
			scanf("%d %d", &from, &to);
			//bfs로 new graph의 간선의 최소값을 구함
			int cnt = bfs(graph,from,to);
			if(cnt!=123123125) ans += cnt;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
