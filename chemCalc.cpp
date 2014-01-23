/*	chemCalc back-end
	by InvisibleTree
	quick compile = g++ chemCalc.cpp -o chemCalc
	
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

int main(int argc, char* argv[]){

	ifstream elementStream("elementData.txt");													//	Open ifstream for "elementData.txt" (needs to be in same folder as source and .exe)
	
	int massCounter = 0;																		//	Incrementing the RFM in the for loop
	char c;
	size_t pos;																					//	Position of element symbol in array
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
			pos = string(argv[2]).find(elementArray[i].symbol);
			if(pos <= string(argv[2]).size()){													//	If the position of the char in the string is less than string size - using this reduces memory usage
				if((pos+2) <= string(argv[2]).size()){											//	If the position + 2 of the char in the string is less than the string size i.e. not at the end
					c = string(argv[2]).at(pos+1);												//	c is equal to the character at the position + 1 of the element symbol in the string
					if((elementArray[i].symbol).size() == 1 && islower(c,loc)){					//	If c is lower case e.g. the e in 'Fe', and if the element is a single letter symbol,
						continue;																//	, do not add it to the mass counter (e.g. FeO = Fe + O + F instead of Fe + O)
					}else{
						if(pos != string::npos){
							massCounter += elementArray[i].massNo;
						}
					}
				}else{
					if(pos != string::npos){
						massCounter += elementArray[i].massNo;
					}
				}
			}else{
				continue;
			}
		}
		cout << "The RFM of " << argv[2] << " is " << massCounter << "g/mol" << endl;
	}
	
	return 0;
}

