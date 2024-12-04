//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<deque>
//#include<stack>
//#include<queue>
//#include<string>
//
//
////3������
//class Solutin3
//{
//public:
//	//������������
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//ǰ�����
//	class Solution1
//	{
//	public:
//		vector<int> preorderTraversal(TreeNode* root)
//		{
//			stack<TreeNode*> st;
//			vector<int> result;
//			if (root == NULL)//�ս�㲻��ջ
//			{
//				return result;
//			}
//			st.push(root);
//
//			while (!st.empty())
//			{
//				TreeNode* node = st.top();
//				st.pop();
//				result.push_back(node->val);//��
//				if (node->right)st.push(node->right);//��
//				if (node->left)st.push(node->left);	//��
//			}
//
//			return result;
//		}
//	};
//
//	class Solution2
//	{
//	public:
//		//�������
//		vector<int> inorderTraversal(TreeNode* root)
//		{
//			stack<TreeNode*> st;
//			vector<int> result;
//			TreeNode* cur = root;
//
//			while (cur!=NULL ||!st.empty())
//			{
//				if (cur!=NULL)
//				{
//					st.push(cur);
//					cur = cur->left;
//				}
//				else
//				{
//					cur = st.top();
//					st.pop();
//					result.push_back(cur->val);
//					cur = cur->right;
//				}
//			}
//
//			return result;
//		}
//	};
//
//	class Solution3
//	{
//	public:
//		//�������
//		vector<int> postorderTraversal(TreeNode* root)
//		{
//			stack<TreeNode*> st;
//			vector<int> result;
//			if (root==NULL)
//			{
//				return result;
//			}
//			while (!st.empty())
//			{
//				TreeNode* node = st.top();
//				st.pop();
//				result.push_back(node->val);
//				if (node->left)st.push(node->left);
//				if (node->right)st.push(node->right);
//			}
//			reverse(result.begin(), result.end());
//			return result;
//		}
//	};
//
//};
//
////4ͳһ������
//class Solution4
//{
//public:
//	//������������
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//�������
//	vector<int> inorderTraversal(TreeNode* root)
//	{
//		stack<TreeNode*> st;
//		vector<int> result;
//		if (root != NULL)st.push(root);
//		while (!st.empty())
//		{
//			TreeNode* node = st.top();
//			if (node!=NULL)
//			{
//				st.pop();//�����ظ�
//				if (node->right)st.push(node->right);//��
//
//				st.push(node);//��
//				st.push(NULL);
//
//				if (node->left)st.push(node->left);//��
//			}
//			else
//			{
//				st.pop();
//				node = st.top();
//				st.pop();
//				result.push_back(node->val);
//			}
//		}
//		return result;
//	}
//
//	//ǰ�����
//	vector<int> preorderTraversal(TreeNode* root)
//	{
//		stack<TreeNode*> st;
//		vector<int> result;
//		if (root != NULL)st.push(root);
//		while (!st.empty())
//		{
//			TreeNode* node = st.top();
//			if (node!=NULL)
//			{
//				st.pop();
//
//				if (node->right)st.push(node->right);
//
//				if (node->left)st.push(node->left);
//
//				st.push(node);
//				st.push(NULL);
//			}
//			else
//			{
//				st.pop();
//				node = st.top();
//				st.pop();
//				result.push_back(node->val);
//			}
//		}
//		return result;
//	}
//	//�������
//	vector<int> postorderTraversal(TreeNode* root)
//	{
//		stack<TreeNode*> st;
//		vector<int> result;
//		if (root != NULL)st.push(root);
//		while (!st.empty())
//		{
//			TreeNode* node = st.top();
//			if (node != NULL)
//			{
//				st.pop();
//				st.push(node);//��
//				st.push(NULL);
//				if (node->right)st.push(node->right);//��
//				if (node->left)st.push(node->left);//��
//			}
//			else
//			{
//				st.pop();
//				node = st.top();
//				st.pop();
//				result.push_back(node->val);
//			}
//		}
//		return result;
//	}
//};
////5�������
//class Solution5
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//���淨
//	vector<vector<int>> levelOrder(TreeNode* root)
//	{
//		queue<TreeNode*> que;
//		if (root != NULL)que.push(root);
//		vector<vector<int>> result;
//		while (!que.empty())
//		{
//			int size = que.size();
//			vector<int> vec;
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				vec.push_back(node->val);
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//			result.push_back(vec);
//		}
//		return result;
//	}
//	//�ݹ鷨
//	void order(TreeNode* cur, vector<vector<int>>& result, int depth)
//	{
//		if (cur == NULL)return;
//		if (result.size() == depth)result.push_back(vector<int>());
//		result[depth].push_back(cur->val);
//		order(cur->left, result, depth + 1);
//		order(cur->right, result, depth + 1);
//	}
//	vector<vector<int>> levelOrder2(TreeNode* root)
//	{
//		vector<vector<int>> result;
//		int depth = 0;
//		order(root, result, depth);
//		return result;
//	}
//
//	//�������Ĳ������2
//	void myReverse(vector<vector<int>>& result)
//	{
//		int left = 0;
//		int right = result.size() - 1;
//		while (left<right)
//		{
//			vector<int> temp = result[left];
//			result[left] = result[right];
//			result[right] = temp;
//
//			left++;
//			right--;
//		}
//	}
//	vector<vector<int>> leverOrderBottom(TreeNode* root)
//	{
//		queue<TreeNode*> que;
//		if (root != NULL)que.push(root);
//		vector<vector<int>> result;
//		while (!que.empty())
//		{
//			int size = que.size();
//			vector<int> vec;
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				vec.push_back(node->val);
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//			result.push_back(vec);
//		}
//		//reverse(result.begin(), result.end());
//		myReverse(result);
//		return result;
//	}
//	//������������ͼ
//	vector<int> rightSideView(TreeNode* root)
//	{
//		queue<TreeNode*> que;
//		if (root)que.push(root);
//		vector<int> result;
//		while (!que.empty())
//		{
//			int size = que.size();
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				if (i == size - 1)result.push_back(node->val);
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//		}
//		return result;
//	}
//
//	//�������Ĳ�ƽ��ֵ
//	vector<double> averageOfLevels(TreeNode* root)
//	{
//		queue<TreeNode*> que;
//		vector<double> result;
//		if (root)que.push(root);
//		while (!que.empty())
//		{
//			int size = que.size();
//			double sum = 0;
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				sum += node->val;
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//			result.push_back(sum / size);
//		}
//		return result;
//	}
//
//	//N�����Ĳ������
//	struct Node
//	{
//		int val;
//		vector<Node*> children;
//		Node(int x, vector<Node*> _children) :val(x), children(_children) {};
//	};
//	vector<vector<int>> levelOrderOfN_tree(Node*root)
//	{
//		queue<Node*> que;
//		if (root)que.push(root);
//		vector<vector<int>> result;
//		while (!que.empty())
//		{
//			int size = que.size();
//			vector<int> vec;
//			for (int i = 0; i < size; i++)
//			{
//				Node* node = que.front();
//				que.pop();
//				vec.push_back(node->val);
//				for (int j = 0; j < node->children.size(); j++)
//				{
//					if (node->children[j])que.push(node->children[j]);
//				}
//			}
//			result.push_back(vec);
//		}
//		return result;
//	}
//
//	//��ÿһ�������������ֵ
//	vector<int> largestValues(TreeNode* root)
//	{
//		queue<TreeNode*> que;
//		if (root)que.push(root);
//		vector<int> result;
//		while (!que.empty())
//		{
//			int size = que.size();
//			int maxValue = INT_MIN;
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				maxValue = node->val > maxValue ? node->val : maxValue;
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//			result.push_back(maxValue);
//		}
//		return result;
//	}
//
//	//���ÿһ���ڵ����һ���Ҳ�ڵ�ָ��
//	struct Node1
//	{
//		int val;
//		Node1* left;
//		Node1* right;
//		Node1* next;
//	};
//	Node1* connect(Node1* root)
//	{
//		queue<Node1*> que;
//		if (root)que.push(root);
//		while (!que.empty())
//		{
//			int size = que.size();
//			Node1* node = NULL;
//			Node1* nodePre = NULL;
//			for (int i = 0; i < size; i++)
//			{
//				if (i == 0)
//				{
//					nodePre = que.front();
//					que.pop();
//					node = nodePre;
//				}
//				else
//				{
//					node = que.front();
//					que.pop();
//					nodePre->next = node;
//					nodePre = node;
//				}
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//			nodePre->next = NULL;
//		}
//		return root;
//	}
//
//	//��������������
//	int maxDepth(TreeNode* root)
//	{
//		if (root == NULL)return 0;
//		queue<TreeNode*> que;
//		que.push(root);
//		int depth = 0;
//		while (!que.empty())
//		{
//			int size = que.size();
//			depth++;
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//		}
//		return depth;
//	}
//	//����������С���
//	int minDepth(TreeNode* root)
//	{
//		if (root == NULL)return 0;
//		queue<TreeNode*> que;
//		que.push(root);
//		int depth = 0;
//		while (!que.empty())
//		{
//			int size = que.size();
//			depth++;
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//				if (!node->left && !node->right)return depth;
//			}
//		}
//		return depth;
//	}
//};
//
////6��ת������
//class Solution6
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//�ݹ鷨
//	TreeNode* invertTree1(TreeNode* root)
//	{
//		if (root == NULL)return root;
//		swap(root->left, root->right);
//		invertTree1(root->left);
//		invertTree1(root->right);
//		return root;
//	}
//	//������1---������ȱ���
//	TreeNode* invertTree2(TreeNode* root)
//	{
//		if (root == NULL) return root;
//		stack<TreeNode*> st;
//		st.push(root);
//		while (!st.empty())
//		{
//			TreeNode* node = st.top();
//			st.pop();
//			swap(node->left, node->right);//��
//
//			if (node->right)st.push(node->right);//��
//			if (node->left)st.push(node->left);//��
//		}
//		return root;
//	}
//	//ͳһ������2---������ȱ���
//	TreeNode* invertTree3(TreeNode* root)
//	{
//		stack<TreeNode*> st;
//		if (root)st.push(root);
//		while (!st.empty())
//		{
//			TreeNode* node = st.top();
//			if (node!=NULL)
//			{
//				st.pop();
//				if (node->right)st.push(node->right);//��
//				if (node->left)st.push(node->left);//��
//				st.push(node);
//				st.push(NULL);//��
//			}
//			else
//			{
//				st.pop();
//				node = st.top();
//				st.pop();
//				swap(node->left, node->right);
//			}
//		}
//		return root;
//	}
//
//	//���������---������ȱ���
//	TreeNode* invertTree4(TreeNode* root)
//	{
//		queue<TreeNode*> que;
//		if (root)que.push(root);
//		while (!que.empty())
//		{
//			int size = que.size();
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				swap(node->left, node->right);
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//		}
//		return root;
//	}
//};
//
////8�Գƶ�����
//class Solution8
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//
//	//�ݹ鷨
//	bool compare(TreeNode* left, TreeNode* right)
//	{
//		//�����ָ�����
//		if (left == NULL && right != NULL) return false;
//		else if (left != NULL && right == NULL)return false;
//		else if (left == NULL && right == NULL) return true;
//		//����ǿ����
//		else if (left->val != right->val)return false;
//
//		//����ѭ���߼�
//		bool outside = compare(left->left, right->right);
//		bool inside = compare(left->right, right->left);
//		bool isSame = outside && inside;
//		return isSame;
//	}
//
//	bool isSymmetric1(TreeNode* root)
//	{
//		if (root == NULL)return true;
//		return compare(root->left, root->right);
//	}
//
//	//������-����
//	bool isSymmetric2(TreeNode* root)
//	{
//		if (root == NULL)return true;
//		queue<TreeNode*> que;
//		que.push(root->left);
//		que.push(root->right);
//
//		while (!que.empty())
//		{
//			TreeNode* leftNode = que.front();
//			que.pop();
//			TreeNode* rightNode = que.front();
//			que.pop();
//			if (!leftNode && !rightNode) continue;
//
//			if (!leftNode || !rightNode || leftNode->val != rightNode->val) return false;
//
//			que.push(leftNode->left);
//			que.push(rightNode->right);
//			que.push(leftNode->right);
//			que.push(rightNode->left);
//
//		}
//		return true;	
//	}
//
//	//������-ջ
//	bool isSymmetric4(TreeNode* root)
//	{
//		if (root == NULL)return true;
//		stack<TreeNode*> st;
//		st.push(root->left);
//		st.push(root->right);
//
//		while (!st.empty())
//		{
//			TreeNode* leftNode = st.top();
//			st.pop();
//			TreeNode* rightNode = st.top();
//			st.pop();
//			
//			if (!leftNode->left && !rightNode->right)continue;
//			if (!leftNode || !rightNode || leftNode->val != rightNode->val) return false;
//			
//			st.push(leftNode->left);
//			st.push(rightNode->right);
//			st.push(leftNode->right);
//			st.push(rightNode->left);
//		}
//		return true;
//	}
//};
//
////9��������������
//class Solution9
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//�ݹ鷨---�������
//	int getDepth1(TreeNode* node)
//	{
//		if (node == NULL) return 0;
//		int leftdepth = getDepth1(node->left);
//		int rightdepth = getDepth1(node->right);
//		int depth = 1 + max(leftdepth, rightdepth);
//
//		return depth;
//	}
//	int maxDepth1(TreeNode* root)
//	{
//		return getDepth1(root);
//	}
//
//	//�ݹ鷨--ǰ�����
//	int result;
//	void getDepth2(TreeNode* node, int depth)
//	{
//		result = depth > result ? depth : result;//��
//		
//		if (node->left == NULL && node->right == NULL)return;
//
//		if (node->left)//��
//		{
//			depth++;
//			getDepth2(node->left, depth);
//			depth--;
//		}
//
//		if (node->right)//��
//		{
//			depth++;
//			getDepth2(node->right, depth);
//			depth--;
//		}
//		return;
//	}
//	int maxDepth2(TreeNode* root)
//	{
//		result = 0;
//		if (root == NULL)return result;
//		getDepth2(root, 1);
//		return result;
//	}
//
//	//������--�������
//	int maxDepth3(TreeNode* root)
//	{
//		if (root == NULL) return 0;
//		int depth = 0;
//		queue<TreeNode*> que;
//		que.push(root);
//		while (!que.empty())
//		{
//			int size = que.size();
//			depth++;
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				if (node->left) que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//		}
//		return depth;
//	}
//};
//
////10����������С���
//class Solution10
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//�ݹ鷨-�������
//	int getDepth(TreeNode* node)
//	{
//		if (node == NULL)return 0;
//		int leftDepth = getDepth(node->left);//��
//		int rightDepth = getDepth(node->right);//��
//		//��
//		if (node->left == NULL && node->right != NULL)
//		{
//			return 1 + rightDepth;
//		}
//		if (node->left!=NULL && node->right==NULL)
//		{
//			return 1 + leftDepth;
//		}
//		if (node->left && node->right)
//		{
//			return 1 + min(leftDepth, rightDepth);
//		}
//	}
//	int minDepth(TreeNode* root)
//	{
//		return getDepth(root);
//	}
//
//	//�ݹ鷨-ǰ�����
//	int result;
//	void getDepth2(TreeNode* node, int depth)
//	{
//		if (node == NULL)return;
//		if (node->left == NULL && node->right == NULL) //��
//		{
//			result = min(depth, result);
//		}
//		if (node->left)//��
//		{
//			getDepth2(node->left, depth + 1);
//		}
//		if (node->right)//��
//		{
//			getDepth2(node->right, depth + 1);
//		}
//	}
//	int minDepth2(TreeNode* root)
//	{
//		if (root == NULL)return 0;
//		result = INT_MAX;
//		getDepth2(root, 1);
//		return result;
//	}
//	
//	//������-�������
//	int minDepth4(TreeNode* root)
//	{
//		if (root == NULL)return 0;
//		int depth = 0;
//		queue<TreeNode*> que;
//		que.push(root);
//		while (!que.empty())
//		{
//			int size = que.size();
//			depth++;
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//				if (node->left == NULL && node->right == NULL)return depth;
//			}
//		}
//		return depth;
//	}
//};
//
////11��ȫ�������Ľڵ����
//class Solution11
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//��ͨ��������---�ݹ鷨
//private:
//	int getNodesNum(TreeNode* cur)
//	{
//		if (cur == nullptr)return 0;
//		int leftNum = getNodesNum(cur->left);//��
//		int rightNum = getNodesNum(cur->right);//��
//		int treeNum = leftNum + rightNum + 1;
//		return treeNum;
//	}
//public:
//	int countNodes1(TreeNode* root)
//	{
//		return getNodesNum(root);
//	}
//
//	//��ͨ��������---������
//	int countNode2(TreeNode* root)
//	{
//		if (root == nullptr) return 0;
//		queue<TreeNode*>que;
//		que.push(root);
//		int result = 0;
//		while (!que.empty())
//		{
//			int size = que.size();
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				result++;
//				if (node->left)que.push(node->left);
//				if (node->right)que.push(node->right);
//			}
//		}
//		return result;
//	}
//
//	//��ȫ����������---�ݹ鷨
//	int countNodes3(TreeNode* root)
//	{
//		if (root == nullptr)return 0;
//		TreeNode* left = root->left;
//		TreeNode* right = root->right;
//		int leftDepth = 0;
//		int rightDepth = 0;
//		while (left)
//		{
//			left = left->left;
//			leftDepth++;
//		}
//		while (right)
//		{
//			right = right->right;
//			rightDepth++;
//		}
//		if (leftDepth == rightDepth)
//		{
//			return (2 << leftDepth) - 1;
//		}
//		return countNodes3(root->left) + countNodes3(root->right) + 1;
//	}
//};
////12ƽ�������
//class Solution12
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//�ݹ鷨--�������
//	int getHeight(TreeNode* node)
//	{
//		if (node == nullptr)return 0;
//
//		int leftHeight = getHeight(node->left);//��
//		if (leftHeight == -1)return -1;
//		int rightHeight = getHeight(node->right);//��
//		if (rightHeight == -1)return -1;
//		return abs(leftHeight-rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);//��
//	}
//	bool isBalanced(TreeNode* root)
//	{
//		return getHeight(root) == -1 ? false : true;
//	}
//};
//
////13������������·��
//class Solution13
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//�ݹ鷨
//	void traversal(TreeNode* cur, vector<int>& path, vector<string>& result)
//	{
//		path.push_back(cur->val);//��
//
//		if (cur->left==nullptr&&cur->right==nullptr)
//		{
//			string sPath;
//			for (int i = 0; i < path.size()-1; i++)
//			{
//				sPath += to_string(path[i]);
//				sPath += "->";
//			}
//			sPath += path[path.size() - 1];
//			result.push_back(sPath);
//			return;
//		}
//		if (cur->left)//��
//		{
//			traversal(cur->left, path, result);
//			path.pop_back();
//		}
//		if (cur->right)//��
//		{
//			traversal(cur->right, path, result);
//			path.pop_back();
//		}
//	}
//
//	vector<string> binaryTreePaths(TreeNode* root)
//	{
//		vector<string> result;
//		vector<int> path;
//		if (root == nullptr)return result;
//		traversal(root, path, result);
//		return result;
//	}
//
//};
//
////15��Ҷ��֮��
//class Solution15
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//�ݹ鷨-����
//	int sumOfLeftLeaves(TreeNode* root)
//	{
//		if (root == NULL) return 0;
//		if (root->left == NULL && root->right == NULL) return 0;
//
//		int leftValue = sumOfLeftLeaves(root->left);//��
//		if (root->left&&!root->left->left&&!root->left->right)
//		{
//			leftValue = root->left->val;
//		}
//
//		int rightValue = sumOfLeftLeaves(root->right);//��
//
//		int sum = leftValue + rightValue;//��
//		return sum;
//	}
//	//������-ջ
//	int sumOfLeftLeaves2(TreeNode* root)
//	{
//		if (root == NULL) return 0;
//		stack<TreeNode*> st;
//		st.push(root);
//		int result = 0;
//		while (!st.empty())
//		{
//			TreeNode* node = st.top();
//			st.pop();
//			if (node->left != NULL && node->left->left == NULL && node->left->right == NULL)
//			{
//				result += node->left->val;
//			}
//			if (node->right)st.push(node->right);
//			if (node->left)st.push(node->left);
//		}
//		return result;
//	}
//};
////16�������½ǵ�ֵ
//class Solution16
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//�ݹ鷨-ǰ�������û���У�
//	int maxDepth = INT_MIN;
//	int result;
//	void traversal(TreeNode* root, int depth)
//	{
//		if (root->left==NULL&&root->right==NULL)
//		{
//			if (depth > maxDepth) 
//			{
//				maxDepth = depth;
//				result = root->val;
//			}
//		}
//
//		if (root->left)
//		{
//			depth++;
//			traversal(root->left, depth);
//			depth--;
//		}
//
//		if (root->right)
//		{
//			depth++;
//			traversal(root->right, depth);
//			depth--;
//		}
//		return;
//	}
//
//	int findBottomLeftValue(TreeNode* root)
//	{
//		traversal(root, 0);
//		return result;
//	}
//
//	//������
//	int findBottomLeftValue2(TreeNode*root)
//	{
//		if (root == NULL) return 0;
//		queue<TreeNode*> que;
//		que.push(root);
//		int result = 0;
//		while (!que.empty())
//		{
//			int size = que.size();
//			for (int i = 0; i < size; i++)
//			{
//				TreeNode* node = que.front();
//				que.pop();
//				if (i == 0) result = node->val;
//				if (node->left) que.push(node->left);
//				if (node->right) que.push(node->right);
//			}
//		}
//		return result;
//	}
//};
//
////17·���ܺ�
//class Solution17
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//
//	//�ݹ鷨
//	bool traversal(TreeNode* cur, int count)
//	{
//		if (cur->left == NULL && cur->right == NULL && count == 0) return true;
//		if (cur->left == NULL && cur->right == NULL)return false;
//
//		if (cur->left)
//		{
//			if (traversal(cur->left, count - cur->left->val))return true;
//		}
//		if (cur->right)
//		{
//			if (traversal(cur->right, count - cur->right->val))return true;
//		}
//		return false;
//	}
//	bool hasPathSum1(TreeNode* root, int sum)
//	{
//		if (root == NULL)return false;
//		traversal(root, sum - root->val);
//	}
//	//������
//	bool hasPathSum2(TreeNode* root, int sum)
//	{
//		if (root == NULL)return false;
//		stack<pair<TreeNode*, int>> st;
//		st.push(pair<TreeNode*, int>(root, root->val));
//		while (!st.empty())
//		{
//			pair<TreeNode*, int> node = st.top();
//			st.pop();
//			if (node.first->left == NULL && node.first->right == NULL && node.second == sum) return true;
//			if (node.first->right)
//			{
//				st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
//			}
//			if (node.first->left)
//			{
//				st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
//			}
//		}
//		return false;
//	}
//};
//
////18�����������������й��������
//class Solution18
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	
//	TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd)
//	{
//		if (postorderBegin == postorderEnd)return NULL;
//
//		int rootValue = postorder[postorderEnd - 1];
//		TreeNode* root = new TreeNode(rootValue);
//
//		if (postorderEnd - postorderBegin == 1)return root;
//
//		int delimiterIndex;
//		for ( delimiterIndex= inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
//		{
//			if (inorder[delimiterIndex] == rootValue) break;
//		}
//		//�и�����
//		int leftInorderBegin = inorderBegin;
//		int leftInorderEnd = delimiterIndex;
//		int rightInorderBegin = delimiterIndex + 1;
//		int rightInorderEnd = inorderEnd;
//		//�и����
//		int leftPostorderBegin = postorderBegin;
//		int leftPostorderEnd = postorderBegin + (leftInorderEnd - leftInorderBegin);
//		int rightPostorderBegin = postorderBegin + (leftInorderEnd - leftInorderBegin);
//		int rightPostorderEnd = postorderEnd - 1;
//
//		root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
//		root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);
//
//		return root;
//	}
//
//	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
//	{
//		if (inorder.size() == 0 || postorder.size() == 0)return NULL;
//		return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
//	}
//};
//
////19��������
//class Solution19
//{
//public:
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//
//};
//
//int main7()
//{
//	system("pause");
//	return 0;
//}