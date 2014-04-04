/*	chemCalc back-end
	by InvisibleTree
	quick compile = g++ chemCalc1.cpp -o chemCalc1
	
	element data stored in elementData.txt
*/
#include<iostream>
#include<string>
#include<fstream>
#include<locale>
using namespace std;

struct element {																				//	Data structure for elements (read from txt file)
	int atomicNo;																				//	Atomic number variable (proton number)
	string symbol;																				//	Symbol variable (e.g. H)
	string name;																				//	Name variable (e.g. Hydrogen)
	float massNo;																				//	Mass number
}elementArray[118];

int checkForNumber(char c, locale loc);
int main(int argc, char* argv[]){

	ifstream elementStream("elementData.txt");													//	Open ifstream for "elementData.txt" (needs to be in same folder as source and .exe)
	
	int massCounter = 0;																		//	Incrementing the RFM in the for loop
	int massMultiplier = 1;																					//	Position of element symbol in array
	locale loc;
	
	for(int i = 0; i < 118; i++){
		elementStream >> elementArray[i].atomicNo;												//	1 element = 1 line, all values on that line are assigned to struct member in order
		elementStream >> elementArray[i].symbol;												
		elementStream >> elementArray[i].name;
		elementStream >> elementArray[i].massNo;
	}
	
	if(string(argv[1]) == "-m" || string(argv[1]) == "--mass"){									
		for(int i = 0; i < 118; i++){
			if(string(argv[2]) == elementArray[i].symbol || string(argv[2]) == elementArray[i].name){
				cout << "The atomic mass of " << elementArray[i].name << " (" << elementArray[i].symbol << ") is: "
					 << elementArray[i].massNo << endl;
					 break;
			}
		}	
	}else if(string(argv[1]) == "-a" || string(argv[1]) == "--atomic"){									
		for(int i = 0; i < 118; i++){
			if(string(argv[2]) == elementArray[i].symbol || string(argv[2]) == elementArray[i].name){
				cout << "The atomic number of " << elementArray[i].name << " (" << elementArray[i].symbol << ") is: "
					 << elementArray[i].atomicNo << endl;
					 break;
			}
		}	
	}else if(string(argv[1]) == "-rfm" || string(argv[1]) == "--RFM"){							
		for(int i = 0; i < 118; i++){													
			size_t pos = string(argv[2]).find(elementArray[i].symbol);
			if(pos <= string(argv[2]).size()){													//	Check the position of the char is in the string
				if((pos+2) <= string(argv[2]).size()){											//	Check if the position + 2 of the char in the string is less than the string size i.e. not at the end (end of string is counted, there
					char c = string(argv[2]).at(pos+1);												//	c is equal to the character at the position + 1 of the element symbol in the string
					if((elementArray[i].symbol).size() == 1 && islower(c,loc)){					//	If c is lower case e.g. the e in 'Fe', and if the element is a single letter symbol,
						continue;																//	, do not add it to the mass counter (e.g. FeO = Fe + O instead of F + Fe + O)
					}else{
						if(pos != string::npos){
							massMultiplier = checkForNumber(c, loc);
							massCounter += massMultiplier * (elementArray[i].massNo);
							massMultiplier = 1;																	// reset massCounter to 1
						}
					}
				}else{																			// If the element/number if is the last in the string...
					if(pos != string::npos){
							char c = string(argv[2]).at(pos);									// char c is set to the element/number
							massMultiplier = checkForNumber(c, loc);
							massCounter += massMultiplier * (elementArray[i].massNo);
							massMultiplier = 1;																	// reset massCounter to 1
					}
				}
			}else{
				continue;
			}
			pos = 0;	// reset pos

		}
		cout << "The RFM of " << argv[2] << " is " << massCounter << "g/mol" << endl;
	}
	
	return 0;
}
int checkForNumber(char c, locale loc){

	int number = 1;
	if(isdigit(c,loc) > 0){
		number = c - '0';
		return number;
	}else{
		return number;
	}
}
