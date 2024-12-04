#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int dir[8][2] = { 2,1,1,2,-1,2,-2,1,-2,-1,-1,-2,1,-2,2,-1 };
int moves[1001][1001];
int b1, b2;

struct Knight 
{
	int x, y; 
	int g, h, f; 
	bool operator < (const Knight& k) const 
	{
		return f>k.f; // 重载为从小到大排序 
	} 
};
priority_queue<Knight> que;


int Heuristic(const Knight& k)
{
	return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
}

void a_star(const Knight&k)
{
	que.push(k);
	Knight cur, next;
	while (!que.empty())
	{
		cur = que.top(); que.pop();
		if (cur.x == b1 && cur.y == b2) break;
		for (int i = 0; i < 8; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x < 1 || next.x>1000 || next.y < 1 || next.y>1000)continue;
			if (!moves[next.x][next.y])
			{
				moves[next.x][next.y] = moves[cur.x][cur.y] + 1;
				next.g = cur.g + 5;
				next.h = Heuristic(next);
				next.f = next.g + next.h;
				que.push(next);
			}
		}
	}
}


int main()
{
	int n, a1, a2;
	cin >> n;
	while (n--)
	{
		cin >> a1 >> a2 >> b1 >> b2;
		memset(moves, 0, sizeof(moves));
		Knight start;
		start.x = a1;
		start.y = a2;
		start.g = 0;
		start.h = Heuristic(start);
		start.f = start.g + start.h;	
		a_star(start);
		while (!que.empty())que.pop();
		cout << moves[b1][b2] << endl;
	}

	system("pause");
	return 0;
}
