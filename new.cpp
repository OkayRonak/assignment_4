//OOP ASSIGNMENT
//Ronak Sinha
//21051843

#include<iostream>
#include<fstream>
using namespace std;

class Vehicle                                                                               //class
{
    public:
    string name;
    int modelno, year, category;
    Vehicle()                                                                              //Constructor
    {
        name="Enter a name";
        modelno=0;
    }
    virtual void getdata()                                                        //virtual function(run time polymorphism)
    {
        cout<<"Enter the name of the vehicle: "<<endl;
        cin>>name;
        cout<<"Enter the model number and the year of manufacture of the vehicle: "<<endl;
        cin>>modelno>>year;
    }
    virtual void showdata()=0;                                                    //pure virtual function
};

class Car: public Vehicle                                                                 //Inheritance
{
    public:
    string car_name, Ccompany, str[2];
    int category=1;
    friend ostream& operator<<(ostream&,Car);
    void getdata()
    {
        cout<<"Enter the name and company of the vehicle: "<<endl;
        cin>>name>>Ccompany;
        cout<<"Enter the model number and the year of manufacture of the vehicle: "<<endl;
        cin>>modelno>>year;
    }
    void showdata()
    {
        cout<<"The name of the car is: "<<name<<endl;
        cout<<"The company of the car is : "<<Ccompany<<endl;
        cout<<"CAR IS STORED IN CATEGORY: "<<category<<endl;
    }
    void takeinput()
    {
        ofstream obj;                                                                     //file object declared
        obj.open("DATA.txt",ios::app);                                                    //File opened in append mode      
        Car object;
        object.getdata();
        object.showdata();
        obj.write((char*)&obj,sizeof(object));
                                                                                
    }
};
 ostream& operator<<(ostream& p,Car ob)                                      //operator overloading (compile time polymorphism)
 {
    ob.showdata();
    return p;
 }
class Bike: public Vehicle
{
    public:
    string bike_name, Bcompany, str[2];
    int category=2;
    void getdata()
    {   int y;
        cout<<"Enter the name and company of the vehicle: "<<endl;
        cin>>name>>Bcompany;
        cout<<"Enter the model number and the year of manufacture of the vehicle: "<<endl;
        cin>>modelno>>y;                                                                       //Exception Handling
        try{
            if(y<=0)
            throw 1;
            else
            year=y;
        }
        catch(int)
        {
            cout<<"The year cannot be negative.";
        }
    }
    void showdata()
    {
        cout<<"The name of the bike is : "<<name<<endl;
        cout<<"The company of th bike is: "<<Bcompany<<endl;
        cout<<"BIKE IS STORED IN CATEGORY: "<<category<<endl;
    }
    void takeinput()
    {
        ofstream obj;                                                                     //file object declared
        obj.open("DATA.txt",ios::app);                                                    //File opened in append mode      
        Bike object;
        object.getdata();
        object.showdata();
        obj.write((char*)&obj,sizeof(object));
                                                                                
    }
};

int main()
{
    Vehicle *v;
    Car c;
    Bike b;
    v=&c;
    c.takeinput();
    cout<<c;

    return 0;
}