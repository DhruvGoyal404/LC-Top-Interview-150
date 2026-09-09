// https://leetcode.com/problems/design-parking-system/
class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b = big; m = medium; s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && b){
            b--; return true;
        } else if(carType == 2 && m){
            m--; return true;
        } else if(carType == 3 && s){
            s--; return true;
        }
        return false;
    }
};
