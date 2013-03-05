using System;

namespace Uppgift1
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int price = 0;
			int paid = 0;
			int change = 0;

			Console.Write ("Price: ");
			price = Int32.Parse (Console.ReadLine ());

			Console.Write ("Paid: ");
			paid = Int32.Parse (Console.ReadLine ());

			change = paid - price;

			int hundred = change / 100;
			change = change - (hundred * 100);

			int fifty = change / 50;
			change = change - (fifty * 50);

			int twenty = change / 20;
			change = change - (twenty * 20);

			int ten = change / 10;
			change = change - (ten * 10);

			int five = change / 5;
			change = change - (five * 5);

			int one = change;

			Console.WriteLine ("\nChange");

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

			Console.ReadLine();
		}
	}
}
