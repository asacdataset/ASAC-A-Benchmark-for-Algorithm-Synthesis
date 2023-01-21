#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e9+7;
int n,m,q,head[1005],cnt,dis[1005],vis[1005];
struct edge{
    int to,nxt,w;
}e[100005];
inline void add(int u,int v,int w){
    e[++cnt]=(edge){v,head[u],w};
    head[u]=cnt;
}
inline void dijkstra(int s){
    for(int i=1;i<=n;i++) dis[i]=inf;
    dis[s]=0;
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&(x==0||dis[j]<dis[x])) x=j;
        vis[x]=1;
        for(int j=head[x];j;j=e[j].nxt)
            dis[e[j].to]=min(dis[e[j].to],dis[x]+e[j].w);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);add(y,x,z);
    }
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        dijkstra(x);
        if(dis[y]==inf) printf("-1\n");
        else printf("%d\n",dis[y]);
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
