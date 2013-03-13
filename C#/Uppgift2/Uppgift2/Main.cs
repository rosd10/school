using System;

namespace Uppgift2
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			//Determines the number of salesmen to handle.
			int numberOfSalesmen = 8;

			//An array of Salesmen.
			Salesman[] sellers = new Salesman[numberOfSalesmen];

			//Read all the salesmen info from the user.
			for (int i = 0; i < numberOfSalesmen; i++)
			{
				//Function call for readInfoFromUser.
				sellers [i] = readInfoFromUser();
			}

			//Sort the sellers.
			sellers = sort (sellers);

			//Prints the sorted sellers and other info to screen.
			printInfo (sellers);

			//Writes the sorted sellers and other info to disk.
			writeToDisk (sellers);
		}


		//Function for reading salesman info from the user, returns a Salesman.
		public Salesman readInfoFromUser ()
		{
			//Reads name.
			Console.Write ("Name: ");
			string name = Console.ReadLine ();

			//Reads ID.
			Console.Write ("Number: ");
			int id = Int32.Parse (Console.ReadLine ());

			//Reads district.
			Console.Write ("District: ");
			char district = Char.Parse (Console.ReadLine ());

			//Reads the number of articles sold.
			Console.Write ("Amount articles sold: ");
			int amountSold = Int32.Parse (Console.ReadLine ());

			//Returns a salesman object.
			return new Salesman (name, id, district, amountSold);
		}

		//Function for sorting the salesmen.
		public Salesman[] sort (Salesman[] sellers)
		{
			//Bubblesort (if I remember correctly).
			for (int n = 0; n < sellers.Length; n++)
			{
				int lowest = sellers [n].AmountSold;
				int index = n;

				for (int i = n; i < sellers.Length; i++)
				{
					if (sellers [i].AmountSold < lowest)
					{
						lowest = sellers [i].AmountSold;
						index = i;
					}
				}

				Salesman temp = sellers [n];
				sellers [n] = sellers [index];
				sellers [index] = temp;
			}

			return sellers;
		}

		//Function for printing the info to screen.
		void printInfo (Salesman[] sellers)
		{
			Console.WriteLine ("NAME\tID\tDISTRICT\tAMOUNT");

			int index = 0;
			int number = 0;

			//Writes all the level one sellers.
			while (sellers[index].AmountSold < 50)
			{
				Console.WriteLine (sellers [index].Name + "\t" + sellers [index].ID + "\t" + sellers [index].District + "\t" + sellers [index].AmountSold);
				index++;
				number++;
			}
			Console.WriteLine (number + " salesmen have reached level 1: under 50 articles");

			number = 0;

			//Writes all the level two sellers.
			while (sellers[index].AmountSold < 100)
			{
				Console.WriteLine (sellers [index].Name + "\t" + sellers [index].ID + "\t" + sellers [index].District + "\t" + sellers [index].AmountSold);
				index++;
				number++;
			}
			Console.WriteLine (number + " salesmen have reached level 2: between 50 and 100 articles");

			number = 0;

			//Writes all the level three sellers.
			while (sellers[index].AmountSold < 200)
			{
				Console.WriteLine (sellers [index].Name + "\t" + sellers [index].ID + "\t" + sellers [index].District + "\t" + sellers [index].AmountSold);
				index++;
				number++;
			}
			Console.WriteLine (number + " salesmen have reached level 3: between 100 and 200 articles");

			number = 0;

			//Writes all the level four sellers.
			while (index < sellers.Length)
			{
				Console.WriteLine (sellers [index].Name + "\t" + sellers [index].ID + "\t" + sellers [index].District + "\t" + sellers [index].AmountSold);
				index++;
				number++;
			}
			Console.WriteLine (number + " salesmen have reached level 4: over 200 articles");

		}

		//Function for writing the salesmen info to disk.
		void writeToDisk (Salesman[] sellers)
		{

		}
	}
}
