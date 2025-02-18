%{
//incluimos librerias y cabeceras
#include<stdio.h>
#include<string.h>
#include<math.h>
char lexema[64];
void yyerror(char *);
%}

%token ID NUM POT RAIZ SI ENTONCES SINO PARA MIENTRAS HACER ASCII

%%
// ESTRUCTURA DEL COMPILADOR
programa: estructura;
// ACEPTA WHILE,FOR,IFELSE,DECLARACION DE VARIABLES Y COMENTARIOS
estructura: estructura comentario 
	    | estructura while
	    | estructura for 
	    | estructura ifelse 
	    | estructura declaracion 
	    | ;

declaracion: '=' ID expresion ';' 
	    | '=' ID expresion ',' declaracion; 
	    
//DEFINO OPERACIONES BASICAS CON PRECEDENCIA
expresion: '+' expresion producto 			{ $$ = $2 + $3; }
	    | '-' expresion producto 			{ $$ = $2 - $3; }
	    | producto ;

producto: '*' producto agrupacion 			{ $$ = $2 * $3; }
	    | '/' producto agrupacion 			{ $$ = $2 / $3; }
	    | agrupacion ;
	    
//DEFINO AGRUPACIONES MEDIANTE () , POTENCIA Y RAIZ.
agrupacion: RAIZ '(' expresion ')'			{ $$ = sqrt($3); } 
	    | POT '(' expresion ',' expresion ')' 	{ $$ = pow($3,$5); }
	    | valor;
	    
//EL COMPILADOR ACEPTA VALORES NUMERICOS, VARIABLES, ejm : x, 5 , (-3) , etc
valor: NUM 
	    | ID 
	    | '(' '-' NUM ')';
	    
//DEFINO IFELSE
ifelse: SI '(' lista_condicion ')' ENTONCES '{' estructura '}' SINO '{' estructura '}' 
	    | SI '(' lista_condicion ')' ENTONCES '{' estructura '}' ;
	    
//LISTA DE CONDICIONES
lista_condicion: condicion lista_condicion 
	    | condicion '&' lista_condicion 
	    | condicion '|' lista_condicion 
	    | ;

condicion: orden expresion expresion ;

//OPERADORES DE ORDEN (<,>,=,!)
orden: '>' 
	    | '>' '=' 
	    | '<' 
	    | '<' '=' 
	    | '=' 
	    | '!''=' ;
	    
//DEFINO FOR
for: PARA '(' declaracion condicion ';' contador ')' '{' estructura '}' ;

contador: '=' ID expresion ;

//DEFINO WHILE
while: MIENTRAS '(' lista_condicion ')' HACER '{' estructura '}' ;

//HABILIDAD PARA AGREGAR COMENTARIO CON LA FORMA: # comentario $
comentario: '#' comen '$' ;

//agrego esto para que los comentarios puedan tener cualquier palabra incluso las instrucciones.
comen: comen ID | comen SI | comen ENTONCES | comen SINO | comen PARA | comen MIENTRAS | comen HACER | comen RAIZ | comen POT | comen ',' | ;


%% 
// AQUI GUARDO TODAS LAS PALABRAS QUE VOY A USAR PARA LLAMAR INSTRUCCIONES
int palabras( char lexema[] ) {
	if( strcmp( lexema, "si" ) == 0 ) return SI;
	if( strcmp( lexema, "entonces" ) == 0 ) return ENTONCES;
	if( strcmp( lexema, "sino" ) == 0 ) return SINO;
	if( strcmp( lexema, "para" ) == 0 ) return PARA;
	if( strcmp( lexema, "mientras" ) == 0 ) return MIENTRAS;
	if( strcmp( lexema, "hacer" ) == 0 ) return HACER;
	if( strcmp( lexema, "raiz" ) == 0 ) return RAIZ;
	if( strcmp( lexema, "pot" ) == 0 ) return POT;
	return ID;
}


//codigo, scanner, parser
void yyerror(char *mgs){
	printf("error: %s", mgs);
}
int yylex(){ //esto retorna un token es decir numeros 
//analizador lexico hecho a mano
	char c;
	while(1){
		c=getchar();
		if(c=='\n') continue;
		if(isspace(c)) continue;		
				
		if(isalpha(c)) {//verifica si es un caracter
			int i=0;
			do {
				lexema[i++]=c;
				c=getchar();
			}while(isalnum(c));
			
         	ungetc(c,stdin);//devuelve el caracter a la entrada estandar
		lexema[i]=0;
		return palabras(lexema);//devuelve una palabra reservada
		}
		
		if(isdigit(c)){//verifica si es un nro. entero
			int i=0;
			do{
				lexema[i++]=c;
				c=getchar();
			}while(isdigit(c));
		ungetc(c,stdin);//devuelve el caracter a la entrada estandar
		lexema[i]=0;
		return NUM; //devuelve el token
		}
		
		return c;
	}
}

void main(){
//llamar al scaner o analizador lexico esto lo inicia el parser o analizador sintactico
//yyparse

	if(!yyparse())
		printf("cadena es valida\n");
	else
		printf("cadena invalida\n");
}
	
			
			
