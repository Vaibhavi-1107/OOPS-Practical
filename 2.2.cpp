/*A university managing academic data for its students. The administration seeks to digitize the records
of student performance, including personal and academic details. The system must store each
student's roll number, name, and marks in three subjects. Additionally, it should provide
functionalities to calculate and display the average marks for performance analysis.
The institution's IT team proposed a solution where student records could be initialized in two ways:
either with default values for testing purposes or by accepting specific input details for each student.
Once initialized, the system would allow for viewing comprehensive student details, including their
roll number, name, marks, and calculated average. This functionality was designed to help faculty and
administrators track individual student performance efficiently.
To simulate real-world usage, the team decided to create multiple student records. They planned to
populate the system with a mix of students initialized using both default and specific values. The
system's ability to accurately calculate averages and display detailed student information was to be
tested with this data.*/
#include<iostream>
using namespace std;
class Student
{
    private:
        int rollno;
        string name;
        int marks[3];
    public:
        //default constructor
        Student() {
            rollno=0;
            name="Unknown";
            marks[0]=marks[1]=marks[2]=0;
        }
        //Parameterized constructor
        Student(int roll,string n,int m[]) {
            rollno=roll;
            name=n;
            for(int i=0;i<3;i++)
            {
                marks[i]=m[i];
            }
        }
    //Function to calculate average marks
    double calculateAvg() {
        return(marks[0]+marks[1]+marks[2])/3.0;
    }
    //Function to display the student details
    void display(){
            cout<<"Roll number:"<<rollno<<"\n";
            cout<<"Name :"<<name<<"\n";
            cout<<"Marks:"<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<"\n";
            cout<<"Average marks:"<<calculateAvg()<<"\n";
    }
};
int main()
{
    Student students[3];
    for(int i=0;i<3;i++)
    {
        int roll;
        string name;
        int m[3];

        cout<<"Enter details for student\n"<<i+1;
        cout<<"Enter roll no: ";
        cin>>roll;
        cout<<"Enter name:";
        cin>>name;
        cout<<"Enter marks for 3 subjects:"<<endl;
        for(int j=0;j<3;j++)
        {
            cout<<"Enter marks"<<j+1<<" ";
            cin>>m[j];
        }
    students[i]=Student(roll,name,m);

    }
    for(int i=0;i<3;i++)
    {
        cout<<"\nStudent"<<i+1<<"Marks"<<endl;
        students[i].display();
    }
    cout<<"Vaibhavi 24CE053";
    return 0;
}

