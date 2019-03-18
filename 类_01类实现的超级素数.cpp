#include <iostream>
int find (int x){
	int k=2;
	for (k=2;k<x;k++){
		if (x%k==0){
			k=0;
			break;
		}
	}
	if (x!=2&&x<2){
		k=0;
		
	}
	
	return k;
}
class MOSS{
	public:
		//int qian;
		int bai;
		int shi;
		int ge;
		int mov (void)
		{
			return find(bai*shi*ge);
		}
		int sum (void)
		{
			return find(bai+shi+ge);
			
		}
		int ss(void)
		{
			
			return find(bai*bai+shi*shi+ge*ge);
			
		}
		int rerange (void);

	
};
int MOSS::rerange(void)
{
	return find(bai*100+shi*10+ge);
	
}
int max=0;



int main ()
{
	MOSS mov_sum_ss1;
	int i1,i2,i3,num=0,sm=0;
	for (i1=1;i1<=9;i1++){
		
		mov_sum_ss1.bai=i1;
		for (i2=0;i2<=9;i2++){
			mov_sum_ss1.shi=i2;
			
			for (i3=0;i3<=9;i3++){
				mov_sum_ss1.ge=i3;
				
				if (mov_sum_ss1.mov()*mov_sum_ss1.rerange()*mov_sum_ss1.ss()*mov_sum_ss1.sum()!=0){
					max=mov_sum_ss1.rerange();
					sm+=max;
					num++;
				}
			}
			
		}
	}	
	
	
	std::cout<<num<<std::endl;
	std::cout<<sm<<std::endl;
	std::cout<<max<<std::endl;
	
	
	return 0;
}
