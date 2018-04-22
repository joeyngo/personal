Q1 identical 
//////////////////////////////////////////////////////////////////////////////////

int identical(BTNode *tree1, BTNode *tree2)

{
    /* If both trees empty, return 1 */

    /* If both not empty
        Check data of root nodes
        Recursively check left and right nodes until NULL
    */

    if (tree1 == NULL && tree2 == NULL){
        return 1;
    }

    if (tree1 != NULL && tree2!=NULL) {
        return
        (
            tree1->item == tree2->item &&
            identical(tree1->left, tree2->left) &&
            identical(tree1->right, tree2->right)
        );
    }
    
    return 0 ; 




}

/////////////////////////////////////////////////////////////////////////////////

Q2 maxHeight
//////////////////////////////////////////////////////////////////////////////////

int maxHeight(BTNode *node)

{
    int left_height , right_height ; 
    BTNode *cur ; 
    if (node == NULL) {
        return -1
    }

    cur = node; 

    if(cur == NULL) {
        return 0 ; 
    }

    else {
        left_height = maxHeight(cur->left) ;
        right_height = maxHeight(cur->right) ;
        
        if (left_height > right_height) 
            return left_height + 1 ; 
        else
            return right_height + 1 ;
    }
}

///////////////////////////////////////////////////////////////////////////////////

Q3 countOneChildNodes 

//////////////////////////////////////////////////////////////////////////////////

int countOneChildNodes(BTNode *node)

{
    /* visit
       left
       right */

    int sum=0 ;

    if(node == NULL)
        return 0 ;
    if(ifChildNode(node))
        sum += 1;

    sum += countOneChildNodes(node->left);
    sum += countOneChildNodes(node->right);

    return sum ;

}

int ifChildNode (BTNode *node) {
    if (node->left == NULL && node->right != NULL) {
        return 1;
    }
    if (node->right == NULL && node->left != NULL) {
        return 1;
    }
    else {
        return 0 ;
    }
}
///////////////////////////////////////////////////////////////////////////////////

Q4 sumOfOddNodes 

//////////////////////////////////////////////////////////////////////////////////

int sumOfOddNodes(BTNode *node)

{
    int sum = 0 ; 
    
    if (node == NULL) return; 
    
    if (odd(node->item)) {
        sum += node->item ; 
    }
    
    sum += sumOfOddNodes(node->left);
    sum += sumOfOddNodes(node->right);
    
    return sum; 
    
}


int odd(int num) { 
    if (num % 2 != 0) 
        return 1 ; 
    else 
        return 0 ; 
}

//////////////////////////////////////////////////////////////////////////////////

Q5 mirrorTree 

//////////////////////////////////////////////////////////////////////////////////

void mirrorTree(BTNode *node)
{
    BTNode *temp ; 

    if ( node == NULL) {
        return ; 
    }

    mirrorTree(node->left); 
    temp = node->left ; 
    node->left = node->right ; 
    node->right = temp ; 
    mirrorTree(node->left); 

}

//////////////////////////////////////////////////////////////////////////////////

Q6 printSmallerValues

//////////////////////////////////////////////////////////////////////////////////

void printSmallerValues(BTNode *node, int m)
{
    if (node == NULL) return ; 
    BTNode *cur ; 

    cur = node ; 

    if (smaller(cur->item , m)) {
        printf("%d ",cur->item);
    }    

    printSmallerValues(cur->left) ;
    printSmallerValues(cur->right) ; 
}

int smaller(num , m)
{
    if (num < m) 
        return 1; 
    else 
        return 0; 
}
//////////////////////////////////////////////////////////////////////////////////

Q7 smallestValue

//////////////////////////////////////////////////////////////////////////////////

int smallestValue(BTNode *node);
{
    BTNode *cur ; 

    int min = 32767 ; 

    if (node == NULL) 
        return -1; 

    else if (node->item < min) {
        min = node->item ; 
        return min ;
    }

    int left = smallestValue(node->left) ;
    int right = smallestValue(node->right) ;

    if (left < right) {
        return left; 
    }
    else 
        return right;
}