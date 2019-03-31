#include <iostream>
#include <string>
#include <cstring>

char error[100]="This puzzle has no final configuration."; 
class S{
	public:
		char s[10][10];//s means the table array
		
		char c; //c is the order
		//now we need to originate the s
		Ori();	
		void Print();
		int swap();
		int order(char c1);
		int x,y;
		void find();
		~S();
		
	
};
S::~S(){
	std::cout<<"NOW : end and clean\n";
}
void S::find(){
	int g=0;int i,j;
	for (i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(s[i][j]==' '){
				g=1;
				break;
			}
		}
		if(g==1){
			break;
		}
	}
	x=i;
	y=j;
	printf("x=%d y=%d\n",x,y);
	
}
S::Ori(){
	char s0[10];
	
	int i=0;
	for (i=0;i<5;i++){
		std::cout<<"Line NO. "<<i<<std::endl;
		fgets(s0,8,stdin);
		strcpy(s[i],s0);
		memset(s0,0,sizeof(s0));
	}

}
int S::order(char c1){
	
	int z;
	//std::cin>>c1;
	c=c1;
	z=swap();
	if(z==0){
		printf("%s\n",error);
		return z;
	}
	c='\0';
	return z;
}
int S::swap(){
	int a=0;
	char t='\0';
	find();
	
	if (c=='B'&&x+1<5){
		t=s[x][y];
		s[x][y]=s[x+1][y];
		s[x+1][y]=t;
		x=x+1;
		a=1;	
	}	
	if (c=='A'&&x-1>=0){
		t=s[x][y];
		s[x][y]=s[x-1][y];
		s[x-1][y]=t;
		x=x-1;
		a=1;
	}
	if (c=='R'&&y+1<5){
		t=s[x][y];
		s[x][y]=s[x][y+1];
		s[x][y+1]=t;
		y=y+1;
		a=1;
	}
	if(c=='L'&&y-1>=0){
		t=s[x][y];
		s[x][y]=s[x][y-1];
		s[x][y-1]=t;
		y=y-1;
		a=1;
	}
	return a;
}
void S::Print(){
	for (int i=0;i<5;i++){
		std::cout<<s[i];
	}
	puts("\n");
}
int main ()
{
	S S1;
	S1.Ori();
	//S1.Print();
	//std::cin<<s0;
	int z=1;
	char c1[10];
	std::cout<<"The order char :\n";
	std::cin>>c1;
	int i=0;
	while(z==0||c1[i]!='0'){
		
		z=S1.order(c1[i]);
		//S1.Print();
		i++;
		
	}
	if (z=!0){
		S1.Print();
	}
	
	
	
	return 0;
}
