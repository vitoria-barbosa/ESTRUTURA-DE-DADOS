#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class No{
	public:
		int elemento;
		No *prox;

		// construtor
		No(int e){
			elemento = e;
			prox = NULL;
		}
};

class Fila{    
	public:
		// atributos ponteiros
		No *inicio;
		No *fim;
		
		// construtor
		Fila(){
			inicio = NULL;
			fim = NULL;
		}
		
		// metodos (adiciona os elementos no final e retira pelo começo)
		bool isEmpty(){
			return (inicio == NULL);
		}

		void append(int e){
			No *novo = new No(e);

			if (isEmpty()) inicio = fim = novo;
			else{
				fim->prox = novo;
				fim = novo;
			}

			cout << "Elemento " << e << " adicionado!" << endl;
		}
		
		int pop(){
			if (!isEmpty()) {
				No *temp = inicio;
				int removido = temp->elemento;
				inicio = inicio->prox;
				delete(temp);
				return removido;
			}else{
				cout << "Fila vazia!" << endl;
				abort();
			}
		}
	
	    void popAll(){
			cout << "Desenfileirando todos..." << endl;
	    	while(!isEmpty()){
				cout << pop() << endl;
			}
		}

};

int main(){
	
	Fila *fila = new Fila();

	fila->append(2);
	fila->append(6);
	fila->append(9);
	fila->append(13);
	fila->append(2);
	fila->append(21);
    cout << "Removeu: " << fila->pop() << endl;
	fila->popAll();
	

	
}
