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

			Console.Write("Price: ");
			price = Int32.Parse(Console.ReadLine());

			Console.Write("Paid: ");
			paid = Int32.Parse(Console.ReadLine());

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

			Console.WriteLine("\nChange");
			Console.WriteLine(hundred + " hundred bills");
			Console.WriteLine(fifty + " fifty bills");
			Console.WriteLine(twenty + " twenty bills");
			Console.WriteLine(ten + " ten crowns");
			Console.WriteLine(five + " five crowns");
			Console.WriteLine(one + " one crowns");

			Console.ReadLine();
		}
	}
}
