#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1100;

int a[maxn][maxn];
int uni_row[maxn],uni_col[maxn];
int lesser_row[maxn][maxn],lesser_col[maxn][maxn];
int temp[maxn];

int cur;

bool comp(int x,int y){
    return a[cur][x] < a[cur][y];
}

bool comp2(int x,int y){
    return a[x][cur] < a[y][cur];
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;++i){
        cur = i;
        for (int j = 1;j <= m;++j) temp[j] = j;
        sort(temp+1,temp+m+1,comp);
        int id = -1;
        for (int j = 1;j <= m;++j){
            int u = temp[j];
            if (a[i][u] != a[i][temp[j-1]]) id++;
            lesser_row[i][u] = id;
        }
        uni_row[i] = id + 1;
    }
    
    for (int i = 1;i <= m;++i){
        cur = i;
        for (int j = 1;j <= n;++j) temp[j] = j;
        sort(temp+1,temp+n+1,comp2);
        int id = -1;
        for (int j = 1;j <= n;++j){
            int u = temp[j];
            if (a[u][i] != a[temp[j-1]][i]) id++;
            lesser_col[u][i] = id;
        }
        uni_col[i] = id + 1;
    }
    for (int i = 1;i <= n;++i){
        for (int j = 1;j <= m;++j){
            cout << max(lesser_row[i][j],lesser_col[i][j]) + max(uni_row[i] - lesser_row[i][j],uni_col[j] - lesser_col[i][j]) << " ";
        }
        cout << endl;
    }
    return 0;
}
