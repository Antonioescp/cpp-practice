#include <iostream>
#include <optional>

#include "Grid.hpp"

class ChessPiece
{
public:
    explicit ChessPiece() = default;
};

std::ostream& operator<<(std::ostream& sobj, const ChessPiece& piece)
{
    sobj << "Hello, im a pice";
    return sobj;
}

int main()
{
    Grid <8, 8, ChessPiece> chessBoard;
    Grid <8, 8, ChessPiece> board;

    chessBoard.At(0, 0) = ChessPiece{};

    const auto otherChessBoard{ chessBoard };

    if ( auto piece{ otherChessBoard.At(0, 0) }; piece.has_value() )
    {
        std::cout << *piece << '\n';
    }
    else
    {
        std::cout << "has no value";
    }

    Grid<2, 2, const char*> myStrGrid;
    const char* dummy = "dumb dumb";
    myStrGrid.At(0, 0) = dummy;

    if ( const auto& cell{ myStrGrid.At(0, 0) }; cell.has_value() )
    {
        std::cout << cell.value() << '\n';
    }
}