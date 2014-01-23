#include<iostream>

int main(int argc, char* argv[]){
loop:
	std::cout << "Hello world" << std::endl;
	goto loop;

}