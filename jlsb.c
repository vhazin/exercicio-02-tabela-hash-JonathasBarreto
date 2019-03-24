#include <stdio.h>
typedef int hash;

hash main(void){
    hash q_testes, q_end, q_chaves, chave,  end, g;

    scanf("%d", &q_testes);

    for(hash i=0; i <= q_testes - 1; i++){
        scanf("%d %d", &q_end, &q_chaves);

        hash chaves_v[q_chaves], v[q_end][q_chaves];
        
        for (hash a = 0; a <= q_chaves - 1; a++){
            scanf("%d", &chave);
            chaves_v[a] = chave;
        }

        for(hash n = 0; n <= q_end - 1; n++){
            g = 0;
            
            for(int p = 0; p <= q_chaves - 1; p++){
                end = chaves_v[p] % q_end;
                
                if(end != n) v[n][g] = 0;
                    else v[n][g] = chaves_v[p];
                    
                g++;

            }
            
            if(n == 0) printf("%d -> ", n);
                else  printf("\n%d -> ", n);

            for(hash d = 0; d <= q_chaves - 1; d++){
                if(v[n][d]) printf("%d -> ", v[n][d]);

            }printf("\\");
            
            if (n==q_end-1 && i!=q_testes-1) printf("\n");
        }printf("\n");
    }
}
