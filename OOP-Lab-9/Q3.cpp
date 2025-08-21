#include <iostream>
#include <vector>
using namespace std;

class Doctor;
class Billing;

class PatientRecord {
    string ID, name, dateOfBirth;
    vector<string> history;
    vector<string> currentTreatments;
    vector<string> billingDetails;
    
    void addHistoryRecord(string treatment) {
        history.push_back(treatment);
    }
    void addBillingRecord(string bill) {
        billingDetails.push_back(bill);
    }

    public:
    PatientRecord(string id, string n, string dob) : ID(id), name(n), dateOfBirth(dob) {}

    void getPublicData()    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
    }
    void getMedicalData() {
        cout << "Treatment History: " << endl;
        for (int i=0; i < history.size(); i++) {
            cout << history[i] << endl;
        }
        cout << "\nCurrent Treatments: " << endl;
        for (int i=0; i < currentTreatments.size(); i++) {
            cout << currentTreatments[i] << endl;
        }
    }
    friend class Doctor;
    friend class Billing;
};

class Doctor {
    public:
    void updateMedicalHistory(PatientRecord& patient, string treatment) {
        patient.addHistoryRecord(treatment);
        cout << "Medical history updated by doctor" << endl;
    }
    void viewMedicalData(PatientRecord& patient) {
        cout << "Doctor viewing medical data: " << endl;
        patient.getMedicalData();
    }

};

class Billing {
    public:
    Billing() {}

    void addBillingRecord(PatientRecord &patient, string bill) {
        patient.addBillingRecord(bill);
        cout << "Billing record added by Billing Staff." << endl;
    }

    void viewMedicalData(PatientRecord &patient) {
        cout << "Billing staff viewing medical data:" << endl;
        patient.getMedicalData();
    }

};

class Receptionist {
    public:
    void viewPatientData(PatientRecord& patient) {
        cout << "Receptionist viewing public data: " << endl;
        patient.getPublicData();
    }
    void viewMedicalData(PatientRecord& patient) {
        cout << "Receptionist attempting to view medical data" << endl;
        patient.getMedicalData();
    }
};

int main() {
    PatientRecord patient1("P12345", "John Doe", "01/01/1980");
    Doctor doctor;
    Billing billing;
    Receptionist receptionist;

    receptionist.viewPatientData(patient1);
    receptionist.viewMedicalData(patient1);

    doctor.updateMedicalHistory(patient1, "Surgery");
    doctor.viewMedicalData(patient1);

    billing.addBillingRecord(patient1, "$500");
    billing.viewMedicalData(patient1);
}