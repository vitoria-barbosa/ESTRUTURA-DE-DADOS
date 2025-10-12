#include <iostream>
using namespace std;

template<class T>
class No {
	public:
		T elemento;
		No<T> *prox;		

		// contrutores:
		No(){
			prox = 0;			
		}
		No(T e){
			elemento = e;
			prox = 0;			
		}
};

template<class T>
class Lista{
	protected:
		No<T> *inicio, *fim, *atual;
	public:
		Lista(){
			inicio = fim = 0;			
		}	
			
		void insert(T ele){	
			No<T> *novo = new No<T>(ele);
			if (inicio == 0 ) inicio = fim = novo;
			fim->prox = novo; 
			fim = novo;  	
		}

		void mostra(){
			atual = inicio;
			while (atual != 0){
				cout << atual->elemento << endl;
				atual = atual->prox;
			}	
		}


};

main(){

	Lista<int> *b = new Lista<int>();
	
	b->insert(10);
	b->insert(5);
	b->insert(20);
	b->insert(3);
	b->insert(7);
	b->mostra();
	
}
