#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Point{
	private:
			double x; 
			double y;
			string name;
			static int num;
	public:			
			Point(){ num++; set(0,0,"Default");}
			Point(double a,double b,string n){ num++; set(a,b,n);}		
			Point(int a,int b,string n){num++; set(a,b,n);}
			
			~Point(){
				num--;
				cout<<"Delete Point: "<<name<<endl;
				cout<<"num: "<<num<<endl;
			}
		
			//set all function
			void set(double a,double b,string n){
				x = a; y = b; name = n; 
			}
			// new function!!!!!!!!!!!!!!!!!!!
			double dot(Point &p){
				return x * p.getX() + y * p.getY();
				// (x1,y1)*(x2,y2)= x1*x2+y1*y2
			}
			// new function!!!!!!!!!!!!!!!!!!!
			Point midpoint(Point& p1,Point& p2){
				double mx = (p1.getX() + p2.getY()) / 2.0;
				double my = (p1.getY() + p2.getY()) / 2.0;
				string mName = "(" + p1.getName() + " and " + p2.getName() + ") midpoint";
				Point m(mx,my, mName);
				return m;
			}
			
			
			//set someone function
			void setX(double a){ x=a;}
			void setY(double b){ y=b;}
			void setX(int a){ x=a;}
			void setY(int b){ y=b;}
			void setName(string n){ name=n;}
			
			//get function
			double getX(){return x;}
			double getY(){return y;}
			string getName(){return name;}
			static int staticNum(){return num;}
			
			//show 
			void show(){
				cout<<" x,y = ("<<x<<","<<y<<")"<<endl;
				cout<<" namePoint: [ "<<name<<" ]"<<endl;
				cout<<"==========================="<<endl;
			}
			
};int Point::num;

int main(){
	cout<<"num: "<<Point::staticNum()<<endl;
	
	Point a_Point;
	cout<<"num: "<<Point::staticNum()<<endl; 
	a_Point.show(); 
	
	Point b_Point; 
	cout<<"num: "<<Point::staticNum()<<endl;
	b_Point.show(); 
	
	Point c_Point(1,1,"C Point");
	cout<<"num: "<<Point::staticNum()<<endl;
	c_Point.show(); 
	
	Point d_Point(9.5,8.5,"D Point");
	cout<<"num: "<<Point::staticNum()<<endl;
	d_Point.show();
	
	cout<<"----------------------------"<<endl;
	cout<<"--      new funtioon      --"<<endl;
	cout<<"----------------------------"<<endl;
	
	// call funtion dot()
	cout<< "dot funtion of c_Point and d_Point: "<<c_Point.dot(d_Point)<<endl;
	// call funtion midPoint()
	Point m_Point = c_Point.midpoint(c_Point,d_Point);
	cout << "midpoint of c_Point and d_Point: ";
	m_Point.show();
	
	cout<<"----------------------------"<<endl;
	cout<<"--         ending         --"<<endl;
	cout<<"----------------------------"<<endl;
	
	
		
	a_Point.set(1,2,"A Point");
	a_Point.show();
	// Point::staticNum();
	cout<<"num: "<<Point::staticNum()<<endl;
	
	b_Point.set(3.3,4.4,"B Point");
	b_Point.show();
	// Point::staticNum();
	cout<<"num: "<<Point::staticNum()<<endl;
	//myPoint
	c_Point.set(1,2,"C Point");
	c_Point.show();
	// Point::staticNum();
	cout<<"num: "<<Point::staticNum()<<endl;
	
	c_Point.setX(-2.2);
	c_Point.setY(1.1);
	c_Point.setName("C Point");
	c_Point.show();
	// Point::staticNum();
	cout<<"num: "<<Point::staticNum()<<endl;
	
	//youPoint
	d_Point.set(3.3,-4.4,"D Point");
	d_Point.show();
	cout<<"num: "<<Point::staticNum()<<endl;
	
	d_Point.setX(7);
	d_Point.setX(8);
	d_Point.setName("D point");
	d_Point.show();
	
	Point e_Point;
	e_Point.set(0.5,0.5,"E Point");
	cout<<"num: "<<Point::staticNum()<<endl;
	e_Point.show();

	//call getFunction
	cout<<"num: "<<Point::staticNum()<<endl;
	cout<<"                         "<<endl;
	cout<<"get X : "<<c_Point.getX()<<endl;
	cout<<"get Y : "<<c_Point.getY()<<endl;
	cout<<"get Name : "<<c_Point.getName()<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"num: "<<Point::staticNum()<<endl;
	cout<<"                         "<<endl;
	cout<<"get X : "<<d_Point.getX()<<endl;
	cout<<"get Y : "<<d_Point.getY()<<endl;
	cout<<"get Name : "<<d_Point.getName()<<endl;
	cout<<"----------------------------"<<endl;
	
	cout<<"                            "<<endl;
	

}
