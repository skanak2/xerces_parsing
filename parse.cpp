#include "stdafx.h"
#include<parse1.h>

const char* flname="c:/demo.xml";
//this is constructor which initializes parser
cap::cap()
{

	try
    {
		XMLPlatformUtils::Initialize();
        parser = new XercesDOMParser();
		parser->setValidationScheme(XercesDOMParser::Val_Always);
		parser->setDoNamespaces(true);    // optional

		erh = (ErrorHandler*) new HandlerBase();
		parser->setErrorHandler(erh);
		cout<<"entered parser"<<endl;
        
    }
	catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n"
             << message << "\n";
        XMLString::release(&message);
        
    }
	  
	
}

cap::~cap()
{
	delete parser;
	delete erh;
}

//start the parsing and finding out the errors
int cap::par1()
{
	

	try
	{
		parser->parse(flname);
			
	}
	catch(const XMLException &tocatch)
	{
		char * mesg=XMLString::transcode(tocatch.getMessage());
		cout<<"Exception is catched"<<mesg<<endl;
		XMLString::release(&mesg);
		return 1;
	}
	catch(const DOMException &tocatch)
	{
		char * msg=XMLString::transcode(tocatch.msg);
		cout<<"Exception is catched"<<msg<<endl;
		XMLString::release(&msg);
		return 1;
	}
	catch(...)//catches all types of errors
	{
		cout<<"Some unexpected exception"<<endl;
		return 1;
	}
  
    doc = parser->getDocument();
    docRootNode = doc->getDocumentElement();
    cout << docRootNode->getAttributes() << endl;
	
	return 0;
}


// to check the value of child node
string cap::parread(const char* parentTag, int parentIndex,const char* childTag,  int childIndex)
{

	
	XMLCh* temp=XMLString::transcode(parentTag);
	DOMNodeList* list = doc->getElementsByTagName(temp);
    XMLString::release(&temp);
 
    DOMElement* parent =dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMElement* child =dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
     
    string value;
    if (child) {
        char* temp2 = XMLString::transcode(child->getTextContent());
		//cout<<"its :"<<child->getTextContent()<<endl;
        value = temp2;
        XMLString::release(&temp2);
    }
    else {
        value = "NO VALUE";
    }
	
	
	return value;

}
 
// to count how many nodes are in total
int cap::getChildCount(const char* parentTag, int parentIndex,const char* childTag)
{

	
	
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = doc->getElementsByTagName(temp);
    XMLString::release(&temp);
 
    DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMNodeList* childList = parent->getElementsByTagName(XMLString::transcode(childTag));
	
	
	
    return (int)childList->getLength();
}

