#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <stdarg.h>
#include <cassert>

class KernalArray {
    private:
        size_t maxSize_;
        double* array_;
    public:
        KernalArray(const size_t maxSize, ...):
            maxSize_(maxSize),
            array_(new double[maxSize_])
            {}

        KernalArray(const KernalArray&) = default;
        KernalArray& operator = (const KernalArray&) = default;
        ~KernalArray() {
            delete [] array_;
        }

        size_t getMaxSize() const { return maxSize_; }

        double& getArrayElem(const size_t i) const { return array_[i]; }
        void setArrayElem(const size_t i, const double elem) { array_[i] = elem; }
};

class Array {
    private:
        KernalArray kernalArray_;
    public:
        KernalArray getKernalArray() const { return kernalArray_; }

        Array(const size_t maxSize, ...):
            kernalArray_(maxSize)
            {
                va_list vl;
                va_start(vl, maxSize);
                for (size_t i = 0; i < maxSize; i++) {
                    kernalArray_.setArrayElem(i, va_arg(vl, double));
                }
                va_end(vl);
            }

        Array(const Array& array):
            kernalArray_(array.getKernalArray())
            {}
        Array& operator = (const Array& array) {
            kernalArray_ = array.getKernalArray();

            return *this;
        }
        ~Array() {}

        double& operator [] (const size_t i) {
            if (i < kernalArray_.getMaxSize()) {
                return kernalArray_.getArrayElem(i);
            } else {
                std::cout << "Invalid index\n";
                assert(0);
            }
        }

        const double& operator [] (const size_t i) const {
            if (i < kernalArray_.getMaxSize()) {
                return kernalArray_.getArrayElem(i);
            } else {
                std::cout << "Invalid index\n";
                assert(0);
            }
        }

        void printArray() const {
            for (size_t i = 0; i < kernalArray_.getMaxSize(); i++) {
                std::cout << kernalArray_.getArrayElem(i) << "\n";
            }
        }
};

#endif // ARRAY_HPP_
