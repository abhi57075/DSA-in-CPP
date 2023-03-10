# include <iostream>
# include <vector>
# include <stack>
using namespace std;

/*
Largest Rectangle in a Histogram

Given an array. Each element represents the height of the histogram's bar and the width of each bar is 1.
Find the area of the largest rectangle in the histogram

Example :
Array : {2,1,5,6,2,3}
Ans is 5*2 = 10 {5,6}
*/

int get_max_area(vector <int> a){
    int n = a.size();
    int ans = 0;
    int i = 0;

    stack <int>st;

    a.push_back(0);

    while (i<n){
        while (!st.empty() && a[st.top()] > a[i]){
            int t = st.top();
            int h = a[t];
            st.pop();
            if (st.empty()){
                ans = max(ans,h*i);
            }
            else{
                int len = i - st.top() - 1;
                ans = max (ans, h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main(){
    vector <int> a = {2,1,5,6,2,3};
    cout<<get_max_area(a)<<endl;
}