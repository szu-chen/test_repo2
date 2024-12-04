//#include<iostream>
//#include<vector>
//#include<list>
//#include<queue>
//#include<climits>
//using namespace std;
//
//struct Edge
//{
//	int to;
//	int val;
//	Edge(int u, int v) :to(u), val(v) {};
//};
//
//
//int main()
//{
//	int n, m, s, t, v;
//	cin >> n >> m;
//	vector<list<Edge>> grid(n + 1);
//	while (m--)
//	{
//		cin >> s >> t >> v;
//		grid[s].push_back(Edge(t, v));
//	}
//
//	vector<int> minDist(n + 1, INT_MAX);
//	minDist[1] = 0;
//	vector<bool> isInQueue(n + 1, false);
//
//	queue<int> que;
//	que.push(1);
//
//	while (!que.empty())
//	{
//		int node = que.front();
//		que.pop();
//		isInQueue[node] = false;
//		for (Edge edge : grid[node])
//		{
//			int from = node;
//			int to = edge.to;
//			int value = edge.val;
//			if (minDist[to] > minDist[from] + value)
//			{
//				minDist[to] = minDist[from] + value;
//				if (isInQueue[to] == false)
//				{
//					que.push(to);
//					isInQueue[to] = true;
//				}
//			}
//		}
//	}
//	if (minDist[n] == INT_MAX)cout << "unconnected" << endl;
//	else cout << minDist[n] << endl;
//
//
//	system("pause");
//	return 0;
//}