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
//class myCompare
//{
//public:
//	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
//	{
//		return a.second > b.second;
//	}
//};
//
//int main()
//{
//	int n, m, p1, p2, val;
//	cin >> n >> m;
//	vector<list<Edge>> grid(n + 1);
//	while (m--)
//	{
//		cin >> p1 >> p2 >> val;
//		grid[p1].push_back(Edge(p2, val));
//	}
//
//	//建立minDist数组
//	vector<int> minDist(n + 1, INT_MAX);
//	vector<bool> visited(n + 1, false);
//	priority_queue < pair<int, int>, vector<pair<int, int>>, myCompare> pq;
//
//	//初始化
//	minDist[1] = 0;
//	pq.push(pair<int, int>(1, 0));
//
//	while (!pq.empty())
//	{
//		//priority_queue < pair<int, int>, vector<pair<int, int>>, myCompare> pqq = pq;
//		//while (!pqq.empty())
//		//{
//		//	pair<int, int> curr = pqq.top();
//		//	pqq.pop();
//		//	cout << curr.first << " " << curr.second << endl;
//		//}
//		//cout << "---------------------" << endl;
//		pair<int, int> cur = pq.top();
//		pq.pop();
//
//		//if (visited[cur.first])continue;
//		visited[cur.first] = true;
//
//		for (Edge edge : grid[cur.first])
//		{
//			if (!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to])
//			{
//				minDist[edge.to] = minDist[cur.first] + edge.val;
//				pq.push(pair<int, int>(edge.to, minDist[edge.to]));
//
//			}
//		}
//	}
//
//	if (minDist[n] != INT_MAX)cout << minDist[n] << endl;
//	else cout << -1 << endl;
//
//
//	system("pause");
//	return 0;
//}
