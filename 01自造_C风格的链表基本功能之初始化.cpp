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
		node=(M)malloc(S);//apply to point a new address for new space(动态可变长的根本原因,每次使用的时候同时又通过node申请了一个空间
		printf ("Fill out NO.%d table ",i+1);
		printf ("(the int x and char name):\n");
		scanf ("%d",&node->x);

		scanf ("%s",&node->name);
		//node has been filled
		//node(i-1) need to point the next node (i)
		end->n=node; //end在这里表示上一个i-1,已创建的N1结构体所在地址 
		//(动态原因: n通过被node赋值, 使得n(i-1)中的内涵的指针n(i)能够有新的内存和地址,不再是野指针)
		//now the n(i-1)'s address equal(be transported) to n(i)=>(which is started at the *n pointer)
		//at the same time ,end need change as well,its address should eaqul to node(i)
		end=node;//end是储存最后(第x个N结构体)的地址,当循环完成时,end(x)装下最后一个地址时,其所指的N(x)中的n(开路)指针是空的
		//需要将N(x).n指向一个空值NULL为结束标识符 

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
		end=n1;//再把尾部也挪过来
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
