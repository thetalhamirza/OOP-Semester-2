# include <iostream>
# include <string>

using namespace std;

class Student
{
    string name;
    string ID;
    int fees_paid; // 0: Not Paid, 1: Paid
    string stop;
    int point;
    int *Attendance;

    public:

    Student(string name, string ID, int fees_paid, string stop) : name(name), ID(ID), fees_paid(fees_paid), stop(stop)
    {
        point = -1;
        cout << "Enter the days of semester: ";
        int days;
        cin >> days;
        Attendance = new int[days];
        for (int i = 0; i < days; i++)
        {
            Attendance[i] = 0;
        }
    }

    void markAttendance(int i) // i is the day of the semester
    {
        Attendance[i-1] = 1;
        cout << "Attendance marked!" << endl;
    }

    Student(){}

    ~Student(){}

    int getFeesPaid()
    {
        return fees_paid;
    }

    void setFeesPaid(int f)
    {
        fees_paid = f;
    }

    void setPoint(int p)
    {
        point = p;
    }

    int getPoint()
    {
        return point;
    }

    string getID()
    {
        return ID;
    }

    string getStop()
    {
        return stop;
    }

    void viewDetails()
    {
        cout << "----- Student Details -----" << endl;
        cout << "Name: " << name << endl;
        cout << "FAST-NU ID: " << ID << endl;
        if (fees_paid == 0)
        {
            cout << "The fees is not Paid!" << endl;
        }
        else
        {
            cout << "The fees is Paid!" << endl;
        }
        cout << "The stop of the student is: " << stop << endl;
    }
};

class Bus
{
    string name;
    static int counter;
    int current;
    int id;
    int max;
    int max_students;
    int current_students;
    Student* studentsRegistered;
    string* busStops;
    Student *s;
    
    public:

    Bus(string name) : name(name)
    {
        current = 0;
        current_students = 0;
        id = counter++;
        cout << "Enter the maximum number of stops of the bus: " << endl;
        cin >> max;
        busStops = new string[max];
        cout << "Enter the maximum number of students which can be registered: " << endl;
        cin >> max_students;
        studentsRegistered = new Student[max_students];
    }

    Bus(){}

    ~Bus()
    {
        delete[] busStops;
        delete[] studentsRegistered;
    }

    int getMax()
    {
        return max;
    }

    void AddStop(string bus_stop)
    {
        if (current < max)
        {
            busStops[current] = bus_stop;
            cout << "Bus Stop has been Added!" << endl;
            current++;
            
        }
        else
        {
            cout << "Max Limit Reached. Cannot Add More Bus Stops." << endl;
        }
    }

    int searchStop(Student &s)
    {
        int found = 0;
        int i = 0;
        while ((found == 0) && (i < current))
        {
            if (s.getStop() == busStops[i])
            {
                return 1;
            }
            i++;
        }
        return 0;
    }

    void AddStudent(Student &s)
    {
        if (current_students < max_students)
        {
            if (s.getFeesPaid() == 1)
            {
                if (searchStop(s) == 1)
                {
                    studentsRegistered[current_students] = s;
                    s.setPoint(id);
                    cout << "Student has been Registered!" << endl;
                    current_students++;
                }
                else
                {
                    cout << "This Bus does not offers the desired Bus Stop." << endl;
                }
            }
            else
            {
                cout << "Fees has not been Paid!" << endl;
            }
            
        }
        else
        {
            cout << "Max Limit Reached. No more students can be registered!" << endl;
        }
    }

    void removeStudent(string ID)
    {
        if (counter > 0)
        {   
            int found = 0;
            int i = 0;
            while ((found == 0) && (i < current_students))
            {
                if (studentsRegistered[i].getID() == ID)
                {
                    found = 1;
                    break;
                }
                i++;
            }
            if (found == 1)
            {
                for (int j = i; j < counter-1; j++)
                {
                    studentsRegistered[j] = studentsRegistered[j+1];
                }
                current_students--;
                cout << "Student Removed!" << endl;
            }
            else
            {
                cout << "Invalid Student ID." << endl;
            }
        }
        else
        {
            cout << "No Students Registered." << endl;
        }
    }

    void initializeFeesPaid()
    {
        for (int i = 0; i < current_students; i++)
        {
            studentsRegistered[i].setFeesPaid(0);
        }
    }

    void viewDetails()
    {
        cout << "----- Bus Details -----" << endl;
        cout << "Route Number: " << id << endl;
        cout << "\nThe stops of the bus: " << endl;
        for (int i = 0; i < counter; i++)
        {
            cout << i+1 << ".   " << busStops[i] << endl;  
        }
        // cout << "\nStudents Registered: " << endl;
        // for (int i = 0; i < current_students; i++)
        // {
        //     studentsRegistered[i].viewDetails();  
        // }
        cout << "-----------------------" << endl;
    }
};

class PointSystem
{
    string name;
    static int counter;
    int max;
    Student* s;
    Bus* b;
    Bus *busSystem;

    public:

    PointSystem(string name) : name(name)
    {
        cout << "Enter the maximum number of buses which can be registered in the system: " << endl;
        cin >> max;
        busSystem = new Bus[max];
    }

    ~PointSystem()
    {
        delete[] busSystem;
    }

    void registerBus(Bus &b)
    {
        if (counter < max)
        {
            busSystem[counter] = b;
            counter++;
            cout << "Bus has been registered!" << endl;
        }
        else
        {
            cout << "Maximum capacity has been reached. No more buses can be registered!" << endl;
        }
    }

    void viewDetails()
    {
        cout << "----- All Point Services Details -----" << endl;
        for (int i = 0; i < counter; i++)
        {
            busSystem[i].viewDetails();
        }
    }

    void initializeFees()
    {
        for (int i = 0; i < counter; i++)
        {
            busSystem[i].initializeFeesPaid(); // new semester
        }
    }

    void AddStudent(Bus &b, Student &s)
    {
        b.AddStudent(s);
    }

    void removeStudent(Bus &b, Student &s)
    {
        b.removeStudent(s.getID());
    }

    
};

int Bus :: counter = 0;
int PointSystem :: counter = 0;

int main()
{

	cout << "Name: Talha Mirza" << endl;
	cout << "24K-0973\n" << endl;
    
    cout << "----- Point System -----" << endl;
    
    cout << "\nBus 1: " << endl;
    Bus bus1("Jadoon");
    bus1.AddStop("A");
    bus1.AddStop("B");
    bus1.AddStop("C");

    cout << "\nBus 2: " << endl;
    Bus bus2("Nadeem");
    bus2.AddStop("D");
    bus2.AddStop("E");
    bus2.AddStop("F");

    PointSystem ps("University Transport");
    ps.registerBus(bus1);
    ps.registerBus(bus2);

    Student student1("Talha", "k240973", 1, "A");
    Student student2("Ayesha", "k240900", 1, "B");
    Student student3("Safi", "k219870", 1, "C");

    Student student4("Khanum", "k240840", 1, "D");
    Student student5("Khan", "k240900", 1, "E");
    Student student6("Shahid", "k219860", 0, "F");

    ps.AddStudent(bus1, student1);
    ps.AddStudent(bus1, student2);
    ps.AddStudent(bus1, student3);
    ps.AddStudent(bus2, student4);
    ps.AddStudent(bus2, student5);
    ps.AddStudent(bus2, student6);

    student1.markAttendance(1);
    student4.markAttendance(1);
    student5.markAttendance(1);

    bus1.removeStudent("k240973"); 
    ps.viewDetails();

    ps.initializeFees();

    return 0;
}
