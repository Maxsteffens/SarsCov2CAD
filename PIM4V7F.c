#include <stdio.h>
#include <stdlib.h>
#include <string.h>  /// operlao strings
#include <locale.h> //// acentuaçõ
//#include <ncurses.h> /// movimentos
//#include <unistd.h> /// movimentos
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */

struct CADUNIC
{
    char VCPF[12];
    int VIdade;
    char VNome[31]; 
    char VTel[13];
    char VCel[14];
    char VEmail[41];
    int VComorb;
    char VCEP[9];
    char VEstado[3];
    char VCidade[41];
    char VBairro[20];
    char VRua[31];
    char VCompl[29];
    int VDataNasc;
    int Vano;
    int Vmes;
    int Vdia;
    int Cano;
    int Cmes;
    int Cdia;
    int Vnumero;
       
 };
///// strcpy tem um Bug que nao coloca null nom final do arquivo \0 por isto os campos char ficaram com um caratere a a mais
//// subrotinas
    int menu();
	void cadastra(struct CADUNIC[], int);
    void listagem(struct CADUNIC[], int);
    void localiza(struct CADUNIC[], int, int);///Localizar registro especifico
    void relatorio(struct CADUNIC list[80], int s);//relatoriosCEP
    void limpa_buffer();
    void coordenadas (int LINHA, int COLUNA); //// movimentação tela 24 linhas e 80 colunas ANSI
    void limpalinha (); //// limpa linha de texto ANSI
    void limpa();/// limpa tela com ANSI
    void telacadastro();// tela de cadastro
    void telaBorda();
    void loguin();/// eu sei  que é login mas melhor diferenciar
    void Tempo();// le a hora e data sistema 
    int Idade();//calcula idade
    void saida();//
//Variaveis globais
    char str[80]="CADUNICO.txt",c;
    int i=1;
    int idadeP; //idade paciente 
    int Gano;
    int Gmes;
    int Gdia;
    char TEMPO[10];

