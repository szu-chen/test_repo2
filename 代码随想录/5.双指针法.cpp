//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////1���Ƴ�Ԫ��
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
////2����ת�ַ���
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
////3���滻����
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
////4����ת�ַ�����ĵ���
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
////5����ת����
//class Solution5
//{
//public:
//	struct ListNode
//	{
//		int data;
//		ListNode* next;
//	};
//
//	//˫ָ�뷨
//	ListNode* reverseList(ListNode* head)
//	{
//		//��ʼ��
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
//	//�ݹ鷨
//	ListNode* reverse(ListNode* pre, ListNode* cur)
//	{
//		if (cur == NULL)return pre;//�����ݹ������
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
////6ɾ������ĵ�����N�����
//class Solution6
//{
//public:
//	//�������
//	struct ListNode
//	{
//		ListNode(int data) :data(data), next(NULL) {};
//		int data;
//		ListNode* next;
//	};
//
//	//��ͷ���
//	ListNode* removeNthFromEnd(ListNode* head,int n)
//	{
//		ListNode* dummyhead = new ListNode(0);
//		dummyhead->next = head;
//		ListNode* slow = dummyhead;
//		ListNode* fast = dummyhead;
//		//fast���ƶ�n+1λ
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
////7�����ཻ
//class Solution7
//{
//public:
//	//�������
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
//		//������A����
//		while (curA!=NULL)
//		{
//			lenA++;
//			curA = curA->next;
//		}
//		//������B����
//		while (curB!=NULL)
//		{
//			lenB++; 
//			curB = curB->next;
//		}
//		//����curA��curB
//		curA = headA;
//		curB = headB;
//		//��֤lenA>lenB
//		if (lenB>lenA)
//		{
//			myswap(lenA, lenB);
//			myswap(curA, curB);
//		}
//		//���ֵ
//		int gap = lenA - lenB;
//		//��curAָ����curB����
//		while (gap--)
//		{
//			curA = curA->next;
//		}
//		//��������
//		while (curA!=NULL)
//		{
//			if (curA==curB)//����curA
//			{
//				return curA;
//			}
//			else//�����
//			{
//				curA = curA->next;
//				curB = curB->next;
//			}
//		}
//		return NULL;
//	}
//};
//
////8��������2
//class Solution8
//{
//public:
//	//�������
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
//			//Ѱ�һ����
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
////9����֮��
//class Solution9
//{
//public:
//
//};
//
////10����֮��
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