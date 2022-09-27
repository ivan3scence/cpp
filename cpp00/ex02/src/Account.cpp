#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;

Account::Account(void) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts++;
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
				<< ";created\n";
}

Account::Account(int initial_deposit) : _amount(initial_deposit),
										_nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
				<< ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
				<< ";closed\n";
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	char str[100];
	std::time_t result = std::time(nullptr);
	std::strftime(str, sizeof(str), "[%Y%m%d_%H%M%S]", std::localtime(&result));
	std::cout << str;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:"
		<< _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	++_nbDeposits;
	++_totalNbDeposits;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit
				<< ";deposit:" << deposit << ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int ref;

	ref = 0;
	if (withdrawal < _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		++_nbWithdrawals;
		++_totalNbWithdrawals;
	}
	else
	{
		ref = 1;
		withdrawal = 0;
	}
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:"
				<< _amount + withdrawal << ";withdrawal:";
	if (ref)
	{
		std::cout << "refused\n";
		return (false);
	}
	std::cout << withdrawal << ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
				<< ";deposits:" << _nbDeposits << ";withdrawals:"
				<< _nbWithdrawals << std::endl;
}