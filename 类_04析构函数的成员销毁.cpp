#include <iostream>
#include <string>
class S{
	public:
		char l[100];
		int i;
		Sa();
		~S();
		
		Print();
		
		

	
};
S::Sa(){
	std::cout<<"Give S.l S.i a value:\n";
	std::cin>>l;
	std::cin>>i;
}
S::Print(){
	printf("char l = : %s\n",l);
	printf("int i = :%d\n",i);
	
	
}
S::~S(){
	std::cout<<"End and clean.\n";
}
int main ()
{
	S S1;
	S1.Sa();
	S1.Print();
	
	
	
	
	return 0;
}

