//queue using array
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int b;
    int * arr;
};

int isFull(struct queue *q){
    if(q->b==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->f==q->b){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("queue overflow");
    }
    else{
        q->b++;
        q->arr[q->b]=val;
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("queue full");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size=4;
    q.f=q.b=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));

    /*//enqueuing elements
    enqueue(&q,12);
    enqueue(&q,15);
    //dequeuing elements
    printf("dequeueing elemnt %d\n",dequeue(&q));
    printf("dequeueing elemnt %d\n",dequeue(&q));

    if(isEmpty(&q)){
        printf("queue is empty");
    }
    if(isFull(&q)){
        printf("queue is full");
    }
    return 0;
    */

    //enqueuing elements
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,1);
    enqueue(&q,6);
    //dequeuing elements
    printf("dequeueing elemnt %d\n",dequeue(&q));
    printf("dequeueing elemnt %d\n",dequeue(&q));
    printf("dequeueing elemnt %d\n",dequeue(&q));
    printf("dequeueing elemnt %d\n",dequeue(&q));
    enqueue(&q,3);

    if(isEmpty(&q)){
        printf("queue is empty");
    }
    if(isFull(&q)){
        printf("queue is full");
    }
    return 0;
}