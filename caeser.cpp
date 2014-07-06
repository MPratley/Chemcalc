/************************
*	Caeser encryption	*
*	by InvisibleTree	*
************************/

#include <iostream>
#include <string>
#include <stdlib.h>

void encrypt();
void decrypt();
int main(int argc, char* argv[]){

	int nSel;
	
	system("cls");
	std::cout << "Caeser Cipher encryption:" << std::endl;
	std::cout << "[1]: Encrypt message" << std::endl;
	std::cout << "[2]: Decrypt message" << std::endl;
	std::cin >> nSel;
		

	
	if(nSel == 1){
		encrypt();
	}
	else if(nSel == 2){
		decrypt();
	}

}

void encrypt(){

	int nOffset;
	std::string sText;
	
	system("cls");
	std::cout << "Enter desired offset: ";
	std::cin >> nOffset;
	
	std::cin.ignore();
	std::cout << "Enter text to be encrypted (max 256 chars, no punctuation): ";
	std::getline(std::cin, sText);
	
	for(int i = 0; i < sText.length(); i++){
		if(sText[i] != ' '){
			if((sText[i] + nOffset) > 122){
				sText[i] = (122 - sText[i]) + 97 + nOffset;
				std::cout << sText[i];
			}else{
				sText[i] += nOffset;
				std::cout << sText[i];
			}
		}else if(sText[i] == 32){
			std::cout << " ";
		}
	}	
}

void decrypt(){

	int nOffset;
	std::string sText;
	
	system("cls");
	std::cout << "Enter desired offset: ";
	std::cin >> nOffset;
	
	std::cin.ignore();
	std::cout << "Enter text to be encrypted (max 256 chars, no punctuation): ";
	std::getline(std::cin, sText);
	
	for(int i = 0; i < sText.length(); i++){
		if(sText[i] != ' '){
			if((sText[i] - nOffset) < 97){
				sText[i] = ((122 + sText[i]) - 97) - nOffset;
				std::cout << sText[i];
			}else{
				sText[i] -= nOffset;
				std::cout << sText[i];
			}
		}else if(sText[i] == 32){
			std::cout << " ";
		}
	}	
}
