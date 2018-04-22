
Q1 createQueueFromLinkedList 
//////////////////////////////////////////////////////////////////////////////////
void createQueueFromLinkedList(LinkedList *ll, Queue *q)
{
	int size = ll->size ;
	int i ;
	ListNode *cur ;

	if (!isEmptyQueue) {
        removeAllItemsFromQueue(q) ;
	}

	cur = ll->head ;
	for(i=0 ; i<size ; i++) {
        enqueue(q, cur->item);
        cur = cur->next;
	}
}

void removeOddValues(Queue *q)
{
	int size = q->ll.size ;
	int i ;
	ListNode *cur ;
	cur = q->ll.head ;
	for(i=0; i<size ; i++) {
        if ( (cur->item)%2 == 1 ) {
            dequeue(q) ;
        }
        else {
            enqueue(q , cur->item );
            dequeue(q);
        }
        cur = cur->next ; // <- forgot this!
	}
}

//////////////////////////////////////////////////////////////////////////////////

Q2 createStackFromLinkedList 

//////////////////////////////////////////////////////////////////////////////////

void createStackFromLinkedList(LinkedList *ll, Stack *s)
{
    ListNode *cur ;
    cur = ll->head ;
    int i ;
    int ll_size = ll->size ;

    if (!isEmptyStack(s))
        removeAllItemsFromStack(s);

    for (i=0 ; i<ll_size; i++) {
        push(s, cur->item) ;
        cur = cur->next ;
    }

}

void removeEvenValues(Stack *s)
{
	int stack_size = s->ll.size ;
	int i ; int index=0 ;
	ListNode *cur = s->ll.head ;
	int pushValues[20] ;
	int odd_count = 0 ;

	for (i=0 ; i<stack_size ; i++) {
        if ( (cur->item)%2 == 0 ) { // if even
            cur = cur->next ;
            pop(s);
        }
        else if ( (cur->item)%2 == 1){ // if odd
            cur = cur->next ;
            pushValues[index] = pop(s) ;
            index++;
            odd_count++ ;
        }
	}

	/* Pushing the values back to stack */
	for (i=0 ; i<odd_count ; i++) {
        push(s,pushValues[i]);
	}
}

//////////////////////////////////////////////////////////////////////////////////

Q3 isStackPairwiseConsecutive 

/////////////////////////////////////////////////////////////////////////////////

int isStackPairwiseConsecutive(Stack *s)
{
    int stacksize = s->ll.size ;
    int first; int i ;
    int second ;

    if(stacksize % 2 == 1) return 0; // if stack is odd it cannot be pairwise

    for (i=0 ; i < (stacksize/2) ; i++) {
        first = pop(s);
        second = pop(s) ;
        if (first - second != 1)
            return 0;
    }
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////

Q4 reverseQueue 

///////////////////////////////////////////////////////////////////////////////////////////////////

void reverse(Queue *q)
{
    Stack s ; // we cannot use Stack *s , because what we want is not a pointer
    /* REMEMBER TO INITIALIZE STACK */
    s.ll.head = NULL;
    s.ll.size = 0;
    s.ll.tail = NULL;
    /* REMEMBER TO INITIALIZE STACK */
    /* THIS ALSO APPLIES TO QUEUE AND LINKED LIST, USUALLY IT IS MADE IN MAIN() BUT
    WE ARE USING OUR OWN DEFINED STACK SO WE NEED TO INITIALIZE IT*/

    int queue_size = q->ll.size ;
    int i ;

    for (i=0 ; i<queue_size ; i++) {
        push(&s,dequeue(q)) ; // <- notice &s
    }

    for (i=0 ; i<queue_size; i++) {
        enqueue(q,pop(&s)); // <- notice &s
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

Q5 recursiveReverseQueue

////////////////////////////////////////////////////////////

void recursiveReverse(Queue *q)
{
    int i ;

    /*terminating condition*/
    if(isEmptyQueue(q)) return ;

    i = dequeue(q) ; // i value different for every recurrence
    recursiveReverse(q);
    enqueue(q,i) ;



}

//////////////////////////////////////////////////////////////////

Q6 removeUntil

////////////////////////////////////////////////////////////

void removeUntil(Stack *s, int value)
{
    /* Take note you can also use peek(s) */
    int check ;
    while (!isEmptyStack(s)) {
        check = pop(s) ;
        if (check == value) {
            push(s,value);
            return ;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////

Q7 balanced 

////////////////////////////////////////////////////////////
int balanced(char *expression)
{
    /* First we initialize our own stack */

    Stack s ;

    s.ll.head == NULL ;
    s.ll.size = 0 ;

    printf("%s\n", expression) ; // as per question requirements

    while (*expression) {
        if (*expression == '{' || *expression == '(' || *expression == '[') {
            push(&s,*expression) ;
        }

        else if (*expression == '}') {
            if (pop(&s) != '{')
                return -1 ;
        }

        else if (*expression == ')') {
            if (pop(&s) != '(')
                return -1 ;
        }
        else if (*expression == ']') {
            if (pop(&s) != '[')
                return -1;
        }
        expression++; // <- take note of this! ( look at str[256] , thats why we ++ the address )
    }
    if (isEmptyStack(&s)){
        return 0;
    }
    else {
        return -1; // <- take note
    }

}

////////////////////////////////////////////////////////////