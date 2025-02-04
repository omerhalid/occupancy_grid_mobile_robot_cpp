#ifndef OCCUPANCYGRID_H
#define OCCUPANCYGRID_H

#include <vector>
#include <string>
#include "sensor.hpp"
#include "position.hpp"

/**
 * @class OccupancyGrid
 * @brief A class representing an occupancy grid for a robot.
 */
class OccupancyGrid {
private:
    /**
     * @brief Width of the map in meters.
     */
    const double mapWidth = 10.0; // Adjust as per the room size or area in which the robot operates

    /**
     * @brief Height of the map in meters.
     */
    const double mapHeight = 10.0;
    
    /**
     * @brief Resolution of the grid in meters. Each cell represents a 10cm x 10cm area.
     */
    const double gridResolution = 0.1; 

    /**
     * @brief 2D vector representing the occupancy grid.
     */
    std::vector<std::vector<double>> occupancyGrid;

public:
    /**
     * @brief Construct a new OccupancyGrid object.
     */
    OccupancyGrid();

    /**
     * @brief Calculate the center position of a cell in the occupancy grid.
     * 
     * @param row The row index of the cell.
     * @param column The column index of the cell.
     * @return The center position of the cell.
     */
    Position calculateCenterPosition(int row, int column);

    /**
     * @brief Calculates the distance and angle from the robot to a cell.
     *
     * @param robotX The x-coordinate of the robot's position.
     * @param robotY The y-coordinate of the robot's position.
     * @param robotTheta The orientation of the robot in radians.
     * @param cellCenter The center position of the cell.
     * @return A pair containing the distance and angle from the robot to the cell.
     */
    std::pair<double, double> calculateDistanceAndAngle(double robotX, double robotY, double robotTheta, Position cellCenter);

    /**
     * @brief Update the occupancy grid based on the robot's position and sensor data.
     * 
     * @param robotX The x-coordinate of the robot's position.
     * @param robotY The y-coordinate of the robot's position.
     * @param robotTheta The orientation of the robot in radians.
     * @param sensorData An array of sensor readings.
     */
    void updateGrid(double robotX, double robotY, double robotTheta, const double* sensorData);

    /**
     * @brief Save the occupancy grid to a file.
     * 
     * @param filename The name of the file to save to.
     */
    void saveToFile(const std::string& filename) const;
};

#endif // OCCUPANCYGRID_H
