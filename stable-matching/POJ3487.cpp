#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define maxn 30

int mp[maxn][maxn];
int mpoint[maxn];
int wp[maxn][maxn];
int wife[maxn];
int husband[maxn];
queue<int > sman;

int n;

void proposal(int man) {
    // woman is not single, woman trades up
    int woman = mp[man][mpoint[man]];
    int curHus = husband[woman];
    if (curHus != -1) {
        if (wp[woman][curHus] > wp[woman][man]) {
            sman.push(curHus);
            mpoint[curHus]++;
            wife[curHus] = -1;
            wife[man] = woman;
            husband[woman] = man;
        } else {
            sman.push(man);
            mpoint[man]++;
        }
    } else { // woman is single, matched temporarily
        wife[man] = woman;
        husband[woman] = man;
    }
}

int main() {
    int T;
    char mnames[maxn];
    char wnames[maxn];
    string prefer;
    int man;

    cin >> T;
    while (T--) {

        // read
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> mnames[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> wnames[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> prefer;
            for (int j = 0; j < n; j++) {
                mp[i][j] = prefer[2 + j] - 'A';
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> prefer;
            for (int j = 0; j < n; j++) {
                // wp[i][j] = prefer[2 + j] - 'a';
                // inverse
                wp[i][prefer[2 + j] - 'a'] = j;
            }
        }

        //init
        memset(mpoint, 0, sizeof(mpoint));
        for (int i = 0; i< n; i++) {
            sman.push(i);
        }
        for (int i = 0; i< n; i++) {
            wife[i] = -1;
        }
        for (int i = 0; i< n; i++) {
            husband[i] = -1;
        }

        // Gale-Shapley
        while (!sman.empty()) {
            man = sman.front();
            sman.pop();
            proposal(man);
        }
        for (int i = 0; i < n; i++) {
            cout << mnames[i] << " " << wnames[wife[i]] << endl;
        }
        cout << endl;
    }
    return 0;
}
