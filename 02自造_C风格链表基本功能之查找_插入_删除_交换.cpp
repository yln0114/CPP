#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#define S sizeof(N)
#define M struct N*
struct N {
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
		
		end->n=node; 
		
		//end�������ʾ��һ��i-1,�Ѵ�����N1�ṹ�����ڵ�ַ 
		//(��̬ԭ��: nͨ����node��ֵ, ʹ��n(i-1)�е��ں���ָ��n(i)�ܹ����µ��ڴ�͵�ַ,������Ұָ��)
		//now the n(i-1)'s address equal(be transported) to n(i)=>(which is started at the *n pointer)
		//at the same time ,end need change as well,its address should eaqul to node(i)
		end=node;
		
		//end�Ǵ������(��x��N�ṹ��)�ĵ�ַ,��ѭ�����ʱ,end(x)װ�����һ����ַʱ,����ָ��N(x)�е�n(��·)ָ���ǿյ�
		//��Ҫ��N(x).nָ��һ����ֵNULLΪ������ʶ�� 

	}
	end->n=NULL;//i=x-1;end as an NULL;

	return head;//return an address
}
void OandC2(int x,N *&N1) {
	//����һ��Ϊʲô���ﴫ�����N *&N1;  ��Ϊ���������*N1,����ʵ������û��ʲô�ı� (ʵ�δ����βε�����������ָ��),����������� 
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
		end->n=n1;			//make i-1 and i connected through struct N *n
		end=n1;				//�ٰ�β��ҲŲ����
	}
	end->n=NULL;
	 

}
void Print(N *N1) {
	printf ("Print:\n");
	N *p;int i=0;
	p=N1->n;//p works as a explorer a head ,pointing to the next, which is to check if it is end(NULL)
	while (p!=NULL) {
		i++;
		printf ("NO.%d p: ",i);
		printf ("%d ",p->x); 
		
		//-> means 2 steps first point to the struct addressed, 
		//then point to the information of the struct as x and name
		
		printf ("%s\n",p->name);
		p=p->n;
		
		//p is only an address pointing to and creat a struct
		//	p=p->n;	//n-1 points to the next n
	}//����ʹ��N1ֱ����Ϊ�ƶ�ָ���ԭ������Ϊ��������������,������Χmain��������ᱻԭ���ĸ�ֵ���������
	//���ǻ�Ƚ�Σ��  

}

int find(N *N1,int b,char s[]){
	N *p;
	p=N1->n;
	int a=1;
	int c=0,c1=0;
	while (p!=NULL){
		
		if(p->x==b){
			printf ("NO.%d.x is the same\n",a);
			c++;
		}
		if(strcmp((p->name),s)==0){
			printf ("NO.%d.name is the same\n",a);
			c1++;
		}
		a++;
		p=p->n;
		
	}
	if (c==0&&c1==0){
		printf ("none\n");
		return -1;
		
	}else{
		return 1;
	}
	
} 

N  *add(N *N1){
	//���� ��ǰ�治�ö�ֻ�ܺ���
	//�Ȳ��ٻ�λ��  
	N *p;//��Ϊͷ��ָ�벻��Ŷ���,���������l=1,����ʹp=p->nָ����(l+1)�� 
	int l;
	printf ("add at NO.X pointer:  ");
	scanf("%d",&l);
	p=N1;
	int i=1;
	while (i<=l-1){
		if (p->n!=NULL){
			p=p->n;
			i++;
		}else {
			
			printf ("WRONG\n");
			return N1;
		}
			
	}//��Ϊ�����ٵĵ�ַ����ɢ��(������ָ�뷽��������),���Բ������,��ֱ�Ӳ���
	//Ҫ���Ǽ���i,�򿪱�һ���µ�λ��,Ȼ��ı�(i-1)->nʹ��ָ���¿ռ�ĵ�ַ,Ȼ�������µ�i�ڵ�ָ��ԭ����i,��ʱԭ����i��Ϊ��i+1�� 
	N *add;
	add=(M)malloc(S);
	int x1;
	char s[100];
	printf ("Add the new x=: name=: ");
	scanf ("%d%s",&x1,s);
	//string str1 = "Hello";

	
	add->x=x1;
	strcpy(add->name,s);
	
	
	add->n=p->n;
	p->n=add;
	return N1;
}
N *del(N *N1){
	
	N *p;//��Ϊͷ��ָ�벻��Ŷ���,���������l=1,����ʹp=p->nָ����(l+1)�� 
	int l;
	printf ("delete NO.X pointer:  ");
	int i=1;
	scanf("%d",&l);
	p=N1;
	while (i<=l-1){
		if (p->n!=NULL){
			p=p->n;
			i++;
		}else {
			
			printf ("WRONG\n");
			return N1;
		}
			
	}
	p->n=p->n->n;//�������ȼ� 
	//t->n=p->n;
	
	
	return N1;
	
}
N *swap(N *N1,int a,int b){

	//find the a-1->n a->n and b-1->n b->n,(a and b a-1 and b-1)
	//make a-1->n point to b,b->n to a+1 
	//b-1->n point to a a->n to b+1  
	if (a>b){
		int t1;
		t1=a;a=b;b=t1;
	}
	N *a1,*ap,*b1,*bp;
	N *p,*t;
	p=N1;int i=1;
	while (i<=b){
		p=p->n;
		if (i==a-1){
			a1=p;
		}
		if (i==a){
			ap=p;
		}
		if (i==b-1){
			b1=p;
		}
		if (i==b){
			bp=p;
		}	
		i++;
		
	}
	//Print (N1);
	t=ap->n;ap->n=bp->n;bp->n=t;
	t=a1->n;a1->n=b1->n;b1->n=t;
	//Print (N1);
	return N1;
}

int main () {
	N *N1; //N1 is a pointer ,represent as the *head
	int lenth01,lenth02;
	printf ("Apply a table lenth01:\n");
	scanf ("%d",&lenth01);
	N1=OandC(lenth01);
	Print (N1);
	//printf ("Try to check same x and name:\n");
	//int b;
	//char s[100];
	//scanf ("%d%s",&b,s);
	
	//find(N1,b,s);
	N1=add(N1);
	Print (N1);
	N1=del(N1);
	Print (N1);
	//N *N2;
	//printf ("Apply a table lenth02:\n");
	//scanf ("%d",&lenth02);
	//OandC2(lenth02,N2);
	//Print(N2);
	int z,y;
	printf ("swap NO.z to NO y: ");
	scanf ("%d%d",&z,&y);
	N1=swap(N1,z,y);
	Print(N1);
	
	


	return 0;
}

