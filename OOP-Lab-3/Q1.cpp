#include <iostream>
using namespace std;

class User 
{
    public:
        int Age;
        string name;
};






int main()  {
    User user1;
    user1.Age = 24;
    user1.name = "Teo";
    cout << "My name is " << user1.name << " and I'm " << user1.Age << " years old.";
}