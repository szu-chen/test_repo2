//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////2���ֲ���
//class Solution2
//{
//public:
//	//����ұ�
//	int binary_search1(vector<int>& nums, int target)
//	{
//		int left = 0;
//		int right = nums.size() - 1;
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] > target)//target��������
//			{
//				right = mid - 1;
//			}
//			else if (nums[mid] < target)//target��������
//			{
//				left = mid + 1;
//			}
//			else
//			{
//				return mid;
//			}
//		}
//		return -1;
//	}
//	//����ҿ�
//	int binary_search2(vector<int>& nums, int target)
//	{
//		int left = 0;
//		int right = nums.size();
//		while (left < right)
//		{
//			int mid = left + ((right - left) >> 1);
//			if (nums[mid] > target)//target��������
//			{
//				right = mid;
//			}
//			else if (nums[mid] < target)
//			{
//				left = mid + 1;
//			}
//			else
//			{
//				return mid;
//			}
//		}
//		return -1;
//	}
//};
//
//
//
////3�Ƴ�Ԫ��
//class Solution3
//{
//public:
//	//�����ⷨ
//	int removeElement1(int val, vector<int>& nums)
//	{
//		int size = nums.size();
//		for (int i = 0; i < size; i++)
//		{
//			if (nums[i]==val)
//			{
//				for (int j = i+1; j <nums.size() ; j++)
//				{
//					nums[j - 1] = nums[j];
//				}
//				i--;
//				size--;
//			}
//		}
//		return size;
//	}
//	//˫ָ�뷨
//	int removeElement2(int val, vector<int>& nums)
//	{
//		int slowIndex = 0;//��ָ��
//		for (int fastIndex = 0;  fastIndex < nums.size();  fastIndex++)
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
////4���������ƽ��
//class Solution4
//{
//public:
//	//�����ⷨ---��ƽ����������
//	vector<int> Sorted_Squares1(vector<int>& A)
//	{
//		for (int i = 0; i < A.size(); i++)
//		{
//			A[i] *= A[i];
//		}
//		sort(A.begin(), A.end());
//		return A;
//	}
//
//	//˫ָ�뷨
//	vector<int> Sorted_Squars2(vector<int>& A)
//	{
//		int k = A.size()-1;
//		vector<int> B(A.size(), 0);
//		for ( int left = 0,right= A.size() - 1; left <= right; )
//		{
//			if (A[left] * A[left] >= A[right] * A[right])
//			{
//				B[k--] = A[left] * A[left];
//				left++;
//			}
//			else 
//			{
//				B[k--] = A[right] * A[right];
//				right--;
//			}
//		}
//		return B;
//
//	}
//};
//
////5������С��������
//class Solution5
//{
//public:
//	//�����ⷨ
//	int min_SubArray_Len1(int s,vector<int> &nums) 
//	{
//		int result = INT32_MAX;
//		int subLength = 0;
//		int sum = 0;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			sum = 0;
//			for (int j = i; j < nums.size(); j++)
//			{
//				sum += nums[j];
//				if (sum>=s)
//				{
//					subLength = j - i + 1;
//					result = result < subLength ? result : subLength;
//					break;
//				}
//			}
//		}
//		return result == INT32_MAX ? 0 : result;
//	}
//
//	//��������
//	int min_SubArray_Len2(int s,vector<int> &nums)
//	{
//		int result = INT32_MAX;
//		int sublength = 0;
//		int sum = 0;
//		int i = 0;
//		for (int j = 0; j < nums.size(); j++)
//		{
//			sum += nums[j];
//			while (sum>=s)
//			{
//				sublength = j - i + 1;
//				result = result < sublength ? result : sublength;
//				sum -= nums[i++];
//			}
//		}
//		return result == INT32_MAX ? 0 : result;
//	}
//};
//
////6��������2
//class Solution6
//{
//public:
//	vector<vector<int>> generateMatrix(int n)
//	{
//		vector<vector<int>> result(n, vector<int>(n, 0));
//		int start_x = 0, start_y = 0;
//		int loop = n / 2;
//		int mid = n / 2;
//		int count = 1;
//		int offset = 1;
//		int i, j;
//		while (loop--)//����ҿ�
//		{
//			i = start_x;
//			j = start_y;
//			for (j; j < n - offset; j++)
//			{
//				result[i][j] = count++;
//			}
//			for ( i	; i < n-offset; i++)
//			{
//				result[i][j] = count++;
//			}
//			for ( j ; j  > start_x; j --)
//			{
//				result[i][j] = count++;
//			}
//			for ( i; i > start_y; i--)
//			{
//				result[i][j] = count++;
//			}
//
//			start_x++;
//			start_y++;
//
//			offset++;
//		}
//		if (n % 2)//����
//		{
//			result[mid][mid] = count;
//		}
//		return result;
//	}
//};
//
//
//
//
//int main()
//{
//
//
//	system("pause");
//	return 0;
//}