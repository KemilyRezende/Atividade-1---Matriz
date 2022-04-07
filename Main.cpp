#include <iostream>
#include <stdlib.h>
#include <locale>
#include "Matriz.hpp"

using namespace std;

int main(int argc, char** argv) {
	int n, op;
	
	setlocale (LC_ALL, "Portuguese");
	
	cout << "\nTamanho da matriz: "; 
	cin >> n;
	
	Matriz m(n);
	
	return 0;
}

