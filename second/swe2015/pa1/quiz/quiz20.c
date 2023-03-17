void addq(int i, element item){
	queuePointer temp,rear;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = NULL;
	for(rear = front[i]; *(rear)->link != NULL; rear = *(rear)->link);
	if(front[i]) rear[i]->link = temp;
	else front[i]= temp;
}
