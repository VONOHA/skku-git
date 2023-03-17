#include "Directory.h"

#include <iomanip>
#include <sstream>
using namespace std;

//DO NOT MODIFY THIS START
Entry* Directory::clone() const
{
    return new Directory(*this);
}
//DO NOT MODIFY THIS END

//Implement constructor, destructor, member functions of the Directory class.
Directory::Directory(const string& name){
	name_ = name;
	count_ = 0;
	for(int i = 0; i<maxcount_; ++i) entries_[i] = 0;
}

Directory::Directory(const Directory& o){
	Directory dummy_directory("");
	dummy_directory = o;
	count_ = o.count(), name_ = o.name();
	Entry *e = 0;
	string str = o.content(), dummy;
	stringstream list_stream(str);
	for(int i = 0; i<count_; ++i){
		list_stream>>dummy;
		e = dummy_directory.find(dummy);
		if(e)entries_[i] = e->clone();
	}
}

Directory::~Directory(){
	for(int i = 0; i<maxcount_; ++i) delete entries_[i];
}

const string& Directory::name()const{
	return name_;
}

void Directory::print(ostream& os, size_t indent) const{
	if(indent)indent+=2;
	for(int i = 0 ; i < indent; ++i) cout<<" ";
	os<<"*"<<name_<<endl;
	for(int i = 0; i< count_; ++i){
		entries_[i]->print(os,indent+1);
	}
}

Entry* Directory::remove(const string& name){
	string str;
	for(int i = 0; i < count_; ++i){ 
		str = entries_[i]->name();
		if(str== name) {
			count_--;
			break;
		}
	
	}
	return 0;
}

bool Directory::add(Entry* entry){

	if(find(entry->name())) return false;
	else entries_[count_++] = entry;
	return true;

}

size_t Directory::count() const{
	return count_;
}

Entry* Directory::find(const string& name){
	Entry* dummy;
	for(int i = 0; i<count_; ++i){
		dummy = entries_[i];
		if(dummy->name() == name) return dummy;
	}
	return 0;

}

string Directory::content()const{
	string result = "", blank = " ", dummy;
	for(int i = 0; i<count_; ++i){
		dummy = entries_[i]->name();
		if(i)result+=blank;
		result+=dummy;
	}
	return result;
}
