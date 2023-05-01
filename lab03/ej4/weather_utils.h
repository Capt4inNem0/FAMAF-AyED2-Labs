#ifndef WEATHER_UTILS_H
#define WEATHER_UTILS_H
#include "array_helpers.h"

void year_max_temp_max(WeatherTable table, int arr[]);

void year_month_max_rainfall(WeatherTable table, unsigned int arr[]);

int min_temp_min(WeatherTable table);

#endif
