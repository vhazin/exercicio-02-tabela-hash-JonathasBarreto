#include <stdio.h>
#include <stdlib.h>

int main()
{
    int q_teste, q_end, q_chaves, chave, end, end_ant;
    int g = 0;

    scanf("%d", &q_teste);// numero de testes q serão feitos


    for(int i = 0; i<q_teste; i++){//for para armazenar os testes

        scanf("%d %d", &q_end, &q_chaves);// recebe quantidade de endereços e chaves

        int v[q_end][q_chaves];// cria a matriz com o tramanho do endereço e das chaves

        for(int a = 0; a<q_end; a++){// zera toda a matriz

            for(int b = 0; b<q_chaves; b++){

                v[a][b] = 0;
            }
        }
        
        for(int f = 0; f<q_chaves; f++){/* recebe as chaves de acordo com 
                o tamanho de chaves pedido*/

            scanf("%d", &chave);

            end = chave % q_end;// hash função, vai dar um endereço
            
            if(end_ant != end){/* zera G toda vez que o 
                endereço for diferente que o endereço anterior*/
                
                g = 0;
            }
            
            end_ant = end;// armazena no endereo como anterior

            while(v[end][g]!=0){// tratamento de colisão
                g++;
            }
            v[end][g]= chave;
        }
        for(int n = 0; n<q_end; n++){// condições do print, for da linha
            if(n != 0){// pula linha sempre q for diferente do inicio

                printf("\n");

            }

            printf("%d", n);

            for(int m = 0; m<q_chaves; m++){// for da coluna

                if (v[n][m] != 0){ /* printa isso se existir um 
                        valor na posião da matriz*/

                    printf(" -> %d", v[n][m]);
                }

                else{

                    printf(" -> \\");// printa / se for vazio
                    if(n == q_end - 1 && i < q_teste-1){/*pula linha uma vez ao
                            final da matriz antes do ultimo teste*/

                        printf("\n");
                    }
                    break;
                }

            }
        }
        if(i < q_teste-1){/*pula linha uma vez antes do ultimo teste*/

            printf("\n");
        }
    }//fecha o for dos testes
    return 0;
}
