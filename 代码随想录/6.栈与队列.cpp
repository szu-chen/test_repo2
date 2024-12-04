//#include<iostream>
//using namespace std;
//#include<string>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//
////3�ö���ʵ��ջ
//class Solution
//{
//public:
//	//����������
//	class myStack1
//	{
//	public:
//		queue<int> que1;
//		queue<int> que2;
//		myStack1()
//		{
//
//		}
//		//��ջ
//		void push(int x)
//		{
//			que1.push(x);
//		}
//
//		//��ջ
//		int pop()
//		{
//			if (que1.empty())
//			{
//				cout << "ջΪ�գ���ջʧ��" << endl;
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
//		//����ջ��Ԫ��
//		int top()
//		{
//			return que1.back();
//		}
//
//		//�п�
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
//		//��ջ
//		int push(int x)
//		{
//			que.push(x);
//		}
//
//		//��ջ
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
//		//����ջ��Ԫ��
//		int top()
//		{
//			return que.back();
//		}
//
//		//�п�
//		bool empty()
//		{
//			return que.empty();
//		}
//	};
//};
//
////4��Ч������
//class Solution4
//{
//public:
//	bool isValid(string s)
//	{
//		//����Ϊ������ֱ��ƥ��ʧ��
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
////5ɾ���ַ����е����������ظ���
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
////6�沨�����ʽ��ֵ����׺���ʽ��
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
////7�����������ֵ
//class Solution7
//{
//private:
//	class MyQueue//�����ݼ�����
//	{
//	public:
//		deque<int> que;
//		//����
//		void pop(int value)
//		{
//			if (!que.empty()&& value==que.front())
//			{
//				que.pop_front();
//			}
//		}
//		//���
//		void push(int value)
//		{
//			while (!que.empty()&& value > que.back())
//			{
//				que.pop_back();
//			}
//			que.push_back(value);
//		}
//		//��ȡ��ͷԪ��
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
//		//ǰk��Ԫ�����
//		for (int i = 0; i < k; i++)
//		{
//			que.push(nums[i]);
//		}
//		result.push_back(que.front());
//
//		//ʣ��Ԫ�����
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
////8ǰK����ƵԪ��
//class Solution8
//{
//public:
//	//С���ѷº���
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
//		//ͳ��Ԫ�س���Ƶ��
//		unordered_map<int, int> map;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			map[nums[i]]++;
//		}
//
//		//��Ƶ�ʽ�������
//		//����һ��С���ѣ���СΪk
//		priority_queue < pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
//		
//		//�ù̶���СΪk��С���ѣ�ɨ������Ƶ�ʵ�ֵ
//		for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
//		{
//			pri_que.push(*it);
//			if (pri_que.size() > k)
//			{
//				pri_que.pop();
//			}
//		}
//
//		//�ҳ�ǰK����ƵԪ�أ���ΪС�����ȵ���������С�ģ����Ե��������������
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