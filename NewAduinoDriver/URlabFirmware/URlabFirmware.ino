
// Declaracón de tipos
typedef union{
   float val;
   byte  b[4];     // Array de bytes de tamaño igual al tamaño de la primera variable: float = 4 bytes
} FLOATUNION_t ;

// Declaración de constantes y variables
const int Q1 = 6;
const int Q2 = 5;
const int Led1 = 10;
const int Led2 = 9;
const float TempMax = 80;


const int dim = 16;
byte buff[dim];

FLOATUNION_t T1, T2, U;

int i   = 0;
int cnt = 0;

unsigned long t_anterior, t_lecturas, t_lecturas_ant, t_actual;

float u1, u2;

void setup() {
  
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);

  pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);

  analogWrite(Q1,0);
  analogWrite(Q2,0);
   
  Serial.begin(115200); 
  Serial.flush();

  T1.val = 22;
  T2.val = 22;
  t_anterior = millis();
  u1 = 0;
  u2 = 0;
  t_lecturas_ant = 0;
  t_anterior = 0;
}

void loop() {
  int n_datos = Serial.available();
  if (n_datos>9){
    int i = 0; 
    while (Serial.available()>0){
      buff[i] = Serial.read();
      i++;
    }
    i--;
    if (buff[i]==10 && buff[i-1] == 13){ 
      delay(10);
      // Generación de salidas PWM
      U.b[0] = buff[i-9];
      U.b[1] = buff[i-8];
      U.b[2] = buff[i-7];
      U.b[3] = buff[i-6];

      u1 = 4.0 * U.val;
      
      U.b[0] = buff[i-5];
      U.b[1] = buff[i-4];
      U.b[2] = buff[i-3];
      U.b[3] = buff[i-2];

      u2 = 4.0 * U.val;
      int pwm1 = map((int)u1,0, 400, 0,255);
      int pwm2 = map((int)u2,0, 400, 0,255);
      if (T1.val>TempMax){pwm1 = 0;}
      if (T2.val>TempMax){pwm1 = 0;}
      analogWrite(Q1,pwm1);
      analogWrite(Q2,pwm2);
    }

  }

    
  t_lecturas = millis ();
  if ((t_lecturas - t_lecturas_ant) >= 50){
    t_lecturas_ant = t_lecturas;
    T1.val  = 0.9 * T1.val + 0.1 * 100 * (5.0 * (float)analogRead(A0)/1024.0 - 0.5);
    T2.val  = 0.9 * T2.val + 0.1 * 100 * (5.0 * (float)analogRead(A1)/1024.0 - 0.5);
  }

  t_actual = millis();
  if ((t_actual - t_anterior) >= 500){
    t_anterior = t_actual;
    Serial.write('A'); 
    Serial.write(T1.b,4);
    Serial.write(T2.b,4);
    Serial.write('\n');  
    int pwmLed1 = map((int)T1.val, 20, 100, 0, 255);
    int pwmLed2 = map((int)T2.val, 20, 100, 0, 255);
    analogWrite(Led1,pwmLed2);
    analogWrite(Led2,pwmLed2);
  }
  
}



