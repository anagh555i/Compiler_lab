type
  bst{
    bst* right;
    bst* left;
    int a;
    int b;
    int c;
  }
endtype

decl
  int in,opt;
  bst* insert(bst* h, int key);
  int inOrder(bst* h); 
  int preOrder(bst* h);
  int postOrder(bst* h);           
enddecl

bst* insert(bst* h, int key)
{

  begin
    if (h == null){
        h = malloc(bst);
        h->a = key;
        h->left = null;
        h->right = null;
    }
    else {
        if (key < h->a) {
            h->left  = insert(h->left, key);
        }
        else {
            if (key > h->a) {
                h->right = insert(h->right, key);
            }
        }
    }   
    return h;
  end
}

int inOrder(bst* h){
     
  begin
    
  if(h!=null){
    in=inOrder(h->left);
    write(h->a);
    in=inOrder(h->right);
  }
  return 1;
  end
}

int preOrder(bst* h){
     
  begin
    
  if(h!=null){
    write(h->a);
    in=preOrder(h->left);
    in=preOrder(h->right);
  }
  return 1;
  end
}

int postOrder(bst* h){
     
  begin
  if(h!=null){
    in=postOrder(h->left);
    in=postOrder(h->right);
    write(h->a);
  }
  return 1;
  end
}

void main()
{ 
  decl
  int val,flag;
  bst *Root;
  enddecl

  begin
    Root = null;

    read(val);

    while(val!=0){
      Root = insert(Root,val);
      read(val);
    }
    write("Inorder:");
    in = inOrder(Root);
    write("preorder:");
    in = preOrder(Root);
    write("postorder:");
    in = postOrder(Root);
    return ;
  end
}
