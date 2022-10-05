#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <cassert>

template <typename elem_type, std::size_t size>
class KernalArray {
    private:
        std::size_t size_;
        elem_type array_[size] = {};
    public:
        KernalArray(): size_(size) {}
        ~KernalArray() {}

        std::size_t get_size() const { return size_; }

              elem_type& get_array_elem(const std::size_t i                      )       { return array_[i]; }
        const elem_type& get_array_elem(const std::size_t i                      ) const { return array_[i]; }
              void       set_array_elem(const std::size_t i, const elem_type elem)       { array_[i] = elem; }
};

template <typename elem_type, std::size_t size>
class Array {
    private:
        KernalArray<elem_type, size> kernal_array_;
    public:
        Array(): kernal_array_() {}

               Array      (const Array& array) = default;
        Array& operator = (const Array& array) = default;
        ~Array() {}

        double& operator [] (const std::size_t i) {
            if (i < kernal_array_.get_size()) {
                return kernal_array_.get_array_elem(i);
            } else {
                std::cout << "Invalid index\n";
                assert(0);
            }
        }

        const double& operator [] (const std::size_t i) const {
            if (i < kernal_array_.get_size()) {
                return kernal_array_.get_array_elem(i);
            } else {
                std::cout << "Invalid index\n";
                assert(0);
            }
        }

        void print_array() const {
            for (std::size_t i = 0; i < kernal_array_.get_size(); i++) {
                std::cout << kernal_array_.get_array_elem(i) << "\n";
            }
        }
};

#endif // ARRAY_HPP_
