#include <iostream>
using namespace std;

int cadastrarDespesasExtras(){
	int quantidadeDespesasExtras = 0;
	float despesasExtras[quantidadeDespesasExtras];
	float somaDespesasExtras = 0;
	
	cout<<"\n\tQuantas despesas serao cadastradas?\n\t";
	cin>> quantidadeDespesasExtras;
	
	for (int i = 0; i < quantidadeDespesasExtras; i++){

		cout<<"\n"<< i + 1 <<"\tQual o valor da despesa que deseja cadastrar?\n\t";
		cin>>despesasExtras[i];
		cout<<"\n";
	}
	
	for (int i = 0; i < quantidadeDespesasExtras; i++){
		somaDespesasExtras += despesasExtras[i];		
	}

	return somaDespesasExtras;
}

int cadastrarDespesasFixas(){
	int quantidadeDespesasFixas = 0;
	float despesasFixas[quantidadeDespesasFixas];
	float somaDespesasFixas = 0;
	
	cout<<"\n\n\tQuantas despesas serao cadastradas?\n\t";
	cin>>quantidadeDespesasFixas;
	
	for (int i = 0; i < quantidadeDespesasFixas; i++){

		cout<<"\n"<< i + 1 <<"\tQual o valor da despesa que deseja cadastrar?\n\t";
		cin>>despesasFixas[i];
	}
	
	for (int i = 0; i < quantidadeDespesasFixas; i++){
		somaDespesasFixas += despesasFixas[i];		
	}

	return somaDespesasFixas;
}

int CadastrarRendaExtra(){
	int quantidadeRendaExtra = 0;
	float RendaExtra[quantidadeRendaExtra];
	float somaRendasExtras = 0;
	
	cout<<"\n\n\tQuantas rendas extras serao cadastradas?\n\t";
	cin>>quantidadeRendaExtra;
	
	for (int i = 0; i < quantidadeRendaExtra; i++){

		cout<<"\n\t"<<i + 1 <<"\tQual o valor da renda extra que deseja cadastrar?\n\t";
		cin>>RendaExtra[i];
	}
	
	for (int i = 0; i < quantidadeRendaExtra; i++){
		somaRendasExtras += RendaExtra[i];		
	}

	return somaRendasExtras;
}	
	
int main() {	
//	menus
	int menuPrincipal;
	int menuEntradas;
	int menuSaidas;
	int menuListagem;
	
//	aux. menus
	bool auxMenuPrincipal;
	char auxMenuEntradas;
	char auxMenuSaidas;
	char auxMenuListagem;
	
//	entradas
	float salario;
	float rendaExtra;
	
//	saidas
	float despesasFixas;
	float despesasExtras;
	
//	totais
	float somaEntrada;
	float somaSaida;	
	float somaTotal;
	
	do{
		system("cls");
		cout<<"\n\tO que deseja fazer?(Digitar numeros)\n\n\t1 - Cadastrar entrada\n\t2 - Cadastrar saida\n\t3 - Listar montantes\n\t0 - Sair\n\n\t";
		cin>> menuPrincipal;
		
		switch(menuPrincipal){
			case 1 :
				do{
					system("cls");
					cout<<"\n\n\tO que gostaria de cadastrar?\n\n\t1 - Salario\n\t2 - Renda Extra\n\n\t";
					cin>> menuEntradas;
					
					switch(menuEntradas){
						case 1 :
							system("cls");
							cout<<"\n\n\tQual o valor do salario que deseja cadastrar?\n\n\t";
							cin>>salario;
							
							cout<<"\tVoltar ao menu anterior? [s]sim [n]nao\n\t";
							cin>>auxMenuEntradas;
						break;
						case 2 :
							system("cls");
							rendaExtra = CadastrarRendaExtra();
							
							cout<<"\tVoltar ao menu anterior? [s]sim [n]nao\n\t";
							cin>>auxMenuEntradas;
						break;
					}
				}while(auxMenuEntradas == 's');
			break;
			case 2 :
				do{
					system("cls");
					cout<<"\n\n\tO que gostaria de cadastrar?\n\n\t1 - Gasto essencial\n\t2 - Gasto nao essencial\n\n\t";
					cin>> menuSaidas;
					
					switch(menuSaidas){
						case 1 :
							system("cls");
							despesasFixas = cadastrarDespesasFixas();
							
							cout<<"\tVoltar ao menu anterior? [s]sim [n]nao\n\t";
							cin>>auxMenuSaidas;
						break;
						case 2 :
							system("cls");
							despesasExtras = cadastrarDespesasExtras();
							
							cout<<"\tVoltar ao menu anterior? [s]sim [n]nao\n\t";
							cin>>auxMenuSaidas;
						break;
				}
				}while(auxMenuSaidas == 's');
			break;
			case 3 :
				do{
					system("cls");
					somaEntrada = (salario + rendaExtra);
					somaSaida = (despesasFixas + despesasExtras);
					somaTotal = (somaEntrada - somaSaida);
					
					cout<<"\n\n\tAqui estao os valores atualizados:\n\n\tReceitas:\t"<<somaEntrada<<"\n\tDespesas:\t"<<somaSaida<<"\n\tMontante final:\t"<<somaTotal;
					
					cout<<"\n\n\tVoltar ao menu anterior? [s]sim [n]nao\n\t";
							cin>>auxMenuListagem;
					
				}while(auxMenuListagem == 's');
			break;
		}	
	}while(menuPrincipal != 0);
}
