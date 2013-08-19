// Author: Markus Schordan, 2013.

#ifndef RDANALYSISASTATTRIBUTE_H
#define RDANALYSISASTATTRIBUTE_H

#include "Labeler.h"
#include "VariableIdMapping.h"
#include "RDAnalysisAbstractAstAttribute.h"
#include "RDLattice.h"
#include <string>

using namespace CodeThorn;
using std::string;

class RDAnalysisAstAttribute : public RDAnalysisAbstractAstAttribute {
 public:
  RDAnalysisAstAttribute(RDLattice* elem);
  bool isBottomElement();
  VariableIdSet allVariableIds();
  LabelSet allLabels();
  LabelSet definitionsOfVariableId(VariableId varId);
  VariableIdSet variableIdsOfDefinition(Label def);
  iterator begin();
  iterator end();
  virtual ~RDAnalysisAstAttribute();
  void toStream(ostream& os, VariableIdMapping* vim);
  string getPreInfoString();
  string getPostInfoString();
 private:
  RDLattice* _elem;
};

#endif
