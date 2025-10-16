#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class No{
	public:
		int elemento;
		No *prox;

		No(int e){
			elemento = e;
			prox = NULL;
		}
};

class Pilha{
	public:
		No *topo;
		
		Pilha(){
			topo = NULL;
		}

		bool isEmpty(){
			return (topo == NULL);
		}
		
		void push(int e){
		No *novo = new No(e);
		if(isEmpty()) topo = novo;
		else{
			novo->prox = topo;
			topo = novo;
			}
		
		cout << "Numero " << e << " empilhado com sucesso!" << endl;
		}
		
		int pop(){
			if (!isEmpty()){
				No *temp = topo;
				int removido = topo->elemento;
				topo = topo->prox;
				delete temp;

				return removido;
			}
			cout << "Pilha vazia!" << endl;
			abort();
		}

		void mostrar(){
			while(!isEmpty()){
				cout << topo->elemento << endl;
				topo = topo->prox;
			}
		}
};

int main(){
	
	Pilha *pilha = new Pilha();

	pilha->push(1);
	pilha->push(2);
	pilha->push(3);
	pilha->push(4);
	pilha->push(5);
	pilha->push(6);
	pilha->pop();
	pilha->pop();
	pilha->pop();
	pilha->mostrar();

	return 0;
}
