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
                write("a p 1");
                return ;
            end
        }
        void print2(){
            decl 
                int a;
            enddecl
            begin
                this->aval=2;
                write("a p 2");
                return ;
            end
        }
        void print3(){
            decl 
                int a;
            enddecl
            begin
                this->aval=3;
                write("a p 3");
                return ;
            end
        }
        void print4(){
            begin
                this->aval=4;
                write("a p 4");
                return ;
            end
        }
    }
    bnode extends anode{
        int bval;
        cnode* next;
        methods:
        void print1(){
            decl 
                int a;
            enddecl
            begin
                this->bval=1;
                write("b p 1");
                return ;
            end
        }
        void print2(){
            decl 
                int a;
            enddecl
            begin
                this->bval=2;
                write("b p 2");
                return ;
            end
        }
        void print3(){
            decl 
                int a;
            enddecl
            begin
                this->bval=3;
                write("b p 3");
                return ;
            end
        }
        void print4(){
            begin
                this->bval=4;
                write("b p 4");
                return ;
            end
        }
    }
    cnode extends anode{
        int cval;
        cnode* next;
        methods:
        void print5(int a){
            begin 
                this->cval=5;
                write("c p 5");
                return;
            end
        }
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
        a= new(anode);
        write("*****");
        a->print4();
        a->print2();
        a=new(bnode);
        a->print1();
        a->print2();
        a= new(cnode);
        a->print5(3);
        return ;
    end
}