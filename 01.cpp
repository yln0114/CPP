#include <stdio.h>
int x[100]={0};
int i=0;
int sum=0;
int f(int y){
	
	int k=2;
	if (y>2){
		for (k=2;k<y;k++){
			if (y%k==0){
				k=0;
				break;
			}
		}
			
	}else {
		
		if (y!=2){
			k=0;
		}
	}
	return k;
	

}
int main ()
{
	int a1,a2,a3;

	for (a1=1;a1<=9;a1++){
		for (a2=0;a2<=9;a2++){
			
			for (a3=0;a3<=9;a3++){
				int a=0,b=0,c=0;
				a=a1+a2+a3;
				b=a1*a2*a3;
				c=a1*a1+a2*a2+a3*a3;
				
				if (f(a)!=0&&f(b)!=0&&f(c)!=0){
					i++;
					int z=a1*100+a2*10+a3;
					//printf ("%d\n",z);
					sum=sum+z;
					x[i]=z;
				}
			
				
				
			}
		}
	}
	
	printf ("total quantity : %d\n",i);
	printf ("total summed up: %d\n",sum);
	printf ("the largest: %d\n",x[i]);
	
	return 0;
}
