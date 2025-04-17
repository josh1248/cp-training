// M_PI is in <cmath>, but if your compiler does not have it, use
// const double PI = acos(-1.0)                  // or 2.0 * acos(0.0)
double DEG_to_RAD(double d) { return d*M_PI / 180.0; }
double RAD_to_DEG(double r) { return r*180.0 / M_PI; }
    // rotate p by theta degrees CCW w.r.t. origin (0, 0)
    point rotate(const point &p, double theta) {     // theta in degrees
    double rad = DEG_to_RAD(theta);                // convert to radians
    return point(p.x*cos(rad) - p.y*sin(rad),
                p.x*sin(rad) + p.y*cos(rad));
}