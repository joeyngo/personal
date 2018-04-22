Q1 insertSortedLL 

//////////////////////////////////////////////////////////////////////////////////
int insertSortedLL(LinkedList *ll, int item)
{
	ListNode *cur ;
	ListNode *pre ;
	int index=0 ;
	/* empty linked list */
	if ( ll->head == NULL )
        insertNode(ll, 0 , item) ;

    /* non-empty linked list */
    cur = ll->head ;

    while (cur->next != NULL) {
        if ( item < cur->item ) {
            insertNode(ll,index,item);
            return index;
            }

        if (item > cur->item) {
            cur = cur->next ;
            index++ ;
        }

        if (item == cur->item)
            return -1;
    }

    if (cur->next == NULL) {
        if (item < cur->item) {
            insertNode(ll, index, item) ;
            return index;
        }
        if (item > cur->item) {
            insertNode(ll, ll->size, item);
            return ll->size;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////

Q2 alternateMergedLinkedList 

///////////////////////////////////////////////////////////////////////////////////
void alternateMergeLinkedList(LinkedList *ll1, LinkedList *ll2)
{
	int i , j ;
	int ll1_size = ll1->size ; // <- IMPORTANT to ensure static value 
	int index = 1 ;

	for(i=0; i < ll1_size ; i++) {
		
		if (ll2->head != NULL) {
			insertNode(ll1, index, ll2->head->item);
			removeNode(ll2, 0);
			printf("%d ", index);
			index = index + 2 ;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////

Q3 moveOddItemsToBack 

//////////////////////////////////////////////////////////////////////////////////

void moveOddItemsToBack(LinkedList *ll)
{
	/* move all odd items to the back */
	/* We can either make use of tail, or given functions */
	/* In this case we make use of given functions as it helps us change head */ 
	ListNode *cur ;
	int index = 0 ;
    int size = ll->size ; // <- good practice to make size a static variable
    int item ;
    int i ;

	if (ll->head == NULL || size == 1) return;

	if (ll->head != NULL) cur = ll->head ;
    /* For fixed number of iterations we should try to use for instead of while */
    for (i=0 ; i<size ; i++){
        if ( odd (cur->item) ) {
            item = cur->item ;
            insertNode(ll , size , item) ;
            cur = cur->next ;
            removeNode(ll, index) ;
        }
        else {
            cur = cur->next ;
            index++ ;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

Q4 moveEvenItemsToBack

//////////////////////////////////////////////////////////////////////////////////

void moveEvenItemsToBack(LinkedList *ll)
{
	/* Same as moveOddItemsToBack , remember we use for instead of while
	since it is a fixed number of iterations */

	int index=0;
	ListNode *cur ;
	int i ,item ;
    int size = ll->size ;

	if (ll->head == NULL || size == 1) return ;

	if (ll->head != NULL) cur = ll->head ;

	for ( i=0 ; i<size ; i++ ) {
        if ( even ( cur->item ) ) {
            item = cur->item ;
            cur = cur->next ;
            insertNode(ll, size , item ) ;
            removeNode (ll , index) ;
            // notice that we didn't add index here because index still remains the same 
        }
        
        else {
            cur = cur->next ;
            index++ ; // <- index changed here 
        }
	}
}

///////////////////////////////////////////////////////////////////////////////////

Q5 frontBackSplitLinkedList

//////////////////////////////////////////////////////////////////////////////////
void frontBackSplitLinkedList(LinkedList *ll, LinkedList *resultFrontList, LinkedList *resultBackList)
{
	/* Front list will have one more item if its odd number of Nodes */

	int size = ll->size ;
	int sizefront , sizeback ;
	int i , j ;

	if ( size % 2 == 1 ) { // if size is odd
        sizefront = (size/2) + 1 ;
        sizeback = (size/2) ;
	}
	else {
        sizefront = size/2 ;
        sizeback = size/2 ;
	}

    for (i=0 ; i<sizefront ; i++) {
        insertNode(resultFrontList, i, findNode(ll,i)->item) ;
    }

    for (j=0; j<sizeback; j++) {
        insertNode(resultBackList, j, findNode(ll,j+sizefront)->item);
    }
}
//////////////////////////////////////////////////////////////////////////////////
Q6 moveMaxToFront 
////////////////////////////////////////////////////////////////////////

int moveMaxToFront(ListNode **ptrHead)
{
	/* **ptrHead is used so ll->size, insertNode, removeNode cannot be used
	Need to break and relink manually!!!! Take note :) */ 

    ListNode *cur ; ListNode *preMax ; // previous Node of the max
    ListNode *max ; ListNode *pre ;
    ListNode *prehead = (*ptrHead) ;

    /* If linked list is empty */
    if ((*ptrHead) == NULL) return -1;

    /* Only one Node in the list */
    if ((*ptrHead)->next == NULL)
        return 0 ;

    cur = (*ptrHead) ;
    max = (*ptrHead) ;

    /* In this case, we have to use while loop because we do not have access to
    linked list size as we are only given the ptr to head Node */
    cur = cur->next ; // we already made first Node the max

    while (cur != NULL) {
        if (cur->item > max->item) {
            max = cur ;
            preMax = pre ;
            pre = cur ;
            cur = cur->next ;
        }
        else {
            pre = cur ;
            cur = cur->next ;
        }

    if (preMax == NULL) {
        return 0 ; // this means that first node is the max
    }

    preMax->next = max->next ;

    (*ptrHead) = max ;
    (*ptrHead)->next = prehead ;


    return 0 ;
}

//////////////////////////////////////////////////////////////////////////////////