#pragma once
#include "Parent.h"

class ParentPseudoInterface
{

private:

	std::vector<Parent*> AllParents;

public:

	void AddParentToList(Parent* parent);

	void PrintChildrenOfParent(Parent* parent);

	Parent* ReturnParentFromAllParents(int i);

	int CountOfParents();

};

