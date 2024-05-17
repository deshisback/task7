#pragma once
#include "Parent.h"
#include "Grandmother.h"

class ParentPseudoInterface
{

private:

	std::vector<Parent*> AllParents;
	std::vector<Grandmother*> AllGrandmothers;

public:

	void AddParentToList(Parent* parent);

	void AddGrandMotherToList(Grandmother* grandmother);

	void PrintChildrenOfParent(Parent* parent);

	void PrintCHildrenOfGrandMother(Grandmother* grandmother);

	Parent* ReturnParentFromAllParents(int i);

	Grandmother* ReturnGrandmoterFromAllGrandmothers(int i);

	int CountOfParents();

	int CountOfGrandMothers();

};

