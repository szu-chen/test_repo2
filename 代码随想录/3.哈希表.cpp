//#include<iostream>
//using namespace std;
//#include<vector>
//#include<unordered_set>
//#include<unordered_map>
//#include<algorithm>
//
////2有效的字母异位词
//class Solution2
//{
//public:
//	bool isanagram(string s, string t)
//	{
//		int record[26] = { 0 };
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			record[s[i] - 'a']++;
//		}
//
//		for (int i = 0; i < t.size(); i++)
//		{
//			record[t[i] - 'a']--;
//		}
//
//		for (int i = 0; i < 26; i++)
//		{
//			if (record[i]!=0)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//};
//
////3两个数组的交集
//class Solution3
//{
//public:
//	//暴力解法
//	vector<int> intersection1(vector<int> num1, vector<int> num2)
//	{
//		unordered_set<int> result_set;
//		for (vector<int> ::iterator it1 = num1.begin(); it1 != num1.end(); it1++)
//		{
//			for (vector<int>::iterator it2 = num2.begin(); it2 != num2.end(); it2++)
//			{
//				if (*it1 == *it2)
//				{
//					result_set.insert(*it2);
//				}
//			}
//		}
//		return vector<int>(result_set.begin(), result_set.end());
//	}
//
//	//哈希解法
//	vector<int> intersection2(vector<int>& nums1, vector<int>& nums2)
//	{
//		unordered_set<int> result_set;//收集结果
//		unordered_set<int> nums_set(nums1.begin(), nums1.end());//将nums1放进nums_set,去重
//		for (int num : nums2)//范围for循环遍历容器
//		{
//			if (nums_set.find(num) != nums_set.end())
//			{
//				result_set.insert(num);
//			}
//		}
//		return vector<int>(result_set.begin(), result_set.end());
//	}
//
//	void test()
//	{
//		vector<int> num1 = { 1,3,5,4,3,4 };
//		vector<int> num2 = { 2,1,2,2,3,4,6,6,6};
//		vector<int> result = intersection2(num1, num2);
//		for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
//		{
//			cout << *it << " ";
//		}
//		cout << endl;
//	}
//};
//
////4快乐数
//class Solution4
//{
//public:
//	int getSum(int n)
//	{
//		int sum = 0;
//		while (n)
//		{
//			sum += (n % 10) * (n % 10);//个位的平方
//			n /= 10;//找到下一次位次，如十位
//		}
//		return sum;
//	}
//
//	bool isHappy(int n)
//	{
//		unordered_set<int> set;
//		while (1)
//		{
//			int sum = getSum(n);
//			if (sum==1)
//			{
//				return true;
//			}
//			if (set.find(sum)!=set.end())
//			{
//				return false;
//			}
//			else
//			{
//				set.insert(sum);
//			}
//			n = sum;
//		}
//	}
//};
//
////5两数之和
//class Solution5
//{
//public:
//	vector<int> twoSum(vector<int>& nums, int target)
//	{
//		unordered_map<int, int> map;
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			auto iter = map.find(target - nums[i]);
//			if (iter!=map.end())
//			{
//				return{ iter->second,i };
//			}
//			else
//			{
//				map.insert(pair<int, int>(nums[i], i));
//			}
//		}
//		return {};
//	}
//};
//
////6四数相加2
//class Solution6
//{
//public:
//	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
//	{
//		unordered_map<int, int> umap;
//		for (int a : A)
//		{
//			for (int b : B)
//			{
//				umap[a + b]++;
//			}
//		}
//		int count = 0;
//		for (int c : C)
//		{
//			for (int d : D)
//			{
//				if (umap.find(0-(c+d))!=umap.end())
//				{
//					count += umap[0-(c+d)];
//				}
//			}
//		}
//		return count;
//	}
//};
//
////7赎金信
//class Solution7
//{
//public:
//	//1、暴力解法
//	bool canConstruct1(string ramsomNote, string magazine) 
//{
//		for (int i = 0; i < magazine.size(); i++)
//		{
//			for (int j = 0; j < ramsomNote.size(); j++)
//			{
//				if (magazine[i]==ramsomNote[j])
//				{
//					ramsomNote.erase(ramsomNote.begin()+j);
//					break;
//				}
//			}
//		}
//
//		if (ramsomNote.size()==0)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	//2、哈希解法
//	bool canConstruct2(string ramsomNote, string magazine)
//	{
//		int record[26] = { 0 };
//
//		if (ramsomNote.size()>magazine.size())
//		{
//			return false;
//		}
//
//		for (int i = 0; i < magazine.size(); i++)
//		{
//			record[magazine[i] - 'a']++;
//		}
//		
//		for (int j = 0; j < ramsomNote.size(); j++)
//		{
//			record[ramsomNote[j] - 'a']--;
//
//			if (record[ramsomNote[j]-'a']<0)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//};
//
////8三数之和
//class Solution8
//{
//public:
//	//1、哈希解法---时间复杂度较高n^2
//	
//	//2、双指针法
//	vector<vector<int>> threeSum(vector<int>& nums)
//	{
//		vector<vector<int>> result;//声明二维数组
//		sort(nums.begin(), nums.end());//排序
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] > 0)
//			{
//				return result;
//			}
//
//			//a去重
//			if (i>0 && nums[i]==nums[i-1])
//			{
//				continue;
//			}
//
//			int left = i + 1;
//			int right = nums.size() - 1;
//			while (left<right)
//			{
//				if (nums[i] + nums[left] + nums[right] > 0)
//				{
//					right--;
//				}
//				else if (nums[i]+nums[left]+nums[right]<0)
//				{
//					left++;
//				}
//				else
//				{
//					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
//					while (left < right && nums[right] == nums[right - 1])right--;
//					while (left < right && nums[left] == nums[left + 1])left++;
//					//区间收缩
//					right--;
//					left++;
//				}
//			}
//		}
//		return result;
//
//	}
//};
//
////9四数之和
//class Solution9
//{
//public:
//	//双指针法
//	vector<vector<int>> fourSum(vector<int>& nums, int target)
//	{
//		vector<vector<int>> result;
//		sort(nums.begin(), nums.end());
//
//		for (int k = 0; k < nums.size(); k++)
//		{
//			//剪枝
//			if (nums[k]>target && nums[k] >= 0)
//			{
//				break;
//			}
//			//去重
//			if (k>0 &&nums[k]==nums[k-1])
//			{
//				continue;
//			}
//
//			for (int j = k+1; j < nums.size(); j++)
//			{
//				//2级剪枝
//				if (nums[k]+nums[j]>=target && nums[k]+nums[j]>=0)
//				{
//					break;
//				}
//
//				if (j>k+1 && nums[j]==nums[j-1])
//				{
//					continue;
//				}
//
//				int left = j + 1;
//				int right = nums.size() - 1;
//				while (left<right)
//				{
//					if ((long)nums[k] + nums[j] + nums[left] + nums[right] > target)right--;
//					else if ((long)nums[k] + nums[j] + nums[left] + nums[right] < target)left++;
//					else 
//					{
//						result.push_back(vector<int>{nums[k] , nums[j] , nums[left] , nums[right]});
//						while (left < right && nums[right] == nums[right - 1])right--;
//						while (left < right && nums[left] == nums[left + 1])left++;
//						//收缩空间
//						right--;
//						left++;
//					}
//				}
//			}
//		}
//		return result;
//	}
//};
//
//int main()
//{
//	//Solution3 s3;
//	//s3.test();
//	system("pause");
//	return 0;
//}