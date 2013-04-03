#line 2 "EllysBulls.cpp"
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
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
class EllysBulls {
public:
    void get_digit(vector<string>& digits, int len) {
        int n = 1;
        for(int i = 0;i < len;i++) {
            n *= 10;
        }
        char buffer[129];
        for(int i = 0;i < n;i++) {
            sprintf(buffer, "%0*d", len, i);
            digits.push_back(buffer);
        }
    }
    string match_start(const string& number, const vector<string>& guesses, const vector<int>& bulls) {
        string result;
        int n = number.size(), m = guesses.size();
        REP(i, 0, m) {
            int match = 0;
            REP(j, 0, n) {
                match += (guesses[i][j] == number[j]);
            }
            if(match > bulls[i]) {
                return string();
            }
            result.push_back(char(match + '0'));
        }
        return result;
    }
    string match_end(const string& number, const vector<string>& guesses, const vector<int>& bulls) {
        string result;
        int n = number.size(), m = guesses.size();
        REP(i, 0, m) {
            int match = 0;
            REP(j, 0, n) {
                match += (guesses[i][guesses[i].size() - 1 - j] == number[n - j - 1]);
            }
            if(match > bulls[i]) {
                return string();
            }
            result.push_back(char(match + '0'));
        }
        return result;
    }
    string getNumber(vector <string> guesses, vector <int> bulls) {
        int n = guesses[0].size(), m = bulls.size();
        int lhs = n / 2, rhs = n - n / 2;
        vector<string> ldights, rdights;
        get_digit(ldights, lhs);
        get_digit(rdights, rhs);
        map<string, string> lhs_map;
        FOREACH(ldights, i) {
            string info = match_start(*i, guesses, bulls);
            if(info != string()) {
                string & ref = lhs_map[info];
                if(ref == string()) {
                    ref = *i;
                } else {
                    ref = "Ambiguity";
                }
            }
        }
        string result = "Liar";

        FOREACH(rdights, i) {
            string info = match_end(*i, guesses, bulls);
            if(info == string()) continue;
            for(int j = 0;j < m;j++) {
                info[j] = bulls[j] - (info[j] - '0') + '0';
            }
            map<string, string>::iterator j = lhs_map.find(info);
            if(j != lhs_map.end()) {
                if(j->second == "Ambiguity") {
                    return j->second;
                } if(result == "Liar") {
                    result = j->second + *i;
                } else {
                    return "Ambiguity";
                }
            }
        }
        return result;
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1337"; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0000", "1111", "2222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Liar"; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"666666", "666677", "777777", "999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Ambiguity"; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "987", "654", "321", "100", "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 0, 0, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "007"; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "54"; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "4266642"; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    EllysBulls ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
