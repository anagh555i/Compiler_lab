type
    node{
        int val;
        node* next;
    }
endtype

class 
    anode{
        int aval;
        cnode* next;
        methods:
        void print1(){
            decl 
                int a;
            enddecl
            begin
                this->aval=1;
                write("print1");
                return ;
            end
        }
        void print2(){
            decl 
                int a;
            enddecl
            begin
                this->aval=2;
                write("print2");
                return ;
            end
        }
        void print3(){
            decl 
                int a;
            enddecl
            begin
                this->aval=3;
                write("print3");
                return ;
            end
        }
    }
    bnode{
        int bval;
        cnode* next;
        methods:
        void print1(){
            decl 
                int a;
            enddecl
            begin
                this->bval=1;
                write("print1");
                return ;
            end
        }
        void print2(){
            decl 
                int a;
            enddecl
            begin
                this->bval=2;
                write("print2");
                return ;
            end
        }
        void print3(){
            decl 
                int a;
            enddecl
            begin
                this->bval=3;
                write("print3");
                return ;
            end
        }
    }
    cnode{
        int cval;
        cnode* next;
        methods:
    }
endclass

decl
    int i,j,n;
    int arr[10];
    int k;
    string s;
    int funct1(int a);
    anode* funct3(int c);
enddecl

int funct1(int a){
    decl
        int c;
        node * b;
    enddecl
    begin
        c=200;
        a=c;
        b=malloc(node);
        return 1;
    end
}

anode* funct3(int c){
    decl 
    enddecl
    begin 
        return new(anode);
    end
}

void main(){
    decl 
        node n;
        int p;
        anode* a;
        bnode* b;
        cnode* c;
    enddecl
    begin
        i=funct1(20);
        a=funct3(0);
        b=new(bnode);
        b->print1();
        write(b->bval);
        b->print2();
        write(b->bval);
        a->print3();
        write(a->aval);
        return ;
    end
}