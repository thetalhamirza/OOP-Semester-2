#include <iostream>
using namespace std;

class Person {
    protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

    public:
    Person(string n, string i, string addr, string phone, string email)
        : name(n), id(i), address(addr), phoneNumber(phone), email(email) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    virtual void updateInfo(string n, string addr, string phone, string mail) {
        name = n;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }
    string getName() {return name;}
    virtual ~Person() {}
};

class Student : public Person {
    private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

    public:
    Student(string n, string i, string addr, string phone, string mail, double gpa, int year) : Person(n, i, addr, phone, mail), GPA(gpa), enrollmentYear(year) {}

    void enrollCourse(const string &course) {
        coursesEnrolled.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "Courses Enrolled: ";
        for (const auto &course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
    private:
    string department;
    vector<string> coursesTaught;
    double salary;

    public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, double sal) : Person(n, i, addr, phone, mail), department(dept), salary(sal) {}

    void assignCourse(const string &course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: ";
        for (const auto &course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Staff : public Person {
    private:
    string department;
    string position;
    double salary;

    public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal) : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course {
    private:
    string courseId;
    string courseName;
    int credits;
    Professor* instructor;
    string schedule;

    public:
    Course(string id, string name, int creds, Professor* prof, string sched) : courseId(id), courseName(name), credits(creds), instructor(prof), schedule(sched) {}

    void registerStudent(Student &student) {
        cout << "Registering " << student.getName() << " for the course: " << courseName << endl;
    }

    void calculateGrades() {
        cout << "Calculating grades for course: " << courseName << endl;
    }

    void displayCourseInfo() const {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor->getName() << endl;
        cout << "Schedule: " << schedule << endl;
    }
};


int main() {
    Professor prof("Dr. Smith", "P123", "123 Elm St.", "123-456-7890", "smith@university.com", "Computer Science", 75000);

    Student student1("Talha Mirza", "S001", "456 Oak St.", "987-654-3210", "talha@university.com", 3.8, 2020);
    Student student2("Izaan Avasti", "S002", "789 Pine St.", "987-321-6540", "izaan@university.com", 3.5, 2021);

    student1.enrollCourse("CS101");
    student1.enrollCourse("CS102");

    student2.enrollCourse("CS103");

    Course course1("CS101", "Intro to Computer Science", 3, &prof, "Mon-Wed 9:00-11:00");

    course1.registerStudent(student1);
    course1.registerStudent(student2);

    cout << "\nProfessor Info:\n";
    prof.displayInfo();

    cout << "\nStudent 1 Info:\n";
    student1.displayInfo();

    cout << "\nStudent 2 Info:\n";
    student2.displayInfo();

    cout << "\nCourse Info (CS101):\n";
    course1.displayCourseInfo();

    return 0;
}
