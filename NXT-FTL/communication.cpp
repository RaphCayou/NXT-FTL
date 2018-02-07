#include "communication.h"
#include "../NxtLibrary/nxt.h"

communication::communication()
{
}


communication::~communication()
{
}

bool communication::connect(Connection_type type)
{
	switch (type)
	{
		case communication::BLUETOOF:
			connection = new Bluetooth();
			break;
		case communication::USB:
			break;
		default:
			break;
	}
	return true;
}

bool communication::disconnect()
{
	return false;
}

SensorDto communication::initializeSensor(Sensor_port port, Sensor_type type)
{
	return SensorDto{};
}

int communication::getSensorValue(SensorDto sensorDto)
{
	return 0;
}

std::array<int, 3> communication::getSensorRGB(SensorDto sensorDto)
{
	return std::array<int, 3>();
}

std::string communication::printSensorValue(SensorDto sensorDto)
{
	return std::string();
}

MotorDto communication::initializeMotor(Motor_port port)
{
	return MotorDto{};
}

long int communication::getMotorRotation(MotorDto motorDto)
{
	return 0;
}

bool communication::isMotorRunning(MotorDto motorDto)
{
	return false;
}

void communication::startMotor(MotorDto motorDto, char speed, unsigned int degrees, bool reply)
{
}

void communication::coastMotor(MotorDto motorDto, char speed, unsigned int degrees, bool reply)
{
}

void communication::stopMotor(MotorDto motorDto, bool reply)
{
}
