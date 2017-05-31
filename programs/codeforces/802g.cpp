#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

 #define rep(i, a, b) for (int i = a; i <= b; i++)

 const int N = 1000 + 5;

 int n, d[N][10];
 bool flag;
 string st, pat;

int main()
{
	freopen("802g.in", "r", stdin);

	cin >> st;
	int n = st.size();

	pat = "heidi";
	d[0][0] = 0;
	rep(i, 1, n)
		rep(j, 1, 5)
			d[i][j] = st[i - 1] == pat[j - 1] ? d[i - 1][j - 1] + 1 : max(d[i - 1][j], d[i][j - 1]);

	puts(d[n][5] == 5 ? "YES" : "NO");

	return 0;
}
