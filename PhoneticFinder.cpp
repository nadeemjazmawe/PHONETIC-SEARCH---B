
#include <iostream>
#include <string.h>
#include "PhoneticFinder.hpp"
#include <stdexcept>

using namespace std;

namespace phonetic {


	bool help( char a , char b){
		if(a == b ) 
			return true;

		if(a == b+32)
			return true;
		if(a == b-32)
			return true;
		
		if(((a == 'v') || (a == 'V') || (a == 'w') || (a == 'W'))
			&&((b == 'v') || (b == 'V') || (b == 'w') || (b == 'W')))
				return true;

		if(((a == 'g') || (a == 'G') || (a == 'j') || (a == 'J'))
			&&((b == 'g') || (b == 'G') || (b == 'j') || (b == 'J')))
				return true;

		if(((a == 's') || (a == 'S') || (a == 'z') || (a == 'Z'))
			&&((b == 's') || (b == 'S') || (b == 'z') || (b == 'Z')))
				return true;

		if(((a == 'd') || (a == 'D') || (a == 't') || (a == 'T'))
			&&((b == 'd') || (b == 'D') || (b == 't') || (b == 'T')))
				return true;

		if(((a == 'o') || (a == 'O') || (a == 'u') || (a == 'U'))
			&&((b == 'o') || (b == 'O') || (b == 'u') || (b == 'U')))
				return true;

		if(((a == 'i') || (a == 'I') || (a == 'y') || (a == 'Y'))
			&& ((b == 'i') || (b == 'I') || (b == 'y') || (b == 'Y')))
				return true;

		if(((a == 'c') || (a == 'C') || (a == 'k') || (a == 'K') || (a == 'q') || (a == 'Q'))
			&& ((b == 'c') || (b == 'C') || (b == 'k') || (b == 'K') || (b == 'q') || (b == 'Q')))
				return true;

		if(((a == 'b') || (a == 'B') || (a == 'f') || (a == 'F') || (a == 'p') || (a == 'P')) 
			&& ((b == 'b') || (b == 'B') || (b == 'f') || (b == 'F') || (b == 'p') || (b == 'P')))
				return true;

		return false;
	}

	string find (string x , string y){
		string save = "";
		int j = 0;
		for(int i = 0 ; i < x.length() ; i++){
			if (y == "")
           		throw std::invalid_argument("Can't find the word in the text !");
		
           	while(x[i] == ' ')
           		i++;

           	while(y[j] == ' ')
           		j++;

           	while((x.length() > i) && (y.length() > j) && (help(x[i] , y[j])) && (x[i] != ' ')){
           		save += x[i];
           		j++;
           		i++;
           	}

           	if(y.length() == save.length())
           		return save;

           	else{
           		j = 0;
           		save.clear();
           	}

           	if((x.length() == i) && (y.length() != save.length()))
           		throw runtime_error("The word " + y + " is not in the text.");
		}
		throw runtime_error("The word " + y + " is not in the text.");
	}

}
