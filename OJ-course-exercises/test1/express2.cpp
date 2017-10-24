/**
*   2的幂次方表示
*/
#include<iostream>
using namespace std;

int num;
void fun(int n)
{
    int i = 0;
    int sum = 1;
    if(n == 0)
        return ;
    if(n == 1)
    {
        cout<<"2(0)";    // 1是2的零次方
        return ;
    }
    if(n == 2)
    {
        cout<<"2";      // 2的一次方
        return ;
    }
    while(2*sum <= n)
    {
        i ++;
        sum = 2*sum;
    }
    cout<<"2";
    if(i != 1)
    {
        cout<<"(";
        fun(i);
        cout<<")";
    }
    if(n - sum != 0)
        cout<<"+";
    fun(n - sum);
}
int main()
{
    int n;
    num = 0;
    cin>>n;
    if(n == 0)
    {
        cout<<n<<endl;
        return 0;
    }
    fun(n);
    return 0;
}
