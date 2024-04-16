//#include "AAlgorithm.h"

// �� ��������

//AAlgorithm::Node::Node(const Position& position, int g, int h, Node* parent) :
//    position(position), g(g), h(h), f(g + h), parent(parent) { }
//
//AAlgorithm::AAlgorithm(const PositionMatrix& matrix, const ActorsInterface& actor) : positionMatrix(matrix), actor(actor) { }
//
//MoveDestination AAlgorithm::getBestMove(const Position& currentPosition, const Position& targetPosition)
//{
//    // ��������� ��������� ������� � �������� ������
//    Node* startNode = new Node(currentPosition, 0, getHeuristic(currentPosition, targetPosition), nullptr);
//    openSet[currentPosition] = startNode;
//
//    // ���� ������ ����
//    while (!openSet.empty())
//    {
//        // ������� ���� � ����������� ��������� f
//        Node* currentNode = nullptr;
//        for (const auto& node : openSet)
//        {
//            if (!currentNode || node.second->f < currentNode->f)
//            {
//                currentNode = node.second;
//            }
//        }
//
//        // ������� ������� ���� �� ��������� ������
//        openSet.erase(currentNode->position);
//
//        // ���������, �������� �� �� ����
//        if (currentNode->position == targetPosition)
//        {
//            // ��������������� ���� �� ���� �� ������
//            Node* parentNode = currentNode->parent;
//            while (parentNode != nullptr)
//            {
//                // ���������� ����������� �������� �� �������� ���� � ������������
//                Position direction = parentNode->position - currentNode->position;
//                int moveLength = actor.getMoveLength();
//                if (direction.getPosition().getColumn() == 0) // ������������ �����������
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
//                else if (direction.getPosition().getRow() == 0) // �������������� �����������
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
//                else if (std::abs(direction.getPosition().getColumn()) == std::abs(direction.getPosition().getRow())) // ������������ �����������
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
//        // ��������� ������� �������� ���� � �������� ������
//        for (const Position& neighborPosition : getNeighbors(currentNode->position))
//        {
//            // ���������, �� ��������� �� ����� � �������� ������
//            if (closedSet.find(neighborPosition) != closedSet.end())
//            {
//                continue;
//            }
//
//            // ��������� ��������� ���� �� ������ �� ������
//            int tentativeG = currentNode->g + 1;
//
//            // ���� ����� ��� ��������� � �������� ������
//            if (openSet.find(neighborPosition) != openSet.end())
//            {
//                // ���������, �� ��������� �� ����� �������� ����
//                if (tentativeG >= openSet[neighborPosition]->g)
//                {
//                    continue;
//                }
//            }
//
//            // ������� ����� ���� ��� ������
//            Node* neighborNode = new Node(neighborPosition, tentativeG, getHeuristic(neighborPosition, targetPosition), currentNode);
//
//            // ��������� ���� � �������� ������
//            openSet[neighborPosition] = neighborNode;
//        }
//
//        // ��������� ������� ���� � �������� ������
//        closedSet[currentNode->position] = currentNode;
//    }
//
//    // ���� ���� �� ���� �������, ���������� MoveDestination::Up
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
//        // ���������, ����� �� ��� ������� ��� � ��������� �����������
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
//            // ��������, �� ������� �� ����� �� ������� �����
//            if (!positionMatrix.isValidPosition(neighborPosition))
//            {
//                continue;
//            }
//
//            // ��������, �� �������� �� ����� ������������
//            if (positionMatrix.isBarrier(neighborPosition))
//            {
//                // ���� ����� �������� ������������, �� ��������� ���������� ������� � ������ �������
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
//            // ��������, �� ��������� �� ���������� �� ������ ������������ ����� ����
//            if (std::abs(neighborPosition.getPosition().getColumn() - position.getPosition().getColumn()) > moveLength ||
//                std::abs(neighborPosition.getPosition().getRow() - position.getPosition().getRow()) > moveLength)
//            {
//                break;
//            }
//
//            // ���������� ������ � ������
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
