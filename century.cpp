int centuryFromYear(int year) {
    int century;
    int int_part = year/100;
    int rem_part = year%100;
    if (rem_part > 0) {
        century = int_part + 1;
    } else {
        century = int_part;
    }
    return century;
}
