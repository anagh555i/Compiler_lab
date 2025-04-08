
class
    A{
    methods:
    int f0() {
        begin
            write("In class A f0");
            return 1;
        end
    }
    int f1() {
        begin
            write("In class A f1");
            return 1;
        end
        }
    }
    B extends A{
        methods:
        int f0() {
            begin
                write("In class B f0");
                return 1;
            end
        }
        int f2() {
            begin
                write("In class B f2");
                return 1;
            end
        }
    }
    C extends B{
        methods:
        int f0() {
            begin
                write("In class C f0");
                return 1;
            end
        }
        int f2() {
            begin
                write("In class C f2");
                return 1;
            end
        }
        int f4() {
            begin
                write("In class C f4");
                return 1;
            end
        }
    }
endclass

decl
    A* obj ;
    A* test_obj;
enddecl

void main() {
    decl
        int temp,n;
    enddecl
    begin
        read(n);
        if(n < 0){
            obj = new(A);
        }
        else{
            if(n == 0){
                obj = new(B);
            }
            else{
                obj = new(C);
            }
        }
        test_obj = obj;
        write(test_obj->f0());
        return ;
    end
}
