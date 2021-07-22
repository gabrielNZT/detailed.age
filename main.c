#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// objetivo desse programa é dizer detalhadamente a idade de algo ou alguem


int function_bix(int ano_teste){
// saber se o ano é bissexto 'ano bissexto é multiplo de 4, mas não de 100, exceto os multiplos de 400'
// a function retarna 1 se for bissexto e 0 se não for.
int binario;
int test1;
int test2;
int test3;
int resultado;

test3 = ano_teste % 400;

if(test3 == 0){
    resultado = 1;
    return resultado;
}

else if(test3 > 0){
    test2 = ano_teste % 100;
    test1 = ano_teste % 4;

    if(test1 == 0 && test2 > 0){
        resultado = 1;
        return resultado;
    }
}
else{
    resultado = 0;
    return resultado;
}
}

int function_mes(int byn, int mes_test){
// mes_test é o mes que deseja se saber o
// achar quantos dias tem aquele mes
// byn representa o binario para positvo ou negativo em relação ao ano bissexto
int dias[12];

dias[1] = 31;

if(byn = 1){
    dias[2] = 29;
}
else{
    dias[2] = 28;
}
 dias[3] = 31;
 dias[4] = 30;
 dias[5] = 31;
 dias[6] = 30;
 dias[7] = 31;
 dias[8] = 31;
 dias[9] = 30;
 dias[10] = 31;
 dias[11] = 30;
 dias[12] = 31;

 return dias[mes_test];
}

