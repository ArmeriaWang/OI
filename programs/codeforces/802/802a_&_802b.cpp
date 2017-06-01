#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

 #define rep(i, a, b) for (int i = a; i <= b; i++)
 #define dep(i, a, b) for (int i = a; i >= b; i--)
 #define fill(a, x) memset(a, x, sizeof(a))
 #define pb push_back

 const int N = 400000 + 5, INF = 0x3f3f3f3f;

 int n, k, now, ans;
 int a[N], pnt[N];
 bool own[N];
 vector<int> app[N];

 struct Item {
 	int id, tim;
 	bool operator < (const Item x) const { return tim < x.tim; }
 };
 inline Item mkItem(int id, int tim) {
 	Item ret;
 	ret.id = id; ret.tim = tim;
 	return ret;
 }

 priority_queue<Item> Q;

 inline int get_cur_time(int x) { return ++pnt[x] >= app[x].size() ? INF : app[x][pnt[x]]; }

int main()
{
	scanf("%d%d", &n, &k);

	rep(i, 1, n) app[i].clear();
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		app[a[i]].pb(i);
	}
	fill(pnt, 0);

	while (!Q.empty()) Q.pop();
	Q.push(mkItem(a[1], get_cur_time(a[1])));
	ans = now = 1;
	own[a[1]] = true;
	rep(i, 2, n) {
		int x = a[i];
		if (!own[x]) {
			if (now == k) {
				while (!own[Q.top().id]) Q.pop();
				Item take = Q.top();
				Q.pop();
				own[take.id] = false;
				now--;
			}
			ans++;
			own[x] = true;
			Q.push(mkItem(x, get_cur_time(x)));
			now++;
		}
		else Q.push(mkItem(x, get_cur_time(x)));
	}
	printf("%d\n", ans);

	return 0;
}
