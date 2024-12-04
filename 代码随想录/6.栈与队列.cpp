//#include<iostream>
//using namespace std;
//#include<string>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//
////3用队列实现栈
//class Solution
//{
//public:
//	//用两个队列
//	class myStack1
//	{
//	public:
//		queue<int> que1;
//		queue<int> que2;
//		myStack1()
//		{
//
//		}
//		//入栈
//		void push(int x)
//		{
//			que1.push(x);
//		}
//
//		//出栈
//		int pop()
//		{
//			if (que1.empty())
//			{
//				cout << "栈为空，出栈失败" << endl;
//				return -1;
//			}
//
//			int size = que1.size();
//			size--;
//			while (size--)
//			{
//				que2.push(que1.front());
//				que1.pop();
//			}
//
//			int result = que1.front();
//			que1.pop();
//
//			que1 = que2;
//			while (!que2.empty())
//			{
//				que2.pop();
//			}
//			return result;
//		}
//
//		//返回栈顶元素
//		int top()
//		{
//			return que1.back();
//		}
//
//		//判空
//		bool empty()
//		{
//			return que1.empty();
//		}
//	};
//	class myStack2
//	{
//	public:
//		queue<int> que;
//		myStack2()
//		{
//
//		}
//		//入栈
//		int push(int x)
//		{
//			que.push(x);
//		}
//
//		//出栈
//		int pop()
//		{
//			if (que.empty())
//			{
//				return -1;
//			}
//
//			int size = que.size();
//			size--;
//			while (size--)
//			{
//				que.push(que.front());
//				que.pop();
//			}
//
//			int result = que.front();
//			que.pop();
//			return result;
//		}
//
//		//返回栈顶元素
//		int top()
//		{
//			return que.back();
//		}
//
//		//判空
//		bool empty()
//		{
//			return que.empty();
//		}
//	};
//};
//
////4有效的括号
//class Solution4
//{
//public:
//	bool isValid(string s)
//	{
//		//括号为奇数，直接匹配失败
//		if (s.size()%2!=0)
//		{
//			return false;
//		}
//		stack<char> st;
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == '{')st.push('}');
//			else if (s[i] == '[')st.push(']');
//			else if (s[i] == '(')st.push(')');
//			else if (st.empty() || st.top() != s[i])return false;
//			else st.pop();
//		}
//		return st.empty();
//	}
//};
//
////5删除字符串中的所有相邻重复项
//class Solution5
//{
//public:
//	void myReverse(string &s)
//	{
//		int left = 0;
//		int right = s.size() - 1;
//		while (left<right)
//		{
//			char temp = s[left];
//			s[left] = s[right];
//			s[right] = temp;
//
//			left++;
//			right--;
//		}
//	}
//	string removeDuplicates(string s)
//	{
//		stack<char> st;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (st.empty() || s[i] != st.top())st.push(s[i]);
//			else st.pop();
//		}
//
//		string result = "";
//		while (!st.empty())
//		{
//			result.push_back(st.top());
//			st.pop();
//		}
//		myReverse(result);
//		return result;
//	}
//};
//
////6逆波兰表达式求值（后缀表达式）
//class Solution6
//{
//public:
//	int evalRPN(vector<string>& token)
//	{
//		stack<long long> st;
//		for (int i = 0; i < token.size(); i++)
//		{
//			if (token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/")
//			{
//				long long num2 = st.top();
//				st.pop();
//				long long num1 = st.top();
//				st.pop();
//				if (token[i] == "+") st.push(num1 + num2);
//				else if (token[i] == "-") st.push(num1 - num2);
//				else if (token[i] == "*") st.push(num1 * num2);
//				else st.push(num1 / num2);
//			}
//			else
//			{
//				st.push(stoll(token[i]));
//			}
//
//		}
//
//		int result = st.top();
//		st.pop();
//		return result;
//	}
//};
//
////7滑动窗口最大值
//class Solution7
//{
//private:
//	class MyQueue//单调递减队列
//	{
//	public:
//		deque<int> que;
//		//出队
//		void pop(int value)
//		{
//			if (!que.empty()&& value==que.front())
//			{
//				que.pop_front();
//			}
//		}
//		//入队
//		void push(int value)
//		{
//			while (!que.empty()&& value > que.back())
//			{
//				que.pop_back();
//			}
//			que.push_back(value);
//		}
//		//获取队头元素
//		int front()
//		{
//			return que.front();
//		}
//	};
//
//public:
//	vector<int> maxSlidingWindow(vector<int>& nums, int k)
//	{
//		MyQueue que;
//		vector<int> result;
//		//前k个元素入队
//		for (int i = 0; i < k; i++)
//		{
//			que.push(nums[i]);
//		}
//		result.push_back(que.front());
//
//		//剩余元素入队
//		for (int i = k; i < nums.size(); i++)
//		{
//			que.pop(nums[i - k]);
//			que.push(nums[i]);
//			result.push_back(que.front());
//		}
//
//		return result;
//	}
//
//};
//
////8前K个高频元素
//class Solution8
//{
//public:
//	//小顶堆仿函数
//	class mycomparison
//	{
//	public:
//		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
//		{
//			return lhs.second > rhs.second;
//		}
//	};
//	
//	vector<int> topFrequent(vector<int>& nums, int k)
//	{
//		//统计元素出现频率
//		unordered_map<int, int> map;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			map[nums[i]]++;
//		}
//
//		//对频率进行排序
//		//定义一个小顶堆，大小为k
//		priority_queue < pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
//		
//		//用固定大小为k的小顶堆，扫描所有频率的值
//		for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
//		{
//			pri_que.push(*it);
//			if (pri_que.size() > k)
//			{
//				pri_que.pop();
//			}
//		}
//
//		//找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
//		vector<int> result(k);
//		for (int i = k-1; i >= 0 ; i--)
//		{
//			result[i] = pri_que.top().first;
//			pri_que.pop();
//		}
//
//		return result;
//	}
//
//};
//
//int main()
//{
//
//
//	system("pause");
//	return 0;
//}