// -*- lsst-c++ -*-

/**
 * @file MathUtils.hxx
 * @brief Declaration of the MathUtils class
 * @author Benjamin Thomas Schwertfeger
 * @copyright Benjamin Thomas Schwertfeger
 * @link https://b-schwertfeger.de
 * @github https://github.com/btschwertfeger/Bias-Adjustment-Cpp
 *
 *  * Copyright (C) 2022  Benjamin Thomas Schwertfeger
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef __MathUtils__
#define __MathUtils__

#include <iostream>
#include <vector>

typedef float (*Func_one)(std::vector<float>& x);
typedef float (*Func_two)(std::vector<float>& x, std::vector<float>& y);

class MathUtils {
   public:
    MathUtils();
    ~MathUtils();

    static std::vector<std::string> available_methods;
    static std::vector<std::string> requires_1_ds;
    static std::vector<std::string> requires_2_ds;

    static Func_one get_method_for_1_ds(std::string name);
    static Func_two get_method_for_2_ds(std::string name);

    static float correlation_coefficient(std::vector<float>& x, std::vector<float>& y);
    static float rmse(std::vector<float>& x, std::vector<float>& y);
    static float mbe(std::vector<float>& x, std::vector<float>& y);
    static float ioa(std::vector<float>& x, std::vector<float>& y);
    static float sd(std::vector<float>& x);
    static float variance(std::vector<float>& x);
    static double mean(std::vector<float>& a);
    static double lerp(double a, double b, double x);

    static std::vector<int> get_pdf(std::vector<float>& arr, std::vector<double>& bins);
    static std::vector<int> get_cdf(std::vector<float>& arr, std::vector<double>& bins);
    static double interpolate(std::vector<double>& xData, std::vector<double>& yData, double x, bool extrapolate);

   private:
};

#endif