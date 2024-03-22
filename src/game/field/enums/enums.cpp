#include "enums.h"

ImageType& operator++(ImageType& type) {
    return type = static_cast<ImageType>(static_cast<int>(type) + 1);
}

ImageType operator++(ImageType& type, int)
{
    ImageType oldType = type;
    ++type;
    return oldType;
}

//returns a set of possible target direction depending on direction
QSet<MoveDestination> getMoveDestinationsByDirection(const MoveDirection& direction)
{
    QSet<MoveDestination> targets;

    switch (direction)
    {
    case MoveDirection::all:
        targets = { Up, Down, Left, Right, UpLeft, UpRight, DownLeft, DownRight };
        break;
    case MoveDirection::vertical:
        targets = { Up, Down };
        break;
    case MoveDirection::horizontal:
        targets = { Left, Right };
        break;
    case MoveDirection::diagonally:
        targets = { UpLeft, UpRight, DownLeft, DownRight };
        break;
    case MoveDirection::verticallyAndHorizontally:
        targets = { Up, Down, Left, Right };
        break;
    }

    return targets;
}

//returns a set of possible target direction wich includ its destination
QSet<MoveDirection> getMoveDirectionsByDistination(const MoveDestination& destination)
{
    QSet<MoveDirection> directions;

    switch (destination)
    {
    case MoveDestination::Up:
        directions.insert(MoveDirection::vertical);
        directions.insert(MoveDirection::verticallyAndHorizontally);
        directions.insert(MoveDirection::all);
        break;
    case MoveDestination::Down:
        directions.insert(MoveDirection::vertical);
        directions.insert(MoveDirection::verticallyAndHorizontally);
        directions.insert(MoveDirection::all);
        break;
    case MoveDestination::Left:
        directions.insert(MoveDirection::horizontal);
        directions.insert(MoveDirection::verticallyAndHorizontally);
        directions.insert(MoveDirection::all);
        break;
    case MoveDestination::Right:
        directions.insert(MoveDirection::horizontal);
        directions.insert(MoveDirection::all);
        directions.insert(MoveDirection::verticallyAndHorizontally);
        break;
    case MoveDestination::UpLeft:
        directions.insert(MoveDirection::diagonally);
        directions.insert(MoveDirection::all);
        break;
    case MoveDestination::UpRight:
        directions.insert(MoveDirection::diagonally);
        directions.insert(MoveDirection::all);
        break;
    case MoveDestination::DownLeft:
        directions.insert(MoveDirection::diagonally);
        directions.insert(MoveDirection::all);
        break;
    case MoveDestination::DownRight:
        directions.insert(MoveDirection::diagonally);
        directions.insert(MoveDirection::all);
        break;
    }

    return directions;
}

// returns true if direction in possibleDirections
bool isValidDestinationByPossibleDirection(const QSet<MoveDirection>& possibleDirections, const MoveDirection direction)
{
    for (auto direction : possibleDirections) {
        if (direction == direction) {
            return true;
        }
    }
    return false;
}
