#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "mmstack.h"

struct llnode{
    int item;
    int max;
    int min;
    struct llnode *next;
};

struct mmstack{
    int len;
    struct llnode *front;
};

MMStack create_MMStack(void){
    MMStack new = malloc(sizeof(struct mmstack));
    new->len = 0;
    new->front = NULL;
    return new;
}

int mms_pop(MMStack mms){
    assert(mms);
    assert(mms->len > 0);
    int reserve = mms->front->item;
    struct llnode *new = mms->front;
    mms->front = mms->front->next;
    mms->len--;
    free(new);
    return reserve;
}


void destroy_MMStack(MMStack mms){
    assert(mms);
    struct llnode *current = mms->front; 
	struct llnode *next;
	while (current != NULL) {
		next = current->next; 
		free(current); 
		current = next; 
	}
	free(mms); 
}	

int mms_length(MMStack mms){
    assert(mms);
    return mms->len;
}


void mms_push(MMStack mms, int i){
    assert(mms);
    struct llnode *new = malloc(sizeof(struct llnode));
    new->item = i;
    if (mms->len == 0){
        new->next = NULL;
        mms->front = new;
        new->max = i;
        new->min = i;
    }
    else{
        new->min = mms->front->min;
        new->max = mms->front->max;
        new->next = mms->front;
        mms->front = new;
        if (mms->front->min  > i)  {
            new->min = i;
        }
        else if (mms->front->max < i) {
            new->max = i;
        }
    }
    mms->len++;
}



int mms_min(MMStack mms){
    assert(mms);
    assert(mms->len > 0);
    return mms->front->min;
}

int mms_max(MMStack mms){
    assert(mms);
    assert(mms->len > 0);
    return mms->front->max;
}

