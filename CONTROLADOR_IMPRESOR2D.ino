volatile int contador = 0; //VAR SEGURA para multiples cambios.
int n = contador ; //VAR comparador.

int CA = 4; //Canal A OUT > D4 INPUT.
int CB = 2; //Canal B OUT > D5 INPUT.
int OA = 6; //Output A OUT D6 OUTPUT.
int OB = 7; //OutputB OUT D7 OUTPUT.

void setup()
{
     pinMode(CA, INPUT);
     pinMode(CB, INPUT);
     pinMode(OA, OUTPUT);
     pinMode(OB, OUTPUT);
     
     Serial.begin(9600); //Velocidad para transmitir datos (9600 baudios = SEGURO).
     attachInterrupt(digitalPinToInterrupt(CB), CalcularPLS, CHANGE); //Definicion de Interrupcion.
}
   
void loop()
{   
     //CalcularPLS();
     if (n != contador)
     {   
       Serial.println(contador);
       n = contador ;
     }
     digitalWrite(OA, LOW);
     digitalWrite(OB, HIGH);
     
}


void CalcularPLS()
{
     if(digitalRead(CB) == 1)
     {   
       contador++ ;
     }
}
