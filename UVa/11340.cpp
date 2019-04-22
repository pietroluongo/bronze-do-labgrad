#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// 11340 - Newspaper


int main(void){
    int N, i, valorFinal;

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        map<char,int> tabela;
        map<char,int>::iterator it;
        int K, j;
        scanf("%d\n", &K);
        valorFinal = 0;
        for(j = 0; j < K; j++){
            char c;
            int valor;
            scanf("%c %d\n", &c, &valor);
            tabela[c] = valor;
        }
        int qtdLines;
        scanf("%d\n", &qtdLines);
        for(j = 0; j < qtdLines; j++){
            char linha[10010];
            string l;
            getline(cin, l);
            strcpy(linha, l.c_str());
            int k;
            for(k = 0; k < strlen(linha); k++){
                char cLinha = linha[k];
                it = tabela.find(cLinha);
                if(it != tabela.end()){
                    valorFinal += tabela[cLinha];
                }
            }
        }
        printf("%02.2lf$\n", (double)valorFinal/100);

    }


    return 0;
}