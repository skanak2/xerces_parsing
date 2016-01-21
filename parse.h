#include "stdafx.h"
#include <iostream>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMText.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>



using namespace std;
using namespace xercesc; 

   
class cap
{
public:
	cap();
	~cap();
	int par1();
	string parread(const char* parentTag, int parentIndex,const char* childTag, int childIndex);
	int getChildCount(const char* parentTag, int parentIndex, const char* childTag);
private:
	XercesDOMParser* parser;
	ErrorHandler* erh;
	DOMDocument* doc;
	DOMNode* docRootNode;
  DOMNode* aNode;
  
};

