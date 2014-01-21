/*	chemCalc back-end
	by InvisibleTree
	quick compile = g++ chemCalc.cpp -o chemCalc
*/
#include<iostream>
#include<string>

int main(int argc, char* argv[]){
	
	if(std::string(argv[1]) == "-m"){
		std::cout << "mass" << std::endl;
	}
	
	return 0;
}