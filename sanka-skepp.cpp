# include <iostream>
# include <iomanip> //Detta bibliotek anv�nder jag f�r att kunna g�ra indrag i texten.
using namespace std;

// - Globala variabler -
int array[4][4]; //Dold spelplan
string plan[4][4]; //Synlig spelplan

// - Funktionsdeklarationer -
int meny(); //Min meny-funktion.
void regler(); //Min regel-funktion.
void nolla(); //Denna funktion nollst�ller alla v�rden p� min spelplan.
void slumpa(); //Denna funktion slumpar fram och placerar ut skeppen.
void spelplan(); //Denna funktion ritar ut spelplanen.
int skott(); //Denna funktion kontrollerar skottet.


main()
{
	int val; //H�r sparas valet fr�n menyfunktionen.
	int highscore=17;
	int antalskott=0; //Skottr�knare.
	int traff=0; //Tr�ffr�knare.
	int avslutasvar; //H�r sparas valet om man verkligen vill avsluta.
	
	bool programloop=true;
	bool spelloop=true;
	bool avslutaloop=true;
	
	cout  <<endl <<endl <<setw(64) <<"- - * V�lkommen till spelet \"S�nka skepp\"! * - -" <<endl <<endl;
   cout  <<"________________________________________________________________________________" <<endl;
  
   while(programloop) //Loopar mitt program tills man v�ljer att avsluta.
   {
     	val=meny(); //Denna k�r min meny och sparar sedan svaret i variabeln val.
   
     	if(val==1)
     		regler(); //Visar reglerna.
   
   	else if(val==2)
   	{
         antalskott=0; //Skottr�knaren nollst�lls.
         traff=0; //Antal tr�ffar nollst�lls.
   		nolla(); //T�mmer spelplanen.
   		slumpa(); //Slumpar ut skepp.
   			
   		spelloop=true;
   		while(spelloop) //Loopar spelomg�ngen tills man hittat alla skepp.
   		{
   			spelplan(); //Ritar ut spelplanen.
   				
   			if (skott()==1) //F�rst k�rs min skottfunktion och sedan kontrolleras det om man f�tt tr�ff.
   				traff++; //Om tr�ff s� �kar tr�ffr�knaren med 1.
   					
   			antalskott++; //Skottr�knaren �kar med 1.
   			
            if(traff>0)
            {	
      			if(traff==1)
      				cout	<<"Det finns bara ett skepp kvar. Kom igen nu!" <<endl;
      				
      			else if(traff==2)
      			{
                  spelplan(); //Ritar ut spelplanen.
      				cout	<<endl <<"Det kr�vdes " <<antalskott <<" skott, och nu har du �ntligen s�nkt b�gge";
      				cout	<<" skeppen. Du kan se din " <<endl <<"highscore om du trycker 3 i menyn. Spelet �r slut.";
      				cout	<<endl <<endl;
      					
      				if(antalskott<highscore)
      				{
      					if(highscore!=17) //Om highscoret har �ndrats tidigare.
      					{
      						cout	<<"Grattis, du har f�tt ett nytt highscore! Du kan se ditt nya highscore om du";
      						cout	<<endl <<"trycker 3 i menyn." <<endl <<endl;
      					}
      
      					highscore=antalskott;
      				}
      						
      				spelloop=false;
      			}
            }	
   		}
   	}
	
		else if(val==3) //Visar highscoren.
		{
			if(highscore==17)
				cout	<<endl <<"Du har inte spelat �n och kan d�rf�r inte se n�gon highscore." <<endl <<endl;
				
			else
				cout	<<endl <<"Din highscore �r " <<highscore <<" antal skott." <<endl <<endl;
		}
		
		else if(val==4)
		{
			cout	<<endl <<"�r du verkligen s�ker p� att du vill avsluta? Din highscore kommer inte sparas " <<endl;
			cout	<<"till n�sta g�ng. Tryck valfri siffra (1=Ja, 2=Nej): " <<endl <<endl;
			
			avslutaloop=true;
			
			while(avslutaloop) //En loop anv�nds f�r att kontrollera ev felaktig input.
			{
				if((cin >>avslutasvar)&&(avslutasvar==1||avslutasvar==2)) //F�rst skrivs Cin in, sedan kontrolleras om det �r
				{																			 //r�tt typ (r�tt typ g�r "cin>>val" till sann) och till
					if(avslutasvar==1)												 //sist kontrolleras om det �r ett giltigt v�rde.
					{
						cout <<endl <<"Tack f�r att du spelat!" <<endl <<endl;
						avslutaloop=false;
						programloop=false;
					}
					
					else //Om man inte �r s�ker p� att avsluta loopas man om till menyn.
						avslutaloop=false;
				}
		
				else
				{
					cout <<endl <<"Ogiltigt val, var god f�rs�k igen." <<endl <<endl;
					cin.clear();
					cin.ignore(1000, '\n'); //Ignorerar upp till 1000 tecken och anv�ndarens ENTER
				}
			}
		}
	}
}


