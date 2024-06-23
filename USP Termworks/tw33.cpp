//termwork 3 emulate unix


#include<bits/stdc++.h>
using namespace std;
int main( int argc , char* argv[] )
 {
   
   if( argc == 4 )   // programName -s <source_file> <destination_file>
    {
      if( symlink( argv[2] ,argv[3] ) == -1 )
        {
	  	perror("link");   		return 1;
	   }
           cout<<"Symbolic | Soft link of File created successfully\n";
    }


if( argc == 3 )  // programName <source_file> <destination_file>
    {
	   if( link(argv[1],argv[2]) == -1 )
	    {
	      perror("link"); 
	      return 1;
	    }
	   cout<<"Hard link of File created successfully\n";
    }
   return 0; 
 }

