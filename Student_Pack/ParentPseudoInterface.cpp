#include "ParentPseudoInterface.h"

void ParentPseudoInterface::AddParentToList(Parent* parent)
{
	AllParents.push_back(parent);
}

void ParentPseudoInterface::PrintChildrenOfParent(Parent* parent)
{
	parent->TellChildrenNames();
}

Parent* ParentPseudoInterface::ReturnParentFromAllParents(int i)
{
	if (i < 0 || i > AllParents.size()) return nullptr;
	else return AllParents[i];
}

int ParentPseudoInterface::CountOfParents()
{
	return AllParents.size();
}
