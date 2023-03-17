#include "File.h"

#include <iomanip>
using namespace std;

//DO NOT MODIFY START
File::~File() = default;

Entry* File::clone() const
{
    return new File(*this);
}
//DO NOT MODIFY END

//Implement constructor, member functions in File class
//write your code here

File::File(const string& name, const string& content){
	name_ = name;
	text_ = content;
}

File::File(const File& o){
	name_ = o.name();
	text_ = o.content();
}


string File::content() const{
	return text_;
}

string File::content(const string& text){
	text_ = text_ + text;
	return text_;
}

const string& File::name()const{
	return name_;
}

void File::print(ostream& os, size_t indent)const{
	indent+=1;
	string blank = " ";
	for(; indent>0; --indent) os << blank;
	os<<"*";
	os<<name_<<endl;

}
