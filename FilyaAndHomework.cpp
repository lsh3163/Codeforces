#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
map<int, int> visited;
int main(){
	int n;
	cin >> n;
	int cnt = 0;
	vector<int> check;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (visited.count(x) != 0){
			continue;
		}
		else if (visited.count(x)==0){
			visited[x] = 1;
			check.push_back(x);
		}
	}
	bool answer = false;
	int s = check.size();
	if (s == 3){
		sort(check.begin(), check.end());
		if (abs(check[0] - check[1]) == abs(check[1] - check[2])){
			answer = true;
		}
	}
	else if (s == 2){
		answer = true;
	}
	else if (s == 1){
		answer = true;
	}
	if (answer){
		printf("YES");
	}
	else{
		printf("NO");
	}

	return 0;
}
