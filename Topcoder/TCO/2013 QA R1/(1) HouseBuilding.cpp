#line 2 "HouseBuilding.cpp"
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
using namespace std;
#define CC(con, v) memset(con, v, sizeof(con))
#define REP(i, l, n) for(int i = l;i < int(n);++i)
#define FOREACH(con, i) for(__typeof(con.begin()) i = con.begin();i != con.end();++i)
template<class T>bool checkmax(T &a,T b){return a < b ? a = b, 1 : 0;}
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
typedef long long LL;
const int INF = 100000;
class HouseBuilding {
  public:
  int getMinimum(vector <string> area) {
    int n = area.size(), m = area[0].size();
    int result = INF;
    for(int height = 0;height < 10;height++) {
      int temp = 0;
      for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
          int v = area[i][j] - '0';
          if(v >= height) {
            temp += (v - height);
          } else {
            temp += (height - 1 - v);
          }
        }
      }
      checkmin(result, temp);
    }
    return result;
  }
  
 
};
 
 
// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
