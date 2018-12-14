#include "MinhaSerial.h"
#include <iostream>
#include <fstream> //classe para ler e escrever em arquivos
#include <string>
using namespace std;

//int contador;

int main(){
   int nValoresRecebidos;
   char valor;
   MinhaSerial<int> conexaoSerial;

   conexaoSerial.AbreDispositivo("/dev/ttyACM0");
   conexaoSerial.IniciaColeta();
   
   //escrevendo em arquivos
   ofstream escreve; 		//classe para escrever em arquivos
   escreve.open("mensagens.txt");  //abre o arquivo mensagens

   while ( 1 != 2 ){
	   conexaoSerial.Recebe(&valor, 1);
       if ( (int)valor ==  1 ) {
           std::cout << "Queda! Entre em contato com o usuario imediatamente!\n" << valor << std::endl;
	   escreve << "Queda! Entre em contato com o usuario imediatamente!\n";	 //escreve no arquivo mensagens
           //escreve.close(); //fecha arquivo
       }
       else {
           std::cout << "Esta tudo bem!" << (int)valor << std::endl;
	   escreve << "Esta tudo bem!\n";
           //escreve.close(); //fecha arquivo
       }   
       usleep(500000);               // aguarda 50ms
       
       escreve.close(); //fecha arquivo
       //contador++;
   }

   //para coleta
   conexaoSerial.ParaColeta();
   escreve.close(); //fecha arquivo

   return 0;
}
