//#include<iostream>
//using namespace std;
//#include<vector>
//#include<unordered_set>
//#include<unordered_map>
//#include<algorithm>
//
//
////1反转字符串
//class Solution1
//{
//public:
//	void reverseString(vector<char>& str)
//	{
//		for (int i = 0,  j = str.size() - 1; i < str.size()/2;j--, i++)
//		{
//			int temp = 0;
//			temp = str[i];
//			str[i] = str[j];
//			str[j] = temp;
//		}
//	}
//};
//
////2.反转字符串②
//class Solution2
//{
//public:
//	//左闭右闭
//	void myreverse(string& s, int start, int end)
//	{
//		for (int i = start,j=end; i < j; i++,j--)
//		{
//			int temp = 0;
//			temp = s[i];
//			s[i] = s[j];
//			s[j] = temp;
//		}
//	}
//
//	string reverseStr(string& s, int k)
//	{
//		for (int i = 0; i < s.size(); i+=(2*k))
//		{
//			//k-2k
//			if (i+k<=s.size())
//			{
//				myreverse(s, i, i + k - 1);
//				//reverse(s.begin() + i, s.begin() + i + k);
//			}
//			else//0-k
//			{
//				myreverse(s, i, s.size() - 1);
//				//reverse(s.begin() + i, s.end());
//			}
//		}
//		return s;
//	}
//};
//
////3替换数字
//class Solution3
//{
//public:
//	void substituteNumber()
//	{
//		string s;
//		while (cin>>s)
//		{
//			//指向原字符串数组末位
//			int sOldIndex = s.size() - 1;
//			int count = 0;
//			for (int i = 0; i < s.size(); i++)
//			{
//				if (s[i] >= '0' && s[i] <= '9')
//				{
//					count++;
//				}
//			}
//			
//			s.resize(s.size() + count * 5);
//			//指向新字符串数组末位
//			int sNewIndex = s.size() - 1;
//			while (sOldIndex >= 0) 
//			{
//				if (s[sOldIndex]>='0'&&s[sOldIndex]<='9')
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
////4翻转字符串里的单词
//class Solution4
//{
//public:
//	//移除空格
//	void removeExtraSpaces(string& s)
//	{
//		int slowIndex = 0;
//		for (int i = 0; i <s.size(); i++)
//		{
//			if (s[i]!=' ')
//			{
//				if (slowIndex!=0)
//				{
//					s[slowIndex++] = ' ';
//				}
//				while (i < s.size() && s[i] != ' ')
//				{
//					s[slowIndex++] = s[i++];
//				}
//			}
//		}
//		s.resize(slowIndex);
//	}
//	//翻转字母---左闭右闭
//	void reverse(string& s, int start, int end)
//	{
//		for (int i = start,j = end; i < j; i++,j--)
//		{
//			int temp = s[i];
//			s[i] = s[j];
//			s[j] = temp;
//		}
//	}
//	//翻转单词
//	string reverseWords(string& s)
//	{
//		removeExtraSpaces(s);
//		reverse(s, 0, s.size() - 1);
//		int start = 0;
//		for (int i = 0; i <= s.size(); i++)
//		{
//			if (i==s.size()||s[i]==' ')
//			{
//				reverse(s, start, i - 1);
//				start = i + 1;
//			}
//		}
//		return s;
//	}
//};
//
////5右旋转字符串
//class Solution5
//{
//public:
//
//	void myreverse(string&s,int start,int end)
//	{
//		for (int i = start,j = end; i < j; i++,j--)
//		{
//			int temp = s[i];
//			s[i] = s[j];
//			s[j] = temp;
//		}
//	}
//	void rotateRight1(string& s, int n)//先整体后局部
//	{
//		int len = s.size();
//		myreverse(s, 0, len-1);
//		myreverse(s, 0, n - 1);
//		myreverse(s, n, len - 1);
//		cout << s << endl;
//	}
//	void rotateRight2(string& s, int n)//先局部后整体
//	{
//		int len = s.size();
//		myreverse(s, 0, len - n - 1);
//		myreverse(s, len - n, len - 1);
//		myreverse(s, 0, len - 1);
//		cout << s << endl;
//	}
//};
//
//
//
//int main() 
//{
//	//Solution3 s;
//	//s.substituteNumber();
//	Solution5 s5;
//	string s = "abcdefg";
//	s5.rotateRight2(s,2);
//	system("pause");
//	return 0;
//}