// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class CWolf;
class CGhost;
class Cdragon;
class CCreature
{
protected:
	int nPower; //��������
	int nLifeValue; //��������ֵ
public:
	void display()
	{
		cout << "nPower=" << nPower << "  nLifeValue=" << nLifeValue << endl;
	}
	void setvalue(int p, int l)
	{
		nPower = p;
		nLifeValue = l;
	}

};
class CDragon :public CCreature
{
public:
	void Attack(CWolf * pWolf);
	void Attack(CGhost * pGhost);
	void Hurted(int nPower);
	void FightBack(CWolf * pWolf);
	void FightBack(CGhost * pGhost);
};
class CWolf :public CCreature
{
public:
	void Attack(CDragon * pDragon);
	void Attack(CGhost * pGhost);
	void Hurted(int nPower);
	void FightBack(CDragon * pDragon);
	void FightBack(CGhost * pGhost);
};
class CGhost :public CCreature
{
public:
	void Attack(CDragon * pDragon);
	void Attack(CWolf * pWolf);
	void Hurted(int nPower);
	void FightBack(CDragon * pDragon);
	void FightBack(CWolf * pWolf);
};
void CDragon::Attack(CWolf * pWolf)
{
	//���������ֹ��������Ĵ���
	pWolf->Hurted(nPower);
	pWolf->FightBack(this);
}
void CDragon::Attack(CGhost * pGhost)
{
	//���������ֹ��������Ĵ���
	pGhost->Hurted(nPower);
	pGhost->FightBack(this);
}
void CDragon::Hurted(int nPower)
{
	//���������������˶����Ĵ���
	nLifeValue -= nPower;
}
void CDragon::FightBack(CWolf * pWolf)
{
	//�����������ַ��������Ĵ���
	pWolf->Hurted(nPower / 2);
}
void CDragon::FightBack(CGhost * pGhost)
{
	//�����������ַ��������Ĵ���
	pGhost->Hurted(nPower / 2);
}
void CWolf::Attack(CDragon * pDragon)
{
	//���������ֹ��������Ĵ���
	pDragon->Hurted(nPower);
	pDragon->FightBack(this);
}
void CWolf::Attack(CGhost * pGhost)
{
	//���������ֹ��������Ĵ���
	pGhost->Hurted(nPower);
	pGhost->FightBack(this);
}
void CWolf::Hurted(int nPower)
{
	//���������������˶����Ĵ���
	nLifeValue -= nPower;
}
void CWolf::FightBack(CDragon * pDragon)
{
	//�����������ַ��������Ĵ���
	pDragon->Hurted(nPower / 2);
}
void CWolf::FightBack(CGhost * pGhost)
{
	//�����������ַ��������Ĵ���
	pGhost->Hurted(nPower / 2);
}
void CGhost::Attack(CDragon * pDragon)
{
	//���������ֹ��������Ĵ���
	pDragon->Hurted(nPower);
	pDragon->FightBack(this);
}
void CGhost::Attack(CWolf * pWolf)
{
	//���������ֹ��������Ĵ���
	pWolf->Hurted(nPower);
	pWolf->FightBack(this);
}
void CGhost::Hurted(int nPower)
{
	//���������������˶����Ĵ���
	nLifeValue -= nPower;
}
void CGhost::FightBack(CDragon * pDragon)
{
	//�����������ַ��������Ĵ���
	pDragon->Hurted(nPower / 2);
}
void CGhost::FightBack(CWolf * pWolf)
{
	//�����������ַ��������Ĵ���
	pWolf->Hurted(nPower / 2);
}

int main()
{
	CDragon oDragon;
	oDragon.setvalue(20, 100);
	CWolf oWolf;
	oWolf.setvalue(4, 100);
	CGhost oGhost;
	oGhost.setvalue(10, 100);
	oDragon.display();
	oWolf.display();
	oGhost.display();
	oDragon.Attack(&oWolf);
	oDragon.Attack(&oWolf);
	oGhost.Attack(&oDragon);
	oDragon.display();
	oWolf.display();
	oGhost.display();
	return 0;
}

