#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std; 
int main(){
	string s1;
	string s2;
	string s3="";
	cin >> s1;
	cin >> s2;
	int len = s1.size();
	for (int i = 0; i < len; i++){
		if (s1[i] == s2[i]){
			s3 = s3 + '0';
		}
		else{
			s3 = s3 + '1';
		}
	}
	cout << s3 << endl;
	return 0;
}
