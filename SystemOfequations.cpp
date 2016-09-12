#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n, m;
int main(){
	cin >> n >> m;
	int ans = 0;
	for (int a = 0; a <= 1000; a++){
		for (int b = 0; b <= 1000; b++){
			int checkn = a*a + b;
			int checkm = a + b*b;
			if (checkn == n && checkm == m){
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
