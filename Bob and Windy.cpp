#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	int n = s.length();
	int w = 0,b = 0;
	for(int i=0;i<n;i++){
	    if(s[i]=='w'){
	        int count = 0;
	        while(i<n and s[i]=='w'){
    	        count++;
    	        i++;
    	    }
    	    i--;
    	    w += (count>=3?(count-2):0);
	    }
	    else{
	        int count = 0;
	        while(i<n and s[i]=='b'){
    	        count++;
    	        i++;
    	    }
    	    i--;
    	    b += (count>=3?(count-2):0);
	    }
	}
	cout<<"The winner is: "<<(w>b?"Windy":"Bob")<<endl;
	return 0;
}
