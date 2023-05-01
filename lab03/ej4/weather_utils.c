#include "weather_utils.h"
#include "weather.h"
#include "array_helpers.h"

int min_temp_min(WeatherTable table){
    int min = table[0][0][0]._min_temp;
    for (unsigned int i = 0; i < YEARS; ++i) {
        for (unsigned int j = 0; j < MONTHS; ++j) {
            for (unsigned int k = 0; k < DAYS; ++k) {
                if (table[i][j][k]._min_temp < min) {
                    min = table[i][j][k]._min_temp;
                }
            }
        }
    }
    return min;
}

void year_max_temp_max(WeatherTable table, int arr[]) {
    for (unsigned int i = 0; i < YEARS; ++i) {
        int max = table[i][0][0]._max_temp;
        for (unsigned int j = 0; j < MONTHS; ++j) {
            for (unsigned int k = 0; k < DAYS; ++k) {
                if (table[i][j][k]._max_temp > max) {
                    max = table[i][j][k]._max_temp;
                }
            }
        }
        arr[i] = max;
    }
}

void year_month_max_rainfall(WeatherTable table, unsigned int arr[]) {
    for (unsigned int i = 0; i < YEARS; ++i) {
        unsigned int max = table[i][0][0]._rainfall;
        for (unsigned int j = 0; j < MONTHS; ++j) {
            for (unsigned int k = 0; k < DAYS; ++k) {
                if (table[i][j][k]._rainfall > max) {
                    max = table[i][j][k]._rainfall;
                    arr[i] = j;
                }
            }
        }
    }
}
