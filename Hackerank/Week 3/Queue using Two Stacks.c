#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100000
int si[MAX],so[MAX];
int ti = -1, to = -1;
void enqueue(int a){
    si[++ti] = a;
}
void trans(){
    while(ti>=0){
        so[++to] = si[ti--];
    }
}
void dequeue(){
    if(to == -1){
        trans();
    }
    if(to >= 0) to--;
}
void peek(){
    if(to == -1){
        trans();
    }
    if(to>=0){
        printf("%d\n", so[to]);
    }
}
int main() {
    int a;
    scanf("%d",&a);
    while(a--){
        int b;
        scanf("%d", &b);
        if(b==1){
            int c;
            scanf("%d", &c);
            enqueue(c);
        }else if(b==2){
            dequeue();
        }else if(b==3){
            peek();
        }
    }
    return 0;
}
