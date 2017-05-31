#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <windows.h>          // mi serve per la funzione di Sleep();
#endif
#ifdef __unix__
#include <unistd.h>
#endif // __unix__

#include <conio.h>            // Mi serve per la funzione di getch e ptuch e kbhit(funzione che realizza condizione se premo un tasto)
#include <time.h>            // srand( time( NULL ) );  num=1 +rand()%n  per numeri casuali





#define dim 18

void sleep_mil(unsigned int ms)
{
    #if defined(WIN32)
      Sleep(ms);
    #elif defined(__unix__)
      usleep(1000*ms);
    #else
      printf("Unsupported operating system!");
    #endif

}

void clear_screen ( void )
{
  DWORD n;                         /* Number of characters written */
  DWORD size;                      /* number of visible characters */
  COORD coord = {0};               /* Top left screen position */
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

  GetConsoleScreenBufferInfo ( h, &csbi );

  /* Find the number of characters to overwrite */
  size = csbi.dwSize.X * csbi.dwSize.Y;

  /* Overwrite the screen buffer with whitespace */
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

  /* Reset the cursor to the top left position */
  SetConsoleCursorPosition ( h, coord );
}

void set_color(short Color)
{
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); // Funzione che mi permette di cambiare colore del testo;
  SetConsoleTextAttribute(hCon,Color);
}

void boss(int vet[dim][dim],int dif)
{
    int i,l,num,flag,k,spara;

    srand(time(NULL));

    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==10)
            {
                num=1+rand()%dif;
                if(vet[i+1][l]==1&&l!=1&&num<dif)
                {
                    vet[i][l]=0;
                    vet[i][l-1]=6;
                }else if(vet[i+1][l]==1&&l!=dim-2&&num<dif)        // evita i proiettili del giocatore se un numero casuale e' minore di 10
                {
                    vet[i][l]=0;
                    vet[i][l+1]=6;

                }

                else{

                num=1+rand()%dif;                           //genero un numero random che provoca diversi comportamneti


                if(num==1){
                    if(vet[i][l-1]==0&&l!=1){              // comportmaneto 1: va a sinistra oppure se non può spara
                        vet[i][l]=0;
                        vet[i][l-1]=6;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6){    //controlla se ha la traiettoria di tiro libera, se ha un compagno davanti restituisce 1
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;            // genera un numero fra 1 e 10 , se è pari lo sparo va a buon fine, altrimenti non spara
                    if(spara%2==0){
                        vet[i+1][l]=5;
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                         vet[i+1][l]=8;
                        }
                        vet[i][l]=6;
                    }
                    }
                    }

                }
                if(num==2){                            // comportamento 2: va su, e se non può spara
                    if(vet[i-1][l]==0&&i!=1){
                        vet[i][l]=0;
                        vet[i-1][l]=6;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        vet[i+1][l]=5;
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                         vet[i+1][l]=8;
                        }
                        vet[i][l]=6;
                    }
                    }
                    }


                }
                if(num==3){
                    if(vet[i][l+1]==0&&l!=dim-2){         // comportamento 3: va a destra, e se non può spara
                        vet[i][l]=0;
                        vet[i][l+1]=6;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        vet[i+1][l]=5;
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                         vet[i+1][l]=8;
                        }
                        vet[i][l]=6;
                    }
                    }
                    }


                }
                if(num==4){
                    if(vet[i+1][l]==0&&i!=(dim/2)-2){
                        vet[i][l]=0;
                        vet[i+1][l]=6;                // comportamento 4: va giu, e se non può spara
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        vet[i+1][l]=5;
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                         vet[i+1][l]=8;
                        }
                        vet[i][l]=6;
                    }
                    }
                    }

                }
                if(num==5){
                    flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6){    // comportamento 5: spara, ovviamente evitando se davanti a se ha un alleato
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        vet[i+1][l]=5;
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                         vet[i+1][l]=8;
                        }
                        vet[i][l]=6;
                    }
                    }
                }
                }

                }


        }
    }
    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==6){
                vet[i][l]=10;
            }
        }
    }



}

