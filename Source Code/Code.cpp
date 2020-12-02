#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;

 
int slotwise[6][15] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // slotwise list of subjects slotwise[0] conins list of subjects in slot 1
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} 
};

int room[6][15] = { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 
  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 
  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 
  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 
  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 
  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15} 
};

int slw[6] = { 0, 0, 0, 0, 0, 0 }; // Number of subjects in each slot e.g slot[0] tells number of subjects in slot number 1;

int islw[6] = { 0, 0, 0, 0, 0, 0 }; // Number of subjects in each slot till previous year e.g slot[0] tells number of subjects in slot number 1;


 
 
 
 
void
NGC (int **ar, int n, int *Codes, int *Credits)
{
  
int V = n;
  
int i = 0, k = 0, j = 0, l = 0;
  
int *a = new int (n); // color-assigned 
  
a[0] = 1;   // start from 1 and assign color 1 to vertex 1
  
for (int x = 1; x < n; x++)
    {
      
a[x] = 0;
    
} 
int *c[2];
  
*c = new int (n); // color
  
*(c + 1) = new int (n); // flag
  
for (int x = 0; x < n; x++)
    {
      
c[0][x] = x + 1;
      
c[1][x] = 0;
    
} 
int count = 1;
  
int p = 0;
  
//
//
    for (i = 1; i < V; i++)
    {
      
for (j = 0; j < V; j++)
	{
	  
	    // checks for adjacent vertices
	    if ((ar[i][j] == 1) && (a[j] >= 0) && (i != j))
	    {
	      
for (k = 0; k < V; k++)
		{		// mark the vertices with the colors of adjacent vertices as 1
		  if (c[0][k] == a[j])
		    {
		      
c[1][k] = 1;
		      
break;
		    
}
		
}
	    
}
	
}			//
      // checks from the left for the first non zero flagged vertex
      for (l = 0; l < V; l++)
	{
	  
if ((c[1][l] != 1) && (p == 0))
	    {
	      
a[i] = c[0][l]; // then assign the color when first  flag=0 
	      
p = 1;
	      
if (count < c[0][l])
		{
		  
count = c[0][l];
		
}
	    
}
	  
 
	  else			// makes other vertices flagged as 0
	    c[1][l] = 0;
	
}
      
p = 0;
    
 
 
}
  
 
 
    // for(i=0; i<V; i++){
    // printf("%d\t",c[0][i]);
    
    // }
    
    // printf("\n");
    //   printf("\n");
    
    // for(i=0; i<V; i++){
    // printf("%d\t",c[1][i]);
    
    // }
    
    // Adding the subject codes
    for (i = 0; i < V; i++)
    {
      
c[0][i] = Codes[i];
    
}
  
printf ("\n\n\n");
  
printf ("Vertex --> Color");
  
printf ("\n");
  
for (i = 0; i < V; i++)
    {
      
printf ("%d --> %d\n", c[0][i], a[i]);
    
 
}
  
 
    // int slotwise[5][10]={{0,0,0,0,0,0,0,0,0,0}, 
    //                                      {0,0,0,0,0,0,0,0,0,0},
    //                                      {0,0,0,0,0,0,0,0,0,0},
    //                                      {0,0,0,0,0,0,0,0,0,0},
    //                                      {0,0,0,0,0,0,0,0,0,0}};
    
    // int slw[5] = {0,0,0,0,0}; // Number of subjects in each slot e.g slot[0] tells number of subjects in slot number 1;
    for (int q = 0; q < 10; q++)
    {
      
if (a[q] == 1)
	{
	  
 
slotwise[0][slw[0]] = c[0][q];
	  
slw[0]++;
	
}
      
      else if (a[q] == 2)
	{
	  
 
slotwise[1][slw[1]] = c[0][q];
	  
slw[1]++;
	
}
      
      else if (a[q] == 3)
	{
	  
 
slotwise[2][slw[2]] = c[0][q];
	  
slw[2]++;
	
}
      
      else if (a[q] == 4)
	{
	  
 
slotwise[3][slw[3]] = c[0][q];
	  
slw[3]++;
	
}
      
      else if (a[q] == 5)
	{
	  
 
slotwise[4][slw[4]] = c[0][q];
	  
slw[4]++;
	
}
    
 
}
  
 
printf ("\n");
  
printf ("-----------Time Table---------------");
  
printf ("\n");
  
 
printf ("           M       T       W       Th       F");
  
printf ("\n");
  
for (int k = 0; k < count; k++)
    {
      
 
int s = 0;
      
s = k;
      
 
int D = 5;
      
for (int z = islw[k]; z < slw[k]; z++)
	
	{
	  
if (D - Credits[k] == 0)
	    
	    {
	      
printf ("slot : %d ", s + 1);
	      
printf ("  %d R%d  %d R%d  %d R%d  %d R%d  %d R%d\n",
		       
slotwise[k][z], room[k][z], slotwise[k][z],
		       room[k][z], 
slotwise[k][z], room[k][z],
		       slotwise[k][z], room[k][z], 
slotwise[k][z],
		       room[k][z]);
	    
}
	  
 
if (D - Credits[k] == 1)
	    
	    {
	      
printf ("slot : %d ", s + 1);
	      
printf ("  -     %d R%d  %d R%d  %d R%d  %d R%d\n",
		       
slotwise[k][z], room[k][z], slotwise[k][z],
		       room[k][z], 
slotwise[k][z], room[k][z],
		       slotwise[k][z], room[k][z]);
	    
}
	  
if (D - Credits[k] == 2)
	    
	    {
	      
printf ("slot : %d ", s + 1);
	      
printf ("  %d R%d  -     %d R%d  -    %d R%d\n",
		       slotwise[k][z], 
room[k][z], slotwise[k][z],
		       room[k][z], slotwise[k][z], 
room[k][z]);
	    
}
	  
if (D - Credits[k] == 3)
	    
	    {
	      
printf ("slot : %d ", s + 1);
	      
printf ("  -     %d R%d  -     %d R%d  -  \n", slotwise[k][z],
		       
room[k][z], slotwise[k][z], room[k][z]);
	    
 
}
	}
    
 
}
  
 
for (int al = 0; al < 6; al++)
    
    {
      
islw[al] = slw[al];
    
} 
 
printf ("Numbers of color used: %d\n\n", count);

 
 
} 
 
 
 
 
int