int main()
{
    char aux;
    char nome[100];
    int ano_nasc;
    int mes_nasc;
    int dia_nasc;
    int ano_atu;
    int mes_atu;
    int dia_atu;
    int anos_resp;
    int meses_resp;
    int dias_resp;
    int qt_dias; // quantidade de dias que o respectivo mês tem
    int answer_byn; // respota da function_bix para o ano
    int aux_num;// variavel para auxiliar na permutação de valores


 // COLETAR DADOS ATUAIS

 printf("informe o ano atual:\n");
 scanf("%d",&ano_atu);
 scanf("%c",&aux);
 system("cls");

 printf("Informe o mes atual:\n");
 scanf("%d",&mes_atu);

 system("cls");

 printf("Informe o dia atual:\n");
 scanf("%d",&dia_atu);
 scanf("%c",&aux);

 system("cls");

 printf("Informe o nome do que ou quem voce quer saber a idade detalhada:\n");
 fgets(nome,100,stdin);

 system("cls");

 // DADOS ANOS

for(int i=3;i>0;i--){ // o usuario terá 3 tentativas para digitar o valor correto
 // ano de nascimento não pode ser superior ao ano atual que no caso será considerado 2021
 printf("informe o ano de nascimento:\n");
 scanf("%d",&ano_nasc);
 scanf("%c",&aux);
 if(ano_atu >= ano_nasc){
    break;
 }

 if(ano_nasc > ano_atu){
    printf("error_01...\n");
    printf("Acho que alguem esta no futuro :3\n\n");
    printf("restam %d tentativas\n",i-1);
    // CASO O USUARIO EXTRAPOLE O NUMERO DE TENTATIVAS.
    if(i == 1){
        return 0;
    }
 }

 printf("Aperte enter para continuar");
 scanf("%c",&aux);

 system("cls");
}

 system("cls");

 answer_byn = function_bix(ano_nasc);

 // DADOS MESES

 for(int i=3;i>0;i--){ // o usuario terá 3 tentativas para digitar o valor correto
 // o mes de nascimento nao pode ser superior a 12 e nem inferior a 1.
 printf("Informe o mes de nascimento:\n");
 scanf("%d",&mes_nasc);
 scanf("%c",&aux);
 if(ano_atu > ano_nasc){
    break;
 }

 if(ano_atu == ano_nasc && mes_atu > mes_nasc){
    break;
 }

 if(ano_atu == ano_nasc && mes_nasc > mes_atu){
     // CASO O USUARIO DIGITE UMA DATA ATUAL MENOR
     printf("error_01...\n");
     printf("Acho que alguem esta no futuro :3\n\n");

     if(mes_nasc > 12 || mes_nasc < 1){
    printf("error_02...\n");
    printf("O mes de nascimento deve estar no intervalo de 1 até 12\n\n");
    // CASO O USUARIO EXTRAPOLE O NUMERO DE TENTATIVAS.
    if(i == 1){
        return 0;
    }
 }
    if(i == 1){
        return 0;
    }

 }

 printf("restam %d tentativas\n",i-1);

printf("Aperte enter para continuar");
scanf("%c",&aux);

system("cls");
}

system("cls");
 qt_dias = function_mes(answer_byn, mes_nasc);

 // DADOS DIAS

 for(int i=3;i>0;i--){ // o usuario terá 3 tentativas para digitar o valor correto
 // O dia de nascimento deve ser coerente com o mês de nascimento.
 printf("Informe o dia de nascimento:\n");
 scanf("%d",&dia_nasc);
 scanf("%c",&aux);
 if(mes_atu > mes_nasc || ano_atu > ano_nasc){
    break;
 }
 else if(mes_atu == mes_nasc && ano_atu == ano_nasc && dia_atu > dia_nasc){
    break;
 }

 else if(mes_atu == mes_nasc && ano_atu == ano_nasc && dia_nasc > dia_atu){
    printf("error_01...\n");
    printf("Acho que alguem esta no futuro:3");

     if(dia_nasc > qt_dias || dia_nasc < 1){
    printf("error_02...\n");
    printf("O dia de nascimento deve tá no intervalo de 1 até %d\n\n",qt_dias);
    printf("Restam %d tentativas\n",i-1);
    // CASO O USUARIO EXTRAPOLE O NUMERO DE TENTATIVAS.
    if(i == 1){
        return 0;
    }
 }
    if(i == 1){
        return 0;
    }
 }
 printf("Aperte enter para continuar");
 scanf("%c",&aux);

 system("cls");
}

system("cls");
 // CALCULOS PARA ACHAR A IDADE

 //calculos anos:
 if(ano_atu == ano_nasc){
    anos_resp = 0;
 }
 else if(mes_atu > mes_nasc){
   anos_resp = ano_atu - ano_nasc;
 }
 else if(mes_atu < mes_nasc){
    anos_resp = (ano_atu - ano_nasc) - 1;
 }

 // calculos meses:
 if(dia_atu == dia_nasc){
    meses_resp = mes_atu - mes_nasc;
    if(meses_resp < 0){
        meses_resp = meses_resp + 12;
    }
 }
 else if(dia_atu > dia_nasc){
    meses_resp = mes_atu - mes_nasc;
    if(meses_resp < 0){
        meses_resp = meses_resp + 12;
    }
 }
 else if(dia_atu < dia_nasc){
    meses_resp = (mes_atu - mes_nasc) - 1;
    if(meses_resp < 0){
        meses_resp = meses_resp + 12;
    }
 }

 // calculos dias:
 if(dia_atu > dia_nasc){
    dias_resp = dia_atu - dia_nasc;
 }
 else if(dia_atu < dia_nasc){
    answer_byn = function_bix(ano_atu);
    qt_dias = function_mes(answer_byn, mes_atu);
    dias_resp = (dia_atu + qt_dias) - dia_nasc;
 }

 puts(nome);
 printf("tem %d ANOS %d MESES %d DIAS\n\n", anos_resp, meses_resp, dias_resp);

 // QUANTO TEMPO FALTA PRO SEU NIVER:
 // para esse caso irei dar novos valores para as variaveis utilizadas anteriormente

ano_nasc = ano_atu;
aux_num = dia_atu;
dia_atu = dia_nasc;
dia_nasc = aux_num;
aux_num = mes_atu;
mes_atu = mes_nasc;
mes_nasc = aux_num;

 //calculos anos:
 if(ano_atu == ano_nasc){
    anos_resp = 0;
 }
 else if(mes_atu > mes_nasc){
   anos_resp = ano_atu - ano_nasc;
 }
 else if(mes_atu < mes_nasc){
    anos_resp = (ano_atu - ano_nasc) - 1;
 }

 // calculos meses:
 if(dia_atu == dia_nasc){
    meses_resp = mes_atu - mes_nasc;
    if(meses_resp < 0){
        meses_resp = meses_resp + 12;
    }
 }
 else if(dia_atu > dia_nasc){
    meses_resp = mes_atu - mes_nasc;
    if(meses_resp < 0){
        meses_resp = meses_resp + 12;
    }
 }
 else if(dia_atu < dia_nasc){
    meses_resp = (mes_atu - mes_nasc) - 1;
    if(meses_resp < 0){
        meses_resp = meses_resp + 12;
    }
 }

 // calculos dias:
 if(dia_atu > dia_nasc){
    dias_resp = dia_atu - dia_nasc;
 }
 else if(dia_atu < dia_nasc){
    answer_byn = function_bix(ano_atu);
    qt_dias = function_mes(answer_byn, mes_atu);
    dias_resp = (dia_atu + qt_dias) - dia_nasc;
 }

 printf("Faltam %d MESES e %d DIAS para o seu aniversario",meses_resp, dias_resp);

return 0;
}
