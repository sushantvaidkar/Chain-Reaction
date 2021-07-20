
#include <iostream>
#include <windows.h>
#include <graphics.h>

using namespace std;

//global char grid for storing chars at positions
char a[10][10][3];
//int extra;

const int cellsize = 50;

//First player char and second player char
char p1,p2;

//displays grid
void board();

//put chars in desired position
char put(int, int , char );

//check for winning condition
int checkwin(char );

//multiply chars after specific count
void multiply(char,int,int );

//Main Function
int main()
{
    int gd = DETECT, gm;

    //initgraph(&gd,&gm,"");
    initwindow(570,600,"Chain Reaction");

    //Initialization of grid
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            for (int k=0;k<3;k++)
            {
                a[i][j][k]=' ';
            }
        }
    }

    //Basic variables for taking input of row and col position
    int r,c,counter=0,i=0;

    outtextxy(100,100,"Welcome to chain reaction game");
    outtextxy(100,300,"Follow instructions in console");

    cout<<"\t\tPLAYER 1\nChoose a character: ";
    cin>>p1;
    cout<<"\n\n\n\t\tPLAYER 2\nChoose a character: ";
    cin>>p2;

    //Clears the screen
    system("cls");
    cleardevice();

    //loop for continuous asking for inputs of positions
    do
    {
        //extra=1;

            //player 1
            cout<<"\t\t\tPLAYER 1 ("<<p1<<")\n\n";
            board();
            while (true)
            {
                cout <<"\n\nChoose a spot: ";
                cin>> r>> c;
                if(a[r][c][0]!=p2)
                    break;
            }
            put(r,c,p1);
            //claer console
            system("cls");
            //clear gui screen
            cleardevice();
            if(i!=0)
            {
                counter=checkwin(p2);
                if(counter==1)
                    {
                        cout<<"Player 1 Wins game\n";
                        outtextxy(100,570,"Player 1 Wins Game");
                        break;
                    }
            }

            //player 2
            cout<<"\t\t\tPLAYER 2 ("<<p2<<")\n\n";
            board();
            while (true)
            {
                cout <<"\n\nChoose a spot: ";
                cin>> r>> c;
                if(a[r][c][0]!=p1)
                    break;
            }
            put(r,c,p2);
            system("cls");
            cleardevice();
            if(i!=0)       // 2nd moves cheack
            {
                counter=checkwin(p1);
                if(counter==1)
                    {
                        cout<<"Player 2 Wins Game\n";
                        outtextxy(100,570,"Player 2 Wins Game");
                        break;
                    }
            }

          i++;
    }
    while(counter!=1);
    board();

    getch();
    closegraph();

    return 0;
}

