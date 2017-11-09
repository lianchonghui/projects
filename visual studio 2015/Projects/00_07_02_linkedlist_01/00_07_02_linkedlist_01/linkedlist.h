struct listdemo {
	int num;
	struct listdemo *pnext;

};

typedef struct listdemo SLD;

void show(SLD * head);

SLD * deleteNode(SLD * head, int num);
void deleteNode1(SLD * head, int num);
void deleteNode2(SLD * head, int num);
void deleteNode3(SLD * head, int num);

void deleteAll1(SLD* head);
SLD* deleteAll2(SLD* head);
SLD* deleteAll3(SLD* head);

SLD* myAdd(SLD* head, int num);
void add(SLD** head, int num);

SLD* headInsert(SLD* head, int num);
SLD* lastInsert(SLD* head, int num);


SLD* frontInsert(SLD* head, int num, int newnum);
SLD* backInsert(SLD* head, int num, int newnum);

SLD* reverse(SLD* head);
SLD* reverse2(SLD* head);

void sort(SLD* head);
void bsort(SLD* head);
void bsort2(SLD* head);

int sum(SLD* head);


void arrbsort(int arr[],int num);
void arrssort(int arr[], int num);