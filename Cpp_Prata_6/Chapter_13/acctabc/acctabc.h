// acctabc.h  -- bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

// Abstract Base Class
class AcctABC
{
private:
	std::string fullName; // Имя клиента
	long acctNum;         // Номер аккаунта
	double balance;       // Актуальный баланс
protected:
	struct Formatting     // Форматирование вывода
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName() const {return fullName;} // Получение имени клиента
	long AcctNum() const {return acctNum;}                  // Получение номера аккаунта
	Formatting SetFormat() const;         // Установить формат
	void Restore(Formatting & f) const;   // Восстановить формат по умолчанию
public: 
	AcctABC(const std::string & s = "Nullbody", long an = -1,
	        double bal = 0.0);
	void Deposit(double amt) ;               // Положить деньги
	virtual void Withdraw(double amt) = 0;   // pure virtual function
	double Balance() const {return balance;} // Актуальный баланс
	virtual void ViewAcct() const = 0;       // pure virtual function
	virtual ~AcctABC() {}
};

// Brass Account Class
class Brass :public AcctABC
{
public:
	Brass(const std::string & s = "Nullbody", long an = -1,
	      double bal = 0.0) : AcctABC(s, an, bal) { }
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1,
	          double bal = 0.0, double ml = 500,
	          double r = 0.10);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct()const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif
