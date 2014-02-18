
import java.util.Scanner;

public class Coins1
{

    static int M(int j, int[] v)
    {
       int[] sol, mySol;
       int   myFinalSol;
       int k;

       sol = new int[v.length];
       mySol = new int[v.length];

       /* ---------------------------
	  Base cases
	  --------------------------- */
       if ( j == 0 )
       {
	   return(0);
       }


       /* --------------------------------------------------------
          Try every denomination k = 1,2,..,C for the last coin
          -------------------------------------------------------- */
       for ( k = 0; k < v.length; k++ )
          mySol[k] = -1;                   // Initialize mySol[]

       for ( k = 0; k < v.length; k++ )
       {
          /* --------------------------------------------
	     Check if we can use the k-th denomination
	     -------------------------------------------- */
          if ( v[k] <= j )
          {
             /* ------------------------
	        Divide step
	        ------------------------ */
             sol[k] = M(j - v[k], v);  // Use coin v[k] as last coin

             mySol[k] = sol[k] + 1;    // Solution to make change for $j
          }
       }

       /* --------------------------------------------------------
          Find the minimum
          -------------------------------------------------------- */
       myFinalSol = -1;

       for ( k = 0; k < v.length; k++ )
       {
          if ( mySol[k] >= 0 )
          {
	     if ( myFinalSol == -1 || mySol[k] < myFinalSol )
	        myFinalSol = mySol[k];
          }
       }

       return(myFinalSol);   // Return best solution
   }


   public static void main(String[] args)
   {
       int[] v = {1, 3, 9, 19, 26};

       int C, r;

       Scanner in = new Scanner( System.in );

       System.out.print("Values of coins: ");
       for ( int i = 0; i < v.length; i++ )
       {
           System.out.print(v[i] + ", ");
       }
       System.out.println("\n");
       
       while ( true )
       {
	  System.out.print(" Change amount = ");
          C = in.nextInt();

          r = M(C, v);

          System.out.println("Min # coins to make change for " + C + " = " + r);
          System.out.println("=======================\n");
       }
   }

}
