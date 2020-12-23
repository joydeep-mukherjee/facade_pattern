//this program implements the facade pattern
//makes an interface simpler
//Facade pattern is fairly straightforward
//allows us to avoid tight coupling between clients and subsystems
#include<iostream>
using namespace std;

//subsystem class-1
class Engine
{

public:
    void Start() {cout<<"Engine Starts"<<endl;}
    void Stop()  {cout<<"Engine Stops"<<endl;}

};

//subsystem class-2
class Headlights
{

public:
    void TurnOn() {cout<<"Headlights On"<<endl; }
    void TurnOff() {cout<<"Headlights Off"<<endl;}

};

//subsystem class-3
class Infotainment
{
public:
	void displayOn() {cout<<"Infotainment Screen Glows"<<endl;}
	void displayOff() {cout<<"Infotainment Screen Dims"<<endl;}
};

//Facade class uses design principle of least knowledge
class CarFacade
{
private:
	//uses composition for subsystem classes
    Engine engine;
    Headlights headlights;
    Infotainment led;

public:
    void TurnIgnitionKeyOn()
    {
    	//internally calls subsystem class methods
        headlights.TurnOn();
        engine.Start();
        led.displayOn();
    }

    void TurnIgnitionKeyOff()
    {
    	//internally calls subsystem class methods
    	headlights.TurnOff();
    	engine.Stop();
    	led.displayOff();
    }

};

int main()
{
    // Use only Facade Class in client
    CarFacade car;
    cout<<"When Ignition is turned On:"<<endl;
    cout<<"--------------------------"<<endl;
    car.TurnIgnitionKeyOn();
    cout<<endl<<endl<<"When Ignition is turned Off:"<<endl;
    cout<<"--------------------------"<<endl;
    car.TurnIgnitionKeyOff();

}

