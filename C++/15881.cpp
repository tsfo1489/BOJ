#include<stdio.h>
int main()
{
    char tmp;
    int n, state, ans;
    state = ans = 0;
    scanf("%d",&n); 
    scanf("%*c",tmp);
    while(n--)
    {
        scanf("%c",&tmp);
        if(state == 0 && tmp == 'p') state = 1;
        else if(state == 1 && tmp == 'P') state = 2;
        else if(state == 2 && tmp == 'A') state = 3;
        else if(state == 3 && tmp == 'p') { state = 0; ans++; }
        else if(tmp == 'p') state = 1;
        else state = 0;
    }
    printf("%d",ans);
}