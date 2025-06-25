#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <unistd.h>
using namespace std;
void start();
void printing_grid(int, int[][100],int , int);
void secondary(int[][100],int[][20],int[][3],int , int);
void neighbouring(int[][100],int[][20],int , int);
void live_neighbours_count(int [][100],  int[][20],int , int);
void dead_neighbours_count(int [][100],  int[][20],int , int);
void rules(int[][100],int[][20],int,int , int);
int generations_input_function();        
int cell_number();                        
void print_generations(int[][100],int,int , int); 
int sec_array[100][3];
int last=0;





int main()
{
   start();
   

    return 0;
}
void start()
{
  int row=20;
int col=20;
   int gen = generations_input_function();
    int number_of_cells = cell_number();
    int gen_count=0;
    int grid[100][100]={0};
    int a,b;
    
    for(int i=0; i<number_of_cells;i++)
    {
       
        ofstream coordinates_file("coordinates.txt");
        cout<<"enter coordinates for the various cells of the object: ";
        cin>>a;
        cin>>b;
        
       coordinates_file<<a<<b;
       grid[a][b]=1;
       coordinates_file.close();
        
        
        
    }
     
    printing_grid(number_of_cells,grid, row,  col);
    int neighborsAlive[20][20]={0};
    int neighborsDead[20][20]={0};
   

    
     for(int u=0; u<gen; u++)
     {
         system("clear");
        gen_count++;
         live_neighbours_count(grid,neighborsAlive, row,  col);
         secondary(grid,neighborsAlive,sec_array, row,  col);
    dead_neighbours_count(grid,neighborsAlive, row, col);
    neighbouring(grid,neighborsDead, row,  col);
    
    rules(grid,neighborsAlive,gen_count, row,  col); 
    sleep(1);
     }
}

int generations_input_function()
{
       int d;
    
       ofstream amna2("amnafile.txt");
       cout<<"enter the number of generations : ";
       cin>>d;
       amna2<<d;
       amna2.close();
       
       
     
       
         ifstream amna("amnafile.txt");
 

  int generations;
  
  amna>>generations;


  amna.close();

    return generations;
}




int cell_number()
{
     
     int e;
     cout<<"enter the number of cells that you want to read: ";
 cin>>e;
     return e;
    
}
void printing_grid(int number_of_cells,int grid[][100],int row, int col)
{
    

     
    
    cout<<endl<<"initial grid"<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
    {
        cout<<grid[i][j];
           }cout<<endl;
        
    }
    cout<<endl;
}
void live_neighbours_count(int grid[][100], int neighborsAlive[][20],int row, int col) {
   
    int live_cells = 0; 
    for(int i = 0; i < row; i++) 
    {
    for(int j = 0; j < col; j++) 
    {
    if(grid[i][j] == 1) 
    {
    neighborsAlive[i][j] = 0; 
    for(int x=i - 1; x<=i + 1; x++)
    {
    for(int y= j - 1; y<= j + 1; y++)
    {
    if(x>=0 && x<row && y>=0 && y<col &&!(x==i && y==j)&&grid[x][y]==1) 
    {
     neighborsAlive[i][j]++; 
     }
               }
   }
 
  
  
                live_cells++; 
       }
             }
 } 
  
}
void secondary(int grid[][100],int neighborsAlive[][20], int sec_array[][3],int row, int col)
{   
    if(last==0){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    sec_array[last][0]=i;
                    sec_array[last][1]=j;
                    sec_array[last][2]=neighborsAlive[i][j];
                    last++;
                }
            }
        }
    }
    
    for(int i=0;i<last;i++){
        int r=sec_array[i][0];
        int c=sec_array[i][1];
        if(grid[r][c]==0){
            for(int l=i;l<=last;l++){
                int temp1=sec_array[l][0];
                sec_array[l][0]=sec_array[l+1][0];
                sec_array[l+1][0]=temp1;
                
                int temp2=sec_array[l][1];
                sec_array[l][1]=sec_array[l+1][1];
                sec_array[l+1][1]=temp2;
                
                int temp3=sec_array[l][2];
                sec_array[l][2]=sec_array[l+1][2];
                sec_array[l+1][2]=temp3;
                
                
            }
            last--;
        }
    }
    
    
    
 

     

}
void dead_neighbours_count(int grid[][100], int neighborsDead[][20],int row, int col)
{
     
     int cells_dead = 0;
     
     
    for(int i = 0; i < row; i++) 
    {
    for(int j = 0; j < col; j++) 
    {
    if(grid[i][j] == 0) 
    {
    neighborsDead[i][j] = 0; 
    for(int x=i - 1; x<=i + 1; x++)
    {
    for(int y= j - 1; y<= j + 1; y++)
    {
    if(x>=0 && x<row && y>=0 && y<col &&!(x==i && y== j)&&grid[x][y]==1) 
    {
     neighborsDead[i][j]++; 
     }
               }
   }
 
  
  
                cells_dead++; 
       }
             }
 } 
 

}


void neighbouring(int grid[][100], int neighborsDead[][20],int row, int col)
{
    int nei_array[300][3]={0};
    
    
    int last=0;
    
   
    for(int i=0; i<row; i++)
    {
   for(int j=0; j<col; j++)
 {
         if(grid[i][j]==0)
{     int h=0;
    for(int x=i-1;x<=i+1;x++)
    {
        for(int y=j-1;y<=j+1;y++)
        {
            if(x >=0 && x<row && y>=0 && y<col &&!(x==i && y==j)&&grid[x][y]==1)
            {
                h++;
            }
        }
    }
        if(h>0)
        {
                     nei_array[last][0]=i;
                     nei_array[last][1]=j;
                     nei_array[last][2]=h;
         last++;
      }
               }
  }
    }
     
  
    
    
    for(int i=0; i<300;i++)
    {
      for(int j=0; j<3;j++)
    {
      nei_array[i][j]=0; 
    }  
    }
    
    
    
}

void rules(int grid[][100], int neighborsAlive[][20], int gen_count,int row, int col)
{
    int next[100][100];

    bool b = false; 
    
    
    for (int i = 0; i < row; i++)
   {
        for (int j = 0; j < col; j++)
 {
        
      next[i][j] = grid[i][j];

         if (grid[i][j]==1 &&(i==0||i==row- 1||j==0|| j== col- 1))
 {
     
                b=true;
         
                }
            
          }
      }



    if (b)
    {
         col =col + 5;
        row = row +5;   
    }

    for (int i=0; i<row; i++) 
{
        for (int j=0; j<col; j++)
 {
            if (next[i][j]== 1) 
            {
             
                if (neighborsAlive[i][j]<2 || neighborsAlive[i][j]>3)
 {
                    next[i][j] = 0;
                }
                
                    else 
                {
                       next[i][j] = 1;
              
                }
            }
            
       else 
      {
              
                if (neighborsAlive[i][j]==3) 
{
                      next[i][j] = 1;
                } 

else {
                    next[i][j] = 0;
                  }
                     }
            }
      }

  
    for (int i=0; i<row; i++)
 {
      
        for (int j=0; j<col; j++)
 {
     
            grid[i][j]=next[i][j];
        }
    }

    
     print_generations(grid,gen_count,row,col); 
    cout<<endl;

    cout<<endl;
}

void print_generations(int grid[][100], int gen_count,int row, int col)   
{
      
      
      
      cout<<endl<<"generation: "<<gen_count<<endl;
    for(int i=0; i<row; i++)
    {
   for(int j=0; j<col; j++)
    {
      cout<<grid[i][j];
    }
         cout<<endl;
    }
    
    
    
      cout<<endl;
      cout<<endl;
    
}
 
 
