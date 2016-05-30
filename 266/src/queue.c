//
// Created by andreas on 5/12/16.
//

#include "queue.h"

queue_t queue_init()
{
    queue_t q = malloc(sizeof(q));
    q->start = NULL;
    q->end = NULL;
    return q;
}

int queue_empty(queue_t q)
{
    if (q==NULL) {
        return TRUE;
    }
    else if (q->start==NULL && q->end==NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int queue_destroy(queue_t q)
{
    if (q==NULL) {
        return ERR_INVAL;
    }
    while (q->start!=NULL) {
        queue_node_t node = q->start;
        q->start = node->next;
        free(node);
    }
    free(q);
    return SUCCESS;
}

int dequeue(queue_t q)
{
    if (queue_empty(q)) {
        return NULL;
    }
    queue_node_t node = q->start;
    q->start = node->next;
    int data = node->data;
    free(node);
    if (q->start==NULL) {
        q->end = NULL;
    }
    return data;
}

int enqueue(queue_t q, int x)
{
    if (q==NULL) {
        return ERR_INVAL;
    }
    queue_node_t new_end = malloc(sizeof(new_end));
    if (new_end==NULL) {
        return ERR_NOMEM;
    }
    new_end->data = x;
    new_end->next = NULL;
    if (q->start==NULL) {
        q->start = new_end;
        q->end = new_end;
    }
    else {
        queue_node_t second_to_last = q->end;
        second_to_last->next = new_end;
        q->end = new_end;
    }
    return SUCCESS;
}

