#include <ien/bit_view.hpp>

#include <ien/assert.hpp>

namespace ien
{
    bool bit_view::operator[](size_t index) const
    {
        LIEN_DEBUG_ASSERT_MSG((index < (_len * 8)), "Out of range!");

        size_t byte_idx = index / 8;
        size_t bit_idx = index % 8;
        uint8_t mask = (uint8_t)1 << (7 - bit_idx);
        uint8_t byte = _data_ptr[byte_idx];

        return (byte | mask) == byte;
    }

    size_t bit_view::size() const
    {
        return _len * 8;
    }

    ien::fixed_vector<bool> bit_view::get_bits(size_t index, size_t count) const
    {
        ien::fixed_vector<bool> result(count);
        for(size_t i = 0; i < count; ++i)
        {
            result[i] = this->operator[](index++);
        }
        return result;
    }
}