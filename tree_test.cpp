#include "BST.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main() {
  
  BST<std::string>* s = new BST<std::string>();
	
  s->insert("mop");
  s->insert("kid");
  s->insert("org");
  s->insert("ark");
  s->insert("bed");
  s->insert("orr");
  s->insert("toe");
  s->insert("zoo");
  s->insert("ape");
  s->insert("abe");
  s->insert("bic");
  s->insert("sow");	
		
  s->visualPrint("   ", " / ", "  \\ ");

  cout << "Removing zoo" << endl;
  s->remove("zoo");
  cout << "Removing ape" << endl;
  s->remove("ape");
  cout << "Removing bic" << endl;
  s->remove("bic");
	
  s->visualPrint("   ", " / ", " \\ ");
	
  cout << "inserting tee, sir... " << endl;
  s->insert("tee");
  s->insert("sir");
	
  s->visualPrint("   ", " / ", " \\ ");
	
}
