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
////3迭代法
//class Solutin3
//{
//public:
//	//定义二叉树结点
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//前序遍历
//	class Solution1
//	{
//	public:
//		vector<int> preorderTraversal(TreeNode* root)
//		{
//			stack<TreeNode*> st;
//			vector<int> result;
//			if (root == NULL)//空结点不入栈
//			{
//				return result;
//			}
//			st.push(root);
//
//			while (!st.empty())
//			{
//				TreeNode* node = st.top();
//				st.pop();
//				result.push_back(node->val);//中
//				if (node->right)st.push(node->right);//右
//				if (node->left)st.push(node->left);	//左
//			}
//
//			return result;
//		}
//	};
//
//	class Solution2
//	{
//	public:
//		//中序遍历
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
//		//后序遍历
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
////4统一迭代法
//class Solution4
//{
//public:
//	//定义二叉树结点
//	struct TreeNode
//	{
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//		TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//	};
//	//中序遍历
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
//				st.pop();//避免重复
//				if (node->right)st.push(node->right);//右
//
//				st.push(node);//中
//				st.push(NULL);
//
//				if (node->left)st.push(node->left);//左
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
//	//前序遍历
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
//	//后序遍历
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
//				st.push(node);//中
//				st.push(NULL);
//				if (node->right)st.push(node->right);//右
//				if (node->left)st.push(node->left);//左
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
////5层序迭代
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
//	//常规法
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
//	//递归法
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
//	//二叉树的层序遍历2
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
//	//二叉树的右视图
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
//	//二叉树的层平均值
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
//	//N叉树的层序遍历
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
//	//在每一个树行中找最大值
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
//	//填充每一个节点的下一个右侧节点指针
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
//	//二叉树的最大深度
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
//	//二叉树的最小深度
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
////6翻转二叉树
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
//	//递归法
//	TreeNode* invertTree1(TreeNode* root)
//	{
//		if (root == NULL)return root;
//		swap(root->left, root->right);
//		invertTree1(root->left);
//		invertTree1(root->right);
//		return root;
//	}
//	//迭代法1---深度优先遍历
//	TreeNode* invertTree2(TreeNode* root)
//	{
//		if (root == NULL) return root;
//		stack<TreeNode*> st;
//		st.push(root);
//		while (!st.empty())
//		{
//			TreeNode* node = st.top();
//			st.pop();
//			swap(node->left, node->right);//根
//
//			if (node->right)st.push(node->right);//右
//			if (node->left)st.push(node->left);//左
//		}
//		return root;
//	}
//	//统一迭代法2---深度优先遍历
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
//				if (node->right)st.push(node->right);//右
//				if (node->left)st.push(node->left);//左
//				st.push(node);
//				st.push(NULL);//根
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
//	//层序遍历法---广度优先遍历
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
////8对称二叉树
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
//	//递归法
//	bool compare(TreeNode* left, TreeNode* right)
//	{
//		//处理空指针情况
//		if (left == NULL && right != NULL) return false;
//		else if (left != NULL && right == NULL)return false;
//		else if (left == NULL && right == NULL) return true;
//		//处理非空情况
//		else if (left->val != right->val)return false;
//
//		//单层循环逻辑
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
//	//迭代法-队列
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
//	//迭代法-栈
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
////9二叉树的最大深度
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
//	//递归法---后序遍历
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
//	//递归法--前序遍历
//	int result;
//	void getDepth2(TreeNode* node, int depth)
//	{
//		result = depth > result ? depth : result;//中
//		
//		if (node->left == NULL && node->right == NULL)return;
//
//		if (node->left)//左
//		{
//			depth++;
//			getDepth2(node->left, depth);
//			depth--;
//		}
//
//		if (node->right)//右
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
//	//迭代法--层序遍历
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
////10二叉树的最小深度
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
//	//递归法-后序遍历
//	int getDepth(TreeNode* node)
//	{
//		if (node == NULL)return 0;
//		int leftDepth = getDepth(node->left);//左
//		int rightDepth = getDepth(node->right);//右
//		//中
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
//	//递归法-前序遍历
//	int result;
//	void getDepth2(TreeNode* node, int depth)
//	{
//		if (node == NULL)return;
//		if (node->left == NULL && node->right == NULL) //中
//		{
//			result = min(depth, result);
//		}
//		if (node->left)//左
//		{
//			getDepth2(node->left, depth + 1);
//		}
//		if (node->right)//右
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
//	//迭代法-层序遍历
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
////11完全二叉树的节点个数
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
//	//普通二叉树求法---递归法
//private:
//	int getNodesNum(TreeNode* cur)
//	{
//		if (cur == nullptr)return 0;
//		int leftNum = getNodesNum(cur->left);//左
//		int rightNum = getNodesNum(cur->right);//右
//		int treeNum = leftNum + rightNum + 1;
//		return treeNum;
//	}
//public:
//	int countNodes1(TreeNode* root)
//	{
//		return getNodesNum(root);
//	}
//
//	//普通二叉树求法---迭代法
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
//	//完全二叉树的求法---递归法
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
////12平衡二叉树
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
//	//递归法--后序遍历
//	int getHeight(TreeNode* node)
//	{
//		if (node == nullptr)return 0;
//
//		int leftHeight = getHeight(node->left);//左
//		if (leftHeight == -1)return -1;
//		int rightHeight = getHeight(node->right);//右
//		if (rightHeight == -1)return -1;
//		return abs(leftHeight-rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);//中
//	}
//	bool isBalanced(TreeNode* root)
//	{
//		return getHeight(root) == -1 ? false : true;
//	}
//};
//
////13二叉树的所有路径
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
//	//递归法
//	void traversal(TreeNode* cur, vector<int>& path, vector<string>& result)
//	{
//		path.push_back(cur->val);//中
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
//		if (cur->left)//左
//		{
//			traversal(cur->left, path, result);
//			path.pop_back();
//		}
//		if (cur->right)//右
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
////15左叶子之和
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
//	//递归法-后序
//	int sumOfLeftLeaves(TreeNode* root)
//	{
//		if (root == NULL) return 0;
//		if (root->left == NULL && root->right == NULL) return 0;
//
//		int leftValue = sumOfLeftLeaves(root->left);//左
//		if (root->left&&!root->left->left&&!root->left->right)
//		{
//			leftValue = root->left->val;
//		}
//
//		int rightValue = sumOfLeftLeaves(root->right);//右
//
//		int sum = leftValue + rightValue;//中
//		return sum;
//	}
//	//迭代法-栈
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
////16找树左下角的值
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
//	//递归法-前序遍历（没有中）
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
//	//迭代法
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
////17路径总和
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
//	//递归法
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
//	//迭代法
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
////18从中序与后序遍历序列构造二叉树
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
//		//切割中序
//		int leftInorderBegin = inorderBegin;
//		int leftInorderEnd = delimiterIndex;
//		int rightInorderBegin = delimiterIndex + 1;
//		int rightInorderEnd = inorderEnd;
//		//切割后序
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
////19最大二叉树
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