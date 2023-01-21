#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod = 1e8+3;
int n,a[1005],b[1005],p[1005],q[1005],f[1005][1005],ans;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]=i;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),q[b[i]]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=abs(p[a[i]]-q[b[j]]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans=(ans+f[i][j])%mod;
    printf("%d\n",ans);
    return 0;
}
