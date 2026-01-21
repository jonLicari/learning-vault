#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LOG(x) cout << x << endl;

class Person {
public:
    Person() {};
    
protected:  
    int age, cur_id;
    string name;  
    vector<string> tokens; 
    
public:
    virtual void putdata() = 0; // output data
    virtual void getdata() = 0; // input data
};

class Professor : public Person {
    int publications;
   
public:
    Professor() : publications(0) {};
    
    void getdata() override {
        static int id = 0;    
        cur_id = ++id;
        
        // Read in and parse data
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
        string data;
        getline(cin, data);

        // break it down into vector of strings
        size_t start = 0, end = 0;
        for(;;) {
            // find index of delimiter
            string delimiter = " ";
            end = data.find(delimiter, start);
            auto substr = data.substr(start, end - start);
            tokens.push_back(substr);
            
            if (end == string::npos) break;
            
            start = end + delimiter.size();
        };
        
        // assign to data members
        name = tokens[0];
        age = stoi(tokens[1]);
        publications = stoi(tokens[2]); 
    };
    
    void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    };
};

class Student : public Person {
    int marks[6] = {0};
    
public:
    Student() {};
    
    void putdata() override {
        int sum = 0;
        for (auto mark : marks) sum += mark;
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    };
    
    void getdata() override {
        static int id = 0;
        cur_id = ++id;
        
        // Read in and parse data
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
        string data;
        getline(cin, data);
        
        // break it down into vector of strings
        size_t start = 0, end = 0;
        for(;;) {
            // find index of delimiter
            string delimiter = " ";
            end = data.find(delimiter, start);
            auto substr = data.substr(start, end - start);
            tokens.push_back(substr);
            
            if (end == string::npos) break;
            
            start = end + delimiter.size();
        };
        
        // assign to data members
        name = tokens[0];
        age = stoi(tokens[1]);
        for (size_t i = 2; i < tokens.size(); ++i) {
            marks[i-2] = stoi(tokens[i]);     
        }
    };
    
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
