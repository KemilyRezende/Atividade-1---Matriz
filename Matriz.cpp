#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Matriz.hpp"

using namespace std;

Matriz::Matriz(int n){
	this->n = n;
	int mat[n][n];
	//coloca os valores
	int i;
	int j;
	int aux;
	srand(time(NULL));
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			fflush(stdin);
			aux = rand()%99;
			mat[i][j] = aux;
			cout << mat[i][j] << "   ";
		}
		cout << "\n";
	}
	cout << "Calculando rota:\n";
	//caminho
	i=0;
	j=0;
	this->atual = mat[i][j];
	this->soma = atual;
	cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
	do{
		if (i==0 && j==0){
			mat[i][j] = -1;
			if (mat[i][j+1]>mat[i+1][j]){
				atual = mat[i][j+1];
				soma = soma + atual;
				mat[i][j] = -1;
				j++;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
			else {
				atual = mat[i+1][j];
				soma = soma + atual;
				mat[i][j] = -1;
				i++;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
		}
		
		else if (i<n-1 && j>0 && j<n-1){
			if ((mat[i][j+1] > mat[i][j-1]) && (mat[i][j+1] > mat[i+1][j])){
				atual = mat[i][j+1];
				mat[i][j]= -1;
				soma = soma + atual;
				j++;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
			else if((mat[i][j-1] > mat[i][j+1]) && (mat[i][j-1] > mat[i+1][j])){
				atual = mat[i][j-1];
				mat[i][j]= -1;
				soma = soma + atual;
				j--;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
			else {
				atual = mat[i+1][j];
				mat[i][j] = -1;
				soma = soma + atual;
				i++;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
		}
		else if (i<n-1 && j==0){
			if (mat[i][j+1] > mat[i+1][j]){
				atual = mat[i][j+1];
				mat[i][j]= -1;
				soma = soma + atual;
				j++;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
			else {
				atual = mat[i+1][j];
				mat[i][j] = -1;
				soma = soma + atual;
				i++;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
		}
		else if (i<n-1 && j == n-1){
			if (mat[i][j-1] > mat[i+1][j]){
				atual = mat[i][j-1];
				mat[i][j]= -1;
				soma = soma + atual;
				j--;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
			else {
				atual = mat[i+1][j];
				mat[i][j] = -1;
				soma = soma + atual;
				i++;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
		}
		else if (i == n-1 && j>0 && j<n-1){
			if (mat[i][j+1] > mat[i][j-1]){
				atual = mat[i][j+1];
				mat[i][j] = -1;
				soma = soma + atual;
				j++;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
			else {
				atual = mat[i][j-1];
				mat[i][j] = -1;
				soma = soma + atual;
				j--;
				cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			}
		}
		else if (i== n-1 && j==0){
			atual = mat[i][j+1];
			mat[i][j] = -1;
			soma = soma + atual;
			j++;
			cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
		}
		else if (i== n-1 && j== n-1){
			atual = mat[i][j];
			mat[i][j] = -1;
			soma = soma + atual;
			cout << "Posição atual: " << i+1 << "x" << j+1 << "\nValor atual: " << atual << endl;
			cout << "Soma: " << soma << endl; 
			i++;
			j++;
		}
	}while (i<n && j<n);
	
	cout << "Imprimindo rota:\n";
	for (i=0; i<n; i++){
		cout << "\n";
		for (j=0; j<n; j++){
			cout << mat[i][j] << "  ";
		}
	}
}