//Function to display grid in graphics
void graphics_board()
{

	int i,j;
    for(i = 0; i <10; i++)
    {
        for(j=0;j<10;j++)
        {
            rectangle(i*cellsize, j * cellsize,i*cellsize + cellsize,j * cellsize + cellsize);
            if(a[i][j][0]==p1)
            {
                setfillstyle(SOLID_FILL,RED);
                circle(j*cellsize+cellsize/2,i*cellsize+cellsize/2,cellsize/5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(j*cellsize+cellsize/2,i*cellsize+cellsize/2,WHITE);
            }
            if(a[i][j][1]==p1)
            {
                setfillstyle(SOLID_FILL,RED);
                circle(j*cellsize+cellsize/2+10,i*cellsize+cellsize/2+10,cellsize/5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(j*cellsize+cellsize/2+10,i*cellsize+cellsize/2+10,WHITE);
            }
            if(a[i][j][2]==p1)
            {
                setfillstyle(SOLID_FILL,RED);
                circle(j*cellsize+cellsize/2-10,i*cellsize+cellsize/2-10,cellsize/5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(j*cellsize+cellsize/2-10,i*cellsize+cellsize/2-10,WHITE);

            }

            if(a[i][j][0]==p2)
            {
                setfillstyle(SOLID_FILL,GREEN);
                circle(j*cellsize+cellsize/2,i*cellsize+cellsize/2,cellsize/5);
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(j*cellsize+cellsize/2,i*cellsize+cellsize/2,WHITE);
            }
            if(a[i][j][1]==p2)
            {
                setfillstyle(SOLID_FILL,GREEN);
                circle(j*cellsize+cellsize/2+10,i*cellsize+cellsize/2+10,cellsize/5);
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(j*cellsize+cellsize/2+10,i*cellsize+cellsize/2+10,WHITE);
            }
            if(a[i][j][2]==p2)
            {
                setfillstyle(SOLID_FILL,GREEN);
                circle(j*cellsize+cellsize/2-10,i*cellsize+cellsize/2-10,cellsize/5);
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(j*cellsize+cellsize/2-10,i*cellsize+cellsize/2-10,WHITE);
            }
        }
    }
}

//Function to display grid
void board()
{
    cout << "       0       1       2       3       4       5       6       7       8       9\n";
    for (int i=0;i<10;i++)
    {
        cout << " " << i << " ";
        for (int j=0;j<10;j++)
        {
            cout<<"||";
            for (int k=0;k<3;k++)
            {
                cout<<a[i][j][k]<<" ";
            }
        }
        cout<<"|| "<< i<<"\n"<<endl;
    }
    cout << "       0       1       2       3       4       5       6       7       8       9";
	graphics_board();
}

//Function to put char on particular position
char put(int r, int c, char player)
{
    //Opponent char
    char opp;
    (player==p1 )? opp=p2 : opp=p1;

    //Condition for four corners
    if ((r==0 || r==9) && (c==0 || c==9))
    {
        if(a[r][c][0]==opp)   // oponant char
        {
            a[r][c][0]=player;
        }
        else if(a[r][c][0]==' ')   // if blank
            a[r][c][0]=player;
        else if (a[r][c][0]==player)  // explodes
             multiply(player,r,c);
    }
    //condition for side rows and cols
    else if ((r==0 && (c>0 && c<9)) || (r==9 && (c>0 && c<9)) || (c==0 && (r>0 && r<9)) || (c==9 && (r>0 && r<9)))
    {
        if(a[r][c][0]==opp)
        {
            if(a[r][c][1]==opp)
            {
                multiply(player,r,c);
            }
            else if(a[r][c][1]==' ')
            {
                a[r][c][0]=player;
                a[r][c][1]=player;
                cout << "right\n";
            }
        }
        else if(a[r][c][0]==' ' && a[r][c][1]==' ')    // both positions are empty
            a[r][c][0]=player;                         // put the char at that position
        else if(a[r][c][0]==player && a[r][c][1]==' ')  // if one is empty then put one at that position
            a[r][c][1]=player;
        else if(a[r][c][0]==player && a[r][c][1]==player)   // if both the positions are filled then simply multiply
            multiply(player,r,c);
    }
    //condition for any middle cell
    else
    {
        if(a[r][c][0]==opp)
        {
            if(a[r][c][1]==' ' && a[r][c][2]==' ')
            {
                a[r][c][0]=player;
                a[r][c][1]=player;
            }
             else if(a[r][c][1]==opp && a[r][c][2]==' ')
            {
                a[r][c][0]=player;
                a[r][c][1]=player;
                a[r][c][2]=player;
            }
            else if(a[r][c][1]==opp && a[r][c][2]==opp)
            {
                multiply(player,r,c);
            }
        }
        else if(a[r][c][0]==' ' && a[r][c][1]==' ' && a[r][c][2]==' ')      // if already blank put that players character
            a[r][c][0]=player;
        else if(a[r][c][0]==player && a[r][c][1]==' ' && a[r][c][2]==' ')   // if already one character is present then put 2nd one
            a[r][c][1]=player;
        else if(a[r][c][0]==player && a[r][c][1]==player && a[r][c][2]==' ') // if already two char is present then put 3rd one
            a[r][c][2]=player;
        else if(a[r][c][0]==player && a[r][c][1]==player && a[r][c][2]==player) // at the 4th chracter it will explodes
            multiply(player,r,c);
    }
}

//Function for checking win condition
int checkwin(char opp)
{
    // check if any cell contains opp char
    int g=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
               if (a[i][j][1]==opp || a[i][j][2]==opp || a[i][j][0]==opp )   //mark is p2 if we want to check win for player 1
                {
                    g++;
                    break;
                }
        }
    }
    if(g==0)
        return 1;
    else
        return 0;
}

//Function for exploding after certain count
void multiply(char player,int row, int col)
{
    //make empty at that cell
   // extra=0;    // is extra element is present or not
    a[row][col][0]=' ';
    a[row][col][1]=' ';
    a[row][col][2]=' ';

    //condition wise putting char at adjacent position
    if(row<9)
    {put( row+1, col, player);}   // not go out of range
    if(col<9)
    {put(row, col+1,player);}
    if(row>0)
    {put( row-1, col, player);}
    if(col>0)
    {put( row, col-1,player);}

}
