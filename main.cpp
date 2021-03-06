
// Radio line of sight distance on Earth
// Author: KE6QH
// January 2022

#include <cstdlib>
#include <iostream>

// Compute Earth line of sight based on authalic radius per constants defined below.
// Height h in meters of stations above the surface.
// Ds (km) the straight (visual) distance is sqrt(2 * R * h / 1000) or approx. 3.57 * sqrt(h)
// Dc (km) the curved (refracted) distance is k * sqrt(2 * R * h / 1000) or approx. 4.12 * sqrt(h)
// k is the refraction coefficient of air for the wavelength in question (VHF/UHF in this case).

int main()
{
    double Rkm = 6371;     // Authalic radius of Earth (km). (IUGG)
    double Rmi = 3958.76;  // Authalic radius of Earth (mi). (IUGG)
    double k = 1.154;      // Coefficient of refraction of air at VHF/UHF.
    double h1;             // Height of station 1 (m)
    double h2;             // Height of station 2 (m)
    double fpm = 3.28084;  // Feet per meter.

    std::cout << "This program computes the straight line and refracted line of sight\n";
    std::cout << "in kilometers between two observers given their heights in meters.\n";
    std::cout << "It ignores terrain variations and equatorial bulge.\n\n";

    std::cout << "Station 1 height (meters)? ";
    std::cin >> h1;
    std::cout << "Station 2 height (meters)? ";
    std::cin >> h2;

    double d1s = sqrt(2 * Rkm * h1 / 1000);
    double d2s = sqrt(2 * Rkm * h2 / 1000);
    double d3s = d1s + d2s;

    double d1c = k * d1s;
    double d2c = k * d2s;
    double d3c = d1c + d2c;

    // In miles for the old timers.
    h1 *= fpm;
    h2 *= fpm;
    double d1smi = sqrt(2 * Rmi * h1 / 5280);
    double d2smi = sqrt(2 * Rmi * h2 / 5280);
    double d3smi = d1smi + d2smi;

    double d1cmi = k * d1smi;
    double d2cmi = k * d2smi;
    double d3cmi = d1cmi + d2cmi;

    std::cout.precision(0);
    std::cout << "\n";
    std::cout << "Straight line of sight distance from Station 1 to horizon: " << std::fixed << d1s << " km (" << d1smi << " miles) " << "\n";
    std::cout << "Straight line of sight distance from Station 2 to horizon: " << std::fixed << d2s << " km (" << d2smi << " miles) " << "\n";
    std::cout << "Straight line of sight distance from Station 1 to Station 2: " << std::fixed << d3s << " km (" << d3smi << " miles) " << "\n";

    std::cout << "\n";
    std::cout << "Curved line of sight distance from Station 1 to horizon: " << std::fixed << d1c << " km (" << d1cmi << " miles) " << "\n";
    std::cout << "Curved line of sight distance from Station 2 to horizon: " << std::fixed << d2c << " km (" << d2cmi << " miles) " << "\n";
    std::cout << "Curved line of sight distance from Station 1 to Station 2: " << std::fixed << d3c << " km (" << d3cmi << " miles) " << "\n";

    return 0;
}

/*
Output with 30m and 40m as h1, h2:
Straight line of sight distance from Station 1 to horizon: 20 km (12 miles)
Straight line of sight distance from Station 2 to horizon: 23 km (14 miles)
Straight line of sight distance from Station 1 to Station 2: 42 km (26 miles)

Curved line of sight distance from Station 1 to horizon: 23 km (14 miles)
Curved line of sight distance from Station 2 to horizon: 26 km (16 miles)
Curved line of sight distance from Station 1 to Station 2: 49 km (30 miles)
*/