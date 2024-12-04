//#include<iostream>
//using namespace std;
//
////2移除链表元素
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
//	//不带头结点
//	ListNode* removeElement1(int val, LinkList& L)
//	{
//		while (L!=NULL && L->data == val)//处理头结点
//		{
//			ListNode* temp = L;
//			L = L->next;
//			delete temp;
//		}
//		
//		ListNode* current = L;
//		while (current!=NULL && current->next!=NULL)//处理非头结点
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
//	//带头结点
//	ListNode* removeElement2(int val, LinkList& L)
//	{
//		//new一个虚拟头结点
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
//		L = dummyhead->next;//更新头结点
//		delete dummyhead;
//		return L;
//	}
//};
//
////3设计链表---增删查
//class Solution3
//{
//public:
//	//定义链表结点结构体
//	struct LinkNode
//	{
//		int data;
//		LinkNode* next;
//		LinkNode(int x) :data(x), next(NULL) {};//初始化列表初始化
//	};
//	
//	//初始化链表
//	Solution3()
//	{
//		_dummyhead = new LinkNode(0);
//		_size = 0;
//	}
//
//	// 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
//	int get_data(int index)
//	{
//		if (index<0 || index> _size-1)
//		{
//			return -1;
//		}
//		LinkNode* current = _dummyhead->next;
//		while (index--)//定位
//		{
//			current = current->next;
//		}
//		return current->data;
//	}
//
//	//头插法
//	void add_At_Head(int val)
//	{
//		LinkNode* p = new LinkNode(val);
//		p->next = _dummyhead->next;
//		_dummyhead->next = p;
//		_size++;
//	}
//
//	//尾插法
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
//	//指定位置插入
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
//	// // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
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
//	//打印链表
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
////4翻转链表
//class Solution4
//{
//public:
//	//定义链表节点结构体 
//	struct ListNode
//	{
//		int data;
//		ListNode* next;
//		ListNode(int x) :data(x), next(NULL) {};
//	};
//	typedef ListNode* LinkList;
//
//	//双指针法
//	ListNode* reverseList1(LinkList head)
//	{
//		ListNode* temp(0);
//		ListNode* pre = NULL;
//		ListNode* cur = head;
//		while (cur!=NULL)
//		{
//			//前两步先改变指向
//			temp = cur->next;
//			cur->next = pre;
//			//后两步更新pre和cur，先移动pre再移动cur
//			pre = cur;
//			cur = temp;
//		}
//		return pre;
//	}
//
//	//递归法--向后
//	ListNode* reverse(ListNode* pre, ListNode* cur)
//	{
//		if (cur==NULL)
//		{
//			return pre;
//		}
//		ListNode* temp = cur->next;
//		cur->next = pre;
//		// 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
//		// pre = cur;
//		// cur = temp;
//		return reverse(cur, temp);
//	}
//
//	ListNode* reverseList2(ListNode* head)
//	{
//		// 和双指针法初始化是一样的逻辑
//		// ListNode* cur = head;
//		// ListNode* pre = NULL;
//		return reverse(NULL, head);
//	}
//
//	//递归法--向前
//
//};
//
////5两两交换链表中的节点
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
//	//两两交换函数
//	ListNode* swapPairs(LinkList head)
//	{
//		//开辟虚拟头结点
//		ListNode* dummyhead = new ListNode(0);
//		dummyhead->next = head;
//		ListNode* cur = dummyhead;
//
//		while (cur->next!=NULL && cur->next->next!=NULL)
//		{
//			//定义临时结点
//			ListNode* temp1 = cur->next;
//			ListNode* temp2 = cur->next->next->next;
//
//			//交换
//			cur->next = cur->next->next;
//			cur->next->next = temp1;
//			cur->next->next->next = temp2;
//			
//			//更新指针
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
////6删除链表的倒数第N个结点
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
//		//双指针法
//		ListNode* delete_back_N(ListNode* head, int n)
//		{
//			ListNode* dummyhead = new ListNode(0);
//			dummyhead->next = head;
//			ListNode* slow =  dummyhead;
//			ListNode* fast = dummyhead;
//
//			//fast先移n个位置
//			while (n && fast)
//			{
//				fast = fast->next;
//				n--;
//			}
//
//			//寻找倒数n+1的位置slow
//			while (fast != NULL && fast->next!=NULL )
//			{
//				fast = fast->next;
//				slow = slow->next;
//			}
//			
//			//删除操作
//			ListNode* temp = slow->next;
//			if (temp!=NULL)
//			{
//				slow->next = temp->next;
//				delete temp;
//			}
//
//			//开辟一个临时变量result保存dummyhead->next;
//			ListNode* result = dummyhead->next;
//			delete dummyhead;
//
//			return result;
//		}
//};
//
////7链表相交
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
//		//求len1
//		while (cur1!=NULL)
//		{
//			cur1 = cur1->next;
//			len1++;
//		}
//		//求len2
//		while (cur2!=NULL)
//		{
//			cur2 = cur2->next;
//			len2++;
//		}
//		//重置cur1，cur2
//		cur1 = head1;
//		cur2 = head2;
//		//使len1大
//		if (len2>len1)
//		{
//			swap(len1, len2);
//			swap(cur1, cur2);
//		}
//		//计算差值
//		int gap = len1 - len2;
//		//挪到与cur2相同起点
//		while (gap--)
//		{
//			cur1 - cur1->next;
//		}
//		//遍历，判断cur1与cur2是否相等
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
////8环形链表2
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