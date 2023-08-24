#include <iostream>
#include <cmath>

class Earth {
public:
    static const double EARTH_RADIUS; // Đơn vị: km
};

const double Earth::EARTH_RADIUS = 6371.0; // Bán kính trung bình của trái đất

class Coordinate {
public:
    Coordinate(double latitude, double longitude) : lat(latitude), lon(longitude) {}

    double getLatitude() const {
        return lat;
    }

    double getLongitude() const {
        return lon;
    }

private:
    double lat; // Vĩ độ
    double lon; // Kinh độ
};

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double calculateHaversineDistance(const Coordinate& point1, const Coordinate& point2) {
    double dLat = degreesToRadians(point2.getLatitude() - point1.getLatitude());
    double dLon = degreesToRadians(point2.getLongitude() - point1.getLongitude());

    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(degreesToRadians(point1.getLatitude())) * std::cos(degreesToRadians(point2.getLatitude())) *
               std::sin(dLon / 2) * std::sin(dLon / 2);

    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    return Earth::EARTH_RADIUS * c;
}

int main() {
    double lat1, lon1, lat2, lon2;

    // Nhập tọa độ cho hai điểm
    std::cout << "Nhập tọa độ cho điểm 1 (latitude, longitude): ";
    std::cin >> lat1 >> lon1; //Ex: New York [40.712776 -74.005974]

    std::cout << "Nhập tọa độ cho điểm 2 (latitude, longitude): ";
    std::cin >> lat2 >> lon2; //Ex: HCM City [10.823099 106.629662]

    // Tạo đối tượng Coordinate cho hai điểm
    Coordinate point1(lat1, lon1);
    Coordinate point2(lat2, lon2);

    // Tính và hiển thị khoảng cách
    double distance = calculateHaversineDistance(point1, point2);
    std::cout << "Khoảng cách giữa hai điểm trên trái đất là: " << distance << " km" << std::endl; //Ex: HCM city <-> New York: 14284.2 km

    return 0;
}
