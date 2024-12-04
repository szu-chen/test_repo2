//#include<iostream>
//using namespace std;
//#include<vector>
//#include<unordered_set>
//
//
////2쳲���������
//class Solution2 {
//public:
//    int fib(int n)
//    {
//        if (n <= 1)return n;
//        //1������dp����
//        vector<int> dp(n + 1);
//        //3��dp�����ʼ��
//        dp[0] = 0;
//        dp[1] = 1;
//        for (int i = 2; i <= n; i++)//4��ȷ������˳��
//        {
//            dp[i] = dp[i - 1] + dp[i - 2];//2��ȷ�����ƹ�ʽ
//        }
//        return dp[n];
//    }
//};
//
////3��¥��
//class Solution3 {
//public:
//    int climbStairs(int n)
//    {
//        if (n <= 2)return n;
//        vector<int> dp(n + 1);
//        dp[1] = 1;
//        dp[2] = 2;
//        for (int i = 3; i <= n; i++)
//        {
//            dp[i] = dp[i - 1] + dp[i - 2];
//        }
//        return dp[n];
//    }
//};
//
////4ʹ����С������¥��
//class Solution4 {
//public:
//    int minCostClimbingStairs(vector<int>& cost)
//    {
//        vector<int> dp(cost.size() + 1);
//        dp[0] = 0;
//        dp[1] = 0;
//        for (int i = 2; i <= cost.size(); i++)
//        {
//            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//        }
//        return dp[cost.size()];
//    }
//};
//
////6��ͬ·��
//class Solution6 {
//public:
//    int uniquePaths(int m, int n)
//    {   
//        //if(m==1||n==1)return 1;
//        vector<vector<int>> dp(m, vector<int>(n, 0));
//        for (int j = 0; j < n; j++) dp[0][j] = 1;
//        for (int i = 0; i < m; i++) dp[i][0] = 1;
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};
//
////7��ͬ·��2
//class Solution7 {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
//    {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//        //���Ϊ1���յ�Ϊ1�����
//        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)return 0;
//        //��ʼ��
//        vector<vector<int>> dp(m, vector<int>(n, 0));
//        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)dp[i][0] = 1;
//        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)dp[0][j] = 1;
//        //����˳��
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                if (obstacleGrid[i][j] == 1)continue;
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};
//
////8�������
//class Solution8 {
//public:
//    int integerBreak(int n)
//    {
//        //ȷ��dp�����Լ��±꺬��
//        vector<int> dp(n + 1, 0);
//         //��ʼ��
//        dp[2] = 1;
//        //ȷ������˳��
//        for (int i = 3; i <= n; i++)
//        {
//            for (int j = 1; j <= i / 2; j++)
//            {
//                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));//����ʽ
//            }
//        }
//        return dp[n];
//    }
//};
//
////9��ͬ�Ķ���������
//class Solution9 {
//public:
//    int numTrees(int n)
//    {
//        
//        vector<int> dp(n + 1, 0);
//        dp[0] = 1;
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 0; j <= i - 1; j++)
//            {
//                dp[i] += dp[j] * dp[i - j - 1];//�ؼ�
//            }
//        }
//        return dp[n];
//    }
//};
//
//
////11 0-1�������ۻ���
//class Solution11
//{
//public:
//    int bagMaxValue(vector<int> weight, vector<int> value, int bagCapacity)
//    {
//        //��ʼ��
//        vector<vector<int>> dp(weight.size(), vector<int>(bagCapacity + 1, 0));
//        for (int j = weight[0]; j < bagCapacity; j++)
//        {
//            dp[0][j] = value[0];
//        }
//        //������������Ʒ�󱳰�
//        for (int i = 1; i < weight.size(); i++)
//        {
//            for (int j = 0; j <= bagCapacity; j++)
//            {
//                if (weight[i] > j) dp[i][j] = dp[i - 1][j];//������Ʒi
//                else
//                {
//                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);//����Ʒi
//                }
//            }
//        }
//        return dp[weight.size() - 1][bagCapacity];
//
//    }
//};
////12 0-1�������ۻ������������飩
//class Solution12
//{
//public:
//    int bagMaxValue(vector<int> weight, vector<int> value, int bagCapacity)
//    {
//        //��ʼ��
//        vector<int> dp(bagCapacity + 1, 0);
//        for (int i = 0; i < weight.size(); i++)
//        {
//            for (int j = bagCapacity; j >= weight[i]; j--)
//            {
//                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
//            }
//        }
//        return dp[bagCapacity];
//    }
//};
//
////13�ָ�Ⱥ��Ӽ�
//class Solution13 {
//public:
//    bool canPartition(vector<int>& nums)
//    {
//        int sum = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            sum += nums[i];
//        }
//        //��ʼ��
//        vector<int> dp(10001, 0);
//        if (sum % 2 == 1)return false;
//        int target = sum / 2;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            for (int j = target; j >= nums[i]; j--)
//            {
//                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//            }
//        }
//        if (dp[target] == target)return true;
//        return false;
//    }
//};
//
////14���һ��ʯͷ����2
//class Solution14 {
//public:
//    int lastStoneWeightII(vector<int>& stones)
//    {
//        int sum = 0;
//        for (int i = 0; i < stones.size(); i++) sum += stones[i];
//        vector<int> dp(15001, 0);
//        int target = sum / 2;
//        for (int i = 0; i < stones.size(); i++)
//        {
//            for (int j = target; j >= stones[i]; j--)
//            {
//                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
//            }
//        }
//        return (sum - dp[target]) - dp[target];
//    }
//};
//
////16Ŀ���
//class Solution16 {
//public:
//    int findTargetSumWays(vector<int>& nums, int target)
//    {
//        int sum = 0;
//        for (int i : nums)sum += i;
//        if (abs(target) > sum)return 0;
//        if ((target + sum) % 2 == 1)return 0;
//        int bagSize = (target + sum) / 2;
//        vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));
//        //��ʼ��
//        if (nums[0] <= bagSize)dp[0][nums[0]] = 1;//��һ��
//        dp[0][0] = 1;//���Ͻ�
//        int sumZero = 0;//��һ��
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[i] == 0)sumZero++;
//            dp[i][0] = (int)pow(2.0, sumZero);
//        }
//        for (int i = 1; i < nums.size(); i++)
//        {
//            for (int j = 0; j <= bagSize; j++)
//            {
//                if (nums[i] > j)dp[i][j] = dp[i - 1][j];
//                else
//                {
//                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
//                }
//            }
//
//        }
//        return dp[nums.size() - 1][bagSize];
//
//    }
//};
////16Ŀ��͡�����������
//class Solution162 {
//public:
//    int findTargetSumWays(vector<int>& nums, int target)
//    {
//        int sum = 0;
//        for (int i : nums)sum += i;
//        if (abs(target) > sum)return 0;
//        if ((target + sum) % 2 == 1)return 0;
//        int bagSize = (target + sum) / 2;
//        vector<int> dp(bagSize + 1, 0);
//        dp[0] = 1;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            for (int j = bagSize; j >= nums[i]; j--)
//            {
//                dp[j] += dp[j - nums[i]];
//            }
//        }
//        return dp[bagSize];
//    }
//};
//
////17һ���㡪����ά����
//class Solution17 {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n)
//    {
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//        for (string str : strs)
//        {
//            int zeroNum = 0, oneNum = 0;
//            for (char c : str)
//            {
//                if (c == '0')zeroNum++;
//                else oneNum++;
//            }
//            //��ά����
//            for (int i = m; i >= zeroNum; i--)
//            {
//                for (int j = n; j >= oneNum; j--)
//                {
//                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
//                }
//            }
//        }
//        return dp[m][n];
//    }
//};
//
//
////18��ȫ��������
//class Solution18
//{
//public:
//    int completePack(vector<int>& value, vector<int> &weight, int bagSize)
//    {
//        vector<int> dp(bagSize + 1, 0);
//        for (int i = 0; i < value.size(); i++)
//        {
//            for (int j = weight[i]; j <= bagSize; j++)
//            {
//                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
//            }
//        }
//        return dp[bagSize];
//    }
//};
//
////19��Ǯ�һ�2
//class Solution19 {
//public:
//    int change(int amount, vector<int>& coins)
//    {
//        vector<int> dp(amount + 1, 0);
//        dp[0] = 1;
//        //�ȱ�����Ʒ���������--�����
//        for (int i = 0; i < coins.size(); i++)
//        {
//            for (int j = coins[i]; j <= amount; j++)
//            {
//                if (dp[j] < INT_MAX - dp[j - coins[i]])
//                {
//                    dp[j] += dp[j - coins[i]];
//                }
//            }
//        }
//        return dp[amount];
//    }
//};
//
////21����ܺ�4
//class Solution21 {
//public:
//    int combinationSum4(vector<int>& nums, int target)
//    {
//        vector<int> dp(target + 1, 0);
//        dp[0] = 1;
//        //�ȱ��������������Ʒ--������
//        for (int j = 0; j <= target; j++)
//        {
//            for (int i = 0; i < nums.size(); i++)
//            {
//                if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
//                {
//                    dp[j] += dp[j - nums[i]];
//                }
//            }
//        }
//        return dp[target];
//    }
//};
//
////22��¥�ݣ����װ棩
//class Solution22
//{
//public:
//    int climbingStairs(int n, int m)
//    {
//        vector<int> dp(n + 1, 0);
//        dp[0] = 1;
//        //�ȱ��������������Ʒ--������
//        for (int j = 1; j <= n; j++)
//        {
//            for (int i = 1; i <= m; i++)
//            {
//                if (j - i >= 0)dp[j] += dp[j - i];
//            }
//        }
//        return dp[n];
//    }
//};
//
////23��Ǯ�һ�
//class Solution23 {
//public:
//    int coinChange(vector<int>& coins, int amount)
//    {
//        vector<int> dp(amount + 1, INT_MAX);
//        dp[0] = 0;
//        for (int i = 0; i < coins.size(); i++)
//        {
//            for (int j = coins[i]; j <= amount; j++)
//            {
//                if (dp[j - coins[i]] != INT_MAX)
//                {
//                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
//                }
//                cout << dp[j] << endl;
//            }
//        }
//        if (dp[amount] == INT_MAX)return -1;
//        return dp[amount];
//    }
//};
////24��ȫƽ����
//class Solution241 {
//public:
//    int numSquares(int n)
//    {
//        vector<int> dp(n + 1, INT_MAX);
//        dp[0] = 0;
//        for (int i = 1; i * i <= n; i++)
//        {
//            for (int j = i * i; j <= n; j++)
//            {
//                dp[j] = min(dp[j], dp[j - i * i] + 1);
//            }
//        }
//        return dp[n];
//    }
//};
//class Solution242 {
//public:
//    int numSquares(int n)
//    {
//        vector<int> dp(n + 1, INT_MAX);
//        dp[0] = 0;  
//        for (int j = 0; j <= n; j++)
//        {
//            for (int i = 1; i * i <= n; i++)
//            {
//                if (i * i <= j)dp[j] = min(dp[j], dp[j - i * i] + 1);
//            }
//        }
//        return dp[n];
//    }
//};
////26���ʲ��
//class Solution26 {
//public:
//    bool wordBreak(string s, vector<string>& wordDict)
//    {
//        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//        vector<bool> dp(s.size() + 1, false);
//        dp[0] = true;
//        for (int i = 1; i <= s.size(); i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                string word = s.substr(j, i - j);
//                cout << word << endl;
//                if (wordSet.find(word) != wordSet.end() && dp[j])
//                {
//                    dp[i] = true;
//                    if (dp[i])cout << 666 << endl;
//                }
//            }
//        }
//        return dp[s.size()];
//    }
//};
////29��ҽ���
//class Solution29 {
//public:
//    int rob(vector<int>& nums)
//    {
//        if (nums.size() == 0)return 0;
//        if (nums.size() == 1)return nums[0];
//        vector<int> dp(nums.size());
//        dp[0] = nums[0];
//        dp[1] = max(nums[0], nums[1]);
//        for (int i = 2; i < nums.size(); i++)
//        {
//            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//        }
//        return dp[nums.size() - 1];
//    }
//};
//
////30��ҽ���2
//class Solution30 {
//public:
//    int rob(vector<int>& nums)
//    {
//        if (nums.size() == 0)return 0;
//        if (nums.size() == 1)return nums[0];
//        int result1 = robRange(nums, 0, nums.size() - 2);
//        int result2 = robRange(nums, 1, nums.size() - 1);
//        return max(result1, result2);
//    }
//    int robRange(vector<int>& nums, int start, int end)
//    {
//        if (start == end)return nums[start];
//        vector<int> dp(nums.size());
//        dp[start] = nums[start];
//        dp[start + 1] = max(nums[start], nums[start + 1]);
//        for (int i = start + 2; i <= end; i++)
//        {
//            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//        }
//        return dp[end];
//    }
//};
//
////31��ҽ���3
//class Solution31 
//{
//public:
//    struct TreeNode
//    {
//        int val;
//        TreeNode* left;
//        TreeNode* right;
//        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//    };
//
//    vector<int> robTree(TreeNode* cur)
//    {
//        if (cur == NULL)return vector<int>{0, 0};
//        vector<int> left = robTree(cur->left);//��
//        vector<int> right = robTree(cur->right);//��
//        //��
//        int val1 = cur->val + left[0] + right[0];
//        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
//        return vector<int> {val2, val1};
//    }
//    int rob(TreeNode* root) {
//        vector<int> result = robTree(root);
//        return max(result[0], result[1]);
//    }
//};
//
////32������Ʊ�����ʱ��
//class Solution32 {
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        if (prices.size() == 0)return 0;
//        //dp���鶨�弰�±꺬��
//        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
//        //��ʼ��
//        dp[0][0] = -prices[0];
//        dp[0][1] = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            dp[i][0] = max(dp[i - 1][0], -prices[i]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
//        }
//        return dp[prices.size() - 1][1];
//    }
//};
//
////34������Ʊ�����ʱ��2
//class Solution34 
//{
//public:
//    int maxProfit(vector<int>& prices) {
//        int len = prices.size();
//        if (len == 0)return 0;
//        vector<vector<int>> dp(len, vector<int>(2, 0));
//        dp[0][0] = -prices[0];
//        dp[0][1] = 0;
//        for (int i = 1; i < len; i++)
//        {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
//        }
//        return dp[len - 1][1];
//    }
//};
//
//
////35������Ʊ�����ʱ��3
//class Solution35 
//{
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        int len = prices.size();
//        if (len == 0)return 0;
//        vector<vector<int>> dp(len, vector<int>(5, 0));
//        dp[0][1] = -prices[0];
//        dp[0][3] = -prices[0];
//        for (int i = 1; i < len; i++)
//        {
//            dp[i][1] = max(dp[i - 1][1], -prices[i]);
//            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
//            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
//            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
//        }
//        return dp[len - 1][4];
//    }
//};
////36������Ʊ�����ʱ��4
//class Solution36 {
//public:
//    int maxProfit(int k, vector<int>& prices)
//    {
//        int len = prices.size();
//        if (len == 0)return 0;
//        vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));
//        for (int j = 1; j < 2 * k; j += 2)
//        {
//            dp[0][j] = -prices[0];
//        }
//        for (int i = 1; i < len; i++)
//        {
//            for (int j = 1; j < 2 * k; j += 2)
//            {
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
//                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
//                cout << dp[i][j] << endl;
//                cout << dp[i][j + 1] << endl;
//            }
//            cout << "!!!" << endl;
//        }
//        return dp[len - 1][2 * k];
//    }
//};
////37������Ʊ�����ʱ�����䶳��
//class Solution37 {
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        int len = prices.size();
//        if (len == 0)return 0;
//        vector<vector<int>> dp(len, vector<int>(4, 0));
//        dp[0][0] = -prices[0];
//        for (int i = 1; i < len; i++)
//        {
//            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
//            dp[i][2] = dp[i - 1][0] + prices[i];
//            dp[i][3] = dp[i - 1][2];
//        }
//        return max(dp[len - 1][1], max(dp[len - 1][2], dp[len - 1][3]));
//    }
//};
////38������Ʊ�����ʱ����������
//class Solution38 {
//public:
//    int maxProfit(vector<int>& prices, int fee)
//    {
//        int len = prices.size();
//        if (len == 0)return 0;
//        vector<vector<int>> dp(len, vector<int>(2, 0));
//        dp[0][0] = -prices[0];
//        for (int i = 1; i < len; i++)
//        {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
//        }
//        return dp[len - 1][1];
//
//    }
//};
//
////41�����������
//class Solution41 {
//public:
//    int lengthOfLIS(vector<int>& nums)
//    {
//        if (nums.size() <= 1)return nums.size();
//        vector<int> dp(nums.size(), 1);
//        int result = 0;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                if (nums[i] > nums[j])dp[i] = max(dp[i], dp[j] + 1);
//            }
//            result = result > dp[i] ? result : dp[i];//����result
//        }
//        return result;
//    }
//};
////42�������������
//class Solution42 {
//public:
//    int findLengthOfLCIS(vector<int>& nums)
//    {
//        if (nums.size() == 0)return 0;
//        int result = 1;
//        vector<int> dp(nums.size(), 1);
//        for (int i = 1; i < nums.size(); i++)
//        {
//            if (nums[i] > nums[i - 1])
//            {
//                dp[i] = dp[i - 1] + 1;
//            }
//            result = result > dp[i] ? result : dp[i];
//        }
//        return result;
//    }
//};
////43��ظ�������
//class Solution43 {
//public:
//    int findLength(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
//        int result = 0;
//        for (int i = 1; i <= nums1.size(); i++)
//        {
//            for (int j = 1; j <= nums2.size(); j++)
//            {
//                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//                result = result > dp[i][j] ? result : dp[i][j];
//            }
//        }
//        return result;
//    }
//};
//
////44�����������
//class Solution44 {
//public:
//    int longestCommonSubsequence(string text1, string text2)
//    {
//        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
//        for (int i = 1; i <= text1.size(); i++)
//        {
//            for (int j = 1; j <= text2.size(); j++)
//            {
//                if (text1[i - 1] == text2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
//                else
//                {
//                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//                }
//            }
//        }
//        return dp[text1.size()][text2.size()];
//    }
//};
//
////45���ཻ����
//class Solution45 {
//public:
//    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
//        for (int i = 1; i <= nums1.size(); i++)
//        {
//            for (int j = 1; j <= nums2.size(); j++)
//            {
//                if (nums1[i - 1] == nums2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
//                else
//                {
//                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//                }
//            }
//        }
//        return dp[nums1.size()][nums2.size()];
//    }
//};
//
////46��������
//class Solution46
//{
//public:
//    int maxSubArray(vector<int>& nums)
//    {
//        if (nums.size() == 0)return 0;
//        vector<int> dp(nums.size(), 0);
//        dp[0] = nums[0];
//        int result = nums[0];
//        for (int i = 1; i < nums.size(); i++)
//        {
//            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//            result = result > dp[i] ? result : dp[i];//���½��
//        }
//        return result;
//    }
//};
////47�ж�������
//class Solution47 {
//public:
//    bool isSubsequence(string s, string t)
//    {
//        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
//        for (int i = 1; i <= s.size(); i++)
//        {
//            for (int j = 1; j <= t.size(); j++)
//            {
//                if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
//                else dp[i][j] = dp[i][j - 1];
//            }
//        }
//        if (dp[s.size()][t.size()] == s.size())return true;
//        return false;
//    }
//};
////48��ͬ��������
//class Solution48 {
//public:
//    int numDistinct(string s, string t)
//    {
//        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
//        for (int i = 0; i <= s.size(); i++)dp[i][0] = 1;
//        for (int j = 1; j <= t.size(); j++)dp[0][j] = 0;
//        for (int i = 1; i <= s.size(); i++)
//        {
//            for (int j = 1; j <= t.size(); j++)
//            {
//                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//                else dp[i][j] = dp[i - 1][j];
//            }
//        }
//        return dp[s.size()][t.size()];
//    }
//};
//
//
////49�����ַ�����ɾ������
//class Solution49 {
//public:
//    int minDistance(string word1, string word2)
//    {
//        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//        for (int i = 0; i <= word1.size(); i++)dp[i][0] = i;
//        for (int j = 1; j <= word2.size(); j++)dp[0][j] = j;
//        for (int i = 1; i <= word1.size(); i++)
//        {
//            for (int j = 1; j <= word2.size(); j++)
//            {
//                if (word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
//                else dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
//            }
//        }
//        return dp[word1.size()][word2.size()];
//    }
//};
//
////50�༭����
//class Solution50 {
//public:
//    int minDistance(string word1, string word2)
//    {
//        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//        for (int i = 0; i <= word1.size(); i++)dp[i][0] = i;
//        for (int j = 1; j <= word2.size(); j++)dp[0][j] = j;
//        for (int i = 1; i <= word1.size(); i++)
//        {
//            for (int j = 1; j <= word2.size(); j++)
//            {
//                if (word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
//                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//            }
//        }
//        return dp[word1.size()][word2.size()];
//    }
//};
//
////52�����Ӵ�
//class Solution52 {
//public:
//    int countSubstrings(string s)
//    {
//        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//        int result = 0;
//        for (int i = s.size() - 1; i >= 0; i--)
//        {
//            for (int j = i; j < s.size(); j++)
//            {
//                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
//                {
//                    result++;
//                    dp[i][j] = true;
//                }
//            }
//        }
//        return result;
//    }
//};
////53���������
//class Solution53 {
//public:
//    int longestPalindromeSubseq(string s)
//    {
//        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
//        for (int i = 0; i < s.size(); i++)dp[i][i] = 1;
//        for (int i = s.size() - 1; i >= 0; i--)
//        {
//            for (int j = i + 1; j < s.size(); j++)
//            {
//                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
//                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//            }
//        }
//        return dp[0][s.size() - 1];
//
//    }
//};
//int main10()
//{
//    Solution36 s;
//    vector<int> prices = { 1,2,3,4,5 };
//    int k = 2;
//    s.maxProfit(k, prices);
//	system("pause");
//	return 0;
//}