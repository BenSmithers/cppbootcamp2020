#include <stdio.h>
#include <iostream>
#include <math.h>

class Position{
    public:
        Position() = default;
        Position(double x, double y, double z);
    private:
        double x_;
        double y_;
        double z_;
    public:
        double get_x() const{
            return x_;
        }
        double get_y() const{
            return y_;
        }
        double get_z() const{
            return z_;
        }
};

Position::Position(double x, double y, double z){
    x_ = x;
    y_ = y;
    z_ = z;
}

struct Direction{
    public: 
        Direction() = default;
        Direction(double zenith, double azimuth);
    private:
        double zenith_;
        double azimuth_;
    public:
        double get_zenith() const{
            return zenith_;
        }
        double get_azimuth() const{
            return azimuth_;
        }
};

Direction::Direction(double zenith, double azimuth){
    if (zenith>=M_PI || zenith<0){
        throw std::invalid_argument("Received invalid zenith");
    }
    if (azimuth>=(2*M_PI) || azimuth<0){
        throw std::invalid_argument("Received invalid azimuth");
    }

    zenith_ = zenith;
    azimuth_ = azimuth;
}

class Particle{
    public:
       Position position() const
       {
            return position_;   
       }
       Direction direction() const
       {
            return direction_;
       }
    private:
        double energy_;
        double mass_;
        double momentum_;
        double time_;
        int charge_;
        Position position_;
        Direction direction_;
};

int main(){
    std::cout << "Well it ran." << std::endl;

    return(0);
}
