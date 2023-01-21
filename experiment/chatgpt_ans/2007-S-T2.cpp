#include<stdio.h>
#include<string.h>

int p1,p2,p3;
char str[10000];

int main()
{
    scanf("%d%d%d",&p1,&p2,&p3);
    scanf("%s",str);

    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='-' && i>0 && i<len-1) 
        {
            if((str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) || (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]))
            {
                if(str[i-1] == str[i+1]-1)
                {
                    for(int j=0;j<p2;j++)
                        printf("%c",str[i-1]);
                }
                else 
                {
                    if(p3==2)
                    {
                        for(int j=str[i-1]+1;j<str[i+1];j++)
                            for(int k=0;k<p2;k++)
                            {
                                if(p1==1)
                                    printf("%c",j);
                                else if(p1==2)
                                    printf("%c",j-32);
                                else if(p1==3)
                                    printf("*");
                            }
                    }
                    else 
                    {
                        for(int j=str[i-1]+1;j<str[i+1];j++)
                            for(int k=0;k<p2;k++)
                            {
                                if(p1==1)
                                    printf("%c",j);
                                else if(p1==2)
                                    printf("%c",j-32);
                                else if(p1==3)
                                    printf("*");
                            }
                    }
                }
            }
            else 
                printf("-");
        }
        else 
            printf("%c",str[i]);
    }

    return 0;
}
