#include <iostream>
using namespace std;

class Character
{
protected:
	string Name;
	int Health;
	int Exp;
	int Level;

public:

	Character(string _Name, int _Health, int _Exp, int _Level)
	{
		Name = _Name;
		Health = _Health;
		Exp = _Exp;
		Level = _Level;
	}

	void GetInfo()
	{
		cout << "Name :" << Name << endl;
		cout << "HP :" << Health << endl;
		cout << "Level :" << Level << endl << endl;
	}

	int HealthHP()
	{
		return Health;
	}

	int TakeDamage(int _Attack)
	{
		if (Health - _Attack > 0)
		{
			cout << this->Name << " was attacked and HP - " << _Attack<<endl<< endl;
			Health -= _Attack;
			return Health;
		}
		else
		{
			cout << this->Name << " was death" << endl<<endl;
			return Health = 0;
		}
	}
};

class Enemy : public Character
{
public :
	Enemy(string _Name, int _Health, int _Exp, int _Level) :Character(_Name, _Health, _Exp, _Level)
	{

	}
};

class Player : public Character
{
public:
	Player(string _Name, int _Health, int _Exp, int _Level) :Character(_Name, _Health, _Exp, _Level)
	{

	}

	void Restore(int _Health, int _Exp, int _Level)
	{
		if (Health <= 0)
		{
			Health = _Health, Exp = _Exp, Level = _Level;
		}
	}

	int Heal(int HP)
	{
		if (Health > 0)
		{
			if(HP <= 20)
			cout << "Player heals "<< HP << " HP" << endl;
			else if(HP > 20)
			cout << "Player use Mega heal " << HP << " HP" << endl;
			return Health += HP;
		}
	}

	int GainExperience(int exp)
	{
		cout << "Gain " <<exp<< " Exp" << endl;
		return Exp += exp;
	}

	int LevelUp()
	{
		if (Health > 0)
		{
			Level += (Exp / 10);
			cout << "Level up to " << Level << endl;
			Exp -= 10;
			return Level;
		}
	}
};
