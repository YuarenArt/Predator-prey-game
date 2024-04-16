//#pragma once

//#include "../ActorsInterface.h"


// НЕ работает

//class AAlgorithm
//{
//public:
//    MoveDestination getBestMove(const Position& currentPosition, const Position& targetPosition);
//    AAlgorithm(const PositionMatrix& matrix, const ActorsInterface& actor);
//
//private:
//
//    struct Node {
//        Position position;
//        int g; // расстояние от стартовой точки
//        int h; // эвристическая оценка расстояния до конечной точки
//        int f; // общая стоимость пути (g + h)
//        Node* parent;
//
//        Node(const Position& position, int g, int h, Node* parent = nullptr);
//    };
//
//    const PositionMatrix& positionMatrix;
//    const ActorsInterface& actor;
//
//    std::unordered_map<Position, Node*> openSet;
//    std::unordered_map<Position, Node*> closedSet;
//
//
//    std::vector<Position> getNeighbors(const Position& position) const;
//    int                   getHeuristic(const Position& position1, const Position& position2) const;
//};

