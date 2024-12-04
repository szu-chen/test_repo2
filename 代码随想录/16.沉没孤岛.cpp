//#include<iostream>
//using namespace std;
//#include<vector>
//
//int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
//void dfs(vector<vector<int>>& grid, int x, int y)
//{
//	if (grid[x][y] == 0||grid[x][y]==2)return;
//	grid[x][y] = 2;
//	for (int i = 0; i < 4; i++)
//	{
//		int nextx = x + dir[i][0];
//		int nexty = y + dir[i][1];
//		if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())continue;
//		if (grid[nextx][nexty] == 1)
//		{
//			dfs(grid, nextx, nexty);
//		}
//	}
//}
//
//int main()
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
//
//	for (int i = 0; i < n; i++)
//	{
//		if (grid[i][0] == 1)dfs(grid, i, 0);
//		if (grid[i][m - 1] == 1)dfs(grid, i, m - 1);
//	}
//
//	for (int j = 0; j < m; j++)
//	{
//		if (grid[0][j] == 1)dfs(grid, 0, j);
//		if (grid[n - 1][j] == 1)dfs(grid, n - 1, j);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (grid[i][j] == 1)grid[i][j] = 0;
//			if (grid[i][j] == 2)grid[i][j] = 1;
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m-1; j++)
//		{
//			cout << grid[i][j] << " ";
//		}
//		cout << grid[i][m - 1] << endl;
//	}
//
//	system("pause");
//	return 0;
//}