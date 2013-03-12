using System;

namespace Uppgift2
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int numberOfSalesmen = 8;

			Salesman[] sellers = new Salesman[numberOfSalesmen];

			for (int i = 0; i < numberOfSalesmen; i++)
			{
				sellers[i] = readInfoFromUser;
			}

			sellers = sort(sellers);


		}

		public Salesman readInfoFromUser ()
		{
			Console.Write("Name: ");
			string name = Console.ReadLine();

			Console.Write("Number: ");
			int id = Int32.Parse(Console.ReadLine());

			Console.Write("District: ");
			char district = Char.Parse(Console.ReadLine());

			Console.Write("Amount articles sold: ");
			int amountSold = Int32.Parse(Console.ReadLine());

			return new Salesman(name, id, district, amountSold);
		}

		public Salesman[] sort (Salesman[] sellers)
		{
			for (int n = 0; n < sellers.Length; n++)
			{
				int lowest = sellers[n].AmountSold;
				int index = n;

				for (int i = n; i < sellers.Length; i++)
				{
					if(sellers[i].AmountSold < lowest)
					{
						lowest = sellers[i].AmountSold;
						index = i;
					}
				}

				Salesman temp = sellers[n];
				sellers[n] = sellers[index];
				sellers[index] = temp;
			}

			return sellers;
		}
	}
}
