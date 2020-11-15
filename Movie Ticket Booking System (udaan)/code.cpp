#include <bits/stdc++.h>

using namespace std;

class Screen{
    private:
        int row,col,total;
        vector<vector<char> > seats;
    public:
        Screen(vector<string> vect){
            row = stoi(vect[2]);
            col = stoi(vect[3]);
            total = col*row;
            seats = vector<vector<char> >(row,vector<char> (col,'E'));
            for(int i=0;i<row;i++){
                for(int j=4;j<vect.size();j++){
                    int c = stoi(vect[j])-1;
                    seats[i][c] = 'A';
                }
            }
            cout<<"Successfully added."<<endl;
        }
        void get_unreserved_seats(int r){
            bool avl = false;
            for(int i=0;i<col;i++){
                if(seats[r][i]=='E' or seats[r][i]=='A'){
                    avl = true;
                    cout<<i+1<<" ";
                }
            }
            if(avl==false)
                cout<<"none";
            cout<<endl;
        }
        void reserve_seat(vector<string> line){
            int r = stoi(line[2])-1;
            for(int i=3;i<line.size();i++){
                if(seats[r][stoi(line[i])-1]=='O'){
                    cout<<"Failed to reserve."<<endl;
                    return;
                }
            }
            for(int i=3;i<line.size();i++){
                seats[r][stoi(line[i])-1] = 'O';
            }
            cout<<"Successfully reserved."<<endl;
        }
        void suggest_contiguous_seats(vector<string> line){
            int rqd = stoi(line[2]);
            int r = stoi(line[3])-1;
            int chc = stoi(line[4])-1;

            int l = chc-rqd+1;
            if(l>=0){
                bool found = true;
                for(int i=0;i<rqd;i++){
                    if(seats[r][i+l]=='O'){
                        found = false;break;
                    }
                    if(i!=0 and i!=rqd-1 and seats[r][i+l]=='A'){
                        found = false;break;
                    }
                }
                if(found){
                    for(int i=0;i<rqd;i++){
                        cout<<i+l+1<<" ";
                    }
                    cout<<endl;
                    return;
                }
            }
            int rt = chc+rqd-1;
            if(r<col){
                bool found = true;
                for(int i=0;i<rqd;i++){
                    if(seats[r][i+chc]=='O'){
                        found = false;break;
                    }
                    if(i!=0 and i!=rqd-1 and seats[r][i+chc]=='A'){
                        found = false;break;
                    }
                }
                if(found){
                    for(int i=0;i<rqd;i++){
                        cout<<i+chc+1<<" ";
                    }
                    cout<<endl;
                    return;
                }
            }
            cout<<"none"<<endl;
        }
        void print(){
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cout<<seats[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};
vector<string> words(string str){
    string word = "";
    vector<string> st;
    for(auto x:str){
        if(x==' '){
            st.push_back(word);
            word = "";
        }
        else
            word = word+x;
    }
    st.push_back(word);
    return st;
}
int main()
{
    int n;
    map<string,Screen*> mp;
    vector<string> line;
    string str;
    getline(cin,str);
    n = stoi(str);
    for(int i=0;i<n;i++){
        getline(cin,str);
        line = words(str);
        if(line[0]=="add-screen"){
            mp[line[1]] = new Screen(line);
        }
        else if(line[0]=="get-unreserved-seats"){
            mp[line[1]]->get_unreserved_seats(stoi(line[2])-1);
        }
        else if(line[0]=="reserve-seat"){
            mp[line[1]]->reserve_seat(line);
        }
        else if(line[0]=="suggest-contiguous-seats"){
            mp[line[1]]->suggest_contiguous_seats(line);
        }
    }
    return 0;
}
