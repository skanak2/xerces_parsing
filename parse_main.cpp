
#include "stdafx.h"
#include<parse1.h>

using namespace std;
using namespace xercesc; 

// main function
int main (int argc, char* args[]) {
cap* c= new cap();

const char* cntparentTag="breakfast_menu";
const char* parentTag="food";
const char* childTag="name";
string value;



c->par1();
for (int i = 0; i < c->getChildCount(cntparentTag, 0, parentTag); i++)
{

	
            value = c->parread(parentTag, i, childTag, i);
			 printf("Dish Name     - %s\n", value.c_str());
}
system("pause");

return 0;

}
