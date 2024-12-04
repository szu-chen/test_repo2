//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////1、移除元素
//class Solution1 
//{
//public:
//	int removeElement(vector<int>& nums, int val)
//	{
//		int slowIndex = 0;
//		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
//		{
//			if (nums[fastIndex]!=val)
//			{
//				nums[slowIndex++] = nums[fastIndex];
//			}
//		}
//		return slowIndex;
//	}
//};
//
////2、翻转字符串
//class Solution2
//{
//public:
//	void reverseStr(string& s)
//	{
//		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
//		{
//			char temp = s[i];
//			s[i] = s[j];
//			s[j] = temp;
//		}
//	}
//};
//
////3、替换数字
//class Solution3
//{
//public:
//	void substituteNumber()
//	{
//		string s;
//		while (cin>>s)
//		{
//			int sOldIndex = s.size() - 1;
//			int count = 0;
//
//			for (int i = 0; i < s.size(); i++)
//			{
//				if (s[i]>='0'&&s[i]<='9')
//				{
//					count++;
//				}
//			}
//
//			s.resize(s.size() + count * 5);
//			int sNewIndex = s.size() - 1;
//
//			while (sOldIndex>=0)
//			{
//				if (s[sOldIndex] >= '0' && s[sOldIndex] <= '9')
//				{
//					s[sNewIndex--] = 'r';
//					s[sNewIndex--] = 'e';
//					s[sNewIndex--] = 'b';
//					s[sNewIndex--] = 'm';
//					s[sNewIndex--] = 'u';
//					s[sNewIndex--] = 'n';
//				}
//				else
//				{
//					s[sNewIndex--] = s[sOldIndex];
//				}
//				sOldIndex--;
//			}
//			
//			cout << s << endl;
//		}
//	}
//};
//
////4、翻转字符串里的单词
//class Solution4
//{
//public:
//	void myreverse(string& s, int start, int end)
//	{
//		for (int i = start, j = end; i < j; i++, j--)
//		{
//			char temp = s[i];
//			s[i] = s[j];
//			s[j] = temp;
//		}
//	}
//
//	void removeExtraSpaces(string& s)
//	{
//		int slow = 0;
//		for (int fast = 0; fast < s.size(); fast++)
//		{
//			if (s[fast]!=' ')
//			{
//				if (slow != 0)s[slow++] = ' ';
//				while (fast<s.size() && s[fast]!=' ')
//				{
//					s[slow++] = s[fast++];
//				}
//			}
//		}
//		s.resize(slow);
//	}
//
//	string reverseWords(string& s)
//	{
//		removeExtraSpaces(s);
//		myreverse(s, 0, s.size() - 1);
//
//		int start = 0;
//		for (int i = 0; i <= s.size(); i++)
//		{
//			if (i == s.size()||s[i]==' ')
//			{
//				myreverse(s, start, i - 1);
//				start = i + 1;
//			}
//		}
//		return s;
//	}
//};
//
////5、翻转链表
//class Solution5
//{
//public:
//	struct ListNode
//	{
//		int data;
//		ListNode* next;
//	};
//
//	//双指针法
//	ListNode* reverseList(ListNode* head)
//	{
//		//初始化
//		ListNode* pre = NULL;
//		ListNode* cur = head;
//		ListNode* temp;
//
//		while (cur)
//		{
//			temp = cur->next;
//			cur->next = pre;
//			pre = cur;
//			cur = temp;
//		}
//		return pre;
//	}
//
//	//递归法
//	ListNode* reverse(ListNode* pre, ListNode* cur)
//	{
//		if (cur == NULL)return pre;//跳出递归的条件
//		ListNode* temp = cur->next;
//		cur->next = pre;
//		//pre = cur;
//		//cur = temp;
//		return reverse(cur, temp);
//	}
//	ListNode* reverseList2(ListNode*head)
//	{
//		return reverse(NULL, head);
//	}
//};
//
////6删除链表的倒数第N个结点
//class Solution6
//{
//public:
//	//创建结点
//	struct ListNode
//	{
//		ListNode(int data) :data(data), next(NULL) {};
//		int data;
//		ListNode* next;
//	};
//
//	//带头结点
//	ListNode* removeNthFromEnd(ListNode* head,int n)
//	{
//		ListNode* dummyhead = new ListNode(0);
//		dummyhead->next = head;
//		ListNode* slow = dummyhead;
//		ListNode* fast = dummyhead;
//		//fast先移动n+1位
//		while ((n--)+1&&fast!=NULL)
//		{
//			fast = fast->next;
//		}
//
//		while (fast!=NULL)
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//
//		ListNode* temp = slow->next;
//		slow->next = temp->next;
//		delete temp;
//
//		ListNode* newHead = dummyhead->next;
//		delete dummyhead;
//		return newHead;
//	}
//
//};
//
////7链表相交
//class Solution7
//{
//public:
//	//创建结点
//	struct ListNode
//	{
//		ListNode(int data) :data(data), next(NULL) {};
//		int data;
//		ListNode* next;
//	};
//
//	template<typename T>
//	void myswap(T& a,T& b)
//	{
//		T temp = a;
//		a = b;
//		b = temp;
//	}
//
//	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
//	{
//		if (headA || headB)
//		{
//			return NULL;
//		}
//		ListNode* curA = headA;
//		ListNode* curB = headB;
//		int lenA = 0;
//		int lenB = 0;
//		//求链表A长度
//		while (curA!=NULL)
//		{
//			lenA++;
//			curA = curA->next;
//		}
//		//求链表B长度
//		while (curB!=NULL)
//		{
//			lenB++; 
//			curB = curB->next;
//		}
//		//重置curA、curB
//		curA = headA;
//		curB = headB;
//		//保证lenA>lenB
//		if (lenB>lenA)
//		{
//			myswap(lenA, lenB);
//			myswap(curA, curB);
//		}
//		//求差值
//		int gap = lenA - lenB;
//		//移curA指针与curB对齐
//		while (gap--)
//		{
//			curA = curA->next;
//		}
//		//遍历链表
//		while (curA!=NULL)
//		{
//			if (curA==curB)//返回curA
//			{
//				return curA;
//			}
//			else//向后移
//			{
//				curA = curA->next;
//				curB = curB->next;
//			}
//		}
//		return NULL;
//	}
//};
//
////8环形链表2
//class Solution8
//{
//public:
//	//创建结点
//	struct ListNode
//	{
//		ListNode(int data) :data(data), next(NULL) {};
//		int data;
//		ListNode* next;
//	};
//
//	ListNode* detectCycle(ListNode* head)
//	{
//		ListNode* slow = head;
//		ListNode* fast = head;
//		while (fast!=NULL && fast->next!=NULL)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//
//			//寻找环入口
//			if (slow == fast)
//			{
//				ListNode* index1 = fast;
//				ListNode* index2 = head;
//				while (index1!=index2)
//				{
//					index1 = index1->next;
//					index2 = index2->next;
//				}
//				return index2;
//			}
//		}
//		return NULL;
//	}
//};
//
////9三数之和
//class Solution9
//{
//public:
//
//};
//
////10四数之和
//class Solution10
//{
//public:
//
//};
//
//int main()
//{
//	Solution4 s4;
//	string s = "number is two";
//	s4.reverseWords(s);
//	cout << s << endl;
//
//
//	system("pause");
//	return 0;
//}