void ia_boss2(int vet[dim][dim],int dif)
{
    int i,l,num,flag,k,spara;

    srand(time(NULL));

    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==14)
            {
                if((vet[i-1][l]==5&&vet[i][l-1]==0)||(vet[i-1][l]==15&&vet[i][l-1]==0))
                {
                    vet[i][l]=0;
                    vet[i][l-1]=6;
                                               // questi due if servono perchè la navicella eviti un proiettile del compagno, se è possibile

                }else if((vet[i-1][l]==5&&vet[i][l+1]==0)||(vet[i-1][l]==15&&vet[i][l+1]==0))
                {
                    vet[i][l]=0;
                    vet[i][l+1]=6;
                                              // questi due if servono perchè la navicella eviti un proiettile del compagno, se è possibile


                }else{
                num=1+rand()%dif;
                if(vet[i+1][l]==1&&l!=1&&num<dif&&vet[i][l-1]==0)
                {
                    vet[i][l]=0;
                    vet[i][l-1]=6;
                }else if(vet[i+1][l]==1&&l!=dim-2&&num<dif&&vet[i][l+1]==0)        // evita i proiettili del giocatore se un numero casuale e' minore di 10
                {
                    vet[i][l]=0;
                    vet[i][l+1]=6;

                }

                else{

                num=1+rand()%dif;                           //genero un numero random che provoca diversi comportamneti


                if(num==1){
                    if(vet[i][l-1]==0&&l!=1){              // comportmaneto 1: va a sinistra oppure se non può spara
                        vet[i][l]=0;
                        vet[i][l-1]=6;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==14||vet[k][l]==6){    //controlla se ha la traiettoria di tiro libera, se ha un compagno davanti restituisce 1
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;            // genera un numero fra 1 e 10 , se è pari lo sparo va a buon fine, altrimenti non spara
                    if(spara%2==0){
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=5;
                        }
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=15;
                        }
                        vet[i][l]=6;
                    }
                    }
                    }

                }
                if(num==2){                            // comportamento 2: va su, e se non può spara
                    if(vet[i-1][l]==0&&i!=1){
                        vet[i][l]=0;
                        vet[i-1][l]=6;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==14||vet[k][l]==6){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=5;
                        }
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=15;
                        }
                        vet[i][l]=6;
                    }
                    }
                    }


                }
                if(num==3){
                    if(vet[i][l+1]==0&&l!=dim-2){         // comportamento 3: va a destra, e se non può spara
                        vet[i][l]=0;
                        vet[i][l+1]=6;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==14||vet[k][l]==6){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=5;
                        }
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=15;
                        }
                        vet[i][l]=6;
                    }
                    }
                    }


                }
                if(num==4){
                    if(vet[i+1][l]==0&&i!=(dim/2)-2){
                        vet[i][l]=0;
                        vet[i+1][l]=6;                // comportamento 4: va giu, e se non può spara
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==14||vet[k][l]==6){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=5;
                        }
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=15;
                        }
                        vet[i][l]=6;
                    }
                    }
                    }

                }
                if(num==5){
                    flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==14||vet[k][l]==6){    // comportamento 5: spara, ovviamente evitando se davanti a se ha un alleato
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=5;
                        }
                        vet[i][l]=6;
                    }else{
                        if(vet[i+2][l]==0){
                          vet[i+1][l]=15;
                        }
                        vet[i][l]=6;
                    }
                    }
                }
                }

                }
            }


        }
    }
    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==6){
                vet[i][l]=14;
            }
        }
    }


}

