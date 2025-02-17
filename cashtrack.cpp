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
	int auxMenuEntradas;
	int auxMenuSaidas;
	char auxMenuListagem;
	
//	entradas
	float salario = 0;
	float rendaExtra = 0;
	
//	saidas
	float despesasFixas = 0;
	float despesasExtras = 0;
	
//	totais
	float somaEntrada = 0;
	float somaSaida = 0;	
	float somaTotal = 0;
	
	do{
		system("cls");
		cout<<"\n\tMenu Principal\n\n\tO que deseja fazer?(Digitar numeros)\n\n\t1 - Cadastrar entrada\n\t2 - Cadastrar saida\n\t3 - Listar montantes\n\t0 - Sair\n\n\t";
		cin>> menuPrincipal;
		
		switch(menuPrincipal){
			case 1 :
				do{
					system("cls");
					cout<<"\n\n\tO que gostaria de cadastrar?\n\n\t1 - Salario\n\t2 - Renda Extra\n\t3 - Voltar ao menu principal\n\n\t";
					cin>> menuEntradas;
					
					switch(menuEntradas){
						case 1 :
							system("cls");
							cout<<"\n\n\tQual o valor do salario que deseja cadastrar?\n\n\t";
							cin>>salario;
							
							cout<<"\n\n\tVoltar para:\n\n\t1 - Menu cadastro entradas\n\t2 - Menu principal\n\n\t";
							cin>>auxMenuEntradas;
						break;
						case 2 :
							system("cls");
							rendaExtra = CadastrarRendaExtra();
							
							cout<<"\n\n\tVoltar para:\n\n\t1 - Menu cadastro entradas\n\t2 - Menu principal\n\n\t";
							cin>>auxMenuEntradas;		
						break;
						case 3 :
							menuPrincipal;
						break;
					}
				}while(auxMenuEntradas == 1);
			break;
			case 2 :
				do{
					system("cls");
					cout<<"\n\n\tO que gostaria de cadastrar?\n\n\t1 - Gasto essencial\n\t2 - Gasto nao essencial\n\t3 - Voltar ao menu principal\n\n\t";
					cin>> menuSaidas;
					
					switch(menuSaidas){
						case 1 :
							system("cls");
							despesasFixas = cadastrarDespesasFixas();
							
							cout<<"\n\n\tVoltar para:\n\n\t1 - Menu cadastro saidas\n\t2 - Menu principal\n\n\t";
							cin>>auxMenuSaidas;
						break;
						case 2 :
							system("cls");
							despesasExtras = cadastrarDespesasExtras();
							
							cout<<"\n\n\tVoltar para:\n\n\t1 - Menu cadastro saidas\n\t2 - Menu principal\n\n\t";
							cin>>auxMenuSaidas;
						break;						
						case 3 :
							menuPrincipal;
						break;
				}
				}while(auxMenuSaidas == 1);
			break;
			case 3 :
				do{
					system("cls");
					somaEntrada = (salario + rendaExtra);
					somaSaida = (despesasFixas + despesasExtras);
					somaTotal = (somaEntrada - somaSaida);
					
					cout<<"\n\n\tAqui estao os valores atualizados:\n\n\tReceitas:\t"<<somaEntrada<<"\n\tDespesas:\t"<<somaSaida<<"\n\tMontante final:\t"<<somaTotal;
				
					cout<<"\n\n\tVoltar ao menu principal? [s]sim\n\t";
					cin>>auxMenuListagem;
					
				}while(auxMenuListagem == 'n');
			break;
		}	
	}while(menuPrincipal != 0);
}
