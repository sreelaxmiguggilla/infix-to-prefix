#include<stdio.h>
void push(char);
int prec(char);
char pop();
char stack[10];
int  top=-1;
void main()
{
	char infix[10],prefix[10];
	int i,j=0;
	printf("eter any infix string");
	scanf("%s",infix);
	strrev(infix);
	for(i=0;infix[i]!='\0';i++)
	{
	if(infix[i]==')')
	push(infix[i]);
	else if(infix[i]=='(')
	{
		while(stack[top]!=')')
		{
		prefix[j]=pop();
		j++;
		}
	    pop();
	}
	else if(infix[i]>='a' && infix[i]<='z')
	  {
	prefix[j]=infix[i];
	j++;
	  }
	else
	{
		while(prec(stack[top])>prec(infix[i]))
		{
			prefix[j]=pop();
			j++;
		}
		push(infix[i]);
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
