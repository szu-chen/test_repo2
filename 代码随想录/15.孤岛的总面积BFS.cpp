//#include<iostream>
//using namespace std;
//#include<vector>
//#include<queue>
//
//int countt = 0;
//int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
//void bfs(vector<vector<int>>& grid, int x, int y)
//{
//	queue<pair<int, int>> que;
//	que.push({ x,y });
//	grid[x][y] = 0;
//	countt++;
//	while (!que.empty())
//	{
//		pair<int, int> cur = que.front();
//		que.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int nextx = cur.first + dir[i][0];
//			int nexty = cur.second + dir[i][1];
//			if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())continue;
//			if ( grid[nextx][nexty] == 1)
//			{
//				que.push({ nextx,nexty });
//				grid[nextx][nexty] = 0;
//				countt++;
//			}
//		}
//	}
//}
//
//
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
//		if (grid[i][0] == 1)bfs(grid, i, 0);
//		if (grid[i][m - 1] == 1)bfs(grid, i, m-1);
//	}
//
//	for (int j = 0; j < m; j++)
//	{
//		if (grid[0][j] == 1)bfs(grid, 0, j);
//		if (grid[n - 1][j] == 1)bfs(grid, n - 1, j);
//	}
//
//	countt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (grid[i][j] == 1)bfs(grid, i, j);
//		}
//	}
//	cout << countt << endl;
//	system("pause");
//	return 0;
//}