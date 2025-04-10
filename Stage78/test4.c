
class
    Person{
        string name;
        int age;
        methods:
        int printDetails(){
            begin
                write(this->name);
                write(this->age);
            return 1;
            end
        }
        string findName(){
            begin
                return this->name;
            end
        }
        int createPerson(string name, int age){
            begin
                this->name=name;
                this->age=age;
                return 1;
            end
        }
    }
    Student extends Person{
        int rollnumber;
        string dept;
        methods:
        int createStudent(string name, int age,int rollNo, string dept){
            begin
                this->name =name;
                this->age = age;
                this->rollnumber = rollNo;
                this->dept = dept;
                return 1;
            end
        }
        int printDetails(){
            begin
                write(this->name);
                write(this->age);
                write(this->rollnumber);
                write(this->dept);
                return 1;
            end
        }
        int printDetails(int a){
            begin
                write(this->name);
                write(this->age);
                write(this->rollnumber);
                write(this->dept);
                write(a);
                return 1;
            end
        }
    }
endclass

decl
    int n,temp;
    string name;
    Person* first;
    Student* second;
    Person* arbitrary;
enddecl

void main(){
    begin
    first=new(Person);
    temp = first->createPerson("Rogers", 37);
    second=new(Student);
    temp = second->createStudent("Mathew", 35, 999, "CS");
    read(n);
    if (n>0) {
        arbitrary = first;
    }
    else{
        arbitrary = second;
    }
    n = arbitrary->printDetails();
    return ;
    end
}