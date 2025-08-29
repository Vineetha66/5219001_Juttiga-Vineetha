#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXN 100000

int heap[MAXN+5];
int heapSize=0;
void swap(int *a,int *b){
    int t=*a;*a=*b;*b=t;
}

void heapify_up(int c){
    while(c>0){
        int p=(c-1)/2;
        if(heap[p]>heap[c]){
            swap(&heap[p], &heap[c]);
            c=p;
        }else break;
    }
}

void heapify_down(int c){
    while(1){
        int l=2*c+1,r=2*c+2,s=c;
        if(l<heapSize && heap[l]<heap[s]) s=l;
        if(r<heapSize && heap[r]<heap[s]) s=r;
        if(s!=c){
            swap(&heap[s], &heap[c]);
            c=s;
        } else break;
    }
}

void insert(int v){
    heap[heapSize]=v;
    heapify_up(heapSize);
    heapSize++;
}

void delete_val(int v){
    int idx=-1;
    for(int k=0;k<heapSize;k++){
        if(heap[k]==v){
            idx=k;
            break;
        }
    }
    if(idx==-1) return;
    heap[idx]=heap[heapSize-1];
    heapSize--;
    heapify_up(idx);
    heapify_down(idx);
}

int get_min(){
    return heap[0];
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    scanf("%d",&q);
    while(q--){
        int type,val;
        scanf("%d",&type);
        if(type==1){
            scanf("%d",&val);
            insert(val);
        }else if(type==2){
            scanf("%d",&val);
            delete_val(val);
        }else if(type==3){
            printf("%d\n",get_min());
        }
    }    
    return 0;
}
