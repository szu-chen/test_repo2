//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main()
//{
//	int n, m, s, t, v, source, destination, k;
//	cin >> n >> m;
//	vector<vector<int>> grid;
//	while (m--)
//	{
//		cin >> s >> t >> v;
//		grid.push_back({ s,t,v });
//	}
//	cin >> source >> destination >> k;
//	vector<int> minDist(n + 1,INT_MAX);
//	minDist[source] = 0;
//
//	vector<int> minDist_copy(n + 1, INT_MAX);//������¼��һ�α�����minDist����Ľ��
//	for (int i = 1; i <= k + 1; i++)
//	{
//		minDist_copy = minDist;//��ȡ��һ�μ���Ľ��
//		for (vector<int>& side: grid)
//		{
//			int from = side[0];
//			int to = side[1];
//			int price = side[2];
//			if (minDist_copy[from] != INT_MAX && minDist[to] > minDist_copy[from] + price)
//			{
//				minDist[to] = minDist_copy[from] + price;
//			}
//		}
//		cout << "��" << i << "���ɳڣ�minDist����Ϊ��" << endl;
//		for (int& a : minDist)
//		{
//			cout << a << " ";
//		}
//		cout << endl;
//	}
//	if (minDist[destination] == INT_MAX)cout << "unreachable" << endl;
//	else cout << minDist[destination] << endl;
//
//
//	system("pause");
//	return 0;
//}