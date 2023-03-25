#ifndef INST_H
#define INST_H
#include <bits/stdc++.h>
#include <exception>
#include <string>

using namespace std;
typedef unsigned int uint;

inline uint parseOpcode(uint inst){	return inst%128; }

class baseInst
{
	protected:
		uint inst;
		uint opcode, imd7, imd8, imd12, imd15, imd20, imd25, imd31;
		string result;
	
	public:
		baseInst(void){};
		baseInst (uint rawInst);
		virtual void printInst(void){
			printf("baseInst !\n");
		}
		virtual ~baseInst(){};
};

class rInst : public baseInst
{
	private:
		uint rd, funct3, rs1, rs2, funct7;
	
	public:
		rInst(uint rawInst);
		virtual void printInst(void);
};

class iInst : public baseInst
{
	private:
		uint rd, funct3, rs1, imd;

	public:
		iInst(uint rawInst);
		virtual void printInst(void);
};

class sInst : public baseInst
{
	private:
		uint funct3, rs1, rs2, imd;

	public:
		sInst(uint rawInst);
		virtual void printInst(void);
};

class bInst : public baseInst
{
	private:
		uint funct3, rs1, rs2, imd;

	public:
		bInst(uint rawInst);
		virtual void printInst(void);
};

class uInst : public baseInst
{
	private:
		uint rd, imd;

	public:
		uInst(uint rawInst);
		virtual void printInst(void);
};

class jInst : public baseInst
{
	private:
		uint rd, imd;

	public:
		jInst(uint rawInst);
		virtual void printInst(void);
};

int cnvU2I(uint,uint);
#endif
