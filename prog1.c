#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct stack
{
    int data;
    struct stack *link;
};
struct stack *top=NULL;
void push(int d)
{
    struct stack *nu=NULL;
    nu=calloc(1,sizeof(struct stack));
    if(nu==NULL)
    {
        printf("stack is full\n");
        return;
    }
    nu->data=d;
    nu->link=top;
    top=nu;
}
int pop()
{
    struct stack *temp;
    int v;
    temp=top;
    top=top->link;
    v=temp->data;
    free(temp);
    return v;
}
int prec(char ch)
{
    if(ch=='^')
    return 3;
    if(ch=='*'||ch=='/')
    return 2;
    if(ch=='+'||ch=='-')
    return 1;
    return 0;
}
int power(int base,int exponent)
{
    int res=1;
    while(exponent>0)
    {
        res=res*base;
        exponent--;
    }
    return res;
}
void infixtopostfix(char *i,char *p)
{
    int j=0,k=0;
    char ch;
    for(j=0;i[j];j++)
    {
        ch=i[j];
        if(isdigit(ch))
        {
            while(isdigit(i[j]))
            {
                p[k++]=i[j++];
            }
            p[k++]=' ';
            j--;
        }
        else if(isalpha(ch))
        {
            p[k]=ch;
            k++;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        {
            while(top!=NULL&&top->data!='('&&(prec(top->data)>prec(ch)||(prec(top->data)==prec(ch)&&ch!='^')))
            {
                p[k]=pop();
                k++;
            }
            push(ch);
        }
        else if(ch==')')
        {
            while((top!=NULL)&&(top->data!='('))
            {
                p[k]=pop();
                k++;
            }
            pop();
        }
    }
    while(top!=NULL)
    {
        p[k]=pop();
        k++;
    }
    p[k]='\0';
}
int evaluate(char *p,int *value)
{
    int i=0,op1,op2;
    char ch;
    char temp[50];
    for(i=0;p[i];i++)
    {
        ch=p[i];
        if(ch==' ')
        continue;
        if(isdigit(ch))
        {
            int j=0;
            while(isdigit(p[i]))
            {
                temp[j++]=p[i++];
            }
            temp[j]='\0';
            push(atoi(temp));
            i--;
        }
        else if(isalpha(ch))
        {
            push(value[ch]);
        }
        else
        {
               op2=pop();
               op1=pop();
               switch(ch)
               {
                   case '+':push(op1+op2);
                   break;
                   case '-':push(op1-op2);
                   break;
                   case '*':push(op1*op2);
                   break;
                   case '/':push(op1/op2);
                    break;
                   case '^':push(power(op1,op2));
                   break;
                }
       }
    }
    return pop();
}
int main()
{
    int i;
    int value[128];
    char infix[100],postfix[100];
    int result=0;
    printf("enter infix: \n");
    scanf("%s",infix);
    for(i=0;infix[i];i++)
    {
        char ch=infix[i];
        if(isalpha(ch))
        {
            printf("enter value of %c: ",ch);
            scanf("%d",&value[ch]);
        }
    }
    infixtopostfix(infix,postfix);
    printf("postfix=%s\n",postfix);
    result=evaluate(postfix,value);
    printf("%d\n",result);
    return 0;
}