int main()
{
  setlocale(LC_ALL, "Portuguese");
int MENUHome;
loguin();
// SubRotina tela inicio//////////////////////////////////

limpa();   ///system("clear");//system("cls"); ROTINA DE LIMPEZA DE TELA linux clear, win csl
telaBorda();
        coordenadas(10,10);
printf(" ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        coordenadas(11,10);
printf(" ██░▄▄▄░█░▄▄▀█░▄▄▀█░▄▄██░▄▄▀█▀▄▄▀█▀███▀█░▄░███░▄▄▀█░▄▄▀██░▄▄▀█");
        coordenadas(12,10);
printf(" ██▄▄▄▀▀█░▀▀░█░▀▀▄█▄▄▀██░████░██░██░▀░███▀▄███░████░▀▀░██░██░█");
        coordenadas(13,10);
printf(" ██░▀▀▀░█▄██▄█▄█▄▄█▄▄▄██░▀▀▄██▄▄████▄███░▀▀███░▀▀▄█░██░██░▀▀░█");
        coordenadas(14,10);
printf(" ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀");
 

do
    {
        coordenadas(2,70);
        Tempo();
        coordenadas(20,20);
        printf("Presione 1 menu principal.");
        coordenadas(21,20);
        printf("Presione 0 para sair do SarsCov2CAD.");
        coordenadas(22,20);
        printf("Escolha entre(0-1) : ");
        scanf("%d", &MENUHome);
        switch (MENUHome)
        {
            case 1:
                limpa_buffer();//limpeza de lixo do buffer teclado
                menu();
                break;
            case 0:
                limpa();        //system("clear");//system("cls"); 
                exit(0);
                break;
           
        }        
    }
    while (MENUHome != 0);

    return 0;                                   

}

// SubRotina cadastra//////////////////////////////////
void cadastra(struct CADUNIC list[80], int s)
{
int ESCOLHA; 
int num;
int bin[5]; // 5bits , numero de comorbidades
int aux;        
 CADASTRO:do
    {  
        char sFrase [100]; //contagem caracters
        int  iTamanho;/// verifica tamanho
        int T; // variavel local do contador de registros conta ate o final
        char temp[100];///limpa lixo
        int LComorb;///variavel local de comorbidade
limpa();        //system("clear");//system("cls"); 
        telacadastro(); ///telacadastro
        list[i].Vnumero = i;
        //fflush(stdin);
        coordenadas(3,45);
        printf(" %d", i);

/////////////////teste conta caractes VNome
NOME:  
        coordenadas(5,18);
        limpa_buffer();///////////////limpeza de lixo do buffer teclado
        scanf("%[a-zA-Z ]",sFrase);
        iTamanho = strlen(sFrase);
            if (iTamanho >=  31 || iTamanho <  5)
            {
                coordenadas(21,5); 
                printf("Limite de 30 caracteres %d", iTamanho);
                telacadastro(); ///telacadastro
                goto NOME;
             }
        
        strcpy(list[i].VNome , sFrase);
        coordenadas(20,16);



///////////////////////////////////////////////// CPF
CPF:    
        coordenadas(5,57);
        limpa_buffer();//limpeza de lixo do buffer teclado
        scanf("%[0-9]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho !=  11)
            {      
                  coordenadas(21,5);                    
                   printf("CPF invalido  %d", iTamanho);
        telacadastro(); ///telacadastro
                  goto CPF;
             }
      
        coordenadas(20,5);
        strcpy(list[i].VCPF , sFrase);
        void limpalinha ();

 


////////////////////////////////////EMAIL

       
EMAIL:   
        coordenadas(7,11); 
        limpa_buffer();//limpeza de lixo do buffer teclado
        scanf("%[a-zA-Z0-9@.]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho >=  41 || iTamanho <  10)
            {
                coordenadas(20,5); 
                printf("Limite de 40 caracteres %d", iTamanho);   
             goto EMAIL;
             }
        coordenadas(20,5);
        void limpalinha ();
        ///printf("DEBUG  %s\n", sFrase);////////////// DEBUG REMOVER APOS CERTEZA
        strcpy(list[i].VEmail , sFrase);

////////////////////////////////////////////// data Contagio
CONTAGIO:        
        limpa_buffer();//limpeza de lixo do buffer teclado
        coordenadas(7,62);
        Idade();
        list[i].Cdia = Gdia;
        list[i].Cmes = Gmes;        
        list[i].Cano = Gano;
        if (idadeP >  0 || idadeP < -1)
            {
                 goto CONTAGIO;
             }

/////////////// ////////////////////////////////// VCel

CELULAR:limpa_buffer();////////limpeza de lixo do buffer teclado
        coordenadas(9,21);    
        
        scanf("%[0-9()]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho >=  14 || iTamanho <  12)
            {   
                 goto CELULAR;
             }
        coordenadas(20,5);
        void limpalinha ();
        strcpy(list[i].VCel , sFrase);
/////////////// ////////////////////////////////// VTel 

TELEFONE:    
        coordenadas(9,67); 
        limpa_buffer();//limpeza de lixo do buffer teclado
        scanf("%[0-9()]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho >=  13)
            {   
                 goto TELEFONE;
             }
        coordenadas(20,10);
        void limpalinha ();
        strcpy(list[i].VTel , sFrase);
     
///////////////////////////////////////////Logradouro 

LOGRADOURO: 
        coordenadas(11,15);
        limpa_buffer();//limpeza de lixo do buffer teclado
        scanf("%[a-zA-Z ]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho >=  31 || iTamanho <  5)
            {
                goto LOGRADOURO; 
             }
        coordenadas(20,5);
        strcpy(list[i].VRua , sFrase);

/////////////////teste conta caractes VBairro

BAIRRO:   
        coordenadas(11,60);
        limpa_buffer();//limpeza de lixo do buffer teclado
        scanf("%[a-zA-Z ]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho >=  20 || iTamanho <  5)
             {
             goto BAIRRO;
             }
        coordenadas(20,10);
        strcpy(list[i].VBairro , sFrase);

///////////////////////////////////VCidade

CIDADE:
        coordenadas(13,11);
        limpa_buffer();//////////limpeza de lixo do buffer teclado
        scanf("%[a-zA-Z ]", sFrase);///scanf("%30[a-zãõéáíóA-ZÃÕÉÍÓÚ ]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho >=  41 || iTamanho <  5)
             {
                //limpa_buffer();
                goto CIDADE;
             }
        coordenadas(20,5);
        strcpy(list[i].VCidade , sFrase);
///////////////////////////VEstado


ESTADO: 
        coordenadas(13,63);
        limpa_buffer();//limpeza de lixo do buffer teclado
        scanf("%[ABCDEFGIJLMNOPRST]", sFrase);//scanf("%2[A-Z]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho != 2)
            {
                coordenadas(20,5);
                printf("Só maiusculas  %d ", iTamanho);
                goto ESTADO;
             }
        coordenadas(20,5);
        void limpalinha ();
        strcpy(list[i].VEstado , sFrase);

////////////////////////////////////////////////////// Complemento

COMPLEMENTO:
        coordenadas(15,25);
        limpa_buffer();//////////limpeza de lixo do buffer teclado    
        scanf("%[a-zA-Z0-9 ]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho >=  29 || iTamanho <  1)
            {
             goto COMPLEMENTO;
             }
        coordenadas(20,5);
        void limpalinha ();
        strcpy(list[i].VCompl , sFrase);


/////////////////////////////CEP ///////////// 

CEP:
        coordenadas(15,57);    
        limpa_buffer();//////////limpeza de lixo do buffer teclado
        scanf("%[0-9]", sFrase);
        iTamanho = strlen(sFrase);
        if (iTamanho !=  8)
            {
                 goto CEP;
             }
        coordenadas(20,5);
        strcpy(list[i].VCEP, sFrase); 
        limpa_buffer();//limpeza de lixo do buffer teclado
////////////////////////////////////////////// data nascimento 
IDADE:
        coordenadas(17,21);
        
        Idade();
        limpa_buffer();//limpeza de lixo do buffer teclado
        coordenadas(17,46);
        //void limpalinha ();
        printf("%d", idadeP);////////////// IDADE paciente
        list[i].Vdia = Gdia;
        list[i].Vmes = Gmes;        
        list[i].Vano = Gano;
        if (idadeP >=  110)
            {
                 goto IDADE;
             }
        coordenadas(17,46);
        list[i].VIdade  = idadeP;      //printf atribui valor a VIdade;
        
/////////////////////////////////////////////////////////// comorbidades
COMORBIDADES:
        coordenadas(19,20);
        //limpa_buffer();//limpeza de lixo do buffer teclado
        printf("SOMAR OS CODIGOS DAS COMORBIDADES");
        coordenadas(20,10);
        printf("Asmáticos=1 Diabéticos=2 Hipertensos=4 Outros=8");
        coordenadas(17,66);
        scanf("%d", &LComorb);
        if (idadeP > 64)
            {
            LComorb = LComorb + 16;///para ficar mais facil para o usuario idade de risco conta como 16 mais os valores das comorbidades maximo 31
            }
        


            if (LComorb >=  31)
                {
                 //printf("DEBUG  %d\n", iTamanho);////////////// DEBUG REMOVER APOS CERTEZA
                 goto COMORBIDADES;
                }
        list[i].VComorb = LComorb;
        num = LComorb;
        for (aux = 4; aux >= 0; aux--)//// rotina conversao dec binario das comorbidades
           {
           if (num % 2 == 0)
             bin[aux] = 0;
             else
              bin[aux] = 1;
              num = num / 2;
             }
        coordenadas(20,10);
        printf("Asmático(%d) Diabético(%d) Hipertenso(%d) Outros(%d) +64 anos(%d)", bin[4], bin[3], bin[2], bin[1], bin[0]);
   
        limpa_buffer();//limpeza de lixo do buffer teclado
//2 Asmáticos 4 Diabéticos 8 Hipertensos 16 Obesidade

        //printf("==========================================================\n");

//////////////// impressao arquivo CADUNICO.txt //////////////////////////////////

       FILE* p = fopen("CADUNICO.txt", "a"); /// inicia CADUNICO.txt 
                if (!(p = fopen("CADUNICO.txt","a")))  /* Caso ocorra algum erro na abertura do arquivo..*/ 
  	        {                           /* o programa aborta automaticamente */
          		 FILE* p = fopen("CADUNICO.txt", "w"); /// inicia CADUNICO.txt 
         		
         	}   
        fprintf(p, "\r|====================================REGISTRO: %d ====================================|", list[i].Vnumero);
        fprintf(p, "\r|Nome: %s |CPF: %s|", list[i].VNome, list[i].VCPF);//// retorno de carro 
        fprintf(p, "\r|E-mail: %s |Data Nascimento: %d/%d/%d|", list[i].VEmail,  list[i].Vdia, list[i].Vmes,list[i].Vano);//// retorno de carro , list[i]VDataNasc)
        fprintf(p, "\r|Estado: %s| Cidade: %s| CEP: %s|" , list[i].VEstado, list[i].VCidade, list[i].VCEP);///// 
        fprintf(p, "\r|Bairro: %s|Logradouro: %s |Numero/complemento: %s|", list[i].VBairro, list[i].VRua, list[i].VCompl);//// retorno de carro
        fprintf(p, "\r|Celular: %s|Telefone: %s|", list[i].VCel, list[i].VTel);//// retorno de carro 
        fprintf(p, "\r|Idade: %d|Comorbidades %d|Contagio: %d/%d/%d|", list[i].VIdade, list[i].VComorb,  list[i].Cdia, list[i].Cmes,list[i].Cano);//// retorno de carro 
        fclose(p);/// fecha arquivo CADUNICO.txt

//////////////// fim impressao arquivo CADUNICO.txt //////////////////////////////////
        coordenadas(22,10);
        printf("INCLUIR MAIS UM PACIENTE? 1 para sim 2 para não ");
        coordenadas(22,58);
        i++;/// incrementa o numero de pedido, deve estat aqui para incrementar mesmo saindo por outra opção do case
         scanf("%d", &ESCOLHA);
        switch (ESCOLHA)
        {
            case 1:
                goto CADASTRO;
                break;
            case '2':
                menu();
                break;
                
         }        
    }
    while (ESCOLHA == 1);
    return;
}
//////////////// SubRotina listagem de regitros//////////////////////////////////
void listagem(struct CADUNIC list[80], int s)  
{
    ///system("clear");//system("cls");
    limpa();        //system("clear");//system("cls"); via ANSI
    telaBorda();
    int tL=1;//pula linhas
    int iL; //variavel de contagem
    char temp;
    for (iL = 1; iL <= i-1;  iL++)
    {
        tL= tL+4;
        //printf("|%d        |%s |%s \n", list[iL].Vnumero, list[iL].VNome, list[iL].VCEP);
        coordenadas(tL-3,2);
        printf("|Registro: %d|Nome: %s |CPF: %s|", list[iL].Vnumero, list[iL].VNome, list[iL].VCPF);//// retorno de carro
        coordenadas(tL-2,2); 
        printf("|Estado: %s| Cidade: %s| CEP: %s|" , list[iL].VEstado, list[iL].VCidade, list[iL].VCEP);///// 
        coordenadas(tL-1,2);
        printf("|Bairro: %s|Rua: %s |Numero/complemento: %s", list[iL].VBairro, list[iL].VRua, list[iL].VCompl);//// retorno de carro 
        coordenadas(tL,2);
       //printf("|Nasc: %d/%d/%d |Idade: %d|Comorbidades %d", list[iL].Vdia, list[iL].Vmes,list[iL].Vano, list[iL].VIdade, list[iL].VComorb);//// retorno de carro 
        printf("|Nasc: %d/%d/%d |Idade: %d|Contagio: %d/%d/%d|Comorbidades %d", list[iL].Vdia, list[iL].Vmes,list[iL].Vano, list[iL].VIdade, list[iL].Cdia, list[iL].Cmes,list[iL].Cano, list[iL].VComorb);//// retorno de carro 
        
    } 
        
                getchar();
                coordenadas(tL+6,36);
                printf("<ENTER>");
    	        scanf("%c",&temp); // temp statement to clear buffer   
return;
}
//////////////// SubRotina listagem por CEP//////////////////////////////////
void relatorio(struct CADUNIC list[80], int s)  
{

///system("clear");//system("cls");
    limpa();        //system("clear");//system("cls"); via ANSI
    telaBorda();
    
    int iL; //variavel de contagem
    int tL=2;//pula linhas
    char temp;
    char CEParq[40];
   int num;
   int bin[5]; // 5 , numero de comorbidades
   int aux;

   coordenadas(2,6);
    printf("Asmáticos=1 Diabéticos=2 Hipertensos=4 Outros=8 +de 64 anos=16");
    for (iL = 1; iL <= i-1;  iL++)
    {
       num = list[iL].VComorb;
            for (aux = 4; aux >= 0; aux--)
                {
                if (num % 2 == 0)
                bin[aux] = 0;
                else
                bin[aux] = 1;
                num = num / 2;
                }
        tL= tL+3;
        coordenadas(tL-1,2);
        printf("|CPF:%s| IDADE:  %d| CEP: %s|Contagio: %d/%d/%d|",  list[iL].VCPF, list[iL].VIdade, list[iL].VCEP,  list[iL].Cdia, list[iL].Cmes,list[iL].Cano);
        coordenadas(tL,2);
        printf("| Asmatico. (%d) |Diabetico(%d)|Hiperenso. (%d)|Outros(%d)|+ De 64(%d)", bin[4], bin[3], bin[2], bin[1], bin[0]);
    }
///////
                        

    //////////////// impressao arquivo CEP<data>.txt //////////////////////////////////
                sprintf (CEParq, "CEP_%s.txt", TEMPO);////inclui data no nome arquivo                  
                FILE* p = fopen(CEParq, "a"); /// inicia CADUNICO.txt 
          
                    for (iL = 1; iL <= i-1;  iL++)
                         {    
                        if (list[iL].VComorb > 0 )
                             {
                               num = list[iL].VComorb;
                                for (aux = 4; aux >= 0; aux--)
                                    {
                                    if (num % 2 == 0)
                                    bin[aux] = 0;
                                    else
                                    bin[aux] = 1;
                                    num = num / 2;
                                    }

                              fprintf(p, "\r|CPF: %s| IDADE: %d|Contagio: %d/%d/%d| Asma.(%d)|Diab.(%d)|HiperT.(%d)|Outros(%d)|+De 64(%d)|CEP: %s|",  list[iL].VCPF, list[iL].VIdade,  list[iL].Cdia, list[iL].Cmes,list[iL].Cano, bin[4], bin[3], bin[2], bin[1], bin[0], list[iL].VCEP);
                              }
                         }
                         fclose(p);/// fecha arquivo CEP<data>.txt
   //////////////// FIM impressao arquivo CEP.txt //////////////////////////////////
             

    //////////////// impressao arquivo CEP.csv //////////////////////////////////
                    sprintf (CEParq, "CEP_%s.csv", TEMPO);////inclui data no nome arquivo                
                    FILE* P = fopen(CEParq, "a"); /// inicia CEP.csv 
                  
                     fprintf(P, "CPF; IDADE;CONTAGIO; Asmatico; Diabetico; Hipertenso; Outros; Mais De 64; CEP \r"); ////cabeçalho tem de vir antes do Lop for
                     for (iL = 1; iL <= i-1;  iL++)
                       { 
                         if (list[iL].VComorb > 0 )
                              {  
                                num = list[iL].VComorb;
                                for (aux = 4; aux >= 0; aux--)
                                    {
                                    if (num % 2 == 0)
                                    bin[aux] = 0;
                                    else
                                    bin[aux] = 1;
                                    num = num / 2;
                                    }


                                fprintf(P, " %s; %d; %d/%d/%d; %d; %d; %d; %d; %d; %s \r",  list[iL].VCPF, list[iL].VIdade, list[iL].Cdia, list[iL].Cmes,list[iL].Cano, bin[4], bin[3], bin[2], bin[1], bin[0], list[iL].VCEP);                           
                               }   
                        }
                        fclose(P);/// fecha arquivo CEP.csv
   //////////////// FIM impressao arquivo CEP.txt //////////////////////////////////
                   
                    

                getchar();
                coordenadas(tL+2,36);
                printf("<ENTER>");
    	        scanf("%c",&temp); // temp statement to clear buffer   
return;
}

/////////////////////////// SubRotina localiza//////////////////////////////////
void localiza(struct CADUNIC list[80], int s, int numero)
{
    //system("clear");//system("cls"); ROTINA DE LIMPEZA DE TELA linux clear, win csl
    int iL;
    int tL;
    int LComorb;
    char temp;
    limpa();        //system("clear");//system("cls");
 telacadastro();
    for (iL = 1; iL <= i; iL++)
    {
        if (list[iL].Vnumero == numero)
        {
  coordenadas(3,45);
        printf("%d", list[iL].Vnumero);//// registro 
        coordenadas(5,18);
        printf("%s", list[iL].VNome);//// nome 
        coordenadas(5,57);
        printf("%s", list[iL].VCPF);//// cpf 
        coordenadas(7,11); 
        printf("%s", list[iL].VEmail);//// email
        coordenadas(9,21);   
        printf("%s" , list[iL].VCel);///// Celular
        coordenadas(9,67); 
        printf("%s" , list[iL].VTel);///// Telefone
        coordenadas(13,63); 
        printf("%s" , list[iL].VEstado);///// ESTADO
        coordenadas(13,11); 
        printf("%s" , list[iL].VCidade);///// CIDADE
        coordenadas(15,57);   
        printf("%s" , list[iL].VCEP);///// CEP
        coordenadas(11,15);
        printf("%s", list[iL].VRua);//// rua
        coordenadas(11,60);
        printf("%s", list[iL].VBairro);//// baiiro
        coordenadas(15,25);
        printf("%s", list[iL].VCompl);//// complmento 
        coordenadas(17,21); 
        printf("%d/%d/%d", list[iL].Vdia, list[iL].Vmes,list[iL].Vano);//// idade data 
        coordenadas(7,62); 
        printf("%d/%d/%d", list[iL].Cdia, list[iL].Cmes,list[iL].Cano);//// contagio 
        coordenadas(17,46);
        printf("%d", list[iL].VIdade);//// idade
        coordenadas(17,66); 
        printf("%d", list[iL].VComorb);//// comorbidades        
         } 
     }

      coordenadas(20,6);
      printf("Asmáticos=1 Diabéticos=2 Hipertensos=4 Outros=8 Mais de 64 anos=16");
      //printf("Fim da pequisa");
      getchar();
      coordenadas(22,40);    
      scanf("<ENTER> %c",&temp); // temp statement to clear buffer   
return ;
}

// SubRotina menu//////////////////////////////////
int menu()

{
    struct CADUNIC data[20];
    int n = 20; /// numeto toal de registros
    int choice; //escolha do menu de cadastrar mais pacientes
    int numero; /// numeto toal de registros
    int T;

    ///system("clear");//system("cls"); ROTINA DE LIMPEZA DE TELA linux clear, win csl
    limpa();        //system("clear");//system("cls");
    telaBorda();


    do
    {
        limpa();        //system("clear");//system("cls");
        telaBorda();
        coordenadas(2,70);
        Tempo();

coordenadas(7,23);
printf("╔═══════════════════════════════╗");
coordenadas(8,23);
printf("║        Menu Principal         ║");
coordenadas(9,23);
printf("╠═══════════════════════════════╣");
///╠╔═╗╔╗  ╚╗╔╝║║═╦╦╦╔╗ ╔╝╚╗╚╣║║║║╔╣

            for (T = 10; T <= 20; T++)
                {
                coordenadas(T,23);
                 printf("║");// esquerda
                coordenadas(T,55);
                 printf("║");// direita
                } 

        coordenadas(19,23);
printf("╠═══════════════════════════════╣"); 
        coordenadas(21,23);
printf("╚═══════════════════════════════╝");

        coordenadas(10,25);
        printf("(1) Listagem de Registros.");
        coordenadas(12,25);
        printf("(2) Encontrar um Registro.");
        coordenadas(14,25);
        printf("(3) Registrar Pacientes.");
        coordenadas(16,25); 
        printf("(4) Relatorio SUS.");
        coordenadas(18,25);
        printf("(5) Deslogar Usuario.");
        coordenadas(20,25);
        printf("   Escolha entre(0-5):");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                listagem(data, n);
                break;
            case 2:
        coordenadas(20,25);
                printf("                        ");
        coordenadas(20,25);
                printf("    Numero do registro:");
                scanf("%d", &numero);
                localiza(data, n, numero);
                break;
            case 3:
                cadastra(data, n);
                break;
            case 4:
                relatorio(data, n);
                break;
            case 5:
                main(n);
                //return 0;
            break;
           case 6:
                saida();
                //return 0;
            break;
        }        
    }
    while (choice != 0);

    return 0;
}
/////////////////Funcao limpa linha

void limpa_buffer()
    {
    scanf ("%*[^\n]");
    scanf ("%*c");
    }

/////////////////Funcao limpa tela

void limpa()
{
printf("\033[2J"); 
return;
}
//* Funcao: Posiciona Cursor /

void coordenadas(int LINHA, int COLUNA)
{
printf("\033[%d;%dH", LINHA, COLUNA);
return;
}
//Funcao: Limpa Linha a partir da posicao do cursor

void limpalinha()
{
printf("\033[k");
return;
}

void Tempo()/////////////////////////relogio do PC
{
  time_t rawtime;
  struct tm * timeinfo;
    char Hdia [3];
    char Hmes [3];
    char Hano [5];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (Hdia,3,"%d",timeinfo);
    strftime (Hmes,3,"%m",timeinfo); 
    strftime (Hano,5,"%Y",timeinfo);
printf("%s %s %s",Hdia,Hmes,Hano);
  //puts (buffer);
sprintf(TEMPO,"%s_%s_%s",Hdia,Hmes,Hano); 
  return;
}

int Idade()/////////////////////// calculo idade
    {
int ano;
int mes;
int dia;
    time_t now = time(0);
    struct tm *t = gmtime(&now);
    dia = t->tm_mday;
      mes = t->tm_mon;
        ano = t->tm_year+1900;


        int checa = scanf("%d/%d/%d", &Gdia, &Gmes, &Gano);
    if (checa!=3 )
       {
        //printf("Somente numeros sua anta\n");
            return 0;
        }  
        else if (Gmes > 12 || Gdia > 31)
                { 
                 //printf("Somente numeros  na faixa correta sua anta\n");
                 }
        else    {
                idadeP = ano - Gano;
                if (Gmes  > mes)
                            {
                             idadeP--;
                             }
                            else if (Gmes == mes)
                                      {
                                        if (Gdia > dia)
                                                {
                                                idadeP--;
                                                }
                             }
                 }
    return 0;
}




void telacadastro()
{
coordenadas(1,0);
//////("0123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789\n"); //regua
printf("████████████████████████████████████████████████████████████████████████████████\n"); //1
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█");//
coordenadas(3,0);
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░REGISTRO Nº");    
coordenadas(3,44);
printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█"); //3
coordenadas(4,0);
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█");
coordenadas(5,0);
printf("█░░NOME PACIENTE:");                              
coordenadas(5,48);
printf("║░░░░CPF:");           
coordenadas(5,68);
printf("║░░░░░░░░░░░█"); //5
coordenadas(6,0);
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
coordenadas(7,0);
printf("█░░E-MAIL:");//7 
coordenadas(7,52);                                        
                                                   printf("║CONTAGIO:DD/MM/AAAA║░░░░░░░█");//7 
//////("01234567890123456789012345678901234567890123456789012345678901234567890123456789\n"); //regua
coordenadas(8,0);
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█");
coordenadas(9,0);
printf("█░░TELEFONE CELULAR:(xx)         ║░░░░░░░░░░░░░░░░░░TELEFONE FIXO:(XX)        ║█\n");//9  
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n"); 
printf("█░░LOGRADOURO:rua avenida...                       ║BAIRRO:                   ║█\n");//11 
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n"); 
printf("█░░CIDADE:                                         ║ESCTADO  :SC░░░░░░░░░░░░░░░█\n");//13
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n"); 
printf("█░░NÚMERO & COMPLEMENTO:                           ║CEP:        ║░░░░░░░░░░░░░░█\n");//15
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
printf("█░░DATA NASCIMENTO: DD/MM/AAAA║░░░░IDADE:      ║░░░░COMORBIDADES:  ║░░░░░░░░░░░█\n");//17 
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");//19
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");//21
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");//22 
printf("█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");//23
printf("████████████████████████████████████████████████████████████████████████████████");//24
//////("01234567890123456789012345678901234567890123456789012345678901234567890123456789\n"); //regua
return;

}
void telaBorda()
{
int T;
coordenadas(0,0);
printf("████████████████████████████████████████████████████████████████████████████████"); //1
            for (T = 1; T <= 23; T++)
                {
                coordenadas(T,0);
                 printf("█");// esquerda
                coordenadas(T,80);
                 printf("█");// direita
                } 
printf("████████████████████████████████████████████████████████████████████████████████");//24

return;
}
void loguin()
{
        limpa(); 
        telaBorda();
        //coordenadas(10,10);
        char username[15]; 
        char password[12];
        char temp[20]= "ai";
        coordenadas(10,15);    
        printf("Enter your username:"); 
        scanf("%s",username); 
        coordenadas(12,15);      
        printf("Enter your password:"); 
        scanf("%s",password); 

        //coordenadas(14,15);      
        //printf("mesagem %s", temp); 
     
        if(strcmp(username,"admin")==0)
        { 
            if(strcmp(password,"unip")==0)
                { 
                //printf("\nnem aparece"); 
                }
                else
                    { 
                    
                    printf("Senha ou usuario errado");
                     loguin();            
                    }
        }
        else
            { 
            //temp[20] = "Senha ou usuario errado";
            loguin(); 
            } 
      
        return; 
     
 } 
void saida()
{
 limpa(); 
int raiz;
int T=8;
do
    {
coordenadas(8,10); 
printf("< EQUIPE 6!!!!! >");
coordenadas(9,10); 
printf(" ---------------");
printf("   \\             ");
coordenadas(10,10); 
printf("    \\            ");
coordenadas(11,10); 
printf("        .--.    ");
coordenadas(12,10); 
printf("       |o_o |   ");
coordenadas(13,10); 
printf("       |:_/ |   ");
coordenadas(14,10); 
printf("      //   \\ \\  ");
coordenadas(15,10); 
printf("     (|     | ) ");
coordenadas(16,10); 
printf("    /'\\_   _/`\\ ");
coordenadas(17,10); 
printf("    \\___)=(___/ ");

            //for (T = 1; T <= 13; T++)
                //{
                coordenadas(8,40);
                printf("\033[41m MAXIMILIAM STEFFENS 41\033[m ");
                coordenadas(8+1,40);
                 printf("\033[42m MÔNICA CAMPANELLA\033[m ");
                coordenadas(8+2,40);
                 printf("\033[43m PATRICK DA SILVA CABRAL\033[m ");
                coordenadas(8+3,40);
                 printf("\033[44m CARLOS OLIVEIRA\033[m ");
                coordenadas(8+4,40);
                 printf("\033[45m WAGNER EDMAR ARAUJO CUNHA\033[m ");
                coordenadas(8+5,40);
                 printf("\033[46m RENATO FRANCISCO DOURADO\033[m ");
               //} 


    coordenadas(19,33);
    printf("SAIR");
    scanf("\n 1 menu, 0 exit %d", &raiz);

        switch (raiz)
        {
            case 1:
               //limpa_buffer();//limpeza de lixo do buffer teclado
                menu();
                break;
            case 0:
                exit(0);
                break;           
         }        
}
    while (raiz != 0);
    return;
}


