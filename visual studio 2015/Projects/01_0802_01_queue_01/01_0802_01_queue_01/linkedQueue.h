struct queue {
	int num;
	int high;
	struct queue *pNext;

};

typedef struct queue LQ;

LQ *init(LQ *queue);
LQ * enQueue(LQ *queue, int num, int high);
void printfall(LQ *queue);
LQ * deLinkedQueue(LQ *queue, LQ *pout);



