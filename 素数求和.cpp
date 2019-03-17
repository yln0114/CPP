#include <stdio.h>
char s[10000000];
int main()
{
	int m,i,e,f;
	scanf("%d",&m);
	for (i=1;i<=m;i++){
		s[i]=1;
	}
		int k,j,c;
		s[1]=0;
		s[2]=1;
		for (k=2;k<=m;k++){
			if (s[k]!=0){
				f=m/k;
				for(c=2;c<=f;c++){
					j=k*c;
					s[j]=0;
				}	
			}
			
		}
		long long sum;
		sum=0;
		for (e=2;e<m;e++){
			if (s[e]==1){
			sum=sum+e;
			}
		}
		  	
		printf("%lld\n",sum);			
	return 0;
}
