#include<stdio.h>
void push(char);
int prec(char);
char pop();
char stack[10];
int  top=-1;
void main()
{
	char st[10],prefix[10];
	int i,j=0;
	printf("eterstrig");
	scanf("%s",st);
	strrev(st);
	for(i=0;st[i]!='\0';i++)
	{
	if(st[i]==')')
	push(st[i]);
	else if(st[i]=='(')
	{
		while(stack[top]!=')')
		{
		prefix[j]=pop();
		j++;
		}
	    pop();
	}
	else if(st[i]>='a' && st[i]<='z')
	  {
	prefix[j]=st[i];
	j++;
	  }
	else
	{
		while(prec(stack[top])>prec(st[i]))
		{
			prefix[j]=pop();
			j++;
		}
		push(st[i]);
	}
      }
prefix[j]='\0';
strrev(prefix);
printf("%s",prefix);
}
void push(char ch)
{
	top++;
	stack[top]=ch;
}
char pop()
{
	char x;
	x=stack[top];
	top--;
	return x;
}
int prec(char ch)
{
	switch(ch)
	{
		case '(':
		case ')':return 0;
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
	}
}
