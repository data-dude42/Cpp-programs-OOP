

#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include "iostream"
#include "iomanip"
#include "string.h"

using namespace std;
using namespace seneca;

Hero::Hero()
{

	setEmpty();
}

Hero::Hero(const char *name, Power *pow, int n_pow)
{

	setEmpty();

	if (name[0] != '\0' && pow != nullptr && n_pow > 0)
	{

		strncpy(m_hero_name, name, MAX_NAME_LEN);

		int i;

		m_powers = new Power[n_pow];
		for (i = 0; i < n_pow; i++)
		{
			m_powers[i] = pow[i];
		}

		m_num_powers = n_pow;

		updatelvl(); 
	}
}

void Hero::setEmpty()
{

	m_hero_name[0] = '\0';
	m_powers = nullptr;
	m_num_powers = 0;
	m_power_lvl = 0;
}

std::ostream &Hero::display(std::ostream &os) const
{

	int indentSize = 2;
	int i;

	os << "Name: " << left << m_hero_name << endl
	   << "List of available powers: " << endl;

	for (i = 0; i < m_num_powers; i++)
	{
		os << std::setw(indentSize) << ""
		   << "Name: " << m_powers[i].checkName() << ", "
		   << "Rarity: " << m_powers[i].checkRarity() << endl;
	}
	os << "Power Level: " << m_power_lvl;

	return os;
}

bool Hero::isEmpty() const
{

	return (m_hero_name[0] == '0' || m_powers == nullptr || m_num_powers == 0 || m_power_lvl == 0);
}

void Hero::updatelvl()
{

	int i, t_rarity = 0;

	for (i = 0; i < m_num_powers; i++)
	{
		t_rarity += this->m_powers[i].checkRarity();
	}

	m_power_lvl = t_rarity * m_num_powers;
}

int Hero::checkPowerLvl() const
{

	return m_power_lvl;
}

bool Hero::operator+=(Power &pow)
{

	if (!pow.isEmpty())
	{

		int i;

		Power *tempArr = new Power[m_num_powers];

		for (i = 0; i < m_num_powers; i++)
		{
			tempArr[i] = m_powers[i];
		}

		m_num_powers++;

		delete[] m_powers;
		m_powers = new Power[m_num_powers];

		for (i = 0; i < m_num_powers - 1; i++)
		{
			m_powers[i] = tempArr[i];
		}

		m_powers[m_num_powers - 1] = pow;

		delete[] tempArr;
		tempArr = nullptr;

		updatelvl();

		return true;
	}
	else
	{
		return false;
	}
}

bool Hero::operator-=(int pow_lvl)
{

	if (pow_lvl > 0)
	{
		m_power_lvl -= pow_lvl;
		return true;
	}
	else
	{
		return false;
	}
}

bool seneca::operator<(Hero &lhs, Hero &rhs)
{
	return (lhs.checkPowerLvl() < rhs.checkPowerLvl());
}

bool seneca::operator>(Hero &lhs, Hero &rhs)
{
	return (lhs.checkPowerLvl() > rhs.checkPowerLvl());
}

bool seneca::operator>>(Power &pow, Hero &hero)
{
	if (!pow.isEmpty() && !hero.isEmpty())
	{
		hero += pow;
		return true;
	}
	else
	{
		return false;
	}
}

bool seneca::operator<<(Hero &hero, Power &pow)
{
	return pow >> hero;
}

Hero::~Hero()
{
	delete[] m_powers;
	m_powers = nullptr;
}
