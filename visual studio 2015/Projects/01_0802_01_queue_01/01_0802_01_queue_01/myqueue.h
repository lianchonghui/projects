
#define N 100
typedef int datatype;

struct myqueue {

	datatype num[N];
	int front;
	int rear;
	
};

typedef struct myqueue MQ;

void initQueue(MQ * mq);
int isEmpty(MQ *mq);
int addNode(MQ *mq, int num);
void show(MQ *mq);
void show2(MQ mq);
datatype deQueue(MQ *mq);

