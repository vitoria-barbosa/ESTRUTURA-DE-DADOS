#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
class No{
	public: 
		int mat;
		string nome;
		No *prox;
		
		// construtor
		No(int m, string n){
			mat = m;
			nome = n;
			prox=NULL;
		}
};

class Lista{
	No *inicio, *fim;
	public:
		// construtor
		Lista(){
			inicio = NULL;
			fim = NULL;
		}

		// métodos
		void addFinal(int m, string n){
			No *novo = new No(m, n);
			if (inicio == NULL) inicio = fim = novo;
			else{
				fim->prox = novo;
				fim = novo;
			}
		}
		
		void addInicio(int m, string n){
			No *novo = new No(m, n);
			if (inicio == NULL) inicio = fim = novo;
			else{
				novo->prox = inicio;
				inicio = novo;
			}
		}
	

		void addOrdenado(int m, string n){
			No *anterior;
			No *atual = inicio; 
			No *novo = new No(m, n);
			
			if (inicio == NULL) inicio = fim = novo;
			else if(novo > atual){
				fim->prox = novo;
				fim = novo;
			}
			else{
				while(novo <= atual) {
					anterior = atual;
					atual = atual->prox;
				}
				anterior->prox = novo;
				novo->prox = atual;
			}
		}
		
		void mostrar(){
		No *atual = inicio;
		while (atual != NULL){
			cout << "-------------------" <<endl;
			cout << "|Mat: "<< atual->mat <<endl;
			cout << "|Nome: "<< atual->nome <<endl;
			atual=atual->prox;
			}
   		}
   
		void remover(int mat){
		No *anterior;
			No *atual = inicio; 
			
			while( atual != NULL){
				if (atual->mat == mat){
					if (atual == inicio){
						inicio = inicio->prox;
					}
					else if (atual == fim){
						fim = anterior;
						fim->prox = NULL;
					}
					else{
						anterior->prox = atual->prox;
						atual->prox = NULL;
					}
					delete atual;
				}
				anterior = atual;
				atual = atual->prox;
			}
		}	

};

int main(){
	
	Lista *turma = new Lista();
	cout << "\nTurma 1: " << endl;
	turma->addFinal(1, "vitoria");
	turma->addFinal(2, "maria");
	turma->addFinal(3, "thalisson");
	turma->addFinal(4, "joana");
	turma->addFinal(5, "kamila");
	turma->mostrar();

	Lista *turma2 = new Lista();
	cout << "\n\nTurma 2: " << endl;
	turma2->addInicio(  7, "vitoria");
	turma2->addInicio( 10, "maria");
	turma2->addInicio( 17, "thalisson");
	turma2->addInicio( 20, "joana");
	turma2->addInicio(100, "kamila");
	turma2->mostrar();

	Lista *turma3 = new Lista();
	cout << "\n\nTurma 3: " << endl;
	turma3->addOrdenado(  7, "vitoria");
	turma3->addOrdenado( 10, "maria");
	turma3->addOrdenado( 17, "thalisson");
	turma3->addOrdenado( 20, "joana");
	turma3->addOrdenado(100, "kamila");
	turma3->mostrar();
	
	cout << "\nRemover aluna Joana\n" << endl;
	turma3->remover(20);
	turma3->mostrar();
	
	return 0;
}