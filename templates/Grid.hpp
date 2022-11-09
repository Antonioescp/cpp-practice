#pragma once

#include <cstdlib>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

template <size_t Rows, size_t Columns, typename T = float>
class Grid
{
private:
    std::optional<T> m_elements[Rows][Columns]{};

    void VerifyRange(size_t row, size_t column) const;

public:

    Grid() = default;
    Grid(const Grid& src) = default;
    Grid& operator=(const Grid& src) = default;

    Grid(Grid&& src) = default;
    Grid& operator=(Grid&& src) = default;

    std::optional<T>& At(size_t row, size_t column);
    const std::optional<T>& At(size_t row, size_t column) const;

    template <size_t ERows, size_t EColumns, typename E>
    Grid(const Grid<ERows, EColumns, E>& src);

    template <size_t ERows, size_t EColumns, typename E>
    Grid& operator=(const Grid<ERows, EColumns, E>& rhs);

    void Swap(Grid& other) noexcept;

    size_t GetRowsCount() const;
    size_t GetColumnsCount() const;
};

template <size_t Rows, size_t Columns>
class Grid<Rows, Columns, const char*>
{
private:
    std::vector<std::vector<std::optional<std::string>>> m_elements;

    void VerifyRange(size_t row, size_t column) const;

public:

    Grid();
    virtual ~Grid() = default;

    Grid(const Grid& src) = default;
    Grid& operator=(const Grid& src) = default;

    Grid(Grid&& src) = default;
    Grid& operator=(Grid&& src) = default;

    std::optional<std::string>& At(size_t row, size_t column);
    const std::optional<std::string>& At(size_t row, size_t column) const;

    template <size_t ERows, size_t EColumns>
    Grid(const Grid<ERows, EColumns, const char*>& src);

    template <size_t ERows, size_t EColumns>
    Grid& operator=(const Grid<ERows, EColumns, const char*>& rhs);

    void Swap(Grid& other) noexcept;

    size_t GetRowsCount() const;
    size_t GetColumnsCount() const;
};

template <size_t Rows, size_t Columns>
Grid<Rows, Columns, const char*>::Grid()
{
    m_elements.resize(Rows);
    for ( auto& column : m_elements )
    {
        column.resize(Columns);
    }
}

template <size_t Rows, size_t Columns>
void Grid<Rows, Columns, const char*>::VerifyRange(size_t row, size_t column) const
{
    if ( row >= Rows )
    {
        throw std::out_of_range{ "Row " + std::to_string(row) + " is out of range." };
    }
    else if ( column >= Columns )
    {
        throw std::out_of_range{ "Column " + std::to_string(column) + " is out of range." };
    }
}

template <size_t Rows, size_t Columns>
std::optional<std::string>& Grid<Rows, Columns, const char*>::At(size_t row, size_t column)
{
    return const_cast<std::optional<std::string>&>( std::as_const(*this).At(row, column) );
}

template <size_t Rows, size_t Columns>
const std::optional<std::string>& Grid<Rows, Columns, const char*>::At(size_t row, size_t column) const
{
    VerifyRange(row, column);
    return m_elements[row][column];
}

template <size_t Rows, size_t Columns>
template <size_t ERows, size_t EColumns>
Grid<Rows, Columns, const char*>::Grid(const Grid<ERows, EColumns, const char*>& src)
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

template <size_t Rows, size_t Columns>
template <size_t ERows, size_t EColumns>
Grid<Rows, Columns, const char*>& Grid<Rows, Columns, const char*>::operator=(const Grid<ERows, EColumns, const char*>& rhs)
{
    Grid<Rows, Columns, const char*> tmp{ rhs };
    Swap(tmp);
    return *this;
}

template <size_t Rows, size_t Columns>
void Grid<Rows, Columns, const char*>::Swap(Grid& other) noexcept
{
    std::swap(m_elements, other.m_elements);
}

#include "Grid.cpp"