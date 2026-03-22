#include <iostream>

#define MAX_CARS 100

using namespace std;

struct Car {
    int car_number;
    int checkpoints;
    int last_time;
    int next;
};

void sort_cars(Car* cars, int n_cars) {
    for (int i = 0; i < n_cars - 1; i++) {
        int best_car = i;

        for (int j = i + 1; j < n_cars; j++) {
            if (cars[j].checkpoints > cars[best_car].checkpoints || 
                (cars[j].checkpoints == cars[best_car].checkpoints &&
                cars[j].last_time < cars[best_car].last_time)) {
                best_car = j;
            }
        }

        Car temp = cars[i];
        cars[i] = cars[best_car];
        cars[best_car] = temp;
    }
}

int main(int argc, char* argv[]) {
    int n_checkpoints, n_cars, n_readings, car, checkpoint;
    int reading, i;
    struct Car cars[MAX_CARS];

    cin >> n_checkpoints >> n_cars >> n_readings;
    
    for (i = 0 ; i < n_cars; i++) {
        cars[i].car_number = i + 1;
        cars[i].checkpoints = 0;
        cars[i].last_time = 0;
        cars[i].next = 1;
    }

    for (reading = 1; reading <= n_readings; reading++) {
        cin >> car >> checkpoint;

        if (checkpoint == cars[car - 1].next) {
            cars[car - 1].checkpoints++;
            cars[car - 1].last_time = reading;

            if (checkpoint == n_checkpoints) 
                cars[car - 1].next = 1;
            else
                cars[car - 1].next++;
        }
    }

    sort_cars(cars, n_cars);

    for (i = 0; i < n_cars; i++) {
        cout << cars[i].car_number << " ";
    }

    return 0;
}
