 int trigger = 6;           // declaramos la palabra trigger como un tipo entero y al mismo tiempo reemplaza al pin 9
 int echo = 5;           // declaramos la palabra echo como un tipo entero y al mismo tiempo reemplaza al pin 8
 float tiempo_de_espera,distancia; // creamos una variable de fotante; es decir, nos puede dar resultados en decimales.
 int tiempo = 500;
 int motor=12;//motor o buzzer
 int pausa;
 int PSensor=7;
void setup() {
  Serial.begin (9600);   // establemos la comucicacion serial
  pinMode (trigger, OUTPUT); // declarmos el pin 9 como salida
  pinMode (echo, INPUT);   // declaramos el 8 como entrada
  pinMode(motor,OUTPUT);//MOTOR OCOMO SALIDA
  pinMode (PSensor, OUTPUT);//Alimento el sensor
digitalWrite(PSensor,HIGH);//ALIMENTO EL PUERTO
           
  
}
void loop() {
digitalWrite (trigger,LOW); // ponemos en bajo el pin 6 durante 2 microsegundos
delayMicroseconds(2);
digitalWrite (trigger, HIGH);// ahora ponemos en alto pin 6 durante 10 microsegundos;
delayMicroseconds (10);     // pues este el momento en que emite el sonido durante 10 segungos
digitalWrite (trigger, LOW); // ahora ponemos en bajo pin 6 
tiempo_de_espera = pulseIn (echo,HIGH); // pulseIn, recoge la señal del sonido que emite el trigger
/*La función pulseIn espera la aparición de un pulso en una entrada y mide su duración, dando como resultado la duración medida                   
 El primer parámetro (ECHO) es el pin sobre el que se realizará la medición.
Y el segundo parámetro (HIGH) indica si el pulso a esperar será un 1 (HIGH) o un 0 (LOW).
 */
distancia =(tiempo_de_espera/2)/29.15; // formula para hallar la distancia
Serial.print (distancia);    // imprimimos la distancia en cm
Serial.println ("cm");//CM


if(distancia < 60){//si detecta algo a 60cm activa!
  
{
   pausa = distancia * 10;//
   digitalWrite(motor, HIGH);
   delay(pausa);
} 
  digitalWrite(motor, LOW);
   delay(pausa);
}
}
