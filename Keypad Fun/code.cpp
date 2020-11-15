#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	vector<vector<char> > keypad(10,vector<char> ());
	keypad[1] = {',','@'};
	keypad[0] = {' ','0'};
	vector<int> unq = {2,2,3,3,3,3,3,4,3,4};
	vector<int> alp = {0,0,0,3,6,9,12,15,19,22};
	vector<int> cnt = {2,2,7,7,7,7,7,9,7,9};
	for(int i=2;i<=9;i++){
	    for(int j=0;j<unq[i];j++){
	        keypad[i].push_back('A'+(char)alp[i]+(char)j);
	    }
	    for(int j=0;j<unq[i];j++){
	        keypad[i].push_back('a'+(char)alp[i]+(char)j);
	    }
	    keypad[i].push_back(to_string(i)[0]);
	}
	string cmb; cin>>cmb;
	int i=0;
	string res = "";
	while(i<cmb.length()){
	    if(cmb[i]=='_'){
	        i++;continue;
	    }
	    char p = cmb[i];
	    int counter = 0;
	    while(i+1<cmb.length() and cmb[i+1]==cmb[i]){
	        counter++;i++;
	    }
	    res += keypad[int(p-'0')][counter%cnt[int(p-'0')]];
	    i++;
	}
	cout<<res<<endl;
	return 0;
}
