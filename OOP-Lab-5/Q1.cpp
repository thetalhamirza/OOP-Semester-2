#include "iostream"
#include "string.h"
using namespace std;

class Engine{
    public:
        Engine(){
            cout << "\nEngine Constructed" << endl;
        }

        bool isRunning;
        void start(){
            if (!isRunning){
                cout << "\nEngine Started" << endl;
                isRunning = true;
            }
        }
        void stop(){
            if (isRunning){
                cout << "\nEngine Stopped" << endl;
                isRunning = false;
            }
        }
        ~Engine (){
            cout << "\nEngine Destroyed" << endl;
        }
};

class Car{
    Engine engine;
    public:
        Car(){
            cout << "\nCar Constructed" << endl;
        }
        void startCar(){
            engine.start();
        }
        void stopCar(){
            engine.stop();
        }
        ~Car (){
            cout << "\nCar Destroyed" << endl;
        }
};

int main(){

    Car car1;
    
    car1.startCar();
    car1.stopCar();

    return 0;
}