#include "counter.h"

void Counter::setValue(int new_val)
{
    if (new_val != val) {
        val = new_val;
        //zmiana wartości emituje sygnał
        emit valueChanged(val);
    }
}
