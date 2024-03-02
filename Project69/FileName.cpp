#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
    string status; 
   
    Student(int i, string n, float g) : id(i), name(n), grade(g) {
        status = (grade >= 40.0) ? "Pass" : "Fail";
    }
};
class StudentManager {
private:
    vector<Student*> records; 
public:
   
    void addStudent(int id, string name, float grade) {
       
        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
    }
 void updateGrade(int id, float newGrade) {
       
        for (Student* student : records) {
            if (student->id == id) {
             
                student->grade = newGrade;
                student->status = (newGrade >= 40.0) ? "Pass" : "Fail";
                return;
            }
        }
        
        cout << "Student ID not found." << endl;
    }
 void displayRecords() {
        cout << "Student Records:" << endl;
        
        for (Student* student : records) {
            cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << ", Status: " << student->status << endl;
        }
    }
 void displayAverageGrade() {
        if (records.empty()) {
            cout << "No student records available." << endl;
            return;
        }
        float totalGrade = 0;
        for (Student* student : records) {
            totalGrade += student->grade;
        }
        float averageGrade = totalGrade / records.size();
        cout << "Average Grade of all students: " << averageGrade << endl;
    }
    ~StudentManager() {
        for (Student* student : records) {
            delete student;
        }
    }
};

int main() {
    
    StudentManager sm;
    sm.addStudent(1, "Emaan", 85.5);
    sm.addStudent(2, "Khadija", 90.0);
    sm.addStudent(3, "Ayesha", 38.5);
     sm.displayRecords();

    
    sm.updateGrade(2, 92.0);
cout << "**After grade update**" << endl;
    sm.displayRecords();
    sm.displayAverageGrade();

    return 0;
}
