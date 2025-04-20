#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Doctor;
class BillingStaff;

class PatientRecord {
private:
    string name;
    string id;
    string dateOfBirth;
    vector<string> medicalHistory;
    vector<string> currentTreatments;
    map<string, double> billingDetails;

    void addMedicalEntry(const string& entry) {
        medicalHistory.push_back(entry);
    }

    void addTreatment(const string& treatment) {
        currentTreatments.push_back(treatment);
    }

    void addBillingEntry(const string& service, double amount) {
        billingDetails[service] = amount;
    }

public:
    PatientRecord(const string& name, const string& id, const string& dob)
        : name(name), id(id), dateOfBirth(dob) {}

    struct PublicData {
        string name;
        string id;
        string dob;
    };

    PublicData getPublicData() const {
        return {name, id, dateOfBirth};
    }

    struct MedicalData {
        vector<string> history;
        vector<string> treatments;
    };

    friend class Doctor;
    friend class BillingStaff;
};

class Doctor {
public:
    void updateMedicalHistory(PatientRecord& record, const string& entry) {
        record.addMedicalEntry(entry);
        cout << "Doctor added medical history entry.\n";
    }

    void prescribeTreatment(PatientRecord& record, const string& treatment) {
        record.addTreatment(treatment);
        cout << "Doctor prescribed new treatment.\n";
    }

    PatientRecord::MedicalData viewMedicalData(const PatientRecord& record) {
        return {record.medicalHistory, record.currentTreatments};
    }
};

class BillingStaff {
public:
    void addBillingDetail(PatientRecord& record, const string& service, double amount) {
        record.addBillingEntry(service, amount);
        cout << "Billing staff added charge for " << service << " ($" << amount << ").\n";
    }

    double calculateTotal(const PatientRecord& record) {
        double total = 0;
        for (const auto& entry : record.billingDetails) {
            total += entry.second;
        }
        return total;
    }
};

class Receptionist {
public:
    void viewPatientInfo(const PatientRecord& record) {
        auto publicData = record.getPublicData();
        cout << "Receptionist viewing patient data:\n"
             << "Name: " << publicData.name << "\n"
             << "ID: " << publicData.id << "\n"
             << "DOB: " << publicData.dob << "\n";
    }

    //attempt to access medical data (should fail)
    void tryAccessMedicalData(const PatientRecord& record) {
        cout << "Receptionist attempting to access medical data...\n";
        //this won't compiley
        // cout << "Medical history: " << record.medicalHistory.size() << " entries\n";
        cout << "Access denied - receptionist not authorized for medical data.\n";
    }
};

int main() {
    PatientRecord patient("Bob the builder", "P10023", "1985-07-15");

    Doctor drSmith;
    drSmith.updateMedicalHistory(patient, "Initial consultation");
    drSmith.prescribeTreatment(patient, "Ibuprofen 400mg");

    BillingStaff billing;
    billing.addBillingDetail(patient, "Consultation", 150.00);
    billing.addBillingDetail(patient, "Medication", 25.50);

    Receptionist reception;
    reception.viewPatientInfo(patient);
    reception.tryAccessMedicalData(patient);

    cout << "\nTotal charges: $" << billing.calculateTotal(patient) << "\n";

    //attempted unauthorized access
    //patient.medicalHistory.push_back("Unauthorized entry");
    //cout << patient.currentTreatments[0];

    return 0;
}
