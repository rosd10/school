using System;

namespace Uppgift2
{
	//A class representing one salesman.
	public class Salesman
	{
		//The salesman's name.
		private string name;

		//The salesman's ID.
		private int id;

		//The salesman's district.
		private char district;

		//The amount of articles the salesman have sold.
		private int amountSold;

		//Public property for getting and setting name.
		public string Name 
		{
			get {
				return this.name;
			}
			set {
				this.name = value;
			}
		}

		//Public property for getting and setting ID.
		public int ID 
		{
			get {
				return this.id;
			}
			set {
				this.id = value;
			}
		}

		//Public property for getting and setting district.
		public char District 
		{
			get {
				return this.district;
			}
			set {
				this.district = value;
			}
		}

		//Public property for getting and setting the amount sold.
		public int AmountSold 
		{
			get { 
				return this.amountSold;
			}
			set {
				this.amountSold = value;
			}
		}

		//Default constructor.
		public Salesman ()
		{
			this.name = "";
			this.id = -1;
			this.district = 'x';
			this.amountSold = -1;
		}

		//Constructor, takes the name, id, district and amount sold and assigns their value.
		public Salesman (string name, int id, char district, int amountSold)
		{
			this.name = name;
			this.id = id;
			this.district = district;
			this.amountSold = amountSold;
		}
	}
}

