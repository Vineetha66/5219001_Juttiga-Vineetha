#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1000000

char *h[100000];  // history stack
int t = -1;       // top of stack
char a[MAX_LEN + 1]; // current string

void push(const char *str){
    h[++t] = strdup(str);  // store a copy of current string
}

void pop(){
    if(t >= 0){
        strcpy(a, h[t]);   // restore last saved string
        free(h[t]);        // free allocated memory
        t--;
    }
}

int main() {
    int c;
    scanf("%d", &c);
    a[0] = '\0';   // initialize string as empty

    for(int i = 0; i < c; i++){  
        int op;
        scanf("%d", &op);        

        if(op == 1){   // append string
            char b[MAX_LEN + 1];
            scanf(" %[^\n]", b);   // read full string (handles spaces)
            push(a);
            strncat(a, b, MAX_LEN - strlen(a) - 1); 
        }
        else if(op == 2){  // delete last k chars
            int k;
            scanf("%d", &k);
            int size = strlen(a);
            if(k <= size){
                push(a);
                a[size-k] = '\0';
            }
        }
        else if(op == 3){  // print kth char
            int k;
            scanf("%d", &k);
            if(k > 0 && k <= strlen(a)){
                printf("%c\n", a[k-1]);
            }
        }
        else if(op == 4){  // undo
            pop();
        }
    }

    // cleanup any remaining stack strings
    while(t >= 0){
        free(h[t--]);
    }
    return 0;
}
