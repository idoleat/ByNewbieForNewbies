#include<iostream>
#include<list>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
    int n, m, q, w;//n heaps, m operations.
    char ins[10],insertt[9]="insert",join[6]="join",extractt[9]="extract",lookup[8]="lookup";
    scanf("%d%d", &n, &m);
    list<int> *heap = new list<int>[n];
    for(int i=0;i<m;i++){
        scanf("%s", &ins);
        if(strcmp(ins,insertt)==0){
            scanf("%d%d", &q, &w);
            heap[q-1].push_back(w);
        }
        else if(strcmp(ins,join)==0){
            scanf("%d%d", &q, &w);
            heap[q-1].sort();
            heap[w-1].sort();
            heap[q-1].merge(heap[w-1]);
        }
        else if(strcmp(ins,extractt)==0){
            scanf("%d", &q);
            heap[q-1].sort();
            if(!heap[q-1].empty()){
                printf("%d\n", heap[q-1].front());
                heap[q-1].pop_front();
            }
            else{
                printf("NULL\n");
            }
        }
        else if(strcmp(ins,lookup)==0){
            scanf("%d", &q);
            heap[q-1].sort();
            if(!heap[q-1].empty()){
                printf("%d\n", heap[q-1].front());
            }
            else{
                printf("NULL\n");
            }
        }
        else{
            cout<<"fuck you"<<endl;
            return 0;
        }
    }

    return 0;
}