void artificial_intelligence (int vet[dim][dim],int dif)         
// Function that manages computer moves for each opposing ship
{
    int i,l,num,flag,k,spara;

    srand(time(NULL));

    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==3||vet[i][l]==12)
            {
                if(vet[i-1][l]==5&&vet[i][l-1]==0)
                {
                    if(vet[i][l]==3)
					{
                       vet[i][l-1]=6;
                    }
					else
					{
                        vet[i][l-1]=13;
                    }
                    vet[i][l]=0;                         
                  // These two if they serve because the ship avoids a bullet bullet if it is possible.
                }
				else if(vet[i-1][l]==5&&vet[i][l+1]==0)
                {
                    if(vet[i][l]==3)
					{
                      vet[i][l+1]=6;
                    }
					 else
					{
                       vet[i][l+1]=13;
                     }
                    vet[i][l]=0;
                }
				else
                {

					num=1+rand()%dif;                           
					// I generate a random number that causes different behaviors.

					// Behave 1: go left or if he can not shoot
					if(num==1)
					{
						if(vet[i][l-1]==0&&l!=1)
						{
							if(vet[i][l]==3)
							{
							   vet[i][l-1]=6;
							}
							else
							{
								vet[i][l-1]=13;
							}               
								vet[i][l]=0;
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
								{    // Check if he has the free throw trajectory, if he has a front mate returns 1
									flag=1;
								}
							}
							if(flag==0)
							{
									spara=1+rand()%10;           
									// Generates a number between 1 and 10, if it is equal the shot fails, otherwise it does not shoot.
								if(spara%2==0)
								{
											if(vet[i+2][l]==0)
											{
												vet[i+1][l]=5;
											}
									if(vet[i][l]==3)
									{
									   vet[i][l]=6;
									}
									else
									{
										vet[i][l]=13;
									}
								}
							}
						}
					}
					// Behavior 2: go on, and if it can not shoot
					if(num==2)
					{                         
						if(vet[i-1][l]==0&&i!=1)
						{
							if(vet[i][l]==3)
							{
							   vet[i-1][l]=6;
							}
							else
							{
								vet[i-1][l]=13;
							}
								vet[i][l]=0;
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
								{
									flag=1;
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;
								if(spara%2==0)
								{
									 if(vet[i+2][l]==0)
									  {
											vet[i+1][l]=5;
									  }
									  if(vet[i][l]==3)
									  {
									   vet[i][l]=6;
									  }
									  else
									  {
										vet[i][l]=13;
									  }
								}
							 }
						}
					}
					// Behavior 3: Go to the right, and if he can not shoot
					if(num==3)
					{
						if(vet[i][l+1]==0&&l!=dim-2)
						{
							if(vet[i][l]==3)
							{
							   vet[i][l+1]=6;
							}
							else
							{
								vet[i][l+1]=13;
							}                                      
								vet[i][l]=0;
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
								{
									flag=1;
								}
							}
							if(flag==0)
							{
									spara=1+rand()%10;
								if(spara%2==0)
								{
										 if(vet[i+2][l]==0)
										 {
												vet[i+1][l]=5;
										  }
										if(vet[i][l]==3)
										{
										   vet[i][l]=6;
										}
										else
										{
											vet[i][l]=13;
										}
								}
							}
						}
					}

					 // Behavior 4: go down, and if he can not shoot
					if(num==4)
					{
						if(vet[i+1][l]==0&&i!=(dim/2)-2)
						{
							if(vet[i][l]==3)
							{
							   vet[i+1][l]=6;
							}
							else
							{
								vet[i+1][l]=13;
							}
								vet[i][l]=0;                   
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
								{
									flag=1;
								}
							}
							if(flag==0)
							{
									spara=1+rand()%10;
								if(spara%2==0)
								{
									 if(vet[i+2][l]==0)
									  {
										 vet[i+1][l]=5;
									  }
									 if(vet[i][l]==3)
									 {
									   vet[i][l]=6;
									 }
									 else
									 {
										vet[i][l]=13;
									 }
								}
							}
						}
					}

					//Behavior 5: shoot, obviously avoiding if in front of you has an ally.
					if(num==5)
					{
						flag=0;
						for(k=i+1;k<dim;k++)
						{
							if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
							{   
								flag=1;
							}
						}
						if(flag==0)
						{
							spara=1+rand()%10;
							if(spara%2==0)
							{
								if(vet[i+2][l]==0)
								 {
									vet[i+1][l]=5;
								 }
								 if(vet[i][l]==3)
								 {
								   vet[i][l]=6;
								 }
								 else
								 {
									vet[i][l]=13;
								 }
							 }
						}
					}
                }
            }
        }
    }
