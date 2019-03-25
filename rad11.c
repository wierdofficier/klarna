~lathund~
1. hur relateras momentumdensitet till angularmomentum energi, jo via en Z funktion som kopplar ihop dem.
2. Hitta generella ekvationen för Z
3. statistiskt lösa ut variablerna för denna funktion.
4. Lösa ut gravitations differens massan M, dvs intertial massa - gravitationsmassan.


momentumdensity*volym*hastighet^2/2*Z = 0.5*y*r^2*(2*pi*f)^2 = ang momentum energy

där momentum densitet är energidensitet/c^2


0.231/299792458^2*(3.528*0.005*pi/2)*(0.001195)^2*2=x*0.5*7.6e-6*1*7.43e-6^2*(2*pi*5e-6)^2
0.925/299792458^2*(3.528*0.005*pi/2)*(0.001195)^2*7=x*0.5*0.000105*1*7.43e-6^2*(2*pi*5e-6)^2
2.077/299792458^2*(3.528*0.005*pi/2)*(0.001195)^2*11=x*0.5*0.00037*1*7.43e-6^2*(2*pi*5e-6)^2
3.7/299792458^2*(3.528*0.005*pi/2)*(0.001195)^2*13=x*0.5*(1.428e-4+6.651e-4)*1*7.43e-6^2*(2*pi*5e-6)^2
5.78/299792458^2*(3.528*0.005*pi/2)*(0.001195)^2*15=x*0.5*(1.428e-4+12.454e-4)*1*7.43e-6^2*(2*pi*5e-6)^2

observera heltalen:
Z= 2
Z= 7
Z= 11
Z= 13
Z= 15

vilken generell formel kan möjligtvis följa den talföljden på releterat med hur volten ökar ?

Z = ( x + (-L - x)/(1 + (num/y)^p))



((( (XX) + (-LL - (XX))/(1.0 + pow((N/(YY)),p)   )  )))		(1)

(( (XX) + (-LL - (XX))/(1.0 + pow((XX/(YY)),YY)   )  ))		(2)

(( (X) + (-L - (X))/(1.0 + pow((X/(L/10.0)),L/10.0)   )  ))  = Z   (3)

eller alternativ form:
X + (-1 L - 1 X)/(1 + e^(0.230259 L) (X/L)^(0.1 L)) = Z		(4)


matar man in inertial massan i X och gmassan i L i denna:
X + (-1 L - 1 X)/(1 + e^(0.230259 L) (X/L)^(0.1 L))

så får man:
1.428e-4 + (-1 *(-2.304e-4) - 1 1.428e-4)/(1 + e^(0.230259 *(-2.304e-4)) (1.428e-4/(-2.304e-4))^(0.1 *(-2.304e-4)))   	(5)

det man får är  = x*r alltså gravityacc*EB_radius



så här härleds (1), (2) och (3) :

1. man bruteforcar sig fram till (1), sen använder man variablerna i sista resultatet för att lista ut nästa ekvation.
2. nästa ekvation alltså (2) innehåller färre variabler, så då använder man denna istället för att lista ut (3)
3. Den här använder bara två variabler vilket förenklar synen på Z avsevärt.

double tryer = 0;
N = 0;  // 0 till 100
XX = 0; // -1000 till 1000
LL = 0; // -10 till 10
YY = 0; //-10 till 10
p = 0;  // 0 till 4
for(int i = 0; i < 100; i += 1)
{
	p += 0.001;	
	for(int j = 0; j < 10; j += 1)
	{
		YY += 0.001;
		for(int k = 0; k < 10 ; k += 1)
		{
		
			LL += 0.001;
			for(int l = 0; l < 50  ; l += 1)
			{
 				//M  = (1.48679e-24* Q* pow(R,2.0) *U*pow(v,2.0)* sqrt((pow(o,3.0) *pow(V,4.0))/(pow(f,3.0)* pow(2700,2.0)* pow(R,4.0)))* ((( (XX) + (-LL - (XX))/(1.0 + pow((N/(YY)),p)   )  ))))/(pow(f,2.0)* pow(V,2.0)); (1) innehåller första Z

				
				V = 0.1;
				f =  5e-6;
				U  = sqrt((pow(o,3.0)* P *pow(V,4.0))/(pow(f,3.0)* pow(2700,2.0)* pow(R,4.0)))/(1199169832000.0 *sqrt(10.0)*M_PI);
				v  = (4.23971e8)/sqrt((1.0 + sqrt(1.0 + 3.23118e20 *pow((o/f),2.0)))* P);
				//innehåller andra Z (2)
				//M  = (1.48679e-24* Q* pow(R,2.0) *U*pow(v,2.0)* sqrt((pow(o,3.0) *pow(V,4.0))/(pow(f,3.0)* pow(2700,2.0)* pow(R,4.0)))*(( (XX) + (-LL - (XX))/(1.0 + pow((XX/(YY)),YY)   )  )))/(pow(f,2.0)* pow(V,2.0));

				//innehåller tredje Z (3)
				M  = (1.48679e-24* Q* pow(R,2.0) *U*pow(v,2.0)* sqrt((pow(o,3.0) *pow(V,4.0))/(pow(f,3.0)* pow(2700,2.0)* pow(R,4.0)))*(( (XX) + (-LL - (XX))/(1.0 + pow((XX/(LL/10.0)),LL/10.0)   )  )))/(pow(f,2.0)* pow(V,2.0));
				//(( (XX) + (-LL - (XX))/(1.0 + pow((XX/(LL/10.0)),LL/10.0)   )  ))  
				// 0.0090000000 :: 0.0001352082 :: 4.0360000000 :: 0.0810000000 :: 4.0360000000 :: 0.0010000000 :: 4036.000000
				// (( (XX) + (-LL - (XX))/(1.0 + pow((XX/(LL/10.0)),LL/10.0)

			
				if(XX > 10.0)
				  XX = -10.0;

				if(LL >	1000.0)
				  LL = -1000.0;
				
				if(N >	1000.0)
				  N = -1000.0;

			
			 	if(p >	4.0)
				  p = -4.0;

				if(YY >	10.0)
				  YY = -10.0;	

				XX += 0.001;
				N  +=0.001;
 
				//(( (XX) + (-LL - (XX))/(1.0 + pow((XX/(YY)),YY)   )
				//(( (4.0) + (-0.08 - (4.0))/(1.0 + pow((4.0/(0.008)),0.008)   )  ))

				//1.428e-4 + (-1*(-2.304e-4)- 1 *1.428e-4 )/(1 + e^(0.230259* (-2.304e-4)) (1.428e-4 /(-2.304e-4)4)^(0.1 *(-2.304e-4))) = 25.5*r  
				
				tryer++;
	   			double  M_g = 1.428e-4 - M;
 

 				if(M_g >      0.0001352 && M_g <    0.0001352+0.0000001 )
				{
				printf("%.10f :: %.10f :: %.10f :: %.10f :: %.10f :: %.10f :: %f\n",YY,M_g, XX,LL, N,p,  tryer);
					for(;;);

		}	}
 		}
	}
}

 
 }

}


