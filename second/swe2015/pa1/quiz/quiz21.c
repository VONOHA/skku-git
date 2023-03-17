void erase(polyPointer* ptr){
	polyPointer temp;
	for(temp = *ptr; temp; *ptr = (*ptr)->link, temp = *ptr) free(temp);
}
