#include<stdio.h>
#include<string.h>
int dot[15],map[15][15],d[15][15],m,pos,e;
void CHK(int arr[]);
bool CMP(int st,int x,int k[]);
void M(int a,int n,int k[],int chk[])
{
    if(pos==1) return;
    if(n==1) { CHK(k); return; }
    int x,y,i,j;

    for(i=0;i<dot[a];i++)
    {
        if(CMP(a,i,k) && chk[map[a][i]]==0)
        {
            k[n-1]=map[a][i];
            chk[map[a][i]]=1;
            M(map[a][i],n-1,k,chk);
            chk[map[a][i]]=0;
        }
    }
}
void O()
{
    int n,i,j,a,b,k[15]={0},chk[15]={0};
    scanf("%d",&n);
    e=n;
    for(i=1;i<=n;i++) { scanf("%d %d",&a,&b); d[a][b]=1; d[b][a]=1; map[a][dot[a]++]=b; map[b][dot[b]++]=a; }

    for(i=1;i<=9;i++) if(dot[i]!=0) m++;
    for(i=1;i<=9;i++)
    {
        if(pos==1) { break; }
        memset(chk,0,sizeof(chk));
        if(dot[i]!=0) { k[m]=i; chk[i]=1; M(i,m,k,chk); chk[i]=0; }
    }
    if(i==10) printf("IMPOSSIBLE");
    printf("\n");
}
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++) O();
}
bool CMP(int st,int x,int k[])
{
    int i,j,us[15]={0},tar;

    for(i=1;i<=9;i++) us[k[i]]++;
    tar=map[st][x];
    if(st==1 && tar==3 && us[2]!=1) return false;
    if(st==4 && tar==6 && us[5]!=1) return false;
    if(st==7 && tar==9 && us[8]!=1) return false; // 가로 오른쪽으로

    if(st==1 && tar==7 && us[4]!=1) return false;
    if(st==2 && tar==8 && us[5]!=1) return false;
    if(st==3 && tar==9 && us[6]!=1) return false; // 세로 아래로

    if(st==3 && tar==1 && us[2]!=1) return false;
    if(st==6 && tar==4 && us[5]!=1) return false;
    if(st==9 && tar==7 && us[8]!=1) return false; //가로 왼쪽으로

    if(st==7 && tar==1 && us[4]!=1) return false;
    if(st==8 && tar==2 && us[5]!=1) return false;
    if(st==9 && tar==3 && us[6]!=1) return false; //세로 위으로

    if(st==1 && tar==9 && us[5]!=1) return false; //왼쪽-오른쪽 아래
    if(st==7 && tar==3 && us[5]!=1) return false; //왼쪽-오른쪽 위
    if(st==3 && tar==7 && us[5]!=1) return false; //오른쪽-왼쪽 아래
    if(st==9 && tar==1 && us[5]!=1) return false; //오른쪽-왼쪽 위로

    return true; //가능함
}
void CHK(int arr[])
{
    int i,j;
    j=e;
    for(i=m;i>1;i--)
    {
        if(d[arr[i]][arr[i-1]]==0) break;
        else j--;
    }
    if(i==1 && j==0) { for(i=m;i>=1;i--) printf("%d ",arr[i]); pos=1; }
}
