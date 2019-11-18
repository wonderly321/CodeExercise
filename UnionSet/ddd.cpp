#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 50007
 
using namespace std;
 
int rank[MAX];
int fa[MAX];
int ans;
 
int _find ( int x )
{
    //return x == fa[x]?x:fa[x]=find(x);
    if ( x == fa[x] ) return x;
    int temp = fa[x];
    fa[x] = _find ( fa[x]);
    rank[x] = (rank[x] + rank[temp])%3;
    return fa[x];
}
 
void init ( )
{
    for( int i = 0 ; i < MAX ; i++ )
        fa[i] = i;
}
 
void _union ( int a , int b , int f )
{
    int ffa = _find ( a );
    int fb = _find ( b );
    if ( ffa == fb ) return;
    fa[ffa] = fb;
    rank[ffa] = (f+rank[b]-rank[a]+3)%3;
}
 
int n,k,u,v,f;
 
bool check ( int u , int v , int f )
{
    if ( u > n || v > n ) return false;
    if ( f == 1 && u == v ) return false;
    if ( _find(u) == _find(v))
        return ((rank[u] - rank[v])%3+3)%3 == f;
    else return true;
}
 
int main ( )
{
    freopen("d.in", "r", stdin);
    freopen("ddd.txt", "w", stdout);
    scanf ( "%d%d" , &n , &k );
    {
        ans = 0;
        memset ( rank , 0 , sizeof ( rank ));
        init ();
        for ( int i = 0 ; i < k ; i++ )
        {
            scanf ( "%d%d%d" , &f , &u , &v );
            f--;
            if ( check ( u , v ,f ))
                _union ( u , v , f );
            else ans++;
            cout << ans << endl;
        }
        printf ( "%d\n" , ans );
    }
}

