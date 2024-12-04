//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main()
//{
//
//	int n, m, s, t, v;
//	cin >> n >> m;
//	vector<vector<int>> grid;
//	while (m--)
//	{
//		cin >> s >> t >> v;
//		grid.push_back({ s,t,v });
//	}
//
//	vector<int> minDist(n + 1, INT_MAX);
//	minDist[1] = 0;
//
//	for (int i = 1; i < n; i++)
//	{
//		for (vector<int>& side : grid)
//		{
//			int from = side[0];
//			int to = side[1];
//			int price = side[2];
//			if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price)
//			{
//				minDist[to] = minDist[from] + price;
//			}
//		}
//		cout<<"第"<<i<<"次松弛"<< "minDist数组为："<<endl;
//		for (int a : minDist)
//		{
//			cout << a << " ";
//		}
//		cout << endl;
//	}
//
//	if (minDist[n] != INT_MAX)cout << minDist[n] << endl;
//	else cout << "unconnected" << endl;
//
//
//	system("pause");
//	return 0;
//}