int meny() //Definition av menyfunktion.
{
	int val; //H�r sparas valet som g�rs.
	bool loop=true;
	
	while(loop) //En loop anv�nds f�r att kontrollera ev felaktig input.
	{
		cout	<<endl <<setw(60) <<"Vad vill du g�ra? Tryck valfri siffra: " <<endl;
		cout	<<setw(69) <<"1. L�sa reglerna    2. Spela    3. Se HighScore    4. Avsluta" <<endl <<endl;
		
		if((cin >>val)&&(val>=1)&&(val<=4)) //F�rst skrivs Cin in, sedan kontrolleras om det �r
		{ 												//r�tt typ (r�tt typ g�r "cin>>val" till sann) och till 
			loop=false;								//sist kontrolleras om det �r ett giltigt v�rde.
			return val;
		}
		
		else
		{
			cout <<endl <<"Ogiltigt val, var god f�rs�k igen." <<endl <<endl;
			cin.clear();
			cin.ignore(1000, '\n'); //Ignorerar upp till 1000 tecken och anv�ndarens ENTER
		}
	}
}


void regler() //Definition av regel-funktion.
{
	cout  <<endl <<endl <<setw(41) <<"Regler" <<endl <<endl;
	cout	<<"Spelet g�r ut p� att datorn slumpar ut 2 skepp p� en spelplan som �r 4*4 rutor" <<endl;
	cout	<<"stor. Din uppgift blir sedan att f�rs�ka hitta och s�nka skeppen genom att" <<endl;
	cout	<<"skjuta p� valfri koordinat. Dina skott r�knas och n�r du har hittat och s�nkt" <<endl;
	cout	<<"b�gge skeppen, som vardera �r en ruta stort, s� har du vunnit och dina antal" <<endl;
	cout	<<"skott skrivs ut." <<endl;
	cout	<<"Du kan spela hur m�nga g�nger du vill och ditt highscore sparas i highscore-" <<endl;
	cout	<<"listan, men st�nger du av programmet s� nollst�lls tyv�rr din highscore." <<endl <<endl;
}


void nolla() //Denna funktion nollst�ller alla v�rden p� min spelplan.
{
	for(int y=0; y<4; y++) //F�r varje rad...
	{
		for(int x=0; x<4; x++) //...kontrolleras varje kolumn...
		{
			array[y][x]=0; //...och nollst�ller arrayernas v�rden.
			plan[y][x]=" ";
		}

	}
}