// BOMBARDIERE INTELLIGENCE
    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==7)
            {
                if(vet[i-1][l]==8&&vet[i][l-1]==0)
                {
                    vet[i][l]=0;                             
					// These two if they serve because the ship avoids a bullet bullet if it is possible.
                    vet[i][l-1]=9;
                }
				else if(vet[i-1][l]==8&&vet[i][l+1]==0)
                {
                    vet[i][l]=0;
                    vet[i][l+1]=9;
                }
				else
                {
					num=1+rand()%dif;                          
					// I generate a random number that causes different behaviors.

					// Behave 1: go left or if he can not shoot
					if(num==1)
					{
						if(vet[i][l-1]==0&&l!=1)
						{              
							vet[i][l]=0;
							vet[i][l-1]=9;
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==7||vet[k][l]==9)
								{     
									// Check if he has the free throw trajectory, if he has a front mate returns 1
									flag=1;
								}
							}
							if(flag==0)
							{
									spara=1+rand()%10;           
									// Generates a number between 1 and 10,
									//if it is equal the shot fails, otherwise it does not shoot
									
									if(spara>7)
									{
									  if(vet[i+2][l]==0)
									  {
										vet[i+1][l]=8;
									  }
										vet[i][l]=9;
									}
							}
						}
					}
				
				// Behavior 2: go on, and if it can not shoot
                if(num==2)
				{                           
                    if(vet[i-1][l]==0&&i!=1)
					{
                        vet[i][l]=0;
                        vet[i-1][l]=9;
                    }
					else
					{
                        flag=0;
						for(k=i+1;k<dim;k++)
						{
							if(vet[k][l]==7||vet[k][l]==9)
							{
								flag=1;
							}
						}
						if(flag==0)
						{
								spara=1+rand()%10;
								if(spara>7)
								{
									if(vet[i+2][l]==0)
									{
									vet[i+1][l]=8;
									}
									vet[i][l]=9;
								}
						}
                    }
                }
				
				// Behavior 3: Go to the right, and if he can not shoot
                if(num==3)
				{
                    if(vet[i][l+1]==0&&l!=dim-2)
					{         
                        vet[i][l]=0;
                        vet[i][l+1]=9;
                    }
					else
					{
                        flag=0;
						for(k=i+1;k<dim;k++)
						{
							if(vet[k][l]==7||vet[k][l]==9)
							{
								flag=1;
							}
						}
						if(flag==0)
						{
								spara=1+rand()%10;
								if(spara>7)
								{
									if(vet[i+2][l]==0)
									{
									vet[i+1][l]=8;
									}
									vet[i][l]=9;
								}
						}
                    }
                }

				//Behavior 4: go down, and if he can not shoot
                if(num==4)
				{
                    if(vet[i+1][l]==0&&i!=(dim/2)-2)
					{
                        vet[i][l]=0;
                        vet[i+1][l]=9;                
                    }
					else
					{
                        flag=0;
						for(k=i+1;k<dim;k++)
						{
							if(vet[k][l]==7||vet[k][l]==9)
							{
								flag=1;
							}
						}
						if(flag==0)
						{
								spara=1+rand()%10;
								if(spara>7)
								{
									if(vet[i+2][l]==0)
									{
									vet[i+1][l]=8;
									}
									vet[i][l]=9;
								}
						}
					}
                }
				
				// Behavior 5: shoot, obviously avoiding if in front of you has an ally
                if(num==5)
				{
                    flag=0;
                    for(k=i+1;k<dim;k++)
					{
                        if(vet[k][l]==7||vet[k][l]==9)
						{    
                            flag=1;
                        }
                    }
                    if(flag==0)
					{
                            spara=1+rand()%10;
							if(spara%2==0)
							{
								if(vet[i+2][l]==0)
								{
								vet[i+1][l]=8;
								}
								vet[i][l]=9;
							}
                    }
                }
                }
            }
        }
    }


    for(i=0;i<dim;i++)
	{
        for(l=0;l<dim;l++)
		{
            if(vet[i][l]==6)
			{
                vet[i][l]=3;
            }
			else if(vet[i][l]==9)
			{
                vet[i][l]=7;
            }
			else if(vet[i][l]==13)
			{
                vet[i][l]=12;
            }
        }
    }
}

int Victory_condition(int vet[dim][dim])
// Function to verify the player's win or defeat condition
{
    int i,l,flag=0,player=0;              // Variable initialization

    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==3||vet[i][l]==7||vet[i][l]==10||vet[i][l]==12||vet[i][l]==14)
			{  // I seek the presence of both the player and the enemy on the playing field
                flag=1;               // There is a flag if I find an enemy
            }
			if(vet[i][l]==2)
			{
                player=1;            // Another flag if I find the player
            }
        }
    }

    if(flag==1&&player==1)
    {
        return 0;
    }
	else if(flag==0&&player==1)
	{  // According to who was found on the field, the function returns different values
        return 1;
    }
	else if(flag==1&&player==0)
	{
        return 2;
    }
	else
	{
        return 3;
    }
}


void mossa_giocatore(int vet[dim][dim],int azione,int sound)                    // Funzione per le azioni che può fare il giocatore, premendo sul tastierino numerico
{


    int i,l;
    switch(azione)
    {
    case 52:
        for(i=0;i<dim;i++){
            for(l=0;l<dim;l++){                                     // 52 asci sta per 4, ovvero azione per andare a sinistra
                if(vet[i][l]==2){
                        if(l>1){
                    vet[i][l]=0;
                    vet[i][l-1]=2;
                        }
                }
            }
        }

        break;
    case 54:
        for(i=0;i<dim;i++){
            for(l=dim;l>0;l--){
                if(vet[i][l]==2){                             // 54 asci sta per 6, ovvero azione per andare a destra
                        if(l<dim-2){
                    vet[i][l]=0;
                    vet[i][l+1]=2;

                }
            }
         }
        }

        break;
    case 53:
        for(i=0;i<dim;i++){
            for(l=0;l<dim;l++){                           // 53 asci sta per 5, ovvero azione per sparare
                if(vet[i][l]==2){
                    vet[i-1][l]=1;
                    if (sound==1){
                    Beep(950,25);
                    }

                }
            }
        }

        break;
    default:
         if (sound==1){
        Beep(300,25);
        }

    }



}

