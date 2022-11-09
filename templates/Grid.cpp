#include "Grid.hpp"

template <size_t Rows, size_t Columns, typename T>
const std::optional<T>& Grid<Rows, Columns, T>::At(size_t row, size_t column) const
{
    VerifyRange(row, column);
    return m_elements[row][column];
}

template <size_t Rows, size_t Columns, typename T>
std::optional<T>& Grid<Rows, Columns, T>::At(size_t row, size_t column)
{
    return const_cast<std::optional<T>&>( std::as_const(*this).At(row, column) );
}

template <size_t Rows, size_t Columns, typename T>
void Grid<Rows, Columns, T>::VerifyRange(size_t row, size_t column) const
{
    if ( row >= Rows )
    {
        throw std::out_of_range{
            "Row " + std::to_string(row) + " is out of range. Matrix has " +
            std::to_string(Rows) + " rows.\n"
        };
    }
    else if ( column >= Columns )
    {
        throw std::out_of_range{
            "Column " + std::to_string(column) + " is out of range. Matrix has " +
            std::to_string(Columns) + " columns.\n"
        };
    }
}

template <size_t Rows, size_t Columns, typename T>
size_t Grid<Rows, Columns, T>::GetRowsCount() const
{
    return Rows;
}

template <size_t Rows, size_t Columns, typename T>
size_t Grid<Rows, Columns, T>::GetColumnsCount() const
{
    return Columns;
}

template <size_t Rows, size_t Columns, typename T>
template <size_t ERows, size_t EColumns, typename E>
Grid<Rows, Columns, T>::Grid(const Grid<ERows, EColumns, E>& src)
{
    for ( size_t i{}; i < Rows; i++ )
    {
        for ( size_t j{}; j < Columns; j++ )
        {
            if ( i < ERows && j < EColumns )
            {
                m_elements[i][j] = src.At(i, j);
            }
            else
            {
                m_elements[i][j].reset();
            }
        }
    }
}

template <size_t Rows, size_t Columns, typename T>
template <size_t ERows, size_t EColumns, typename E>
Grid<Rows, Columns, T>& Grid<Rows, Columns, T>::operator=(const Grid<ERows, EColumns, E>& rhs)
{
    Grid<Rows, Columns, T> temp{ rhs };
    Swap(temp);
    return *this;
}

template <size_t Rows, size_t Columns, typename T>
void Grid<Rows, Columns, T>::Swap(Grid& other) noexcept
{
    std::swap(m_elements, other.m_elements);
}

// testing template
template class Grid<8, 8, std::string>;