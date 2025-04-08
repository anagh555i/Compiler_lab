
class
    Rectangle{
        int length;
        int breadth;
        methods:
        int area() {
            begin
                return this->length * this->breadth;
            end
        }
        int set_dimensions() {
            decl 
                int x;
            enddecl
            begin
                write("Enter length ");
                read(x);
                this->length=x;
                write("Enter breadth");
                read(x);
                this->breadth=x;
                return 0;
            end
        }
    }
    Square extends Rectangle{
        methods:
        int set_dimensions() {
            decl 
            int x;
            enddecl
            begin
                write("Enter side sq");
                read(x);
                this->length=x;
                this->breadth = this->length;
                return 0;
            end
        }
    }
endclass

decl
    Rectangle* obj;
enddecl

void main() {
    decl
        int x;
    enddecl
    begin
        write("Enter");
        write("1.Rectangle");
        write("2.Square");
        read(x);
    if(x==1) {
        obj = new(Rectangle);
    }
    else{
        obj = new(Square);
    }
    x = obj->set_dimensions();
    write(obj->area());
    return ;
    end
}