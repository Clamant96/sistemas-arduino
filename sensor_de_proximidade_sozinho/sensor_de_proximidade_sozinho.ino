// C++ code
//
#include <LiquidCrystal.h>

int distancia = 0; // VARIAVEL DE CALCULO DO SENSOR
int portaTrigger = 10; // DEFINE A POSTA DE TRIGGER -> TRAVA / DEIXA PASSAR ENERGIA
int portaEcho = 9; // DEFINE A PORTA DO ECHO -> CALCULO DE DISTANCIA
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2; // POSTAR DO DISPLAY

LiquidCrystal monitorLCD(rs,en,d4,d5,d6,d7); // INTANCIA UM NOVO DISPLAY / PORTAS DE CONEXAO DEFINIDAS ANTERIORMENTE

/* REALIZA A LEITURA DA DISTANCIA COM O SENSOR ULTRASONICO / CALCULO */
long lerDistancia(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  //delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  //delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

/* GERA UM LOOP PARA FICAR OBSERVANDO SEMPRE QUANDO OUHER MUDANCAS NA DISTANCIA COM A UTILIZACAO DO SENSOR ULTRASONICO */
/*void loop() {
  Distancia = 0.01723 * lerDistancia(portaTrigger, portaEcho); // RETORNA O CALCULO DA DISTANCIA OBTIDA POR MEIO DO SENSOR ULTRASONICO
  //delay(500); // DEFINE UM DELAY PARA SE APAGAR OU LIGAR A TRAVA
  
  if (Distancia > 50) { // CASO A DISTANCIA SEJA SUPERIOR A 50, A LUZ E ACESA
    // Luz acesa!!
    //Serial.println("Luz acesa!!");
    // O pino 8 e responsável por deixar ligar o LED
    digitalWrite(8, HIGH);

  } else { // CASO A DISTANCIA SEJA INFERIOR OU IGUAL A 50, A LUZ E APAGADA
    // Luz apagada!!
    //Serial.println("Luz apagada!!");
    // O pino 8 e responsável por deixar apagar o LED
    digitalWrite(8, LOW);
    
  }

}*/

/* RECURSAO PARA REALIZAR A ATUALIZACAO E O RECALCULO DO SENSOR */
void imprimirValorNaTela() {
  double calculo = 0;
  
  calculo = (0.01723 * lerDistancia(portaTrigger, portaEcho)); // CALULA A DISTANCIA E ARMAZENA NA VARIAVEL CALCULO
  
  //monitorLCD.setCursor(0, 1); // SETA A POSICAO NA QUAL OS DADOS SERAM APRESENTADOS NO MONITOR
  
  monitorLCD.display(); // DEIXA OS DADOS DO MONITOR VISIVEIS
  //delay(500);
  
  //monitorLCD.home(); // JOGA O CUROR PARA O LADO SUPERIOR ESQUERDO DO DISPLAY
  monitorLCD.print(calculo); // IMPRIME OS DADOS NA TELA

  delay(500); // APLICA UM DELAY A APLICACAO, PARA QUE A LIMPEZA DOS DADOS NAO SEJA INSTANTANEA, ASSIM CONSEGUIMOS VER O QUE ESTA SENDO APRESENTADO NA TELA
  monitorLCD.clear(); // LIMPA A TELA DO MONITOR E POSICIONA NA LATERAL SUPERIROR ESQUERDA DO DISPLAY

  controlaLuzLED(calculo); // DEFINE SE O ESTADO ATUAL DO LED
  
  imprimirValorNaTela(); // SE ALTO CHAMA, PARA QUE SEJA POSSIVEL ENTRAR EM RECURSAO
  
}

void controlaLuzLED(int calculo) {
  if (calculo > 50) { // CASO A DISTANCIA SEJA SUPERIOR A 50, A LUZ E ACESA
    // Luz acesa!!
    //Serial.println("Luz acesa!!");
    // O pino 8 e responsável por deixar ligar o LED
    digitalWrite(8, HIGH);

  } else { // CASO A DISTANCIA SEJA INFERIOR OU IGUAL A 50, A LUZ E APAGADA
    // Luz apagada!!
    //Serial.println("Luz apagada!!");
    // O pino 8 e responsável por deixar apagar o LED
    digitalWrite(8, LOW);
    
  }
    
}

/* INICIONALIZA O SISTEMA */
void setup() {
  monitorLCD.begin(16, 2); // ESPECIFICA A DIMENSAO DE LARGURA E ALTURA QUE IRA OCUPAR NO DISPLAY

  pinMode(8, OUTPUT); // INFORMA QUAL PINO E RESPOSVEL POR MANDAR A TRAVA
  
  imprimirValorNaTela();
  
}
