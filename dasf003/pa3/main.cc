#include "Entry.h"
#include "Directory.h"
#include "File.h"

#include <sstream>

using namespace std;

// type definition of func => function pointer
typedef bool (*func)(Directory*&, string&, string&);

// unify function signature
// function name is instruction
bool cd(Directory*& root, string& target_path, string& dest_path);
bool mkdir(Directory*& root, string& target_path, string& dest_path);
bool touch(Directory*& root, string& target_path, string& dest_path);
bool echo(Directory*& root, string& target_path, string& content);
bool ls(Directory*& root, string& target_path, string& dest_path);
bool tree(Directory*& root, string& target_path, string& dest_path);
bool cat(Directory*& root, string& target_path, string& dest_path);
bool mv(Directory*& root, string& target_path, string& dest_path);
bool cp(Directory*& root, string& target_path, string& dest_path);
bool rmdir(Directory*& root, string& target_path, string& dest_path);
bool rm(Directory*& root, string& target_path, string& dest_path);

// these two array is for mapping instruction to function
string instruction[11] = {"cd","mkdir", "touch", "echo", "ls", "tree", "cat", "mv", "cp", "rmdir", "rm"};
func func_arr[11] = {cd,mkdir, touch, echo, ls, tree, cat, mv, cp, rmdir, rm};

//This function finds directory with the given name(2nd argument) from the given path(1st argument)
//For example below finds "world" directory from the root directory
//find_directory(&root, "world");
Entry* find_directory(Directory* root, const std::string& path)
{
    //Implement your code here.
    //Leverage find member function.
	string target;
	istringstream path_(path);
	Directory* result = root;
	Entry* position = root;

	// "position &&" is for when no such files
	// "&& getline()" is for end of input 
	while(position && getline(path_,target,'/')){
		
		// type casting
		result = (Directory*) position;
	
		// if target is in resut directory position is not null
		// else poisition is null
		position = result->find(target);	
	}

	return position;
}


void exec_cmd(Directory* root,std::string cmd)
{
	if(cmd.length() < 0) return;
	int i = 0;
	string target_path, dest_path;
  //*****Do NOT MODIFY START*****
  std::istringstream iss1(cmd),iss2(cmd);
  std::string token;
  std::getline(iss2,token,' ');
  std::getline(iss1,token,' ');
  //*****DO NOT MODIFY END*****

  //Implement your here
  //mapping intruction to function
	for(;i<10; ++i) if(token == instruction[i]) break;
	iss1>>target_path;
	iss1>>dest_path;
	func_arr[i](root,target_path,dest_path);
}


int main()
{
  //*****Do NOT MODIFY START*****
    Directory root("root");
    root.add(new Directory("hello"));
    std::cout << root << std::endl; //this prints all the directories and files in root directory. (the result of tree command)

    std::string inputBuffer;
    while(1){
      std::getline(std::cin,inputBuffer);
      if(inputBuffer.compare("exit")==0) break;
      exec_cmd(&root,inputBuffer);
    }
  //*****DO NOT MODIFY END*****

}


bool cd(Directory*& root, string& target_path, string& dest_path){
	Directory* dummy = root;
	dummy = (Directory*)find_directory(root,target_path);
	if(!dummy){ 
		cout<<"Invalid input"<<endl;
		return false;
	}
	else{ 
		*root = *dummy;
		return true;
	}
}


bool mkdir(Directory*& root, string& target_path, string& dest_path){

	//prev is parent directory
	Directory* prev = 0, input("genesis");
	//now is literally now
	//next is next directory
	//if there's no next directory, next is null
	string now,next;
	istringstream path(target_path);
	//if the directory already exists
	if(find_directory(root, target_path)){
		cout<<"directory already exists";
		return false;
	}
	//we have to make directory
	else{
		// default setting
		getline(path,now,'/');
		do{
			if(root->find(now)) root = static_cast<Directory*>(root->find(now));
			else {
				root->add(new Directory(now));
				root = static_cast<Directory*>(root->find(now));
			}	
		}while(getline(path,now,'/'));
		return true;
	}
}


bool touch(Directory*& root, string& target_path, string& dest_path){

	//prev is parent directory
	Directory* prev = 0;
	//now is literally current_root
	//next is next directory
	//if there's no next directory, next is null
	string now,next;
	istringstream path(target_path);
	//if the directory already exists
	if(find_directory(root, target_path)){
		cout<<"file already exists";
		return false;	
	}
		//we have to make directory
	else{
		// default setting
		getline(path,now,'/');
		do{
			if(root->find(now)) root = static_cast<Directory*>(root->find(now));
			else {
				prev = root;
				next = now;
				root->add(new Directory(now));
				root = static_cast<Directory*>(root->find(now));
			}
		}while(getline(path,now,'/'));
		prev->remove(next);
		prev->add(new File(next));
		return true;
	}
}


bool echo(Directory*& root, string& target_path, string& content){

	Directory* prev = 0;
	File* target = 0;
	string now, next;
	istringstream path(target_path);
	while(getline(path,now,'/')){
			if(root->find(now)){ 
				prev = root;
				next = now;
				root = static_cast<Directory*>(root->find(now));
			}
			else {
				prev = root;
				next = now;
				root->add(new Directory(now));
				root = static_cast<Directory*>(root->find(now));
			}
	}
	prev->remove(next);
	prev->add(new File(next));
	target = static_cast<File*>(prev->find(next));
	target->content(content);
	cout<<"Content Updated!"<<endl;
	return true;
}

bool ls(Directory*& root, string& target_path, string& dest_path){
	cout<<root->content();
	cout<<endl;
	return true;
}


bool tree(Directory*& root, string& target_path, string& dest_path){
	root->print(cout,0);
	return true;
}

bool cat(Directory*& root, string& target_path, string& dest_path){

	File* target = static_cast<File*>(find_directory(root,target_path));
	if(!target){
		cout<<"no such file"<<endl;
		return false;
	}else{
		cout<<target->content()<<endl;
		return true;
	}

}

bool mv(Directory*& root, string& target_path, string& dest_path){
	
	if(cp(root, target_path, dest_path))
		rmdir(root, target_path, dest_path);
	return true;
}


bool cp(Directory*& root, string& target_path, string& dest_path){

	Entry* target = find_directory(root,target_path);
	cout<<"!"<<endl;
	Directory* dest = static_cast<Directory*>(find_directory(root,dest_path));
	if(!(target&&dest)){
		cout<<"no such file or directory"<<endl;
		return false;
	}
	dest->add(target->clone());
	return true;
}

bool rmdir(Directory*& root, string& target_path, string& dest_path){

	Directory* prev = 0;
	string now, next;
	istringstream path(target_path);
	while(getline(path,now,'/')){
			if(root->find(now)){ 
				prev = root;
				next = now;
				root = static_cast<Directory*>(root->find(now));
			}
			else {
				cout<<"no such directory"<<endl;
				return false;
			}
	}
	prev->remove(next);
	return true;
}

bool rm(Directory*& root, string& target_path, string& dest_path){
	Directory* prev = 0;
	string now, next;
	istringstream path(target_path);
	while(getline(path,now,'/')){
			if(root->find(now)){ 
				prev = root;
				next = now;
				root = static_cast<Directory*>(root->find(now));
			}
			else {
				cout<<"no such file"<<endl;
				return false;
			}
	}
	prev->remove(next);
	return true;
}
