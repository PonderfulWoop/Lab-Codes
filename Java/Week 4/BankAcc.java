import java.util.Scanner;

class BankAcc1{
	String name, acc_num, acc_type;
	double balance;
	static double rate;

	BankAcc1(){
		name = acc_num = acc_type = "Nil";
		balance = 0.0;
		rate = 7.5;
	}

	BankAcc1(String name, String acc_num, String acc_type, double balance){
		this.rate = rate;
		this.name = name;
		this.acc_type = acc_type;
		this.acc_num = acc_num;
		this.balance = balance;
		rate = 7.5;
	}

	void deposit(double amount){
		this.balance += amount;
		System.out.println("Available balance: " + this.balance);
	}

	void withdraw(double amount){
		if(amount > this.balance){
			System.out.println("Insufficient balance");
		}
		else if(this.balance-amount<1000){
			System.out.println("Need to maintain a minimum balance of Rs. 1000");
		}
		else{
			this.balance-=amount;
			System.out.println("Successful.\nAvailable balance: " + this.balance);
		}
	}

	void displayDetails(){
		System.out.println("Account Details: ");
		System.out.println("-----------------------------");
		System.out.println("Account Holder: " + this.name);
		System.out.println("Account Type: " + this.acc_type);
		System.out.println("Account Number: " + this.acc_num);
		System.out.println("Available Balance: " + this.balance);
		System.out.println("-----------------------------");
	}

	static void dispRate(){
		System.out.println("Rate of Interest: " + rate);
	}
}

class BankAcc{
	public static void main(String args[]){
		String name, accNum, accType;
		double balance, amount;

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Name, Account Number, Account Type, Initial Balance");
		name = sc.next();
		accNum = sc.next();
		accType = sc.next();
		balance = sc.nextDouble();

		BankAcc1 obj = new BankAcc1(name, accNum, accType, balance);

		int ch = 0;
		while(ch != 5){
			System.out.println("Enter Choice: ");
			System.out.println("1. Deposit");
			System.out.println("2. Withdraw");
			System.out.println("3. Display Details");
			System.out.println("4. Display Rate of Interest");
			System.out.println("5. Exit");
			ch = sc.nextInt();

			switch(ch){
				
				case 1:
				System.out.println("Enter Amount: ");
				amount = sc.nextDouble();
				obj.deposit(amount);
				break;

				case 2:
				System.out.println("Enter Amount: ");
				amount = sc.nextDouble();
				obj.withdraw(amount);
				break;

				case 3:		
				obj.displayDetails();
				break;

				case 4:
				BankAcc1.dispRate();
				break;
			}
		}
	}
}