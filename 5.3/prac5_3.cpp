#include<iostream>
using namespace std;

class Cordinate
{
    private:   // private members
    int Cord_x,Cord_y;
    public:    // public members
    // constructor to initialize the coordinates
    Cordinate(int x=0,int y=0):Cord_x(x),Cord_y(y)
    {}
    // showing data
    void show()
    {
        cout<<"X coordinate: "<<Cord_x<<endl;
        cout<<"Y coordinate: "<<Cord_y<<endl;
    }
    // operator overloading for + operator
    Cordinate operator+ (const Cordinate &obj)
    {
        Cordinate Result;
         return Result=Cordinate(this->Cord_x + obj.Cord_x,this->Cord_y + obj.Cord_y);
    }
    // operator overloading for - operator
    Cordinate operator- ()
    {
        return Cordinate(-Cord_x,-Cord_y);
    }
    // operator overloading for == operator
    bool operator == (Cordinate &obj)
    {
        return (this->Cord_x == obj.Cord_x && this->Cord_y == obj.Cord_y);
    }

};


// main function stack started from here

int main()
{
    Cordinate C1(2,3),C2(2,3),C3(4,5),C4,C5;
    C1.show();
    C2.show();  
    C3.show();
    C4 = C1 + C2;
    cout<<"Sum of Cordinate 1 and Cordinate 2 is: "<<endl;
    C4.show();

    C5 = -C1;

    cout<<"Subtraction of Cordinate 1 and Cordinate 2 is: "<<endl;
    C5.show();


    if(C1 == C2)
    {
        cout<<"Cordinate 1 and Cordinate 2 are equal"<<endl;
    }
    else
    {
        cout<<"Cordinate 1 and Cordinate 2 are not equal"<<endl;
    }
    if(C1 == C3)
    {
        cout<<"Cordinate 1 and Cordinate 3 are equal"<<endl;
    }
    else
    {
        cout<<"Cordinate 1 and Cordinate 3 are not equal"<<endl;
 
    }
    return 0;
}