/* Project: Stack Sorting
   Description: Implement a stack & sort its implements using a temporary secondary stack
   Language: C  */
#include <stdio.h>
#define MAX 100
int S1[MAX], S2[MAX];
int top1=-1, top2=-1;
void push(int s[], int *top, int x){ s[++(*top)] = x; }
int pop(int s[], int *top){ return s[(*top)--]; }
int peek(int s[], int top){ return s[top]; }
int empty(int top){ return top==-1; }
void sortStack(){
    while(!empty(top1)){
        int temp = pop(S1,&top1);
        while(!empty(top2) && peek(S2,top2) > temp)
            push(S1,&top1,pop(S2,&top2));
        push(S2,&top2,temp);
    }
    while(!empty(top2)) push(S1,&top1,pop(S2,&top2));
}
int main(){
 int n,x; 
printf("Enter n: "); scanf("%d",&n);
printf("Enter elements:\n");
 for(int i=0;i<n;i++){ scanf("%d",&x); push(S1,&top1,x); }
 printf("Original: ");
 for(int i=0;i<=top1;i++) printf("%d ",S1[i]); printf("\n");
 sortStack();
 printf("Sorted: ");
    for(int i=0;i<=top1;i++) printf("%d ",S1[i]); 
}
