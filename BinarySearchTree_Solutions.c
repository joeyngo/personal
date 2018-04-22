Q1 levelOrderTraversal (iterative) 
//////////////////////////////////////////////////////////////////////////////////

void levelOrderTraversal(BSTNode* root)
{

    BSTNode *temp ; // something to dequeue into 
    Queue q ;
    q.head = NULL ;
    q.tail = NULL ;

    temp = root ;
    // if tree is not empty
    if ( temp != NULL ) {
        enqueue(&q.head,&q.tail,temp) ;

        while ( q.head != NULL ) { // while the queue is not empty
            temp = dequeue(&q.head, &q.tail) ;
            printf("%d ", temp->item) ;

            if(temp->left != NULL) {
                enqueue(&q.head, &q.tail, temp->left) ;
            }
            if (temp->right != NULL) {
                enqueue(&q.head,&q.tail,temp->right);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

Q2 Inorder traversal (iterative) 

/* Algorithm
1. Create an empty stack S 
2. Initialize current node as root 
3. While current != NULL push to stack (cur->left)
4. If current is NULL and stack !empty 
    a) Pop the item 
    b) Print
    c) Set current to popped_item->right
    d) Go to step 3 
5) If current is NULL and stack empty , done
*/
//////////////////////////////////////////////////////////////////////////////////

void inOrderTraversal(BSTNode *root)
{
    Stack s;
    BSTNode *cur;

    s.top = NULL;
    cur = root;

    if (cur == NULL)
        return;

    while (1) {

        if (cur!=NULL) {
            push(&s,cur);
            cur = cur->left;
        }

        else if (cur == NULL && !(isEmpty(&s))) {
                cur = pop(&s);
                printf("%d ", cur->item);
                cur = cur->right;
            }
        else {
            break ;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

preOrderTraversal(iterative) 

//////////////////////////////////////////////////////////////////////////////////

void preOrderIterative(BSTNode *root)
{
    Stack s ;
    s.top = NULL ;
    BSTNode *cur ;
    cur = root;

    if(cur==NULL) return ;

    push(&s,cur);

    while (!isEmpty(&s)) { 
        cur = pop(&s);
        printf("%d ",cur->item);

        if (cur->right != NULL)
            push(&s,cur->right); // right is pushed first so left will be pop first
        if (cur->left !=NULL)
            push(&s,cur->left);
    }
}


///////////////////////////////////////////////////////////////////////////////