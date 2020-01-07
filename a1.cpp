# include <bits/stdc++.h>
# include "akari.h"

using namespace std;

namespace aka{
const int N = 250;


struct BA{
    int x, y;
    bool flag;
};


struct BC{
    int x, y;
};


vector<BA> point;
vector<BC> bcell;


vector<vector<int> > akari1, akari2;


bool vis[N][N], conn[N][N], ll[15][15];
int n, m;


bool check1(int now)
{
    int p[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int dx = point[now].x + p[i][0], dy = point[now].y + p[i][1];
        
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && akari1[dx][dy] == 0) return false;
    }
    return true;
}


void doun(int now, int delta)
{
    int p[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int dx = point[now].x + p[i][0], dy = point[now].y + p[i][1];
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && akari1[dx][dy] >= 0) akari1[dx][dy] += delta;
    }
}
bool check2(int x, int y) {
	
	
	
    int p[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    
    
    for (int i = 0; i < 4; i++) {
        int dx = x + p[i][0], dy = y + p[i][1];
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && akari2[dx][dy] >= 0) return false;
    }
    for (int k = x + 1; k < n; k++) {
        if (ll[k][y] == true) return false;
        if (akari2[k][y] != -2) break;
    }
    for (int k = x - 1; k >= 0; k--) {
        if (ll[k][y] == true) return false;
        if (akari2[k][y] != -2) break;
    }
    for (int k = y + 1; k < m; k++) {
        if (ll[x][k] == true) return false;
        if (akari2[x][k] != -2) break;
    }
    for (int k = y - 1; k >= 0; k--) {
        if (ll[x][k] == true) return false;
        if (akari2[x][k] != -2) break;
    }
    return true;
}
bool dlc (int x, int y)
{
    if (x == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (akari2[i][j] != -2 || ll[i][j] == true) continue;
                bool mark = false;
                for (int k = i + 1; k < n; k++) {
                    if (ll[k][j] == true) {mark = true; break;}
                    if (akari2[k][j] != -2) break;
                }
                if (mark == true) continue;
                for (int k = i - 1; k >= 0; k--) {
                    if (ll[k][j] == true) {mark = true; break;}
                    if (akari2[k][j] != -2) break;
                }
                if (mark == true) continue;
                for (int k = j + 1; k < m; k++) {
                    if (ll[i][k] == true) {mark = true; break;}
                    if (akari2[i][k] != -2) break;
                }
                if (mark == true) continue;
                for (int k = j - 1; k >= 0; k--) {
                    if (ll[i][k] == true) {mark = true; break;}
                    if (akari2[i][k] != -2) break;
                }
                if (mark == false) return false;
            }
        }
        return true;
    }
    if (ll[x][y] == true || akari2[x][y] != -2) {
        return dlc(y == m - 1 ? x + 1 : x, y == m - 1 ? 0 : y + 1);
    }
    else {
       if (check2(x, y) == true) {
            ll[x][y] = true;
            if (dlc(y == m - 1 ? x + 1 : x, y == m - 1 ? 0 : y + 1) == true)
                return true;
            ll[x][y] = false;
       }
       return dlc(y == m - 1 ? x + 1 : x, y == m - 1 ? 0 : y + 1);
    }
}


bool dlca(int now)
{
    if (now == (int)point.size()) {
        for (int i = 0; i < (int)bcell.size(); ++i) if (akari1[bcell[i].x][bcell[i].y] != 0) return false;
        memset(ll, false, sizeof(ll));
        for (int i = 0; i < (int)point.size(); ++i) {
            if (point[i].flag == true) ll[point[i].x][point[i].y] = true;
        }
        bool flag = dlc(0, 0);
        return flag;
    }
    if (check1(now)) {
        bool mark = false;
        for (int i = 0; i < now; ++i) {
            if (point[i].flag == true && conn[i][now] == true) {mark = true; break;}
        }
        if (mark == false) {
            point[now].flag = true;
            doun(now, -1);
            if (dlca(now + 1) == true) return true;
            point[now].flag = false;
            doun(now, 1);
        }
    }
    return dlca(now + 1);
}



vector<vector<int> >  solveAkari(vector<vector<int> > & g)
{
    // 请在此函数内返回最后求得的结果
    n = (int)g.size(); m = (int)g[0].size();
    int ps[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    for (int i = 0; i < n; i++) {
        akari1.push_back(vector<int>()); akari2.push_back(vector<int>());
        for (int j = 0; j < m; j++) {
            akari1[i].push_back(g[i][j]); akari2[i].push_back(g[i][j]);
            if (g[i][j] >= 0 && g[i][j] <= 4) {
                bcell.push_back(BC{i, j});
                for (int k = 0; k < 4; k++) {
                    int dx = i + ps[k][0], dy = j + ps[k][1];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m && g[dx][dy] == -2 && vis[dx][dy] == false) {
                        point.push_back(BA{dx, dy, false});
                        vis[dx][dy] = true;
                    }
                }
            }
        }
    }
    int siz = (int)point.size();
    for (int i = 0; i < siz; i++) {
        for (int j = i + 1; j < siz; j++) {
            if (point[i].x == point[j].x) {
                bool mark = false;
                for (int k = min(point[i].y, point[j].y)+1; k <= max(point[i].y, point[j].y)-1; k++) {
                    if (akari1[point[i].x][k] >= -1) {mark = true; break;}
                }
                if (mark == false) conn[i][j] = true;
            }
            else if (point[i].y == point[j].y) {
                bool mark = false;
                for (int k = min(point[i].x, point[j].x)+1; k <= max(point[i].x, point[j].x)-1; k++) {
                    if (akari1[k][point[i].y] >= -1) {mark = true; break;}
                }
                if (mark == false) conn[i][j] = true;
            }
        }
    }
    dlca(0);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (ll[i][j] == true) akari2[i][j] = 5;
    return akari2;
}
}