void slumpa() //Denna funktion slumpar fram och placerar ut skeppen.
{
	bool loop=true;
	int skepp1=0;
	int skepp2=0;
	
	while(loop) //Loop f�r att undvika att b�gge skeppen placeras p� samma ruta.
	{
      srand(time(0)); //Randomfunktionen nollst�lls.
		skepp1=rand()%16+1; //Ger skepp1 ett slumpat v�rde mellan 1 och 16.
		skepp2=rand()%16+1; //Ger skepp2 ett slumpat v�rde mellan 1 och 16.

		if(skepp1!=skepp2)
			loop=false;
	}
	
	//Beroende p� skeppens tilldelade v�rde f�r�ndras arrayen enligt nedan.
	
	if(skepp1==1)
		array[0][0]=1;
			
	else if(skepp1==2)
		array[0][1]=1;
			
	else if(skepp1==3)
		array[0][2]=1;
	
	else if(skepp1==4)
	  array[0][3]=1;
			
	else if(skepp1==5)
		array[1][0]=1;
	
	else if(skepp1==6)
		array[1][1]=1;
	
	else if(skepp1==7)
		array[1][2]=1;
	
	else if(skepp1==8)
		array[1][3]=1;
	
	else if(skepp1==9)
		array[2][0]=1;
	
	else if(skepp1==10)
		array[2][1]=1;
	
	else if(skepp1==11)
		array[2][2]=1;
	
	else if(skepp1==12)
		array[2][3]=1;
	
	else if(skepp1==13)
		array[3][0]=1;
	
	else if(skepp1==14)
		array[3][1]=1;
	
	else if(skepp1==15)
		array[3][2]=1;
	
	else if(skepp1==16)
		array[3][3]=1;
	
	if(skepp2==1)
		array[0][0]=1;
	
	else if(skepp2==2)
		array[0][1]=1;

	else if(skepp2==3)
		array[0][2]=1;
	
	else if(skepp2==4)
		array[0][3]=1;
	
	else if(skepp2==5)
		array[1][0]=1;
	
	else if(skepp2==6)
		array[1][1]=1;
	
	else if(skepp2==7)
		array[1][2]=1;
	
	else if(skepp2==8)
		array[1][3]=1;
	
	else if(skepp2==9)
		array[2][0]=1;
	
	else if(skepp2==10)
		array[2][1]=1;
	
	else if(skepp2==11)
		array[2][2]=1;
	
	else if(skepp2==12)
		array[2][3]=1;
	
	else if(skepp2==13)
		array[3][0]=1;
	
	else if(skepp2==14)
		array[3][1]=1;
	
	else if(skepp2==15)
		array[3][2]=1;
			
	else if(skepp2==16)
		array[3][3]=1;
}


void spelplan() //Denna funktion ritar ut spelplanen.
{
	
	for(int y=0; y<4; y++) //F�r varje rad...
	{
		for(int x=0; x<4; x++) //...kontrolleras varje kolumn...
		{
			if(array[y][x]==0) //...och ritar ut korrekt tecken i spelplanen.
			   plan[y][x]=" ";
			   
			else if(array[y][x]==1)
			   plan[y][x]=" ";
			
			else if(array[y][x]==2)
			   plan[y][x]="X";
			   
			else if(array[y][x]==3)
			   plan[y][x]="O";
		}
	}
	
	//F�r att arrayen ska funka i windows
	char vohorn=218; //V�nster �vre h�rn p� spelplanen
	char hohorn=191; //H�ger �vre h�rn
	char vsida=195; //V�nster sida
	char hsida=180; //H�ger sida
   char vnhorn=192; //V�nster nedre h�rn
	char hnhorn=217; //H�ger nedre h�rn
	
	/*//F�r att arrayen ska funka i Unix
	string vohorn="+"; //V�nster �vre h�rn p� spelplanen
	string hohorn="+"; //H�ger �vre h�rn
	char vsida=21; //V�nster sida
	char hsida=22; //H�ger sida
   string vnhorn="+"; //V�nster nedre h�rn
	string hnhorn="+"; //H�ger nedre h�rn*/
	
	cout	<<endl <<vohorn <<"-------------------" <<hohorn <<endl;
	cout	<<"|   | A | B | C | D |" <<endl;
	cout	<<vsida <<"-------------------" <<hsida <<endl;
	cout	<<"| 1 | " <<plan[0][0] <<" | " <<plan[0][1] <<" | " <<plan[0][2] <<" | " <<plan[0][3] <<" |" <<endl;
	cout	<<vsida <<"-------------------" <<hsida <<endl;
	cout	<<"| 2 | " <<plan[1][0] <<" | " <<plan[1][1] <<" | " <<plan[1][2] <<" | " <<plan[1][3] <<" |" <<endl;
	cout	<<vsida <<"-------------------" <<hsida <<endl;
	cout	<<"| 3 | " <<plan[2][0] <<" | " <<plan[2][1] <<" | " <<plan[2][2] <<" | " <<plan[2][3] <<" |" <<endl;
	cout	<<vsida <<"-------------------" <<hsida <<endl;
	cout	<<"| 4 | " <<plan[3][0] <<" | " <<plan[3][1] <<" | " <<plan[3][2] <<" | " <<plan[3][3] <<" |" <<endl;
	cout	<<vnhorn <<"-------------------" <<hnhorn <<endl <<endl;
}


