#include <iostream>
using namespace std;
class Solution {
public:
    int sum(int num1, int num2) {
        return num1+num2;
    }
int main()
{
    int num1,num2;
    cin>>num1>>num2;
    if(num1<-100||num2>100)
    {
        cout<<"Error"<<endl;
        return 1;
    }
    Solution solution;
    int result=solution.sum(num1,num2);
    cout<<result<<endl;
    return 0;
} 
};