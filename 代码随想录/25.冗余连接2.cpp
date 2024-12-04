//#include<iostream>
//#include<vector>
//using namespace std;
//
//int n;
//vector<int> father(1001, 0);
//void init()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		father[i] = i;
//	}
//}
//
//int find(int u)
//{
//	return father[u] == u ? u : father[u] = find(father[u]);
//}
//
//bool isSame(int u, int v)
//{
//	u = find(u);
//	v = find(v);
//	return u == v;
//}
//
//void join(int u, int v)
//{
//	u = find(u);
//	v = find(v);
//	if (u == v)return;
//	father[v] = u;
//}
//
//bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge)
//{
//	init();
//	for (int i = 0; i < n; i++)
//	{
//		if (i == deleteEdge)continue;
//		if (isSame(edges[i][0], edges[i][1]))return false;
//		else
//		{
//			join(edges[i][0], edges[i][1]);
//		}
//	}
//	return true;
//}
//
//void getRemoveEdge(const vector<vector<int>>& edges)
//{
//	init();
//	for (int i = 0; i < n; i++)
//	{
//		if (isSame(edges[i][0], edges[i][1]))
//		{
//			cout << edges[i][0] << " " << edges[i][1] << endl;
//			return;
//		}
//		else
//		{
//			join(edges[i][0], edges[i][1]);
//		}
//	}
//}
//
//
//int main()
//{
//	int s, t;
//	vector<vector<int>> edges;
//	cin >> n;
//	vector<int> inDegree(n + 1, 0);
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s >> t;
//		inDegree[t]++;
//		edges.push_back({ s,t });
//	}
//
//	vector<int> vec;
//	for (int i = n - 1; i >= 0; i--)
//	{
//		if (inDegree[edges[i][1]] == 2)
//		{
//			vec.push_back(i);
//		}
//	}
//	if (vec.size() > 0)
//	{
//		if (isTreeAfterRemoveEdge(edges, vec[0]))
//		{
//			cout << edges[vec[0]][0] << " " << edges[vec[1]][1] << endl;
//			system("pause");
//			return 0;
//		}
//		else
//		{
//			cout << edges[vec[1]][0] << " " << edges[vec[1]][1] << endl;
//			system("pause");
//			return 0;
//		}
//	}
//		
//	getRemoveEdge(edges);
//	system("pause");
//	return 0;
//}