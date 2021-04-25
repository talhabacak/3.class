using System.IO;
using System;

class Program
{
    static void Main()
    {
        int round = 100;
        int [] A = new int [round];
        int [] B = new int [round];
        int tie = 0;
        int winA = 0;
        int winB = 0;
        int i;
        Random rastgele = new Random();
        
        for(i=0; i<round; i++){
            A[i] = 0;   // 0 = Paper
            B[i] = rastgele.Next(0,3);;
            
            if(B[i] == 0){  // 0 = Paper
                tie++;
            }
            else if(B[i] == 1){ // 1 = Scissors 
                winB++;
            }
            if(B[i] == 2){  // 2 = Rock 
                winA++;
            }
        }
        
        Console.WriteLine("Player A wins {0} of 100 games",winA);
        Console.WriteLine("Player B wins {0} of 100 games",winB);
        Console.WriteLine("Tie: {0} of 100 games",tie);
    }
}