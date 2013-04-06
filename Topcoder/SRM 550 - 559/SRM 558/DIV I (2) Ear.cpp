#line 2 "Ear.cpp"
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
#include <iterator>
#include <utility>
#include <cassert>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
struct Point {
    int x, y;
    Point(int xx = 0, int yy = 0)
    {x = xx, y = yy;}
    bool operator <(const Point a) const
    {return y == a.y ? x < a.x : y < a.y;}
    friend ostream& operator << (ostream& out, Point a) {
        out << "(" << a.x << " " << a.y << ")";
        return out;
    }
};
int dblcmp(int x) {
    if(x == 0) return 0;
    return x < 0 ? -1: 1;
}
int det(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}
double cross(const Point& a, const Point& b, const Point& c)/*ab x ac*/ {
    return det(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
}
template<class T> void string_reader(const string& s, vector<T>& vec){
    istringstream sin(s);
    copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
const int N = 310;
class Ear {
public:
    long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
        vector<int> rx, bx, by;
        string_reader(accumulate(redX.begin(), redX.end(), string()), rx);
        string_reader(accumulate(blueX.begin(), blueX.end(), string()), bx);
        string_reader(accumulate(blueY.begin(), blueY.end(), string()), by);

        LL res = 0;
        int n = rx.size(), m = bx.size();
        vector<Point> blue;

        REP(i, 0, m) blue.push_back(Point(bx[i], by[i]));

        sort(blue.begin(), blue.end());
        sort(rx.begin(), rx.end());

        REP(p, 0, m) REP(q, 0, p) {
            // D on right side of q->p
            int startD = -1;
            REP(k, 0, n) {
                if(cross(blue[q], blue[p], Point(rx[k], 0)) < 0) {
                    startD = k;
                    break;
                }
            }
            int maxb = -1;
            REP(k, 0, n) {
                if(rx[k] < blue[q].x) maxb = k;
            }
            if(startD == -1 || maxb == -1) continue;
            for(int k = 0;k < n && rx[k] < blue[p].x;k++) {
                // A on left side of q->p
                if(cross(blue[q], blue[p], Point(rx[k], 0)) <= 0) continue;

                int startC = upper_bound(rx.begin(), rx.end(), blue[q].x) - rx.begin();
                int NB = max(0, maxb - k);
                int NC = n - startC;
                int ND = 0;
                if(startC != n) {
                    ND = n - (upper_bound(rx.begin() + max(startD, startC + 1), rx.end(), blue[p].x) - rx.begin());
                }
                LL add = NB * (ND * (ND - 1) / 2 + (NC - ND) * ND);
                res += add;
            }
        }
        return res;
    }

        // BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7 8 9 10 11 12 13"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"9994 9996 9998 10000 9999 9997 9995"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"3 2 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 2 6 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 6 8 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 5 4 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 4LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10000 9999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10000 9999"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"15", "0 250 ", "349"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4", " ", "5", " ", "6", " 7 ", "8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1", " 2 ", "3 4", " 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 204LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Ear ___test;
    ___test.run_test(0);
    return 0;
}
// END CUT HERE
