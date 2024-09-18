#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct s{
    int top;
    int capacity;
    char *arr;
}Stack;
int isEmpty(Stack *s){
    return s->top == -1;
}
Stack *createstack(int capacity){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top=-1;
    s->capacity = capacity;
    s->arr = (char*)malloc(sizeof(char)*capacity);
    return s;
}
void push(Stack *s, char c){
    s->arr[++s->top]=c;
}
char pop(Stack *s){
    if(!isEmpty(s)){
        return s->arr[s->top--];
    }
    return '\0';
}
int ismatch(char opening, char closing){
    printf("\n%c %c\n",opening,closing);
    return(opening == '(' && closing == ')'
            || opening == '[' && closing == ']'
            || opening == '{' && closing == '}' );
}
int isexprBalance(char *expr){
    int n = strlen(expr);
    Stack *s = createstack(n);
    for(int i=0;i<n;i++){
        if(expr[i] == '{' || expr[i] == '[' || expr[i]=='('){
            push(s,expr[i]);
        }else if( expr[i] == '}' || expr[i] == ']' || expr[i]==')' ){
            if( isEmpty(s) || !ismatch(pop(s),expr[i]) ){
                return 0;
            }
            
        }
    }
    return isEmpty(s);
}
int main(){
    char expr[]="{[(abc)]}";
    //printf("enter the expr\n");
    //scanf("%s",expr);
    if(isexprBalance(expr)){
        printf("balanced");
    }else{
        printf("un balanced\n");
    }
    return 0;
}