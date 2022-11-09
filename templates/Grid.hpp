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

#include "Grid.cpp"