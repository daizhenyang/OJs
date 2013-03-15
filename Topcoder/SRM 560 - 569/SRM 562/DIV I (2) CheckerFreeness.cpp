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
#include <cmath>
#include <cassert>
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
template<class T> void string_reader(const string& s, vector<T>& vec){
	istringstream sin(s);
	copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter(vec));
}
typedef long long LL;
struct Point {
	int x, y;
	Point(int xx = 0, int yy = 0)
	{x = xx, y = yy;}
	bool operator < (const Point a) const
	{return y == a.y ? x < a.x : y < a.y;}
};
LL dist(const Point& a, const Point& b) {
	return (a.x - b.x) * (a.x - b.x + 0LL) + (a.y - b.y) * (a.y - b.y + 0LL);
}
LL det(LL x1, LL y1, LL x2, LL y2) {
	return x1 * y2 - x2 * y1;
}
LL cross(const Point& a, const Point& b, const Point& c) {
	return det(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
}
int dblcmp(LL x) {
	if(x == 0) return 0;
	return x < 0 ? -1: 1;
}

void integer_parse(const vector<string>& s, vector<int>& vec) {
	vec.clear();
	int res = 0;
	FOREACH(s, j) FOREACH((*j), i) {
		if(isdigit(*i)) {
			res = res * 10 + (*i - '0');
		} else {
			vec.push_back(res);
			res = 0;
		}
	}
	vec.push_back(res);
}
const int N = 250;
double dst[N][N], sqt[N][N];
class CheckerFreeness {
	public:
	string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
		vector<int> wx, wy, bx, by;
		vector<Point> w, b;
		vector<pair<double, double> > lpos, rpos;
		integer_parse(whiteX, wx);
		integer_parse(whiteY, wy);
		integer_parse(blackX, bx);
		integer_parse(blackY, by);
		int n = wx.size(), m = bx.size();
		REP(i, 0, n) w.push_back(Point(wx[i], wy[i]));
		REP(i, 0, m) b.push_back(Point(bx[i], by[i]));
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				dst[i][j] = dist(w[i], b[j]);
				sqt[i][j] = sqrt(dst[i][j]);
			}
		}
		for(int i = 0;i < n;i++) {
			for(int j = i + 1;j < n;j++) {
				lpos.clear();
				rpos.clear();
				double lc  = dist(w[i], w[j]);
				double sqc = sqrt(double(lc));
				REP(k, 0, m) {
					double la = dst[i][k];
					double lb = dst[j][k];
					//s & f is cos(dgr)
					double s = (la + lc - lb) / (sqt[i][k] * sqc);
					double f = (lb + lc - la) / (sqt[j][k] * sqc);
					if(dblcmp(cross(w[i], w[j], b[k])) == 1) {
						lpos.push_back(make_pair(s, f));
					} else {
						rpos.push_back(make_pair(s, f));
					}
				}
				//dgr decreasing
				sort(lpos.begin(), lpos.end());
				//dgr increasing
				sort(rpos.begin(), rpos.end());
				double best = -10000;
				int ls = lpos.size(), rs = rpos.size();
				for(int k = 0, id = rs - 1;k < ls;k++) {
					while(id >= 0 && lpos[k].first + rpos[id].first > 0) {
						best = max(best, rpos[id].second);
						id--;
					}
					if(best + lpos[k].second > 0) {
						return "NO";
					}
				}
			}
		}
		return "YES";
	}

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "NO"; verify_case(0, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"2", "5", "3", " ", "1", "7", "3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"180 254"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"32", "5 1", "42"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"462 423"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(1, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1 10000000 9999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 9999999 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 5000000 9999998"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"2 5000001 9999999"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(2, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(3, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7"
		,"716 9645 2547 9490 9365 326 6601 5215 6771 7153 72"
,"93 5922 714 2258 4369 9524 302 8417 6620 1143"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"621 1611 7140 503 5345 7202 681 4908 2510 5908 279"
,"6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665"
,"4 446 3561 7241 6168 2025 4739 9501 5340 6446"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94"
,"24 5374 6718 2919 6068 6644 5070 710 7121 1630 370"
,"3 1051 5739 9294 8798 3371 8107 2130 6608 534"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 "
,"8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 "
,"7259 8842 5294 7209 2317 3825 3413 820 3774 5393"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "NO"; verify_case(4, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }

	void test_case_5() { string Arr0[] = 
	{"5833488 4224864 4225545 7807147 3159529 795259 110", "5990 2611680 1953607 2824656 7110298 9633063 83820", "10 4183599 559610 3962536 108264 3279385 5059492 8", "686057 7299214 8646592 3430749 8079040 4406527 526", "7893 4878993 6521326 4923493 1467361 1913466 65865", "54 370505 1351681 5240094 4555443 3715100 5745709 ", "3573806 9055911 2449041 4367993 1856249 1249781 49", "86332 6010551 9957325 4877968 807071 777411 572715", "9 2605343 2663116 3599051 6470975 624048 5786982 2", "70369 8858343 511249 7827793 2624670 8968611 37355", "57 8131854 1598734 2114548 3498255 6635014 9885597", " 1821708 8905654 1398150 7623096 1796899 9144309 2", "463310 1245676 5390884 1712565 1494318 285369 6305", "033 8983209 3864619 4562607 8458597 5104115 416250", "3 2918188 3304153 5488408 5003761 4163088 7595987 ", "1462801 1499062 553753 8695321 6895457 9684676 620", "5020 3695129 8873377 7866618 7233909 4803835 18358", "26 7497550 3006544 4448561 9740228 1392494 4601809", " 1945682 7033082 1848600 4092014 7662552 2529127 3", "81989 5161833 4091371 7713097 9899870 6965176 5693", "053 2042723 1944003 915105 1341589 9578312 2696675", " 6730104 9077620 7279136 3599624 9645095 1530297 5", "407106 6206550 446709 1545686 454926 1336570 12760", "90 6739969 3570574 7881686 3503970 7430530 6851294", " 1449091 58920 4959339 3707095 6245667 8387593 124", "5233 447157 7761816 3121428 5865251 3994660 780538", "4 7421193 469830 2548133 8988350 7170641 6989528 3", "063703 3150256 990620 1100169 6846472 3689434 8104", "758 6605200 6104121 1329736 3937103 2938835 645793", "5 7890610 3641040 9575776 9180351 8554042 8686214 ", "1202438 5629556 6980741 1897172 3355540 9739021 29", "49073 7320542 9259546 2134523 1038394 8685617 1010", "57 6339236 1014534 7009355 2387318 2082365 2322039", " 2479199 9648777 805372 5958744 4562090 3218096 36", "88822 820247 7400823 7253667 3348505 2641317 39684", "57"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = 
	{"4268168 4255937 3328104 2741237 3338514 3768359 71", "3348 2717241 4072768 4633327 243343 139449 2381920", " 2653418 895468 1712257 2778413 1496377 1862977 24", "36275 4581057 1448410 473553 4428883 389108 392002", "8 1702412 4882630 1996889 1943826 2629320 3174068 ", "4271558 1105152 3741189 2698128 3461514 3461952 43", "738 3384956 2169467 3908486 4449942 1948250 415566", "4 1338618 2871502 2516201 2428287 4738776 4216587 ", "518392 1507122 3266791 4236175 2534508 549189 2831", "312 2293493 1491815 1166874 649817 3998856 3543683", " 2650454 3447089 4665190 2636171 3936063 4139789 1", "098353 3705686 4375469 948040 4652458 823794 47339", "48 1821560 3951140 2547714 794398 5148431 4616994 ", "1361734 1628726 2029875 3965203 1250078 4370838 40", "40200 847262 2916228 681124 2053441 105911 455822 ", "1398514 2364 1511612 3740429 1196070 4863541 39187", "36 483134 1101897 4491144 4824243 2218350 1373675 ", "4077913 3972994 4079852 4966435 1158593 3718801 15", "46065 3738768 4146874 376506 3985771 2767408 45102", "61 3541846 406563 888041 130846 610365 2158759 314", "2499 853999 2475690 4609643 4242485 2964065 238263", "0 387894 4511583 177470 1906513 325743 4516487 265", "1161 236103 1896955 5104083 4384943 552631 1152933", " 2029014 3924095 3680889 2851164 3495217 1722732 3", "735154 3403043 893878 3975549 4762283 1369003 2651", "421 2461376 108663 2291722 4896430 1365764 1236013", " 2135218 1679120 36831 1935710 478293 4602948 1907", "697 1478381 3789346 4061278 417454 3947689 3165170", " 2324603 359093 2330045 1692093 2085226 4393228 32", "60247 610489 1330515 1989423 3487914 3065987 41736", "6 1406792 1117061 4300977 4228737 119843 3955545 5", "92524 1828987 3466467 772079 1506469 147004 380829", "2 4975453 213636 1219917 1095151 4656362 820991 87", "6053 715208 3831554 2629198 1931975 1739757 439888", " 4230430 610422 2031280"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = 
	{"8769055 6101858 2888614 8587626 6254070 7300225 73", "14471 1951171 9759062 8871385 5413786 8565891 2641", "818 757329 1649046 9411641 6086387 3942478 9467915", " 3814540 7213069 6217543 3792175 2812165 5964824 7", "443284 7718725 201854 8310505 8668833 2955269 3449", "784 6636151 2238383 8193810 7046539 416150 3619086", " 1981628 6072325 6937795 358500 4384923 3661354 21", "13662 259935 1117130 7375342 6656362 4725398 40332", "5 2810686 9676806 5037351 3551191 5906187 851541 1", "433630 2488245 1550102 8854673 6977002 1591062 799", "3206 4648644 4421463 5204065 7021257 9187904 27252", "01 3045182 4619041 7658594 4118705 2373074 872349 ", "8438721 5535736 254524 1911575 5530513 8148612 560", "6665 1329466 2620193 5011303 3180124 7111122 27550", "79 8105929 3661540 2964215 8157413 5347874 5066057", " 5279454 8436478 5482370 6159747 6807897 8316110 2", "366453 7331463 7449342 3008258 8184130 3178503 232", "4918 5333093 158931 4411920 376954 4584197 4966307", " 9026360 8117696 6896401 7375208 1413171 2557067 9", "15550 6809498 3163282 65143 8325013 8588740 714647", "2 1577665 3361481 5399173 9201449 3598246 7653777 ", "777575 3002693 2935592 4725408 3137175 422667 5305", "038 5945818 8981433 4167662 6536948 581068 2140828", " 4072077 7743922 6826702 2852147 7203638 897340 25", "10450 6443282 2466777 7255831 8934622 4928511 1546", "325 7047335 3811601 2279014 7830899 6971540 876115", "9 1419751 4037667 2866721 578469 6362048 397467 83", "53501 7261026 8043956 7944756 3911930 5478950 8540", "7 1362005 7501429 5369429 931802 3387547 4669665 5", "431259 803301 459974 4006187 2879018 4721061 30760", "66 222109 9469417 6155557 8109553 3928167 6089244 ", "6160755 7839580 5121353 6123678 6370395 5341792 90", "87601 8026208 1114760 5057762 261433 1491212 13953", "43 8473839 6013598 6618078 6479957 7544331 4049929", " 9834301 639453 7283550 5592606 1437010 8282757"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = 
	{"7035752 6026934 6788315 9205508 9253869 9927974 51", "28715 9493288 7478481 5155598 7192954 5852661 6057", "375 5708589 8777966 6574703 8347063 7701844 911273", "4 5229186 7685049 5375696 5173879 5471715 7721803 ", "6590534 6438157 5593511 6639678 7202922 8743204 88", "02038 9028050 8429248 8516738 6727216 6014367 6837", "476 6894972 6094121 5135523 8848405 7588407 983589", "7 7915132 6027286 5974889 5675004 9539525 7599131 ", "8290414 8681075 7895288 8224536 6428961 9315832 60", "88104 7736000 7146514 6656046 7983345 7086862 9397", "697 9705605 5147211 7980781 9824674 8582334 682991", "1 7908313 6022876 5606421 6886629 9517348 7279482 ", "6740874 5159920 6614985 9017309 6818971 6496945 63", "08905 5063179 7394930 7506526 7456141 9934872 7959", "671 9920193 8446618 7681809 6893363 9342212 801229", "5 5214337 9425061 7264320 8546570 9689690 6740528 ", "6242021 7715319 8125963 5173541 9790987 9288063 60", "31294 8132394 9186158 5738113 9415106 8980134 6280", "962 5477797 9903441 8272404 5888646 6909406 664792", "2 7170471 5149048 9989679 7425147 9013345 6357769 ", "8206743 9512690 6111557 5856214 8436262 6614925 61", "51949 9495691 8553877 6664937 9331307 7079878 5771", "802 9465034 7229112 6641524 8661049 8361436 822813", "5 6158968 8704124 7219889 5665615 8758074 8540086 ", "7383734 5554524 7259623 9560393 9901445 5120673 63", "87182 8734204 8257228 9244478 7072050 8012657 5052", "048 7277199 7758862 8602638 7538002 7605609 841950", "5 5942532 9706719 6092576 9167427 8140155 7139185 ", "5839599 8544324 6780031 9410600 6655243 8815579 62", "22762 7549602 9892388 7180207 7695946 6858813 5382", "831 6336047 8570564 9986617 6901926 8748167 964318", "3 7478619 9030968 8499765 7920987 6955964 7245647 ", "5820557 5560087 7208935 5455467 7000626 7909110 92", "93583 9104648 8337835 6879625 8173427 9565359 8780", "957 7005174 6751324 6115328 5168146 8325786 613400", "1 5726446 6170774 8308218"}
; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(5, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CheckerFreeness ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE