type 
endtype
class
    A{
        int i;
        methods:
        int f1() {
            begin
            this->i=0;
            write("In A F1");
            return 1;
            end
        }
        int f0() {
            decl
                int c;
            enddecl
            begin
                c = this->f1();
                write(this->i);
                return 1;
            end
        }
    }
    B extends A{
        methods:
        int f1() {
        begin
            this->i=1;
            write("In B F1");
            return 1;
        end
        }
    }
endclass
decl
    int n;
    A* obj;
enddecl
void main() {
    decl
    enddecl
    begin
        read(n);
        if(n>0) {
            obj = new(A);
        }
        else{
            obj = new(B);
        }
        n = obj->f0();
        return ;
    end
}