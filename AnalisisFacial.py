from ast import Return
import math

class AnalisisFacial:
     
    longitudes=None
    listaPuntosFaciales=None
    longitudOjoIzquierdo=None
    longitudOjoDerecho=None
 
    emocion=None

    def __init__(self,listaPuntosFaciales) :  
       self.listaPuntosFaciales=listaPuntosFaciales

    def getLongitudes(self):
        xpuntaRostro1,yPuntaRostro1=self.listaPuntosFaciales[93][1:]
        xpuntaRostro2,yPuntaRostro2=self.listaPuntosFaciales[323][1:]
        self.longitudRostro=math.hypot(xpuntaRostro1-xpuntaRostro2,yPuntaRostro1-yPuntaRostro2)
        #print(f"Longitud Rostro {longitudRostro}")
        #Trabajamos con proporciones 240 es el 100%
        
        porcentaje=self.longitudRostro/240
        #print(f"Porcentaje {int(porcentaje*100)}% Decimal {int(porcentaje*100)}")
        #print(f"Tamaño rostro proporcional {self.longitudRostro/porcentaje}")
        #Segun el identificador tomamos coordenadas en x,y ([n:] desde la posicion n en adelante)
        x1Boca,y1Boca=self.listaPuntosFaciales[13][1:]
        x2Boca,y2Boca=self.listaPuntosFaciales[14][1:]
        #Devuelve la norma de un vector es decir distancia entre dos puntos
        self.longitudBoca=abs(int(math.hypot(x2Boca-x1Boca,y2Boca-y1Boca)/porcentaje))
        
        if self.longitudBoca<=8:
            escalaLongitudBoca="boca_cerrada"
        elif self.longitudBoca>8:
            escalaLongitudBoca="boca_abierta"   
        if (escalaLongitudBoca=="boca_abierta"):
            return "yes" 
        return "no"

        


      
       

