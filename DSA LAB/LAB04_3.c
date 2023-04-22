#include<stdio.h>
#define MAX 21
#define TOP_B 0
#define TOP_U 1
struct Stack
{
    int topU;
    int topB;
    int arr[MAX];
};

void Pop(struct Stack* stack, int* value, int which);
void Push(struct Stack* stack, int* value, int which);
void Display(struct Stack* stack, int which);
void Check(struct Stack* stack, int* result, int which);
void Clear(struct Stack* stack);
int isEmpty(struct Stack* stack, int which);


int isEmpty(struct Stack* stack, int which)
{
	if(which == TOP_B)
	{
		if(stack->topB == -1)
			return 1;
		else
			return 0;
	}
	else
    {

		if(stack->topU == MAX)
			return 1;
		else
			return 0;
	}
}

void Pop(struct Stack* stack, int* value, int which)
{
	int flow;
    Check(stack, &flow, which);
    if(flow && isEmpty(stack, which))
    	return;
	if(which == TOP_B)
    	*value = stack->arr[stack->topB--];
	else
    	*value = stack->arr[stack->topU++];
}

void Push(struct Stack* stack, int* value, int which)
{
    int flow;
    Check(stack, &flow, which);
    if(flow == 1 && !isEmpty(stack, which))
        return;
    if(which == TOP_B)
    	stack->arr[++stack->topB] = *value;
    else
    	stack->arr[--stack->topU] = *value;
    return;
}

void Display(struct Stack* stack, int which)
{
    printf("\n ABHISHEK JHAWAR 200905144 \n");
    int flow;
    Check(stack, &flow, which);
    if(flow)
        return;

    printf("\n");
    if(which == TOP_B)
    	for(int i = 0; i <= stack->topB; i++)
        	printf("%d ", stack->arr[i]);
    else // which == TOP_U
    	for(int i = MAX-1; i >= stack->topU; i--)
        	printf("%d ", stack->arr[i]);

    printf("\n");
}

void Clear(struct Stack* stack)
{
    stack->topB = -1;
    stack->topU = MAX;
    for(int i = 0; i <= MAX; i++)
        stack->arr[i] = 0;
}

void Check(struct Stack* stack, int* result, int which)
{
    *result = 0;
    if(which == TOP_B)
    {
    	if(stack->topB >= stack->topU)
    	{
    	    printf("\nERROR: The Stack is Overflowing.\n");
    	    *result = 1;
    	}
    	else if(stack->topB < -1)
    	{
    	    printf("\nERROR: The Stack is Underflowing.\n");
    	    *result = 1;
    	}
    }
    else
    {
    	if(stack->topU <= stack->topB)
    	{
    	    printf("\nERROR: The Stack is Overflowing.\n");
    	    *result = 1;
    	}
    	else if(stack->topU > MAX)
    	{
    	    printf("\nERROR: The Stack is Underflowing.\n");
    	    *result = 1;
    	}
    }
    return;
}
