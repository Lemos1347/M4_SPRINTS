#include <iostream>
#include <string>

using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

double converteSensor (double valor, int min, int max) {
	// Crio uma variável que vai receber um float, por isso o tipo é double
	double valorConvertido;

	// Subtraio o valor do mínimo pois quero saber a distância do valor ao mínimo
	double novoValor = valor - min;
	// Subtraio o valor máximo do mínimo para saber a distância dentre esses dois pontos
	double range = max - min;

	// Divido pelo range pois assim vou descobrir a porcentagem do valor que foi passado em relação a distância entre o mínimo e o máximo
	valorConvertido = novoValor / range;

	return valorConvertido;
}

// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor

int leComando (string direcao) {
	int resposta;
	// Mostro no terminal do usuário o que quero que ele insira no terminal
	cout << "Insira um valor para a " << direcao << endl;
	// Armazeno a informação do terminal em uma variável que é o retorno da função
	cin >> resposta;
	return resposta;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor

int armazena (double valor, int tamanhoVetor, int posicao, double *vetor) {

	// Verifico se a posição que o usuário quer inserir já não está ocupada
    if (posicao + 1 < tamanhoVetor) {
        vetor[posicao + 1] = valor;
		  // Retorno a última posição que foi ocupada
        return (posicao + 1);
    }

    else{
		// Trabalho de erro
        cout << "Posição maior que o tamanho do vetor" << endl;
    }

}

// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.

string maiorLado (double *vetor) {

	// Sequência de verificações para saber qual é o maior valor do vetor fornecido, e retornar a direção que aquele maior valor faz referência
	if (vetor[0] > vetor[1] && vetor[0] > vetor[2] && vetor[0] > vetor[3]) {
		return "Direita";
	}
	else if (vetor[1] > vetor[0] && vetor[1] > vetor[2] && vetor[1] > vetor[3]) {
		return "Esquerda";
	}
	else if (vetor[2] > vetor[0] && vetor[2] > vetor[1] && vetor[2] > vetor[3]) {
		return "Frente";
	}
	else if (vetor[3] > vetor[0] && vetor[3] > vetor[1] && vetor[3] > vetor[2]) {
		return "Tras";
	}
	// Trabalho de erro
	else {
		return "Valores incompatíveis";
	}
}

double maiorDistancia (double *vetor) {
	// Sequência de verificações para saber qual é o maior valor do vetor e retorná-lo
	if (vetor[0] > vetor[1] && vetor[0] > vetor[2] && vetor[0] > vetor[3]) {
		return vetor[0];
	}
	else if (vetor[1] > vetor[0] && vetor[1] > vetor[2] && vetor[1] > vetor[3]) {
		return vetor[1];
	}
	else if (vetor[2] > vetor[0] && vetor[2] > vetor[1] && vetor[2] > vetor[3]) {
		return vetor[2];
	}
	else if (vetor[3] > vetor[0] && vetor[3] > vetor[1] && vetor[3] > vetor[2]) {
		return vetor[3];
	}
}



// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso

int leResposta () {
	char resposta;
	int retorno;

	// Informo do terminal se o usuário deseja fornecer mais algum dado
	cout << "Deseja continuar o mapeamento? (S/N)";

	// Loop para que o usuario informe o que está sendo pedido 
	while (true) {
		cin >> resposta;
		// Verifico se o usuário informou S ou N, caso não seja, continuará perguntando até que ele forneça a resposta compatível
		if (resposta == 'S') {
		retorno = 1;
		break;
		}
		else if (resposta == 'N') {
		retorno = 0;
		break;
		}
		else {
			cout << "Resposta incorreta, deseja continuar o mapeamento? (S/N)";
			cin >> resposta;
		}
	}

	return retorno;
}


// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int dirige(double *v,int maxv){
	int maxVetor = maxv;
	double *vetorMov = v;
	int posAtualVetor = -1;
	int dirigindo = 1;
	// Loop que vai rodar enquanto o dirigindo for 1	
	// Observação: não utilizo a função leComando pois qual rodo o script, ele pula o próximo valor que ele vai armazenar, erro sem sentido. 
	// Para mais detalhes, comente o cout até o cin ; e descomente a linha que possui a função leComando.	
	while(dirigindo){
		// Exibo para o usuário qual informação ele tem que informar
		cout << "Insira um valor para a direita" << endl;
		// int medidaDireita = leComando("direita");
		// Armazeno essa informacao em uma variável, faço as conversões necessárias e a armazeno no vetor de posições
		double medidaDireita;
		cin >> medidaDireita;
		medidaDireita = converteSensor(medidaDireita, 0, 830);
		posAtualVetor = armazena(medidaDireita, maxv, posAtualVetor, vetorMov);

		// Exibo para o usuário qual informação ele tem que informar
		cout << "Insira um valor para a esquerda" << endl;
		// int medidaEsquerda = leComando("esquerda");
		// Armazeno essa informacao em uma variável, faço as conversões necessárias e a armazeno no vetor de posições
		double medidaEsquerda;
		cin >> medidaEsquerda;
		medidaEsquerda = converteSensor(medidaEsquerda,0,830);
		posAtualVetor = armazena(medidaEsquerda, maxv, posAtualVetor, vetorMov);

		// Exibo para o usuário qual informação ele tem que informar
		cout << "Insira um valor para a frente" << endl;
		// int medidaFrente = leComando("frente");
		// Armazeno essa informacao em uma variável, faço as conversões necessárias e a armazeno no vetor de posições
		double medidaFrente;
		cin >> medidaFrente;
		medidaFrente = converteSensor(medidaFrente,0,830);
		posAtualVetor = armazena(medidaFrente, maxv, posAtualVetor, vetorMov);

		// Exibo para o usuário qual informação ele tem que informar
		cout << "Insira um valor para tras" << endl;
		// int medidaTras = leComando("tras");
		// Armazeno essa informacao em uma variável, faço as conversões necessárias e a armazeno no vetor de posições
		double medidaTras;
		cin >> medidaTras;
		medidaTras = converteSensor(medidaTras,0,830);
		posAtualVetor = armazena(medidaTras, maxv, posAtualVetor, vetorMov);

		// Pergunto ao usuário se ele deseja mapear mais algum valor, caso seja o seu desejo, o dirigindo permanecerá como 1, executando o loop novamente
		dirigindo = leResposta();		
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(double *v,int tamPercorrido){		
	double *vetorMov = v;
	
	// Loop que vai acontecer para cada conjunto de movimentações, ou seja, de 4 em 4 valores que existem nos vetores
	for(int i = 0; i < tamPercorrido; i+=4){
		// Crio um vetor que vai receber 4 valore a cada loop, os quais representam os valores da direita, esquerda, frente e tras respectivamente
		double vetorAnalise [4] = {vetorMov[i], vetorMov[i + 1], vetorMov[i +2], vetorMov[i + 3]};
		// Descubro em qual direção há o maior valor
		string direcao = maiorLado(vetorAnalise);
		// Descubro qual a maior distância
		double valorDeMovimento = maiorDistancia(vetorAnalise);
		cout << "Movimentando para a " << direcao << " = " << valorDeMovimento << endl;
		// printf("Movimentando para %s distancia = %i\n",direcao,valorDeMovimento);
	}
}

int main() {
	int maxVetor = 100;
	double vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}