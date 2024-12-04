//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct Edge
//{
//	int l, r, val;
//};
//
//class myCompare
//{
//public:
//	bool operator()(Edge a, Edge b)
//	{
//		return a.val < b.val;
//	}
//};
//
//int n = 10001;
//vector<int> father(10001, -1);
//
//void init()
//{
//	for (int i = 1; i < n; i++)
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
//
//int main()
//{
//	int v, e, v1, v2, val;
//	cin >> v >> e;
//	vector<Edge> edges;
//	while (e--)
//	{
//		cin >> v1 >> v2 >> val;
//		edges.push_back({ v1,v2,val });
//	}
//
//	int result_val = 0;
//	vector<Edge> result;
//
//	//排序
//	sort(edges.begin(), edges.end(), myCompare());
//
//
//	init();
//	//遍历每一条边
//	for (Edge edge : edges)
//	{
//		if (isSame(edge.l, edge.r))continue;
//		result.push_back(edge);
//		join(edge.l, edge.r);
//		result_val += edge.val;
//	}
//	cout << result_val << endl;
//	
//	for (Edge edge : result)
//	{
//		cout << edge.l << "-" << edge.r << ":" << edge.val << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}
