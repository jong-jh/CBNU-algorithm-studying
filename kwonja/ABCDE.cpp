#include <iostream>
#include<vector>
using namespace std;

vector<int> graph[2001];
int vistied[2001] = { 0, };
bool ans = false;

void DFS(int i, int g)
{
	vistied[i] = 1;
	if (g == 4)
	{
		ans = true;
		return;
	}
	for (int j = 0; j < graph[i].size(); j++)
	{
		if (!vistied[graph[i][j]])
		{
			DFS(graph[i][j], g + 1);
		}
	}
	vistied[i] = 0; //깊이우선탐색에서 예외경우가 있는데,
					//예외경우를 제외하고, 다시 시작해야되기때문에, 노드탐색이 잘못되었을때,
					//돌아오면서 노드 방문기록을 없애는 방법
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	int v, g;
	for (int i = 0; i < m; i++)
	{
		cin >> v >> g;
		graph[v].push_back(g);
		graph[g].push_back(v);
		//양방향 간선 저장
	}
	for (int i = 0; i < n; i++)
	{
		DFS(i, 0);
		if (ans == true)
		{
			cout << 1;
			break;
		}
		ans = false;
		for (int i = 0; i < n; i++)
		{
			vistied[i] = 0;
		}
	}
	if (ans == false)
	{
		cout << 0;
	}
	return 0;
}