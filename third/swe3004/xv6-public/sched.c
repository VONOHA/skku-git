#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"

// Structure to represent each
// node in a red-black tree
struct node {
    struct proc * p;      // data
    int color;						// 1-red, 0-black
    int left;							// left-child
    int right;						// right-child
    int parent;						// parent
}RBtree[NPROC];


int rootIdx = -1, size = 0;

void initTree(void)
{
	for(int i = 0; i<NPROC; ++i)
	{
		RBtree[i].p = 0;
		RBtree[i].color = 0;
		RBtree[i].left = -1;
		RBtree[i].right = -1;
		RBtree[i].parent = -1;
	}
}

void insertNode(struct proc *target)
{
	int ti,pi, temp; // target index, parent index

	temp = rootIdx;

	while(temp != -1)
	{
		pi = temp;
		if(target->vruntime < RBtree[temp].p->rruntime)
			temp = RBtree[temp].left;
		else
			temp = RBtree[temp].right;
	}

	temp = size++; 
	RBtree[temp].p = target;
	RBtree[temp].parent = pi;
	RBtree[temp].color = 1;

	if(pi == -1)
			rootIdx = temp;
	else if(RBtree[temp].p->vruntime < RBtree[pi].p->rruntime)
			RBtree[pi].left = temp;
	else
			RBtree[pi].right = temp;
	
}

//succeding you ... father
//left rotate
void leftRotate(int temp)
{
	int son, father;
	
	son = RBtree[temp].right;
	father = RBtree[temp].parent;

	RBtree[temp].right = RBtree[son].left;
	RBtree[temp].parent = son;
	RBtree[son].parent = father;
	RBtree[son].left = temp;
}

//succeding you ... father
//left rotate
void rightRotate(int temp)
{
	int son, father;
	
	son = RBtree[temp].right;
	father = RBtree[temp].parent;

	RBtree[temp].left = RBtree[son].right;
	RBtree[temp].parent = son;
	RBtree[son].parent = father;
	RBtree[son].right = temp;
}

void insertFixup(int temp)
{
	int father, uncle, grandpa, son;
	
	father = RBtree[temp].parent;
	grandpa = RBtree[father].parent;
	uncle = father != RBtree[grandpa].left ?\
					RBtree[grandpa].left : RBtree[grandpa].right;

	if(temp == rootIdx){
		if(RBtree[rootIdx].color)
			RBtree[rootIdx].color = 0;
		return;
	}

	if(!RBtree[temp].color || !RBtree[RBtree[temp].parent].color)
		return;
	
	if(RBtree[uncle].color)
	{
		RBtree[uncle].color = 0;
		RBtree[father].color = 0;
		RBtree[grandpa].color = 1;
		return insertFixup(grandpa);	
	}
	else
	{
		if(RBtree[grandpa].left == father)
		{
			if(temp == RBtree[father].right)
				leftRotate(father);
	
			temp = RBtree[grandpa].left;
 			father = RBtree[temp].parent;
			RBtree[temp].color = 0;
			RBtree[father].color = 1;

			rightRotate(father);
		}
		else
		{
			if(temp == RBtree[father].right)
				rightRotate(father);

			temp = RBtree[grandpa].right;
			father = RBtree[temp].parent;
			RBtree[temp].color = 0;
			RBtree[father].color = 1;

			leftRotate(father);
		}
	}
}

int searchNode(struct proc *target)
{
	int temp;

	temp = rootIdx;
	
	while(temp != -1)
	{
		if(RBtree[temp].p->vruntime < target->vruntime)
			temp = RBtree[temp].right;
		else if(RBtree[temp].p->vruntime > target->vruntime)
			temp = RBtree[temp].left;
		else
			return temp;
	}

	return -1; // Not Found
}

void deleteNode(struct proc *target)
{
	int temp;
	temp = searchNode(target);

	if(!RBtree[temp].color)
	{
		//here
		
	}
}
