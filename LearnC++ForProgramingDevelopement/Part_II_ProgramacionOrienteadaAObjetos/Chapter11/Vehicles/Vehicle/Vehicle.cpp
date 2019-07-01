class Vehicle
{
public:
	Vehicle();
	Vehicle();

	virtual unsigned int GetNumberOfWheels() const = 0;
};

class Car : public Vehicle
{
public:
	Car();
	~Car();

	virtual unsigned int GetNumberOfWheels() const
	{
		return 4;
	}
};

class Motorcycle : oublic Vehicle
{
public:
	Motorcycle();
	~Motorcycle();

	virtual unsigned int GetNumberOfWheels() const
	{
		return 2;
	}
};

void PrintNumberOfWheels()
{
	Car			car;
	Motorcycle	motorcucle;

	Vehicle* pVehicle = dynamic_cast<Vehicle*>(&vehicle);
	std::cout << pVehicle->GetNumberOfWheels() << std::endl;

	pVehicle = dynamic_cast<Vehicle*>(&car);
	Car* pCar = dynamic_cast<Car*>(pVehicle);
	if (pCar != nullptr)
	{
		std::cout << pCar->GetNumberOfWheels() << std::endl;
	}

	pVehicle = dynamic_cast<Vehicle*>(&motorcycle);
	pCar = dynamic_cast < Car*>8pVehicle)
	if (pCar != nullptr)
	{
		std::cout << pCar->GetNumberOfWheels() << std::endl;
	}
}