void livelli(int vet[dim][dim],int lv)
{
    int i,l;

    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){               // Svuoto il campo
            vet[i][l]=0;
        }
    }

    switch(lv)
    {
    case 1:
    vet[dim-2][(dim/2)-1]=2;
    vet[3][10]=3;


     for(i=1;i<2;i++){
        for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=3;
            l++;
        }
     }

        break;
    case 2:
    vet[dim-2][(dim/2)-1]=2;

     for(i=1;i<3;i++){
        if(i==1){
         for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=3;
            l++;
        }
        }
        if(i==2){
            for(l=2;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=3;
            l++;
        }
        }
     }
      break;
    case 3:
    vet[dim-2][(dim/2)-1]=2;
    vet[3][10]=7;


     for(i=1;i<2;i++){
        for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=7;
            l++;
        }
     }



        break;
    case 4:
        vet[dim-2][(dim/2)-1]=2;
        vet[1][(dim/2)-1]=10;
        break;
    case 5:
        vet[dim-2][(dim/2)-1]=2;
        vet[3][10]=12;


       for(i=1;i<2;i++){
          for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
              vet[i][l]=12;
              l++;
          }
       }

        break;
    case 6:
         vet[dim-2][(dim/2)-1]=2;

     for(i=1;i<3;i++){
        if(i==1){
         for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=12;
            l++;
        }
        }
        if(i==2){
            for(l=2;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=12;
            l++;
        }
        }
     }
        break;
    case 7:
        vet[dim-2][(dim/2)-1]=2;
        vet[1][(dim/2)-4]=14;
        vet[1][(dim/2)+4]=14;
        break;
    case 8:
        vet[dim-2][(dim/2)-1]=2;
         for(i=1;i<4;i++){
        if(i==1){
         for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=3;
            l++;
        }
        }
        if(i==2){
            for(l=2;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=3;
            l++;
        }
        }
        if(i==3){
            for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=3;
            l++;
        }
        }
     }
        break;
    case 9:
        vet[dim-2][(dim/2)-1]=2;
         for(i=1;i<4;i++){
        if(i==1){
         for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=12;
            l++;
        }
        }
        if(i==2){
            for(l=2;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=12;
            l++;
        }
        }
        if(i==3){
            for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=12;
            l++;
        }
        }
     }
        break;
    case 10:
     vet[dim-2][(dim/2)-1]=2;

     for(i=1;i<3;i++){
        if(i==1){
         for(l=1;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=7;
            l++;
        }
        }
        if(i==2){
            for(l=2;l<dim-1;l++){          //Inserisco i nemici secondo un algoritmo
            vet[i][l]=7;
            l++;
        }
        }
     }
      break;
    case 11:
        vet[dim-2][(dim/2)-1]=2;
        vet[1][(dim/2)-4]=14;
        vet[1][(dim/2)+4]=14;
        vet[1][(dim/2)]=14;
        break;


    }


}

void disegna_schermo(int vet[dim][dim],int punt,int vit,int lv)                   // Funzione che disegna il campo di gioco da un vettore[n][n]
{
    int i,l;

    printf(" vite: %d       (%d)     punteggio: %d",vit,lv,punt);

    for(i=0;i<dim;i++){
            printf("\n");
        for(l=0;l<dim;l++){

            if(i==0){
                printf(" -");                             //secondo quali valori trova nel vettore sa se disegnare il giocatore, i nemici o gli altri aspetti grafici
            }else if(i==dim-1){
                printf(" -");
            }else if(l==0){
                printf(" | ");
            }else if(l==dim-1){
                printf(" | ");
            }
            else if(vet[i][l]==0){
                printf("  ");
            }else if(vet[i][l]==1){
                printf(" |");
            }else if(vet[i][l]==2){
                set_color(11);
                printf(" A");
                set_color(15);
            }else if(vet[i][l]==3){
                set_color(14);
                printf(" W");
                set_color(15);
            }else if(vet[i][l]==4){
                set_color(12);
                printf(" @");
                set_color(15);
            }else if(vet[i][l]==5){
                set_color(6);
                printf(" U");
                set_color(15);
            }else if(vet[i][l]==7){
                set_color(2);
                printf(" V");
                set_color(15);
            }else if(vet[i][l]==8){
                set_color(10);
                printf(" o");
                set_color(15);
            }else if(vet[i][l]==10){
                set_color(3);
                printf(" Y");
                set_color(15);
            }else if(vet[i][l]==12){
                set_color(4);
                printf(" W");
                set_color(15);
            }else if(vet[i][l]==14){
                set_color(5);
                printf(" X");
                set_color(15);
            }else if(vet[i][l]==15){
                set_color(14);
                printf(" *");
                set_color(15);
            }else if(vet[i][l]==16){
                set_color(12);
                printf(" @");
                set_color(15);
            }
        }
    }


}

