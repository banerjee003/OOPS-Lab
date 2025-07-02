#include<iostream>
#include<cstring>
using namespace std;

class PatientNotFoundException {
public:
    const char* what() {
        return "Patient not found.";
    }
};

class InvalidPatientIDException {
public:
    const char* what() {
        return "Invalid patient ID.";
    }
};

class MaxCapacityReachedException {
public:
    const char* what() {
        return "Maximum patient capacity reached.";
    }
};

class Patient{
protected:
    char name[30];
    int age;
    int patientID;
    static int patientCount;
public:
    Patient(char *name,int age,int patientID){
        strcpy(this->name,name);
        this->age=age;
        this->patientID=patientID;
        patientCount++;        
    }

    virtual void showStatus()const=0;

    int getPatientID();

    static int getPatientCount(){
        return patientCount;
    }

    virtual ~Patient(){
        patientCount--;
    }
};

int Patient::patientCount = 0;

inline int Patient::getPatientID(){
    return patientID;
}

class InPatient:public Patient{
    int wardNumber;
    int daysAdmitted;
public:
    InPatient(char* n, int a, int p, int w, int d):Patient(n,a,p){
        wardNumber=w;
        daysAdmitted=d;
    }

    void showStatus()const override{
        cout<<"In Patient status"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Patient ID: "<<patientID<<endl;
        cout<<"Ward Number: "<<wardNumber<<endl;
        cout<<"No of Days Admitted: "<<daysAdmitted<<endl;
    }
};

class OutPatient:public Patient{
    char  nextAppointmentDate[15];
public:
    OutPatient(char* n, int a, int p, char* nxt):Patient(n,a,p){
        strcpy(nextAppointmentDate,nxt);  
    }

    void showStatus()const override{
        cout<<"Out Patient status"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Patient ID: "<<patientID<<endl;
        cout<<"Next Appointment Date: "<<nextAppointmentDate<<endl;
    }
};

class ICUPatient:public Patient{
    bool onVentilator;
    int oxygenLevel;
public:
    ICUPatient(char* n, int a, int p, bool v, int o):Patient(n,a,p){
        onVentilator=v;
        oxygenLevel=o;
    }

    void showStatus()const override{
        cout<<"ICU Patient status"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Patient ID: "<<patientID<<endl;
        cout<<"On Ventilator: "<<(onVentilator?"Yes":"No")<<endl;
        cout<<"Oxygen Level: "<<oxygenLevel<<endl;
    }
};

class HospitalSystem{
public:
    Patient *patients[100];
    int currentCount=0;

    void admitPatient(char *n, int a, int i, int w, int d){
        if(currentCount >= 100)
            throw MaxCapacityReachedException();
        patients[currentCount++]=new InPatient(n,a,i,w,d);
    }

    void admitPatient(char *n, int a, int i, char *nxt){
        if(currentCount >= 100)
            throw MaxCapacityReachedException();
        patients[currentCount++]=new OutPatient(n,a,i,nxt);
    }

    void admitPatient(char *n, int a, int i, bool v, int o){
        if(currentCount >= 100)
            throw MaxCapacityReachedException();
        patients[currentCount++]=new ICUPatient(n,a,i,v,o);
    }

    void dischargePatient(int id){
        if (id <= 0)
            throw InvalidPatientIDException();

        bool found = false;
        for(int i=0; i<currentCount; i++){
            if(id == patients[i]->getPatientID()){
                delete patients[i];
                for(int j=i; j<currentCount-1; j++){
                    patients[j] = patients[j+1];
                }
                patients[currentCount-1] = nullptr;
                currentCount--;
                found = true;
                break;
            }
        }
        if(!found)
            throw PatientNotFoundException();
    }

    void displayPatient(int id){
        if(id <= 0)
            throw InvalidPatientIDException();

        for(int i=0; i<currentCount; i++){
            if(patients[i]->getPatientID() == id){
                patients[i]->showStatus();
                return;
            }
        }
        throw PatientNotFoundException();
    }

    void displayAll(){
        for(int i=0; i<currentCount; i++){
            patients[i]->showStatus();
            cout<<"--------------------------"<<endl;
        }
    }

    void countPatients(){
        cout<<"Total no of patients present here is: "<<Patient::getPatientCount()<<endl;
    }
};

int main(){
    HospitalSystem h;
    int n;
    cout<<"Enter the no of patients to be admitted: ";
    cin>>n;

    for(int i=0; i<n; i++){
        char name[30];
        int age, id;

        cout << "\nEnter patient name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter patient ID: ";
        cin >> id;

        int type;
        cout<<"Enter type (1: InPatient, 2: OutPatient, 3: ICUPatient): ";
        cin>>type;

        try {
            switch (type)
            {
                case 1: {
                    int ward, days;
                    cout << "Enter ward number: ";
                    cin >> ward;
                    cout << "Enter number of days admitted: ";
                    cin >> days;
                    h.admitPatient(name, age, id, ward, days);
                    break;
                }
                case 2: {
                    char date[15];
                    cout << "Enter next appointment date: ";
                    cin >> date;
                    h.admitPatient(name, age, id, date);
                    break;
                }
                case 3: {
                    bool vent;
                    int oxygen;
                    cout<<"On ventilator? (1 for yes, 0 for no): ";
                    cin>>vent;
                    cout<<"Oxygen Level: ";
                    cin>>oxygen;
                    h.admitPatient(name, age, id, vent, oxygen);
                    break;
                }
                default:
                    cout<<"Invalid patient type.\n";
            }
        }
        catch(MaxCapacityReachedException &e){
            cout << e.what() << endl;
        }
    }

    cout << "\nDisplaying all patients:\n";
    h.displayAll();
    h.countPatients();

    int x;
    cout<<"Enter the id to discharge: ";
    cin>>x;
    h.dischargePatient(x);

    h.displayAll();
    h.countPatients();

    cout << "\n--- Trying to display patient with ID -1 ---\n";
    try {
        h.displayPatient(-1);
    } catch(InvalidPatientIDException &e) {
        cout << e.what() << endl;
    } catch(PatientNotFoundException &e) {
        cout << e.what() << endl;
    }

    cout << "\n--- Trying to discharge patient with ID 9999 ---\n";
    try {
        h.dischargePatient(9999);
    } catch(PatientNotFoundException &e) {
        cout << e.what() << endl;
    } catch(InvalidPatientIDException &e) {
        cout << e.what() << endl;
    }

    return 0;
}
