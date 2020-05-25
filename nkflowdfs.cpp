#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int ds[1005][1005] , ff[1005][1005] , tr[1005] , f = INT_MAX;
bool ok[1005];
long long ans = 0 , n , m , s , t;
queue <int> q;

bool dfs(int u , int t)
{
    ok[u] = true;
    for(int v = 1;  v <= n; ++v)
    {
        if(ok[v] == 0 && ds[u][v] > ff[u][v])
        {
            tr[v] = u;
            dfs(v , t);
        }
    }
    return ok[t];
}

void Find_f(int f , int u , int v)
{
    while(u != v)
    {
        f = min(f , ds[tr[v]][v] - ff[tr[v]][v]);
        v = tr[v];
    }
}

void Solve(int f , int u , int v)
{
    while(u != v)
    {
        ff[tr[v]][v] += f;
        ff[v][tr[v]] -= f;
        v = tr[v];
    }
    ans += f;
}

int main()
{
    cin >> n >> m >> s >> t;
    int tam = t;
    for(int i = 1; i <= m ; ++i)
    {
        int u , v , c;
        cin >> u >> v >> c;
        ds[u][v] = c;
    }
    while(dfs(s , t))
    {
        f = INT_MAX;
        t = tam;
        while(s != t)
        {
            f = min(f , ds[tr[t]][t] - ff[tr[t]][t]);
            t = tr[t];
        }
        t = tam;
        while(s != t)
        {
            ff[tr[t]][t] += f;
            ff[t][tr[t]] -= f;
            t = tr[t];
        }
        t = tam;
        ans += f;


//        Find_f(f , s , t);
//        t = tam;
//        Solve(f , s , t);
//        t = tam;


        for(int i = 1; i <= n; ++i)
        {
            ok[i] = 0;
            tr[i] = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
