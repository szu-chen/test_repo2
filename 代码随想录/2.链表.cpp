//#include<iostream>
//using namespace std;
//
////2�Ƴ�����Ԫ��
//class Solution2
//{
//public:
//	struct ListNode
//	{
//		int data;
//		ListNode* next;
//		ListNode(int x) :data(x), next(NULL) {};
//	};
//	typedef ListNode* LinkList;
//
//	//����ͷ���
//	ListNode* removeElement1(int val, LinkList& L)
//	{
//		while (L!=NULL && L->data == val)//����ͷ���
//		{
//			ListNode* temp = L;
//			L = L->next;
//			delete temp;
//		}
//		
//		ListNode* current = L;
//		while (current!=NULL && current->next!=NULL)//�����ͷ���
//		{
//			if (current->next->data == val)
//			{
//				ListNode* temp = current->next;
//				current->next = temp->next;
//				delete temp;
//			}
//			else
//			{
//				current = current->next;
//			}
//		}
//		return L;
//	}
//
//	//��ͷ���
//	ListNode* removeElement2(int val, LinkList& L)
//	{
//		//newһ������ͷ���
//		ListNode* dummyhead = new ListNode(0);
//		dummyhead->next = L;
//
//		ListNode* current = dummyhead;
//		while (current->next!=NULL)
//		{
//			if (current->next->data == val)
//			{
//				ListNode* temp = current->next;
//				current->next = temp->next;
//				delete temp;
//			}
//			else
//			{
//				current = current->next;
//			}
//		}
//		L = dummyhead->next;//����ͷ���
//		delete dummyhead;
//		return L;
//	}
//};
//
////3�������---��ɾ��
//class Solution3
//{
//public:
//	//����������ṹ��
//	struct LinkNode
//	{
//		int data;
//		LinkNode* next;
//		LinkNode(int x) :data(x), next(NULL) {};//��ʼ���б��ʼ��
//	};
//	
//	//��ʼ������
//	Solution3()
//	{
//		_dummyhead = new LinkNode(0);
//		_size = 0;
//	}
//
//	// ��ȡ����index���ڵ���ֵ�����index�ǷǷ���ֱֵ�ӷ���-1�� ע��index�Ǵ�0��ʼ�ģ���0���ڵ����ͷ���
//	int get_data(int index)
//	{
//		if (index<0 || index> _size-1)
//		{
//			return -1;
//		}
//		LinkNode* current = _dummyhead->next;
//		while (index--)//��λ
//		{
//			current = current->next;
//		}
//		return current->data;
//	}
//
//	//ͷ�巨
//	void add_At_Head(int val)
//	{
//		LinkNode* p = new LinkNode(val);
//		p->next = _dummyhead->next;
//		_dummyhead->next = p;
//		_size++;
//	}
//
//	//β�巨
//	void add_At_Tail(int val)
//	{
//		LinkNode* current = _dummyhead;
//		while (current->next!=NULL)
//		{
//			current = current->next;
//		}
//
//		LinkNode* p = new LinkNode(val);
//		p->next = NULL;
//		current->next = p;
//		_size++;
//	}
//
//	//ָ��λ�ò���
//	void add_At_Index(int val, int index)
//	{
//		if (index>_size)
//		{
//			return;
//		}
//		if (index<0)
//		{
//			index = 0;
//		}
//		LinkNode* p = new LinkNode(val);
//		LinkNode* current = _dummyhead;
//		while (index--)
//		{
//			current = current->next;
//		}
//		p->next = current->next;
//		current->next = p;
//		_size++;
//	}
//
//	// // ɾ����index���ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
//	void Delete_At_Index(int index,int& val)
//	{
//		if (index>=_size||index<0)
//		{
//			return;
//		}
//		LinkNode* current = _dummyhead;
//		while (index--)
//		{
//			current = current->next;
//		}
//		LinkNode* p = current->next;
//		val = p->data;
//		current->next = p->next;
//		delete p;
//		p = NULL;
//		_size--;
//	}
//
//	//��ӡ����
//	void printLinkList()
//	{
//		LinkNode* current = _dummyhead;
//		while (current->next!=NULL)
//		{
//			cout << current->next->data << " ";
//			current = current->next;
//		}
//		cout << endl;
//	}
//
//private:
//	int _size;
//	LinkNode* _dummyhead;
//};
//
////4��ת����
//class Solution4
//{
//public:
//	//��������ڵ�ṹ�� 
//	struct ListNode
//	{
//		int data;
//		ListNode* next;
//		ListNode(int x) :data(x), next(NULL) {};
//	};
//	typedef ListNode* LinkList;
//
//	//˫ָ�뷨
//	ListNode* reverseList1(LinkList head)
//	{
//		ListNode* temp(0);
//		ListNode* pre = NULL;
//		ListNode* cur = head;
//		while (cur!=NULL)
//		{
//			//ǰ�����ȸı�ָ��
//			temp = cur->next;
//			cur->next = pre;
//			//����������pre��cur�����ƶ�pre���ƶ�cur
//			pre = cur;
//			cur = temp;
//		}
//		return pre;
//	}
//
//	//�ݹ鷨--���
//	ListNode* reverse(ListNode* pre, ListNode* cur)
//	{
//		if (cur==NULL)
//		{
//			return pre;
//		}
//		ListNode* temp = cur->next;
//		cur->next = pre;
//		// ���Ժ�˫ָ�뷨�Ĵ�����жԱȣ����µݹ��д������ʵ��������������
//		// pre = cur;
//		// cur = temp;
//		return reverse(cur, temp);
//	}
//
//	ListNode* reverseList2(ListNode* head)
//	{
//		// ��˫ָ�뷨��ʼ����һ�����߼�
//		// ListNode* cur = head;
//		// ListNode* pre = NULL;
//		return reverse(NULL, head);
//	}
//
//	//�ݹ鷨--��ǰ
//
//};
//
////5�������������еĽڵ�
//class Solution5
//{
//public:
//	struct ListNode
//	{
//		int data;
//		ListNode* next;
//		ListNode(int x) :data(x), next(NULL) {};
//	};
//	typedef ListNode* LinkList;
//
//	//������������
//	ListNode* swapPairs(LinkList head)
//	{
//		//��������ͷ���
//		ListNode* dummyhead = new ListNode(0);
//		dummyhead->next = head;
//		ListNode* cur = dummyhead;
//
//		while (cur->next!=NULL && cur->next->next!=NULL)
//		{
//			//������ʱ���
//			ListNode* temp1 = cur->next;
//			ListNode* temp2 = cur->next->next->next;
//
//			//����
//			cur->next = cur->next->next;
//			cur->next->next = temp1;
//			cur->next->next->next = temp2;
//			
//			//����ָ��
//			cur = cur->next->next;
//		}
//		ListNode* result = dummyhead->next;
//		delete dummyhead;
//		dummyhead = NULL;
//		return result;
//
//	}
//};
//
////6ɾ������ĵ�����N�����
//class Solution6
//{
//	public:
//		struct ListNode
//		{
//			int data;
//			ListNode* next;
//			ListNode(int x) :data(x), next(NULL) {};
//		};
//
//		//˫ָ�뷨
//		ListNode* delete_back_N(ListNode* head, int n)
//		{
//			ListNode* dummyhead = new ListNode(0);
//			dummyhead->next = head;
//			ListNode* slow =  dummyhead;
//			ListNode* fast = dummyhead;
//
//			//fast����n��λ��
//			while (n && fast)
//			{
//				fast = fast->next;
//				n--;
//			}
//
//			//Ѱ�ҵ���n+1��λ��slow
//			while (fast != NULL && fast->next!=NULL )
//			{
//				fast = fast->next;
//				slow = slow->next;
//			}
//			
//			//ɾ������
//			ListNode* temp = slow->next;
//			if (temp!=NULL)
//			{
//				slow->next = temp->next;
//				delete temp;
//			}
//
//			//����һ����ʱ����result����dummyhead->next;
//			ListNode* result = dummyhead->next;
//			delete dummyhead;
//
//			return result;
//		}
//};
//
////7�����ཻ
//class Soluton7
//{
//public:
//	struct ListNode
//	{
//		int data;
//		ListNode* next;
//		ListNode(int x) :data(x), next(NULL) {};
//	};
//
//	ListNode* get_Intersection_Node(ListNode* head1, ListNode* head2)
//	{
//		ListNode* cur1 = head1;
//		ListNode* cur2 = head2;
//		int len1 = 0;
//		int len2 = 0;
//		//��len1
//		while (cur1!=NULL)
//		{
//			cur1 = cur1->next;
//			len1++;
//		}
//		//��len2
//		while (cur2!=NULL)
//		{
//			cur2 = cur2->next;
//			len2++;
//		}
//		//����cur1��cur2
//		cur1 = head1;
//		cur2 = head2;
//		//ʹlen1��
//		if (len2>len1)
//		{
//			swap(len1, len2);
//			swap(cur1, cur2);
//		}
//		//�����ֵ
//		int gap = len1 - len2;
//		//Ų����cur2��ͬ���
//		while (gap--)
//		{
//			cur1 - cur1->next;
//		}
//		//�������ж�cur1��cur2�Ƿ����
//		while (cur1!=NULL && cur2!=NULL)
//		{
//			if (cur1 == cur2)
//			{
//				return cur1;
//			}
//			cur1 = cur1->next;
//			cur2 = cur2->next;
//		}
//		return NULL;
//	}
//};
//
////8��������2
//class Solution8
//{
//public:
//	struct ListNode
//	{
//		int data;
//		ListNode* next;
//		ListNode(int x) :data(x), next(NULL) {};
//	};
//
//	ListNode* detectCycle(ListNode* head)
//	{
//		ListNode* slow = head;
//		ListNode* fast = head;
//
//		while (fast != NULL && fast->next != NULL)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//			
//			if (slow==fast)
//			{
//				ListNode* index1 = head;
//				ListNode* index2 = fast;
//
//				while (index1!=index2)
//				{
//					index1 = index1->next;
//					index2 = index2->next;
//				}
//				return index1;
//			}
//		}
//		return NULL;
//	}
//};
//
//
//int main()
//{
//	system("pause");
//	return 0;
//}