#include <iostream>
#include <bits/stdc++.h>
/*

	need
	 
	empty
	



*/




using namespace std;

#include <sstream>
using namespace std;


	string a[1000][1000];
class Table{
	protected:
		int row;
		int column;
	public:
		Table(){
			row=1;
			column=1;
		}
		void show(){
			for(int i=0;i<row;i++){
				for(int j=0;j<column;j++){
					cout<<a[i][j]<<" ";
				}cout<<"\n";
			}
		cout<<"\n";	
		}
		void addRow(){
			row=row++;
		}
		void addColumn(){
			column=column++;
		}
		Table(int x,int y){
			row=x;
			column=y;
		}
		void set(int x,int y,int z){
			stringstream ss;
			string u;
			ss<<z;
			ss>>u;
			a[x][y]=u;
		}
		void set(int x,int y,string z){
			a[x][y]=z;
		}
		void delRow(int i){//��?3y�̨�iDD 
			 for(int j=i;j<row-1;j++){
			 	string *p=a[j];
			 	*a[j]=*a[j+1];
				*a[j+1]=*p;
			 }
			 row--;
		} 
		void delColumn(int i){
			for(int j=i;j<column-1;j++){
				for(int k=0;k<row-1;k++){
					string p=a[j][k];
					a[j][k]=a[j][k+1];
					a[j][k+1]=p;
				}
			}
			column--;
		}
};

int main() {

  Table tb;
  
  tb.show();

  tb.addRow();

  tb.show();

  tb.addColumn();

  tb.show();

  Table tb1(5,5);

  tb1.show();

  tb1.set(1,1,30);

  tb1.set(2,2,"hello");

  tb1.show();

  tb1.delRow(1);

  tb1.show();

  tb1.delColumn(1);

  tb1.show();

  return 0;
/*

class Cell {

	public:

		
		
		
		Cell(char con[]);
		
		//���캯�� 

		~Cell();



		void show(){
			int i=0;
			cout<<"NO."<<i<<"row: "<<content<<endl;
			
		}
		
		
		//��ʾ��Աcell.content

	private:

		string content;//string ���� content�洢stringģ��

};
Cell::Cell(char con[]){
	cout<<"Cell con[] add"<<endl;
	cin>>con;//con ���ݸ�string content 
	content=con;
	
			
			
}



class Table {

	public:
		Table(){
			int a=5;
			int b=5;
			;
		}

		Table(int a,int b){
			
		}
		
		void show();//���

		int addRow();//������

		void delRow(int n);//ɾ��n��

		int addColumn();//������ //�е�����,���ӵ��ĸ�λ��???

		void delColumn(int n);//ɾ����n��
		
		void set(int a,int b,int c);

	private:

		Cell cells;
		

};
Table::show(){
	
	cells.show();
	
	
	
}



int main() {

	Table tb;//��ʼ����(δ����) 

	tb.show();//��ʾ�������

	tb.addRow();//���ӱ����

	tb.show();//���ֱ�

	tb.addColumn();//���ӱ����

	tb.show();//���ֱ�

	Table tb1(5,5);//���캯����ʼ����--��5*5

	tb1.show();//

	tb1.set(1,1,30);//λ��(1,1)��ʼ��

	tb1.set(2,2,"hello");//λ��(2,2)��

	tb1.show();//���ֱ�

	tb1.delRow(1);//ɾ����1

	tb1.show();//��ʾ��

	tb1.delColumn(1);//ɾ���� 1

	tb1.show();//���ֱ�

	return 0;

}

*/



/*


class Table {

public:



  void show();

  int addRow();

  void delRow(int n);

  int addColumn();

  void delColumn(int n);

private:

  Cell cells;

};

class Cell {

public:

  Cell(char con[]);

  ~Cell();



  void show();

private:

  string content;

}

int main() {

  Table tb;

  tb.show();

  tb.addRow();

  tb.show();

  tb.addColumn();

  tb.show();

  Table tb1(5,5);

  tb1.show();

  tb1.set(1,1,30);

  tb1.set(2,2,"hello");

  tb1.show();

  tb1.delRow(1);

  tb1.show();

  tb1.delColumn(1);

  tb1.show();

  return 0;

}


*/