void esplosione(int vet[dim][dim])                       // funzione che cancella le esplosioni dal vattore del campo una volta innescate
{
    int i,l;
    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==4){
                vet[i][l]=16;
            }else if(vet[i][l]==16){
                vet[i][l]=0;
            }
        }
    }


}

void proiettile(int vet[dim][dim],int sound)           // funzione che calcola i movimenti dei proiettili saprati sia dal giocatore che dal nemico
{
    int i,l;
    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==1){
                    if(i==1){               // cerco i proiettili del giocatore e li faccio avanzare
                        vet[i][l]=0;
                    }else {
                      vet[i][l]=0;
                      vet[i-1][l]=1;
                    }
            }
        }
    }
    for(i=dim-2;i>0;i--){
        for(l=0;l<dim;l++){
            if(vet[i][l]==5){         // cerco i proiettili nemici e li faccio avanzare
                if(i==dim-2){
                    vet[i][l]=0;
                }else{
                    vet[i][l]=0;
                    vet[i+1][l]=5;
                }
            }
        }
    }
    for(i=dim-2;i>0;i--){                // bombe bombardieri
        for(l=0;l<dim;l++){
            if(vet[i][l]==8){         // cerco i proiettili nemici e li faccio avanzare
                if(i==dim-2){
                    vet[i][l]=4;
                    vet[i][l-1]=4;        //toccano il fondo esplodono
                    vet[i][l+1]=4;
                    if (sound==1){
                    Beep(150,50);
                    }
                }else{
                    vet[i][l]=0;
                    vet[i+1][l]=8;
                }
            }
        }
    }
     for(i=dim-2;i>0;i--){                // bombe boss2
        for(l=0;l<dim;l++){
            if(vet[i][l]==15){         // cerco i proiettili e li faccio avanzare
                if(i==dim-2){
                    vet[i][l]=4;
                    vet[i][l-1]=4;
                    vet[i][l-2]=4;    //toccano il fondo esplodono
                    vet[i][l+1]=4;
                    vet[i][l+2]=4;
                    if (sound==1){
                    Beep(150,50);
                    }
                }else{
                    vet[i][l]=0;
                    vet[i+1][l]=15;
                }
            }
        }
    }



}

int attacked(int vet[dim][dim],int sound)          // funzione che controlla se un nemico o il giocatore è stato colpito, e nel caso cambia il suo valore con quello dell'esplosione
{
    int i,l,point=0;                   // variabili fra cui quella del pointeggio

    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if((vet[i][l]==3&&vet[i+1][l]==1)||(vet[i][l]==12&&vet[i+1][l]==1)){
                if(vet[i][l]==12){
                    vet[i][l]=3;
                    vet[i+1][l]=0;
                    point+=2;
                     if (sound==1){
                    Beep(150,25);
                }
                }else{

                vet[i][l]=4;                       // controlla se il nemico è stato colpito, se si lo trasforma in esplosione e fa beep e aggiunge pointeggio
                vet[i+1][l]=0;
                point+=2;
                if (sound==1){
                Beep(250,50);
                }
                }

            }else if(vet[i][l]==7&&vet[i+1][l]==1){
                vet[i][l]=4;                       // controlla se il nemico bombardiere è stato colpito, se si lo trasforma in esplosione e fa beep
                vet[i+1][l]=0;
                point+=3;
                if (sound==1){
                Beep(250,50);
                }
        }else if((vet[i][l]==10&&vet[i+1][l]==1)||(vet[i][l]==14&&vet[i+1][l]==1)){
                vet[i][l]=4;                       // controlla se il boss è stato colpito
                vet[i+1][l]=0;
                point+=25;
                if (sound==1){
                Beep(250,50);
                }
        }
    }
    }

    for(i=dim-2;i>0;i--){
        for(l=0;l<dim;l++){
            if(vet[i][l]==2&&vet[i-1][l]==5){       // controlla se è stato colpito il giocatore
                vet[i][l]=4;
                vet[i-1][l]=0;
                if (sound==1){
                Beep(250,50);
                }
            }
             if(vet[i][l]==2&&vet[i-1][l]==8){       // controlla se è stato colpito il giocatore dalle bombe
                vet[i][l]=4;
                vet[i-1][l]=0;
                if (sound==1){
                Beep(250,50);
                }
                }
            if(vet[i][l]==2&&vet[i-1][l-1]==8){       // controlla se è stato colpito il giocatore dalle bombe
                vet[i][l]=4;
                vet[i-1][l]=0;
                vet[i][l-1]=4;
                vet[i][l+1]=4;
                if (sound==1){
                Beep(250,50);
                }
                }
            if(vet[i][l]==2&&vet[i-1][l+1]==8){       // controlla se è stato colpito il giocatore dalle bombe
                vet[i][l]=4;
                vet[i-1][l]=0;
                vet[i][l-1]=4;
                vet[i][l+1]=4;
                if (sound==1){
                Beep(250,50);
                }
                }
            if(vet[i][l]==2&&vet[i-1][l]==15){       // controlla se è stato colpito il giocatore dalle bombe del boss
                vet[i][l]=4;
                vet[i-1][l]=0;
                if (sound==1){
                Beep(250,50);
                }
                }
        }
    }

    return point;


}

