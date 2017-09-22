//断言
//malloc 内存不足时我们怎么办
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>

#define STACKSIZE 100
#define STACKINC 2

typedef int ElemType;
typedef struct{
    // ElemType date;
    ElemType* date;
    int top;
    int maxsize;
}Stack;
int InitStack(Stack* pstack){
    assert(pstack != NULL);
    pstack->date = BuySpace(pstack);
    int top = -1;
    int maxsize = STACKSIZE;
}
Elemtype* BuySpace(Stack* pstack){
    assert(pstack != NULL);
    Elemtype* new = (ElemType*)malloc(sizeof(ElemType)*pstack->maxsize);
    assert(new != NULL);
    memset(new,0,sizeof(ElemType)*STACKSIZE);
    return new;
}
int empty(Stack* pstack){//出栈的时候判断
    assert(pstack != NULL);//先判断stack是否存在；后面的判断才有意义
    if(pstack->top == -1){
        return 1;
    }else{
        return 0;
    }
}
int full(Stack* pstack){//入栈的时候判断
    assert(pstack != NULL);
    if(pstack->top == pstack->maxsize-1){
        return 1;
    }else{
        return 0;
    }
}
int size(Stack* pstack){
    assert(pstack != NULL);
    return pstack->top + 1;
}

 Incsize(Stack* pstack){
    assert(pstack != NULL);
    ElemType* new = (ElemType*)realloc(pstack->date,pstack->maxise*STACKINC*sizeof(ElemType));
    assert(new != NULL);
    free(pstack->date);
    pstack->date = new;
    pstack->maxsize *= STACKINC;
    return new;
}
ElemType* Incs(Stack* pstack){
    assert(pstack != NULL);
    
    pstack->maxsize *= STACKINC;
    ElemType* new = BuySpace(pstack);
    int n = size(pstack);
    for(int i=0;i<n;i++){
        new[i] = pstack->date[i];
    }
    free(pstack->date);
    pstack->date = new;
    return new;
}

void push(ElemType elem,Stack* pstack){
    assert(pstack != NULL);
    
    if(full(pstack)){
        Incsize(pstack);
    }
    pstack->date[++pstack->top] = elem;
    

}
int popElem(Stack* pstack){//调用的时候要先要判空
    assert(pstack != NULL);
    return pstack->date[pstack->top];    
}
void pop(Stack* pstack){
    assert(pstack != NULL);
    if(!empty（pstack){
        pstack->top--;
    }  
}
int main()
{
    Stack newstack;
    InitStack(&newstack);
}