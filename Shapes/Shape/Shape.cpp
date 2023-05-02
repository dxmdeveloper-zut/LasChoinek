#include "Shape.hpp"
#include <algorithm>

static inline void matrix_uniqptr_ondelete(size_t height, bool** arr){
    std::for_each(arr, arr + height, std::default_delete<bool[]>());
    delete [] arr;
}

Shape::Shape(size_t mat_width, size_t mat_height, RGB color, char symbol) 
    : mat_width{mat_width}, mat_height{mat_height}, color{color}, symbol{symbol}{
    this->matrix = std::unique_ptr<bool*[], std::function<void(bool**)> >(
        new bool*[mat_height](),
        [mat_height](bool** arr) {matrix_uniqptr_ondelete(mat_height, arr);}
);

}

