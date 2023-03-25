#include "inst.h"
#include <string>

baseInst::baseInst(uint rawInst)
{
	uint div;
	inst = rawInst;
	
	div = 1<<7;
	opcode = inst % div;
	inst /= div;

	div = 1<<1;
	imd7 = inst % div;
	inst /= div;

	div = 1<<4;
	imd8 = inst % div;
	inst /= div;

	div = 1<<3;
	imd12 = inst % div;
	inst /= div;

	div = 1<<5;
	imd15 = inst % div;
	inst /= div;

	div = 1<<5;
	imd20 = inst % div;
	inst /= div;

	div = 1<<6;
	imd25 = inst % div;
	inst /= div;

	imd31 = inst;
}

rInst::rInst(uint rawInst)
:baseInst(rawInst)
{
	rd = imd7 + (imd8<<1);
	funct3 = imd12;
	rs1 = imd15;
	rs2 = imd20;
	funct7 = imd25 + (imd31<<6);
}

void rInst::printInst(void)
{
	switch(funct3)
	{
		case 0x00:
			if(!funct7)
				result = "add x";
			else
				result = "sub x";
			break;
		case 0x01:
			result = "sll x";
			break;
		case 0x02:
			result = "slt x";
			break;
		case 0x03:
			result = "sltu x";
			break;
		case 0x04:
			result = "xor x";
			break;
		case 0x05:
			if(!funct7)
				result = "srl x";
			else
				result = "sra x";
			break;
		case 0x06:
			result = "or x";
			break;
		case 0x07:
			result = "and x";
			break;
		default:
			result = "unknown instruction";
			goto print;
	}
	result += to_string(rd) + ", x" + to_string(rs1)\
			  + ", x" + to_string(rs2);
	print:
		printf("%s", result.c_str());
}

iInst::iInst(uint rawInst)
:baseInst(rawInst)
{
	rd = imd7 + (imd8<<1);
	funct3 = imd12;
	rs1 = imd15;
	imd = imd20 + (imd25<<5) + (imd31<<11);
	imd = cnvU2I(imd, 11);
}

void iInst::printInst(void)
{
	if(opcode == 0x03)
	{
		switch(funct3)
		{
			case 0:
				result = "lb x";
				break;
			case 1:
				result = "lh x";
				break;
			case 2:
				result = "lw x";
				break;
			case 4:
				result = "lbu x";
				break;
			case 5:
				result = "lhu x";
				break;
			default:
				goto unknownInst;
		}
		result += to_string(rd) + ", " + to_string(int(imd))\
				  + "(x" + to_string(rs1) + ")";
		goto print;
	
	}
	else if(opcode == 0x13){
			switch(funct3)
			{
				case 0:
					result = "addi x";
					break;
				case 1:
					result = "slli x";
					imd %= 0x20;
					break;
				case 2:
					result = "slti x";
					break;
				case 3:
					result = "sltiu x";
					break;
				case 4:
					result = "xori x";
					break;
				case 5:
					if(imd>>10)
						result = "srai x";
					else
						result = "srli x";
					imd %= 0x20;
					break;
				case 6:
					result = "ori x";
					break;
				case 7:
					result = "andi x";
					break;
				default:
					goto unknownInst;
			}

			result += to_string(rd) + ", x" + to_string(rs1)\
					  + ", " + to_string(int(imd));
			goto print;
	}
	else if(opcode == 0x67){
		result = "jalr x" + to_string(rd) + ", "\
				  + to_string(int(imd)) + "(x"\
				  + to_string(rs1) + ")";
		goto print;
	}
	else
	{
		unknownInst:
			result = "unknown instruction";
			goto print;
	}

	print:
		printf("%s",result.c_str());
}

sInst::sInst(uint rawInst)
:baseInst(rawInst)
{ 
	imd = imd7 + (imd8<<1) + (imd25<<5) \
		  + (imd31<<11);
	imd = cnvU2I(imd, 11);
	funct3 = imd12;
	rs1 = imd15;
	rs2 = imd20;
}

void sInst::printInst(void)
{
	switch(funct3)
	{
		case 0:
			result = "sb x";
			break;
		case 1:
			result = "sh x";
			break;
		case 2:
			result = "sw x";
			break;
		default:
			result = "unknown instruction";
			goto print;
	}

	result += to_string(rs2) + ", " + to_string(int(imd))\
			  + "(x" + to_string(rs1) + ")";

	print:
		printf("%s",result.c_str());
}

bInst::bInst(uint rawInst)
:baseInst(rawInst)
{
	imd = (imd8<<1) + (imd25<<5) \
		  + (imd7<<11) + (imd31<<12);
	imd = cnvU2I(imd, 12);
	funct3 = imd12;
	rs1 = imd15;
	rs2 = imd20;
}

void bInst::printInst(void)
{
	switch(funct3)
	{
		case 0:
			result = "beq x";
			break;
		case 1:
			result = "bne x";
			break;
		case 4:
			result = "blt x";
			break;
		case 5:
			result = "bge x";
			break;
		case 6:
			result = "bltu x";
			break;
		case 7:
			result = "bgeu x";
			break;
		default:
			result = "unknown instruction";
			goto print;
	}
	
	result += to_string(rs1) + ", x" + to_string(rs2)\
			  + ", " + to_string(int(imd));
	print:
		printf("%s",result.c_str());
}

uInst::uInst(uint rawInst)
:baseInst(rawInst)
{
	rd = imd7 + (imd8<<1);
	imd = imd12 + (imd15<<3) + (imd20<<8) \
		  + (imd25<<13) + (imd31<<19);
	imd = imd<<12;
}

void uInst::printInst(void)
{
	if(opcode == 0x37)
		result = "lui x";
	else
		result = "auipc x";
	result += to_string(rd) + ", " + to_string(int(imd));
	printf("%s",result.c_str());
}

jInst::jInst(uint rawInst)
:baseInst(rawInst)
{
	int imd21, _imd;
	imd21 = (imd20 / 2);
	imd20 %= 2;
	rd = imd7 + (imd8<<1);
	imd = (imd21<<1) + (imd25<<5) + (imd20<<11) \
		  + (imd12<<12) + (imd15<<15) \
		  + (imd31<<20);
	imd = cnvU2I(imd, 20);
}

void jInst::printInst(void)
{
	result = "jal x" + to_string(rd) + ", "\
			  + to_string(int(imd));
	printf("%s",result.c_str());
}

int cnvU2I(uint target, uint locate)
{
	int result;

	result = target;
	result = result << (31-locate);
	result = result >> (31-locate);
	
	return result;
}
