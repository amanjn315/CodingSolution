#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<int> a = {10,20,30,40};
	vector<int> b = {10,15,20,25};
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int i = 0, j = 0, k = 0,counter = 0; 
    while (i < a.size() && j < b.size()) { 
  
        // If not common, print smaller 
        if (a[i] < b[j]) { 
            counter++; 
            i++; 
            k++; 
        } 
        else if (b[j] < a[i]) { 
            counter++; 
            k++; 
            j++; 
        } 
  
        // Skip common element 
        else { 
            i++; 
            j++; 
        } 
    } 
  
    // printing remaining elements 
    while (i < a.size()) { 
        counter++; 
        i++; 
        k++; 
    } 
    while (j < b.size()) { 
        counter++;
        j++; 
        k++; 
    } 
	cout<<"The total number of Uncommon Elements are: "<<counter<<endl;
	return 0;
}
