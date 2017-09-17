/**
* OJ 1008
* Maya Calendar
*/
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string hname[20] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
string tname[20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };

int main() {
    int n;
    cin>>n;
    cout<<n<<endl;
    while(n--) {
        int sum = 0;
        int date,year;
        char c;
        string month;
        cin>>date;
        cin>>c;
        cin>>month>>year;
        sum += year * 365;
        for (int i = 0; i<19; i++) {
            if(month == hname[i]){
                sum += 20*i;
                break;
            }
        }
        sum += (date + 1);
        cout<<(sum-1)%13+1<<" "<<tname[(sum-1)%20]<<" "<<(sum-1)/260<<endl;    
    }
    return 0;
}