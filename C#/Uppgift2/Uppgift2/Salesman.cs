using System;

namespace Uppgift2
{
	public class Salesman
	{
		private string name;
		private int id;
		private char district;
		private int amountSold;

		public string Name 
		{
			get {
				return this.name;
			}
			set {
				this.name = value;
			}
		}

		public int ID 
		{
			get {
				return this.id;
			}
			set {
				this.id = value;
			}
		}

		public char District 
		{
			get {
				return this.district;
			}
			set {
				this.district = value;
			}
		}

		public int AmountSold 
		{
			get { 
				return this.amountSold;
			}
			set {
				this.amountSold = value;
			}
		}

		public Salesman ()
		{
			this.name = "";
			this.id = -1;
			this.district = 'x';
			this.amountSold = -1;
		}

		public Salesman (string name, int id, char district, int amountSold)
		{
			this.name = name;
			this.id = id;
			this.district = district;
			this.amountSold = amountSold;
		}
	}
}

