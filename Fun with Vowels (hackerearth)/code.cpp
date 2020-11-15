#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> mp;
vector<char> vowels = {'a','e','i','o','u'};
int longestSubsequence(string& str,int index,char last,int len){
    if(index == str.length()){
        return last=='u'?len:0;
    }
    else{
        if(len==0){
            if(str[index]!='a')
                return longestSubsequence(str,index+1,last,len);
            else
                return longestSubsequence(str,index+1,'a',len+1);
        }
        else if(last==str[index])
            return longestSubsequence(str,index+1,last,len+1);
        else if(last != 'u' and vowels[mp[last]+1]==str[index]){
            int len1 = longestSubsequence(str,index+1,str[index],len+1);
            int len2 = longestSubsequence(str,index+1,last,len);
            if(len1>len2)
                return len1;
            else 
                return len2;
        }
        else
            return longestSubsequence(str,index+1,last,len);
    }
}
int main(){
    string str;cin>>str;
    mp['a'] = 0;
    mp['e'] = 1;
    mp['i'] = 2;
    mp['o'] = 3;
    mp['u'] = 4;
    cout<<longestSubsequence(str,0,'a',0)<<endl;
    return 0;
}