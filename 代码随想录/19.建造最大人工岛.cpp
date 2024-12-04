//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//using namespace std;
//
//int n, m;
//int countt;
//int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
//
//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark)
//{
//	if (visited[x][y] || grid[x][y] == 0)return;
//	visited[x][y] = true;
//	grid[x][y] = mark;
//	countt++;
//	for (int i = 0; i < 4; i++)
//	{
//		int nextx = x + dir[i][0];
//		int nexty = y + dir[i][1];
//		if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)continue;
//		dfs(grid, visited, nextx, nexty, mark);
//	}
//}
//
//
//int main()
//{
//	cin >> n >> m;
//	vector<vector<int>> grid(n, vector<int>(m, 0));
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> grid[i][j];
//		}
//	}
//	vector<vector<bool>> visited(n, vector<bool>(m, false));
//	unordered_map<int, int> gridNum;
//	int mark = 2;
//	bool isAllGrid = true;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (grid[i][j] == 0)isAllGrid = false;
//			if (grid[i][j] == 1 && !visited[i][j])
//			{
//				countt = 0;
//				dfs(grid, visited, i, j, mark);
//				gridNum[mark] = countt;
//				mark++;
//			}
//		}
//	}
//
//	if (isAllGrid)
//	{
//		cout << n * m << endl;
//		return 0;
//	}
//
//	int result = 0;
//	unordered_set<int> visitedGrid;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{	
//			countt = 1;
//			visitedGrid.clear();
//			if (grid[i][j] == 0)
//			{
//				for (int k = 0; k < 4; k++)
//				{
//					int nexti = i + dir[k][0];
//					int nextj = j + dir[k][1];
//					if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m)continue;
//					if (visitedGrid.count(grid[nexti][nextj]))continue;
//					countt += gridNum[grid[nexti][nextj]];
//					visitedGrid.insert(grid[nexti][nextj]);
//				}
//			}
//			result = max(result, countt);
//		}
//	}
//	cout << result << endl;
//
//
//	system("pause");
//	return 0;
//}