#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int nc, np;
	int ans = 0;
	scanf("%d", &nc);
	vector<int>c (nc);
	for(int i = 0; i<nc; i++)
		scanf("%d", &c[i]);
	scanf("%d", &np);
	vector<int>p (np);
	for(int i = 0; i<np; i++)
		scanf("%d", &p[i]);
	sort(c.begin(), c.end());
	sort(p.begin(), p.end());
	int m = 0, n = 0;
	while(m<nc && n<np && c[m]<0 && p[n] < 0)
		ans += c[m++] * p[n++];
	m = nc-1, n = np - 1;
	while(m>=0 && n>=0 && c[m]>0 && p[n] > 0)
		ans+= c[m--] * p[n--];
	printf("%d", ans);
	return 0;
}
