//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//
//int main()
//{
//	int m, n, p1, p2, val;
//	cin >> n>> m;
//	vector < vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
//	while (m--)
//	{
//		cin >> p1 >> p2 >> val;
//		grid[p1][p2] = val;
//	}
//
//	vector<int> minDist(n + 1, INT_MAX);
//	vector<bool> visited(n + 1, false);
//	vector<int> father(n + 1, -1);
//	//��ʼ��
//	minDist[1] = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		int minVal = INT_MAX;
//		int cur = 1;
//		for (int j = 1; j <= n; j++)
//		{
//			if (!visited[j] && minDist[j] < minVal)
//			{
//				minVal = minDist[j];
//				cur = j;
//			}
//		}
//		visited[cur] = true;
//
//		for (int j = 1; j <= n; j++)
//		{
//			if (!visited[j] && grid[cur][j] != INT_MAX && grid[cur][j] + minDist[cur] < minDist[j])
//			{
//				minDist[j] = grid[cur][j] + minDist[cur];
//				father[j] = cur;
//			}
//		}
//	}
//	if (minDist[n] == INT_MAX)cout << -1 << endl;
//	else cout << minDist[n] << endl;
//
//	//for (int i = 1; i <= n; i++)
//	//{
//	//	if (father[i] == -1)continue;
//	//	cout << father[i] << "->" << i << endl;
//	//}
//
//	system("pause");
//	return 0;
//}