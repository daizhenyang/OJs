#include <cstring>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>
#include <cassert>
#include <cmath>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
class CatchTheMice {
	public:
	vector<double> below, above;
	void doit(double p, double v, double l) {
		if(v == 0) {
			if(fabs(p) >= l) {
				above.push_back(0);
			}
		} else if(v > 0) {
			if(p > 0) {
				above.push_back((l - p) / v);
			} else {
				if(-p >= l) {
					below.push_back((-l - p) / v);
				}
				above.push_back((l - p) / v);
			}
		} else {
			assert(v >= 0);
		}
	}
	bool judge(const vector<int>& xp, const vector<int>& yp, const vector<int>& xv, const vector<int>& yv, double l) {
		below.clear();
		above.clear();
		int n = xp.size();
		for(int i = 0;i < n;i++) {
			for(int j = i + 1;j < n;j++) {
				if(xv[i] >= xv[j]) {
					doit(xp[i] - xp[j], xv[i] - xv[j], l);
				} else {
					doit(xp[j] - xp[i], xv[j] - xv[i], l);
				}
				if(yv[i] >= yv[j]) {
					doit(yp[i] - yp[j], yv[i] - yv[j], l);
				} else {
					doit(yp[j] - yp[i], yv[j] - yv[i], l);
				}
			}
		}
//		cout << "below" << endl;
//		copy(below.begin(), below.end(), ostream_iterator<int>(cout, " ")); cout << endl;
//		cout << "above" << endl;
//		copy(above.begin(), above.end(), ostream_iterator<int>(cout, " ")); cout << endl;
//		printf("%d %d\n", below.size(), above.size());
		if(below.size() == 0) {
			if(above.size() == 0) {
				return false;
			} else {
				return *min_element(above.begin(), above.end()) <= 0;
			}
		} else {
			return *max_element(below.begin(), below.end()) >= *min_element(above.begin(), above.end());
		}
	}
	double largestCage(vector<int> xp, vector<int> yp, vector<int> xv, vector<int> yv) {
		double l = 0, r = 1e10, res = -1;
		REP(k, 0, 200) {
			double mid = (l + r) / 2;
			if(judge(xp, yp, xv, yv, mid)) {
				res = mid;
				l = mid;
			} else {
				r = mid;
			}
		}
		return res;
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,-10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(0, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,10,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,-6,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,5,-4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3.0; verify_case(1, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {50,10,30,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,30,20,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-5,-10,-15,-5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {40,-10,-1,-50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 40.526315789473685; verify_case(2, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,10,10,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,-1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,0,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(3, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {13,50,100,40,-100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,20,-150,-40,63}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,50,41,-41,-79}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,3,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 212.78688524590163; verify_case(4, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(5, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {-49,-463,-212,-204,-557,-67,-374,-335,-590,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {352,491,280,355,129,78,404,597,553,445}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-82,57,-23,-32,89,-72,27,17,100,-94}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-9,-58,9,-14,56,75,-32,-98,-81,-43}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 25.467532467532468; verify_case(6, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	CatchTheMice ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
