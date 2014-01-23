#include<iostream>

int main(int argc, char* argv[]){
	
	char foo[] = {'H', 'E', 'L', 'L', 'O'};
	char bar[] = {'W', 'O', 'R', 'L', 'D'};
loop:
	std::cout << foo << bar << std::endl;
	goto loop;

}
