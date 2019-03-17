#include <iostream>
#include <stdio.h>
#include <cstring>
char s[100]={0};
#define L sizeof(struct note)//it can ease the process(L can replace the sizeof(struct note))

struct note {
	int data;
	struct note *next;
	//there are two kinds of members in this struct note
	//the one is its basic type "int ",the other is its direction *next;
	
	
};	//it needs head ,changeable next and "NUll" as the end;
//build the basic struct
//clear the head point //the next point is changeable//we use "->" to lead the point to the right direction


	 
//build the first point 
int main ()
{
	struct note *p,*p1,*head;//they belong to the type --struct note;they can point the struct note (integration)
	head=p=(struct note*)malloc(sizeof(struct note));//apply  changing space for the  head/p1/p,for the space it needs is changeable
	//malloc will apply space in the computer ,and return the address of the first-space (so we can store our data there)
	//if it fails, return the "NULL"
	printf ("第一次输入:\n"); 
	scanf ("%d",&p->data);
	printf ("p->data=%d\n",p->data);
	//printf ("赋值(p1=p)之前:p1->data=%d p->data=%d\n",p1->data,p->data);
	//it belongs to the *head,give a value"scanf (any number)" to the data //the first is head's
	while (p->data!=0)//define the signal of the end as "0" ,when scanf (0) as the value of the memeber --data,it end ; 
		{
			p1=p;
			p=(struct note*)malloc(L);//every point need a changeable space 
			printf ("再次输入前; p申请空间之后):\n") ; 
			printf ("p1->data=%d p->data=%d\n",p1->data,p->data);
			scanf ("%d",&p->data);// the middle point 
			p1->next=p;//the member of the struct note,which is its value
			printf ("再次输入后:\n") ;
			printf ("p1->data=%d p->data=%d\n",p1->data,p->data);
			//printf ("p1.=%d *p.next=%d\n",*p1.next,*p.next);
			//printf ("%d\n",p1->data);
			// the first while is written to  scanf()place value
		} 	
	p->next=NULL;// the end tail ,define "NULL" as the end *point  
	p=head;// present the line 
	printf ("the data members of the line are\n");
	while (p->next!=NULL){
		
		printf ("%d ",p->data);
		p=p->next;
		
	}
	printf ("%d\n",p->data);
	
	return 0;
}
