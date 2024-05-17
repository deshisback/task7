#include "ParentPseudoInterface.h"

void ParentPseudoInterface::AddParentToList(Parent* parent)
{
	AllParents.push_back(parent);
}

void ParentPseudoInterface::AddGrandMotherToList(Grandmother* grandmother)
{
	AllGrandmothers.push_back(grandmother);
}

void ParentPseudoInterface::PrintChildrenOfParent(Parent* parent)
{
	parent->TellChildrenNames();
}

void ParentPseudoInterface::PrintCHildrenOfGrandMother(Grandmother* grandmother)
{
	grandmother->TellChildrenNames();
}

Parent* ParentPseudoInterface::ReturnParentFromAllParents(int i)
{
	if (i < 0 || i > AllParents.size()) return nullptr;
	else return AllParents[i];
}

Grandmother* ParentPseudoInterface::ReturnGrandmoterFromAllGrandmothers(int i)
{
	if (i < 0 || i > AllGrandmothers.size()) return nullptr;
	else return AllGrandmothers[i];
}

int ParentPseudoInterface::CountOfParents()
{
	return AllParents.size();
}

int ParentPseudoInterface::CountOfGrandMothers()
{
	return AllGrandmothers.size();
}
