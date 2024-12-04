//#include<iostream>
//using namespace std;
//#include<vector>
//
//int n, m;
//int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
//{
//	if (visited[x][y]) return;
//	visited[x][y] = true;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nextx = x + dir[i][0];
//		int nexty = y + dir[i][1];
//		if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)continue;
//		if (grid[nextx][nexty] <= grid[x][y])
//		{
//			dfs(grid, visited, nextx, nexty);
//		}
//	}
//	return;
//}
//
//bool isResult(vector<vector<int>>& grid, int x, int y)
//{
//	vector<vector<bool>> visited(n, vector<bool>(m, false));
//	bool isFirst = false;
//	bool isSecond = false;
//	
//	dfs(grid, visited, x, y);
//	for (int j = 0; j < m; j++)
//	{
//		if (visited[0][j])
//		{
//			isFirst = true;
//			break;
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i][0])
//		{
//			isFirst = true;
//			break;
//		}
//	}
//
//	for (int j = 0; j < m; j++)
//	{
//		if (visited[n-1][j])
//		{
//			isSecond = true;
//			break;
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i][m-1])
//		{
//			isSecond = true;
//			break;
//		}
//	}
//	if (isFirst && isSecond)return true;
//	return false;
//}
//
//
//int main()
//{
//	cin >> n >> m;
//
//	vector<vector<int>> grid(n, vector<int>(m, 0));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> grid[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (isResult(grid, i, j))
//			{
//				cout << i << " " << j << endl;
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}