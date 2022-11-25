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

File::File(const string& name, string& content){
	name_ = name;
	text_ = content;
}

File::File(const File& o){
	name_ = o.name();
	text_ = o.content();
}


