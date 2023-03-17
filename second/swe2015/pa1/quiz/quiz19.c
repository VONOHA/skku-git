void delete(listPointer *first, listPointer x){
	listPointer tmp,reserve;
	for(tmp = *(first)->link, reserve=NULL; tmp != x; reserve = tmp, tmp = tmp->link);
	if(reserve) reserve->link = x->link;
	else *frist = (*first)->link;
	free(x);
}
