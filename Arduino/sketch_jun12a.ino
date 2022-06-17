#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

Servo myservo1, myservo2, myservo3, myservo4;

String cadenaAux;
String cadena;

int potpin = A0;
int val;
int grado1 = 120;
int grado2 = 30;
int grado3 = 100;
int grado4 = 90;
int tiempo=200;

void setup()
{
    lcd.begin(16, 2);
    myservo1.attach(2);
    myservo2.attach(3);
    myservo3.attach(4);
    myservo4.attach(5);
    Serial.begin(9600);
    myservo1.write(grado1);
    myservo2.write(grado2);
    myservo3.write(grado3);
    myservo4.write(grado4);
    cadena=cadenaAux;
}
void movSer1(int grado)
{

    if (grado >= grado1)
    {
        for (int i = grado1; i <= grado; i += 15)
        {
            grado1 = i;
            myservo1.write(grado1);
            delay(tiempo);
        }
    }
    else
    {
        for (int i = grado1; i >= grado; i -= 15)
        {
            grado1 = i;
            myservo1.write(grado1);
            delay(tiempo);
        }
    }
}
void movSer2(int grado)
{
    if (grado >= grado2)
    {
        for (int i = grado2; i <= grado; i += 15)
        {
            grado2 = i;
            myservo2.write(grado2);
            delay(tiempo);
        }
    }
    else
    {
        for (int i = grado2; i >= grado; i -= 15)
        {
            grado2 = i;
            myservo2.write(grado2);
            delay(tiempo);
        }
    }
}

void movSer3(int grado)
{
    if (grado >= grado3)
    {
        for (int i = grado3; i <= grado; i += 15)
        {
            grado3 = i;
            myservo3.write(grado3);
            delay(tiempo);
        }
    }
    else
    {
        for (int i = grado3; i >= grado; i -= 15)
        {
            grado3 = i;
            myservo3.write(grado3);
            delay(tiempo);
        }
    }
}

void loop()
{
  
   if (Serial.available()) 
   { 
     if(cadena!=cadenaAux){
      writeLcd();
    }

    cadena= Serial.readString();
   
    if (cadena=="yes")
    {
        
        primerMov();
        segMov();
        tercMov();
        delay(3000);
        cuarMov();
    }
 }else{
  lcd.setCursor(0,0);          
     lcd.print("Puerto cerrado");
  
  }
}
void writeLcd(){
     lcd.clear();
     lcd.setCursor(0,0);          
     lcd.print(cadena); 
}
void primerMov()
{
    movSer1(120);
    movSer2(30);
    movSer3(100);
    myservo4.write(90);
}
void segMov()
{

    movSer2(0);
    movSer3(80);
    delay(1000);
    movSer1(180);
    myservo4.write(90);
}
void tercMov()
{
    movSer1(180);
    movSer2(30);
    movSer3(40);
    myservo4.write(90);
}
void cuarMov()
{
    movSer1(120);
    movSer2(30);
    movSer3(40);
    myservo4.write(90);
}