main ()
{
  
 
int years;
  
cout << "Enter Number of years you want timetable - ";
  
cin >> years;
  
 
int n;
  
 
for (int y = 1; y <= years; y++)
    {
      
cout << "\nFor Year " << y << "\n\n";
      
 
 
cout << "Enter the number of subjects - ";
      
cin >> n;
      
vector < string > Names;
      
string word;
      
int *Codes = new int (n);
      
int *Credits = new int (n);
      
int **a = new int *[n];
      
 
int eachYear;
      
 
 
for (int i = 0; i < n; ++i)
	
a[i] = new int[n];
      
 
for (int i = 0; i < n; i++)
	{
	  
cout << "Enter the name of the subject number " << i + 1 << " - ";
	  
cin >> word;
	  
Names.push_back (word);
	  
cout << "Enter the subject code of " << word << " - ";
	  
cin >> Codes[i];
	  
cout << "Enter the number of credits of " << word << " - ";
	  
cin >> Credits[i];
	  
cout << "\n";
	
 
} 
 
cout <<
	"\n\nWill each student study each subject. Enter 1 for no and 0 for yes.\n";
      
cin >> eachYear;
      
if (eachYear == 0)
	{
	  
for (int i = 0; i < n; i++)
	    {
	      
for (int j = 0; j < n; j++)
		{
		  
a[i][j] = 1;
	
} 
} 
}
      else
	{
	  
 
for (int i = 0; i < n; i++)
	    {
	      
                        cout << "Can " << Names[i] << " be scheduled with ";
                                
                        for (int k = 0; k < n; k++)
                                {
                                
                        if (k == n - 1)
                                    {
                                    
                        cout << Names[k] << " ";
                                    
                        }
                                else
                                    
                        cout << Names[k] << ", ";
                                
                        }
                                
                        cout << ". Enter 1 for no and 0 for yes separated by space.\n";
	      
for (int j = 0; j < n; j++)
		{
		  
cin >> a[i][j];
	
} 
}} 
 
 
 
 
printf ("\n\n\n\n-------------Year %d-------------", y);
      
NGC (a, n, Codes, Credits);
      
cout << "Subject Code                Subject Name\n\n";
      
for (int r = 0; r < n; r++)
	{
	  
cout << Codes[r] << "                         " << Names[r] <<
	    endl;
    
} 
} 
 
 
return 0;

 
}


