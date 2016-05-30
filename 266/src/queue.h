//
// Created by andreas on 5/12/16.
//

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define SUCCESS 0
#define ERR_INVAL 1
#define ERR_NOMEM 2

#define FALSE 0
#define TRUE 1

typedef struct queue_node *queue_node_t;

struct queue_node{
    struct queue_node *next;
    int data;
};

struct queue{
    queue_node_t start;
    queue_node_t end;
};

typedef struct queue *queue_t;


queue_t queue_init(void);

int queue_empty(queue_t);

int queue_destroy(queue_t);

int enqueue(queue_t, int);

int dequeue(queue_t);