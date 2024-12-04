//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<unordered_set>
//#include<unordered_map>
//#include<map>
//
////2分发饼干
//class Solution2
//{
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(), g.end());
//        sort(s.begin(), s.end());
//        int index = s.size() - 1;
//        int result = 0;
//        for (int i = g.size() - 1; i >= 0; i--)
//        {
//            if (index >= 0 && s[index] >= g[i])
//            {
//                result++;
//                index--;
//            }
//        }
//        return result;
//    }
//};
//
////3摆动序列
//class Solution3 {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//        if (nums.size() <= 1)return nums.size();
//        int preDiff = 0;
//        int curDiff = 0;
//        int result = 1;
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            curDiff = nums[i + 1] - nums[i];
//            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0))
//            {
//                result++;
//                preDiff = curDiff;
//            }
//        }
//        return result;
//    }
//};
////4最大子数组和
//class Solution4 {
//public:
//    int maxSubArray(vector<int>& nums)
//    {
//        int result = INT32_MIN;
//        int count = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            count += nums[i];
//            result = count > result ? count : result;
//            if (count < 0)
//            {
//                count = 0;
//            }
//        }
//        return result;
//    }
//};
//
////6买卖股票的最佳时机2
//class Solution6 {
//public:
//    int maxProfit(vector<int>& prices) {
//        int result = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            if (prices[i] - prices[i - 1] > 0)result += prices[i] - prices[i - 1];
//        }
//        return result;
//    }
//};
//
////7跳跃游戏
//class Solution7
//{
//public:
//    bool canJump(vector<int>& nums)
//    {
//        int cover = 0;
//        if (nums.size() == 1)return true;
//        for (int i = 0; i <= cover; i++)
//        {
//            cover = cover > nums[i] + i ? cover : nums[i] + i;
//            if (cover >= nums.size() - 1)return true;
//        }
//        return false;
//    }
//};
//
////8跳跃游戏2
//class Solution8
//{
//public:
//    int jump(vector<int>& nums)
//    {
//        if (nums.size() == 1)return 0;
//        int nextDistance = 0;
//        int curDistance = 0;
//        int ans = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            nextDistance = max(i + nums[i], nextDistance);
//            if (i == curDistance)
//            {
//                ans++;
//                curDistance = nextDistance;
//                if (nextDistance >= nums.size() - 1)break;
//            }
//        }
//        return ans;
//    }
//};
//
////9K次取反后最大化的数组和
//class Solution {
//public:
//    static bool cmp(int a, int b)
//    {
//        return abs(a) > abs(b);
//    }
//    int largestSumAfterKNegations(vector<int>& nums, int k)
//    {
//        sort(nums.begin(), nums.end(), cmp);
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[i] < 0 && k>0)
//            {
//                nums[i] *= -1;
//                k--;
//            }
//        }
//        if (k % 2 == 1)nums[nums.size() - 1] *= -1;
//        int sum = 0;
//        for (int a : nums)sum += a;
//        return sum;
//    }
//};
//
////11加油站
//class Solution11 {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int curSum = 0;
//        int totalSum = 0;
//        int start = 0;
//        for (int i = 0; i < gas.size(); i++)
//        {
//            curSum += gas[i] - cost[i];
//            totalSum += gas[i] - cost[i];
//            if (curSum < 0)
//            {
//                start = i + 1;
//                curSum = 0;
//            }
//        }
//        if (totalSum < 0)return -1;
//        return start;
//
//    }
//};
//
////12分发糖果
//class Solution12{
//public:
//    int candy(vector<int>& ratings)
//    {
//        vector<int> candyVec(ratings.size(), 1);
//        for (int i = 1; i < ratings.size(); i++)
//        {
//            if (ratings[i] > ratings[i - 1])candyVec[i] = candyVec[i - 1] + 1;
//        }
//
//        for (int i = ratings.size() - 2; i >= 0; i--)
//        {
//            if (ratings[i] > ratings[i + 1])candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
//        }
//        int result = 0;
//        for (int a : candyVec)
//        {
//            result += a;
//        }
//        return result;
//    }
//};
//
////13柠檬水找零
//class Solution13 {
//public:
//    bool lemonadeChange(vector<int>& bills) {
//        int five = 0, ten = 0, twenty = 0;
//        for (int bill : bills)
//        {
//            if (bill == 5)five++;
//
//            if (bill == 10)
//            {
//                if (five > 0)
//                {
//                    ten++;
//                    five--;
//                }
//                else return false;
//            }
//
//            if (bill == 20)
//            {
//                if (five > 0 && ten > 0)
//                {
//                    five--;
//                    ten--;
//                    twenty++;
//                }
//                else if (five >= 3)
//                {
//                    five -= 3;
//                }
//                else return false;
//            }
//        }
//        return true;
//    }
//};
////14根据身高重建队列
//class Solution14 {
//public:
//    static bool cmp(vector<int> a, vector<int> b)
//    {
//        if (a[0] == b[0])return a[1] < b[1];
//        return a[0] > b[0];
//    }
//    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
//    {
//        sort(people.begin(), people.end(), cmp);
//        list<vector<int>> que;
//        for (int i = 0; i < people.size(); i++)
//        {
//            int position = people[i][1];
//            list<vector<int>>::iterator it = que.begin();
//            while (position--)
//            {
//                it++;
//            }
//            que.insert(it, people[i]);
//        }
//        return vector<vector<int>>(que.begin(), que.end());
//    }
//};
//
////17用最少数量的箭引爆气球
//class Solution17 {
//private:
//    static bool cmp(const vector<int> a, const vector<int> b)
//    {
//        return a[0] < b[0];
//    }
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        if (points.size() == 0)return 0;
//        sort(points.begin(), points.end(), cmp);
//        int result = 1;
//        for (int i = 1; i < points.size(); i++)
//        {
//            if (points[i - 1][1] < points[i][0])
//            {
//                result++;
//            }
//            else
//            {
//                points[i][1] = min(points[i - 1][1], points[i][1]);
//            }
//        }
//        return result;
//    }
//};
//
////18无重叠区间
//class Solution18 {
//private:
//    static bool cmp(const vector<int> a, const vector<int> b)
//    {
//        return a[1] < b[1];
//    }
//public:
//    int eraseOverlapIntervals(vector<vector<int>>& intervals)
//    {
//        if (intervals.size() == 0)return 0;
//        sort(intervals.begin(), intervals.end(), cmp);
//        int count = 1;
//        int end = intervals[0][1];
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (end <= intervals[i][0])
//            {
//                end = intervals[i][1];
//                count++;
//            }
//        }
//        return intervals.size() - count;
//    }
//};
//
////19划分字母区间
//class Solution19 {
//public:
//
//    vector<int> partitionLabels(string s)
//    {
//        //统计字母最远出现的位置
//        int hash[26] = { 0 };
//        for (int i = 0; i < s.size(); i++)
//        {
//            hash[s[i] - 'a'] = i;
//        }
//
//        int left = 0, right = 0;
//        vector<int> result;
//        for (int i = 0; i < s.size(); i++)
//        {
//            right = max(right, hash[s[i] - 'a']);
//            if (i == right)
//            {
//                result.push_back(right - left + 1);
//                left = i + 1;
//            }
//        }
//        return result;
//    }
//};
//
////20合并区间
//class Solution20
//{
//private:
//    static bool cmp(const vector<int> a, const vector<int> b)
//    {
//        return a[0] < b[0];
//    }
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) 
//    {
//        if (intervals.size() == 0)return intervals;
//        sort(intervals.begin(), intervals.end(), cmp);
//        vector<vector<int>> result;
//        vector<int> interval = intervals[0];
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (interval[1] >= intervals[i][0])
//            {
//                interval[1] = max(interval[1], intervals[i][1]);      
//            }
//            else 
//            {
//                result.push_back(interval);
//                interval = intervals[i];
//            }
//        }
//        result.push_back(interval);
//        return result;
//    }
//};
//
////21单调递增的数字
//class Solution21 {
//public:
//    int monotoneIncreasingDigits(int n) {
//        string strNum = to_string(n);
//        int flag = strNum.size();
//        for (int i = strNum.size() - 1; i > 0; i--)
//        {
//            if (strNum[i - 1] > strNum[i])
//            {
//                strNum[i - 1]--;
//                flag = i;
//            }
//        }
//        for (int i = flag; i < strNum.size(); i++)
//        {
//            strNum[i] = '9';
//        }
//        return stoi(strNum);
//    }
//};
//
////22监控二叉树
//class Solution22 {
//private:
//    struct TreeNode 
//    {
//        int val;
//        TreeNode* left;
//        TreeNode* right;
//        TreeNode() : val(0), left(nullptr), right(nullptr) {};
//        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
//        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
//    };
//
//    int result;
//    int traversal(TreeNode* cur)
//    {
//        if (cur == NULL)return 2;
//        int left = traversal(cur->left);
//        int right = traversal(cur->right);
//
//        if (left == 2 && right == 2)return 0;
//        if (left == 0 || right == 0)
//        {
//            result++;
//            return 1;
//        }
//        if (left == 1 || right == 1)return 2;
//        return -1;
//    }
//public:
//    int minCameraCover(TreeNode* root) {
//        result = 0;
//        if (traversal(root) == 0)
//        {
//            result++;
//        }
//        return result;
//    }
//};
//
//int main9()
//{
//	system("pause");
//	return 0;
//}