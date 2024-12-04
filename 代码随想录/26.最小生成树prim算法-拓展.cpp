//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main()
//{
//	int v, e, s, t, val;
//	cin >> v >> e;
//	vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));
//	while (e--)
//	{
//		cin >> s >> t >> val;
//		grid[s][t] = val;
//		grid[t][s] = val;
//	}
//
//	vector<int> minDist(v + 1, 10001);
//	vector<bool> inTree(v + 1, false);
//	//添加parent数组
//	vector<int> parent(v + 1, -1);
//
//	for (int i = 1; i < v; i++)
//	{
//		//1、选择非生成树中距离生成树最近的点
//		int cur = -1;
//		int minVal = INT_MAX;
//		for (int j = 1; j <= v; j++)
//		{
//			if (!inTree[j] && minDist[j] < minVal)
//			{
//				minVal = minDist[j];
//				cur = j;
//			}
//		}
//		//2、加入生成树
//		inTree[cur] = true;
//
//		//3、更新minDist数组
//		for (int j = 1; j <= v; j++)
//		{
//			if (!inTree[j] && grid[cur][j] < minDist[j])
//			{
//				minDist[j] = grid[cur][j];
//				parent[j] = cur;
//			}
//		}
//	}
//
//	//int result = 0;
//	//for (int i = 2; i <= v; i++)
//	//{
//	//	result += minDist[i];
//	//}
//	//cout << result << endl;
//	for (int i = 1; i <= v; i++)
//	{
//		cout << i << "->" << parent[i] << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}