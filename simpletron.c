#include <stdio.h>


void limpiarMemoria(int mem[]);
void cargarPrograma(int mem[]);
void ejecutarPrograma(int mem[]);
void mostrarVaciado(int acum, int contador, int regInst, int op, int arg, const int mem[]);

int main() {
	int memoria[100];
	
	printf(" SIMULADOR SIMPLETRON \n");
	printf("Introduce las instrucciones una por una.\n");
	printf("Introduce 9999 para terminar la carga.\n\n");
	
	limpiarMemoria(memoria);
	cargarPrograma(memoria);
	
	printf("\nCarga finalizada. Iniciando ejecucion \n\n");
	ejecutarPrograma(memoria);
	
	return 0;
}


void limpiarMemoria(int mem[]) {
	int i;
	for (i = 0; i < 100; i++) {
		mem[i] = 0;
	}
}


void cargarPrograma(int mem[]) {
	int instruccion = 0;
	int pos = 0;
	
	while (pos < 100) {
		printf("[%02d] ? ", pos);
		scanf("%d", &instruccion);
		
	
		if (instruccion == 9999) {
			break;
		}
		
	
		if (instruccion < -9999 || instruccion > 9998) {
			printf("Instruccion invalida. Debe estar entre -9999 y +9998.\n");
			continue;
		}
		
		mem[pos] = instruccion;
		pos++;
	}
}


void ejecutarPrograma(int mem[]) {
	int acumulador = 0;
	int contadorInst = 0;
	int regInstruccion = 0;
	int codigoOp = 0;
	int operando = 0;
	int error = 0;
	
	while (contadorInst < 100 && error == 0) {

		regInstruccion = mem[contadorInst];
		
	
		codigoOp = regInstruccion / 100;
		operando = regInstruccion % 100;
		
	
		contadorInst++;
		
	
		switch (codigoOp) {
		case 10: 
			printf("? ");
			scanf("%d", &mem[operando]);
			while (mem[operando] < -9999 || mem[operando] > 9998) {
				printf("Numero fuera de rango (-9999 a +9998). Reintenta (? ): ");
				scanf("%d", &mem[operando]);
			}
			break;
			
		case 11: 
			printf("Salida SML: %d\n", mem[operando]);
			break;
			
		case 20: 
			acumulador = mem[operando];
			break;
			
		case 21: 
			mem[operando] = acumulador;
			break;
			
		case 30: 
			acumulador += mem[operando];
			break;
			
		case 31: 
			acumulador -= mem[operando];
			break;
			
		case 32:
			if (mem[operando] == 0) {
				printf("\n*** ERROR FATAL: Division por cero ***\n");
				error = 1;
			} else {
				acumulador /= mem[operando];
			}
			break;
			
		case 33: 
			acumulador *= mem[operando];
			break;
			
		case 40: 
			contadorInst = operando;
			break;
			
		case 41: 
			if (acumulador < 0) {
				contadorInst = operando;
			}
			break;
			
		case 42: 
			if (acumulador == 0) {
				contadorInst = operando;
			}
			break;
			
		case 43: 
			printf("\n*** Fin de la ejecucion (ALTO) ***\n");
			mostrarVaciado(acumulador, contadorInst, regInstruccion, codigoOp, operando, mem);
			return;
			
		default:
			printf("\n*** ERROR FATAL: Codigo de operacion invalido (%02d) ***\n", codigoOp);
			error = 1;
			break;
		}
		

		if (acumulador < -9999 || acumulador > 9998) {
			printf("\n ERROR FATAL: Desbordamiento del acumulador (%d)\n", acumulador);
			error = 1;
		}
	}
	

	if (error == 1) {
		printf("*** La ejecucion se detuvo por un error ***\n");
		mostrarVaciado(acumulador, contadorInst, regInstruccion, codigoOp, operando, mem);
	}
}


void mostrarVaciado(int acum, int contador, int regInst, int op, int arg,  int mem[]) {
	int i, j;
	
	printf("\nREGISTROS:\n");
	printf("acumulador            %+05d\n", acum);
	printf("contadorInstrucciones    %02d\n", contador);
	printf("registroInstruccion   %+05d\n", regInst);
	printf("codigoOperacion          %02d\n", op);
	printf("operando                 %02d\n\n", arg);
	
	printf("MEMORIA:\n\t");
	

	for (i = 0; i < 10; i++) {
		printf("%d\t", i);
	}
	printf("\n");
	

	for (i = 0; i < 100; i += 10) {
		printf("%d\t", i);
		for (j = 0; j < 10; j++) {
			printf("%d\t", mem[i + j]);
		}
		printf("\n");
	}
	printf("\n");
}
