// -------------------------------------driver file-------------------------------------------

//Helen Hu, CSS501-A

//Creation Date: 10/27/2020

//Date of Last Modification: 10/31/2020

//--------------------------------------------------------------------------------------------

//Purpose - Implements the Longest Common Subsequence(LCS) problem by using iteration and recursion, analyze and compare the two implementations.LCS algorithm is applied to many real-world problems including DNA/protein sequence alignment in bioinformatics, and computational linguistics. 

//--------------------------------------------------------------------------------------------

//Descriptions:
//getLine: Read the string outside of the program
//LCS len: Get the length of the LCS
//LCS: Get the LCS
//backtrack: Use backtrack to print out the LCS
//preconditions: two original strings that we don't know about their size and how long the consecutive common subsequence is. Which algorithm(dynamic programming/interative or recursive) runs faster?
//preconditions: We are clear about the size of the two strings and the resulting longest common subsequence, and which algorithm is more efficient regarding their time complexity.
//Assumptions: The program might have some flaws like when the string is too long, the recursive method will run slow and forever. The format of output might be improved in a better way.

//------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//Iterative method implementation with 2D metric
int lcs_it(int **C, string X, string Y, int m, int n ){    
  //Create the board
  for (int i=0; i<m+1;++i){
    C[i]=new int [n+1];  
  } 
  //Go through two strings, and count the LCS length
  for (int i=0; i<=m; i++) 
  { 
    for (int j=0; j<=n; j++) 
    { 
      //If the string is empty, LCS length is 0
      if (i == 0 || j == 0) 
        C[i][j] = 0; 

      /*If the character correspoding to the current row and current    column are matching,then fill the current cell by adding one to the diagonal element. Point an arrow to the diagonal cell*/
      else if (X[i-1] == Y[j-1]) 
        C[i][j] = C[i-1][j-1] + 1; 

      /*Else take the maximum value from the previous column and previous row element for filling the current cell. Point an arrow to the cell with maximum value. If they are equal, point to any of them.*/
      else
        C[i][j] = max(C[i-1][j], C[i][j-1]); 
    } 
  } 
  
  // Following code is used to print LCS 
  int index = C[m][n]; 
  
  //Create a character array to store the lcs string 
   char lcs[index+1]; 
   lcs[index] = '\0'; // Set the terminating character 
  
   /*Start from the right-most-bottom-most corner and 
    one by one store characters in lcs[] */
   int i = m, j = n; 
   while (i > 0 && j > 0) 
  { 
    /*If current character in X[] and Y are same, then 
      current character is part of LCS*/
    if (X[i-1] == Y[j-1]) 
    { 
      lcs[index-1] = X[i-1]; //Put current character in result 
      i--; j--; index--;     //reduce values of i, j and index 
    } 
  
    /*If not same, then find the larger of two and 
      go in the direction of larger value*/
    else if (C[i-1][j] > C[i][j-1]) 
      i--; 
    else
      j--; 
   } 
    string s(lcs);
    return s.length();   
}

/*backtrack implementation with 2D matric, return the resulting string in recursive call*/
string backtrack(int **C, string X, string Y, int m, int n){
  //Create the board
  for (int i=0; i<m+1;++i){
    C[i]=new int [n+1];  
  } 
  //Go through two strings, and count the LCS length
  for (int i=0; i<=m; i++) 
  { 
    for (int j=0; j<=n; j++) 
    { 
      //If the string is empty, LCS length is 0
      if (i == 0 || j == 0) 
        C[i][j] = 0; 

      /*If the character correspoding to the current row and current    column are matching,then fill the current cell by adding one to the diagonal element. Point an arrow to the diagonal cell*/
      else if (X[i-1] == Y[j-1]) 
        C[i][j] = C[i-1][j-1] + 1; 

       /*Else take the maximum value from the previous column and previous row element for filling the current cell. Point an arrow to the cell with maximum value. If they are equal, point to any of them.*/
      else
        C[i][j] = max(C[i-1][j], C[i][j-1]); 
    } 
  } 
  
   // Following code is used to print LCS 
   int index = C[m][n]; 
  
   // Create a character array to store the lcs string 
   char lcs[index+1]; 
   lcs[index] = '\0'; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
  { 
    // If current character in X[] and Y are same, then 
    // current character is part of LCS 
    if (X[i-1] == Y[j-1]) 
    { 
      lcs[index-1] = X[i-1]; // Put current character in result 
      i--; j--; index--;     // reduce values of i, j and index 
    } 
  
    // If not same, then find the larger of two and 
    // go in the direction of larger value 
    else if (C[i-1][j] > C[i][j-1]) 
      i--; 
      else
      j--; 
    } 

    string s(lcs);
    return s;   
  }

  /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
  int lcs_it_test(string X, string Y, int m, int n) {
  int **C=new int*[m+1];
  return lcs_it(C, X, Y, m, n);
}  

int lcs_re( string X, string Y, int m, int n){
   //If one or two strings are empty, then LCS = 0
  if((m == 0) || (n == 0)){
    return 0;  
  }
  // If the element of array X and array Y are equal, then add 1
  else if (X[m] == Y[n]){
    return 1 + lcs_re( X, Y, m-1, n-1);
  }
  //Else, return the maximum
   else{
      return max(lcs_re( X, Y, m-1, n), lcs_re( X, Y, m, n-1));
  } 
}

int main() {

  //Initialize two strings
   string X;
   string Y;
  
  // Read from the text file
   ifstream readFile("input.txt");
   
   //Read the file when it is open
   if(readFile.is_open()){
     getline(readFile, X);
     cout<< X;
     cout<<endl;

    //Get line
     getline(readFile, Y);
     cout<< Y;
     cout<<endl;

    //Close the file
     readFile.close();
  }
  
   //Create a table for the iterative method
   int **C=new int*[X.length()+1];
   cout<<endl;

  /*Print out the size of two strings, iterative LCS length and resulting LCS for recursive*/
   string backtrackString = backtrack(C, X, Y, X.length(), Y.length());
   cout<<"LCS is "<<backtrackString<<endl;
   cout<<"LCS length in iterative function is "<<lcs_it_test(X, Y, X.length(), Y.length())<<endl;

  //Prompt the user input for trial time for iterative call
   int m;
   cout<< "Enter trial time for iterative version (less than min(|X|, |Y|)): ";
   cin>>m;

  //Prompt the user input for trial time for recursive call
   int n;
   cout<< "Enter trial time for recursive version (less than 20): ";
   cin>>n;
  //Initialize start-time, end-time for both methods
   int start_it, stop_it, start_re, stop_re;

  //Run and calculate the runtime for iterative method
   for (int i=0; i<m; i++){
     start_it=clock();
     lcs_it_test(X, Y, i, i);
     stop_it=clock();
    
     clog << i << " iterative method runtime's" << "\t" << (stop_it-start_it)/double(CLOCKS_PER_SEC)*1000 << endl;
   }

  //Run and calculate the LCS length and the runtime for recursive method
   for (int i=0; i<n; i++){
     start_re=clock();
     lcs_re( X,  Y, i, i);
     stop_re=clock();
     clog << i << " recursive method runtime's" << "\t" << (stop_re-start_re)/double(CLOCKS_PER_SEC)*1000 << endl;
  }
}


