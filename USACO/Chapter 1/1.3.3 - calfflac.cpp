/*
  ID   : 900831f1
  PROG : calfflac
  LANG : C++
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
template<class T>bool checkmax(T &a,T b) { return a < b ? a = b, 1 : 0; }
template<class T>bool checkmin(T &a,T b) { return a > b ? a = b, 1 : 0; }
const int BUF_SIZE = 20480;
char buffer[BUF_SIZE + 1];

void copy(char * target, int * pos, const char * source, int length) {
	for(int i = 0;i < length;i++) {
		if(isalpha(source[i])) {
			*target++ = tolower(source[i]);
			*pos++    = i;
		}
	}
	*target++ = 0;
}
char used[BUF_SIZE];
int  pos [BUF_SIZE];
char * get_palindrome(const char * ptr, int length, int & result) {
	result = 0;
	copy(used, pos, ptr, length);
	int n = strlen(used), begin = 0, end = 1;
	//odd
	for(int i = 0, j;i < n;i++) {
		for(j = 0;i + j < n && i - j >= 0 && used[i + j] == used[i - j];j++) ;
		j--;
		if(checkmax(result, j * 2 + 1)) {
			begin = pos[i - j];
			end   = pos[i + j] + 1;
		} else if(result == j * 2 + 1 && checkmin(begin, pos[i - j]))  {
			end   = pos[i + j] + 1;
		}
	}
	//even
	for(int i = 0, j;i < n;i++) {
		for(j = 1;i + j - 1 < n && i - j >= 0 && used[i + j - 1] == used[i - j];j++) ;
		j--;
		if(checkmax(result, j * 2)) {
			begin = pos[i - j];
			end   = pos[i + j - 1] + 1;
		} else if(result == j * 2 && checkmin(begin, pos[i - j])) {
			end   = pos[i + j - 1] + 1;
		}
	}
	return strndup(ptr + begin, end - begin);
}
int main() {
	FILE * fin  = fopen("calfflac.in",  "r");
	FILE * fout = fopen("calfflac.out", "w");
	char ch, * buffer_ptr = buffer;
	while((ch = fgetc(fin)) != EOF) {
		*buffer_ptr++ = ch;
	}
	*buffer_ptr = 0;
	int length = (buffer_ptr - buffer) / sizeof(char), result;
	char * ptr = get_palindrome(buffer, length, result);
	fprintf(fout, "%d\n%s\n", result, ptr);
	free(ptr);
	return 0;
}
