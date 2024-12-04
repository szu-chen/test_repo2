//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<unordered_set>
//#include<unordered_map>
//#include<map>
//
//
//
////2�������
//class Solution2
//{
//private:
//	vector<vector<int>> result;
//	vector<int> path;
//	void backtracking(int n, int k, int startIndex)
//	{
//		if (path.size() == k)
//		{
//			result.push_back(path);
//			return;
//		}
//
//		for (int i = startIndex; i <= n ;i++)
//		{
//			path.push_back(i);
//			backtracking(n, k, i + 1);
//			path.pop_back();
//		}
//	}
//public:
//	vector<vector<int>> combine(int n, int k)
//	{
//		backtracking(n, k, 1);
//		return result;
//	}
//
//};
//
////3���(�Ż�)
//class Solution3
//{
//private:
//	vector<vector<int>> result;
//	vector<int> path;
//	void backtracking(int n, int k, int startIndex)
//	{
//		if (path.size() == k)
//		{
//			result.push_back(path);
//			return;
//		}
//
//		for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
//		{
//			path.push_back(i);
//			backtracking(n, k, i + 1);
//			path.pop_back();
//		}
//	}
//public:
//	vector<vector<int>> combine(int n, int k)
//	{
//		backtracking(n, k, 1);
//		return result;
//	}
//
//};
//
////4����ܺ�3
////class Solution4
////{
////private:
////	vector<vector<int>> result;
////	vector<int> path;
////	void backtracking(int n, int k, int startIndex)
////	{
////		if (path.size() == k)
////		{
////			int sum = 0;
////			for (auto i : path)
////			{
////				sum += i;
////			}
////			if (sum == n)
////			{
////				result.push_back(path);
////			}
////			return;
////		}
////		
////		for (int i = startIndex; i <=9 ; i++)
////		{
////			path.push_back(i);
////			backtracking(n, k, i + 1);
////			path.pop_back();
////		}
////	}
////public:
////	vector<vector<int>> combinationSum3(int n, int k)
////	{
////		backtracking(n, k, 1);
////		return result;
////	}
////};
//class Solution4
//{
//private:
//	vector<vector<int>> result;
//	vector<int> path;
//
//	void backtracking(int n, int k, int sum, int startIndex)
//	{
//		//��֦����
//		if (sum > n)return;
//		//��ֹ����
//		if (path.size() == k)
//		{
//			if (sum == n)result.push_back(path);
//			return;
//		}
//		//forѭ��
//		for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
//		{
//			sum += i;
//			path.push_back(i);
//			backtracking(n, k, sum, i + 1);
//			sum -= i;
//			path.pop_back();
//		}
//	}
//public:
//	vector<vector<int>> combinationSum3(int n, int k)
//	{
//		backtracking(n, k, 0,1);
//		return result;
//	}
//};
//
////5�绰�������ĸ���
//class Solution5
//{
//private:
//	const string letterMap[10] =
//	{
//		"",
//		"",
//		"abc",
//		"def",
//		"ghi",
//		"jkl",
//		"mno",
//		"pqrs",
//		"tuv",
//		"wsyz"
//	};
//public:
//	vector<string> result;
//	string s;
//	void backtracking(const string& digits, int index)
//	{
//		if (index == digits.size())
//		{
//			result.push_back(s);
//			return;
//		}
//		int digit = digits[index] - '0';
//		string letters = letterMap[digit];
//		for (int i = 0; i < letters.size(); i++)
//		{
//			s.push_back(letters[i]);
//			backtracking(digits, index + 1);
//			s.pop_back();
//		}
//	}
//
//	vector<string> letterCombinations(string digits)
//	{
//		s.clear();
//		result.clear();
//		if (digits.size() == 0)return result;
//		backtracking(digits, 0);
//		return result;
//	}
//};
//
////7����ܺ�
//class Solution7
//{
//public:
//	vector<vector<int>> result;
//	vector<int> path;
//	void backtracking(vector<int>& candidates, int target,int startIndex)
//	{
//		if (target == 0)
//		{
//			result.push_back(path);
//			return;
//		}
//		//if (target < 0)return;
//		//&&target-candidates[i]��֦
//		for (int i = startIndex; i < candidates.size()&&target-candidates[i] >= 0; i++)
//		{
//			path.push_back(candidates[i]);
//			backtracking(candidates, target - candidates[i],i);
//			path.pop_back();
//		}
//	}
//	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//	{
//		result.clear();
//		path.clear();
//		//�����֦
//		sort(candidates.begin(), candidates.end());
//		backtracking(candidates, target,0);
//		return result;
//	}
//
//};
//
////8����ܺ�2
//class Solution8
//{
//public:
//	vector<vector<int>> result;
//	vector<int> path;
//
//	void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used)
//	{
//		if (target == 0)
//		{
//			result.push_back(path);
//			return;
//		}
//
//		for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++) 
//		{
//			//ͬһ��ȥ��
//			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
//			{
//				continue;
//			}
//			path.push_back(candidates[i]);
//			used[i] = true;
//			backtracking(candidates, target - candidates[i], i + 1, used);
//			used[i] = false;
//			path.pop_back();
//		}
//	}
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
//	{
//		vector<bool> used(candidates.size(), false);
//		result.clear();
//		path.clear();
//		//�����֦
//		sort(candidates.begin(), candidates.end());
//		backtracking(candidates,target,0,used);
//		return result;
//	}
//
//};
//
////9�ָ���Ĵ�
//class Solution9
//{
//private:
//	bool isPalindrome(const string& s, int start, int end)
//	{
//		for (int i = start, j = end; i < j; i++, j--)
//		{
//			if (s[i] != s[j])return false;
//		}
//		return true;
//	}
//
//	vector<vector<string>> result;
//	vector<string> path;
//	void backtracking(const string& s, int startIndex)
//	{
//
//		//��ֹ����
//		if (startIndex >= s.size())
//		{
//			result.push_back(path);
//			return;
//		}
//
//		for (int i = startIndex; i < s.size(); i++)
//		{
//			if (isPalindrome(s, startIndex, i)) 
//			{
//				string str = s.substr(startIndex, i - startIndex + 1);
//				path.push_back(str);
//			}
//			else
//			{
//				continue;
//			}
//			backtracking(s, i + 1);
//			path.pop_back();
//		}
//	}
//
//public:
//	vector<vector<string>> partition(string s)
//	{
//		result.clear();
//		path.clear();
//		backtracking(s, 0);
//		return result;
//	}
//	
//};
//
////10��ԭIP��ַ
//class Solution10
//{
//private:
//	vector<string> result;
//	//�ж��ַ���s������[start��end]����ɵ������Ƿ�Ϸ�
//	bool isValid(string s, int start, int end)
//	{
//		if (start > end)return false;//ѭ����ֹ����
//		if (s[start] == '0' && start != end)return false;//������Ϊ0�ҳ��ȴ���1
//		int num = 0;
//		for (int i = start; i <= end; i++)
//		{
//			if (s[i] < '0' || s[i]>'9')return false;//���ַǷ�
//			num = num * 10 + (s[i] - '0');
//			if (num > 255)return false;//���ִ���255
//		}
//		return true;
//	}
//
//	void backtracking(string& s, int startIndex, int pointNum)
//	{
//		if (pointNum == 3)
//		{
//			if (isValid(s, startIndex, s.size() - 1))
//			{
//				result.push_back(s);
//			}
//			return;
//		}
//		
//		for (int i = startIndex; i < s.size(); i++)
//		{
//			if (isValid(s, startIndex, i))
//			{
//				s.insert(s.begin() + i + 1, '.');
//				pointNum++;
//				backtracking(s, i + 2, pointNum);
//				pointNum--;
//				s.erase(s.begin() + i + 1);
//			}
//			else break;
//		}
//	}
//
//public:
//	vector<string> restoreIpAddresses(string s)
//	{
//		result.clear();
//		if (s.size() < 4 || s.size() > 12)return result;
//		backtracking(s, 0, 0);
//		return result;
//	}
//};
//
////11�Ӽ�����
//class Solution11
//{
//private:
//	vector<vector<int>> result;
//	vector<int> path;
//	void backtracking(vector<int>& nums, int startIndex)
//	{
//		result.push_back(path);//�ռ��Ӽ�
//		if (startIndex >= nums.size())
//		{
//			return;
//		}
//		for (int i = startIndex; i < nums.size(); i++)
//		{
//			path.push_back(nums[i]);
//			backtracking(nums, i + 1);
//			path.pop_back();
//		}
//	}
//public:
//	vector<vector<int>> subsets(vector<int>& nums) 
//	{
//		result.clear();
//		path.clear();
//		backtracking(nums, 0);
//		return result;
//	}
//};
//
////13�Ӽ�2
//class Solution13
//{
//private:
//	vector<vector<int>> result;
//	vector<int> path;
//	void backtracking(vector<int>& nums, int startIndex, vector<bool>& used)
//	{
//		result.push_back(path);
//		if (startIndex >= nums.size())return;
//
//		for (int i = startIndex; i < nums.size(); i++)
//		{
//			//ͬһ��ȥ��
//			if (i>0&&nums[i] == nums[i-1] && used[i-1] == false)continue;
//			path.push_back(nums[i]);
//			used[i] = true;
//			backtracking(nums, i + 1, used);
//			used[i] = false;
//			path.pop_back();
//		}
//	}
//public:
//	vector<vector<int>> subsetsWithDup(vector<int>& nums)
//	{
//		result.clear();
//		path.clear();
//		//�������ȥ��
//		sort(nums.begin(), nums.end());
//		vector<bool> used(nums.size(), false);
//		backtracking(nums, 0, used);
//		return result;
//	}
//};
//
//
////14����������
//class Solution14
//{
//private:
//	vector<vector<int>> result;
//	vector<int> path;
//	void backtracking(vector<int>& nums, int startIndex)
//	{
//		if (path.size() > 1)
//		{
//			result.push_back(path);
//		}
//
//		unordered_set<int> uset;
//		for (int i = startIndex; i < nums.size(); i++)
//		{
//			if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
//			{
//				continue;
//			}
//			uset.insert(nums[i]);
//			path.push_back(nums[i]);
//			backtracking(nums, i + 1);
//			path.pop_back();
//		}
//	}
//public:
//	vector<vector<int>> findSubsequences(vector<int>& nums) 
//	{
//		result.clear();
//		path.clear();
//		backtracking(nums, 0);
//		return result;
//	}
//
//};
//
////15ȫ����
//class Solution15
//{
//private:
//	vector<vector<int>> result;
//	vector<int> path;
//	void backtracking(vector<int>& nums, vector<bool>& used)
//	{
//		if (path.size() == nums.size())
//		{
//			result.push_back(path);
//			return;
//		}
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (used[i] == true)continue;
//			used[i] = true;
//			path.push_back(nums[i]);
//			backtracking(nums, used);
//			path.pop_back();
//			used[i] = false;
//		}
//	}
//public:
//	vector<vector<int>> permute(vector<int>& nums) 
//	{
//		result.clear();
//		path.clear();
//		vector<bool> used(nums.size(), false);
//		backtracking(nums, used);
//		return result;
//	}
//};
//
////16ȫ����2
//class Solution16
//{
//private:
//	vector<vector<int>> result;
//	vector<int> path;
//	void backtracking(vector<int>& nums, vector<bool>& used)
//	{
//		if (nums.size() == path.size())
//		{
//			result.push_back(path);
//			return;
//		}
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if ((i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) || used[i] == true)continue;
//			used[i] = true;
//			path.push_back(nums[i]);
//			backtracking(nums, used);
//			used[i] = false;
//			path.pop_back();
//		}
//	}
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		result.clear();
//		path.clear();
//		vector<bool> used(nums.size(), false);
//		sort(nums.begin(), nums.end());
//		backtracking(nums, used);
//		return result;
//	}
//};
//
////19���°����г�
//class Soluion19
//{
//private:
//	unordered_map<string, map<string, int>> targets;
//	bool backtracking(int ticketNum, vector<string>& result)
//	{
//		if (result.size() == ticketNum + 1)
//		{
//			return true;
//		}
//		for (pair<const string, int>& ticket : targets[result[result.size() - 1]])
//		{
//			if (ticket.second > 0)
//			{
//				ticket.second--;
//				result.push_back(ticket.first);
//				if (backtracking(ticketNum, result))return true;
//				result.pop_back();
//				ticket.second++;
//			}
//		}
//		return false;
//	}
//public:
//	vector<string> findItinerary(vector<vector<string>>& tickets)
//	{
//		targets.clear();
//		vector<string> result;
//		//��ʼ��
//		result.push_back("JFK");
//		for (const vector<string>& vec : tickets)
//		{
//			targets[vec[0]][vec[1]]++;
//		}
//		backtracking(tickets.size(), result);
//		return result;
//	}
//};
////20N�ʺ�
//class Solution20 {
//private:
//	bool isValid(int row, int col, vector<string>& chessboard, int n)
//	{
//		//��ͬ��
//		for (int i = 0; i < row; i++)
//		{
//			if (chessboard[i][col] == 'Q')return false;
//		}
//		//45��б��
//		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
//		{
//			if (chessboard[i][j] == 'Q')return false;
//		}
//		//135��б��
//		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
//		{
//			if (chessboard[i][j] == 'Q')return false;
//		}
//		return true;
//	}
//	vector<vector<string>> result;
//	void backtracking(int n, int row, vector<string>& chessboard)
//	{
//		if (row == n)
//		{
//			result.push_back(chessboard);
//			return;
//		}
//		for (int col = 0; col < n; col++)
//		{
//			if (isValid(row, col, chessboard, n))
//			{
//				chessboard[row][col] = 'Q';
//				backtracking(n, row + 1, chessboard);
//				chessboard[row][col] = '.';
//			}
//		}
//	}
//public:
//	vector<vector<string>> solveNQueens(int n) {
//		result.clear();
//		vector<string> chessboard(n, string(n, '.'));
//		backtracking(n, 0, chessboard);
//		return result;
//	}
//};
////21������
//class Solution21 {
//private:
//	bool isValid(int row, int col, char val, vector<vector<char>>& board)
//	{
//		//��ͬ��
//		for (int i = 0; i < 9; i++)
//		{
//			if (board[row][i] == val)return false;
//		}
//		//��ͬ��
//		for (int j = 0; j < 9; j++)
//		{
//			if (board[j][col] == val)return false;
//		}
//		//��ͬ�Ź���
//		int rowStart = (row / 3) * 3;
//		int colStart = (col / 3) * 3;
//		for (int i = rowStart; i < rowStart + 3; i++)
//		{
//			for (int j = colStart; j < colStart + 3; j++)
//			{
//				if (board[i][j] == val)return false;
//			}
//		}
//		return true;
//	}
//
//	bool backtracking(vector<vector<char>>& board)
//	{
//		for (int i = 0; i < board.size(); i++)
//		{
//			for (int j = 0; j < board[0].size(); j++)
//			{
//				if (board[i][j] == '.')
//				{
//					for (char k = '1'; k <= '9'; k++)
//					{
//						if (isValid(i, j, k, board))
//						{
//							board[i][j] = k;
//							if (backtracking(board))return true;
//							board[i][j] = '.';
//						}
//					}
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//public:
//	void solveSudoku(vector<vector<char>>& board)
//	{
//		backtracking(board);
//	}
//};
//
//
//
//
//	
//int main8()
//{
//	system("pause");
//	return 0;
//}