#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack, Stack *move, int breadValue);
void stack_single_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack, Stack *move, int breadValue) 
{
    for (int i = 0; i<breadValue; i++){
        if (!stack_isEmpty(stack)) {
            stack_push(move, stack->_top->data);
            StackNode *temp = stack->_top;
            stack->_top = stack->_top->next;
            free(temp);
            stack->_size--;
        }
    }
}

void stack_single_pop(Stack *stack)
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }  
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main()
{
    // Buat objek Stack
    Stack ray, kakak;
    stack_init(&ray);
    stack_init(&kakak);
    int bread,t,a,b;
    scanf("%d", &bread);
    if (bread == 0){
        printf("Ray SangaT MaraH!\n");
    }
    for (int i = bread; i>=1; i--){
        stack_push(&ray, i);
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        if (a==1){
            stack_pop(&ray, &kakak, b);
        }
        else if (a==2){
            stack_pop(&kakak, &ray, b);
        }
        else{
            printf("TumpukAnnya saLah! :(\n");
            return 0;
        }
    }
    // printf("\nRAY\n");
    // while(!stack_isEmpty(&ray)){
    //     printf("%d", stack_top(&ray));
    //     stack_single_pop(&ray);
    // }
    // printf("\nKAKAK\n");
    // while(!stack_isEmpty(&kakak)){
    //     printf("%d", stack_top(&kakak));
    //     stack_single_pop(&kakak);
    // }
    
    if (stack_size(&ray)>stack_size(&kakak)){
        bool stop = false;
        while(!stack_isEmpty(&ray)){
            printf("%d ", stack_top(&ray));   
            if (!stack_isEmpty(&kakak)){
                printf("%d", stack_top(&kakak));
                stack_single_pop(&kakak);
            }
            else if (stop == false){
                printf(":(");
                stop = true;
            }
            printf("\n");
            stack_single_pop(&ray);
        }
    }

    else if (stack_size(&ray)<stack_size(&kakak)){
        bool stop = false;
        while(!stack_isEmpty(&kakak)){
            if (!stack_isEmpty(&ray)){
                printf("%d ", stack_top(&ray));
                stack_single_pop(&ray);
            }
            else if (stop == false){
                printf("- ");
                stop = true;
            }
            else{
                printf(" ");
            }
            printf("%d", stack_top(&kakak));   
            printf("\n");
            stack_single_pop(&kakak);
        }
    }
    return 0;
}