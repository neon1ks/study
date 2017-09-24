// brass.h  -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
// Brass Account Class
class Brass
{
private:
	std::string fullName; // Имя клиента
	long acctNum;         // Номер счета
	double balance;       // текущий баланс
public:
	Brass(const std::string & s = "Nullbody", long an = -1,
	      double bal = 0.0);           // Конструктор создает счет
	void Deposit(double amt);          // Положить деньги на счет
	virtual void Withdraw(double amt); // Снять деньги со счета
	double Balance() const;            // Информация об балансе
	virtual void ViewAcct() const;     // Вывод состояния счета
	virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus : public Brass
{
private:
	double maxLoan;  // Доступный овердрафт
	double rate;     // Проценты
	double owesBank; // Долг банку
public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1,
	          double bal = 0.0, double ml = 500,
	          double r = 0.11125);
	BrassPlus(const Brass & ba, double ml = 500,
	          double r = 0.11125);

	virtual void ViewAcct()const;            // Вывод состояния счета
	virtual void Withdraw(double amt);       // Снять деньги со счета

	void ResetMax(double m) { maxLoan = m; } // Изменение доступного овердрафта
	void ResetRate(double r) { rate = r; }   // Изменение процентной ставки
	void ResetOwes() { owesBank = 0; }       // Забавно списывается долг
};

// В основном классе нам еще надо реализовать один конструктор и 4 метода

// В произвольном классе - 2 конструктора и 2 метода

#endif
