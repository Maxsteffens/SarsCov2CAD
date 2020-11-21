# SarsCov2CAD
Programa de cadastro de pacientes do Covid19 Trabalho escrito em C para a faculdade UNIP PIMiV 2020

Multiplataforma.
O programa SarsCov2CAD é um programa multiplataforma que permite agilizar o controle e monitoramento de pacientes diagnosticados com vírus SarsCov2CAD, através de um cadastro completo com filtragem por comorbidades e geração de relatórios diário, com dados de controle para o sistema de monitoramento. 
O programa foi totalmente desenvolvido em C  que é uma linguagem procedural de médio nível e muito portátil que permite ser compilado para diversos  sistema operacionais linux e windows 

Visual Retrô 
Utilizando as funções do ANSI ele foi desenvolvido para funcionar em terminais de sistema padrão com 24 linhas por 80 colunas e sem a necessidade do uso de dispositivo apontador.

Instalação
O SarsCov2CAD é um programas idealizado para ser utilizado por usuário  e de uso local pode ser instalado no seu disco rígido  ou ou em um em até um pendrive, todos os arquivos necessários estão na mesma pasta. 
No ambiente windows o executável deve ser instalado em uma única  pasta exclusiva, nesta pasta também  serão criados os arquivos de relatórios. 
No linux pode ser instalado em uma pasta exclusiva dentro do home e executado com o comando ./sarcov2cad

Operação
Para ter total acesso às funcionalidades do SarsCov2CAD é necessário efetuar o login. 
Usuário: < admin>
Senha :   <unip>
Na tela inicial digite 1 seguido de <enter> para acessar o menu principal ou 0 seguido de <enter> para sair

Menu Principal:
Para ter acesso às opções do menu do  você vai precisar unicamente teclar o número digitado e <enter>

Listagem de registros:
Aqui você tem acesso aos registros cadastrados

Encontrar Registros:
Digite o número do registro para visualizar os dados integrais do paciente

Registrar Pacientes:
Tela de registro de pacientes, com todos os campos necessários para um bom monitoramento do paciente infectado, incluindo a data da infecção e as comorbidades  que devem ser inseridas somando os números das comorbidades .

Relatório SUS:
Aqui são gerados os relatórios  dos CEP dos pacientes de forma incremental e diária. são criados dois arquivos em formatos diferentes em um em texto sem formatação e um em csv.   O arquivo de  texto tem esta estrutura.
|CPF: número| IDADE: xx| Contágio  dd/mm/aaaa |Asma.(  )|Diab.(  )|HiperT.(   )|Outros( )|+De 64(  )|CEP: xx.xxx-xx
Os relatórios de CEP em csv tem seus campos separados por (;) e são facilmente convertidos em planilhas como a do exemplo  .

Para compilar no terminal do Linux utilize o  GCC
linha de comando ~$ GCC ~$ gcc -std=c99 sarcov2cad.c -o sarcov2cad.o 
Para executar ./sarscov2cad 
