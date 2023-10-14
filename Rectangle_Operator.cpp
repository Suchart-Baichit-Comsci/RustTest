#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

class Rectangle{
	private:
			int width; int length; 
			char name[20];
			static int num;
	public:	
			Rectangle(){ num++; set(0,0,(char*)"no name");} //convert char*
			Rectangle(int w,int l){ num++; set(w,l,(char*)"no name");}
			Rectangle(int w,int l,char *n){ num++; set(w,l,n);}
			Rectangle(int w,char *n){ num++; set(w,0,n);}
			
			~Rectangle(){
				num--;
				cout<<"Delete: "<<name<<endl;
				cout<<"num: "<<num<<endl;
			}
			
			//set function
			void set(int w,int l,char *n){
				width = w; length = l; strcpy(name,n);
			}
			
			//Formular function
			int calculatorFunc(){
				int total; 
				total = width * length;
				return total;
			}
			int perimeterFunc(){
				int perimeter; 
				perimeter = 2 * (width + length);
				return perimeter;
			}

			//set someone function
			void setWidth(int w){ width=w;}
			void setLength(int l){ length=l;}
			void setName(char *n){ strcpy(name,n);}
			
			//get function
			int getWidth(){return width;}
			int getLength(){return length;}
			char* getName(){return name;}
			int getArea() const {return width * length;}
			static int staticNum(){return num;}
			
			void show(){
				cout<<"[ Function Show ]"<<endl;
				cout<<">> width and length = "<<"("<<width<<","<<length<<")"<<endl;
				cout<<">> name: "<<name<<endl;
			}
			
			//front
			Rectangle operator++(){ // prefix 
			//	if (width > 0 && length > 0){
				++length;
			//	}
				return *this;
			}
			
			Rectangle operator--(){ // prefix
				if (length > 1){
				--length;
				}
				return *this;
			}
			
			//back
			Rectangle operator++(int){ // postfix
				Rectangle temp = *this;
			//	if (width > 0 && length > 0){
				++width;
			//	}
				return temp;
			}
			
			Rectangle operator--(int){ // postfix
				Rectangle temp = *this;
				if (width > 1){
				--width;
				}
				return temp;
			}
			
			//friend Rectangle operator--(Rectangle &rect){
			//	rect.length--;
			//	return rect;
			//}
			//friend Rectangle& operator++(Rectangle& rect);  // length Prefix ++
		    //friend Rectangle operator++(Rectangle& rect, int);  // Width Postfix ++
		    //friend Rectangle& operator--(Rectangle& rect);  // length Prefix --
		    //friend Rectangle operator--(Rectangle& rect, int);  // Width Postfix --

			int operator()() const {
        	return width * length;
    		}
			
			int operator()(int w) const{
			return width * width;
			}
			
			int operator()(int w,int l) const{
				return (width * width) + (length * length);
			}
			
			int operator[](int index) {
			    if (index == 0) {
			        return width;
			    } else if (index == 1) {
			        return length;
			    } else {
			    	cout << "error input 0 or 1 []"<<endl;
					return -1;
			    }
			}
		    
			bool operator<(const Rectangle& other) const {
		        return getArea() < other.getArea();
		    }
		
		    bool operator<=(const Rectangle& other) const {
		        return getArea() <= other.getArea();
		    }
		
		    bool operator>(const Rectangle& other) const {
		        return getArea() > other.getArea();
		    }
			
		    bool operator>=(const Rectangle& other) const {
		        return getArea() >= other.getArea();
		    }
		
		    bool operator!=(const Rectangle& other) const {
		        return getArea() != other.getArea();
		    }
			
};	int Rectangle::num;
/*
Rectangle& operator++(Rectangle& rect) {
    if (rect.width > 0 && rect.length > 0) {
        ++rect.length;
    }
    return rect;
}

Rectangle operator++(Rectangle& rect, int) {
    Rectangle temp = rect;
    if (rect.width > 0 && rect.length > 0) {
        ++rect.width;
    }
    return temp;
}

Rectangle& operator--(Rectangle& rect) {
    if (rect.length > 0) {
        --rect.length;
    }
    return rect;
}

Rectangle operator--(Rectangle& rect, int) {
    Rectangle temp = rect;
    if (rect.width > 0) {
        --rect.width;
    }
    return temp;
}
*/

