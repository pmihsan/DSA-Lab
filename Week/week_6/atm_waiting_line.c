#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Customer {
    int arrivalTime;
    int servTime;
    struct Customer *next;
};
struct Queue {
    struct Customer *front, *rear;
};
int AtmisAvailable = 0,numArrivals = 0,numCustomersServed = 0;
float totalWaitingTime = 0;
struct Queue *q;
struct Customer *customer;
int randArrivals(){
    int number = rand() % 10 , numArrivals;
    switch(number){
        case 0: case 1: case 2: case 3: case 4:
        numArrivals = 0;
        break;
        case 5: case 6: case 7: case 8:
        numArrivals = 1;
        break;
        case 9:
        numArrivals = 2;
        break;
    }
    return numArrivals;
}
int randServiceTime(){
    return (rand() % 3) + 1;
}
void enqueue(struct Customer *customer){
    if(q->front == NULL){
        q->front = customer;
        q->rear = customer;
        return;
    }
    (q->rear)->next = customer;
    q->rear = customer;
}
struct Customer *dequeue(){
    if(q->front == NULL){
        return NULL;
    }
    struct Customer *temp;
    if(q->front == q->rear){
        temp = q->front;
        q->front = NULL,q->rear = NULL;
    }
    else{
        temp = q->front;
        q->front = (q->front)->next;
    }
    return temp;
}
void main(){
    q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL,q->rear = NULL;
    int arrivals;
    srand(time(0));
    struct Customer *temp;
    for(int i=0;i<60;i++){
        arrivals = randArrivals();
        for(int j=0;j<arrivals;j++){
            customer = (struct Customer *)malloc(sizeof(struct Customer));
            customer->arrivalTime = i;
            customer->servTime = randServiceTime();
            customer->next = NULL;
            enqueue(customer);
        }
        if(q->front && AtmisAvailable <= i){
            temp = dequeue();
            AtmisAvailable += temp->servTime;
            totalWaitingTime += (i - (temp->arrivalTime));
            numCustomersServed++;
        }
        numArrivals += arrivals;
    }
    printf("Number of Customers Served is %d\n",numCustomersServed);
    printf("Average Waiting Time is %f minutes\n",totalWaitingTime/numCustomersServed);
    printf("Number of Customers Left in the Queue is %d\n",numArrivals-numCustomersServed);
}

