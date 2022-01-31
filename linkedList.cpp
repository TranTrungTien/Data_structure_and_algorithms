#include <iostream>
#include <string>

class People
{
protected:
    std::string fullName;
    int age;
public:
    People(){ this->fullName = nullptr; this->age = 0;}
    ~People();
    void inputInfo();
    void display();
};


class Students:public People
{
private:
    std::string major;
    Subject subject;
public:
    Students() { major = nullptr; };
    ~Students();
};

class Subject
{
private:
    std::string subjectName;
    int scores;
public:
    Subject() {subjectName = nullptr; scores = 0;};
    ~Subject();
};



class Node
{
private:
    Students data; 
public:
    Node(/* args */);
    ~Node();
};


int main()
{
    return 0;
}

People::inputInfo()
{
    
}