int main(){
    Rectangle rect1(3, 4);
    Rectangle rect2(5, 4);
    Rectangle rect3(1, 1);
	
	cout<< "=== Testing ===" <<endl;
	cout << "rect3 => width: "<< rect3.getWidth() << " | length: " << rect3.getLength() <<endl;
	rect3++;
	++rect3;
	cout << "rect3 => width: "<< rect3.getWidth() << " | length: " << rect3.getLength() <<endl;
	rect3--;
	--rect3;
	cout << "rect3 => width: "<< rect3.getWidth() << " | length: " << rect3.getLength() <<endl;
	// < 0
	rect3--;
	--rect3;
	cout << "rect3 => width: "<< rect3.getWidth() << " | length: " << rect3.getLength() <<endl;
	
	rect1 = ++rect2;
	cout << "rect1 = ++rect2" <<endl;
	cout << "rect1 => width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
	cout << "rect2 => width: "<< rect2.getWidth() << " | length: " << rect2.getLength() <<endl;
	rect3 = rect1++;
	cout << "rect3 = rect1++" <<endl;
	cout << "rect3 => width: "<< rect3.getWidth() << " | length: " << rect3.getLength() <<endl;
	cout << "rect1 => width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
	
	rect1 = --rect2;
	cout << "rect1 = --rect2" <<endl;
	cout << "rect1 => width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
	cout << "rect2 => width: "<< rect2.getWidth() << " | length: " << rect2.getLength() <<endl;
	rect3 = rect1--;
	cout << "rect3 = rect1--" <<endl;
	cout << "rect3 => width: "<< rect3.getWidth() << " | length: " << rect3.getLength() <<endl;
	cout << "rect1 => width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
	cout << "=============================" <<endl;
	
	cout << "rect1 => width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
	cout << "rect2 => width: "<< rect2.getWidth() << " | length: " << rect2.getLength() <<endl;
	cout << "rect3 => width: "<< rect3.getWidth() << " | length: " << rect3.getLength() <<endl;
	cout << "=============================" <<endl;
	
	cout << "Original Rectangle: "<<endl;
    rect1.show();
    
    cout << "Prefix Increment: "<<endl; // lenght++ 3 4 -> 3 5
    ++rect1;
    cout << "width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
    rect1.show();
    
    cout << "Postfix Increment: "<<endl; // width++ 3 5 -> 4 5
    rect1++;
    cout << "width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
	rect1.show();
    
    cout << "Prefix Decrement: "<<endl; // length-- 4 5 -> 4 4
    --rect1;
    cout << "width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
    rect1.show();
    
    cout << "Postfix Decrement: "<<endl; // width-- 4 4 -> 3 4
	rect1--;
	cout << "width: "<< rect1.getWidth() << " | length: " << rect1.getLength() <<endl;
    rect1.show();
	
	int area = rect1();
	cout << "Area: "<< area <<endl;
	int squaredWidth = rect1(1); 
	cout << "Squared width: " << squaredWidth << endl;
	int customArea = rect1(1, 1);
    cout << "Custom area: " << customArea << endl;
	
	int a = rect1[0];
	int b = rect1[1];
    int c = rect1[2];
    
    cout << "Before Increment:" << c << endl;
    
	cout << "Before Increment: width = " << a << ", length = " << b << endl;
    ++b;  // Prefix increment length
    cout << "After prefix increment: width = " << a << ", length = " << b << endl;

    a++;  // Postfix increment width
    cout << "After postfix increment: width = " << a << ", length = " << b << endl;

    --b;  // Prefix decrement length
    cout << "After prefix decrement: width = " << a << ", length = " << b << endl;

    a--;  // Postfix decrement width
    cout << "After postfix decrement: width = " << a << ", length = " << b << endl;

    cout << "Rectangle 1 area: " << rect1.getArea() << endl;
    cout << "Rectangle 2 area: " << rect2.getArea() << endl;
    cout << "Rectangle 3 area: " << rect3.getArea() << endl;

    cout << "Comparisons:" << endl;
    cout << "rect1 < rect2: " << (rect1 < rect2) << endl;
    cout << "rect1 <= rect2: " << (rect1 <= rect2) << endl;
    cout << "rect1 > rect2: " << (rect1 > rect2) << endl;
    cout << "rect1 >= rect2: " << (rect1 >= rect2) << endl;
    cout << "rect1 != rect2: " << (rect1 != rect2) << endl;

    cout << "rect1 < rect3: " << (rect1 < rect3) << endl;
    cout << "rect1 <= rect3: " << (rect1 <= rect3) << endl;
    cout << "rect1 > rect3: " << (rect1 > rect3) << endl;
    cout << "rect1 >= rect3: " << (rect1 >= rect3) << endl;
    cout << "rect1 != rect3: " << (rect1 != rect3) << endl;

}
