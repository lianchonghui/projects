#include"myqueue.h"

//int main() {
//
//	printf("%d", demo(1));
//
//	return 0;
//}


int main3() {

	//����Ұָ��:һ��ָ��free()�Ժ�

	//Ұָ����Ҫ����Ϊ��Щ��������ֵģ�
	//1.ָ�����δ��ʼ��
	//	�κ�ָ������ձ�����ʱ�����Զ���ΪNULLָ�룬����ȱʡֵ������ģ�������ָһ�������ԣ�ָ������ڴ�����ͬʱӦ������ʼ����Ҫô��ָ������ΪNULL��Ҫô����ָ��Ϸ����ڴ档
	//2.ָ���ͷź�֮��δ�ÿ�
	//	��ʱָ����free��delete��δ��ֵ NULL�����ʹ����Ϊ�ǺϷ��ġ���free��delete�����֣�������delete��������ֻ�ǰ�ָ����ָ���ڴ���ͷŵ�������û�а�ָ�뱾��ɵ�����ʱָ��ָ��ľ��ǡ��������ڴ档�ͷź��ָ��Ӧ������ָ����ΪNULL����ֹ������Ұָ�롱��
	//3.ָ�������Խ����������
	//	��Ҫ����ָ��ջ�ڴ��ָ������ã���Ϊջ�ڴ��ں�������ʱ�ᱻ�ͷš�

	//free()
	//free���Զ�ζ�NULLָ��ʹ��,�������NULLָ��ֻ��ʹ��һ��
	//deleteֻ��ʹ��һ��
	//free()�Ժ��ڴ汻��������,��ָ����Ȼָ�������,����Ȩ����,�޸�����.
	//delete���Ǹ���ϵͳ���˵�ַ�����ٴη��䣬��û������ָ�룬���ԣ�����delete�󣬼�һ��p = NULL,delete�Ժ�����Ȼָ�������,��ûȨ���ʸ��ڴ�����.
	
	//-------------------------------------
	//free,delete���ܶ�ջ�ڴ����

	int num = 12;
	int *pnum = &num;
	
	//delete()�����ͷ�new�������ڴ�,��free()�Ĳ��
	//printf("pnum:%p\n", pnum);
	//delete(pnum);//
	//printf("pnum:%p\n", pnum);


	//free()ֻ���ͷ��ֶ�������ڴ�
	//free(pnum);����


	//-------------------------------------
	//free,delete�Զ��ڴ�����

	int *pnum2 = (int *)malloc(sizeof(int));
	//pnum2 = &num;//����ֻ�Ǹı���pnum2ָ���ָ��,ʹ��ָ��num,free()�ǲ����ͷŵ�
	*pnum2 = 22;
	printf("%p\n", pnum2);
	printf("%d\n", *pnum2);

	//====================================
	//��ʾfree��delete������,���Ƚ���ͬ

	//����free/delete�Ժ�,ָ���ָ��:ָ����Ȼָ���ĸ��ڴ��ַ
	free(pnum2);
	//delete(pnum2);
	//����free�Ժ�û�ж�pnum2ָ���ÿ�,��ָ�뻹��ָ��ԭ�����ڴ�,����Ƭ�ڴ��Ѿ�������(�������ϱ���������ռ��),pnum2��ΪҰָ��

	printf("%p\n", pnum2);

	//����free/delete�Ժ�ָ���Ƿ��Զ���Ϊ��:free/delete�Բ����ָ����ΪNULL
	if (pnum2 == NULL) {
		printf("it is NULL");
	}
	printf("%p\n", pnum2);

	//����free/delete�Ժ�,ָ���Ƿ�Ը��ڴ滹�з���Ȩ��:free�Ժ��з���Ȩ��,delete�Ժ�û�з���Ȩ��
	printf("%d\n", *pnum2);//����free()�Ժ�,��ȡ������������;��delete�Ժ�,���ָ�벻����Ȩ�޷�������ڴ�.

	*pnum2 = 13;
	printf("%d\n", *pnum2);

	//����printf()��ӡ��pnum2��ָ�붼��ָ��ͬһ����ַ


	//=====================================
	
	//��ָ��free/delete�Ժ���ΪNULL�Ժ�ָ���ָ��
	pnum2 = NULL;
	if (pnum2 == NULL) {
		printf("it is NULL\n");
	}
	printf("%p\n", pnum2);


	system("pause");
	return 0;
}

int main2() {

	MQ mq;
	initQueue(&mq);

	char *str = "abcdefg";
	char *p = str;
	while (*p != '\0') {
		enQueue(&mq, *p);
		showQueue(&mq);
		p++;
	}
	while (isempty(&mq) != 1) {
		printf("\n���ӵ��ַ�%c", deQueue(&mq));
		showQueue(&mq);
	}


	system("pause");
	return 0;
}

int main1() {


	MQ mq;
	initQueue(&mq);

	datatype d = gehead(&mq);

	printf("%d", d);

	enQueue(&mq,12);

	printf("%d,%d,%d,%d", d,mq.data[mq.rear-1],mq.front,mq.rear);
	system("pause");
	return 0;
}