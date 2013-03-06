//Kristian Lundkvist <kristian.lundkvist@gmail.com> 900831-0592
using System;

namespace Uppgift1
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			/**
				 * Variables for price, the amount paid and the change.
				 */
			int price = 0;
			int paid = 0;
			int change = 0;

			//Ask for and read the price.
			Console.Write ("Price: ");
			price = Int32.Parse (Console.ReadLine ());

			//Ask for and read the amount paid.
			Console.Write ("Paid: ");
			paid = Int32.Parse (Console.ReadLine ());

			//Calculate the change.
			change = paid - price;

			//Check if the customer paid enough
			if (change >= 0) {

				//Calculate the number of fivehundred bills and update the amount of change.
				int fivehundred = change / 500;
				change = change - (fivehundred * 500);

				//Calculate the number of hundred bills and update the amount of change.
				int hundred = change / 100;
				change = change - (hundred * 100);

				//Calculate the number of fifty bills and update the amount of change.
				int fifty = change / 50;
				change = change - (fifty * 50);

				//Calculate the number of twenty bills and update the amount of change.
				int twenty = change / 20;
				change = change - (twenty * 20);

				//Calculate the amount of tens and update the amount of change.
				int ten = change / 10;
				change = change - (ten * 10);

				//Calculate the amount of fives and update the amount of chanage.
				int five = change / 5;
				change = change - (five * 5);

				//The amount of ones
				int one = change;

				Console.WriteLine ("\nChange");

				//Check if value isn't zero and print.
				if (fivehundred != 0) {
					Console.WriteLine (fivehundred + " fivehundred bills");
				}
				if (hundred != 0) {
					Console.WriteLine (hundred + " hundred bills");
				}
				if (fifty != 0) {
					Console.WriteLine (fifty + " fifty bills");
				}
				if (twenty != 0) {
					Console.WriteLine (twenty + " twenty bills");
				}
				if (ten != 0) {
					Console.WriteLine (ten + " ten crowns");
				}
				if (five != 0) {
					Console.WriteLine (five + " five crowns");
				}
				if (one != 0) {
					Console.WriteLine (one + " one crowns");
				}

			} else {
				Console.WriteLine ("Sorry, you didn't pay enough, come back later.");
			}

			//Keep the console open after running.
			Console.ReadLine ();
		}
	}
}
