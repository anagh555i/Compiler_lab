type
    node{
        int val;
        node* next;
    }
endtype
decl
    int i,j,n;
    int arr[10];
    int k;
    string s;
    pointer funct1(int a);
    void funct2(int b);
    int funct3(int c);
enddecl



pointer funct1(int a){
    decl
        int c;
        node * b;
    enddecl
    begin
        c=200;
        a=c;
        b=malloc(node);
        return b;
    end
}

int funct3(int c){
    decl
    enddecl
    begin
        c=999;
        return c;
    end
}

void main(){
    decl 
        node* n;
        void p;
    enddecl
    begin
        i=funct3(20);
        write(i);
        n=funct1(i);
        n->val=34;
        // n->next->val=45;
        write(n->val);
        //write(n->next->val);
        return ;
    end
}