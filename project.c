#include <LiquidCrystal.h>   
#include <Keypad.h>
#include <Servo.h>

Servo servo_pin_A2;

int num1=0, num2=0, num3=0, num4=0, num5=0;//armazenar a senha
int var=0; 
int C1=1,C2=2,C3=3,C4=4,C5=5;//Definição da senha
int D1=5,D2=4,D3=3,D4=2,D5=1;//Definição da senha
const byte filas = 4; 
const byte columnas = 4; 
char tecla[filas][columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinFilas[filas] = {7, 6, 5, 4}; 
byte pinColumnas[columnas] = {3, 2, 1, 0}; 

Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColumnas, filas, columnas );
LiquidCrystal lcd(8,9,10,11,12,13); 
void setup(){
  lcd.begin(16,2); 
  pinMode(A0,OUTPUT); 
  pinMode(A1,OUTPUT); 
  servo_pin_A2.attach(A2);
  servo_pin_A2.write(0);
}
  
void loop(){
  char key = keypad.getKey();
  if (key){
   lcd.setCursor(6+var,1);
   lcd.print(key),lcd.setCursor(6+var,1),lcd.print('*');//mostrar senha = key
   key=key-48; 
   var++; 
   switch(var){
    case 1:
    num1=key;  
    break;
    case 2:
    num2=key;  
    break;
    case 3:
    num3=key; 
    break;
    case 4:
    num4=key; 
    break;
    case 5:
    num5=key; 
   delay(100);
  if(num1==C1 && num2==C2 && num3==C3 && num4==C4 && num5==C5){//se a,b,c,d,e forem iguais ao declarado em cima na pass entao
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Codigo");
    lcd.setCursor(5,1);
    lcd.print("Aceito");
    digitalWrite(A0,HIGH);
    delay(1000); 
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Pacote");
    lcd.setCursor(2,1);
    lcd.print("Intermediario");
    delay(1000); 
    lcd.clear();
    digitalWrite(A0,LOW);
    servo_pin_A2.write(90);
    delay(2000);
    servo_pin_A2.write(0);
    delay(1000);
    }
  else if(num1==D1 && num2==D2 && num3==D3 && num4==D4 && num5==D5){//se a,b,c,d,e forem iguais ao declarado em cima na pass entao
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Codigo");
    lcd.setCursor(5,1);
    lcd.print("Aceito");
    digitalWrite(A0,HIGH);
    delay(1000); 
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Bem-vindo");
    lcd.setCursor(3,1);
    lcd.print("Bruno");
    delay(2500); 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Retirando o Paco");
    lcd.setCursor(3,1);
    lcd.print("te Pequeno");
    delay(2500); 
    lcd.clear();
    digitalWrite(A0,LOW);
    servo_pin_A2.write(90);
    delay(2000);
    servo_pin_A2.write(0);
    delay(1000);
    }else {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Codigo");
    lcd.setCursor(4,1);
    lcd.print("Invalido");
    digitalWrite(A1,HIGH); 
    delay(1000); 
    lcd.clear();
    digitalWrite(A1,LOW); 
    servo_pin_A2.write(0);
    delay(1000);
    }
   var=0;
   lcd.clear();

  break;//termina
  }

 }
 if(!key){lcd.setCursor(0,0),lcd.print("Insira o codigo");}

  delay(2);
}
