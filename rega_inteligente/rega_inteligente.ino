// C++ code
//
#include <LiquidCrystal.h>

const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2; // POSTAR DO DISPLAY
const int portaAnalogicaA0 = A0; // PORTA ANALOGICA DE RECEBIMENTO DE SINAL

LiquidCrystal monitorLCD(rs,en,d4,d5,d6,d7); // INTANCIA UM NOVO DISPLAY / PORTAS DE CONEXAO DEFINIDAS ANTERIORMENTE

/* CONTROLA  */
void controlaLuzLED(int calculo) {
  String variacao = "";
  
  if (calculo > 50) { // CASO A DISTANCIA SEJA SUPERIOR A 50, A LUZ E ACESA
    // Luz acesa!!
    //Serial.println("Luz acesa!!");
    // O pino 8 e responsável por deixar ligar o LED
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);

    variacao = "RELE FECHADO"; // IMPRIME OS DADOS NA TELA

  } else { // CASO A DISTANCIA SEJA INFERIOR OU IGUAL A 50, A LUZ E APAGADA
    // Luz apagada!!
    //Serial.println("Luz apagada!!");
    // O pino 8 e responsável por deixar apagar o LED
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    
    variacao = "RELE ABERTO"; // IMPRIME OS DADOS NA TELA
    
  }

  monitorLCD.display(); // DEIXA OS DADOS DO MONITOR VISIVEIS

  //monitorLCD.home(); // JOGA O CUROR PARA O LADO SUPERIOR ESQUERDO DO DISPLAY
  monitorLCD.print(variacao); // IMPRIME OS DADOS NA TELA

  delay(500); // APLICA UM DELAY A APLICACAO, PARA QUE A LIMPEZA DOS DADOS NAO SEJA INSTANTANEA, ASSIM CONSEGUIMOS VER O QUE ESTA SENDO APRESENTADO NA TELA
  monitorLCD.clear(); // LIMPA A TELA DO MONITOR E POSICIONA NA LATERAL SUPERIROR ESQUERDA DO DISPLAY
    
}

void recursao() {
  controlaLuzLED(analogRead(portaAnalogicaA0));

  monitorLCD.display(); // DEIXA OS DADOS DO MONITOR VISIVEIS

  //monitorLCD.home(); // JOGA O CUROR PARA O LADO SUPERIOR ESQUERDO DO DISPLAY
  //monitorLCD.print(analogRead(portaAnalogicaA0)); // IMPRIME OS DADOS NA TELA

  delay(500); // APLICA UM DELAY A APLICACAO, PARA QUE A LIMPEZA DOS DADOS NAO SEJA INSTANTANEA, ASSIM CONSEGUIMOS VER O QUE ESTA SENDO APRESENTADO NA TELA
  monitorLCD.clear(); // LIMPA A TELA DO MONITOR E POSICIONA NA LATERAL SUPERIROR ESQUERDA DO DISPLAY

  recursao();
}

/* INICIONALIZA O SISTEMA */
void setup() {
  monitorLCD.begin(16, 2); // ESPECIFICA A DIMENSAO DE LARGURA E ALTURA QUE IRA OCUPAR NO DISPLAY

  pinMode(8, OUTPUT); // INFORMA QUAL PINO E RESPOSVEL POR MANDAR A TRAVA
  pinMode(9, OUTPUT); // INFORMA QUAL PINO E RESPOSVEL POR MANDAR A TRAVA

  recursao();
  
}
