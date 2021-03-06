#include "brain.h"
using namespace nxtftl;


brain::brain(unsigned int stopDistance) : stopDistance(stopDistance)
{
}

bool brain::check_for_critical_stop(const distance_sensor_dto distance_sensor)
{
	// The distance before the robot stop
	// If distanceSensor.distance < stopDistance => stop
	return distance_sensor.distance <= stopDistance;
}

std::tuple<float, bool> brain::compute_direction(const touch_sensor_dto touch_sensor, color_sensor_dto left_color_sensor, color_sensor_dto right_color_sensor) const
{
	bool needsToStop = false;
	// The touch sensor stop the robot
	// If touchsensor is touch => stop
	needsToStop |= touch_sensor.is_pressed;

	// Calculate the direction of the robot
    const float sensorTotal = left_color_sensor.value() + right_color_sensor.value();
	float direction{ left_color_sensor.value()/sensorTotal - right_color_sensor.value()/sensorTotal };

	return std::tuple<float, bool>{direction, needsToStop};
}
