// 07-1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class Car
{
public:
	Car();
	~Car();
	Car(int gas);
	int getGasGauge();
private:
	int gasolineGauge;
};

class HybridCar : public Car
{
public:
	HybridCar();
	~HybridCar();
	HybridCar(int elec);
	HybridCar(int elec, int gas);
	int GetElecGauge();
private:
	int electricGauge;
};

class HybridWaterCar : public HybridCar
{
public:
	HybridWaterCar();
	~HybridWaterCar();
	HybridWaterCar(int water);
	HybridWaterCar(int water, int elec);
	HybridWaterCar(int water, int elec, int gas);
	void ShowCurrentGauge();
private:
	int waterGauge;
};

HybridWaterCar::HybridWaterCar() : waterGauge(0)
{
	cout << "Water is empty" << endl;
}

HybridWaterCar::~HybridWaterCar()
{
	cout << "Water Tank detached" << endl;
}

HybridWaterCar::HybridWaterCar(int water) : waterGauge(water)
{
	cout << "WaterTank is filled! " << waterGauge << endl;
}

HybridWaterCar::HybridWaterCar(int water, int elec) : waterGauge(water), HybridCar(elec)
{
	cout << "WaterTank is filled! " << waterGauge << endl;
}

HybridWaterCar::HybridWaterCar(int water, int elec, int gas) : waterGauge(water), HybridCar(elec, gas)
{
	cout << "WaterTank is filled! " << waterGauge << endl;
}

void HybridWaterCar::ShowCurrentGauge()
{
	cout << "Left Gasoline" << getGasGauge() << endl;
	cout << "Left Electricity" << GetElecGauge() << endl;
	cout << "Left Water" << waterGauge << endl;
}

HybridCar::HybridCar() : electricGauge(0)
{
	cout << "Electricity is None" << endl;
}

HybridCar::~HybridCar()
{
	cout << "Battery detached" << endl;
}

HybridCar::HybridCar(int elec) : electricGauge(elec)
{
	cout << "Electricity is Charged! " << electricGauge << endl;
}

HybridCar::HybridCar(int elec, int gas) : electricGauge(elec), Car(gas)
{
	cout << "Electricity is Charged! " << electricGauge << endl;
}

int HybridCar::GetElecGauge()
{
	return electricGauge;
}
Car::Car():gasolineGauge(0)
{
	cout << "Gas Is Empty" << endl;
}
Car::~Car()
{
	cout << "Gas Tank detached" << endl;
}
Car::Car(int gas) : gasolineGauge(gas)
{
	cout << "Gas Charged! " << gasolineGauge << endl;
}
int Car::getGasGauge()
{
	return gasolineGauge;
}
int main()
{
	cout << "Car TankTest" << endl;
	cout << "1. no Fuel" << endl;
	HybridWaterCar();
	cout << "--------------------------------------" << endl;
	cout << "2. Only Water" << endl;
	HybridWaterCar(10);
	cout << "--------------------------------------" << endl;
	cout << "3.Water and Electricity" << endl;
	HybridWaterCar(10, 20);
	cout << "--------------------------------------" << endl;
	cout << "4. Charge All" << endl;
	HybridWaterCar(10, 20, 30);
	cout << "--------------------------------------" << endl;
    return 0;
}