int skott() //Denna funktion kontrollerar skottet.
{
	string skott;
	bool tmloop=true; //Kontroll av tr�ff eller miss.
	
	while(tmloop) //En loop anv�nds f�r att kontrollera ev felaktig input.
	{
		cout	<<"Ange skottets koordinat: ";
		cin	  >>skott;
		
		if(!skott[2]) //Kontrollerar om det �r r�tt antal tecken. Tecken1=0, Tecken2=1 o ENTER=2.
		{
			if(skott=="a1"||skott=="A1"||skott=="1a"||skott=="1A")
   		{
   			if(array[0][0]==0)
   			{
   				array[0][0]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
				else if(array[0][0]==1)
   			{
   				array[0][0]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="b1"||skott=="B1"||skott=="1b"||skott=="1B")
   		{
   			if(array[0][1]==0)
   			{
   				array[0][1]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[0][1]==1)
   			{
   				array[0][1]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="c1"||skott=="C1"||skott=="1c"||skott=="1C")
   		{
   			if(array[0][2]==0)
   			{
   				array[0][2]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[0][2]==1)
   			{
   				array[0][2]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="d1"||skott=="D1"||skott=="1d"||skott=="1D")
   		{
   			if(array[0][3]==0)
   			{
   				array[0][3]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[0][3]==1)
   			{
   				array[0][3]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="a2"||skott=="A2"||skott=="2a"||skott=="2A")
   		{
   			if(array[1][0]==0)
   			{
   				array[1][0]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[1][0]==1)
   			{
   				array[1][0]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="b2"||skott=="B2"||skott=="2b"||skott=="2B")
   		{
   			if(array[1][1]==0)
   			{
   				array[1][1]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[1][1]==1)
   			{
   				array[1][1]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="c2"||skott=="C2"||skott=="2c"||skott=="2C")
   		{
   			if(array[1][2]==0)
   			{
   				array[1][2]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[1][2]==1)
   			{
   				array[1][2]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="d2"||skott=="D2"||skott=="2d"||skott=="2D")
   		{
   			if(array[1][3]==0)
   			{
   				array[1][3]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[1][3]==1)
   			{
   				array[1][3]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="a3"||skott=="A3"||skott=="3a"||skott=="3A")
   		{
   			if(array[2][0]==0)
   			{
   				array[2][0]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[2][0]==1)
   			{
   				array[2][0]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="b3"||skott=="B3"||skott=="3b"||skott=="3B")
   		{
   			if(array[2][1]==0)
   			{
   				array[2][1]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[2][1]==1)
   			{
   				array[2][1]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="c3"||skott=="C3"||skott=="3c"||skott=="3C")
   		{
   			if(array[2][2]==0)
   			{
   				array[2][2]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[2][2]==1)
   			{
   				array[2][2]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="d3"||skott=="D3"||skott=="3d"||skott=="3D")
   		{
   			if(array[2][3]==0)
   			{
   				array[2][3]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[2][3]==1)
   			{
   				array[2][3]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="a4"||skott=="A4"||skott=="4a"||skott=="4A")
   		{
   			if(array[3][0]==0)
   			{
   				array[3][0]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[3][0]==1)
   			{
   				array[3][0]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="b4"||skott=="B4"||skott=="4b"||skott=="4B")
   		{
   			if(array[3][1]==0)
   			{
   				array[3][1]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[3][1]==1)
   			{
   				array[3][1]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="c4"||skott=="C4"||skott=="4c"||skott=="4C")
   		{
   			if(array[3][2]==0)
   			{
   				array[3][2]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[3][2]==1)
   			{
   				array[3][2]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   		
   		if(skott=="d4"||skott=="D4"||skott=="4d"||skott=="4D")
   		{
   			if(array[3][3]==0)
   			{
   				array[3][3]=2;
   				cout	<<endl <<"Plask!!! Tyv�rr, du missade!" <<endl;
   				return 0;
   			}
   			
   			else if(array[3][3]==1)
   			{
   				array[3][3]=3;
   				cout	<<endl <<"Kaboom!!! Grattis, du tr�ffade!" <<endl;
   				return 1;
   			}
   			
   			else
   				cout	<<endl <<"Du har ju redan skjutit h�r. F�rs�k igen!" <<endl <<endl;
   		}
   	}

		cout <<endl <<"Ogiltigt val, var god f�rs�k igen." <<endl <<endl;
		cin.clear();
		cin.ignore(1000, '\n'); //Ignorerar upp till 1000 tecken och anv�ndarens ENTER.
	}
}
