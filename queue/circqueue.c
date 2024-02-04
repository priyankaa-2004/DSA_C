//queue using array
#include<stdio.h>
#include<stdlib.h>

struct circular_queue{
    int size;
    int f;
    int b;
    int * arr;
};

int isFull(struct circular_queue *q){
    if((q->b+1)%q->size==q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct circular_queue *q){
    if(q->f==q->b){
        return 1;
    }
    return 0;
}

void enqueue(struct circular_queue *q, int val){
    if(isFull(q)){
        printf("\nqueue overflow\n");
    }
    else{
        q->b=(q->b+1)%q->size;
        q->arr[q->b]=val;
        printf("enqueuing element %d\n",val);
    }
}

int dequeue(struct circular_queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("\nqueue empty\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct circular_queue q;
    q.size=4;
    q.f=q.b=0;//why 0 and not -1?-> bcz agar 0 nahi lenge then queue full hone ke baad bhi element enqueue hoke elements overwrite hote jayenge
    q.arr=(int*)malloc(q.size*sizeof(int));

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