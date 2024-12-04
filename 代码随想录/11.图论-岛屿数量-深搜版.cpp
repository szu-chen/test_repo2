//#include<iostream>
//using namespace std;
//#include<vector>
//
//int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
//void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
//{
//	if (visited[x][y] || grid[x][y] == 0)return;
//	visited[x][y] = true;
//	for(int i = 0;i<4;i++)
//	{
//		int nextx = x + dir[i][0];
//		int nexty = y + dir[i][1];
//		if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())continue;
//		dfs(grid, visited, nextx, nexty);
//	}
//}
//
//int main11()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> grid(n, vector<int>(m, 0));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> grid[i][j];
//		}
//	}
//	vector<vector<bool>> visited(n, vector<bool>(m, false));
//
//	int result = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (!visited[i][j] && grid[i][j] == 1)
//			{
//				result++;
//				dfs(grid, visited, i, j);
//			}
//		}
//	}
//	cout << result << endl;
//
//
//	system("pause");
//	return 0;
//}