/**
* Risk
*/
#include<iostream>  

using namespace std;  

#define maxn 21   
  
int main()  
{  
    int map[maxn + 5][maxn + 5];  
    int t=1,n,m,k,i,j;  
      
    while (scanf("%d",&n)!=EOF) {  
        for (i=1; i<=20; i++)  
            for (j=1; j<=20; j++)  
                map[i][j] = 19;  
            while (n--) {  
                cin >> m;  
                map[1][m] = 1;  
                map[m][1] = 1;  
            }  
            for (i=2; i<20; i++) {  
                cin >> n;  
                while (n--) {  
                    cin >> m;  
                    map[i][m] = 1;  
                    map[m][i] = 1;  
                }  
            }  
            // Floyd算法核心代码。  
            for (k=1; k<=20; k++)     
                for (i=1; i<=20; i++)  
                    for (j=1; j<=20; j++)  
                        if (map[i][k] + map[k][j] < map[i][j])  
                            map[i][j] = map[i][k] + map[k][j];  
                        cin >> n;  
                        cout << "Test Set #" << t++ << endl;  
                        while (n--) {  
                            cin >> i >> j;  
                            cout << i << " to " << j << ": " << map[i][j] << endl;  
                        }  
                        cout << endl;  // 输出格式要注意。  
    }  
    return 0;  
}  