//#include "AAlgorithm.h"

// Ќ≈ работает

//AAlgorithm::Node::Node(const Position& position, int g, int h, Node* parent) :
//    position(position), g(g), h(h), f(g + h), parent(parent) { }
//
//AAlgorithm::AAlgorithm(const PositionMatrix& matrix, const ActorsInterface& actor) : positionMatrix(matrix), actor(actor) { }
//
//MoveDestination AAlgorithm::getBestMove(const Position& currentPosition, const Position& targetPosition)
//{
//    // ƒобавл€ем стартовую позицию в открытый список
//    Node* startNode = new Node(currentPosition, 0, getHeuristic(currentPosition, targetPosition), nullptr);
//    openSet[currentPosition] = startNode;
//
//    // ÷икл поиска пути
//    while (!openSet.empty())
//    {
//        // Ќаходим узел с минимальным значением f
//        Node* currentNode = nullptr;
//        for (const auto& node : openSet)
//        {
//            if (!currentNode || node.second->f < currentNode->f)
//            {
//                currentNode = node.second;
//            }
//        }
//
//        // ”дал€ем текущий узел из открытого списка
//        openSet.erase(currentNode->position);
//
//        // ѕровер€ем, достигли ли мы цели
//        if (currentNode->position == targetPosition)
//        {
//            // ¬осстанавливаем путь от цели до старта
//            Node* parentNode = currentNode->parent;
//            while (parentNode != nullptr)
//            {
//                // ќпредел€ем направление движени€ из текущего узла в родительский
//                Position direction = parentNode->position - currentNode->position;
//                int moveLength = actor.getMoveLength();
//                if (direction.getPosition().getColumn() == 0) // вертикальное направление
//                {
//                    if (direction.getPosition().getRow() > 0)
//                    {
//                        for (int i = 1; i <= moveLength; ++i)
//                        {
//                            if (currentNode->position.getPosition().getRow() + i == parentNode->position.getPosition().getRow())
//                            {
//                                return MoveDestination::Down;
//                            }
//                        }
//                    }
//                    else
//                    {
//                        for (int i = 1; i <= moveLength; ++i)
//                        {
//                            if (currentNode->position.getPosition().getRow() - i == parentNode->position.getPosition().getRow())
//                            {
//                                return MoveDestination::Up;
//                            }
//                        }
//                    }
//                }
//                else if (direction.getPosition().getRow() == 0) // горизонтальное направление
//                {
//                    if (direction.getPosition().getColumn() > 0)
//                    {
//                        for (int i = 1; i <= moveLength; ++i)
//                        {
//                            if (currentNode->position.getPosition().getColumn() + i == parentNode->position.getPosition().getColumn())
//                            {
//                                return MoveDestination::Right;
//                            }
//                        }
//                    }
//                    else
//                    {
//                        for (int i = 1; i <= moveLength; ++i)
//                        {
//                            if (currentNode->position.getPosition().getColumn() - i == parentNode->position.getPosition().getColumn())
//                            {
//                                return MoveDestination::Left;
//                            }
//                        }
//                    }
//                }
//                else if (std::abs(direction.getPosition().getColumn()) == std::abs(direction.getPosition().getRow())) // диагональное направление
//                {
//                    if (direction.getPosition().getColumn() > 0 && direction.getPosition().getRow() > 0)
//                    {
//                        for (int i = 1; i <= moveLength; ++i)
//                        {
//                            if (currentNode->position.getPosition().getColumn() + i == parentNode->position.getPosition().getColumn() &&
//                                currentNode->position.getPosition().getRow() + i == parentNode->position.getPosition().getRow())
//                            {
//                                return MoveDestination::DownRight;
//                            }
//                        }
//                    }
//                    else if (direction.getPosition().getColumn() < 0 && direction.getPosition().getRow() < 0)
//                    {
//                        for (int i = 1; i <= moveLength; ++i)
//                        {
//                            if (currentNode->position.getPosition().getColumn() - i == parentNode->position.getPosition().getColumn() &&
//                                currentNode->position.getPosition().getRow() - i == parentNode->position.getPosition().getRow())
//                            {
//                                return MoveDestination::UpLeft;
//                            }
//                        }
//                    }
//                    else if (direction.getPosition().getColumn() > 0 && direction.getPosition().getRow() < 0)
//                    {
//                        for (int i = 1; i <= moveLength; ++i)
//                        {
//                            if (currentNode->position.getPosition().getColumn() + i == parentNode->position.getPosition().getColumn() &&
//                                currentNode->position.getPosition().getRow() - i == parentNode->position.getPosition().getRow())
//                            {
//                                return MoveDestination::UpRight;
//                            }
//                        }
//                    }
//                    else if (direction.getPosition().getColumn() < 0 && direction.getPosition().getRow() > 0)
//                    {
//                        for (int i = 1; i <= moveLength; ++i)
//                        {
//                            if (currentNode->position.getPosition().getColumn() - i == parentNode->position.getPosition().getColumn() &&
//                                currentNode->position.getPosition().getRow() + i == parentNode->position.getPosition().getRow())
//                            {
//                                return MoveDestination::DownLeft;
//                            }
//                        }
//                    }
//                }
//
//                currentNode = parentNode;
//                parentNode = parentNode->parent;
//            }
//        }
//
//        // ƒобавл€ем соседей текущего узла в открытый список
//        for (const Position& neighborPosition : getNeighbors(currentNode->position))
//        {
//            // ѕровер€ем, не находитс€ ли сосед в закрытом списке
//            if (closedSet.find(neighborPosition) != closedSet.end())
//            {
//                continue;
//            }
//
//            // ¬ычисл€ем стоимость пути от старта до соседа
//            int tentativeG = currentNode->g + 1;
//
//            // ≈сли сосед уже находитс€ в открытом списке
//            if (openSet.find(neighborPosition) != openSet.end())
//            {
//                // ѕровер€ем, не обнаружен ли более короткий путь
//                if (tentativeG >= openSet[neighborPosition]->g)
//                {
//                    continue;
//                }
//            }
//
//            // —оздаем новый узел дл€ соседа
//            Node* neighborNode = new Node(neighborPosition, tentativeG, getHeuristic(neighborPosition, targetPosition), currentNode);
//
//            // ƒобавл€ем узел в открытый список
//            openSet[neighborPosition] = neighborNode;
//        }
//
//        // ƒобавл€ем текущий узел в закрытый список
//        closedSet[currentNode->position] = currentNode;
//    }
//
//    // ≈сли цель не была найдена, возвращаем MoveDestination::Up
//    return MoveDestination::Up;
//}
//
//std::vector<Position> AAlgorithm::getNeighbors(const Position& position) const
//{
//    std::vector<Position> neighbors;
//
//    QSet<MoveDestination> possibleDirections = getMoveDestinationsByDirection(actor.getPossibleDirection());
//
//    for (MoveDestination direction : possibleDirections)
//    {
//        Position neighborPosition = position;
//
//        // ѕровер€ем, может ли нпс сделать ход в выбранном направлении
//        int moveLength = actor.getMoveLength();
//        for (int i = 1; i <= moveLength; ++i)
//        {
//            switch (direction)
//            {
//            case MoveDestination::Up:
//                neighborPosition.moveUp();
//                break;
//            case MoveDestination::Down:
//                neighborPosition.moveDown();
//                break;
//            case MoveDestination::Left:
//                neighborPosition.moveLeft();
//                break;
//            case MoveDestination::Right:
//                neighborPosition.moveRight();
//                break;
//            case MoveDestination::UpLeft:
//                neighborPosition.moveUpLeft();
//                break;
//            case MoveDestination::UpRight:
//                neighborPosition.moveUpRight();
//                break;
//            case MoveDestination::DownLeft:
//                neighborPosition.moveDownLeft();
//                break;
//            case MoveDestination::DownRight:
//                neighborPosition.moveDownRight();
//                break;
//            }
//
//            // ѕроверка, не выходит ли сосед за пределы карты
//            if (!positionMatrix.isValidPosition(neighborPosition))
//            {
//                continue;
//            }
//
//            // ѕроверка, не €вл€етс€ ли сосед преп€тствием
//            if (positionMatrix.isBarrier(neighborPosition))
//            {
//                // ≈сли сосед €вл€етс€ преп€тствием, то добавл€ем предыдущую позицию в список соседей
//                if (i == 1)
//                {
//                    switch (direction)
//                    {
//                    case MoveDestination::Up:
//                        neighborPosition.moveUp();
//                        break;
//                    case MoveDestination::Down:
//                        neighborPosition.moveDown();
//                        break;
//                    case MoveDestination::Left:
//                        neighborPosition.moveLeft();
//                        break;
//                    case MoveDestination::Right:
//                        neighborPosition.moveRight();
//                        break;
//                    case MoveDestination::UpLeft:
//                        neighborPosition.moveUpLeft();
//                        break;
//                    case MoveDestination::UpRight:
//                        neighborPosition.moveUpRight();
//                        break;
//                    case MoveDestination::DownLeft:
//                        neighborPosition.moveDownLeft();
//                        break;
//                    case MoveDestination::DownRight:
//                        neighborPosition.moveDownRight();
//                        break;
//                    }
//                    neighbors.push_back(neighborPosition);
//                }
//                break;
//            }
//
//            // ѕроверка, не превышает ли рассто€ние до соседа максимальную длину хода
//            if (std::abs(neighborPosition.getPosition().getColumn() - position.getPosition().getColumn()) > moveLength ||
//                std::abs(neighborPosition.getPosition().getRow() - position.getPosition().getRow()) > moveLength)
//            {
//                break;
//            }
//
//            // ƒобавление соседа в список
//            neighbors.push_back(neighborPosition);
//        }
//    }
//
//    return neighbors;
//}
//
//int AAlgorithm::getHeuristic(const Position& position1, const Position& position2) const
//{
//    int dx = std::abs(position1.getPosition().getColumn() - position2.getPosition().getColumn());
//    int dy = std::abs(position1.getPosition().getRow() - position2.getPosition().getRow());
//    return dx + dy;
//}
