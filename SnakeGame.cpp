#include <bits/stdc++.h>                        // Whole Package of Libraries i.e Include Everthing.
#include <conio.h>                              // Becoz of -> _kbhit() and _getline().
#include <windows.h>                            // Becoz of -> sleep() and Background color.
using namespace std;

bool gameOver;                                  // Whether GAME is ended or not.

// -----------------------------------------------------------------------------------------------

class Snake_Game{  
    
    protected:
        int height;                            // For defining Borders -> LEFT and RIGHT.   
        int width;                             // For defining Borders -> UP and DOWN.
        int x, y, fruitX, fruitY;                       // x -> Snake x-coordinate , y -> Snake y-coordinate , fruitX -> Fruit x-coordinate , fruitY -> Fruit y-coordinate.
        int score;                                      // Total points Scored.
        enum direction{STOP=0,LEFT,RIGHT,UP,DOWN};      // Enumerated Type.
        direction Dir;                                  // *** JUST A CONCEPT ***  ----->>  DATATYPE -> direction  and  Dir is variable of that direction type.
        int snake_length;
        int tail_X[100],tail_Y[100];

    public:
        Snake_Game()    // Constructor.
        {
            height=20;
            width=35;
            snake_length=0;
        }
    
        void setup()
        {
            srand(time(NULL));                         // Help in Random Number Generation(SEQUENCE REPETTION REMOVED)
            gameOver=false;
            Dir=STOP;
            x=width/2;
            y=height/2;
            fruitX = (rand()%33)+1;                    // Random Generation of Fruit X-Coordinate.
            fruitY = (rand()%18)+1;                    // Random Generation of Fruit Y-Coordinate.
            score=0;
        }

        void draw()
        {
            system("cls");                              // Clear Screen

            for(int i=0;i<width;i++)
            {
                cout<<"#";                              // Print upper Boundries of Game.
            }
            cout<<endl;
            
            for(int i=0; i<height; i++)
            {
                for(int j=0; j<width; j++)
                {
                    if(j==0 || j==(width-1))
                    {
                        cout<<"#";                      // Print BOTH Side Boundries of Game.
                    }
                    else if(j==x && i==y)
                    {
                        cout<<"O";
                    }
                    else if(j==fruitX && i==fruitY)
                    {
                        cout<<"$";
                    }
                    else
                    {
                        bool print=false;
                        for(int z=0;z<snake_length;z++)
                        {
                            if(tail_X[z]==j && tail_Y[z]==i)
                            {
                                cout<<"o";
                                print =true;
                            }
                        }
                        if(print==false)
                        {
                            cout<<" ";
                        }                        
                    }
                }
                cout<<endl;
            }
            int q=1;
            for(int i=0;i<width;i++)
            {
                cout<<"#";
            }
            cout<<endl<<endl;
            cout<<"SCORE -->> "<<score<<endl;
            cout<<endl;
        }
    
        void input()
        {
            
            int prev1_X=tail_X[0];    
            int prev1_Y=tail_Y[0];
            
            int prev2_X,prev2_Y;
            
            tail_X[0]=x;
            tail_Y[0]=y;
            
            for(int i=1;i<snake_length;i++)
            {
                prev2_X=tail_X[i]; 
                prev2_Y=tail_Y[i]; 
                tail_X[i]=prev1_X; 
                tail_Y[i]=prev1_Y; 
                prev1_X=prev2_X;   
                prev1_Y=prev2_Y;    
            }
            
            while(_kbhit())
            {
                switch(_getch())
                {
                    case 'a':
                        Dir=LEFT;
                        break;
                    case 'd':
                        Dir=RIGHT;
                        break;
                    case 'w':
                        Dir=UP;
                        break;
                    case 's':
                        Dir=DOWN;
                        break;
                    case 'x':
                        gameOver=true;
                        break;
                }
            }
        }

        void logic()
        {
            switch(Dir)
            {
                case LEFT:
                    x--;
                    break;
                case RIGHT:
                    x++;
                    break;
                case UP:
                    y--;
                    break;
                case DOWN:
                    y++;  
                    break;
                default:
                    break;      
            }

            gameOver = (x>=width || x<=0 || y>=height || y<0) ? true:false;
            
            if(!gameOver)
            {
            	for(int i=0;i<snake_length;i++)
				{
					gameOver = (tail_X[i]==x && tail_Y[i]==y) ? true:false;
					if(gameOver)
					break;
                }
            }

            if(x==fruitX && y==fruitY)
            {
                score += 10;
                fruitX = (rand()%(width-1))+1;
                fruitY = (rand()%(height-1))+1;
                snake_length+=1;
            } 
            
        }
};

int main()
{
    Snake_Game snake;
    snake.setup();
    system("Color 70");
    while(!gameOver)
    {
        system("Color 70");
        snake.draw();
        snake.input();
        snake.logic();
    }
    getch();
    return 0;   
}
