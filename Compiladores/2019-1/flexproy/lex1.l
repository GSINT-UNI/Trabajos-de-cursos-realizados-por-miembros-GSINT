%{
/* Ejemplo para una pequeña calculadora que permite trabajar con numeros enteros y reales con las operacionesbásicas de suma, resta, producto, division y trigonometricas como el seno y el coseno */

#include <stdio.h>
#include <stdlib.h>
#include "bison1.tab.h"
int nlines=0;
%}

DIGITO [0-9]
ID [a-zA-Z][a-zA-Z0-9_]*

%%

{DIGITO}+("."{DIGITO}+)?  {//printf("Encontrado TKN_NUM: %f \n",atof(yytext));
			yylval.real=atof(yytext);
			return(TKN_NUM);}
"="                    {//printf("Encontrado TKN_ASIGN: %s \n",yytext);
			return(TKN_ASIGN);}
";"                    {//printf("Encontrado TKN_PTOCOMA: %s \n",yytext);
			return(TKN_PTOCOMA);}
"*"                    {//printf("Encontrado TKN_MULT: %s \n",yytext);
			return(TKN_MULT);}
"/"                    {//printf("Encontrado TKN_DIV: %s \n",yytext);
			return(TKN_DIV);}
"+"                    {//printf("Encontrado TKN_MAS: %s \n",yytext);
			return(TKN_MAS);}
"-"                    {//printf("Encontrado TKN_MENOS: %s \n",yytext);
			return(TKN_MENOS);}
"("                    {//printf("Encontrado TKN_PAA: %s \n",yytext);
			return(TKN_PAA);}
")"                    {//printf("Encontrado TKN_PAC: %s \n",yytext);
			return(TKN_PAC);}
"cos"                  {//printf("Encontrado TKN_COS: %s \n",yytext);
			return(TKN_COS);}
"sen"                  {//printf("Encontrado TKN_SEN: %s \n",yytext); 
			return(TKN_SEN);}
{ID}                   {//printf("Encontrado TKN_ID: %s \n",yytext);
			return(TKN_ID);}
"\n"                   {nlines++;}
. 


%%

/************
void main(int argc,char **argv){
if (argc>1)
	yyin=fopen(argv[1],"rt");
else
	yyin=stdin;
yylex();
printf("\nNumerolineas analizadas: %d\n", nlines);
}
*************/

