#include <iostream>
void f1(int &x){
	x=10;
}
void f2(int y){
	y=11;
} 
void f3(int *z){
	*z=1022;
}
int f4(int z){
	
	z=100;
	return z;
}
int main ()
{
	int x=100;
	int *px=&x; 
	f1(x);
	printf ("%d\n",x);
	f2(x);
	printf ("%d\n",x);
	f3(px);
	printf ("%d\n",x);
	f4(x);
	printf ("%d\n",x);
	
	
	
	return 0;
}
