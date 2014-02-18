
import java.util.Scanner;


public class Coins1_dp
{
    /* =============================================================
       make_M(v, M): make the M[] array

	   v[] = values of each type of coin
	   M[j] = min # coins used to make change for $j

       Return: the value M[Am] (which is the min # coins used 
		to make change for $Am
       ============================================================= */
    static int findM(int Am, int v[])
    {
       int[] M;
       int[] sol, mySol;
       int j, k, min;

       M = new int[Am+1];
       sol = new int[v.length];
       mySol = new int[v.length];

       /* ---------------------------
	  Base cases
	  --------------------------- */
       M[0] = 0;	// 0 coins needed to make change for $0

       /* ---------------------------------------------------
	  The other cases (starting from 1 to M.length - 1)
	  --------------------------------------------------- */
       for ( j = 1; j <= Am; j++ )
       {

          if ( Am < 20 )
             System.out.println("\nComputing M[" + j + "]");


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
                sol[k] = M[j - v[k]];     // Use coin v[k] as last coin
                mySol[k] = sol[k] + 1;    // Solution to make change for $j
             }
          }

          /* --------------------------------------------------------
             Find the minimum
             -------------------------------------------------------- */
          M[j] = -1;

          for ( k = 0; k < v.length; k++ )
          {
             if ( mySol[k] >= 0 )
             {
                if ( M[j] == -1 || mySol[k] < M[j] )
                   M[j] = mySol[k];
             }
          }

          if ( M.length < 20 )
             System.out.println("=====> M[" + j + "] = " + M[j]);
       }

       return( M[Am] );
   }


   public static void main(String[] args)
   {
//       int[] v = {1, 5, 10, 25, 50, 100, 500};
       int[] v = {1, 3, 9, 19, 26 };

       int Am, r;

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
          Am = in.nextInt();

          r = findM(Am, v);

/*
          for (int i = 0; i <= Am; i ++)
             System.out.println("M[" + i + "] = " + M[i]);
*/

          System.out.println("Min # coins to make change for " + Am + "= " + r);          System.out.println("=======================\n");
       }
   }
}
