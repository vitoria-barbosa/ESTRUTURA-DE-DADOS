#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#define MAX 50
using namespace std;

typedef struct {
    int x, y;
} Ponto;

class No{
	public:
		Ponto ponto;
		No *prox;

		// construtor
		No(Ponto ponto){
			this->ponto = ponto;
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

		void append(int x, int y){
            Ponto p;
            p.x = x;
            p.y = y;
			No *novo = new No(p);

			if (isEmpty()) inicio = fim = novo;
			else{
				fim->prox = novo;
				fim = novo;
			}
		}
		
		Ponto pop(){
			if (!isEmpty()) {
				No *temp = inicio;
				Ponto removido = temp->ponto;
				inicio = inicio->prox;
				delete temp;
				return removido;
			}else{
				cout << "Fila vazia!" << endl;
				abort();
			}
		}
};

class FloodFill{
    public:
        int imagem[MAX][MAX], linhas, colunas, x, y, corAtual, novaCor;
        Fila *fila = new Fila();
        
        FloodFill(int imagem[MAX][MAX], int linhas, int colunas, int x, int y, int novaCor){
            this->linhas = linhas;
            this->colunas = colunas;
            this->x = x;
            this->y = y;
            this->novaCor = novaCor;
            this->corAtual = imagem[x][y];

            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    this->imagem[i][j] = imagem[i][j];
                }
            }
        };


        void changeColor(){
            fila->append(x, y);

            while(!fila->isEmpty()){
                Ponto p = fila->pop();
                int i = p.x;
                int j = p.y;

                if (i < 0 || i >= linhas || j < 0 || j >= colunas || imagem[i][j] != corAtual){
                    continue;
                }
                
                imagem[i][j] = novaCor;
                fila->append(i + 1, j);             
                fila->append(i, j + 1);             
                fila->append(i - 1, j);             
                fila->append(i, j - 1);             
            }
        }

        
        void exibirImagem(){
            for(int v = 0; v < linhas; v++){
                for(int t = 0; t < colunas; t++){
                    cout << imagem[v][t] << " "; 
                } 
                cout << endl;
            }
        }
};


int main() {
    int imagem[MAX][MAX] = {
        {1, 1, 1, 2, 2},
        {1, 1, 0, 2, 2},
        {1, 0, 0, 2, 2},
        {1, 1, 0, 2, 2},
        {1, 1, 1, 2, 2}
    };

    FloodFill *ff = new FloodFill(imagem, 5, 5, 2, 2, 9);

    ff->exibirImagem();
    cout << " " << endl;

    ff->changeColor();
    cout << "Imagem apos mudar o 0 por 9:" << endl;
    ff->exibirImagem();

    return 0;
}