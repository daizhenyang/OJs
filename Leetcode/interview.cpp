#include <iostream>
#include <cassert>
#include <cstddef>
#include <set>
#include <sstream>
#include <stack>
#include <cstring>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
	public:
		void rotate(vector<vector<int> > &matrix) {
			int n = matrix.size();
			for(int i = 0;i < n;i++) {
				for(int j = i;j < n - i - 1;j++) {
					int value = matrix[i][j];
					for(int k = 0;k < 4;k++) {
						swap(i, j);
						j = n - 1 - j;
						swap(value, matrix[i][j]);
					}
				}
			}
		}
		bool isPalindrome(int x) {
			if(x < 0) return false;
			int div = 1;
			while(x / div >= 10) {
				div *= 10;
			}
			while(x) {
				int l = x / div;
				int r = x % 10;
				if(l != r) return false;
				x = (x % div) / 10;
				div /= 100;
			}
		}
		ListNode *partition(ListNode *head, int x) {
			ListNode * lower_head = NULL, * lower_tail = NULL;
			ListNode * upper_head = NULL, * upper_tail = NULL;
			while(head) {
				if(head->val < x) {
					lower_tail = lower_head == NULL ?
						lower_head = new ListNode(head->val) : lower_tail->next = new ListNode(head->val);
				} else {
					upper_tail = upper_head == NULL ?
						upper_head = new ListNode(head->val) : upper_tail->next = new ListNode(head->val);
				}
				head = head->next;
			}
			if(lower_head == NULL) return upper_head;
			lower_tail->next = upper_head;
			return lower_head;
		}
		vector<int> plusOne(vector<int> &digits) {
			int c = 1, n = digits.size();
			for(int i = n - 1;i >= 0;i--) {
				digits[i] = (c + digits[i]) % 10;
				c = (c + digits[i]) / 10;
			}
			vector<int> res;
			if(c) {
				res.push_back(c);
			}
			copy(digits.begin(), digits.end(), back_inserter<vector<int> >(res));
			return res;
		}
		int threeSumClosest(vector<int> &num, int target) {
			sort(num.begin(), num.end());
			int res = -1;
			for(vector<int>::iterator i = num.begin();i != num.end();++i) {
				for(vector<int>::iterator j = i + 1;j != num.end();++j) {
					vector<int>::iterator k = lower_bound(j + 1, num.end(), target - *i - *j);
					if(k != num.end()) {
						int v = *i + *j + *k;
						if(res == -1 || abs(v - target) < res) {
							res = abs(v - target);
						}
					}
					if(k != num.begin() && k != j + 1) {
						k--;
						int v = *i + *j + *k;
						if(res == -1 || abs(v - target) < res) {
							res = abs(v - target);
						}
					}
				}
			}
			return abs(target - res);
		}
		struct sum {
			int v;
			pair<int, int> p;
			bool operator < (const sum& oth) const {
				return v == oth.v ? p < oth.p : v < oth.v;
			}
			sum(int v = 0, int idx0 = 0, int idx1 = 0) {
				if(idx0 > idx1) swap(idx0, idx1);
				this->v = v;
				p = make_pair(idx0, idx1);
			}
		};
		bool compare(const pair<int, int>& p1, const pair<int, int>& p2) const {
			return p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second;
		}
		vector<vector<int> > fourSum(vector<int> &num, int target) {
			sort(num.begin(), num.end());
			vector<sum> p;
			set<vector<int> > res;
			int n = num.size();
			for(int i = 0;i < n;i++) {
				for(int j = i + 1;j < n;j++) {
					p.push_back(sum(num[i] + num[j], i, j));
				}
			}
			int m = p.size();
			sort(p.begin(), p.end());
			for(int i = 0;i < m;i++) {
				int beg = lower_bound(p.begin(), p.end(), sum(target - p[i].v, 0, 0)) - p.begin();
				int end = lower_bound(p.begin(), p.end(), sum(target - p[i].v + 1, 0, 0)) - p.begin();
				for(int j = beg;j < end;j++) {
					if(compare(p[i].p, p[j].p)) {
						int v [] = {num[p[i].p.first], num[p[i].p.second], num[p[j].p.first], num[p[j].p.second]};
						sort(v, v + 4);
						res.insert(vector<int>(v, v + 4));
					}
				}
			}
			vector<vector<int> > ret;
			copy(res.begin(), res.end(), back_inserter<vector<vector<int> > >(ret));
			return ret;
		}
		string addBinary(string a, string b) {
			int v = max(a.size(), b.size());
			a.insert(0, v - a.size(), '0');
			b.insert(0, v - b.size(), '0');
			string res(v, '0');
			int c = 0;
			for(int i = v - 1;i >= 0;i--) {
				int v = a[i] - '0' + b[i] - '0' + c;
				c = v / 2;
				res[i] += v % 2;
			}
			if(c) {
				res.insert(0, 1, '1');
			}
			return res;
		}
		int get_value(ListNode * & l) {
			int v = 0;
			if(l != NULL) {
				v = l->val;
				l = l->next;
			}
			return v;
		}
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			ListNode * res = new ListNode(0);
			ListNode * ret = res;
			int c = 0;
			while(l1 != NULL || l2 != NULL) {
				int v = get_value(l1) + get_value(l2) + c;
				c = v / 10;
				res->next = new ListNode(v % 10);
				res = res->next;
			}
			if(c) {
				res->next = new ListNode(c);
			}
			return ret->next;
		}
		vector<string> anagrams(vector<string> &strs) {
			map<string, int> count;
			int n = strs.size();
			for(int i = 0;i < n;i++) {
				string s = strs[i];
				sort(s.begin(), s.end());
				count[s]++;
			}
			vector<string> res;
			for(int i = 0;i < n;i++) {
				string s = strs[i];
				sort(s.begin(), s.end());
				if(count[s] > 1) {
					res.push_back(strs[i]);
				}
			}
			return res;
		}
		vector<int> inorderTraversal(TreeNode *root) {
			stack<TreeNode *> stk;
			vector<int> res;
			TreeNode * tmp = root;
			while(tmp != NULL || stk.empty() == false) {
				while(tmp != NULL) {
					stk.push(tmp);
					tmp = tmp->left;
				}
				tmp = stk.top();
				stk.pop();
				res.push_back(tmp->val);
				tmp = tmp->right;
			}
			return res;
		}
		int climbStairs(int n) {
			vector<int> res(n + 1);
			res[0] = 1;
			for(int i = 1;i <= n;i++) {
				res[i] += res[i - 1];
				if(i >= 2) res[i] += res[i - 2];
			}
			return res[n];
		}
		vector<vector<int> > sumres;
		void dfs(const vector<int>& candidates, vector<int> res, int dep, int rest) {
			if(rest == 0) {
				sumres.push_back(res);
				return;
			}
			if(dep == int(candidates.size())) {
				return;
			}
			dfs(candidates, res, dep + 1, rest);
			while(rest - candidates[dep] >= 0) {
				res.push_back(candidates[dep]);
				dfs(candidates, res, dep + 1, rest -= candidates[dep]);
			}
		}
		vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
			sort(candidates.begin(), candidates.end());
			candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
			sumres.clear();
			dfs(candidates, vector<int>(), 0, target);
			return sumres;
		}
		set<vector<int> > sumset;
		void dfs2(const vector<int>& candidates, vector<int> res, int dep, int rest) {
			if(rest == 0) {
				sumset.insert(res);
				return;
			}
			if(dep == int(candidates.size())) {
				return;
			}
			dfs2(candidates, res, dep + 1, rest);
			if(rest >= candidates[dep]) {
				res.push_back(candidates[dep]);
				dfs2(candidates, res, dep + 1, rest - candidates[dep]);
			}
		}
		vector<vector<int> > combinationSum2(vector<int> &num, int target) {
			sort(num.begin(), num.end());
			sumres.clear();
			sumset.clear();
			dfs2(num, vector<int>(), 0, target);
			copy(sumset.begin(), sumset.end(), back_inserter<vector<vector<int> > >(sumres));
			return sumres;
		}
		void combin_n_k(vector<vector<int> >& res, vector<int>& num, int n, int k, int cur, int select) {
			if(select == k) {
				res.push_back(num);
				return;
			}
			if(cur == n) {
				return ;
			}
			combin_n_k(res, num, n, k, cur + 1, select);
			num.push_back(cur + 1);
			combin_n_k(res, num, n, k, cur + 1, select + 1);
			num.pop_back();
		}
		vector<vector<int> > combine(int n, int k) {
			vector<vector<int> > res;
			vector<int> num;
			combin_n_k(res, num, n, k, 0, 0);
			return res;
		}
		int maxArea(vector<int> &height) {
			int n = height.size();
			int res = 0;
			int beg = 0, end = n - 1;
			while(beg < end) {
				res = max(res, min(height[beg], height[end]) * (end - beg));
				if(height[beg] < height[end]) {
					beg++;
				} else {
					end--;
				}
			}
			return res;
		}
		string countAndSay(int n) {
			string res = "1", tmp;
			for(int i = 1;i < n;i++) {
				ostringstream sout;
				int len = res.size();
				for(int i = 0, j;i < len;i = j) {
					for(j = i;j < len && res[i] == res[j];j++);
					sout << (j - i) << res[i];
				}
				res = sout.str();
			}
			return res;
		}
		int todigit(char ch0, char ch1) {
			return (ch0 - '0') * 10 + ch1 - '0';
		}
		int numDecodings(string s) {
			int n = s.size();
			vector<int> dp(n + 1);
			dp[0] = 1;
			for(int i = 1;i <= n;i++) {
				if(s[i - 1] != '0') {
					dp[i] += dp[i - 1];
				}
				if(i > 1 && '0' < s[i - 2] && todigit(s[i - 2], s[i - 1]) <= 26) {
					dp[i] += dp[i - 2];
				}
			}
			return n == 0 ? 0 : dp[n];
		}
		int firstMissingPositive(int A[], int n) {
			for(int i = 0;i < n;i++) {
				while(1 <= A[i] && A[i] <= n && A[A[i] - 1] != A[i]) {
					swap(A[i], A[A[i] - 1]);
				}
			}
			for(int i = 0;i < n;i++) {
				if(A[i] != i + 1) {
					return i + 1;
				}
			}
			return n + 1;
		}
		char *strStr(char *haystack, char *needle) {
			int m = strlen(needle);
			if(m == 0) return haystack;
			vector<int> next(m);
			int k = -1, q = -1;
			next[0] = -1;
			for(int i = 1;i < m;i++) {
				while(k != -1 && needle[k + 1] != needle[i]) k = next[k];
				if(needle[k + 1] == needle[i]) k++;
				next[i] = k;
			}
			for(char * str = haystack;*str;str++) {
				while(q > -1 && *str != needle[q + 1]) q = next[q];
				if(needle[q + 1] == *str) q++;
				if(q == m - 1) return str - m + 1;
			}
			return NULL;
		}
		bool isMatch(const char *s, const char *p) {
			if (*p == '\0') return *s == '\0';
			if (*(p+1) != '*') {
				return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
			} else {
				while ((*p == *s) || (*p == '.' && *s != '\0')) {
					if (isMatch(s, p+2)) return true;
					s++;
				}
				return isMatch(s, p+2);
			}
		}
		bool isInterleave(string s1, string s2, string s3) {
			int n = s1.size(), m = s2.size(), len = s3.size();
			if(s1.size() + s2.size() != s3.size()) return false;
			vector<vector<bool> > dp(n + 1, vector<bool>(m + 1));
			dp[0][0] = true;
			for(int i = 0;i < len;i++) {
				for(int j = max(0, i - m);j <= i && j <= n;j++) {
					int k = i - j;
					if(dp[j][k] == false) continue;
					if(j < n && s3[i] == s1[j]) dp[j + 1][k] = true;
					if(k < m && s3[i] == s2[k]) dp[j][k + 1] = true;
				}
			}
			return dp[n][m];
		}
		void generate(int l, int r, int dep, char* buf, vector<string>& res) {
			if(l == 0 && r == 0) {
				buf[dep] = 0;
				res.push_back(buf);
				return;
			}
			if(l != 0) {
				buf[dep] = '(';
				generate(l - 1, r, dep + 1, buf, res);
			}
			if(l < r) {
				buf[dep] = ')';
				generate(l, r - 1, dep + 1, buf, res);
			}
		}
		vector<string> generateParenthesis(int n) {
			char* buf = new char[(n << 1) | 1];
			vector<string> res;
			generate(n, n, 0, buf, res);
			delete buf;
			return res;
		}
		vector<int> grayCode(int n) {
			vector<int> res(1 << n);
			for(int i = 1;i < (1 << n);i++) {
				res[i] = i ^ (i >> 1);
			}
			return res;
		}
		vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
			int l = newInterval.start, r = newInterval.end, n = intervals.size(), ins = 0;
			vector<Interval> res;
			for(int i = 0;i < n;i++) {
				if(intervals[i].end < l) {
					res.push_back(intervals[i]);
				} else if(intervals[i].start > r) {
					if(ins == 0) {
						res.push_back(Interval(l, r));
						ins++;
					}
					res.push_back(intervals[i]);
				} else {
					l = min(l, intervals[i].start);
					r = max(r, intervals[i].end);
				}
			}
			if(ins == 0) res.push_back(Interval(l, r));
			return res;
		}
		bool canJump(int A[], int n) {
			int maxn = 0;
			for(int i = 0;i < n && i <= maxn;i++) {
				maxn = max(maxn, A[i] + i);
			}
			return maxn >= n - 1;
		}
		int jump(int A[], int n) {
			int res = 0;
			for(int i = 0, j = 1, pos;j < n;i = j, j = pos + 1){
				pos = j;
				for(int k = i;k < j;k++) {
					pos = max(pos, A[k] + k);
				}
				res++;
			}
			return res;
		}
		int lengthOfLastWord(const char *s) {
			int res = -1, pre = 0;
			for(const char* str = s;*str;str++) {
				if(*str == ' ' && res != -1) {
					pre = res;
					res = -1;
				}
				if(isalpha(*str)) {
					res = (res == -1) ? 1 : res + 1;
				}
			}
			return res == -1 ? pre : res;
		}
		string longestCommonPrefix(vector<string> &strs) {
			int n = strs.size();
			if(n == 0) {
				return "";
			}
			vector<int> res(n);
			int pos = 0;
			for(int i = 1;i < n;i++) {
				if(strs[i].size() < strs[pos].size()) {
					pos = i;
				}
			}
			for(int i = 0;i < n;i++) {
				size_t j = 0;
				while(j < strs[pos].size() && j < strs[i].size() && strs[pos][j] == strs[i][j]) {
					j++;
				}
				res[i] = j;
			}
			int length = *min_element(res.begin(), res.end());
			return strs[pos].substr(0, length);
		}
		string longestPalindrome(string s) {
			int n = s.size();
			int max_length = 0, idx = 0;
			for(int i = 0, j;i < n;i++) {
				for(j = 0;i - j >= 0 && i + j < n && s[i - j] == s[i + j];j++);
				j--;
				if(max_length < j * 2 + 1) {
					max_length = j * 2 + 1;
					idx = i - j;
				}
			}
			for(int i = 0, j;i < n;i++) {
				for(j = 1;i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j];j++);
				j--;
				if(max_length < j * 2) {
					max_length = j * 2;
					idx = i - j + 1;
				}
			}
			return s.substr(idx, max_length);
		}
		int lengthOfLongestSubstring(string s) {
			int res = 0, pre = 0, n = s.size();
			int used[26] = {0};
			for(int i = 0;i < n;i++) {
				while(used[s[i] - 'a']) {
					used[s[pre++] - 'a'] = false;
				}
				used[s[i] - 'a'] = true;
				res = max(res, i - pre + 1);
			}
			return res;
		}
		int longestValidParentheses(string s) {
			stack<int> stk;
			int n = s.size(), res = 0, pre = -1;
			for(int i = 0;i < n;i++) {
				if(s[i] == '(') {
					stk.push(i);
				} else if(stk.size() != 0) {
					stk.pop();
					res = max(res, stk.empty() ? i - pre : i - stk.top());
				} else {
					pre = i;
				}
			}
			return res;
		}
		int divide(int dividend, int divisor) {
			int neg = 0, res = 0;
			neg ^= (divisor < 0);
			neg ^= (dividend < 0);
			unsigned int end = dividend < 0 ? -dividend : dividend;
			unsigned int sor = divisor < 0 ? -divisor : divisor;
			unsigned int mod = 0;
			for(int i = 31;i >= 0;i--) {
				res <<= 1;
				mod = (mod << 1) + ((end & (1u << i)) >> i);
				if(mod >= sor) {
					res |= 1;
					mod -= sor;
				}
			}
			return neg ? -res : res;
		}
		double pow(double x, int n) {
			bool is_neg = n < 0;
			double res = 1;
			unsigned int N = n < 0 ? (-n) : n;
			while(N != 0) {
				if(N & 1) res *= x;
				N >>= 1;
				x *=x;
			}
			return is_neg ? 1 / res : res;
		}
		int sqrt(int x) {
			int low = 0, high = 65536, res = 0;
			while(low <= high) {
				int mid = (low + high) >> 1;
				if(1LL * mid * mid <= x) {
					res = mid;
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			return res;
		}
}one;
int main() {
	one.longestPalindrome("bb");
	return 0;
}
