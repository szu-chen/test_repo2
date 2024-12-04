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
//		if (grid[nextx][nexty] >= grid[x][y])
//		{
//			dfs(grid, visited, nextx, nexty);
//		}
//	}
//	return;
//}
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
//	vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
//	vector<vector<bool>> secondBorder(n, vector<bool>(m, false));
//	for (int i = 0; i < n; i++)
//	{
//		dfs(grid, firstBorder, i, 0);
//		dfs(grid, secondBorder, i, m - 1);
//	}
//	for (int j = 0; j < m; j++)
//	{
//		dfs(grid, firstBorder, 0, j);
//		dfs(grid, secondBorder, n-1, j);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (firstBorder[i][j] && secondBorder[i][j])
//			{
//				cout << i << " " << j << endl;
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}