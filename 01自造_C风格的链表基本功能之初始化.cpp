#include <iostream>
#include <stdio.h>
#include <string>

#define S sizeof(N)
#define M struct N*
typedef struct N {
	char name[100];
	int x;
	struct N *n;
	///struct N *n2;//n1 n2 are the changeable direction pointer.to the next address
};
N *OandC(int x) {
	//x==the lenth of the nodes
	N *head,*node,*end;
	//head ,the first ,expecting an address and space
	head=(M)malloc(S);//strcut N*=struct **N
	end=head;//same address at first(i=1)

	// fill the value
	int i;
	for (i=0; i<x; i++) {
		node=(M)malloc(S);//apply to point a new address for new space(��̬�ɱ䳤�ĸ���ԭ��,ÿ��ʹ�õ�ʱ��ͬʱ��ͨ��node������һ���ռ�
		printf ("Fill out NO.%d table ",i+1);
		printf ("(the int x and char name):\n");
		scanf ("%d",&node->x);

		scanf ("%s",&node->name);
		//node has been filled
		//node(i-1) need to point the next node (i)
		end->n=node; //end�������ʾ��һ��i-1,�Ѵ�����N1�ṹ�����ڵ�ַ 
		//(��̬ԭ��: nͨ����node��ֵ, ʹ��n(i-1)�е��ں���ָ��n(i)�ܹ����µ��ڴ�͵�ַ,������Ұָ��)
		//now the n(i-1)'s address equal(be transported) to n(i)=>(which is started at the *n pointer)
		//at the same time ,end need change as well,its address should eaqul to node(i)
		end=node;//end�Ǵ������(��x��N�ṹ��)�ĵ�ַ,��ѭ�����ʱ,end(x)װ�����һ����ַʱ,����ָ��N(x)�е�n(��·)ָ���ǿյ�
		//��Ҫ��N(x).nָ��һ����ֵNULLΪ������ʶ�� 

	}
	end->n=NULL;//i=x-1;end as an NULL;

	return head;//return an address
}
void OandC2(int x,N *&N1) {
	int i;
	N *n1,*end;
	//first, apply for a space,get the address
	N1=(M)malloc(S);
	end=N1;
	for (i=0; i<x; i++) {
		n1=(M)malloc(S);
		printf ("Fill out NO.%d table ",i+1);
		printf ("(the int x and char name):\n");
		scanf ("%d%s",&n1->x,&n1->name);
		end->n=n1;//make i-1 and i connected through struct N *n
		end=n1;//�ٰ�β��ҲŲ����
	}
	end->n=NULL;
	 

}
void Print(N *N1) {
	printf ("Print:\n");
	//N *p;
	//p=N1->n;//p works as a explorer a head ,pointing to the next, which is to check if it is end(NULL)
	while (N1->n!=NULL) {

		printf ("%d ",N1->n->x); //-> means 2 steps first point to the struct addressed, then point to the information of the struct as x and name
		printf ("%s\n",N1->n->name);
		N1=N1->n;//p is only an address pointing to and creat a struct
		//	p=p->n;	//n-1 points to the next n
	}

}


int main () {
	N *N1; //N1 is a pointer ,represent as the *head
	int lenth01,lenth02;
	printf ("Apply a table lenth01:\n");
	scanf ("%d",&lenth01);
	N1=OandC(lenth01);
	Print (N1);
	N *N2;
	printf ("Apply a table lenth02:\n");
	scanf ("%d",&lenth02);
	OandC2(lenth02,N2);
	Print(N2);



	return 0;
}
