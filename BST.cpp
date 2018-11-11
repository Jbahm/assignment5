
BST::BST()
{
  root = NULL;

}

BST::~BST()
{

}

void BST::printTree()
{
  recPrint(root);
}

bool BST::isEmpty()
{
  return root == NULL;
}

void BST::recPrint(TreeNode *node)
{
  if(node == NULL){
    return;
  }

  recPrint(node->left);
  cout << node->data << endl;
  recPrint(node->right);
}

void BST::insert(int value)
{
  //check for duplicates
  TreeNode *node = new TreeNode(value);

  if(isEmpty()){
    root = node;
  }else{//not an empty tree, find insertion point
    TreeNode *current = root;
    TreeNode *parent; //empty TreeNode
    while(true){
      parent = current;
      if(value < current->key){//go left
        current = current->left;

        if(current == NULL)//we found the insertion point
        {
          parent->left = node;
          break;
        }
      }
      else
      {

      }
    }
  }

}

//search method
bool BST::contains(int value)
{
  if(isEmpty()){
    return false;
  }else{//not an empty tree, continue to search
    TreeNode *current = root;
    while(current->key != value){
      if(current == NULL){
        return false;
      }
      if(value < current->key){
        current = current->left;
      }else{
          current = current->right;
        }
      }
      return true;
    }
  }

bool BST::deleteRec(int k)
{
  //use contains method

  if(!contains(k)){
    return false;
  }
  //lets proceed to find the TreeNode
  TreeNode *current = root;
  TreeNode *parent = root;
  bool isLeft = true;

  while(current->key != k){
    parent = current;

    if(k < current->key){//go left
      isLeft = true;
      current = current->left;
    }else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL){
      return false;
    }
    //at this point we found the node to be deleted

    //lets check wether it is a leaf or not

    if(current->left == NULL && current->right == NULL){//then its a leaf
        if(current == root){
          root = NULL;
        }else if(isLeft){
          parent->left = NULL;
        }else{
          parent->right = NULL;
        }
    }else if(current->right = NULL){//no right child, must be isLeft
        if(current == root)
        {
          root = current->left;
        }else if(isLeft)
        {
          parent->left = current->left;
        }else{//right child
          parent->right = current->left;
        }
    }else if(current->left == NULL){//no left child, must be right
      if(current == root){
        root = current->right;
      }else if(isLeft){
        parent->left = current->right;
      }else{//right child
        parent->right = current->right;
      }

    }else{//it has two children, at this point we begin to cry and take a long nap
      TreeNode *successor = getSuccessor(current);

      if(current == root){
        root = successor;
      }else if(isLeft){
        parent->left = successor;
      }else{
        parent->right = successor;
      }
    }

  }
  return true;
}

TreeNode* BST::getSuccessor(TreeNode *d)
{
  TreeNode *sp = d;
  TreeNode *successor = d;
  TreeNode *current = d->right;


  while(current != NULL){
    sp = succesor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){//descendant of right child, left most of right
    sp->left = successor->right;
    successor->right = d->right;

  }

  return successor;
}
