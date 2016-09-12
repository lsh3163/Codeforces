#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std; 
int main(){
	int n;
	cin >> n;
	vector<int> v;
	vector<pair<int, int> > ans;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++){
		int pushmin = 0x7fffffff;
		int pushmax = -1;
		if (i != 1 && i != n){
			pushmin = min(abs(v[i] - v[i + 1]), abs(v[i] - v[i - 1]));
			pushmax = max(abs(v[i] - v[1]), abs(v[i] - v[n]));
		}
		else if (i == 1){
			pushmin = abs(v[2] - v[1]);
			pushmax = abs(v[n] - v[1]);
		}
		else if (i == n){
			pushmin = abs(v[n] - v[n - 1]);
			pushmax = abs(v[n] - v[1]);
		}
		ans.push_back(make_pair(pushmin, pushmax));
	}
	int len = ans.size();
	for (int i = 0; i < len; i++){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