int main()                                    // funzione principale del gioco
{
    int cate[dim][dim],i,l,move=0,condition,speed=100,diff;
    int victory=0, score, final_game=0, level, sound, life;      // Inizializzo le varie variabili del main, fra cui anche il puntatore per il file delle impostazioni
    int selection=0,record;
    char name[dim];
    FILE *fp;

    fp=fopen("dati.dat","r");
    if(fp==NULL){
        printf("\nERROR OPENING FILE!");
        sleep_mil(3000);                                                           // apertura e lettura del file delle impostazioni
        return 1;
    }

    if(fscanf(fp,"%d %d %d %d %s",&speed,&diff,&sound,&record,name)==EOF){
        printf("\nERROR READING FILE!");
        sleep_mil(3000);
        return 1;
    }
    fclose(fp);


    while(selection!=5)                                                  //  ciclo while dei menu finche' non si seleziona l'uscita dal gioco
    {
         system("cls");

           fp=fopen("dati.dat","r");
         if(fp==NULL){
             printf("\nERROR OPENING FILE!");
             sleep_mil(3000);                                                           // apertura e lettura del file delle impostazioni
             return 1;
         }

         if(fscanf(fp,"%d %d %d %d %s",&speed,&diff,&sound,&record,name)==EOF){
             printf("\nERROR READING FILE!");
             sleep_mil(3000);
             return 1;
         }
         fclose(fp);

         printf("\n     SPACE INVATERS v0.4                   \n");
         printf("\n                                            ");
         printf("\n                                            ");           //stampa a schermo il menu del gioco e attende la scelta del giocatore
         printf("\n   1)New Game                               ");
         printf("\n   2)Game Guide                             ");
         printf("\n   3)Setting                                ");
         printf("\n   4)Credits                                ");
         printf("\n   5)Exit                                 \n");
         sleep_mil(500);
         Beep(450,200);
         printf("\n\n  choice: ");
         fflush(stdin);
         scanf("%d",&selection);


         switch(selection)
         {

             case 1:
             life=3;
             level=1;
             score=0;
             final_game=0;
             printf("\n Get ready to start the game!");
             sleep_mil(2000);
             system("cls");                        // pulisco schermo



             while(final_game==0)
             {

                 system("cls");
                 livelli(cate,level);                                                      // seleziono il livello con l'apposita funzione
                 victory=0;
                 disegna_schermo(cate,score,life,level);      // disegno la schermata di gioco ed aspetto prima dell'inizio della partita
                 sleep_mil(1500);

             while(victory==0)                   // ciclo while che fa continuare la partita finchè qualcuno non vince
             {
                     clear_screen();
                     disegna_schermo(cate,score,life,level);                 // ridisegno la schermata di gioco

                     condition=0;                          // imposto la condizione della pressione tasto a zero


                     sleep_mil(speed);                          // velocità di gioco grazie ad uno sleep del programma
                     condition=_kbhit();                    // se durante il periodo si è premuto un tasto allora viene imagazzinato il valore come mossa del giocatore,
                     if(condition==1){                     // altrimenti va avanti il gioco
                         move=_getch();
                         mossa_giocatore(cate,move,sound);
                     }


                     if(level==4){
                         boss(cate,diff);
                     }else if(level==7||level==11||level==18||level==22||level==29||level==33){
                         ia_boss2(cate,diff);
                     }else{
                     artificial_intelligence(cate,diff);       // avvio l'intelligenza artificiale
                     }
                     esplosione(cate);                     // calcello le esplosioni se ci sono
                     score+=attacked(cate,sound);                        // controllo chi è stato colpito e calcola il punteggio
                                          // eseguo la funzione dello spostamento dei proiettili


                     clear_screen();                          //pulisco nuovamente lo schermo, e ridisegno con i nuovi cambiamenti che ci sono stati
                     disegna_schermo(cate,score,life,level);
                     proiettile(cate,sound);

                     victory=Victory_condition(cate);


                     if(victory==1){
                         printf("\n PLAYER'S WINNING !!!\n");
                         if(score>record&&level==33){
                             record=score;
                             printf("\n Enter the name for records: ");
                             scanf("%s",name);
                         }
                         sleep_mil(1000);                                  // controllo le condizioni di vittoria, se nessuna è rispettata proseguo col gioco
                     }else if(victory==2&&life>1){                     // giocatore morto, ma ha ancora vite, quindi respawn del giocatore
                         system("cls");
                         disegna_schermo(cate,score,life,level);
                         life--;
                         sleep_mil(1000);
                         for(i=(dim-2);i>(dim/2);i--){
                           for(l=0;l<dim;l++){               // Svuoto il campo di proiettili sorpa il giocatore
                         cate[i][l]=0;
                         }
                       }
                       cate[dim-2][(dim/2)-1]=2;             // respawn
                       system("cls");
                       disegna_schermo(cate,score,life,level);
                       sleep_mil(500);
                       victory=0;


                     }else if(victory==2){
                         life--;
                         system("cls");                            // morte giocatore senza vite
                         disegna_schermo(cate,score,life,level);
                         printf("\n THE PLAYER LOSE !!!\n");
                         if(score>record){
                             record=score;
                             printf("\n Enter the name for records: ");
                             scanf("%s",name);
                         }
                         sleep_mil(1000);
                     }else if(victory==3){
                         printf("\n ERROR SEARCH CONDITION VOCTORY!!!\n");
                         sleep_mil(3000);
                     }


                 }
                 if(victory==1&&level<11){
                     level++;
                     printf("\nPREPARE FOR THE NEXT LEVEL!!!\n");         // vittoria e avanzamento livello
                     Sleep(3000);
                     if(diff==10) score+=10;
                     if(diff==7) score+=20;
                     if(level%3==0){
                         printf("  LIFE BONUS !!!\n");
                         sleep_mil(1000);
                         life++;
                     }

                 }else{
                     system("cls");
                     if(victory==1) printf("\n Congratulations, you finished I'm fucking game!!!!");
                     printf("\n Press 1 to play again or a key to return to the menu: ");
                     sleep_mil(500);
                     fflush(stdin);
                     scanf("%d",&selection);
                     if(selection!=1) selection=6;
                     final_game=1;
                 }
             }
             break;

             case 2:
               system("cls");
				printf("\n Game controls:                             ");
                printf("\n Use the numeric keypad to play             ");
                printf("\n 4: To go left                              ");
                printf("\n 6: To go right                             ");
                printf("\n 5: To shoot                             \n ");
                printf("\n Lower the enemy spaceships to win, to the initial 3 lives.\n");
                printf("\n Press a key to go back                   : ");
               fflush(stdin);
               scanf("%d",&selection);
               selection=6;
              break;

             case 3:
               system("cls");
               printf("\n Select the speed of play: 1) Normal 2) Fast 3) Crazy\n speed': ");
               scanf("%d",&speed);
             if(speed==2){
                 speed=50;
             }else if(speed==3){
                 speed=25;
             }else if(speed==4){
                 speed=50;
                 life=15;
             }
             else{
                 speed=75;
             }
             printf("\n Select difficulty: 1) easy 2) normal 3) difficult\n difficulty': ");
             scanf("%d",&diff);
             if(diff==3){
                 diff=7;
             }else if(diff==2){
                 diff=10;
             }else if(diff==4){
                 diff=35;
             }
             else{
                 diff=15;
             }
             printf("\n Select sound: 1) on 2) off sound: ");
             scanf("%d",&sound);

              printf("\n Press a key to go back: ");
              scanf("%d",&selection);
              selection=6;
              break;

              case 4:
                  system("cls");
                  printf("\n       SPACE INVATERS VER. 0.4  \n");
                  printf("\n Game made for boredom and for various fucking sticks.");
                  printf("\n Completely programmed in c from the only and inimitable I'm fucking!");
                  printf("\n All rights reserved to me in the event of unauthorized use of this program");
                  printf("\n You will be lynched by a crowd of penguins!!!");
                  printf("\n\n Current record: %d performed by %s",record,name);
                  printf("\n Press a key to go back: ");
                  fflush(stdin);
                  scanf("%d",&selection);
                  selection=6;
                  break;

              case 5:
                  printf("\n Get out of the game... missed!!!");
                  sleep_mil(1000);
                 break;

         }

    }

    fp=fopen("dati.dat","w");
    if(fp==NULL){
        printf("\n ERROR OPENING FILE!");
        sleep_mil(3000);
        return 1;
    }
    fprintf(fp,"%d %d %d %d %s",speed,diff,sound,record,name);
    fclose(fp);




    printf("\n Thank you for playing!\n");
    sleep_mil(3000);
    return 0;
}

