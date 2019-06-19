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
		void delRow(int i){//é?3yμúiDD 
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
		
		//构造函数 

		~Cell();



		void show(){
			int i=0;
			cout<<"NO."<<i<<"row: "<<content<<endl;
			
		}
		
		
		//显示成员cell.content

	private:

		string content;//string 类型 content存储string模板

};
Cell::Cell(char con[]){
	cout<<"Cell con[] add"<<endl;
	cin>>con;//con 传递给string content 
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
		
		void show();//打表

		int addRow();//增加行

		void delRow(int n);//删除n行

		int addColumn();//增加列 //有点问题,增加到哪个位置???

		void delColumn(int n);//删除第n列
		
		void set(int a,int b,int c);

	private:

		Cell cells;
		

};
Table::show(){
	
	cells.show();
	
	
	
}



int main() {

	Table tb;//初始化表(未构造) 

	tb.show();//显示表的内容

	tb.addRow();//增加表的行

	tb.show();//重现表

	tb.addColumn();//增加表的列

	tb.show();//再现表

	Table tb1(5,5);//构造函数初始化表--按5*5

	tb1.show();//

	tb1.set(1,1,30);//位点(1,1)初始化

	tb1.set(2,2,"hello");//位点(2,2)改

	tb1.show();//重现表

	tb1.delRow(1);//删除行1

	tb1.show();//显示表

	tb1.delColumn(1);//删除列 1

	tb1.show();//重现表

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
