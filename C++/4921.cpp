#include<stdio.h>
#include<string.h>
char m[10005];
int main()
{
    int i,j,l;
    for(i=1;;i++)
    {
        scanf("%s",m);
        if(m[0]=='0') break;
        l=strlen(m);
        for(j=0;j<l;j++)
        {
            if(j==0 && m[j]!='1') break;
            if(j>0 && j<l-1)
            {
                if(m[j]=='1') break;
                if(m[j]=='2') break;
                if(m[j]=='3' && m[j-1]!='4' && m[j-1]!='6') break;
                if(m[j]=='4' && m[j-1]!='3' && m[j-1]!='1') break;
                if(m[j]=='5' && m[j-1]!='3' && m[j-1]!='1') break;
                if(m[j]=='6' && m[j-1]!='8') break;
                if(m[j]=='7' && m[j-1]!='8') break;
                if(m[j]=='8' && m[j-1]!='5' && m[j-1]!='7') break;
            }
            if(j==l-1 && (m[j]!='2' || (m[j]=='2' && m[j-1]!='4' && m[j-1]!='6'))) break;
        }
        if(l!=j) printf("%d. NOT\n",i);
        else printf("%d. VALID\n",i);
    }
}
