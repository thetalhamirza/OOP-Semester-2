#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years;

    string toString() const {
        return to_string(id) + "," + name + "," + designation + "," + to_string(years);
    }
};

void writeData(string text) {
    ofstream out("dataCRUD.txt");
    if (out.is_open()) {
        out << text << endl;
        out.close();
    }
}

vector<Employee> readAll() {
    vector<Employee> employees;
    ifstream in("dataCRUD.txt");
    string line;
    while (getline(in, line)) {
        istringstream ss(line);                     // to iterate through words in the line (GPT's idea)
        string idStr, name, desig, yearsStr;
        if (getline(ss, idStr, ',') &&
            getline(ss, name, ',') &&
            getline(ss, desig, ',') &&
            getline(ss, yearsStr)) {
            Employee emp = { stoi(idStr), name, desig, stoi(yearsStr) };
            employees.push_back(emp);
        }
    }
    return employees;
}

// (a) Find manager with >=2 years of service
vector<Employee> queryManagersWithExperience(const vector<Employee>& all) {
    vector<Employee> result;
    for (const auto& e : all) {
        if (e.designation == "manager" && e.years >= 2) {
            result.push_back(e);
        }
    }
    return result;
}

// (b) Overwrite file with matched data
void overwriteWithMatched(const vector<Employee>& data) {
    ofstream out("dataCRUD.txt");
    for (const auto& e : data) {
        out << e.toString() << endl;
    }
    out.close();
}

// (c) Write the same data with incremented IDs and years
void writeIncremented(const vector<Employee>& data) {
    ofstream out("dataCRUD.txt", ios::app); // Append to existing file
    for (const auto& e : data) {
        Employee updated = e;
        updated.id += 100;    // increment ID
        updated.years += 1;   // increment years of service
        out << updated.toString() << "\n";
    }
    out.close();
}

// print employees
void print(const vector<Employee>& v) {
    for (const auto& e : v) {
        cout << e.toString() << endl;
    }
}

int main() {

    writeData("1,Ali,developer,1");
    writeData("2,Ayesha,manager,3");
    writeData("3,John,designer,4");
    writeData("4,Sara,manager,1");
    writeData("5,Bilal,manager,5");

    vector<Employee> all = readAll();
    cout << "Original data:\n";
    print(all);

    vector<Employee> filtered = queryManagersWithExperience(all);
    cout << "\n(a) Managers with ≥2 years:\n";
    print(filtered);

    overwriteWithMatched(filtered);
    cout << "\n(b) File after deletion of others.\n";

    writeIncremented(filtered);
    cout << "\n(c) File after adding incremented versions.\n";

    // final state
    vector<Employee> final = readAll();
    cout << "\nFinal file content:\n";
    print(final);

    return 0;
}
